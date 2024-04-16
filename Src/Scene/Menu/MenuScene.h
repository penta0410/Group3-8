#pragma once
//メニュー画面枚数
#define MENU_NUMBER	(2)

//遷移ボタン画像枚数
#define MENU_BOTTAN_NUMBER	(3)

//合成ボタン画像パス
#define CONPOS_BOTTAN_PATH	"Data/Menu/図1.png"

//インベントリボタンパス
#define INVENTORY_BOTTAN_PATH	"Data/Menu/図3.png"

//戻るボタンパス
#define MENU_RETURN_BOTTAN_PATH	"Data/Menu/図7.png"


class MENU
{
private:

	//メニューシーンからの遷移フラグ
	int m_MenuSceneFlag = 0;

	//メニュー画像ハンドル
	int m_MenuHundle[MENU_NUMBER] = { 0 };

	//遷移ボタン画像ハンドル
	int m_BottanHundle[MENU_BOTTAN_NUMBER] = { 0 };

	//戻るボタン画像ハンドル
	int m_ReturnBottanHundle = { 0 };

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	//戻るボタンサイズ
	int m_bottan_x = 1070;	//ｘ座標
	int m_bottan_y = 570;	//y座標
	int m_bottan_r = 30;	//半径

	//アイテム合成ボタンサイズ
	int m_itemcps_bottan_x = 160;	//ｘ座標
	int m_itemcps_bottan_y = 250;	//y座標
	int m_itemcps_bottan_r = 50;	//半径
	

	//インベントリボタンサイズ
	int m_ivt_bottan_x = 535;	//ｘ座標
	int m_ivt_bottan_y = 250;	//y座標
	int m_ivt_bottan_r = 50;	//半径
	

public:

	//ステージセレクト初期化
	void InitMenu();

	//ステージセレクト通常処理
	void StepMenu();

	//ステージセレクト描画処理
	void DrawMenu();

	//ステージセレクト後処理
	void FinMenu();

	//マウスクリック処理
	void MouseClick();
};
