#pragma once
#include "../Scene.h"

//タイトルクラス
class TITLE : public SCENE_BASE 
{
private:
	int m_BackHndl;
	int m_GroundHndl;
	int m_TitleHndl;
	int m_EnterHndl;

	//地面のスライド用の変数
	int m_GroundPosX;
	int m_GroundMaxPosX;

	//エンターの点滅用の変数
	int m_blink;
	int m_blinkflag;
public:

	//初期化
	void Init() override;
	//ロード
	void Load() override;
	//通常処理
	void Step()	override;
	//描画処理
	void Draw() override;
	//後処理
	void Fin() override;

};

