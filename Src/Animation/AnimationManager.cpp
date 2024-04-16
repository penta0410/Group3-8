#include "DxLib.h"
#include "AnimationManager.h"
#include <string.h>

#define ANIMATION_NUM_MAX 100
#define ANIMATION_SPEED_MAX 100.0f

AnimationInfo g_animations[ANIMATION_NUM_MAX];
int g_animation_num = 0;

void InitAnimationManager() 
{
	/*memset(g_animations, 0, sizeof(g_animations));*/
}

int LoadAnimation(const char *file_path, int frame_width, int frame_height, int frame_num, int step_time, bool is_loop)
{
	// アクセス用ハンドル
	int handle = g_animation_num;

	AnimationInfo *anim = g_animations + g_animation_num;

	// ハンドルバッファを確保
	anim->handle_buf = (int*)malloc(sizeof(int) * frame_num);

	// 画像読み込み
	LoadDivGraph(file_path, frame_num, frame_num, 1, frame_width, frame_height, anim->handle_buf);

	// 各パラメータ設定
	anim->frame_num = frame_num;
	anim->frame_step_time = step_time;
	anim->time_cnt = 0;
	anim->now_frame = 0;
	anim->is_loop = is_loop;
	anim->is_playing = false;
	anim->is_end = false;

	// アニメーション個数を加算
	g_animation_num++;

	return handle;
}

void StepAnimationManager()
{
	AnimationInfo *anim = g_animations;

	// 各アニメーションを更新
	for (int i = 0; i < g_animation_num; i++, anim++) {

		// 再生していないアニメーションは更新しない
		if (!anim->is_playing) continue;

		// 終了しているアニメーションは更新しない
		if (anim->is_end) continue;

		// 更新時間チェック
		if (anim->time_cnt >= anim->frame_step_time) {
			// 次のフレームへ
			anim->now_frame++;
			// 最後のフレームまで再生したかどうか
			if (anim->now_frame >= anim->frame_num) {
				if (anim->is_loop) {
					// ループアニメーションであれば0フレーム目に戻す
					anim->now_frame = 0;
				}
				else {
					// そうでなければ終了フラグを立てる
					anim->is_end = true;
					// 最後のフレームで停止
					anim->now_frame--;
				}
			}
			// カウンターを戻す
			anim->time_cnt = 0;
		}
		else {
			// カウンターを進める
			anim->time_cnt++;
		}
	}
}

void FinAnimationManager()
{
	UnloadAnimation();
}

void UnloadAnimation()
{
	AnimationInfo *anim = g_animations;

	// アニメーション削除
	for (int i = 0; i < g_animation_num; i++, anim++) {
		// 画像を削除
		for (int j = 0; j < anim->frame_num; j++) {
			DeleteGraph(anim->handle_buf[j]);
		}
		//// ハンドルバッファを解放
		//free(anim->handle_buf);
	}
}

// アニメーション再生
void PlayAnimation(int handle)
{
	AnimationInfo *anim = g_animations + handle;
	anim->is_playing = true;
	anim->time_cnt = 0;
	anim->now_frame = 0;
	anim->is_end = false;
}

// アニメーション停止
void StopAnimation(int handle)
{
	AnimationInfo *anim = g_animations + handle;
	anim->is_playing = false;
	anim->time_cnt = 0;
	anim->now_frame = 0;
	anim->is_end = true;
}

// 渡されているアニメーションの現在のフレームのハンドルを返す
int GetAnimationGraphicHnadle(int handle)
{

	int now_frame = g_animations[handle].now_frame;
	return g_animations[handle].handle_buf[now_frame];
}
