#include "DxLib.h"
#include "GameExplain.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// ゲーム説明シーン
//=============================

//ゲーム説明初期化
void GAME_EXPLAIN::InitGameExplain()
{

	//ゲーム説明ループへ
	g_CurrentSceneID = SCENE_ID_LOOP_GAME_EXPLAIN;

	//ゲーム説明シーン画像ハンドル
	m_BackgroundHundle = LoadGraph(GAME_EXPLAIN_BACK_PATH);

	//説明画像ハンドル
	m_explainhandle = LoadGraph(EXPLAIN_PATH);

	//ボタン画像ハンドル
	m_BottanHandle[0] = LoadGraph(OPTION_BOTTAN_PATH);

}

//ゲーム説明通常処理
void GAME_EXPLAIN::StepGameExplain()
{
	//ゲーム説明シーンフレームカウント
	m_GameExPlainFlame++;

	//オプションシーンへの遷移
	//戻るボタンフラグがonだったら
	if (m_Return_Bottan_Flag == 1)
	{
		//左コントロールキー押されたなら
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			//ゲーム説明シーンフラグをオプションシーンに変更
			m_GameExplainSceneFlag = 0;

			//プレイ後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_GAME_EXPLAIN;
		}
	}
	
	//ゲーム説明シーンに移動して１秒たったら
	if (m_GameExPlainFlame >= 60)
	{
		//戻るボタンフラグをonに
		m_Return_Bottan_Flag = 1;
	}
}

//ゲーム説明描画処理
void GAME_EXPLAIN::DrawGameExplain()
{
	//ゲーム説明画面描画
	DrawRotaGraph(910, 360, 1.5f, 0.0f, m_BackgroundHundle, true);

	//ボタン画像描画
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_BottanHandle[0], true);

	//説明画像描画
	DrawRotaGraph(830, 450, 0.4f, 0.0f, m_explainhandle, true);

	//マウス処理
	if (m_Return_Bottan_Flag == 1)
	{
		MouseClick();
	}

}

//ゲーム説明後処理
void GAME_EXPLAIN::FinGameExplain()
{
	if (m_GameExplainSceneFlag == 0)
	{
		//オプションINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_OPTION;
	}

}

void GAME_EXPLAIN::MouseClick()
{
	//マウス位置取得
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);

	//戻るボタン
	//ボタン位置とボタンとの当たり判定
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_bottan_x, m_bottan_y, m_bottan_r) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<戻る>\nボタンを左クリックするか\nTab(タブ)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			
			//ゲーム説明シーンフラグをオプションシーンに変更
			m_GameExplainSceneFlag = 0;

			//'オプション後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_GAME_EXPLAIN;
		}
		else
		{
			//押されていない
		}
	}

	////説明ボタン
	//if (IsHitRect(m_explain_bottan_x - 105, m_explain_bottan_y - 70, m_explain_bottan_w, m_explain_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	//{
	//	//文字背景
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	//	DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
	//	SetFontSize(12);
	//	DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<ゲーム説明>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

	//	//文字サイズをもとに
	//	SetFontSize(16);

	//	//左クリックしたとき
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	//	{
	//		//オプションシーンへの遷移
	//		//画面上のオプションボタン押されたなら

	//		//タイトルシーンフラグをオプションシーンに変更
	//		m_OptionSceneFlag = 0;

	//		//'タイトル後処理'へ移動
	//		g_CurrentSceneID = SCENE_ID_FIN_OPTION;

	//	}
	//	else
	//	{
	//		//押されていない
	//	}
	//}
}