#include "DxLib.h"
#include "ShopScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"


//=============================
// ショップシーン
//=============================

//ショップ初期化
void SHOP::InitShop()
{
	//ショップ背景
	m_Shophandle[0] = LoadGraph(SHOP_BACK_PATH);

	//ショップループへ
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//ショップ通常処理
void SHOP::StepShop()
{
	
	//メニューシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_ShopFlag = 0;

		//ショップ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

	//メインメニューシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_ShopFlag = 1;

		//ショップ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

}

//ショップ描画処理
void SHOP::DrawShop()
{
    //ショップ背景	
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_Shophandle[0], true);
	


}

//ショップ後処理
void SHOP::FinShop()
{
	if (m_ShopFlag == 0)
	{
		//メニューシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

	if (m_ShopFlag == 1)
	{
		//メインメニューシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MEIN_MENU;
	}

}
