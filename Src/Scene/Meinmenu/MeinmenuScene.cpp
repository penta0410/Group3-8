#include "DxLib.h"
#include "MeinmenuScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// ���C�����j���[�V�[��
//=============================

//���C�����j���[������
void MEIN_MENU::InitMeinMnu()
{
	//���ߔw�i
	m_MeinmenuHundle[1] = LoadGraph(MEINMENU_BACKGROUND_PATH);

	//�߂�{�^���n���h��
	m_ReturnBottanHundle = LoadGraph(RETURN_BOTTAN_PATH);

	//�J�ڃ{�^���摜�n���h��
	//�^�C�g��
	m_BottanHundle[0] = LoadGraph(BOTTAN_TITLE_PATH);

	//�I�v�V����
	m_BottanHundle[1] = LoadGraph(BOTTAN_OPTION_PATH);

	//�V���b�v
	m_BottanHundle[2] = LoadGraph(BOTTAN_SHOP_PATH);

	//���j���[
	m_BottanHundle[3] = LoadGraph(BOTTAN_MENU_PATH);

	//�߂�{�^���t���O
	m_ReturnBottanFlag = 0;

	//���C�����j���[����߂����t���O
	m_returnflag = 0;

	//���C�����j���[�V�[���t���[��
	m_MeinMenu_Flame = 0;


}

//���C�����j���[�ʏ폈��
void MEIN_MENU::StepMeinMnu()
{

	//�^�C�g���V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_MeinMenuSceneFlag = 0;
		//���C�����j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}
	
	//���C�����j���[�V�[���̃t���[�����J�E���g
	m_MeinMenu_Flame++;

	m_returnflag = 1;

	//�X�e�[�W�I���ւ̑J��
	//�߂�{�^���t���O��on��������
	if (m_ReturnBottanFlag == 1)
	{
		//�R���g���[���L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			m_MeinMenuSceneFlag = 1;
			//���C�����j���[�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
			
		}
	}

	//���C�����j���[�V�[���Ɉړ�����0.5�b��������
	if (m_MeinMenu_Flame >= 30)
	{
		//�߂�{�^���t���O��on��
		m_ReturnBottanFlag = 1;
	}

	//�I�v�V�����ւ̑J��
	//�����L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_DOWN))
	{
		m_MeinMenuSceneFlag = 2;
		//���C�����j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}

	//�V���b�v�ւ̑J��
	//�����L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_LEFT))
	{
		m_MeinMenuSceneFlag = 3;
		//���C�����j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}

	//���j���[�ւ̑J��
	//�E���L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RIGHT))
	{
		m_MeinMenuSceneFlag = 4;
		//���C�����j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
	}
}

//���C�����j���[�`�揈��
void MEIN_MENU::DrawMeinMnu()
{

	//���ߔw�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawRotaGraph(0, 100, 1.2f, 0.0f, m_MeinmenuHundle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//�߂�{�^���`��
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_ReturnBottanHundle, true);
	
	//�^�C�g���{�^���`��
	DrawRotaGraph(m_title_bottan_x, m_title_bottan_y, 0.65f, 0.0f, m_BottanHundle[0], true);
	
	//�I�v�V�����{�^���`��
	DrawRotaGraph(m_option_bottan_x, m_option_bottan_y, 0.65f, 0.0f, m_BottanHundle[1], true);
	
	//�V���b�v�{�^���`��
	DrawRotaGraph(m_shop_bottan_x, m_shop_bottan_y, 0.65f, 0.0f, m_BottanHundle[2], true);

	//���j���[�{�^���`��
	DrawRotaGraph(m_menu_bottan_x, m_menu_bottan_y, 0.65f, 0.0f, m_BottanHundle[3], true);

	//�}�E�X����
	MouseClick();
}

//���C�����j���[�㏈��
void MEIN_MENU::FinMeinMnu()
{

	//�t���O���O�̎��^�C�g����
	if (m_MeinMenuSceneFlag == 0)
	{

		//�^�C�g��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}

	if (m_MeinMenuSceneFlag == 1)
	{

		//�X�e�[�W�I��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_STAGE_SELECT;
	}

	if (m_MeinMenuSceneFlag == 2)
	{
		//�I�v�V����INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_OPTION;
	}

	if (m_MeinMenuSceneFlag == 3)
	{
		//�V���b�vINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_SHOP;
	}

	if (m_MeinMenuSceneFlag == 4)
	{
		//���j���[INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}
}

void MEIN_MENU::MouseClick()
{
	//�}�E�X�ʒu�擾
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);

	//�߂�{�^��
	//�{�^���ʒu�ƃ{�^���Ƃ̓����蔻��
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_bottan_x, m_bottan_y, m_bottan_r) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		//�X�e�[�W�Z���N�g�ɖ߂�{�^��
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�߂�>\n�{�^�������N���b�N���邩\nTab(�^�u)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�X�e�[�W�Z���N�g�V�[���ւ̑J��
			//��ʏ�̖߂�{�^�������ꂽ�Ȃ�
			//���C�����j���[�V�[���t���O���X�e�[�W�Z���N�g�V�[���ɕύX
			m_MeinMenuSceneFlag = 1;

			//'�^�C�g���㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//�^�C�g���{�^��
	if (IsHitRect(m_title_bottan_x - 105, m_title_bottan_y - 70, m_title_bottan_w, m_title_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		
		//�^�C�g����
		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�^�C�g����>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�^�C�g���V�[���ւ̑J��
			//��ʏ�̃^�C�g���{�^�������ꂽ�Ȃ�

			//���C�����j���[�V�[���t���O���^�C�g���V�[���ɕύX
			m_MeinMenuSceneFlag = 0;

			//'���C�����j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//�I�v�V�����{�^��
	if (IsHitRect(m_option_bottan_x - 105, m_option_bottan_y - 70, m_option_bottan_w, m_option_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�I�v�V������
		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�I�v�V������>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�I�v�V�����V�[���ւ̑J��
			//��ʏ�̃I�v�V�����{�^�������ꂽ�Ȃ�

			//���C�����j���[�V�[���t���O���I�v�V�����V�[���ɕύX
			m_MeinMenuSceneFlag = 2;

			//'���C�����j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//�V���b�v�{�^��
	if (IsHitRect(m_shop_bottan_x - 105, m_shop_bottan_y - 70, m_shop_bottan_w, m_shop_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�V���b�v��
		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�V���b�v��>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�V���b�v�V�[���ւ̑J��
			//��ʏ�̃V���b�v�{�^�������ꂽ�Ȃ�

			//���C�����j���[�V�[���t���O���V���b�v�V�[���ɕύX
			m_MeinMenuSceneFlag = 3;

			//'���C�����j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//���j���[�{�^��
	if (IsHitRect(m_menu_bottan_x - 105, m_menu_bottan_y - 70, m_menu_bottan_w, m_menu_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//���j���[��
		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<���j���[��>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//���j���[�V�[���ւ̑J��
			//��ʏ�̃��j���[�{�^�������ꂽ�Ȃ�

			//���C�����j���[�V�[���t���O�����j���[�V�[���ɕύX
			m_MeinMenuSceneFlag = 4;

			//'���C�����j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}
}

//�X�e�[�W�J�ڃt���O��ݒ�
void MEIN_MENU::SetFlag(int flag)
{
	m_MeinMenuSceneFlag = flag;
}