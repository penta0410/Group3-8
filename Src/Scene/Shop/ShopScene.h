#pragma once

//ショップ画像背景
#define SHOP_BACK_PATH	"Data/Shop/図1.jpg"

//ショップ画像枚数
#define SHOP_NUM	(10)

class SHOP
{

private:

	//ショップシーンからの遷移フラグ
	int m_ShopFlag = 0;

	//ショップ画像ハンドル
	int m_Shophandle[SHOP_NUM] = { 0 };

public:

	

	//ショップ初期化
	void InitShop();

	//ショップ通常処理
	void StepShop();

	//ショップ描画処理
	void DrawShop();

	//ショップ後処理
	void FinShop();

};
