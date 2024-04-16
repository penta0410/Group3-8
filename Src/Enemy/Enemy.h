#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../Screen/Screen.h"

//�G1�摜�p�X
#define ENEMY_IMAGE_PATH  "Data/PlayImage/enemy.png"

//�G�摜����
#define ENEMYI_IMAGE_NUMBER	 (1)

//�G�P
#define ENEMY_MAX_NUM		(3)	    //�G1�̐�
#define ENEMY_WIDTH		(600)		//�G���o���ł��鉡��
#define ENEMY_ORIGIN_WIDTH	(400)	//���_���痣��邘
#define ENEMY_HP	(100)			//�G�P��HP
#define ENEMY_DAMAGE   (5)			//�G�P�̍U����
#define ENEMY_BODY_DAMAGE   (20)	//�G�P�̑̂̃_���[�W
#define ENEMY_POINT		(5)		//�G1�̃|�C���g
const int  ENEMY_W = 60;	//��
const int  ENEMY_H = 30;	//����

class Enemy
{
private:

	//�G�摜�n���h��
	int m_EnemyImageHandle[ENEMYI_IMAGE_NUMBER] = { 0 };

	

	//�G���W
	int m_enemy_x = 0;	//x���W
	int m_enemy_y = 0;	//y���W

	// �ړ���
	int m_speedY = 0;
	int m_speedX = 0;

	//�ړ���̍��W
	int m_nextPosX;
	int m_nextPosY;

	// �d�̓t���O
	bool isGravity = false;

	//�G��HP
	int m_HP = 100;

public:
	Enemy();
	~Enemy();

	

	//�G������
	void Init();

	//�G�ʏ폈��
	void Step();

	//�G�`�揈��
	void Draw(int mapmove);

	//���݂̍��W���擾
	int GetPosX() { return m_enemy_x; }
	int GetPosY() { return m_enemy_y; }

	//�ړ���̍��W���擾
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//���W���X�V
	void UpdatePos();

	//���W��ݒ�
	void SetPosX(int x);
	void SetPosY(int y);

	//�i��ł���������`�F�b�N
	//�㉺���E
	void GetMoveDirection(bool* _dirArray);

	//�GHP�擾
	int GetHP() { return m_HP; }

	//�G��HP��ݒ�
	void SetHP(int hp);

	
};
#endif
