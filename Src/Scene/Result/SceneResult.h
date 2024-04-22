#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"
#include "../../Transparent/Transparent.h"

const char RESULT_PATH[] = { "Data/Result/���U���g�w�i.png" };			//���U���g�̉摜�p�X
const char RESULT_MOJI_PATH[] = {"Data/Result/�l���R�C���� ����.png"};	//���U���g�����摜�p�X]
const char RESULT_NUMBER_PATH[] = { "Data/Result/number12x24_03.png" };

const int MOJI_X = 459 / 2;
const int MOJI_Y = 76 / 2;

const int UI_W_R = 6;
const int UI_H_R = 12;

const int SCORE_NUMBER_MAX_NUM = 13;

//���U���g�N���X
class RESULT : public SCENE_BASE
{
private:
	//�N���X�錾
	Player player;

	int ImageHandle;
	int MojiHandle;

	int m_moji_x;
	int m_moji_y;

	int score;
	int m_NumposX;
	int m_NumposY;
	int m_numberHandle[10];
	int m_UI_Image_posX;
	int m_UI_Image_posY;
	int num;
	int FreamCnt;

	int m_alpha;
	int m_Numalpha;

	bool IsMojiDraw;
	bool IsSceneFlag;			//�V�[���J�ڂł��邩�ǂ����̃t���O
	bool IsScoreDrawFrag;



public:

	//������
	void Init(int m_score);
	//���[�h
	void Load() override;
	//�ʏ폈��
	void Step()	override;
	//�`�揈��
	void Draw() override;
	//�㏈��
	void Fin() override;

};