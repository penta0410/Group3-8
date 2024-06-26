
#include "DxLib.h"
#include "Collision.h"

// 円の当たり判定
// x座標、y座標は中心座標
bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2)
{
	//２つの半径の合計
	float sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//円同士の長さ
	float x_len = x1 - x2;
	x_len *= x_len;

	float y_len = y1 - y2;
	y_len *= y_len;

	//円の当たり判定
	if(sum_radius > x_len + y_len)
	{
		return true;
	}

	return false;
}

// 矩形の当たり判定
// xy座標は左上の座標
bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if( x1 < x2 + w2 && x1 + w1 > x2 &&
		y1 + h1 > y2 && y1 < y2 + h2 )
	{
		return true;
	}

	return false;
}

