#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include <math.h>
#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Screen/Screen.h"
#include "../../Map/Map.h"

//�v���C�V�[���摜����
const int PLAY_IMAGE_PATH_NUM = 3;

//�R�C������
const int COIN_NUM = 200;

//�v���C�V�[���p�X
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//�w�i
	"Data/Play/BackGround2.png",		//�w�i�Q
	"Data/Play/coin.png",				//�R�C��
};

const char PLAY_SCENE_BGM[] = { "" };				//�v���C�V�[����BGM

//�R�C�����W
//��ꂘ���W�A��񂙍��W
const int COIN_PLACE[COIN_NUM][2] =
{
	{2000, 400},{1950, 450},{2050, 450},{1900, 500},{2100, 500},

};

//�v���C�V�[���N���X
class PLAY : public SCENE_BASE
{
private:
	//�N���X�錾
	Player player;			//�v���C���[�N���X
	Screen m_screen;		//�X�N���[���N���X
	Map m_map;				//�}�b�v�N���X

	//�摜�n���h��
	int m_ImageHandle[PLAY_IMAGE_PATH_NUM];

	//�w�i���W
	int m_BG_x[2];
	int m_BG_y;
	
	//�w�i�ړ���
	int m_BG_move_x;

	//�R�C�����W
	int m_coin_x[COIN_NUM];
	int m_coin_y[COIN_NUM];
	//�R�C���`��t���O
	int CoinFlag[COIN_NUM];

public:

	//������
	void Init() override;
	//���[�h
	void Load() override;
	//�ʏ폈��
	void Step()	override;
	//�`�揈��
	void Draw() override;
	//�㏈��
	void Fin() override;
	// �}�b�v�̓����蔻��
	void MapCollision(int mapmove);
	//�R�C�����W������
	void InitCoin();
	//�R�C���`��
	void DrawCoin(int mapmove);
	//�R�C�������蔻��
	void CoinCollision(int mapmove);

};

