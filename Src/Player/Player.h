#pragma once

#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const char PLAYER_IMAGE_PATH[] = { "Data/Player/pipo-simpleenemy01g.png" };			//�摜�p�X

const int PLAYER_WIDTH = 32;														//���T�C�Y
const int PLAYER_HIGHT = 32;														//�c�T�C�Y
const int PLAYER_W_R = 16;															//���̔��a
const int PLAYER_H_R = 16;															//�c�̔��a
const int PLAYER_IMAGE_NUM = 12;													//�摜�̔z��̐�
const float PLAYER_SPEED = 2.5;														//�v���C���[��X�X�s�[�h
const float PLAYER_Y_SPEED = 15.0f;													//�v���C���[��Y�X�s�[�h
const int PLAYER_IMG_TOTAL_NUM = 12;												//�v���C���[�̉摜����
const int PLAYER_IMG_X_NUM = 3;														//�v���C���[�̉��̖���
const int PLAYER_IMG_Y_NUM = 4;														//�v���C���[�̏c�̖���

const int PLAYER_FREAM_CNT = 60;													//1�b�J�E���g
const int PLAYER_SPEED_UP_TIME = 10;												//���ԃJ�E���g������

const float GRAVITY = 0.7f;															//�d��


class Player
{
private:
	//�N���X�錾
	Screen screen;

	//�v���C���[�̍��W
	float m_posX = 0.0f;
	float m_posY = 0.0f;

	//�ړ���̍��W
	float m_nextPosX = 0.0f;
	float m_nextPosY = 0.0f;

	//�ړ��O�̍��W
	float old_pos_x = 0.0f;
	float old_pos_y = 0.0f;

	//�v���C���[�ړ���
	float m_move_x = 0;
	float m_move_y = 0;

	//�摜�n���h��
	int m_ImageHandle[PLAYER_IMAGE_NUM];

	//�A�j���[�V�����֘A
	int m_Animation_Num;					//�A�j���[�V�����ԍ�
	int m_AnimationFreamCnt;				//�A�j���[�V�����p�t���[���J�E���g

	//�v���C���[�摜���]�t���O
	int m_PlayerVisualDirection = 0;

	//�ύX����O�̏��
	int m_animation_before = 0;

	//�d�̓t���O
	bool isGravity = false;

	//�v���C���[��HP
	int m_HP = 0;

	//�v���C���[�ړ��t���O
	int m_PlayerMoveFlag = 0;

	//�`��t���O
	int m_drawflag = 0;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	//�t���[���J�E���g
	int SpeedFreamCnt;

	//�v���C���[������������܂ł̎���
	int PlayerUpSeedTime;

public:
	//������
	void Init();
	
	//�ǂݍ���
	void Load();

	//�����l
	void DefaultValue();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	//�I������
	void Fin();

	//�ړ�����
	void Move();

	//���쏈��
	void Control();

	void Animation();
	
	//�d�͂�^����
	void Gravity();

	//���W�擾
	float GetPosX() { return m_posX; }		//X���W
	float GetPosY() { return m_posY; }		//Y���W



};





