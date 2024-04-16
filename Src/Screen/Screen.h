
#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "../Player/Player.h"

class Screen
{
private:

	int m_player_x = 0;
	int m_player_y = 0;

	float m_screenX = 0;
	float m_screenY = 0;

public:

	Screen();
	~Screen();

	//スクリーンのステップ
	void StepScreen(int x);

	//スクリーンのＸ座標を取得
	float GetScreenX();

	//スクリーンのＹ座標を取得
	float GetScreenY();
};

#endif
