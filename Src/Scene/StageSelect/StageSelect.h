#pragma once
#include "../../Player/Player.h"


//ステージセレクト画面画像パス
#define STAGE_SELECT_BACK_PATH	"Data/StageSelectImage/ループ背景004.jpg"

//ステージセレクトアイコン画像パス
#define STAGE_SELECT_STAGE_ICON_PATH  "Data/StageSelectImage/図3.png"

//アイコン背景画像パス
#define STAGE_SELECT_ICON_BACKGROUND_PATH  "Data/StageSelectImage/図4.png"

//ステージセレクト道画像パス
#define STAGE_SELECT_LOAD_PATH	"Data/StageSelectImage/画像1.png"

//プレイヤー情報表示欄画像パス
#define PLAYER_INFO_FIELD	"Data/StageSelectImage/画像8.png"

//プレイヤー残機画像パス
#define PLAYER_REMAIN_PATH	"Data/StageSelectImage/図5.png"

//コイン画像パス
#define KOIN_PATH		"Data/StageSelectImage/図6.png"

//隠しコイン画像パス
#define HIDE_KOIN_PATH		"Data/StageSelectImage/図8.png"

//アイテム画像パス
#define ITEM_PATH		"Data/StageSelectImage/図9.png"

//ステージアイコンパス
#define STAGE_ICON_PATH	"Data/StageSelectImage/図10.png"

//ステージ１パス
#define STAGE_1_PATH	"Data/StageSelectImage/図11.png"

//ステージセレクト動画パス
#define STAGE_SELECT_MOVIE_PATH	"Data/StageSelectImage/Shooting_star.mp4"

//ステージセレクト画像枚数
#define STAGE_SELECT_IMAGE_NUMBER	(20)

//プレイヤー画像
#define PLAYER_NUM	(100)

class STAGE_SELECT
{
private:

	Player m_player;

	//ステージセレクトからの遷移フラグ
	int m_StageSelectFlag = 0;

	//ステージセレクト画面画像
	int m_StageSelectImageHandle[STAGE_SELECT_IMAGE_NUMBER] = { 0 };

	//プレイヤー移動
	int m_player_move_x = 0;
	int m_player_move_y = 0;

	//ステージ選択フラグ
	int m_Stage_Flag = 1;

	int m_playerhandle[10] = { 0 };

	//ステージセレクト動画ハンドル
	int m_Stageselect_Movie_handle = 0;

	//ステージ遷移フラグ
	int m_StageMoveFlag = 1;

	//プレイヤー画像ハンドル
	int m_PlayerHandle[PLAYER_NUM] = { 0 };

public:

	

	//ステージセレクト初期化
	void InitStageSelect();

	//ステージセレクト通常処理
	void StepStageSelect();

	//ステージセレクト描画処理
	void DrawStageSelect(int koin, int hidekoin, int playerremain);

	//ステージセレクト後処理
	void FinStageSelect();

	//セットフラグ
	void SetFlag(int flag);

};
