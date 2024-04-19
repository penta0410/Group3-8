#pragma once

#include "Player.h"

//初期化処理
void Player::Init()
{
	//座標
	m_posX = 0.0f;			//X座標
	m_posY = 0.0f;			//Y座標
	m_nextPosX = 0.0f;		//移動後のX座標
	m_nextPosY = 0.0f;		//移動後のY座標
	old_pos_x = 0.0f;		//移動前のX座標
	old_pos_y = 0.0f;		//移動前のY座標

	//移動量
	m_move_x = 0.0f;		//X移動量
	m_move_y = 0.0f;		//Y移動量

	//画像ハンドル
	memset(m_ImageHandle, -1, sizeof(m_ImageHandle));

	//アニメーション番号
	m_Animation_Num = 0;

	//プレイヤーフレームカウントタイム
	SpeedFreamCnt = 0;
	//プレイヤー速さをあげるまでの時間
	PlayerUpSeedTime = 0;

	//HP
	m_HP = 0.0f;

	//重力フラグ
	isGravity = false;

}

//読み込み処理
void Player::Load()
{
	LoadDivGraph(PLAYER_IMAGE_PATH, PLAYER_IMG_TOTAL_NUM, PLAYER_IMG_X_NUM, PLAYER_IMG_Y_NUM, PLAYER_WIDTH, PLAYER_HIGHT, m_ImageHandle);
}

//初期値設定処理
void Player::DefaultValue()
{
	//座標
	m_posX = 0.0f;			//X座標
	m_posY = 600.0f;			//Y座標
	m_nextPosX = 0.0f;		//移動後のX座標
	m_nextPosY = 0.0f;		//移動後のY座標
	old_pos_x = 0.0f;		//移動前のX座標
	old_pos_y = 0.0f;		//移動前のY座標

	//移動量
	m_move_x = PLAYER_SPEED;		//X移動量
	m_move_y = 0.0;					//Y移動量

	//アニメーション関連
	m_Animation_Num = 6;				//アニメーション番号
	m_AnimationFreamCnt = 0;			//アニメーション用フレームカウント

	SpeedFreamCnt = 0;					//プレイヤーのスピードアップ用フレームカウント

	//HP
	m_HP = 1.0f;

	//重力フラグ
	isGravity = true;
}

//通常処理
void Player::Step()
{
	Control();			//操作処理
	Move();				//移動処理	
	Animation();		//アニメーション処理

	//プレイヤーが落ちないようにする
	if (m_nextPosY > 600)
	{
		m_posY = 600;
	}

	Gravity();			//重力与える
}

//描画処理
void Player::Draw()
{
	//デバッグ
	DrawFormatString(32, 32, GetColor(255, 0, 0), "%f, %f", m_posX, m_posY);

	//プレイヤー画像
	DrawRotaGraph(m_posX + PLAYER_W_R - screen.GetScreenX() , m_posY + PLAYER_H_R - screen.GetScreenY(), 1.0f, 0.0f, m_ImageHandle[m_Animation_Num], true, false);
}

//終了処理
void Player::Fin()
{
	//プレイヤーの画像を削除
	for (int i = 0; i < PLAYER_IMAGE_NUM; i++) {
		DeleteGraph(m_ImageHandle[i]);
	}
}

void Player::Move()
{
	//フレームカウントを加算
	SpeedFreamCnt++;

	//移動後の座標を代入
	m_nextPosX = m_posX;

	//プレイヤーが横に移動し続ける
	m_posX += m_move_x;

	//フレームカウントが60になったとき
	if (SpeedFreamCnt >= PLAYER_FREAM_CNT)
	{
		//一秒経過させる
		PlayerUpSeedTime += 1;

		//0に戻す
		SpeedFreamCnt = 0;
	}
	//10秒経過したら
	if (PlayerUpSeedTime >= PLAYER_SPEED_UP_TIME)
	{
		//プレイヤーのスピードを少しあげる
		m_move_x += 0.1;

		//0に戻す
		PlayerUpSeedTime = 0;
	}



}

//操作処理
void Player::Control()
{
	//ジャンプ処理
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		m_move_y -= PLAYER_Y_SPEED;
	}
}

//アニメーション
void Player::Animation()
{
	//フレームカウントを加算
	m_AnimationFreamCnt++;

	//1秒たったら
	if (m_AnimationFreamCnt >= 15)
	{
		//アニメーション番号を1つ加算
		m_Animation_Num++;
		//アニメーションが反対向きにならないようにする
		if (m_Animation_Num > 8)
		{
			//アニメーションを最初に戻す
			m_Animation_Num = 6;
		}

		//アニメーション処理が終わったらフレームカウントを初期化
		m_AnimationFreamCnt = 0;
	}
}

//重力を与える
void Player::Gravity()
{
	//重力フラグがオンの時
	if (isGravity)
	{
		//重力を与える
		m_move_y += GRAVITY;

		//プレイヤーの重力の限界値
		if (m_move_y >= 12.0f)
		{
			m_move_y = 12.0;
		}
		//プレイヤーの座標にY方向のスピードを加算
		m_posY += m_move_y;

	}
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

//天井処理
void Player::PlayerCeiling()
{
	//ｙの移動量をリセット
	m_move_y = 0.0f;

	if (IsAirPlayer())
	{
		//プレイヤー落下状態に変更
		state = PLAYER_STATE_FALL;

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

	}

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