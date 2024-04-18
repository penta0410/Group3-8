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
	PlayerFreamCnt = 0;
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
	LoadDivGraph(PLAYER_IMAGE_PATH, 12, 3, 4, PLAYER_WIDTH, PLAYER_HIGHT, m_ImageHandle);
}

//�����l�ݒ菈��
void Player::DefaultValue()
{
	//���W
	m_posX = 0.0f;			//X���W
	m_posY = 0.0f;			//Y���W
	m_nextPosX = 0.0f;		//�ړ����X���W
	m_nextPosY = 0.0f;		//�ړ����Y���W
	old_pos_x = 0.0f;		//�ړ��O��X���W
	old_pos_y = 0.0f;		//�ړ��O��Y���W

	//�ړ���
	m_move_x = 2.5f;		//X�ړ���
	m_move_y = 5.0f;		//Y�ړ���

	//�A�j���[�V�����ԍ�
	m_Animation_Num = 0;

	PlayerFreamCnt = 0;

	//HP
	m_HP = 1.0f;

	//�d�̓t���O
	isGravity = false;
}

//�ʏ폈��
void Player::Step()
{
	PlayerFreamCnt++;

	//�ړ�����
	Move();
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
	for (int i = 0; i < PLAYER_IMAGE_NUM; i++) {
		DeleteGraph(m_ImageHandle[i]);
	}
}

void Player::Move()
{
	m_posX += m_move_x;

	//�t���[���J�E���g��60�ɂȂ����Ƃ�
	if (PlayerFreamCnt >= PLAYER_FREAM_CNT)
	{
		//��b�o�߂�����
		PlayerUpSeedTime += 1;

		PlayerFreamCnt = 0;
	}
	//10�b�o�߂�����
	if (PlayerUpSeedTime >= PLAYER_SPEED_UP_TIME)
	{
		//�v���C���[�̃X�s�[�h������������
		m_move_x += 0.1;

		PlayerUpSeedTime = 0;
	}

}