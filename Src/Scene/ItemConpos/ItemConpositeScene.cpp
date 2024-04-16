#include "DxLib.h"
#include "ItemConpositeScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../StageSelect/StageSelect.h"
#include "../Play/ScenePlay.h"
#include "../../Item/Item.h"
#include "../../Collision/Collision.h"

//=============================
// �A�C�e�������V�[��
//=============================

Item m_item;

//�A�C�e������������
void ITEM_CONPOS::InitItemConpos()
{

	//������ʔw�i
	m_ItemCoposHandle[0] = LoadGraph(ITEM_CONPOS_PATH);

	//���w�i
	m_ItemCoposHandle[1] = LoadGraph(STAGE_SELECT_ICON_BACKGROUND_PATH);

	//�v���X�摜
	m_ItemCoposHandle[2] = LoadGraph(ITEM_PLUS_PATH);

	//�͂Ăȉ摜
	m_ItemCoposHandle[3] = LoadGraph(QUESTION_PATH);

	//���g�摜
	m_ItemCoposHandle[7] = LoadGraph(FLAME_PATH);

	//���w�i
	m_ItemCoposHandle[8] = LoadGraph(BLACK_PATH);

	//����
	m_w = 0;

	//������
	m_bottan_x[0] = 180;
	m_bottan_y[0] = 400;
	m_bottan_r[0] = 80;

	m_bottan_x[1] = 500;
	m_bottan_y[1] = 400;
	m_bottan_r[1] = 80;

	//�������t���O
	m_FlameFlag1 = 0;
	m_FlameFlag2 = 0;

	//�C���x���g���t���O
	m_InventoryFlag = 0;

	//�C���x���g���̒��g
	m_InventoryContents_X[0] = 905;
	m_InventoryContents_X[1] = 1015;
	m_InventoryContents_X[2] = 1125;
	m_InventoryContents_X[3] = 1235;

	m_InventoryContents_Y[0] = 45;
	m_InventoryContents_Y[1] = 155;
	m_InventoryContents_Y[2] = 265;
	m_InventoryContents_Y[3] = 375;
	m_InventoryContents_Y[4] = 480;
	m_InventoryContents_Y[5] = 590;
	m_InventoryContents_Y[6] = 700;
	m_InventoryContents_Y[7] = 810;
	m_InventoryContents_Y[8] = 920;
	m_InventoryContents_Y[9] = 1030;

	//�������A�C�e���I���t���O
	m_item1alreadyFlag = 0;
	m_item2slreadyFlag = 0;

	//�C���x���g���T�C�Y
	m_Inventory_x = 830;
	m_Inventory_y = 0;
	m_Inventory_w = 500;
	m_Inventory_h = 2000;

	//�}�E�X���W
	m_Mouse_x = 0;
	m_Mouse_y = 0;

	//�A�C�e��������
	m_item.InitItem();

	//�A�C�e���������[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_ITEM_CONPOS;

}

//�A�C�e�������ʏ폈��
void ITEM_CONPOS::StepItemConpos()
{
	
	//���j���[�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_ItemConposFlag = 0;

		//�A�C�e�������㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_ITEM_CONPOS;
	}

}

//�A�C�e�������`�揈��
void ITEM_CONPOS::DrawItemConpos()
{

	//�A�C�e��������ʕ`��
	DrawRotaGraph(650, 380, 1.55f, 0.0f, m_ItemCoposHandle[0], true);

	//���w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawRotaGraph(180, 400, 0.65f, 0.0f, m_ItemCoposHandle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//���g
	if (m_FlameFlag1 == 1)
	{
		DrawRotaGraph(180, 400, 0.3f, 0.0f, m_ItemCoposHandle[7], true);
	}

	//���w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawRotaGraph(500, 400, 0.65f, 0.0f, m_ItemCoposHandle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//���g
	if (m_FlameFlag2 == 1)
	{
		DrawRotaGraph(500, 400, 0.3f, 0.0f, m_ItemCoposHandle[7], true);
	}

	//�v���X�摜
	DrawRotaGraph(340, 400, 0.2f, 0.0f, m_ItemCoposHandle[2], true);
	
	//�͂Ăȉ摜
	if (m_item1alreadyFlag == 1 && m_item2slreadyFlag == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220);
		DrawRotaGraph(340, 250, 0.4f, 0.0f, m_ItemCoposHandle[3], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�A�C�e���C���x���g��
	if (m_InventoryFlag == 1)
	{
		//���w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220);
		DrawRotaGraph(1200, 200, 0.8f, 0.0f, m_ItemCoposHandle[8], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//��
		DrawLine(960, 0, 960, 2000, GetColor(255, 255, 255), true);

		//�^��
		DrawLine(1070, 0, 1070, 2000, GetColor(255, 255, 255), true);

		//�E
		DrawLine(1180, 0, 1180, 2000, GetColor(255, 255, 255), true);

		//����
		for (int i = 0; i < 2000; i += 110)
		{
			for (int s = 0; s < 20; s++)
			{
				DrawLine(845, 100 + i, 1300, 100 + i, GetColor(255, 255, 255), true);
			}
		}

		//�C���x���g������
		Inventory();

	}

	

	//�}�E�X�N���b�N����
	MouseClick();

}

//�A�C�e�������㏈��
void ITEM_CONPOS::FinItemConpos()
{

	if (m_ItemConposFlag == 0)
	{
		//���j���[�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

}

//�}�E�X�N���b�N����
void ITEM_CONPOS::MouseClick()
{

	//�}�E�X�ʒu�擾
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);

	//�A�C�e���������P
	if (IsHitCircle(m_bottan_x[0], m_bottan_y[0], m_bottan_r[0], m_Mouse_x, m_Mouse_y, 1) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255),
			"�����Ɏg���A�C�e����\n��I��ł�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�C���x���g���t���O��on��
			m_InventoryFlag = 1;

			//�A�C�e����������on��
			m_FlameFlag1 = 1;

			//�A�C�e����������off��
			m_FlameFlag2 = 0;
		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//�A�C�e���������Q
	if (IsHitCircle(m_bottan_x[1], m_bottan_y[1], m_bottan_r[1], m_Mouse_x, m_Mouse_y, 1) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255),
			"�����Ɏg���A�C�e����\n��I��ł�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�C���x���g���t���O��on��
			m_InventoryFlag = 1;

			//�A�C�e����������on��
			m_FlameFlag2 = 1;

			//�A�C�e����������off��
			m_FlameFlag1 = 0;

		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//�A�C�e��������off
	if (m_InventoryFlag == 1)
	{
		if (!IsHitCircle(m_bottan_x[0], m_bottan_y[0], m_bottan_r[0], m_Mouse_x, m_Mouse_y, 1) == 1
			&& !IsHitCircle(m_bottan_x[1], m_bottan_y[1], m_bottan_r[1], m_Mouse_x, m_Mouse_y, 1) == 1
			&& !IsHitRect(m_Inventory_x, m_Inventory_y, m_Inventory_w, m_Inventory_h,
				m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//���N���b�N�����Ƃ�
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				//�C���x���g���t���O��off��
				m_InventoryFlag = 0;

				//�A�C�e����������off��
				m_FlameFlag1 = 0;

				//�A�C�e����������off��
				m_FlameFlag2 = 0;
			}
			else
			{
				//������Ă��Ȃ�
			}
		}
	}

	////���g���C�{�^��
	//if (IsHitRect(m_Inventory_x, m_Inventory_y, m_Inventory_w, m_Inventory_h,
	//	m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	//{
	//	//�����w�i
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	//	DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
	//	SetFontSize(12);
	//	DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255),
	//		"<���g���C>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

	//	//�����T�C�Y�����Ƃ�
	//	SetFontSize(16);

	//	//���N���b�N�����Ƃ�
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	//	{
	//		

	//	}
	//	else
	//	{
	//		//������Ă��Ȃ�
	//	}
	//}

}

//�C���x���g������
void ITEM_CONPOS::Inventory()
{
	
	//�A�C�e��1
	
	for (int item_y = 0; item_y < 10; item_y++)
	{
		for (int item_x = 0; item_x < 4; item_x++)
		{
			if (m_InventoryContentsFlag_X[item_x] == 0 && m_InventoryContentsFlag_Y[item_y] == 0)
			{
				DrawRotaGraph(m_InventoryContents_X[item_x], m_InventoryContents_Y[item_y], 0.8f, 0.0f, m_item.m_ItemImageHandle[0], true);
				
				m_InventoryContentsFlag_X[item_x] == 1;

			}
		}

		m_InventoryContentsFlag_Y[item_y] == 1;

	}

	//�A�C�e��2
	for (int item_y = 0; item_y < 10; item_y++)
	{
		for (int item_x = 0; item_x < 4; item_x++)
		{
			if (m_InventoryContentsFlag_X[item_x] == 0 && m_InventoryContentsFlag_Y[item_y] == 0)
			{
				DrawRotaGraph(m_InventoryContents_X[item_x], m_InventoryContents_Y[item_y], 0.8f, 0.0f, m_item.m_ItemImageHandle[1], true);
			
				m_InventoryContentsFlag_X[item_x] == 1;

			}

		}

		m_InventoryContentsFlag_Y[item_y] == 1;

	}

	////�A�C�e��3
	//for (int item_y = 0; item_y < 10; item_y++)
	//{
	//	for (int item_x = 0; item_x < 4; item_x++)
	//	{
	//		if (m_InventoryContentsFlag_X[item_x] == 0 && m_InventoryContentsFlag_Y[item_y] == 0)
	//		{
	//			DrawRotaGraph(m_InventoryContents_X[item_x] - 5, m_InventoryContents_Y[item_y], 0.8f, 0.0f, m_item.m_ItemImageHandle[2], true);
	//		
	//			m_InventoryContentsFlag_X[item_x] == 1;

	//		}

	//	}
	//
	//	m_InventoryContentsFlag_Y[item_y] == 1;

	//}


}