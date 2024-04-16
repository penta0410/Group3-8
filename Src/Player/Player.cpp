
#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Scene/Play/ScenePlay.h"
#include "../Screen/Screen.h"
#include "../Scene/Scene.h"
#include "../Effect/Effect.h"
#include "../Collision/Collision.h"
#include "../Enemy/Enemy.h"
#include "../Screen/Screen.h"

//�A�j���[�V�����t�@�C���p�X
const char* ANIMATION_PATH[PLAYER_ANIMATION_TYPE_MAX] =
{
	PLAYER_STAND_PATH,
	PLAYER_WALK_PATH,
	PLAYER_RUN_PATH,
	PLAYER_JUMP_PATH,
	PLAYER_MIDAIR_PATH,
	PLAYER_FALL_PATH,
	PLAYER_LANDING_PATH,
	PLAYER_DAMAGE_PATH,
	PLAYER_ATTACK_PATH,

};

PLAY m_play;
Screen m_screen;
Enemy m_enemy;

Player::Player() 
{

}

Player::~Player() {}

Player m_player;

//������
void Player::Init() 
{
	//�A�j���[�V�����n���h��
	animation_handle[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//�A�j���[�V�����摜�t���O
    animation_flag[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//�A�j���[�V�����t���[��
	animation_flame = 0;

	//�v���C���[�������
	m_posX = 100;
	m_posY = 100;
	m_HP = 100;

	//�U���t���[��
	m_attack = 0;

	//�U���t���O
	m_attackFlag = 0;

	//�U���A�j���[�V�����t���[��
	m_attack_frame = 0;
	
	//�`��t���O
	m_drawflag = 1;

	//�v���C���[�ړ���̍��W
	m_nextPosX = 0.0f;
	m_nextPosY = 0.0f;

	//�v���C���[�ړ���
	m_move_x = 0;
	m_move_y = 0;

	//�}�E�X���W
	m_Mouse_x = 0;	//�����W
	m_Mouse_y = 0;	//y���W

	//�v���C���[�ړ��t���O
	m_PlayerMoveFlag = false;

	//�d�̓t���O
	isGravity = false;

	//�A�j���[�V�����ύX�t���O
	m_player_animationflag = 0;

	//�v���C���[�̍ŏ��̃A�j���[�V����
	now_animation = PLAYER_ANIMATION_TYPE_STAND;

}

//�ǂݍ��ݏ���g
void Player::LoadPlayer()
{
	//�v���C���[�ǂݍ���
	for (int load_num = 0; load_num <
		PLAYER_ANIMATION_TYPE_MAX; load_num++)
	{
		LoadDivGraph(ANIMATION_PATH[load_num],
			ANIMATION_FRAME_NUM[load_num],
			AnimationImgSplitNum[load_num][0],
			AnimationImgSplitNum[load_num][1],
			AnimationImgSize[0][0],
			AnimationImgSize[0][1],
			animation_handle[load_num]);
	}

}

//�X�V
void Player::StepPlayer()
{
	//�ړ��O�̍��W���L�^����
	old_pos_x = m_posX;
	old_pos_y = m_posY;

	//���ړ��ʂ����Z�b�g
	m_move_x = 0.0f;

	//�󒆂ɂ��Ȃ���Ώ�Ԃ����Z�b�g
	if (!IsAirPlayer())
	{
		state = PLAYER_STATE_STAND;
	
		//�A�j���[�V�����ύX�t���O
		m_player_animationflag = 1;

	}

	//�ʏ폈��
	Control();

	//�����O�X�V
	StepPlayerMidAir();

	//�����X�V
	StepPlayerFall();

}

//�ʏ폈��
void Player::Control() {

	// �\���L�[����ȊO�ňړ������Ƃ��ɂǂ̕�����
	// �ړ����Ă��邩�`�F�b�N���邽��
	m_nextPosX = m_posX;
	m_nextPosY = m_posY;

	//���ړ�����
	//��
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{

		//����
		m_move_x = -MOVE_X;
		m_nextPosX -= MOVE_X;

		//�v���C���[���������ɂ���
		m_PlayerVisualDirection = 1;

		//�󒆂ɂ��Ȃ���Ε����A�j���[�V����
		if (!IsAirPlayer())
		{
			state = PLAYER_STATE_WALK;


			//�A�j���[�V�����ύX�t���O
			m_player_animationflag = 1;
		}

	}
	

	//�E
	if (CheckHitKey(KEY_INPUT_D) == 1) 
	{
		//����
		m_move_x = MOVE_X;

		m_nextPosX += MOVE_X;

		//�v���C���[���E�����ɂ���
		m_PlayerVisualDirection = 0;

		//�󒆂ɂ��Ȃ���Ε����A�j���[�V����
		if (!IsAirPlayer())
		{
			state = PLAYER_STATE_WALK;

			//�A�j���[�V�����ύX�t���O
			m_player_animationflag = 1;
		}

	}
	

	//�W�����v����
	if (IsKeyPush(KEY_INPUT_SPACE) == 1) 
	{
		if (CanJumpPlayer() == true)
		{
			m_move_y = -JUMP_POWER;

			//�W�����v��Ԃɐݒ�
			state = PLAYER_STATE_JUMP;

			//�A�j���[�V�����ύX�t���O
			m_player_animationflag = 1;
			
		}
	}
	

	//�V�[���v���C�݂̂ŏ���
	//�d��
	if (g_CurrentSceneID == SCENE_ID_LOOP_PLAY)
	{
		//�d��on
		isGravity = true;

		//�d�͂̌v�Z
		m_move_y += GRAVITY;
		if (m_move_y > FALL_MAX)
		{
			// Y�����̈ړ��ʂ𐧌�
			m_move_y = FALL_MAX;
		}
		if (isGravity)
		{

			m_nextPosY += m_move_y;
		}
	}
}

//�`��
void Player::Draw(int mapmove) 
{	

	//�A�j���[�V�����t���[���J�E���g
	animation_flame++;

	//��̃A�j���[�V�����̉摜��������
	for (int image_num = 0; image_num <
		ANIMATION_FRAME_NUM[state]; image_num++)
	{
		
		
		if (m_drawflag == 1)
		{
			//�g�p�t���O�𖢎g�p��
			animation_flag[state][image_num] = 1;

			//�`��t���O��off��
			m_drawflag = 0;

		
		}

		


		//�摜���g�p����Ă��Ȃ�������
		if (animation_flag[state][image_num] == 1)
		{
			
			// �����ɂ���Ă͔��]���ĕ`��
			//�ŏ��͉E
			if (m_PlayerVisualDirection == 0)
			{
				DrawGraph(m_posX - mapmove - 300, m_posY,
					animation_handle[state][image_num], TRUE);

			}
			//��
			else if (m_PlayerVisualDirection == 1)
			{
				DrawTurnGraph(m_posX - mapmove - 300, m_posY,
					animation_handle[state][image_num], TRUE);

			}
		}

		//�t���[�����X�V���ԃt���[���������玟�̉摜�`��
		if (m_drawflag == 0 && animation_flame > ANIMATION_FRAME_TIME[state] * 1.5)
		{
			//�摜�t���O���g�p�ς݂ɂ���
			animation_flag[state][image_num] = 0;

			//�`��t���O��on�ɂ���
			m_drawflag = 1;

			//�A�j���[�V�����t���[��������
			animation_flame = 0;
		}

	}

	

}

//�v���C���[�U������
int Player::PlayerAttack(int mapmove, int m_x, int m_y)
{

	//�}�E�X�ʒu�擾
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);


	//�U���t���[��
	m_attack++;

	//��b�N�[���^�C��
	if (m_attack >= 60)
	{
		//���N���b�N�����Ƃ��U��
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{

			m_attack = 0;

			//�U���t���O
			m_attackFlag = 1;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	

	//�U���t���O��on�ɂȂ�����
	if (m_attackFlag == 1)
	{
		//�v���C���[���E�������Ă���Ƃ�
		if (m_PlayerVisualDirection == 0)
		{

			

			/*DrawBox(m_x - mapmove - 30, m_y - 30,
				m_x - mapmove + 30, m_y + 30,
				GetColor(255, 255, 255), true);*/

			if (IsHitRect(m_posX - 230 - mapmove, m_posY + 30, 20, 40,
				m_x - mapmove - 30, m_y - 30, ENEMY_W, ENEMY_H) == 1)
			{
				
				int hp = m_enemy.GetHP();

				if (hp >= 0)
				{
					hp -= 100;

					return hp;
				}

			}
		}
		//�v���C���[�����������Ă���Ƃ�
		else if (m_PlayerVisualDirection == 1)
		{

			/*DrawBox(m_posX - 300 - mapmove, m_posY + 30,
				m_posX - 300 - mapmove + 20, m_posY + 70,
				GetColor(255, 255, 255), true);*/

			if (IsHitRect(m_posX - 300 - mapmove, m_posY + 30, 20, 40,
				m_x - mapmove - 30, m_y - 30, ENEMY_W, ENEMY_H) == 1)
			{

				int hp = m_enemy.GetHP();

				if (hp >= 0)
				{
					hp -= 100;

					return hp;
				}

			}
		}

		m_attack_frame++;
	}

	//��b�ԃA�j���[�V�����\��
	if (m_attackFlag == 1 && m_attack_frame <= 30)
	{
		//�A�j���[�V����
		//�U����Ԃ�
		state = PLAYER_STATE_ATTACK;

		//�A�j���[�V�����ύX�t���O
		m_player_animationflag = 1;

	}
	else if (m_attack_frame > 30)
	{
		//�U���t���O��off��
		m_attackFlag = 0;

		//�U���t���[����������
		m_attack_frame = 0;
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

		//�A�j���[�V�����ύX�t���O
		m_player_animationflag = 1;
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

		//�A�j���[�V�����ύX�t���O
		m_player_animationflag = 1;
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

		//�A�j���[�V�����ύX�t���O
		m_player_animationflag = 1;
	}

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

		//�A�j���[�V�����ύX�t���O
		m_player_animationflag = 1;
	}

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

//�v���C���[�I������
void Player::FinPlayer() 
{
	
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

// ���W���X�V
void Player::UpdatePos() {
	m_posX = m_nextPosX;
	m_posY = m_nextPosY;
}

//�v���C���[��HP��ݒ�
void Player::SetHP(int hp)
{
	m_HP = hp;
}

//�v���C���[�ړ��t���O�̏�Ԃ�ݒ�
void Player::SetPlayerMoveFlag(int flag)
{
	m_PlayerMoveFlag = flag;

}
