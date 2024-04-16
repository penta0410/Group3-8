
#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Scene/Play/ScenePlay.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Effect/Effect.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"
#include "../Screen/Screen.h"

//アニメーションファイルパス
const char* ANIMATION_PATH[PLAYER_ANIMATION_TYPE_MAX] =
{
	PLAYER_STAND_PATH,
	PLAYER_WALK_PATH,
	PLAYER_RUN_PATH,
	PLAYER_JUMP_PATH,
	PLAYER_MIDAIR_PATH,
	PLAYER_FALL_PATH,
	PLAYER_LANDING_PATH,
	PLAYER_DAMAGE_PATH,
	PLAYER_ATTACK_PATH,

};

PLAY m_play;
Screen m_screen;
Enemy m_enemy;

Player::Player() 
{

}

Player::~Player() {}

Player m_player;

//初期化
void Player::Init() 
{
	//アニメーションハンドル
	animation_handle[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//アニメーション画像フラグ
    animation_flag[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//アニメーションフレーム
	animation_flame = 0;

	//プレイヤー初期状態
	m_posX = 100;
	m_posY = 100;
	m_HP = 100;

	//攻撃フレーム
	m_attack = 0;

	//攻撃フラグ
	m_attackFlag = 0;

	//攻撃アニメーションフレーム
	m_attack_frame = 0;
	
	//描画フラグ
	m_drawflag = 1;

	//プレイヤー移動後の座標
	m_nextPosX = 0.0f;
	m_nextPosY = 0.0f;

	//プレイヤー移動量
	m_move_x = 0;
	m_move_y = 0;

	//マウス座標
	m_Mouse_x = 0;	//ｘ座標
	m_Mouse_y = 0;	//y座標

	//プレイヤー移動フラグ
	m_PlayerMoveFlag = false;

	//重力フラグ
	isGravity = false;

	//アニメーション変更フラグ
	m_player_animationflag = 0;

	//プレイヤーの最初のアニメーション
	now_animation = PLAYER_ANIMATION_TYPE_STAND;

}

//読み込み処理g
void Player::LoadPlayer()
{
	//プレイヤー読み込み
	for (int load_num = 0; load_num <
		PLAYER_ANIMATION_TYPE_MAX; load_num++)
	{
		LoadDivGraph(ANIMATION_PATH[load_num],
			ANIMATION_FRAME_NUM[load_num],
			AnimationImgSplitNum[load_num][0],
			AnimationImgSplitNum[load_num][1],
			AnimationImgSize[0][0],
			AnimationImgSize[0][1],
			animation_handle[load_num]);
	}

}

//更新
void Player::StepPlayer()
{
	//移動前の座標を記録する
	old_pos_x = m_posX;
	old_pos_y = m_posY;

	//横移動量をリセット
	m_move_x = 0.0f;

	//空中にいなければ状態をリセット
	if (!IsAirPlayer())
	{
		state = PLAYER_STATE_STAND;
	
		//アニメーション変更フラグ
		m_player_animationflag = 1;

	}

	//通常処理
	Control();

	//落下前更新
	StepPlayerMidAir();

	//落下更新
	StepPlayerFall();

}

//通常処理
void Player::Control() {

	// 十字キー操作以外で移動したときにどの方向に
	// 移動しているかチェックするため
	m_nextPosX = m_posX;
	m_nextPosY = m_posY;

	//横移動処理
	//左
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{

		//歩き
		m_move_x = -MOVE_X;
		m_nextPosX -= MOVE_X;

		//プレイヤーを左方向にする
		m_PlayerVisualDirection = 1;

		//空中にいなければ歩くアニメーション
		if (!IsAirPlayer())
		{
			state = PLAYER_STATE_WALK;


			//アニメーション変更フラグ
			m_player_animationflag = 1;
		}

	}
	

	//右
	if (CheckHitKey(KEY_INPUT_D) == 1) 
	{
		//歩き
		m_move_x = MOVE_X;

		m_nextPosX += MOVE_X;

		//プレイヤーを右方向にする
		m_PlayerVisualDirection = 0;

		//空中にいなければ歩くアニメーション
		if (!IsAirPlayer())
		{
			state = PLAYER_STATE_WALK;

			//アニメーション変更フラグ
			m_player_animationflag = 1;
		}

	}
	

	//ジャンプ処理
	if (IsKeyPush(KEY_INPUT_SPACE) == 1) 
	{
		if (CanJumpPlayer() == true)
		{
			m_move_y = -JUMP_POWER;

			//ジャンプ状態に設定
			state = PLAYER_STATE_JUMP;

			//アニメーション変更フラグ
			m_player_animationflag = 1;
			
		}
	}
	

	//シーンプレイのみで処理
	//重力
	if (g_CurrentSceneID == SCENE_ID_LOOP_PLAY)
	{
		//重量on
		isGravity = true;

		//重力の計算
		m_move_y += GRAVITY;
		if (m_move_y > FALL_MAX)
		{
			// Y方向の移動量を制限
			m_move_y = FALL_MAX;
		}
		if (isGravity)
		{

			m_nextPosY += m_move_y;
		}
	}
}

//描画
void Player::Draw(int mapmove) 
{	

	//アニメーションフレームカウント
	animation_flame++;

	//一つのアニメーションの画像枚数分回す
	for (int image_num = 0; image_num <
		ANIMATION_FRAME_NUM[state]; image_num++)
	{
		
		
		if (m_drawflag == 1)
		{
			//使用フラグを未使用に
			animation_flag[state][image_num] = 1;

			//描画フラグをoffに
			m_drawflag = 0;

		
		}

		


		//画像が使用されていなかったら
		if (animation_flag[state][image_num] == 1)
		{
			
			// 向きによっては反転して描画
			//最初は右
			if (m_PlayerVisualDirection == 0)
			{
				DrawGraph(m_posX - mapmove - 300, m_posY,
					animation_handle[state][image_num], TRUE);

			}
			//左
			else if (m_PlayerVisualDirection == 1)
			{
				DrawTurnGraph(m_posX - mapmove - 300, m_posY,
					animation_handle[state][image_num], TRUE);

			}
		}

		//フレームが更新時間フレームたったら次の画像描画
		if (m_drawflag == 0 && animation_flame > ANIMATION_FRAME_TIME[state] * 1.5)
		{
			//画像フラグを使用済みにする
			animation_flag[state][image_num] = 0;

			//描画フラグをonにする
			m_drawflag = 1;

			//アニメーションフレーム初期化
			animation_flame = 0;
		}

	}

	

}

//プレイヤー攻撃処理
int Player::PlayerAttack(int mapmove, int m_x, int m_y)
{

	//マウス位置取得
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);


	//攻撃フレーム
	m_attack++;

	//一秒クールタイム
	if (m_attack >= 60)
	{
		//左クリックしたとき攻撃
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{

			m_attack = 0;

			//攻撃フラグ
			m_attackFlag = 1;

		}
		else
		{
			//押されていない
		}
	}

	

	//攻撃フラグがonになったら
	if (m_attackFlag == 1)
	{
		//プレイヤーが右を向いているとき
		if (m_PlayerVisualDirection == 0)
		{

			

			/*DrawBox(m_x - mapmove - 30, m_y - 30,
				m_x - mapmove + 30, m_y + 30,
				GetColor(255, 255, 255), true);*/

			if (IsHitRect(m_posX - 230 - mapmove, m_posY + 30, 20, 40,
				m_x - mapmove - 30, m_y - 30, ENEMY_W, ENEMY_H) == 1)
			{
				
				int hp = m_enemy.GetHP();

				if (hp >= 0)
				{
					hp -= 100;

					return hp;
				}

			}
		}
		//プレイヤーが左を向いているとき
		else if (m_PlayerVisualDirection == 1)
		{

			/*DrawBox(m_posX - 300 - mapmove, m_posY + 30,
				m_posX - 300 - mapmove + 20, m_posY + 70,
				GetColor(255, 255, 255), true);*/

			if (IsHitRect(m_posX - 300 - mapmove, m_posY + 30, 20, 40,
				m_x - mapmove - 30, m_y - 30, ENEMY_W, ENEMY_H) == 1)
			{

				int hp = m_enemy.GetHP();

				if (hp >= 0)
				{
					hp -= 100;

					return hp;
				}

			}
		}

		m_attack_frame++;
	}

	//一秒間アニメーション表示
	if (m_attackFlag == 1 && m_attack_frame <= 30)
	{
		//アニメーション
		//攻撃状態に
		state = PLAYER_STATE_ATTACK;

		//アニメーション変更フラグ
		m_player_animationflag = 1;

	}
	else if (m_attack_frame > 30)
	{
		//攻撃フラグをoffに
		m_attackFlag = 0;

		//攻撃フレームを初期化
		m_attack_frame = 0;
	}

}

//落下前チェック
void Player::StepPlayerMidAir()
{
	//ジャンプ頂上に到達する２フレーム前にアニメーションを再生する
	if (state == PLAYER_STATE_JUMP && m_move_y > -GRAVITY * 2) 
	{
		//空中状態に変更
		state = PLAYER_STATE_MIDAIR;

		//アニメーション変更フラグ
		m_player_animationflag = 1;
	}
}

//落下更新
void Player::StepPlayerFall()
{
	//落下し始めて５フレーム後に落下状態にする
	if (m_move_y > GRAVITY * 5)
	{
		//落下状態に変更
		state = PLAYER_STATE_FALL;

		//アニメーション変更フラグ
		m_player_animationflag = 1;
	}
}

//着地処理
void Player::PlayerLanding()
{
	//ｙの移動量をリセット
	m_move_y = 0.0f;

	//待機状態に戻す
	if (IsAirPlayer())
	{
		//待機状態に変更
		state = PLAYER_STATE_STAND;

		//アニメーション変更フラグ
		m_player_animationflag = 1;
	}

}

//天井処理
void Player::PlayerCeiling()
{
	//ｙの移動量をリセット
	m_move_y = 0.0f;

	if (IsAirPlayer())
	{
		//プレイヤー落下状態に変更
		state = PLAYER_STATE_FALL;

		//アニメーション変更フラグ
		m_player_animationflag = 1;
	}

}

//ジャンプ可能かどうか
bool Player::CanJumpPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_FALL:
		return false;

	}

	return true;

}

//空中状態かどうか
bool Player::IsAirPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_FALL:
		return true;

	}

	return false;

}

//プレイヤー終了処理
void Player::FinPlayer() 
{
	
}

//座標を更新
void Player::SetNextPosX(int _posX) 
{
	m_nextPosX = _posX;
}

//座標を更新
void Player::SetNextPosY(int _posY) 
{
	m_nextPosY = _posY;
}

// 進んでいる方向をチェック
// 上下左右の順になっている
void Player::GetMoveDirection(bool* _dirArray) {

	// 右方向のチェック
	if (m_nextPosX > m_posX) {
		_dirArray[3] = true;
		
	}

	// 左方向のチェック
	if (m_nextPosX < m_posX) {

		_dirArray[2] = true;
		
	}

	// 下方向のチェック
	if (m_nextPosY > m_posY) {
		_dirArray[1] = true;
		
	}

	// 上方向のチェック
	if (m_nextPosY < m_posY) {
		_dirArray[0] = true;

	}

}

// 座標を更新
void Player::UpdatePos() {
	m_posX = m_nextPosX;
	m_posY = m_nextPosY;
}

//プレイヤーのHPを設定
void Player::SetHP(int hp)
{
	m_HP = hp;
}

//プレイヤー移動フラグの状態を設定
void Player::SetPlayerMoveFlag(int flag)
{
	m_PlayerMoveFlag = flag;

}
