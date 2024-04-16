#include "DxLib.h"
#include "Option.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// オプションシーン
//=============================

//オプション初期化
void OPTION::InitOption()
{

	//オプションループへ
	g_CurrentSceneID = SCENE_ID_LOOP_OPTION;

	//背景画像ハンドル
	m_BackGroundImageHandle[0] = LoadGraph(OPTION_MOVIE_PATH);

	//ボタン画像ハンドル
	m_BottanHandle[0] = LoadGraph(OPTION_BOTTAN_PATH);
	m_BottanHandle[1] = LoadGraph(OPTION_EXPLAIN_PATH);

	//ボタンネームハンドル
	//説明
	m_BackGroundImageHandle[1] = LoadGraph("Data/OptionImage/図4.png");

	//アイテム
	m_BackGroundImageHandle[2] = LoadGraph("Data/OptionImage/図5.png");

	//キャラクター
	m_BackGroundImageHandle[3] = LoadGraph("Data/OptionImage/図6.png");

	//右矢印ハンドル
	m_BackGroundImageHandle[4] = LoadGraph("Data/OptionImage/図9.png");

	//左矢印ハンドル
	m_BackGroundImageHandle[5] = LoadGraph("Data/OptionImage/図10.png");

	//オプションタイトルハンドル
	m_OptionTitleHundle = LoadGraph(OPTION_TITLE_PATH);

	//戻るボタンフラグ
	m_Return_Bottan_Flag = 0;

	//ボタン選択フラグ
	m_Bottan_Flag = 1;

	//オプションフレーム
	m_Option_Flame = 0;

	//マウスフレーム
	m_mouse_Flame = 0;
}

//オプション通常処理
void OPTION::StepOption()
{

	//ゲーム説明シーンへの遷移
	//enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_OptionSceneFlag = 0;
		//プレイ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_OPTION;

	}

	//オプションフレームをカウント
	m_Option_Flame++;

	//横移動処理
	//左
	if (IsKeyPush(KEY_INPUT_A) == 1)
	{
		//ボタン２を選択しているときボタン１に
		if (m_Bottan_Flag == 2)
		{
			//説明ボタン
			m_explain_bottan_x += 290;
			m_explain_size += 0.3f;
			m_explain2_size += 0.15f;
			m_explain2_bottan_x += 320;

			//アイテムボタン
			m_text_bottan_x += 300;
			m_text_size -= 0.3f;
			m_text2_size -= 0.25f;
			m_text2_bottan_x += 230;

			//キャラクターボタン
			m_character_bottan_x += 300;
			m_character2_bottan_x += 300;

			m_Bottan_Flag = 1;
		}
		//ボタン３を選択しているときにボタン２に
		if (m_Bottan_Flag == 3)
		{
			//説明ボタン
			m_explain_bottan_x += 290;
			m_explain2_bottan_x += 290;

			//アイテムボタン
			m_text_bottan_x += 300;
			m_text_size += 0.3f;
			m_text2_size += 0.25f;
			m_text2_bottan_x += 365;

			//キャラクターボタン
			m_character_bottan_x += 300;
			m_character2_bottan_x += 280;
			m_character_size -= 0.3f;
			m_character2_size -= 0.15f;

			m_Bottan_Flag = 2;
		}
	}

	//右
	if (IsKeyPush(KEY_INPUT_D) == 1)
	{
		//ボタン２を選択しているときボタン３に
		if (m_Bottan_Flag == 2)
		{
			//説明ボタン
			m_explain_bottan_x -= 290;
			m_explain2_bottan_x -= 290;

			//アイテムボタン
			m_text_bottan_x -= 300;
			m_text_size -= 0.3f;
			m_text2_size -= 0.25f;
			m_text2_bottan_x -= 365;

			//キャラクターボタン
			m_character_bottan_x -= 300;
			m_character2_bottan_x -= 280;
			m_character_size += 0.3f;
			m_character2_size += 0.15f;

			m_Bottan_Flag = 3;
		}
		//ボタン１を選択しているときボタン２に
		if (m_Bottan_Flag == 1)
		{
			//説明ボタン
			m_explain_bottan_x -= 290 ;
			m_explain_size -= 0.3f;
			m_explain2_size -= 0.15f;
			m_explain2_bottan_x -= 320;

			//アイテムボタン
			m_text_bottan_x -= 300;
			m_text_size += 0.3f;
			m_text2_size += 0.25f;
			m_text2_bottan_x -= 230;

			//キャラクターボタン
			m_character_bottan_x -= 300;
			m_character2_bottan_x -= 300;

			m_Bottan_Flag = 2;
		}


	}

	//タイトルシーンへの遷移
	//戻るボタンフラグがonだったら
	if (m_Return_Bottan_Flag == 1)
	{
		//左コントロールキー押されたなら
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			//タイトルシーンフラグをタイトルシーンに変更
			m_OptionSceneFlag = 2;

			//プレイ後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_OPTION;
		}
	}

	//オプションシーンに移動して1秒たったら
	if (m_Option_Flame >= 60)
	{
		//戻るボタンフラグをonに
		m_Return_Bottan_Flag = 1;
	}

}

//オプション描画処理
void OPTION::DrawOption()
{
	PlayMovieToGraph(m_BackGroundImageHandle[0] );

	//オプション画面描画
	DrawRotaGraph(610, 350, 0.7f, 0.0f, m_BackGroundImageHandle[0], true);

	if ((GetMovieStateToGraph(m_BackGroundImageHandle[0])) == 0) {
		//動画再生位置を初期化
		SeekMovieToGraph(m_BackGroundImageHandle[0], 0);
		PlayMovieToGraph(m_BackGroundImageHandle[0]);
	}

	//戻るボタン画像描画
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_BottanHandle[0], true);

	//矢印右ボタン画像描画
	DrawRotaGraph(720, 350, 0.9f, 0.0f, m_BackGroundImageHandle[4], true);

	//矢印左ボタン画像描画
	DrawRotaGraph(390, 350, 0.9f, 0.0f, m_BackGroundImageHandle[5], true);

	//説明ボタン画像描画
	DrawRotaGraph(m_explain_bottan_x, m_explain_bottan_y, m_explain_size, 0.0f, m_BottanHandle[1], true);
	DrawRotaGraph(m_explain2_bottan_x, m_explain_bottan_y, m_explain2_size, 0.0f, m_BackGroundImageHandle[1], true);
	
	//アイテムボタン画像描画
	DrawRotaGraph(m_text_bottan_x, m_text_bottan_y, m_text_size, 0.0f, m_BottanHandle[1], true);
	DrawRotaGraph(m_text2_bottan_x, m_text_bottan_y, m_text2_size, 0.0f, m_BackGroundImageHandle[2], true);

	//キャラクターボタン画像描画
	DrawRotaGraph(m_character_bottan_x, m_character_bottan_y, m_character_size, 0.0f, m_BottanHandle[1], true);
	DrawRotaGraph(m_character2_bottan_x, m_character_bottan_y, m_character2_size, 0.0f, m_BackGroundImageHandle[3], true);

	//マウス処理
	if (m_Return_Bottan_Flag == 1)
	{
		MouseClick();
	}

}

//オプション後処理
void OPTION::FinOption()
{

	DeleteGraph(m_BackGroundImageHandle[0]);

	if (m_OptionSceneFlag == 0)
	{
		//ゲーム説明INITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_GAME_EXPLAIN;
	}

	if (m_OptionSceneFlag == 1)
	{
		//メインメニューINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MEIN_MENU;
	}

	if (m_OptionSceneFlag == 2)
	{
		//タイトルINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}

void OPTION::MouseClick()
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
			//タイトルシーンへの遷移
			//画面上の戻るボタン押されたなら

			//オプションシーンフラグをタイトルシーンに変更
			m_OptionSceneFlag = 2;

			//'オプション後処理'へ移動
			g_CurrentSceneID = SCENE_ID_FIN_OPTION;
		}
		else
		{
			//押されていない
		}
	}

	//説明ボタン
	if (m_Bottan_Flag == 1)
	{
		if (IsHitRect(m_explain_bottan_x - 105, m_explain_bottan_y - 70, m_explain_bottan_w, m_explain_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//文字背景
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
			DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
			SetFontSize(12);
			DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<ゲーム説明>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

			//文字サイズをもとに
			SetFontSize(16);

			//左クリックしたとき
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				//オプションシーンへの遷移
				//画面上のオプションボタン押されたなら

				//オプションシーンフラグを説明シーンフラグに変更
				m_OptionSceneFlag = 0;

				//'タイトル後処理'へ移動
				g_CurrentSceneID = SCENE_ID_FIN_OPTION;

			}
			else
			{
				//押されていない
			}
		}
	}

	//アイテムボタン
	if (m_Bottan_Flag == 2)
	{
		if (IsHitRect(m_text_bottan_x - 105, m_text_bottan_y - 70, m_text_bottan_w, m_text_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//文字背景
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
			DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
			SetFontSize(12);
			DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<アイテム>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

			//文字サイズをもとに
			SetFontSize(16);

			//左クリックしたとき
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				////アイテムシーンへの遷移
				////画面上のオプションボタン押されたなら

				////オプションシーンフラグをアイテムシーンに変更
				//m_OptionSceneFlag = 0;

				////'タイトル後処理'へ移動
				//g_CurrentSceneID = SCENE_ID_FIN_OPTION;

			}
			else
			{
				//押されていない
			}
		}
	}

	//キャラクターボタン
	if (m_Bottan_Flag == 3)
	{
		if (IsHitRect(m_character_bottan_x - 105, m_character_bottan_y - 70, m_character_bottan_w, m_character_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//文字背景
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
			DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
			SetFontSize(12);
			DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<キャラクター>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

			//文字サイズをもとに
			SetFontSize(16);

			//左クリックしたとき
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				////キャラクターシーンへの遷移
				////画面上のオプションボタン押されたなら

				////オプションシーンフラグをキャラクターシーンに変更
				//m_OptionSceneFlag = 0;

				////'タイトル後処理'へ移動
				//g_CurrentSceneID = SCENE_ID_FIN_OPTION;

			}
			else
			{
				//押されていない
			}
		}
	}

	//左
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, 390, 350, 20) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<左へ>\nボタンを左クリックするか\nAキーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		//マウスフレーム
		m_mouse_Flame++;

		//ボタン２を選択しているときボタン１に
		if (m_mouse_Flame >= 20 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (m_Bottan_Flag == 2)
			{
				//説明ボタン
				m_explain_bottan_x += 290;
				m_explain_size += 0.3f;
				m_explain2_size += 0.15f;
				m_explain2_bottan_x += 320;

				//アイテムボタン
				m_text_bottan_x += 300;
				m_text_size -= 0.3f;
				m_text2_size -= 0.25f;
				m_text2_bottan_x += 230;

				//キャラクターボタン
				m_character_bottan_x += 300;
				m_character2_bottan_x += 300;

				//マウスフレーム
				m_mouse_Flame = 0;

				m_Bottan_Flag = 1;
			}

			//ボタン３を選択しているときにボタン２に
			if (m_Bottan_Flag == 3)
			{
				//説明ボタン
				m_explain_bottan_x += 290;
				m_explain2_bottan_x += 290;

				//アイテムボタン
				m_text_bottan_x += 300;
				m_text_size += 0.3f;
				m_text2_size += 0.25f;
				m_text2_bottan_x += 365;

				//キャラクターボタン
				m_character_bottan_x += 300;
				m_character2_bottan_x += 280;
				m_character_size -= 0.3f;
				m_character2_size -= 0.15f;

				//マウスフレーム
				m_mouse_Flame = 0;

				m_Bottan_Flag = 2;
			}

		}
	}

	//右
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, 720, 350, 20) == 1)
	{

		//マウスフレーム
		m_mouse_Flame++;

		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<右へ>\nボタンを左クリックするか\nDキーを押してください");

		//文字サイズをもとに
		SetFontSize(16);

		if (m_mouse_Flame >= 20 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//ボタン２を選択しているときボタン３に
			if (m_Bottan_Flag == 2)
			{
				//説明ボタン
				m_explain_bottan_x -= 290;
				m_explain2_bottan_x -= 290;

				//アイテムボタン
				m_text_bottan_x -= 300;
				m_text_size -= 0.3f;
				m_text2_size -= 0.25f;
				m_text2_bottan_x -= 365;

				//キャラクターボタン
				m_character_bottan_x -= 300;
				m_character2_bottan_x -= 280;
				m_character_size += 0.3f;
				m_character2_size += 0.15f;

				//マウスフレーム
				m_mouse_Flame = 0;

				m_Bottan_Flag = 3;
			}

			//ボタン１を選択しているときボタン２に
			if (m_Bottan_Flag == 1)
			{
				//説明ボタン
				m_explain_bottan_x -= 290;
				m_explain_size -= 0.3f;
				m_explain2_size -= 0.15f;
				m_explain2_bottan_x -= 320;

				//アイテムボタン
				m_text_bottan_x -= 300;
				m_text_size += 0.3f;
				m_text2_size += 0.25f;
				m_text2_bottan_x -= 230;

				//キャラクターボタン
				m_character_bottan_x -= 300;
				m_character2_bottan_x -= 300;

				//マウスフレーム
				m_mouse_Flame = 0;

				m_Bottan_Flag = 2;
			}
		}

		
	}

}