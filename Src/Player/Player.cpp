
#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Scene/Play/ScenePlay.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"
#include "../Screen/Screen.h"

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
	memset(m_ImageHandle, 0, sizeof(m_ImageHandle));

	//�A�j���[�V�����ԍ�
	m_Animation_Num = 0;

	//HP
	m_HP = 0.0f;

	//�d�̓t���O
	isGravity = false;

}

//�ǂݍ��ݏ���
void Player::Load()
{
	LoadDivGraph(PLAYER_IMAGE_PARH, 12, 3, 4, PLAYER_WIDTH, PLAYER_HIGHT, m_ImageHandle);
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
	m_move_x = 2.0f;		//X�ړ���
	m_move_y = 5.0f;		//Y�ړ���

	//�A�j���[�V�����ԍ�
	m_Animation_Num = 0;

	//HP
	m_HP = 1.0f;

	//�d�̓t���O
	isGravity = false;
}

//�ʏ폈��
void Player::Step()
{

}

//�`�揈��
void Player::Draw()
{
	DrawRotaGraph(m_posX + PLAYER_W_R, m_posY + PLAYER_H_R, 1.0f, 0.0f, m_ImageHandle[m_Animation_Num], true, false);
}

//�I������
void Player::Fin()
{
	for (int i = 0; i < PLAYER_IMAGE_NUM; i++) {
		DeleteGraph(m_ImageHandle[i]);
	}
}