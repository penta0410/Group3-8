#include "DxLib.h"
#include "MenuScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// ���j���[�V�[��
//=============================

//���j���[������
void MENU::InitMenu()
{
	//���j���[���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_MENU;

	/*m_MenuHundle[0] = LoadGraph();*/
	
	//�A�C�e������
	m_BottanHundle[0] = LoadGraph(CONPOS_BOTTAN_PATH);

	//�C���x���g��
	m_BottanHundle[1] = LoadGraph(INVENTORY_BOTTAN_PATH);

	//�߂�
	m_ReturnBottanHundle = LoadGraph(MENU_RETURN_BOTTAN_PATH);

}

//���j���[�ʏ폈��
void MENU::StepMenu()
{

	//�A�C�e�������V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_MenuSceneFlag = 0;

		//���j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_MENU;
	}

	//���C�����j���[�ւ̑J��
	//tab�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_MenuSceneFlag = 1;

		//���j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_MENU;
	}

	//�C���x���g���ւ̑J��
	//tab�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_MenuSceneFlag = 2;

		//���j���[�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_MENU;
	}
}

//���j���[�`�揈��
void MENU::DrawMenu()
{
	//���j���[��ʕ`��
	
	//�߂�{�^���`��
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_ReturnBottanHundle, true);

	//�A�C�e�������{�^���`��
	DrawRotaGraph(m_itemcps_bottan_x, m_itemcps_bottan_y, 0.3f, 0.0f, m_BottanHundle[0], true);

	//�C���x���g���{�^���`��
	DrawRotaGraph(m_ivt_bottan_x, m_ivt_bottan_y, 0.25f, 0.0f, m_BottanHundle[1], true);

	//�}�E�X����
	MouseClick();
}

//���j���[�㏈��
void MENU::FinMenu()
{
	if (m_MenuSceneFlag == 0)
	{
		//�A�C�e�������V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_ITEM_CONPOS;
	}

	if (m_MenuSceneFlag == 1)
	{
		//���C�����j���[�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

	if (m_MenuSceneFlag == 2)
	{
		//�C���x���g���V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

}

void MENU::MouseClick()
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
		//���C�����j���[�ɖ߂�{�^��
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�߂�>\n�{�^�������N���b�N���邩\nctrl(�R���g���[��)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//���C�����j���[�V�[���ւ̑J��
			//��ʏ�̖߂�{�^�������ꂽ�Ȃ�
			//���j���[�V�[���t���O�����C�����j���[�V�[���ɕύX
			m_MenuSceneFlag = 1;

			//'���j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_MENU;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}


	//�A�C�e�������{�^��
	//�{�^���ʒu�ƃ{�^���Ƃ̓����蔻��
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_itemcps_bottan_x, m_itemcps_bottan_y, m_itemcps_bottan_r) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		//�A�C�e�������{�^��
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<����>\n�{�^�������N���b�N���邩\nctrl(�R���g���[��)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�A�C�e�������V�[���ւ̑J��
			//��ʏ�̍����{�^�������ꂽ�Ȃ�
			//���j���[�V�[���t���O���A�C�e�������ɕύX
			m_MenuSceneFlag = 0;

			//'���j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_MENU;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}


	//�C���x���g���{�^��
	//�{�^���ʒu�ƃ{�^���Ƃ̓����蔻��
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, m_ivt_bottan_x, m_ivt_bottan_y, m_ivt_bottan_r) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		//�C���x���g���{�^��
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�C���x���g��>\n�{�^�������N���b�N���邩\nctrl(�R���g���[��)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�C���x���g���V�[���ւ̑J��
			//��ʏ�̖߂�{�^�������ꂽ�Ȃ�
			//���j���[�V�[���t���O���C���x���g���V�[���ɕύX
			m_MenuSceneFlag = 2;

			//'���j���[�㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_MENU;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}
}