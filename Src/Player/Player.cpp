
#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Scene/Play/ScenePlay.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"
#include "../Screen/Screen.h"

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
	memset(m_ImageHandle, 0, sizeof(m_ImageHandle));

	//アニメーション番号
	m_Animation_Num = 0;

	//HP
	m_HP = 0.0f;

	//重力フラグ
	isGravity = false;

}

//読み込み処理
void Player::Load()
{
	LoadDivGraph(PLAYER_IMAGE_PARH, 12, 3, 4, PLAYER_WIDTH, PLAYER_HIGHT, m_ImageHandle);
}

//初期値設定処理
void Player::DefaultValue()
{
	//座標
	m_posX = 0.0f;			//X座標
	m_posY = 0.0f;			//Y座標
	m_nextPosX = 0.0f;		//移動後のX座標
	m_nextPosY = 0.0f;		//移動後のY座標
	old_pos_x = 0.0f;		//移動前のX座標
	old_pos_y = 0.0f;		//移動前のY座標

	//移動量
	m_move_x = 2.0f;		//X移動量
	m_move_y = 5.0f;		//Y移動量

	//アニメーション番号
	m_Animation_Num = 0;

	//HP
	m_HP = 1.0f;

	//重力フラグ
	isGravity = false;
}

//通常処理
void Player::Step()
{

}

//描画処理
void Player::Draw()
{
	DrawRotaGraph(m_posX + PLAYER_W_R, m_posY + PLAYER_H_R, 1.0f, 0.0f, m_ImageHandle[m_Animation_Num], true, false);
}

//終了処理
void Player::Fin()
{
	for (int i = 0; i < PLAYER_IMAGE_NUM; i++) {
		DeleteGraph(m_ImageHandle[i]);
	}
}