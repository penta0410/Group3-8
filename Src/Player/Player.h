#pragma once

class Player
{
private:

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

	//�U���t���[��
	int m_attack = 0;

	//�U���t���O
	int m_attackFlag = 0;

	//�U���A�j���[�V�����t���[��
	int m_attack_frame = 0;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W


public:
	

	
};





