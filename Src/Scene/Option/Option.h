#pragma once

//オプション画像枚数
#define OPTION_IMAGE_NUMBER		(10)

//ボタン画像枚数
#define OPTION_BOTTAN_NUMBER	(2)

//オプション画像パス
#define OPTION_MOVIE_PATH	"Data/OptionImage/08tukihosikumo.mp4"

//タイトル戻るボタンパス
#define OPTION_BOTTAN_PATH	"Data/OptionImage/図3.png"

//説明ボタンパス
#define OPTION_EXPLAIN_PATH	"Data/OptionImage/図8.png"

//オプションタイトル画像パス
#define OPTION_TITLE_PATH	"Data/OptionImage/図1.png"

class OPTION
{
private:

	//オプションシーンからの遷移選択フラグ
	int m_OptionSceneFlag = 0;

	//オプションタイトルハンドル
	int m_OptionTitleHundle = 0;

	//オプション背景ハンドル
	int m_BackGroundImageHandle[OPTION_IMAGE_NUMBER] = { 0 };

	//ボタンハンドル
	int m_BottanHandle[OPTION_BOTTAN_NUMBER] = { 0 };

	//戻るボタンサイズ
	int m_bottan_x = 1200;	//ｘ座標
	int m_bottan_y = 650;	//y座標
	int m_bottan_r = 30;	//半径

	//説明ボタンサイズ
	int m_explain_bottan_x = 550;	//ｘ座標
	int m_explain_bottan_y = 350;	//y座標
	int m_explain_bottan_w = 210;	//横
	int m_explain_bottan_h = 130;	//縦
	float m_explain_size = 1.0f;
	int m_explain2_bottan_x = 645;	//ｘ座標
	float m_explain2_size = 0.5f;

	//アイテムボタンサイズ
	int m_text_bottan_x = 850;	//ｘ座標
	int m_text_bottan_y = 350;	//y座標
	int m_text_bottan_w = 210;	//横
	int m_text_bottan_h = 130;	//縦
	float m_text_size = 0.7f;
	int m_text2_bottan_x = 950;	//ｘ座標
	float m_text2_size = 0.4f;

	//キャラクターボタンサイズ
	int m_character_bottan_x = 1150;	//ｘ座標
	int m_character_bottan_y = 350;	//y座標
	int m_character_bottan_w = 210;	//横
	int m_character_bottan_h = 130;	//縦
	float m_character_size = 0.7f;
	float m_character2_size = 0.25f;
	int m_character2_bottan_x = 1180;	//ｘ座標

	//ボタン選択フラグ
	int m_Bottan_Flag = 1;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標
	
	//戻るボタンフラグ
	int m_Return_Bottan_Flag = 0;
	
	//オプションフレーム
	int m_Option_Flame = 0;

	//マウスフレーム
	int m_mouse_Flame = 0;

public:
	// オプション初期化
	void InitOption();

	//オプション通常処理
	void StepOption();

	//オプション描画処理
	void DrawOption();

	//オプション後処理
	void FinOption();

	//マウスクリック処理
	void MouseClick();

};