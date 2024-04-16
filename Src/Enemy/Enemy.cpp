
#include <math.h>
#include "DxLib.h"
#include "Enemy.h"
#include "../Player/Player.h"
#include "../Common.h"
#include "../Scene/Scene.h"
#include "../Scene/Play/ScenePlay.h"
#include "../Collision/Collision.h"
#include "../Input/Input.h"

//�G�ړ����x
const int MOVE_SPEED = 2;


Enemy::Enemy()
{
	//�G�摜�n���h��
	m_EnemyImageHandle[0] = -1;

	//�G���W
	m_enemy_x = 0;	//x���W
	m_enemy_y = 0;	//y���W

	// �d�̓t���O
	isGravity = false;

	//������
	Init();
}

Enemy::~Enemy(){}

//������
void Enemy::Init()
{
	//�G�摜�n���h��
	m_EnemyImageHandle[0] = LoadGraph(ENEMY_IMAGE_PATH);

	//�G���W
	m_enemy_x = 900;	//x���W
	m_enemy_y = 300;	//y���W

	// �d�̓t���O
	isGravity = false;

	//�GHP
	m_HP = 100;
	
}

//�G�ʏ폈��
void Enemy::Step()
{

	m_nextPosX = m_enemy_x;
	m_nextPosY = m_enemy_y;

	//�G�ړ�����
	if (m_speedX < 300) 
	{
		m_nextPosX += MOVE_SPEED;
		m_speedX += MOVE_SPEED;
	}
	else if (m_speedX >= 300 && m_speedX <= 600)
	{
		m_nextPosX -= MOVE_SPEED;
		m_speedX += MOVE_SPEED;
	}
	else if (m_speedX > 600)
	{
		m_speedX = 0;
	}
	
	
	 //�����蔻��f�o�b�O�p
	//���ړ�����
	//��
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_nextPosX -= MOVE_SPEED;

	}
	//�E
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_nextPosX += MOVE_SPEED;

	}
	//�W�����v����
	if (IsKeyPush(KEY_INPUT_UP) == 1)
	{
		m_speedY = -JUMP_POWER;
	}
	

	//�V�[���v���C�݂̂ŏ���
	//�d��
	if (g_CurrentSceneID == SCENE_ID_LOOP_PLAY)
	{

		/*�d��on*/
		isGravity = true;

		//�d�͂̌v�Z
		m_speedY += GRAVITY;
		if (m_speedY > GRAVITY)
		{
			// Y�����̈ړ��ʂ𐧌�
			m_speedY = GRAVITY + 5;
		}
		if (isGravity)
		{
			m_nextPosY += m_speedY;
		}
	}

}



//�`��
void Enemy::Draw(int mapmove) 
{

	DrawRotaGraph(m_enemy_x - mapmove, m_enemy_y, 0.35f, 0.0f, m_EnemyImageHandle[0], true);
	DrawFormatString((m_enemy_x - 30) - mapmove , m_enemy_y - 60, GetColor(0, 0, 0), "HP�F%d", m_HP, true);

}

//�G��HP��ݒ�
void Enemy::SetHP(int hp)
{
	m_HP = hp;
}

//�v���C���[�̍��W��ݒ�
void Enemy::SetPosX(int x)
{
	m_nextPosX = x;
}
void Enemy::SetPosY(int y)
{
	m_nextPosY = y;
}

// �i��ł���������`�F�b�N
// �㉺���E�̏��ɂȂ��Ă���
void Enemy::GetMoveDirection(bool* _dirArray) {
	// �E�����̃`�F�b�N
	if (m_nextPosX > m_enemy_x) {
		_dirArray[3] = true;
	}

	// �������̃`�F�b�N
	if (m_nextPosX < m_enemy_x) {
		_dirArray[2] = true;
	}

	// �������̃`�F�b�N
	if (m_nextPosY > m_enemy_y) {
		_dirArray[1] = true;
	}

	// �������̃`�F�b�N
	if (m_nextPosY < m_enemy_y) {
		_dirArray[0] = true;
	}

}

// ���W���X�V
void Enemy::UpdatePos() {
	m_enemy_x = m_nextPosX;
	m_enemy_y = m_nextPosY;
}