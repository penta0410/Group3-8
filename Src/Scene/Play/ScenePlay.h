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
const int PLAY_IMAGE_PATH_NUM = 4;

//�v���C�V�[���p�X
const char PLAY_PATH[PLAY_IMAGE_PATH_NUM][256] =
{
	"Data/Play/BackGround.png",		//�w�i
	"Data/Play/BackGround2.png",		//�w�i�Q
};

const char PLAY_SCENE_BGM[] = { "" };				//�v���C�V�[����BGM

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
	
	//�g���b�v�ʏ폈��
	void TrapStep();
};

