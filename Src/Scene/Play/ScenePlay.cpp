#pragma once

#include "ScenePlay.h"
#include "../../Common.h"

//=============================
// プレイシーン
//=============================

//初期化
void PLAY::Init()
{
	player.Init();				//プレイヤーの初期化処理
	player.DefaultValue();		//プレイヤーの初期値設定

	//背景座標
	m_BG_x[0] = WINDOW_WIDTH/2;
	m_BG_y[0] = WINDOW_HEIGHT/2;
	m_BG_x[1] = WINDOW_WIDTH + WINDOW_WIDTH / 2;
	m_BG_y[1] = WINDOW_HEIGHT + WINDOW_HEIGHT / 2;

	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//ロード
void PLAY::Load()
{
	m_ImageHandle[0] = LoadGraph(PLAY_PATH[0]);			//プレイ背景
	player.Load();				//プレイヤーの読み込み
}

//通常処理
void PLAY::Step()
{	
	player.Step();				//プレイヤーの通常処理
	player.GetPosX();

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
	//背景描画
	DrawRotaGraph(m_BG_x[0], m_BG_y[0], 1.0f, 0.0f, m_ImageHandle[0], true);

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