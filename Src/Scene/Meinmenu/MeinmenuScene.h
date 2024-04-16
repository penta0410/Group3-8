#pragma once

//メインメニュー画像パス
#define MEINMENU_IMAGE_PATH	"Data/MeinmenuImage/ループ背景004.jpg"

//メインメニューシーンの透過背景
#define MEINMENU_BACKGROUND_PATH	"Data/MeinmenuImage/画像8.png"

//メインメニュー画像枚数
#define MEINMENU_NUMBER	(2)

//タイトルボタン画像パス
#define BOTTAN_TITLE_PATH	"Data/MeinmenuImage/図9.png"

//オプション画像パス
#define BOTTAN_OPTION_PATH	"Data/MeinmenuImage/図1.png"

//ショップ画像パス
#define BOTTAN_SHOP_PATH	"Data/MeinmenuImage/図2.png"

//メニュー画像パス
#define BOTTAN_MENU_PATH	"Data/MeinmenuImage/図4.png"

//ボタン画像枚数
#define MEINMENU_BOTTAN_NUMBER	(5)

//戻るボタンパス
#define RETURN_BOTTAN_PATH	"Data/MeinmenuImage/図3.png"

#include "../StageSelect/StageSelect.h"

class MEIN_MENU
{
private:

	

	//メインメニューシーンからの遷移選択フラグ
	int m_MeinMenuSceneFlag = 0;

	//メインメニュー画像ハンドル
	int m_MeinmenuHundle[MEINMENU_NUMBER] = { 0 };

	//遷移ボタン画像ハンドル
	int m_BottanHundle[MEINMENU_BOTTAN_NUMBER] = { 0 };

	//戻るボタン画像ハンドル
	int m_ReturnBottanHundle = { 0 };

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	
	//戻るボタンサイズ
	int m_bottan_x = 1170;	//ｘ座標
	int m_bottan_y = 570;	//y座標
	int m_bottan_r = 30;	//半径

	//タイトルボタンサイズ
	int m_title_bottan_x = 160;	//ｘ座標
	int m_title_bottan_y = 250;	//y座標
	int m_title_bottan_w = 210;	//横
	int m_title_bottan_h = 130;	//縦

	//オプションボタンサイズ
	int m_option_bottan_x = 465;	//ｘ座標
	int m_option_bottan_y = 250;	//y座標
	int m_option_bottan_w = 210;	//横
	int m_option_bottan_h = 130;	//縦

	//ショップボタンサイズ
	int m_shop_bottan_x = 770;	//ｘ座標
	int m_shop_bottan_y = 250;	//y座標
	int m_shop_bottan_w = 210;	//横
	int m_shop_bottan_h = 130;	//縦

	//メニューボタンサイズ
	int m_menu_bottan_x = 1075;	//ｘ座標
	int m_menu_bottan_y = 250;	//y座標
	int m_menu_bottan_w = 210;	//横
	int m_menu_bottan_h = 130;	//縦

	//戻るボタンフラグ
	int m_ReturnBottanFlag = 0;

	//メインメニューから戻ったフラグ
	int m_returnflag = 0;

	//メインメニューシーンフレーム
	int m_MeinMenu_Flame = 0;

public:
	

	//メインメニュー初期化
	void InitMeinMnu();

	//メインメニュー通常処理
	void StepMeinMnu();

	//メインメニュー描画処理
	void DrawMeinMnu();

	//メインメニュー後処理
	void FinMeinMnu();

	//マウスクリック処理
	void MouseClick();

	//現在の遷移フラグ取得
	int GetFlag() { return m_MeinMenuSceneFlag; }

	//フラグをセット
	void SetFlag(int flag);

	//フラグをゲット
	int GetReturnFlag() { return m_returnflag; }

};