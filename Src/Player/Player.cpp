#pragma once

#include "Player.h"

//����������
void Player::Init()
{
	//���W
	m_posX = 0.0f;			//X���W
	m_posY = 0.0f;			//Y���W
	m_nextPosX = 0.0f;		//�ړ����X���W
	m_nextPosY = 0.0f;		//�ړ����Y���W
	old_pos_x = 0.0f;		//�ړ��O��X���W
	old_pos_y = 0.0f;		//�ړ��O��Y���W

	//�ړ���
	m_move_x = 0.0f;		//X�ړ���
	m_move_y = 0.0f;		//Y�ړ���

	//�摜�n���h��
	memset(m_ImageHandle, -1, sizeof(m_ImageHandle));

	//�A�j���[�V�����ԍ�
	m_Animation_Num = 0;

	//�v���C���[�t���[���J�E���g�^�C��
	SpeedFreamCnt = 0;
	//�v���C���[������������܂ł̎���
	PlayerUpSeedTime = 0;

	//HP
	m_HP = 0.0f;

	//�d�̓t���O
	isGravity = false;

}

//�ǂݍ��ݏ���
void Player::Load()
{
	LoadDivGraph(PLAYER_IMAGE_PATH, PLAYER_IMG_TOTAL_NUM, PLAYER_IMG_X_NUM, PLAYER_IMG_Y_NUM, PLAYER_WIDTH, PLAYER_HIGHT, m_ImageHandle);
}

//�����l�ݒ菈��
void Player::DefaultValue()
{
	//���W
	m_posX = 0.0f;			//X���W
	m_posY = 600.0f;			//Y���W
	m_nextPosX = 0.0f;		//�ړ����X���W
	m_nextPosY = 0.0f;		//�ړ����Y���W
	old_pos_x = 0.0f;		//�ړ��O��X���W
	old_pos_y = 0.0f;		//�ړ��O��Y���W

	//�ړ���
	m_move_x = PLAYER_SPEED;		//X�ړ���
	m_move_y = 0.0;					//Y�ړ���

	//�A�j���[�V�����֘A
	m_Animation_Num = 6;				//�A�j���[�V�����ԍ�
	m_AnimationFreamCnt = 0;			//�A�j���[�V�����p�t���[���J�E���g

	SpeedFreamCnt = 0;					//�v���C���[�̃X�s�[�h�A�b�v�p�t���[���J�E���g

	//HP
	m_HP = 1.0f;

	//�d�̓t���O
	isGravity = true;
}

//�ʏ폈��
void Player::Step()
{
	Control();			//���쏈��
	Move();				//�ړ�����	
	Animation();		//�A�j���[�V��������

	//�v���C���[�������Ȃ��悤�ɂ���
	if (m_nextPosY > 600)
	{
		m_posY = 600;
	}

	Gravity();			//�d�͗^����
}

//�`�揈��
void Player::Draw()
{
	//�f�o�b�O
	DrawFormatString(32, 32, GetColor(255, 0, 0), "%f, %f", m_posX, m_posY);

	//�v���C���[�摜
	DrawRotaGraph(m_posX + PLAYER_W_R - screen.GetScreenX() , m_posY + PLAYER_H_R - screen.GetScreenY(), 1.0f, 0.0f, m_ImageHandle[m_Animation_Num], true, false);
}

//�I������
void Player::Fin()
{
	//�v���C���[�̉摜���폜
	for (int i = 0; i < PLAYER_IMAGE_NUM; i++) {
		DeleteGraph(m_ImageHandle[i]);
	}
}

void Player::Move()
{
	//�t���[���J�E���g�����Z
	SpeedFreamCnt++;

	//�ړ���̍��W����
	m_nextPosX = m_posX;

	//�v���C���[�����Ɉړ���������
	m_posX += m_move_x;

	//�t���[���J�E���g��60�ɂȂ����Ƃ�
	if (SpeedFreamCnt >= PLAYER_FREAM_CNT)
	{
		//��b�o�߂�����
		PlayerUpSeedTime += 1;

		//0�ɖ߂�
		SpeedFreamCnt = 0;
	}
	//10�b�o�߂�����
	if (PlayerUpSeedTime >= PLAYER_SPEED_UP_TIME)
	{
		//�v���C���[�̃X�s�[�h������������
		m_move_x += 0.1;

		//0�ɖ߂�
		PlayerUpSeedTime = 0;
	}



}

//���쏈��
void Player::Control()
{
	//�W�����v����
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		m_move_y -= PLAYER_Y_SPEED;
	}
}

//�A�j���[�V����
void Player::Animation()
{
	//�t���[���J�E���g�����Z
	m_AnimationFreamCnt++;

	//1�b��������
	if (m_AnimationFreamCnt >= 15)
	{
		//�A�j���[�V�����ԍ���1���Z
		m_Animation_Num++;
		//�A�j���[�V���������Ό����ɂȂ�Ȃ��悤�ɂ���
		if (m_Animation_Num > 8)
		{
			//�A�j���[�V�������ŏ��ɖ߂�
			m_Animation_Num = 6;
		}

		//�A�j���[�V�����������I�������t���[���J�E���g��������
		m_AnimationFreamCnt = 0;
	}
}

//�d�͂�^����
void Player::Gravity()
{
	//�d�̓t���O���I���̎�
	if (isGravity)
	{
		//�d�͂�^����
		m_move_y += GRAVITY;

		//�v���C���[�̏d�͂̌��E�l
		if (m_move_y >= 12.0f)
		{
			m_move_y = 12.0;
		}
		//�v���C���[�̍��W��Y�����̃X�s�[�h�����Z
		m_posY += m_move_y;

	}
}

// �i��ł���������`�F�b�N
// �㉺���E�̏��ɂȂ��Ă���
void Player::GetMoveDirection(bool* _dirArray) {

	// �E�����̃`�F�b�N
	if (m_nextPosX > m_posX) {
		_dirArray[3] = true;

	}

	// �������̃`�F�b�N
	if (m_nextPosX < m_posX) {

		_dirArray[2] = true;

	}

	// �������̃`�F�b�N
	if (m_nextPosY > m_posY) {
		_dirArray[1] = true;

	}

	// ������̃`�F�b�N
	if (m_nextPosY < m_posY) {
		_dirArray[0] = true;

	}

}

//�󒆏�Ԃ��ǂ���
bool Player::IsAirPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_FALL:
		return true;

	}

	return false;

}

//�V�䏈��
void Player::PlayerCeiling()
{
	//���̈ړ��ʂ����Z�b�g
	m_move_y = 0.0f;

	if (IsAirPlayer())
	{
		//�v���C���[������ԂɕύX
		state = PLAYER_STATE_FALL;

	}

}

//���n����
void Player::PlayerLanding()
{
	//���̈ړ��ʂ����Z�b�g
	m_move_y = 0.0f;

	//�ҋ@��Ԃɖ߂�
	if (IsAirPlayer())
	{
		//�ҋ@��ԂɕύX
		state = PLAYER_STATE_STAND;

	}

}

//���W���X�V
void Player::SetNextPosX(int _posX)
{
	m_nextPosX = _posX;
}

//���W���X�V
void Player::SetNextPosY(int _posY)
{
	m_nextPosY = _posY;
}