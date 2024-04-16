#pragma once

//���C�����j���[�摜�p�X
#define MEINMENU_IMAGE_PATH	"Data/MeinmenuImage/���[�v�w�i004.jpg"

//���C�����j���[�V�[���̓��ߔw�i
#define MEINMENU_BACKGROUND_PATH	"Data/MeinmenuImage/�摜8.png"

//���C�����j���[�摜����
#define MEINMENU_NUMBER	(2)

//�^�C�g���{�^���摜�p�X
#define BOTTAN_TITLE_PATH	"Data/MeinmenuImage/�}9.png"

//�I�v�V�����摜�p�X
#define BOTTAN_OPTION_PATH	"Data/MeinmenuImage/�}1.png"

//�V���b�v�摜�p�X
#define BOTTAN_SHOP_PATH	"Data/MeinmenuImage/�}2.png"

//���j���[�摜�p�X
#define BOTTAN_MENU_PATH	"Data/MeinmenuImage/�}4.png"

//�{�^���摜����
#define MEINMENU_BOTTAN_NUMBER	(5)

//�߂�{�^���p�X
#define RETURN_BOTTAN_PATH	"Data/MeinmenuImage/�}3.png"

#include "../StageSelect/StageSelect.h"

class MEIN_MENU
{
private:

	

	//���C�����j���[�V�[������̑J�ڑI���t���O
	int m_MeinMenuSceneFlag = 0;

	//���C�����j���[�摜�n���h��
	int m_MeinmenuHundle[MEINMENU_NUMBER] = { 0 };

	//�J�ڃ{�^���摜�n���h��
	int m_BottanHundle[MEINMENU_BOTTAN_NUMBER] = { 0 };

	//�߂�{�^���摜�n���h��
	int m_ReturnBottanHundle = { 0 };

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	
	//�߂�{�^���T�C�Y
	int m_bottan_x = 1170;	//�����W
	int m_bottan_y = 570;	//y���W
	int m_bottan_r = 30;	//���a

	//�^�C�g���{�^���T�C�Y
	int m_title_bottan_x = 160;	//�����W
	int m_title_bottan_y = 250;	//y���W
	int m_title_bottan_w = 210;	//��
	int m_title_bottan_h = 130;	//�c

	//�I�v�V�����{�^���T�C�Y
	int m_option_bottan_x = 465;	//�����W
	int m_option_bottan_y = 250;	//y���W
	int m_option_bottan_w = 210;	//��
	int m_option_bottan_h = 130;	//�c

	//�V���b�v�{�^���T�C�Y
	int m_shop_bottan_x = 770;	//�����W
	int m_shop_bottan_y = 250;	//y���W
	int m_shop_bottan_w = 210;	//��
	int m_shop_bottan_h = 130;	//�c

	//���j���[�{�^���T�C�Y
	int m_menu_bottan_x = 1075;	//�����W
	int m_menu_bottan_y = 250;	//y���W
	int m_menu_bottan_w = 210;	//��
	int m_menu_bottan_h = 130;	//�c

	//�߂�{�^���t���O
	int m_ReturnBottanFlag = 0;

	//���C�����j���[����߂����t���O
	int m_returnflag = 0;

	//���C�����j���[�V�[���t���[��
	int m_MeinMenu_Flame = 0;

public:
	

	//���C�����j���[������
	void InitMeinMnu();

	//���C�����j���[�ʏ폈��
	void StepMeinMnu();

	//���C�����j���[�`�揈��
	void DrawMeinMnu();

	//���C�����j���[�㏈��
	void FinMeinMnu();

	//�}�E�X�N���b�N����
	void MouseClick();

	//���݂̑J�ڃt���O�擾
	int GetFlag() { return m_MeinMenuSceneFlag; }

	//�t���O���Z�b�g
	void SetFlag(int flag);

	//�t���O���Q�b�g
	int GetReturnFlag() { return m_returnflag; }

};