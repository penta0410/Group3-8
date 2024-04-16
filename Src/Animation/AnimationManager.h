#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

struct AnimationInfo {
	int *handle_buf = 0;
	int frame_num = 0;
	int now_frame = 0;
	int frame_step_time = 0;
	int time_cnt = 0;
	bool is_loop = 0;
	bool is_playing = 0;
	bool is_end = 0;
};

void InitAnimationManager();
int  LoadAnimation(const char *file_path, int frame_width, int frame_height, int frame_num, int step_time, bool is_loop = true);
void StepAnimationManager();
void FinAnimationManager();
void UnloadAnimation();

void PlayAnimation(int handle);
void StopAnimation(int handle);

int GetAnimationGraphicHnadle(int handle);

#endif


