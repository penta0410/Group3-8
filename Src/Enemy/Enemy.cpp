
#include <math.h>
#include "DxLib.h"
#include "Enemy.h"
#include "../Player/Player.h"
#include "../Common.h"
#include "../Scene/Scene.h"
#include "../Scene/Play/ScenePlay.h"
#include "../Collision/Collision.h"
#include "../Input/Input.h"

//敵移動速度
const int MOVE_SPEED = 2;


Enemy::Enemy()
{
	//敵画像ハンドル
	m_EnemyImageHandle[0] = -1;

	//敵座標
	m_enemy_x = 0;	//x座標
	m_enemy_y = 0;	//y座標

	// 重力フラグ
	isGravity = false;

	//初期化
	Init();
}

Enemy::~Enemy(){}

//初期化
void Enemy::Init()
{
	//敵画像ハンドル
	m_EnemyImageHandle[0] = LoadGraph(ENEMY_IMAGE_PATH);

	//敵座標
	m_enemy_x = 900;	//x座標
	m_enemy_y = 300;	//y座標

	// 重力フラグ
	isGravity = false;

	//敵HP
	m_HP = 100;
	
}

//敵通常処理
void Enemy::Step()
{

	m_nextPosX = m_enemy_x;
	m_nextPosY = m_enemy_y;

	//敵移動処理
	if (m_speedX < 300) 
	{
		m_nextPosX += MOVE_SPEED;
		m_speedX += MOVE_SPEED;
	}
	else if (m_speedX >= 300 && m_speedX <= 600)
	{
		m_nextPosX -= MOVE_SPEED;
		m_speedX += MOVE_SPEED;
	}
	else if (m_speedX > 600)
	{
		m_speedX = 0;
	}
	
	
	 //当たり判定デバッグ用
	//横移動処理
	//左
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_nextPosX -= MOVE_SPEED;

	}
	//右
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_nextPosX += MOVE_SPEED;

	}
	//ジャンプ処理
	if (IsKeyPush(KEY_INPUT_UP) == 1)
	{
		m_speedY = -JUMP_POWER;
	}
	

	//シーンプレイのみで処理
	//重力
	if (g_CurrentSceneID == SCENE_ID_LOOP_PLAY)
	{

		/*重量on*/
		isGravity = true;

		//重力の計算
		m_speedY += GRAVITY;
		if (m_speedY > GRAVITY)
		{
			// Y方向の移動量を制限
			m_speedY = GRAVITY + 5;
		}
		if (isGravity)
		{
			m_nextPosY += m_speedY;
		}
	}

}



//描画
void Enemy::Draw(int mapmove) 
{

	DrawRotaGraph(m_enemy_x - mapmove, m_enemy_y, 0.35f, 0.0f, m_EnemyImageHandle[0], true);
	DrawFormatString((m_enemy_x - 30) - mapmove , m_enemy_y - 60, GetColor(0, 0, 0), "HP：%d", m_HP, true);

}

//敵のHPを設定
void Enemy::SetHP(int hp)
{
	m_HP = hp;
}

//プレイヤーの座標を設定
void Enemy::SetPosX(int x)
{
	m_nextPosX = x;
}
void Enemy::SetPosY(int y)
{
	m_nextPosY = y;
}

// 進んでいる方向をチェック
// 上下左右の順になっている
void Enemy::GetMoveDirection(bool* _dirArray) {
	// 右方向のチェック
	if (m_nextPosX > m_enemy_x) {
		_dirArray[3] = true;
	}

	// 左方向のチェック
	if (m_nextPosX < m_enemy_x) {
		_dirArray[2] = true;
	}

	// 下方向のチェック
	if (m_nextPosY > m_enemy_y) {
		_dirArray[1] = true;
	}

	// 左方向のチェック
	if (m_nextPosY < m_enemy_y) {
		_dirArray[0] = true;
	}

}

// 座標を更新
void Enemy::UpdatePos() {
	m_enemy_x = m_nextPosX;
	m_enemy_y = m_nextPosY;
}