#include "DxLib.h"
#include "../FPS/fps.h"
#include "../Common.h"
#include "../Scene/Title/SceneTitle.h"

TITLE m_title;

//FPS計算
void CalcFPS()
{
	//前回のFPSを計算した時間からの経過時間を求める
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//前回のFPSを計算した時間から
	//１秒以上経過していたらFPSを計算する
	if (difTime > 1000)
	{
		//フレーム回数をミリ秒に合わせる
		//小数まで出したいのでfloatにキャスト
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPSを求める
		//理想の数値は 60000 / 1000 で 60 となる
		frameRateInfo.fps = frameCount / difTime;

		//フレームレートカウントをクリア
		frameRateInfo.count = 0;

		//FPSを計算した時間を更新
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS表示（デバッグ用）
void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);

	if (m_title.m_start_animetion_flag == 0)
	{
		DrawFormatString(1190, 700, color, "FPS[%.2f]", frameRateInfo.fps);
	}

}