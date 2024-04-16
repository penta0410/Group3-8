//#include "DxLib.h"
//#include "Animation.h"
//#include <string.h>
//#include "../Scene/Scene.h"
//#include "../Common.h"
////#include "../Player/Player.h"
//
////�A�j���[�V����������
//void Animation::InitAnimation(ANIMATION_TYPE type)
//{
//	
//	//���ׂẴA�j���[�V�����̏��̕ϐ����N���A
//	for (int animation_index = 0; animation_index < ANIMATION_MAX_NUM;
//		animation_index++)
//	{
//		for (int anime_index = 0; anime_index < ANIMATION_NUM_MAX;
//			anime_index++)
//		{
//			//�v���C���[�摜�n���h��
//			Animation_Handle[type][anime_index] = 0;
//		}
//
//		//x���W
//		m_x[animation_index] = 0;
//
//		//y���W
//		m_y[animation_index] = 0;
//
//		//�g�p�t���O
//		m_isUse[animation_index] = false;
//
//		//�A�j����
//		m_animeNum[animation_index] = 0;
//
//		//���݂̃A�j���ԍ�
//		m_currentAnimeIndex[animation_index] = 0;
//
//		//�ꖇ������̕\������
//		m_changetime[animation_index] = 0.0f;
//
//		//���݂̃A�j������
//		m_currentChangetime[animation_index] = 0.0f;
//
//
//
//	}
//
//}
//
////�A�j���[�V�����ǂݍ���
//void Animation::LoadAnimation(ANIMATION_TYPE type, int anime_num)
//{
//	for (int create_index = 0; create_index < anime_num; create_index++)
//	{
//		for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//		{
//			//�ǂݍ��܂�Ă��Ȃ��A�j���[�V��������������
//			if (Animation_Handle[anime_index][0] == 0)
//			{
//				//�摜�𕪊��ǂݍ���
//				int success_flag = LoadDivGraph(AnimationFilePath[type],
//					AnimationImgNum[type],
//					AnimationImgSplitNum[type][0],
//					AnimationImgSplitNum[type][1],
//					AnimationImgSize[type][0],
//					AnimationImgSize[type][1],
//					Animation_Handle[type]);
//
//				//����
//				if (success_flag == 0)
//				{
//					//�A�j�������i�[
//					m_animeNum[anime_index] = AnimationImgNum[type];
//
//					//�ꖇ������̕\�����Ԃ�ݒ�
//					m_changetime[anime_index] = AnimationChangeTime[type];
//
//					//�A�j���V���[���̎�ނ�ݒ�
//					AnimationType[anime_index] = type;
//
//				}
//
//				//���ۂɂ�����炸������
//				break;
//
//			}
//		}
//	}
//
//}
//
////�A�j���[�V�����ʏ폈��
//void Animation::StepAnimation()
//{
//	for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//	{
//		//�g�p���Ȃ�A�j���@�ւ��o�߂����āA�A�j���ԍ����X�V����
//		if (m_isUse[anime_index] == true)
//		{
//			//�摜�؂�ւ��ɕK�v�Ȏ��Ԍo�߂�����
//			if (m_currentChangetime[anime_index] >= m_changetime[anime_index])
//			{
//				m_currentAnimeIndex[anime_index]++;		//���̉摜��
//				m_currentChangetime[anime_index] = 0.0f;	//�v�����ԃ��Z�b�g
//			
//				//���̉摜���Ȃ��Ȃ�
//				if (m_currentAnimeIndex[anime_index] >= m_animeNum[anime_index])
//				{
//					//�g�p���t���O��off��
//					m_isUse[anime_index] = false;
//
//
//					continue;
//				}
//			}
//
//			//���ԍX�V
//			m_currentChangetime[anime_index] += 1.0f / FRAME_RATE;
//		}
//	}
//}
//
////�A�j���[�V�����`�揈��
//void Animation::DrawAnimation(ANIMATION_TYPE type)
//{
//
//	for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//	{
//		//�g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
//		if (m_isUse[anime_index] == true)
//		{
//			DrawGraph(m_x[anime_index], m_y[anime_index],
//				Animation_Handle[type][m_currentAnimeIndex[anime_index]], true);
//		}
//	}
//}
//
////�A�j���[�V�����`��i���]�j����
//void Animation::DrawTurnAnimation(ANIMATION_TYPE type)
//{
//	for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//	{
//		//�g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
//		if (m_isUse[anime_index] == true)
//		{
//			DrawTurnGraph(m_x[anime_index], m_y[anime_index],
//				Animation_Handle[type][m_currentAnimeIndex[anime_index]], true);
//		}
//	}
//}
//
////�A�j���[�V�����̌㏈��
//void Animation::FinAnimetion()
//{
//	//���ׂẴA�j���[�V�������폜����
//	for (int animetion_index = 0; animetion_index < ANIMATION_MAX_NUM; animetion_index++)
//	{
//		//���ׂč폜����
//		for (int anime_index = 0; anime_index < ANIMATION_NUM_MAX; anime_index++)
//		{
//			//�[���ȊO�Ȃ�폜����
//			if (Animation_Handle[animetion_index][anime_index] != 0)
//			{
//				//�摜�폜
//				DeleteGraph(Animation_Handle[animetion_index][anime_index]);
//			
//				//�폜������[�������Ă���
//				Animation_Handle[animetion_index][anime_index] = 0;
//
//			}
//		}
//	}
//}
//
////�A�j���[�V�����̍Đ�
//void Animation::PlayAnimation(ANIMATION_TYPE type, float x, float y)
//{
//
//	//���g�p�A�j���[�V������T���čĐ�
//	for (int animation_index = 0; animation_index < ANIMATION_MAX_NUM; animation_index++)
//	{
//		//�g�p���Ȃ�ȉ��s��Ȃ�
//		if (m_isUse[animation_index] == true)
//		{
//			continue;
//		}
//
//		//�^�C�v����v����
//		if (AnimationType[animation_index] == type)
//		{
//			//�`�悷����W��ݒ�
//			m_x[animation_index] = x;
//			m_y[animation_index] = y;
//
//			//�v���p�̕ϐ����N���A
//			m_currentAnimeIndex[animation_index] = 0;
//			m_currentChangetime[animation_index] = 0.0f;
//
//			//�g�p���ɂ���
//			m_isUse[animation_index] = true;
//
//			break;
//		}
//	}
//
//}