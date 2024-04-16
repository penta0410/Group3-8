#ifndef __PLAYER_H__
#define __PLAYER_H__
//#include "../Scene/Play/ScenePlay.h"

//�v���C���[�摜�p�X
#define PLAYER_STAND_PATH	"Data/PlayImage/playerstand.png"	//�v���C���[�ҋ@�摜
#define PLAYER_WALK_PATH	"Data/PlayImage/playerwalk.png"		//�v���C���[�����摜
#define PLAYER_RUN_PATH		"Data/PlayImage/playerrun.png"		//�v���C���[����摜
#define PLAYER_JUMP_PATH	"Data/PlayImage/playerjump.png"		//�v���C���[�W�����v�摜
#define PLAYER_MIDAIR_PATH	"Data/PlayImage/playermidair.png"	//�v���C���[�󒆉摜
#define PLAYER_FALL_PATH	"Data/PlayImage/playerfall.png"		//�v���C���[�����摜
#define PLAYER_LANDING_PATH	"Data/PlayImage/playerlanding.png"	//�v���C���[���n�摜
#define PLAYER_DAMAGE_PATH	"Data/PlayImage/playerdamage.png"	//�v���C���[�_���[�W�摜
#define PLAYER_ATTACK_PATH	"Data/PlayImage/plaayerattack.png"	//�v���C���A�^�b�N�摜

//�摜����
#define PLAYER_IMAGE_NUM	(200)

//�A�j���[�V�����摜����
const int PLAYER_ANIMATION_NUM = 30;

// �e�A�j���[�V�����̃t���[����
#define PLAYER_STAND_FRAME_NUM	(12)	//�ҋ@
#define PLAYER_WALK_FRAME_NUM	(10)	//����
#define PLAYER_RUN_FRAME_NUM	(6)		//����
#define PLAYER_JUMP_FRAME_NUM	(2)		//�W�����v
#define PLAYER_MIDAIR_FRAME_NUM	(3)		//��	
#define PLAYER_FALL_FRAME_NUM	(3)		//����
#define PLAYER_LANDING_FRAME_NUM	(3)		//���n
#define PLAYER_DAMAGE_FRAME_NUM		(4)		//�_���[�W
#define PLAYER_ATTACK_FRAME_NUM		(3)		//�A�^�b�N

// �e�A�j���[�V�����̍X�V����
#define PLAYER_STAND_FRAME_TIME	(5)	//�ҋ@
#define PLAYER_WALK_FRAME_TIME	(5)	//����
#define PLAYER_RUN_FRAME_TIME	(3)		//����
#define PLAYER_JUMP_FRAME_TIME	(1)		//�W�����v
#define PLAYER_MIDAIR_FRAME_TIME	(2)		//��	
#define PLAYER_FALL_FRAME_TIME	(2)		//����
#define PLAYER_LANDING_FRAME_TIME	(5)		//���n
#define PLAYER_DAMAGE_FRAME_TIME		(3)		//�_���[�W
#define PLAYER_ATTACK_FRAME_TIME		(2)		//�A�^�b�N

// �����J�n�A�j���[�V�����ɐ؂�ւ���l
#define ANIM_CHANGE_MIDAIR_VAL -0.8f

// �����A�j���[�V�����ɐ؂�ւ���l
#define ANIM_CHANGE_FALL_VAL 0.8f


//�v���C���[�T�C�Y
#define PLAYER_W	(80)
#define PLAYER_H	(96)

// �d��
#define GRAVITY 1.225f

// �ړ���
#define MOVE_X 4.0f

// �W�����v��
#define JUMP_POWER 25.0f

// �������x���
#define FALL_MAX 10.0f

//�v���C���[�A�j���[�V�������
enum PlayerAnimationType {

	PLAYER_ANIMATION_TYPE_STAND = 0,
	PLAYER_ANIMATION_TYPE_WALK,
	PLAYER_ANIMATION_TYPE_RUN,
	PLAYER_ANIMATION_TYPE_JUMP,
	PLAYER_ANIMATION_TYPE_MIDAIR,
	PLAYER_ANIMATION_TYPE_FALL,
	PLAYER_ANIMATION_TYPE_LANDING,
	PLAYER_ANIMATION_TYPE_DAMAGE,
	PLAYER_ANIMATION_TYPE_ATTACK,

	PLAYER_ANIMATION_TYPE_MAX,
};

//�v���C���[�̃A�j���[�V�����̏��
enum PlayerState {
	PLAYER_STATE_STAND = 0,
	PLAYER_STATE_WALK,
	PLAYER_STATE_RUN,
	PLAYER_STATE_JUMP,
	PLAYER_STATE_MIDAIR,
	PLAYER_STATE_FALL,
	PLAYER_STATE_LANDING,
	PLAYER_STATE_DAMAGE,
	PLAYER_STATE_ATTACK,

};



//�A�j���[�V�����t���[����
const int ANIMATION_FRAME_NUM[PLAYER_ANIMATION_TYPE_MAX] =
{
	PLAYER_STAND_FRAME_NUM,
	PLAYER_WALK_FRAME_NUM,
	PLAYER_RUN_FRAME_NUM,
	PLAYER_JUMP_FRAME_NUM,
	PLAYER_MIDAIR_FRAME_NUM,
	PLAYER_FALL_FRAME_NUM,
	PLAYER_LANDING_FRAME_NUM,
	PLAYER_DAMAGE_FRAME_NUM,
	PLAYER_ATTACK_FRAME_NUM,

};

//�A�j���[�V�����X�V����
const int ANIMATION_FRAME_TIME[PLAYER_ANIMATION_TYPE_MAX] =
{
	PLAYER_STAND_FRAME_TIME,
	PLAYER_WALK_FRAME_TIME,
	PLAYER_RUN_FRAME_TIME,
	PLAYER_JUMP_FRAME_TIME,
	PLAYER_MIDAIR_FRAME_TIME,
	PLAYER_FALL_FRAME_TIME,
	PLAYER_LANDING_FRAME_TIME,
	PLAYER_DAMAGE_FRAME_TIME,
	PLAYER_ATTACK_FRAME_TIME,

};

//�e�A�j���[�V�����̉摜������
const int AnimationImgSplitNum[PLAYER_ANIMATION_TYPE_MAX][2] =
{
	{10, 2,},	//�v���C���[�ҋ@�A�j���[�V����
	{10, 1,},	//�v���C���[�����A�j���[�V����
	{6, 1,},	//�v���C���[����A�j���[�V����
	{2, 1,},	//�v���C���[�W�����v�A�j���[�V����
	{3, 1,},	//�v���C���[�󒆃A�j���[�V����
	{3, 1,},	//�v���C���[�����A�j���[�V����
	{3, 1,},	//�v���C���[���n�A�j���[�V����
	{4, 1,},	//�v���C���[�_���[�W�A�j���[�V����
	{5, 1,},	//�v���C���[�A�^�b�N�A�j���[�V����

};

//�e�A�j���[�V�����̉摜�T�C�Y
const int AnimationImgSize[1][2] =
{
	{80,96},	//�v���C���[�摜�T�C�Y


};

class Player
{
private:

	/*PLAY play;*/
	//�v���C���[�摜�n���h��
	int animation_handle[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//�A�j���[�V�����摜�t���O
	int animation_flag[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//�A�j���[�V�����t���[��
	int animation_flame = 0;

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

	//�v���C���[�A�j���[�V�������
	PlayerAnimationType now_animation;

	//�v���C���[�A�j���|�V�������
	PlayerState state;
	
	//�A�j���[�V�����ύX�t���O
	int m_player_animationflag = 0;

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
	Player();
	~Player();

	//�v���C���[������
	void Init();

	//�v���C���[�ǂݍ���
	void LoadPlayer();

	//�v���C���[�X�V
	void StepPlayer();

	//�v���C���[�ʏ폈��
	void Control();

	//�v���C���[�U������
	int PlayerAttack(int mapmove, int m_x, int m_y);

	//�v���C���[�`�揈��
	void Draw(int mapmove);

	//�v���C���[�I������
	void FinPlayer();

	//�v���C���[�����O�`�F�b�N
	void StepPlayerMidAir();

	//�v���C���[�����X�V
	void StepPlayerFall();


	//�v���C���[���n����
	void PlayerLanding();

	//�v���C���[�V�䏈��
	void PlayerCeiling();

	//�v���C���[���W�����v�\���ǂ���
	bool CanJumpPlayer();

	//�v���C���[���󒆏�Ԃ��ǂ���
	bool IsAirPlayer();

	//�ړ���̍��W���擾
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//���݂̍��W���擾
	int GetPosX() { return m_posX; }
	int GetPosY() { return m_posY; }

	//���W���X�V
	void UpdatePos();

	//�ړ���̍��W��ݒ�
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posY);

	//�i��ł���������`�F�b�N
	//�㉺���E
	void GetMoveDirection(bool* _dirArray);

	//�v���C���[HP�擾
	int GetHP() { return m_HP; }

	//�v���C���[��HP��ݒ�
	void SetHP(int hp);
	
	//�v���C���[�ړ��t���O�̏�Ԃ��擾
	int  GetPlayerMoveFlag() { return m_PlayerMoveFlag; }

	//�v���C���[�ړ��t���O�̏�Ԃ�ݒ�
	void SetPlayerMoveFlag(int flag);

};




#endif
