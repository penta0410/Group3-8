
#include <DxLib.h>
#include "Screen.h"
#include "../Player/Player.h"
#include "../Common.h"
#include "../Scene/Play/ScenePlay.h"

//スクリーンのワールド座標
Screen::Screen()
{
	m_player_x = 0;
	m_player_y = 0;

	m_screenX = 0;
	m_screenY = 0;
}

Screen::~Screen() {}

//スクリーンのステップ
void Screen::StepScreen(int x)
{
	//自機が中心になるように、
	//スクリーン座標を設定

	m_screenX = x - WINDOW_WIDTH / 2;

}


//スクリーンのＸ座標を取得
float Screen::GetScreenX()
{
	return m_screenX;
}

//スクリーンのＹ座標を取得
float Screen::GetScreenY()
{
	return m_screenY;
}



