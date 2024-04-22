#include "SceneResult.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//初期化
void RESULT::Init(int m_score)
{
	ImageHandle = -1;
	MojiHandle	= -1;
	m_moji_x = 240;
	m_moji_y = 360;
	m_alpha = 0;

	IsMojiDraw = false;
	IsSceneFlag = false;
	IsScoreDrawFrag = false;

	score = m_score;

	m_NumposX = 840;
	m_NumposY = 390;

	for (int i = 0; i < 10; i++) {
		m_numberHandle[i] = 0;
	}

	num = 0;

	//リザルトループへ
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}
//ロード
void RESULT::Load()
{
	ImageHandle = LoadGraph(RESULT_PATH);
	MojiHandle = LoadGraph(RESULT_MOJI_PATH);
	for (int i = 0; i < 10; i++) {
		LoadDivGraph(RESULT_NUMBER_PATH, SCORE_NUMBER_MAX_NUM, SCORE_NUMBER_MAX_NUM, 1, 12, 24, m_numberHandle, false);
	}
}

//通常処理
void RESULT::Step()
{
	//タイトルシーンへの遷移
	if (IsKeyPush(KEY_INPUT_RETURN) && IsSceneFlag) {
		//シーンフラグをタイトルシーンに変更
		m_SceneFlag = 0;
		//リザルト後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}

	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		IsMojiDraw = true;

		IsSceneFlag = true;
	}
	if (IsMojiDraw)
	{
		if (m_alpha <= 200) {
			m_alpha += 10;
		}
		else {
			IsScoreDrawFrag = true;
		}
	}

}

//描画処理
void RESULT::Draw()
{

	DrawGraph(0, 0, ImageHandle, true);
	
	if (IsMojiDraw) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
		DrawRotaGraph(m_moji_x + MOJI_X, m_moji_y + MOJI_Y, 1.0f, 0.0f, MojiHandle, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_alpha);
	}

	int count = 0;

	int ItemScore = 0;

	num = 0;

	//スコアがゼロの時
	if (score == 0) {
		DrawRotaGraph(m_NumposX - count * 16, m_NumposY, 2.0f, 0.0f, m_numberHandle[0], true);
	}

	//DrawFormatString(100, 100, GetColor(255, 0, 0), "%d", score);

	ItemScore = score;

	//スコアがゼロ以上の時
	while (ItemScore > 0) {
		num = ItemScore % 10;
		ItemScore = ItemScore / 10;
		DrawRotaGraph(m_NumposX - count * 16, m_NumposY, 2.0f, 0.0f,m_numberHandle[num], true);
		count++;
	}

	DrawRotaGraph(m_UI_Image_posX + UI_W_R, m_UI_Image_posY + UI_H_R, 1.0f, 0.785, m_numberHandle[num], true);

	//デバッグ
//	SetFontSize(30);
//	DrawFormatString(100, 100, GetColor(255, 255, 255), "リザルトシーンです。", true);
//	DrawFormatString(100, 200, GetColor(255, 255, 255), "enterでタイトルシーン", true);
//	SetFontSize(16);
}

//後処理
void RESULT::Fin()
{

	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//プレイINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}