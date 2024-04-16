
#include "DxLib.h"
#include "Collision.h"

// ‰~‚Ì“–‚½‚è”»’è
// xÀ•WAyÀ•W‚Í’†SÀ•W
bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2)
{
	//‚Q‚Â‚Ì”¼Œa‚Ì‡Œv
	float sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//‰~“¯m‚Ì’·‚³
	float x_len = x1 - x2;
	x_len *= x_len;

	float y_len = y1 - y2;
	y_len *= y_len;

	//‰~‚Ì“–‚½‚è”»’è
	if(sum_radius > x_len + y_len)
	{
		return true;
	}

	return false;
}

// ‹éŒ`‚Ì“–‚½‚è”»’è
// xyÀ•W‚Í¶ã‚ÌÀ•W
bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if( x1 < x2 + w2 && x1 + w1 > x2 &&
		y1 + h1 > y2 && y1 < y2 + h2 )
	{
		return true;
	}

	return false;
}

