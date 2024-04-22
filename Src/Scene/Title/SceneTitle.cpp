
#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"

//画像読み込み
#define TITEL_BACK_PATH	"Data/Title/BackGround.png"
#define TITEL_GROUND_PATH "Data/Title/ground.png"
#define TITLE_PATH	"Data/Title/Title.png"
#define TITLE_ENTER_PATH "Data/Title/Enter.png"

//=============================
// タイトルシーン
//=============================

//初期化
void TITLE::Init()
{
	//ハンドルの初期化
	m_BackHndl = 0;			//背景
	m_GroundHndl = 0;		//地面
	m_TitleHndl = 0;		//タイトル名
	m_EnterHndl = 0;		//エンター
	m_BGMHndl = -1;			//タイトル画面BGM

	//地面のスライド用の変数の初期化
	m_GroundPosX = 0;
	m_GroundMaxPosX = 1280;

	//エンターの点滅用の変数の初期化
	m_blink = 0;
	m_blinkflag = 0;

	//タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//ロード
void TITLE::Load()
{
	m_BGMHndl = LoadSoundMem(TITLE_BGM);
	m_BackHndl = LoadGraph(TITEL_BACK_PATH);
	m_GroundHndl = LoadGraph(TITEL_GROUND_PATH);
	m_TitleHndl = LoadGraph(TITLE_PATH);
	m_EnterHndl = LoadGraph(TITLE_ENTER_PATH);
}

void TITLE::PlayTitleMusic()
{
	PlaySoundMem(m_BGMHndl, DX_PLAYTYPE_LOOP);
}

//通常処理
void TITLE::Step()
{

	//地面のスクロール
	m_GroundPosX -= 4;
	m_GroundMaxPosX -= 4;
	if (m_GroundPosX <= -1280) {
		m_GroundPosX = 1280;
	}
	if (m_GroundMaxPosX <= -1280) {
		m_GroundMaxPosX = 1280;
	}

	//エンターの点滅処理
	switch (m_blinkflag)
	{
	case0:
		m_blink += 9;
		if (m_blink >= 255) {
			m_blinkflag = 1;
		}
		break;
	case1:
		m_blink -= 9;
		if (m_blink <= 100) {
			m_blinkflag = 0;
		}
		break;
	}

	//メインメニューシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//シーンフラグをプレイシーンに変更
		m_SceneFlag = 0;
		//タイトル後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}

}

//描画処理
void TITLE::Draw()
{
	DrawGraph(0, 0, m_BackHndl, true);
	DrawGraph(m_GroundPosX, 600, m_GroundHndl, true);
	DrawGraph(m_GroundMaxPosX, 600, m_GroundHndl, true);
	DrawGraph(300, 50, m_TitleHndl, true);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_blink);
	DrawGraph(300, 100, m_EnterHndl, true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//デバッグ
	//SetFontSize(30);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "タイトルシーンです。", true);
	//DrawFormatString(100, 200, GetColor(255, 255, 255), "enterでメインメニューシーン", true);
	//SetFontSize(16);
}

//消去処理
void TITLE::Fin()
{
	//削除
	DeleteSoundMem(m_BGMHndl);

	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//INITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

