#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include <math.h>
#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"

//プレイシーン画像枚数
const int PLAY_IMAGE_PATH_NUM = 1;

//プレイシーンパス
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//背景

};

//プレイシーンクラス
class PLAY : public SCENE_BASE
{
private:
	//クラス宣言
	Player player;			//プレイヤークラス
	Screen m_screen;		//スクリーンクラス

	//画像ハンドル
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//背景座標
	int m_BG_x[2];
	int m_BG_y[2];
	

public:

	//初期化
	void Init() override;
	//ロード
	void Load() override;
	//通常処理
	void Step()	override;
	//描画処理
	void Draw() override;
	//後処理
	void Fin() override;


};

