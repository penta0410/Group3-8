#pragma once

class Player
{
private:

	//プレイヤーの座標
	float m_posX = 0.0f;
	float m_posY = 0.0f;

	//移動後の座標
	float m_nextPosX = 0.0f;
	float m_nextPosY = 0.0f;

	//移動前の座標
	float old_pos_x = 0.0f;
	float old_pos_y = 0.0f;

	//プレイヤー移動量
	float m_move_x = 0;
	float m_move_y = 0;

	//プレイヤー画像反転フラグ
	int m_PlayerVisualDirection = 0;

	//変更する前の状態
	int m_animation_before = 0;

	//重力フラグ
	bool isGravity = false;

	//プレイヤーのHP
	int m_HP = 0;

	//プレイヤー移動フラグ
	int m_PlayerMoveFlag = 0;

	//描画フラグ
	int m_drawflag = 0;

	//攻撃フレーム
	int m_attack = 0;

	//攻撃フラグ
	int m_attackFlag = 0;

	//攻撃アニメーションフレーム
	int m_attack_frame = 0;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標


public:
	

	
};





