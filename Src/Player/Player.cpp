#pragma once

#include "Player.h"

//����������
void Player::Init()
{
	//���W
	m_posX = 0;			//X���W
	m_posY = 0;			//Y���W
	m_nextPosX = 0;		//�ړ����X���W
	m_nextPosY = 0;		//�ړ����Y���W
	old_pos_x = 0;		//�ړ��O��X���W
	old_pos_y = 0;		//�ړ��O��Y���W

	//�ړ���
	m_move_x = 0;		//X�ړ���
	m_move_y = 0;		//Y�ړ���

	CoinNum = 0;

	//�摜�n���h��
	memset(m_ImageHandle, -1, sizeof(m_ImageHandle));

	//�A�j���[�V�����ԍ�
	m_Animation_Num = 0;

	//�v���C���[�t���[���J�E���g�^�C��
	SpeedFreamCnt = 0;
	//�v���C���[������������܂ł̎���
	PlayerUpSeedTime = 0;

	//HP
	m_HP = 0;

	//SE
	m_PlayerDashSE = -1;

	//�v���C���[���G�t���O
	PlayerInviFlag = false;

	//�v���C���[���G�t���[��
    PlayerInviFlame = 0;

	//�d�̓t���O
	isGravity = false;

}

//�ǂݍ��ݏ���
void Player::Load()
{
	//�摜�ǂݍ���
	LoadDivGraph(PLAYER_IMAGE_PATH, PLAYER_IMG_TOTAL_NUM, PLAYER_IMG_X_NUM, PLAYER_IMG_Y_NUM, PLAYER_WIDTH, PLAYER_HEIGHT, m_ImageHandle);

	//SE
	m_PlayerDashSE = LoadSoundMem(PLAYER_RUN_SE);

}

//�����l�ݒ菈��
void Player::DefaultValue()
{
	//���W
	m_posX = 350;			//X���W
	m_posY = 350;			//Y���W
	m_nextPosX = 0;		//�ړ����X���W
	m_nextPosY = 0;		//�ړ����Y���W
	old_pos_x = 0;		//�ړ��O��X���W
	old_pos_y = 0;		//�ړ��O��Y���W

	//�ړ���
	m_move_x = PLAYER_SPEED;		//X�ړ���
	m_move_y = 0;					//Y�ړ���

	//�A�j���[�V�����֘A
	m_Animation_Num = 6;				//�A�j���[�V�����ԍ�
	m_AnimationFreamCnt = 0;			//�A�j���[�V�����p�t���[���J�E���g

	SpeedFreamCnt = 0;					//�v���C���[�̃X�s�[�h�A�b�v�p�t���[���J�E���g

	CoinNum = 0;

	//HP
	m_HP = 100;

	//�v���C���[���G�t���O
	PlayerInviFlag = false;

	//�d�̓t���O
	isGravity = false;
}

//�ʏ폈��
void Player::Step()
{
	//�ړ��O�̍��W���L�^����
	old_pos_x = m_posX;
	old_pos_y = m_posY;

	//�ړ�����	
	//Move();				

	//���쏈��
	Control();

	//�A�j���[�V��������
	Animation();		

	Gravity();			//�d�͗^����

	//�󒆂ɂ��Ȃ���Ώ�Ԃ����Z�b�g
	if (!IsAirPlayer())
	{
		state = PLAYER_STATE_RUN;
	}

	//�����O�X�V
	StepPlayerMidAir();

	//�����X�V
	StepPlayerFall();

}

//�`�揈��
void Player::Draw()
{
	////�f�o�b�O
	//DrawFormatString(32, 32, GetColor(255, 0, 0), "%f, %f", m_posX, m_posY);

	//�v���C���[�摜
	DrawRotaGraph(m_posX + PLAYER_W_R , m_posY + PLAYER_H_R, 3.0f, 0.0f, m_ImageHandle[m_Animation_Num], true, false);

	//�v���C���[�����`��
	DrawHp();
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
	m_nextPosY = m_posY;

}

//���쏈��
void Player::Control()
{
	m_nextPosX = m_posX;
	m_nextPosY = m_posY;

	//�W�����v����
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		if (CanJumpPlayer() == true)
		{
			m_move_y -= PLAYER_Y_SPEED;

			m_JumpCnt++;
			
			if (m_JumpCnt >= 2) {
				//�W�����v��Ԃɐݒ�
				state = PLAYER_STATE_JUMP;

				m_JumpCnt = 0;
			}
		}
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
	//�d��on
	isGravity = true;

	//�d�͂̌v�Z
	m_move_y += GRAVITY;
	if (m_move_y > 15)
	{
		// Y�����̈ړ��ʂ𐧌�
		m_move_y = 15;
	}
	if (isGravity)
	{
		m_nextPosY += m_move_y;
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

//�����O�`�F�b�N
void Player::StepPlayerMidAir()
{
	//�W�����v����ɓ��B����Q�t���[���O�ɃA�j���[�V�������Đ�����
	if (state == PLAYER_STATE_JUMP && m_move_y > -GRAVITY * 2)
	{
		//�󒆏�ԂɕύX
		state = PLAYER_STATE_MIDAIR;
	}
}

//�����X�V
void Player::StepPlayerFall()
{
	//�������n�߂ĂT�t���[����ɗ�����Ԃɂ���
	if (m_move_y > GRAVITY * 5)
	{
		//������ԂɕύX
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
		//��ԂɕύX
		state = PLAYER_STATE_RUN;
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

//�W�����v�\���ǂ���
bool Player::CanJumpPlayer()
{
	switch (state)
	{
	case PLAYER_STATE_JUMP:
	case PLAYER_STATE_MIDAIR:
	case PLAYER_STATE_FALL:
		return false;

	}

	return true;

}

//�v���C���[���_�b�V�����Ă�����SE�𗬂�
void Player::PlaySoundDashSE()
{
	if (state == PLAYER_ANIMATION_TYPE_RUN)
	{
		PlaySoundMem(m_PlayerDashSE, DX_PLAYTYPE_BACK);
	}
}

// ���W���X�V
void Player::UpdatePos() {
	m_posX = m_nextPosX;
	m_posY = m_nextPosY;
}

//H���Z�b�g
void Player::SetHp(int hp)
{
	m_HP = hp;
}

//�v���C���[���G���ǂ���
bool Player::PlayerInvincible()
{
	//�v���C���[���G�t���[��
	PlayerInviFlame++;

	//�v���C���[���G
	PlayerInviFlag = true;

	//1�b�������疳�G����
	if (PlayerInviFlame > 60)
	{
		//�v���C���[���G�o�Ȃ�
		PlayerInviFlag = false;

		//�t���[��������
		PlayerInviFlame = 0;
	}

	return PlayerInviFlag;
}

//Hp�`��
void Player::DrawHp()
{
	DrawBox(m_posX - 13, m_posY - 33, m_posX + 53, m_posY - 30, GetColor(255, 255, 255), true);
	DrawBox(m_posX - 10, m_posY - 30, m_posX + m_HP / 2 , m_posY - 20, GetColor(0, 255, 0), true);
	DrawBox(m_posX - 13, m_posY - 20, m_posX + 53, m_posY - 17, GetColor(255, 255, 255), true);
	DrawBox(m_posX - 13, m_posY - 33, m_posX - 10, m_posY - 17, GetColor(255, 255, 255), true);
	DrawBox(m_posX + 50, m_posY - 33, m_posX + 53, m_posY - 17, GetColor(255, 255, 255), true);

}

//�v���C���[���S����
bool Player::DeathPlayer()
{
	if (m_HP > 0)
	{
		return false;
	}
	else if (m_HP <= 0)
	{
		return true;
	}
}