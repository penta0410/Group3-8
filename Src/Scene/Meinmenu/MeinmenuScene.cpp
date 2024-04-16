#include "DxLib.h"
#include "MeinmenuScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// メインメニューシーン
//=============================

//メインメニュー初期化
void MEIN_MENU::InitMeinMnu()
{
	//透過背景
	m_MeinmenuHundle[1] = LoadGraph(MEINMENU_BACKGROUND_PATH);

	//戻るボタンハンドル
	m_ReturnBottanHundle = LoadGraph(RETURN_BOTTAN_PATH);

	//遷移ボタン画像ハンドル
	//タイトル
	m_BottanHundle[0] = LoadGraph(BOTTAN_TITLE_PATH);

	//オプション
	m_BottanHundle[1] = LoadGraph(BOTTAN_OPTION_PATH);

	//ショップ
	m_BottanHundle[2] = LoadGraph(BOTTAN_SHOP_PATH);

	//メニュー
	m_BottanHundle[3] = LoadGraph(BOTTAN_MENU_PATH);

	//戻るボタンフラグ
	m_ReturnBottanFlag = 0;

	//メインメニューから戻ったフラグ
	m_returnflag = 0;

	//メインメニューシーンフレーム
	m_MeinMenu_Flame = 0;


}

//メインメニュー通常処理
void MEIN_MENU::StepMeinMnu()
{

	//タイトルシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_MeinMenuSceneFlag = 0;
		//メインメニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}
	
	//メインメニューシーンのフレームをカウント
	m_MeinMenu_Flame++;

	m_returnflag = 1;

	//ステージ選択への遷移
	//戻るボタンフラグがonだったら
	if (m_ReturnBottanFlag == 1)
	{
		//コントロールキー押されたなら
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			m_MeinMenuSceneFlag = 1;
			//メインメニュー後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
			
		}
	}

	//メインメニューシーンに移動して0.5秒たったら
	if (m_MeinMenu_Flame >= 30)
	{
		//戻るボタンフラグをonに
		m_ReturnBottanFlag = 1;
	}

	//オプションへの遷移
	//下↓キー押されたなら
	if (IsKeyPush(KEY_INPUT_DOWN))
	{
		m_MeinMenuSceneFlag = 2;
		//メインメニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}

	//ショップへの遷移
	//左←キー押されたなら
	if (IsKeyPush(KEY_INPUT_LEFT))
	{
		m_MeinMenuSceneFlag = 3;
		//メインメニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}

	//メニューへの遷移
	//右→キー押されたなら
	if (IsKeyPush(KEY_INPUT_RIGHT))
	{
		m_MeinMenuSceneFlag = 4;
		//メインメニュー後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}
}

//メインメニュー描画処理
void MEIN_MENU::DrawMeinMnu()
{

	//透過背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawRotaGraph(0, 100, 1.2f, 0.0f, m_MeinmenuHundle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//戻るボタン描画
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_ReturnBottanHundle, true);
	
	//タイトルボタン描画
	DrawRotaGraph(m_title_bottan_x, m_title_bottan_y, 0.65f, 0.0f, m_BottanHundle[0], true);
	
	//オプションボタン描画
	DrawRotaGraph(m_option_bottan_x, m_option_bottan_y, 0.65f, 0.0f, m_BottanHundle[1], true);
	
	//ショップボタン描画
	DrawRotaGraph(m_shop_bottan_x, m_shop_bottan_y, 0.65f, 0.0f, m_BottanHundle[2], true);

	//メニューボタン描画
	DrawRotaGraph(m_menu_bottan_x, m_menu_bottan_y, 0.65f, 0.0f, m_BottanHundle[3], true);

	//マウス処理
	MouseClick();
}

//メインメニュー後処理
void MEIN_MENU::FinMeinMnu()
{

	//フラグが０の時タイトルへ
	if (m_MeinMenuSceneFlag == 0)
	{

		//タイトルINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}

	if (m_MeinMenuSceneFlag == 1)
	{

		//ステージ選択INITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

	if (m_MeinMenuSceneFlag == 2)
	{
		//オプションINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_OPTION;
	}

	if (m_MeinMenuSceneFlag == 3)
	{
		//ショップINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_SHOP;
	}

	if (m_MeinMenuSceneFlag == 4)
	{
		//メニューINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}
}

void MEIN_MENU::MouseClick()
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
		//ステージセレクトに戻るボタン
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<戻る>\nボタンを左クリックするか\nTab(タブ)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//ステージセレクトシーンへの遷移
			//画面上の戻るボタン押されたなら
			//メインメニューシーンフラグをステージセレクトシーンに変更
			m_MeinMenuSceneFlag = 1;

			//'タイトル後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//押されていない
		}
	}

	//タイトルボタン
	if (IsHitRect(m_title_bottan_x - 105, m_title_bottan_y - 70, m_title_bottan_w, m_title_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		
		//タイトルへ
		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<タイトルへ>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//タイトルシーンへの遷移
			//画面上のタイトルボタン押されたなら

			//メインメニューシーンフラグをタイトルシーンに変更
			m_MeinMenuSceneFlag = 0;

			//'メインメニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//押されていない
		}
	}

	//オプションボタン
	if (IsHitRect(m_option_bottan_x - 105, m_option_bottan_y - 70, m_option_bottan_w, m_option_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//オプションへ
		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<オプションへ>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//オプションシーンへの遷移
			//画面上のオプションボタン押されたなら

			//メインメニューシーンフラグをオプションシーンに変更
			m_MeinMenuSceneFlag = 2;

			//'メインメニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//押されていない
		}
	}

	//ショップボタン
	if (IsHitRect(m_shop_bottan_x - 105, m_shop_bottan_y - 70, m_shop_bottan_w, m_shop_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ショップへ
		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<ショップへ>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//ショップシーンへの遷移
			//画面上のショップボタン押されたなら

			//メインメニューシーンフラグをショップシーンに変更
			m_MeinMenuSceneFlag = 3;

			//'メインメニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//押されていない
		}
	}

	//メニューボタン
	if (IsHitRect(m_menu_bottan_x - 105, m_menu_bottan_y - 70, m_menu_bottan_w, m_menu_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//メニューへ
		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<メニューへ>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//メニューシーンへの遷移
			//画面上のメニューボタン押されたなら

			//メインメニューシーンフラグをメニューシーンに変更
			m_MeinMenuSceneFlag = 4;

			//'メインメニュー後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//押されていない
		}
	}
}

//ステージ遷移フラグを設定
void MEIN_MENU::SetFlag(int flag)
{
	m_MeinMenuSceneFlag = flag;
}