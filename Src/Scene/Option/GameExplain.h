#pragma once
//ゲーム説明画面画像パス
#define GAME_EXPLAIN_BACK_PATH	"Data/OptionImage/画像2.png"

//タイトル戻るボタンパス
#define OPTION_BOTTAN_PATH	"Data/OptionImage/図3.png"

//説明画像
#define EXPLAIN_PATH	"Data/OptionImage/画像4.png"

//ボタン画像枚数
#define OPTION_BOTTAN_NUMBER	(2)

class GAME_EXPLAIN
{
private:

	//背景ハンドル
	int m_BackgroundHundle = 0;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	//戻るボタンサイズ
	int m_bottan_x = 1200;	//ｘ座標
	int m_bottan_y = 650;	//y座標
	int m_bottan_r = 30;	//半径

	//ボタンハンドル
	int m_BottanHandle[OPTION_BOTTAN_NUMBER] = { 0 };

	//説明画像ハンドル
	int m_explainhandle = 0;

	//戻るボタンフラグ
	int m_Return_Bottan_Flag = 0;

	//ゲーム説明シーンフレーム
	int m_GameExPlainFlame = 0;

	//シーン遷移フラグ
	int m_GameExplainSceneFlag = 0;

public:

	//ゲーム説明初期化
	void InitGameExplain();

	//ゲーム説明通常処理
	void StepGameExplain();

	//ゲーム説明描画処理
	void DrawGameExplain();

	//ゲーム説明後処理
	void FinGameExplain();

	//マウスクリック処理
	void MouseClick();
};
