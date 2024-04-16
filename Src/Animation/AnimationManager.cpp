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
	// �A�N�Z�X�p�n���h��
	int handle = g_animation_num;

	AnimationInfo *anim = g_animations + g_animation_num;

	// �n���h���o�b�t�@���m��
	anim->handle_buf = (int*)malloc(sizeof(int) * frame_num);

	// �摜�ǂݍ���
	LoadDivGraph(file_path, frame_num, frame_num, 1, frame_width, frame_height, anim->handle_buf);

	// �e�p�����[�^�ݒ�
	anim->frame_num = frame_num;
	anim->frame_step_time = step_time;
	anim->time_cnt = 0;
	anim->now_frame = 0;
	anim->is_loop = is_loop;
	anim->is_playing = false;
	anim->is_end = false;

	// �A�j���[�V�����������Z
	g_animation_num++;

	return handle;
}

void StepAnimationManager()
{
	AnimationInfo *anim = g_animations;

	// �e�A�j���[�V�������X�V
	for (int i = 0; i < g_animation_num; i++, anim++) {

		// �Đ����Ă��Ȃ��A�j���[�V�����͍X�V���Ȃ�
		if (!anim->is_playing) continue;

		// �I�����Ă���A�j���[�V�����͍X�V���Ȃ�
		if (anim->is_end) continue;

		// �X�V���ԃ`�F�b�N
		if (anim->time_cnt >= anim->frame_step_time) {
			// ���̃t���[����
			anim->now_frame++;
			// �Ō�̃t���[���܂ōĐ��������ǂ���
			if (anim->now_frame >= anim->frame_num) {
				if (anim->is_loop) {
					// ���[�v�A�j���[�V�����ł����0�t���[���ڂɖ߂�
					anim->now_frame = 0;
				}
				else {
					// �����łȂ���ΏI���t���O�𗧂Ă�
					anim->is_end = true;
					// �Ō�̃t���[���Œ�~
					anim->now_frame--;
				}
			}
			// �J�E���^�[��߂�
			anim->time_cnt = 0;
		}
		else {
			// �J�E���^�[��i�߂�
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

	// �A�j���[�V�����폜
	for (int i = 0; i < g_animation_num; i++, anim++) {
		// �摜���폜
		for (int j = 0; j < anim->frame_num; j++) {
			DeleteGraph(anim->handle_buf[j]);
		}
		//// �n���h���o�b�t�@�����
		//free(anim->handle_buf);
	}
}

// �A�j���[�V�����Đ�
void PlayAnimation(int handle)
{
	AnimationInfo *anim = g_animations + handle;
	anim->is_playing = true;
	anim->time_cnt = 0;
	anim->now_frame = 0;
	anim->is_end = false;
}

// �A�j���[�V������~
void StopAnimation(int handle)
{
	AnimationInfo *anim = g_animations + handle;
	anim->is_playing = false;
	anim->time_cnt = 0;
	anim->now_frame = 0;
	anim->is_end = true;
}

// �n����Ă���A�j���[�V�����̌��݂̃t���[���̃n���h����Ԃ�
int GetAnimationGraphicHnadle(int handle)
{

	int now_frame = g_animations[handle].now_frame;
	return g_animations[handle].handle_buf[now_frame];
}
