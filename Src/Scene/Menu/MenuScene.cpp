#include "DxLib.h"
#include "MenuScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// メニューシーン
//=============================

//メニュー初期化
void MENU::InitMenu()
{
	//メニューループへ
	g_CurrentSceneID = SCENE_ID_LOOP_MENU;

	/*m_MenuHundle[0] = LoadGraph();*/
	
	//アイテム合成
	m_BottanHundle[0] = LoadGraph(CONPOS_BOTTAN_PATH);

	//インベントリ
	m_BottanHundle[1] = LoadGraph(INVENTORY_BOTTAN_PATH);

	//戻る
	m_ReturnBottanHundle = LoadGraph(MENU_RETURN_BOTTAN_PATH);

}

//メニュー通常処理
void MENU::StepMenu()
{

	//アイテム合成シーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_MenuSceneFlag = 0;

		//メニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_MENU;
	}

	//メインメニューへの遷移
	//tabキー押されたなら
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_MenuSceneFlag = 1;

		//メニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_MENU;
	}

	//インベントリへの遷移
	//tabキー押されたなら
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_MenuSceneFlag = 2;

		//メニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_MENU;
	}
}

//メニュー描画処理
void MENU::DrawMenu()
{
	//メニュー画面描画
	
	//戻るボタン描画
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_ReturnBottanHundle, true);

	//アイテム合成ボタン描画
	DrawRotaGraph(m_itemcps_bottan_x, m_itemcps_bottan_y, 0.3f, 0.0f, m_BottanHundle[0], true);

	//インベントリボタン描画
	DrawRotaGraph(m_ivt_bottan_x, m_ivt_bottan_y, 0.25f, 0.0f, m_BottanHundle[1], true);

	//マウス処理
	MouseClick();
}

//メニュー後処理
void MENU::FinMenu()
{
	if (m_MenuSceneFlag == 0)
	{
		//アイテム合成シーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_ITEM_CONPOS;
	}

	if (m_MenuSceneFlag == 1)
	{
		//メインメニューシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

	if (m_MenuSceneFlag == 2)
	{
		//インベントリシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

}

void MENU::MouseClick()
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
		//メインメニューに戻るボタン
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<戻る>\nボタンを左クリックするか\nctrl(コントロール)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//メインメニューシーンへの遷移
			//画面上の戻るボタン押されたなら
			//メニューシーンフラグをメインメニューシーンに変更
			m_MenuSceneFlag = 1;

			//'メニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_MENU;

		}
		else
		{
			//押されていない
		}
	}


	//アイテム合成ボタン
	//ボタン位置とボタンとの当たり判定
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_itemcps_bottan_x, m_itemcps_bottan_y, m_itemcps_bottan_r) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		//アイテム合成ボタン
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<合成>\nボタンを左クリックするか\nctrl(コントロール)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//アイテム合成シーンへの遷移
			//画面上の合成ボタン押されたなら
			//メニューシーンフラグをアイテム合成に変更
			m_MenuSceneFlag = 0;

			//'メニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_MENU;

		}
		else
		{
			//押されていない
		}
	}


	//インベントリボタン
	//ボタン位置とボタンとの当たり判定
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_ivt_bottan_x, m_ivt_bottan_y, m_ivt_bottan_r) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		//インベントリボタン
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<インベントリ>\nボタンを左クリックするか\nctrl(コントロール)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//インベントリシーンへの遷移
			//画面上の戻るボタン押されたなら
			//メニューシーンフラグをインベントリシーンに変更
			m_MenuSceneFlag = 2;

			//'メニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_MENU;

		}
		else
		{
			//押されていない
		}
	}
}