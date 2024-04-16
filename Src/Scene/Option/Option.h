#pragma once

//�I�v�V�����摜����
#define OPTION_IMAGE_NUMBER		(10)

//�{�^���摜����
#define OPTION_BOTTAN_NUMBER	(2)

//�I�v�V�����摜�p�X
#define OPTION_MOVIE_PATH	"Data/OptionImage/08tukihosikumo.mp4"

//�^�C�g���߂�{�^���p�X
#define OPTION_BOTTAN_PATH	"Data/OptionImage/�}3.png"

//�����{�^���p�X
#define OPTION_EXPLAIN_PATH	"Data/OptionImage/�}8.png"

//�I�v�V�����^�C�g���摜�p�X
#define OPTION_TITLE_PATH	"Data/OptionImage/�}1.png"

class OPTION
{
private:

	//�I�v�V�����V�[������̑J�ڑI���t���O
	int m_OptionSceneFlag = 0;

	//�I�v�V�����^�C�g���n���h��
	int m_OptionTitleHundle = 0;

	//�I�v�V�����w�i�n���h��
	int m_BackGroundImageHandle[OPTION_IMAGE_NUMBER] = { 0 };

	//�{�^���n���h��
	int m_BottanHandle[OPTION_BOTTAN_NUMBER] = { 0 };

	//�߂�{�^���T�C�Y
	int m_bottan_x = 1200;	//�����W
	int m_bottan_y = 650;	//y���W
	int m_bottan_r = 30;	//���a

	//�����{�^���T�C�Y
	int m_explain_bottan_x = 550;	//�����W
	int m_explain_bottan_y = 350;	//y���W
	int m_explain_bottan_w = 210;	//��
	int m_explain_bottan_h = 130;	//�c
	float m_explain_size = 1.0f;
	int m_explain2_bottan_x = 645;	//�����W
	float m_explain2_size = 0.5f;

	//�A�C�e���{�^���T�C�Y
	int m_text_bottan_x = 850;	//�����W
	int m_text_bottan_y = 350;	//y���W
	int m_text_bottan_w = 210;	//��
	int m_text_bottan_h = 130;	//�c
	float m_text_size = 0.7f;
	int m_text2_bottan_x = 950;	//�����W
	float m_text2_size = 0.4f;

	//�L�����N�^�[�{�^���T�C�Y
	int m_character_bottan_x = 1150;	//�����W
	int m_character_bottan_y = 350;	//y���W
	int m_character_bottan_w = 210;	//��
	int m_character_bottan_h = 130;	//�c
	float m_character_size = 0.7f;
	float m_character2_size = 0.25f;
	int m_character2_bottan_x = 1180;	//�����W

	//�{�^���I���t���O
	int m_Bottan_Flag = 1;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W
	
	//�߂�{�^���t���O
	int m_Return_Bottan_Flag = 0;
	
	//�I�v�V�����t���[��
	int m_Option_Flame = 0;

	//�}�E�X�t���[��
	int m_mouse_Flame = 0;

public:
	// �I�v�V����������
	void InitOption();

	//�I�v�V�����ʏ폈��
	void StepOption();

	//�I�v�V�����`�揈��
	void DrawOption();

	//�I�v�V�����㏈��
	void FinOption();

	//�}�E�X�N���b�N����
	void MouseClick();

};