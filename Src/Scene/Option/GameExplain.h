#pragma once
//�Q�[��������ʉ摜�p�X
#define GAME_EXPLAIN_BACK_PATH	"Data/OptionImage/�摜2.png"

//�^�C�g���߂�{�^���p�X
#define OPTION_BOTTAN_PATH	"Data/OptionImage/�}3.png"

//�����摜
#define EXPLAIN_PATH	"Data/OptionImage/�摜4.png"

//�{�^���摜����
#define OPTION_BOTTAN_NUMBER	(2)

class GAME_EXPLAIN
{
private:

	//�w�i�n���h��
	int m_BackgroundHundle = 0;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	//�߂�{�^���T�C�Y
	int m_bottan_x = 1200;	//�����W
	int m_bottan_y = 650;	//y���W
	int m_bottan_r = 30;	//���a

	//�{�^���n���h��
	int m_BottanHandle[OPTION_BOTTAN_NUMBER] = { 0 };

	//�����摜�n���h��
	int m_explainhandle = 0;

	//�߂�{�^���t���O
	int m_Return_Bottan_Flag = 0;

	//�Q�[�������V�[���t���[��
	int m_GameExPlainFlame = 0;

	//�V�[���J�ڃt���O
	int m_GameExplainSceneFlag = 0;

public:

	//�Q�[������������
	void InitGameExplain();

	//�Q�[�������ʏ폈��
	void StepGameExplain();

	//�Q�[�������`�揈��
	void DrawGameExplain();

	//�Q�[�������㏈��
	void FinGameExplain();

	//�}�E�X�N���b�N����
	void MouseClick();
};
