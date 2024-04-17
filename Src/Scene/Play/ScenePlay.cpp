
#include <math.h>
#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"

//=============================
// プレイシーン
//=============================

//初期化
void PLAY::Init()
{
	player.Init();				//プレイヤーの初期化処理
	player.DefaultValue();		//プレイヤーの初期値設定

	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//ロード
void PLAY::Load()
{
	player.Load();				//プレイヤーの読み込み
}

//通常処理
void PLAY::Step()
{	
	player.Step();				//プレイヤーの通常処理

	//リザルトシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//シーンフラグをリザルトシーンに変更
		m_SceneFlag = 0;
		//プレイ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

}

//描画処理
void PLAY::Draw()
{
	player.Draw();				//プレイヤーの描画処理

	//デバッグ
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "プレイシーンです。", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "enterでリザルトシーン", true);
	SetFontSize(16);
}

//後処理
void PLAY::Fin()
{
	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//プレイINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}