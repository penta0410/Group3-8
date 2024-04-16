#pragma once
//���j���[��ʖ���
#define MENU_NUMBER	(2)

//�J�ڃ{�^���摜����
#define MENU_BOTTAN_NUMBER	(3)

//�����{�^���摜�p�X
#define CONPOS_BOTTAN_PATH	"Data/Menu/�}1.png"

//�C���x���g���{�^���p�X
#define INVENTORY_BOTTAN_PATH	"Data/Menu/�}3.png"

//�߂�{�^���p�X
#define MENU_RETURN_BOTTAN_PATH	"Data/Menu/�}7.png"


class MENU
{
private:

	//���j���[�V�[������̑J�ڃt���O
	int m_MenuSceneFlag = 0;

	//���j���[�摜�n���h��
	int m_MenuHundle[MENU_NUMBER] = { 0 };

	//�J�ڃ{�^���摜�n���h��
	int m_BottanHundle[MENU_BOTTAN_NUMBER] = { 0 };

	//�߂�{�^���摜�n���h��
	int m_ReturnBottanHundle = { 0 };

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	//�߂�{�^���T�C�Y
	int m_bottan_x = 1070;	//�����W
	int m_bottan_y = 570;	//y���W
	int m_bottan_r = 30;	//���a

	//�A�C�e�������{�^���T�C�Y
	int m_itemcps_bottan_x = 160;	//�����W
	int m_itemcps_bottan_y = 250;	//y���W
	int m_itemcps_bottan_r = 50;	//���a
	

	//�C���x���g���{�^���T�C�Y
	int m_ivt_bottan_x = 535;	//�����W
	int m_ivt_bottan_y = 250;	//y���W
	int m_ivt_bottan_r = 50;	//���a
	

public:

	//�X�e�[�W�Z���N�g������
	void InitMenu();

	//�X�e�[�W�Z���N�g�ʏ폈��
	void StepMenu();

	//�X�e�[�W�Z���N�g�`�揈��
	void DrawMenu();

	//�X�e�[�W�Z���N�g�㏈��
	void FinMenu();

	//�}�E�X�N���b�N����
	void MouseClick();
};
