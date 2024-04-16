#include "DxLib.h"
#include "ShopScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"


//=============================
// �V���b�v�V�[��
//=============================

//�V���b�v������
void SHOP::InitShop()
{
	//�V���b�v�w�i
	m_Shophandle[0] = LoadGraph(SHOP_BACK_PATH);

	//�V���b�v���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_SHOP;
}

//�V���b�v�ʏ폈��
void SHOP::StepShop()
{
	
	//���j���[�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_ShopFlag = 0;

		//�V���b�v�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

	//���C�����j���[�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_TAB))
	{
		m_ShopFlag = 1;

		//�V���b�v�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_SHOP;
	}

}

//�V���b�v�`�揈��
void SHOP::DrawShop()
{
    //�V���b�v�w�i	
	DrawRotaGraph(640, 360, 1.0f, 0.0f, m_Shophandle[0], true);
	


}

//�V���b�v�㏈��
void SHOP::FinShop()
{
	if (m_ShopFlag == 0)
	{
		//���j���[�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

	if (m_ShopFlag == 1)
	{
		//���C�����j���[�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MEIN_MENU;
	}

}
