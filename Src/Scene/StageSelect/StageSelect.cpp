#include "DxLib.h"
#include "StageSelect.h"
#include "../Scene.h"
#include "../../Score/Score.h"
#include "../../Input/Input.h"
#include "../Meinmenu/MeinmenuScene.h"
//=============================
// ステージセレクトシーン
//=============================


MEIN_MENU m_meinmenu;

//ステージセレクト初期化
void STAGE_SELECT::InitStageSelect()
{
	//メインメニュー
	m_meinmenu.InitMeinMnu();

	//ステージセレクトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

	//ステージセレクト画面画像
	m_StageSelectImageHandle[0] = LoadGraph(STAGE_SELECT_BACK_PATH);
	
	//ステージセレクトアイコン画像
	m_StageSelectImageHandle[1] = LoadGraph(STAGE_SELECT_STAGE_ICON_PATH);

	//ステージセレクトアイコン背景画像
	m_StageSelectImageHandle[2] = LoadGraph(STAGE_SELECT_ICON_BACKGROUND_PATH);

	
	

	LoadDivGraph(PLAYER_STAND_PATH, 12,
		10, 2, 80, 96, m_playerhandle);

	//プレイヤー残機画像
	m_StageSelectImageHandle[6] = LoadGraph(PLAYER_REMAIN_PATH);

	//道
	m_StageSelectImageHandle[4] = LoadGraph(STAGE_SELECT_LOAD_PATH);

	//プレイヤー情報表示欄画像パス
	m_StageSelectImageHandle[5] = LoadGraph(PLAYER_INFO_FIELD);

	//コイン画像
	m_StageSelectImageHandle[7] = LoadGraph(KOIN_PATH);

	//隠しコイン画像
	m_StageSelectImageHandle[8] = LoadGraph(HIDE_KOIN_PATH);

	//アイテム画像
	m_StageSelectImageHandle[9] = LoadGraph(ITEM_PATH);

	//ステージアイコン画像
	m_StageSelectImageHandle[10] = LoadGraph(STAGE_ICON_PATH);

	//ステージセレクト動画ハンドル
	m_Stageselect_Movie_handle = LoadGraph(STAGE_SELECT_MOVIE_PATH);

	//ステージ１文字ハンドル
	m_StageSelectImageHandle[11] = LoadGraph(STAGE_1_PATH);

	//ローディング画面
	m_StageSelectImageHandle[12] = LoadGraph("Data/StageSelectImage/0125 (1)(1).mp4");

	m_StageMoveFlag = 1;

	//ステージセレクトシーンフラグ
	m_StageSelectFlag = 0;

}

//ステージセレクト通常処理
void STAGE_SELECT::StepStageSelect()
{
	//メインメニュー処理
	//ステージセレクトフラグが１の時
	if (m_StageSelectFlag == 1)
	{
		//メインメニュー処理
		m_meinmenu.StepMeinMnu();
	}

	//ステージセレクト処理
	if (m_StageSelectFlag == 0)
	{
		//プレイシーンへの遷移
		//Enterキー押されたなら
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			m_StageSelectFlag = 0;
			//ステージセレクト後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}

		//メインメニューへ
		//tabキー押されたなら
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			m_StageSelectFlag = 1;
		}

		//プレイヤー移動
		//横移動処理
		//左
		if (IsKeyPush(KEY_INPUT_A) == 1)
		{
			//プレイヤーがステージ２にいるときステージ１の位置に
			if (m_Stage_Flag == 2)
			{
				m_player_move_x -= 320;
				m_player_move_y -= 200;

				m_Stage_Flag = 1;
			}
			//プレイヤーがステージ３にいるときステージ２の位置に
			if (m_Stage_Flag == 3)
			{
				m_player_move_x -= 320;
				m_player_move_y += 200;

				m_Stage_Flag = 2;
			}
		}

		//右
		if (IsKeyPush(KEY_INPUT_D) == 1)
		{
			//プレイヤーがステージ２にいるときステージ３に
			if (m_Stage_Flag == 2)
			{
				m_player_move_x += 320;
				m_player_move_y -= 200;

				m_Stage_Flag = 3;
			}
			//プレイヤーがステージ１にいるときステージ２に
			if (m_Stage_Flag == 1)
			{
				m_player_move_x += 320;
				m_player_move_y += 200;

				m_Stage_Flag = 2;
			}


		}
	}
}

//ステージセレクト描画処理
void STAGE_SELECT::DrawStageSelect(int koin, int hidekoin, int playerremain)
{
	if (m_meinmenu.GetReturnFlag() == 0 && m_StageMoveFlag == 1)
	{
		PlayMovieToGraph(m_StageSelectImageHandle[12]);

		//ステージセレクト遷移描画
		DrawGraph(0, 0, m_StageSelectImageHandle[12], true);

	}

	if ((GetMovieStateToGraph(m_StageSelectImageHandle[12])) == 0)
	{
		m_StageMoveFlag = 0;

		PlayMovieToGraph(m_Stageselect_Movie_handle);

		//ステージセレクト動画描画
		DrawGraph(0, 0, m_Stageselect_Movie_handle, true);

		if ((GetMovieStateToGraph(m_Stageselect_Movie_handle)) == 0) {
			//動画再生位置を初期化
			SeekMovieToGraph(m_Stageselect_Movie_handle, 0);
			PlayMovieToGraph(m_Stageselect_Movie_handle);
		}

		//道1
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawRotaGraph(330, 450, 0.43f, 0.56f, m_StageSelectImageHandle[4], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//道2
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawRotaGraph(660, 460, 0.43f, 2.57f, m_StageSelectImageHandle[4], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ステージセレクトアイコン
		//ステージ１
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawRotaGraph(180, 350, 0.46f, 0.0f, m_StageSelectImageHandle[2], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawRotaGraph(181, 349, 0.66f, 0.0f, m_StageSelectImageHandle[1], true);

		//ステージフラグが１の時に
		if (m_Stage_Flag == 1)
		{
			//ステージアイコン
			DrawRotaGraph(220, 200, 0.8f, 0.0f, m_StageSelectImageHandle[10], true);

			//ステージ１文字
			DrawRotaGraph(170, 130, 0.9f, -0.1f, m_StageSelectImageHandle[11], true);

		}

		//ステージ2
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawRotaGraph(500, 550, 0.46f, 0.0f, m_StageSelectImageHandle[2], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawRotaGraph(501, 549, 0.66f, 0.0f, m_StageSelectImageHandle[1], true);

		//ステージ3
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawRotaGraph(820, 350, 0.46f, 0.0f, m_StageSelectImageHandle[2], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawRotaGraph(821, 349, 0.66f, 0.0f, m_StageSelectImageHandle[1], true);

		//プレイヤー情報表示欄
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 80);
		DrawRotaGraph(90, 55, 0.22f, 0.0f, m_StageSelectImageHandle[5], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//プレイヤー
		DrawRotaGraph(180 + m_player_move_x, 315 + m_player_move_y, 1.0f, 0.0f, m_playerhandle[0], true);

		//プレイヤー残機
		DrawRotaGraph(215, 55, 0.66f, 0.0f, m_StageSelectImageHandle[6], true);

		//コイン
		DrawRotaGraph(150, 55, 0.45f, 0.0f, m_StageSelectImageHandle[7], true);

		//隠しコイン
		DrawRotaGraph(90, 55, 0.70f, 0.0f, m_StageSelectImageHandle[8], true);

		//コイン枚数描画
		DrawFormatString(170, 60, GetColor(255, 255, 255), "X%d", koin, true);

		//隠しコイン枚数描画
		DrawFormatString(110, 60, GetColor(255, 255, 255), "X%d", hidekoin, true);

		//プレイヤー残機数描画
		DrawFormatString(235, 60, GetColor(255, 255, 255), "X%d", playerremain, true);

		//メインメニュー描画
		//ステージセレクトフラグが１の時
		if (m_StageSelectFlag == 1)
		{
			m_meinmenu.DrawMeinMnu();	//動いてる
		}
	}

}

//ステージセレクト後処理
void STAGE_SELECT::FinStageSelect()
{

	

	DeleteGraph(m_StageSelectImageHandle[12]);

	DeleteGraph(m_Stageselect_Movie_handle);

	//メインメニュー
	if (m_StageSelectFlag == 1)
	{
		m_meinmenu.FinMeinMnu();
	}

	if (m_StageSelectFlag == 0 && m_Stage_Flag == 1)
	{

		//プレイシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

//セットフラグ
void STAGE_SELECT::SetFlag(int flag)
{

	m_StageMoveFlag = flag;

}