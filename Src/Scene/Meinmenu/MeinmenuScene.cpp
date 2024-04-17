#include "DxLib.h"
#include "MeinmenuScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// メインメニューシーン
//=============================

//初期化
void MEIN_MENU::Init()
{

	//メインメニューループへ
	g_CurrentSceneID = SCENE_ID_LOOP_MEIN_MENU;
}

//ロード
void MEIN_MENU::Load()
{

}

//通常処理
void MEIN_MENU::Step()
{

	//プレイシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//シーンフラグをプレイシーンに変更
		m_SceneFlag = 0;
		//タイトル後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_MEIN_MENU;
	}
}

//描画処理
void MEIN_MENU::Draw()
{

	//デバッグ
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "メインメニューシーンです。", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "enterでプレイシーン", true);
	SetFontSize(16);
}

//後処理
void MEIN_MENU::Fin()
{

	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//プレイINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}
