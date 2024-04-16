
#ifndef __COLLISION_H__
#define __COLLISION_H__

// 円の当たり判定
// xy座標は中心座標
bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);

// 矩形の当たり判定
// xy座標は左上の座標
bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

#endif
