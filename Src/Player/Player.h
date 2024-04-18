#pragma once

#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const char PLAYER_IMAGE_PATH[] = { "Data/Player/pipo-simpleenemy01g.png" };			//画像パス

const int PLAYER_WIDTH = 32;														//横サイズ
const int PLAYER_HIGHT = 32;														//縦サイズ
const int PLAYER_W_R = 16;															//横の半径
const int PLAYER_H_R = 16;															//縦の半径
const int PLAYER_IMAGE_NUM = 12;													//画像の配列の数
const float PLAYER_SPEED = 2.5;														//プレイヤーのXスピード
const float PLAYER_Y_SPEED = 15.0f;													//プレイヤーのYスピード
const int PLAYER_IMG_TOTAL_NUM = 12;												//プレイヤーの画像総数
const int PLAYER_IMG_X_NUM = 3;														//プレイヤーの横の枚数
const int PLAYER_IMG_Y_NUM = 4;														//プレイヤーの縦の枚数

const int PLAYER_FREAM_CNT = 60;													//1秒カウント
const int PLAYER_SPEED_UP_TIME = 10;												//時間カウントするやつ

const float GRAVITY = 0.7f;															//重力


class Player
{
private:
	//クラス宣言
	Screen screen;

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

	//画像ハンドル
	int m_ImageHandle[PLAYER_IMAGE_NUM];

	//アニメーション関連
	int m_Animation_Num;					//アニメーション番号
	int m_AnimationFreamCnt;				//アニメーション用フレームカウント

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

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	//フレームカウント
	int SpeedFreamCnt;

	//プレイヤー速さをあげるまでの時間
	int PlayerUpSeedTime;

public:
	//初期化
	void Init();
	
	//読み込み
	void Load();

	//初期値
	void DefaultValue();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//終了処理
	void Fin();

	//移動処理
	void Move();

	//操作処理
	void Control();

	void Animation();
	
	//重力を与える
	void Gravity();

	//座標取得
	float GetPosX() { return m_posX; }		//X座標
	float GetPosY() { return m_posY; }		//Y座標



};





