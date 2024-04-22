#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include <math.h>
#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"
#include "../../Map/Map.h"
#include "../Result/SceneResult.h"

//プレイシーン画像枚数
const int PLAY_IMAGE_PATH_NUM = 4;
const char PLAY_BGM_PATH[] = { "Data/Sound/Play/PlayBGM.mp3" };			//プレイシーンのBGM

//プレイシーンパス
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//背景
	"Data/Play/BackGround2.png",		//背景２
	"Data/Play/coin.png",			//コイン

};

const char PLAY_SCENE_BGM[] = { "" };				//プレイシーンのBGM

//プレイシーンクラス
class PLAY : public SCENE_BASE
{
private:
	//クラス宣言
	Player player;			//プレイヤークラス
	Screen m_screen;		//スクリーンクラス
	Map m_map;				//マップクラス
	RESULT m_result;

	//画像ハンドル
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//背景座標
	int m_BG_x[2];
	int m_BG_y;
	
	//背景移動量
	int m_BG_move_x;

	//コインUI座標
	int m_coin_x;
	int m_coin_y;

	//獲得コイン保存変数
	int m_CoinNum;

	//文字フォントハンドル
	int MojiHandle;

	//数字文字数
	int m_numberHandle[10];
	int num;

	int m_PlayBgmHndl;

public:

	//初期化
	void Init() override;
	//ロード
	void Load() override;
	//音楽を流す
	void PlaySound
	//通常処理
	void Step()	override;
	//描画処理
	void Draw() override;
	//後処理
	void Fin() override;
	// マップの当たり判定
	void MapCollision(int mapmove);
	
	//トラップ通常処理
	void TrapStep();

	//コインゲット
	int GetCoin() { return m_CoinNum; };
	//コインセット
	void SetCoin(int num);

};

