#include "DxLib.h"
#include "GameExplain.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// �Q�[�������V�[��
//=============================

//�Q�[������������
void GAME_EXPLAIN::InitGameExplain()
{

	//�Q�[���������[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_GAME_EXPLAIN;

	//�Q�[�������V�[���摜�n���h��
	m_BackgroundHundle = LoadGraph(GAME_EXPLAIN_BACK_PATH);

	//�����摜�n���h��
	m_explainhandle = LoadGraph(EXPLAIN_PATH);

	//�{�^���摜�n���h��
	m_BottanHandle[0] = LoadGraph(OPTION_BOTTAN_PATH);

}

//�Q�[�������ʏ폈��
void GAME_EXPLAIN::StepGameExplain()
{
	//�Q�[�������V�[���t���[���J�E���g
	m_GameExPlainFlame++;

	//�I�v�V�����V�[���ւ̑J��
	//�߂�{�^���t���O��on��������
	if (m_Return_Bottan_Flag == 1)
	{
		//���R���g���[���L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			//�Q�[�������V�[���t���O���I�v�V�����V�[���ɕύX
			m_GameExplainSceneFlag = 0;

			//�v���C�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_GAME_EXPLAIN;
		}
	}
	
	//�Q�[�������V�[���Ɉړ����ĂP�b��������
	if (m_GameExPlainFlame >= 60)
	{
		//�߂�{�^���t���O��on��
		m_Return_Bottan_Flag = 1;
	}
}

//�Q�[�������`�揈��
void GAME_EXPLAIN::DrawGameExplain()
{
	//�Q�[��������ʕ`��
	DrawRotaGraph(910, 360, 1.5f, 0.0f, m_BackgroundHundle, true);

	//�{�^���摜�`��
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_BottanHandle[0], true);

	//�����摜�`��
	DrawRotaGraph(830, 450, 0.4f, 0.0f, m_explainhandle, true);

	//�}�E�X����
	if (m_Return_Bottan_Flag == 1)
	{
		MouseClick();
	}

}

//�Q�[�������㏈��
void GAME_EXPLAIN::FinGameExplain()
{
	if (m_GameExplainSceneFlag == 0)
	{
		//�I�v�V����INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_OPTION;
	}

}

void GAME_EXPLAIN::MouseClick()
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
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�߂�>\n�{�^�������N���b�N���邩\nTab(�^�u)�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//���N���b�N�����Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			
			//�Q�[�������V�[���t���O���I�v�V�����V�[���ɕύX
			m_GameExplainSceneFlag = 0;

			//'�I�v�V�����㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_GAME_EXPLAIN;
		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	////�����{�^��
	//if (IsHitRect(m_explain_bottan_x - 105, m_explain_bottan_y - 70, m_explain_bottan_w, m_explain_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	//{
	//	//�����w�i
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	//	DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
	//	SetFontSize(12);
	//	DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�Q�[������>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

	//	//�����T�C�Y�����Ƃ�
	//	SetFontSize(16);

	//	//���N���b�N�����Ƃ�
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	//	{
	//		//�I�v�V�����V�[���ւ̑J��
	//		//��ʏ�̃I�v�V�����{�^�������ꂽ�Ȃ�

	//		//�^�C�g���V�[���t���O���I�v�V�����V�[���ɕύX
	//		m_OptionSceneFlag = 0;

	//		//'�^�C�g���㏈��'�ֈړ�
	//		g_CurrentSceneID = SCENE_ID_FIN_OPTION;

	//	}
	//	else
	//	{
	//		//������Ă��Ȃ�
	//	}
	//}
}