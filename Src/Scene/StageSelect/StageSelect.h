#pragma once
#include "../../Player/Player.h"


//�X�e�[�W�Z���N�g��ʉ摜�p�X
#define STAGE_SELECT_BACK_PATH	"Data/StageSelectImage/���[�v�w�i004.jpg"

//�X�e�[�W�Z���N�g�A�C�R���摜�p�X
#define STAGE_SELECT_STAGE_ICON_PATH  "Data/StageSelectImage/�}3.png"

//�A�C�R���w�i�摜�p�X
#define STAGE_SELECT_ICON_BACKGROUND_PATH  "Data/StageSelectImage/�}4.png"

//�X�e�[�W�Z���N�g���摜�p�X
#define STAGE_SELECT_LOAD_PATH	"Data/StageSelectImage/�摜1.png"

//�v���C���[���\�����摜�p�X
#define PLAYER_INFO_FIELD	"Data/StageSelectImage/�摜8.png"

//�v���C���[�c�@�摜�p�X
#define PLAYER_REMAIN_PATH	"Data/StageSelectImage/�}5.png"

//�R�C���摜�p�X
#define KOIN_PATH		"Data/StageSelectImage/�}6.png"

//�B���R�C���摜�p�X
#define HIDE_KOIN_PATH		"Data/StageSelectImage/�}8.png"

//�A�C�e���摜�p�X
#define ITEM_PATH		"Data/StageSelectImage/�}9.png"

//�X�e�[�W�A�C�R���p�X
#define STAGE_ICON_PATH	"Data/StageSelectImage/�}10.png"

//�X�e�[�W�P�p�X
#define STAGE_1_PATH	"Data/StageSelectImage/�}11.png"

//�X�e�[�W�Z���N�g����p�X
#define STAGE_SELECT_MOVIE_PATH	"Data/StageSelectImage/Shooting_star.mp4"

//�X�e�[�W�Z���N�g�摜����
#define STAGE_SELECT_IMAGE_NUMBER	(20)

//�v���C���[�摜
#define PLAYER_NUM	(100)

class STAGE_SELECT
{
private:

	Player m_player;

	//�X�e�[�W�Z���N�g����̑J�ڃt���O
	int m_StageSelectFlag = 0;

	//�X�e�[�W�Z���N�g��ʉ摜
	int m_StageSelectImageHandle[STAGE_SELECT_IMAGE_NUMBER] = { 0 };

	//�v���C���[�ړ�
	int m_player_move_x = 0;
	int m_player_move_y = 0;

	//�X�e�[�W�I���t���O
	int m_Stage_Flag = 1;

	int m_playerhandle[10] = { 0 };

	//�X�e�[�W�Z���N�g����n���h��
	int m_Stageselect_Movie_handle = 0;

	//�X�e�[�W�J�ڃt���O
	int m_StageMoveFlag = 1;

	//�v���C���[�摜�n���h��
	int m_PlayerHandle[PLAYER_NUM] = { 0 };

public:

	

	//�X�e�[�W�Z���N�g������
	void InitStageSelect();

	//�X�e�[�W�Z���N�g�ʏ폈��
	void StepStageSelect();

	//�X�e�[�W�Z���N�g�`�揈��
	void DrawStageSelect(int koin, int hidekoin, int playerremain);

	//�X�e�[�W�Z���N�g�㏈��
	void FinStageSelect();

	//�Z�b�g�t���O
	void SetFlag(int flag);

};
