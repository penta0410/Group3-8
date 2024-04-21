#pragma once

#include "DxLib.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"

const char PLAYER_IMAGE_PATH[] = { "Data/Player/sample08.png" };			//�摜�p�X

const char PLAYER_RUN_SE[] = { "data/Player/SE/�Ő��̏�𑖂�.mp3" };				//�����Ă���Ƃ���SE
const char PLAYER_JUMP_SE[] = { "" };				//�W�����v���Ă���Ƃ���SE


const int PLAYER_WIDTH = 32;											//���T�C�Y
const int PLAYER_HEIGHT = 32;											//�c�T�C�Y
const int PLAYER_W_R = 16;												//���̔��a
const int PLAYER_H_R = 16;												//�c�̔��a
const int PLAYER_IMAGE_NUM = 12;										//�摜�̔z��̐�
const int PLAYER_SPEED = 4;											//�v���C���[��X�X�s�[�h
const int PLAYER_Y_SPEED = 14;										//�v���C���[��Y�X�s�[�h
const int PLAYER_IMG_TOTAL_NUM = 12;									//�v���C���[�̉摜����
const int PLAYER_IMG_X_NUM = 3;											//�v���C���[�̉��̖���
const int PLAYER_IMG_Y_NUM = 4;											//�v���C���[�̏c�̖���

const int PLAYER_FREAM_CNT = 60;										//1�b�J�E���g
const int PLAYER_SPEED_UP_TIME = 10;									//���ԃJ�E���g������

const float GRAVITY = 0.7f;												//�d��

//�v���C���[�A�j���[�V�������
enum PlayerAnimationType {

	PLAYER_ANIMATION_TYPE_RUN = 0,
	PLAYER_ANIMATION_TYPE_JUMP,
	PLAYER_ANIMATION_TYPE_MIDAIR,
	PLAYER_ANIMATION_TYPE_FALL,
	PLAYER_ANIMATION_TYPE_LANDING,
	

	PLAYER_ANIMATION_TYPE_MAX,
};

//�v���C���[�̃A�j���[�V�����̏��
enum PlayerState {
	
	PLAYER_STATE_RUN = 0,
	PLAYER_STATE_JUMP,
	PLAYER_STATE_MIDAIR,
	PLAYER_STATE_FALL,
	PLAYER_STATE_LANDING,
	
};

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
	float m_move_x = 0.0f;
	float m_move_y = 0.0f;

	//�W�����v�����񂵂����ǂ���
	int m_JumpCnt = 0;

	//�摜�n���h��
	int m_ImageHandle[PLAYER_IMAGE_NUM];

	//�A�j���[�V�����֘A
	int m_Animation_Num;					//�A�j���[�V�����ԍ�
	int m_AnimationFreamCnt;				//�A�j���[�V�����p�t���[���J�E���g

	//SE
	int m_PlayerDashSE;					//�v���C���[���_�b�V�����Ă���Ƃ���SE

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

	//�v���C���[�A�j���[�V�������
	PlayerAnimationType now_animation;

	//�v���C���[�A�j���|�V�������
	PlayerState state;

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

	//�ړ���̍��W���擾
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//�ړ���̍��W��ݒ�
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posY);

	//���W���X�V
	void UpdatePos();

	//�i��ł���������`�F�b�N
	//�㉺���E
	void GetMoveDirection(bool* _dirArray);

	//�v���C���[�V�䏈��
	void PlayerCeiling();

	//�v���C���[�����O�`�F�b�N
	void StepPlayerMidAir();

	//�v���C���[�����X�V
	void StepPlayerFall();

	//�v���C���[���n����
	void PlayerLanding();

	//�v���C���[���W�����v�\���ǂ���
	bool CanJumpPlayer();

	//�v���C���[���󒆏�Ԃ��ǂ���
	bool IsAirPlayer();

	//�v���C���[�������Ă�����_�b�V��SE�𗬂�
	void PlaySoundDashSE();


};





