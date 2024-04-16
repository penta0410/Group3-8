#include "DxLib.h"
#include "Option.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//=============================
// �I�v�V�����V�[��
//=============================

//�I�v�V����������
void OPTION::InitOption()
{

	//�I�v�V�������[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_OPTION;

	//�w�i�摜�n���h��
	m_BackGroundImageHandle[0] = LoadGraph(OPTION_MOVIE_PATH);

	//�{�^���摜�n���h��
	m_BottanHandle[0] = LoadGraph(OPTION_BOTTAN_PATH);
	m_BottanHandle[1] = LoadGraph(OPTION_EXPLAIN_PATH);

	//�{�^���l�[���n���h��
	//����
	m_BackGroundImageHandle[1] = LoadGraph("Data/OptionImage/�}4.png");

	//�A�C�e��
	m_BackGroundImageHandle[2] = LoadGraph("Data/OptionImage/�}5.png");

	//�L�����N�^�[
	m_BackGroundImageHandle[3] = LoadGraph("Data/OptionImage/�}6.png");

	//�E���n���h��
	m_BackGroundImageHandle[4] = LoadGraph("Data/OptionImage/�}9.png");

	//�����n���h��
	m_BackGroundImageHandle[5] = LoadGraph("Data/OptionImage/�}10.png");

	//�I�v�V�����^�C�g���n���h��
	m_OptionTitleHundle = LoadGraph(OPTION_TITLE_PATH);

	//�߂�{�^���t���O
	m_Return_Bottan_Flag = 0;

	//�{�^���I���t���O
	m_Bottan_Flag = 1;

	//�I�v�V�����t���[��
	m_Option_Flame = 0;

	//�}�E�X�t���[��
	m_mouse_Flame = 0;
}

//�I�v�V�����ʏ폈��
void OPTION::StepOption()
{

	//�Q�[�������V�[���ւ̑J��
	//enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_OptionSceneFlag = 0;
		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_OPTION;

	}

	//�I�v�V�����t���[�����J�E���g
	m_Option_Flame++;

	//���ړ�����
	//��
	if (IsKeyPush(KEY_INPUT_A) == 1)
	{
		//�{�^���Q��I�����Ă���Ƃ��{�^���P��
		if (m_Bottan_Flag == 2)
		{
			//�����{�^��
			m_explain_bottan_x += 290;
			m_explain_size += 0.3f;
			m_explain2_size += 0.15f;
			m_explain2_bottan_x += 320;

			//�A�C�e���{�^��
			m_text_bottan_x += 300;
			m_text_size -= 0.3f;
			m_text2_size -= 0.25f;
			m_text2_bottan_x += 230;

			//�L�����N�^�[�{�^��
			m_character_bottan_x += 300;
			m_character2_bottan_x += 300;

			m_Bottan_Flag = 1;
		}
		//�{�^���R��I�����Ă���Ƃ��Ƀ{�^���Q��
		if (m_Bottan_Flag == 3)
		{
			//�����{�^��
			m_explain_bottan_x += 290;
			m_explain2_bottan_x += 290;

			//�A�C�e���{�^��
			m_text_bottan_x += 300;
			m_text_size += 0.3f;
			m_text2_size += 0.25f;
			m_text2_bottan_x += 365;

			//�L�����N�^�[�{�^��
			m_character_bottan_x += 300;
			m_character2_bottan_x += 280;
			m_character_size -= 0.3f;
			m_character2_size -= 0.15f;

			m_Bottan_Flag = 2;
		}
	}

	//�E
	if (IsKeyPush(KEY_INPUT_D) == 1)
	{
		//�{�^���Q��I�����Ă���Ƃ��{�^���R��
		if (m_Bottan_Flag == 2)
		{
			//�����{�^��
			m_explain_bottan_x -= 290;
			m_explain2_bottan_x -= 290;

			//�A�C�e���{�^��
			m_text_bottan_x -= 300;
			m_text_size -= 0.3f;
			m_text2_size -= 0.25f;
			m_text2_bottan_x -= 365;

			//�L�����N�^�[�{�^��
			m_character_bottan_x -= 300;
			m_character2_bottan_x -= 280;
			m_character_size += 0.3f;
			m_character2_size += 0.15f;

			m_Bottan_Flag = 3;
		}
		//�{�^���P��I�����Ă���Ƃ��{�^���Q��
		if (m_Bottan_Flag == 1)
		{
			//�����{�^��
			m_explain_bottan_x -= 290 ;
			m_explain_size -= 0.3f;
			m_explain2_size -= 0.15f;
			m_explain2_bottan_x -= 320;

			//�A�C�e���{�^��
			m_text_bottan_x -= 300;
			m_text_size += 0.3f;
			m_text2_size += 0.25f;
			m_text2_bottan_x -= 230;

			//�L�����N�^�[�{�^��
			m_character_bottan_x -= 300;
			m_character2_bottan_x -= 300;

			m_Bottan_Flag = 2;
		}


	}

	//�^�C�g���V�[���ւ̑J��
	//�߂�{�^���t���O��on��������
	if (m_Return_Bottan_Flag == 1)
	{
		//���R���g���[���L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			//�^�C�g���V�[���t���O���^�C�g���V�[���ɕύX
			m_OptionSceneFlag = 2;

			//�v���C�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_OPTION;
		}
	}

	//�I�v�V�����V�[���Ɉړ�����1�b��������
	if (m_Option_Flame >= 60)
	{
		//�߂�{�^���t���O��on��
		m_Return_Bottan_Flag = 1;
	}

}

//�I�v�V�����`�揈��
void OPTION::DrawOption()
{
	PlayMovieToGraph(m_BackGroundImageHandle[0] );

	//�I�v�V������ʕ`��
	DrawRotaGraph(610, 350, 0.7f, 0.0f, m_BackGroundImageHandle[0], true);

	if ((GetMovieStateToGraph(m_BackGroundImageHandle[0])) == 0) {
		//����Đ��ʒu��������
		SeekMovieToGraph(m_BackGroundImageHandle[0], 0);
		PlayMovieToGraph(m_BackGroundImageHandle[0]);
	}

	//�߂�{�^���摜�`��
	DrawRotaGraph(m_bottan_x, m_bottan_y, 0.75f, 0.0f, m_BottanHandle[0], true);

	//���E�{�^���摜�`��
	DrawRotaGraph(720, 350, 0.9f, 0.0f, m_BackGroundImageHandle[4], true);

	//��󍶃{�^���摜�`��
	DrawRotaGraph(390, 350, 0.9f, 0.0f, m_BackGroundImageHandle[5], true);

	//�����{�^���摜�`��
	DrawRotaGraph(m_explain_bottan_x, m_explain_bottan_y, m_explain_size, 0.0f, m_BottanHandle[1], true);
	DrawRotaGraph(m_explain2_bottan_x, m_explain_bottan_y, m_explain2_size, 0.0f, m_BackGroundImageHandle[1], true);
	
	//�A�C�e���{�^���摜�`��
	DrawRotaGraph(m_text_bottan_x, m_text_bottan_y, m_text_size, 0.0f, m_BottanHandle[1], true);
	DrawRotaGraph(m_text2_bottan_x, m_text_bottan_y, m_text2_size, 0.0f, m_BackGroundImageHandle[2], true);

	//�L�����N�^�[�{�^���摜�`��
	DrawRotaGraph(m_character_bottan_x, m_character_bottan_y, m_character_size, 0.0f, m_BottanHandle[1], true);
	DrawRotaGraph(m_character2_bottan_x, m_character_bottan_y, m_character2_size, 0.0f, m_BackGroundImageHandle[3], true);

	//�}�E�X����
	if (m_Return_Bottan_Flag == 1)
	{
		MouseClick();
	}

}

//�I�v�V�����㏈��
void OPTION::FinOption()
{

	DeleteGraph(m_BackGroundImageHandle[0]);

	if (m_OptionSceneFlag == 0)
	{
		//�Q�[������INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_GAME_EXPLAIN;
	}

	if (m_OptionSceneFlag == 1)
	{
		//���C�����j���[INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_MEIN_MENU;
	}

	if (m_OptionSceneFlag == 2)
	{
		//�^�C�g��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}

void OPTION::MouseClick()
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
			//�^�C�g���V�[���ւ̑J��
			//��ʏ�̖߂�{�^�������ꂽ�Ȃ�

			//�I�v�V�����V�[���t���O���^�C�g���V�[���ɕύX
			m_OptionSceneFlag = 2;

			//'�I�v�V�����㏈��'�ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_OPTION;
		}
		else
		{
			//������Ă��Ȃ�
		}
	}

	//�����{�^��
	if (m_Bottan_Flag == 1)
	{
		if (IsHitRect(m_explain_bottan_x - 105, m_explain_bottan_y - 70, m_explain_bottan_w, m_explain_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//�����w�i
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
			DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
			SetFontSize(12);
			DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�Q�[������>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

			//�����T�C�Y�����Ƃ�
			SetFontSize(16);

			//���N���b�N�����Ƃ�
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				//�I�v�V�����V�[���ւ̑J��
				//��ʏ�̃I�v�V�����{�^�������ꂽ�Ȃ�

				//�I�v�V�����V�[���t���O������V�[���t���O�ɕύX
				m_OptionSceneFlag = 0;

				//'�^�C�g���㏈��'�ֈړ�
				g_CurrentSceneID = SCENE_ID_FIN_OPTION;

			}
			else
			{
				//������Ă��Ȃ�
			}
		}
	}

	//�A�C�e���{�^��
	if (m_Bottan_Flag == 2)
	{
		if (IsHitRect(m_text_bottan_x - 105, m_text_bottan_y - 70, m_text_bottan_w, m_text_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//�����w�i
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
			DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
			SetFontSize(12);
			DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�A�C�e��>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

			//�����T�C�Y�����Ƃ�
			SetFontSize(16);

			//���N���b�N�����Ƃ�
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				////�A�C�e���V�[���ւ̑J��
				////��ʏ�̃I�v�V�����{�^�������ꂽ�Ȃ�

				////�I�v�V�����V�[���t���O���A�C�e���V�[���ɕύX
				//m_OptionSceneFlag = 0;

				////'�^�C�g���㏈��'�ֈړ�
				//g_CurrentSceneID = SCENE_ID_FIN_OPTION;

			}
			else
			{
				//������Ă��Ȃ�
			}
		}
	}

	//�L�����N�^�[�{�^��
	if (m_Bottan_Flag == 3)
	{
		if (IsHitRect(m_character_bottan_x - 105, m_character_bottan_y - 70, m_character_bottan_w, m_character_bottan_h, m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//�����w�i
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
			DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
			SetFontSize(12);
			DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�L�����N�^�[>\n�{�^�������N���b�N���邩\nenter(�G���^�[)�L�[�������Ă�������");

			//�����T�C�Y�����Ƃ�
			SetFontSize(16);

			//���N���b�N�����Ƃ�
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				////�L�����N�^�[�V�[���ւ̑J��
				////��ʏ�̃I�v�V�����{�^�������ꂽ�Ȃ�

				////�I�v�V�����V�[���t���O���L�����N�^�[�V�[���ɕύX
				//m_OptionSceneFlag = 0;

				////'�^�C�g���㏈��'�ֈړ�
				//g_CurrentSceneID = SCENE_ID_FIN_OPTION;

			}
			else
			{
				//������Ă��Ȃ�
			}
		}
	}

	//��
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, 390, 350, 20) == 1)
	{
		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<����>\n�{�^�������N���b�N���邩\nA�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		//�}�E�X�t���[��
		m_mouse_Flame++;

		//�{�^���Q��I�����Ă���Ƃ��{�^���P��
		if (m_mouse_Flame >= 20 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			if (m_Bottan_Flag == 2)
			{
				//�����{�^��
				m_explain_bottan_x += 290;
				m_explain_size += 0.3f;
				m_explain2_size += 0.15f;
				m_explain2_bottan_x += 320;

				//�A�C�e���{�^��
				m_text_bottan_x += 300;
				m_text_size -= 0.3f;
				m_text2_size -= 0.25f;
				m_text2_bottan_x += 230;

				//�L�����N�^�[�{�^��
				m_character_bottan_x += 300;
				m_character2_bottan_x += 300;

				//�}�E�X�t���[��
				m_mouse_Flame = 0;

				m_Bottan_Flag = 1;
			}

			//�{�^���R��I�����Ă���Ƃ��Ƀ{�^���Q��
			if (m_Bottan_Flag == 3)
			{
				//�����{�^��
				m_explain_bottan_x += 290;
				m_explain2_bottan_x += 290;

				//�A�C�e���{�^��
				m_text_bottan_x += 300;
				m_text_size += 0.3f;
				m_text2_size += 0.25f;
				m_text2_bottan_x += 365;

				//�L�����N�^�[�{�^��
				m_character_bottan_x += 300;
				m_character2_bottan_x += 280;
				m_character_size -= 0.3f;
				m_character2_size -= 0.15f;

				//�}�E�X�t���[��
				m_mouse_Flame = 0;

				m_Bottan_Flag = 2;
			}

		}
	}

	//�E
	if (IsHitCircle(m_Mouse_x, m_Mouse_y, 2, 720, 350, 20) == 1)
	{

		//�}�E�X�t���[��
		m_mouse_Flame++;

		//�����w�i
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�{�^���ʒu�Ƀ}�E�X�J�[�\�����������ɕ\������q���g�e�L�X�g
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255), "<�E��>\n�{�^�������N���b�N���邩\nD�L�[�������Ă�������");

		//�����T�C�Y�����Ƃ�
		SetFontSize(16);

		if (m_mouse_Flame >= 20 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//�{�^���Q��I�����Ă���Ƃ��{�^���R��
			if (m_Bottan_Flag == 2)
			{
				//�����{�^��
				m_explain_bottan_x -= 290;
				m_explain2_bottan_x -= 290;

				//�A�C�e���{�^��
				m_text_bottan_x -= 300;
				m_text_size -= 0.3f;
				m_text2_size -= 0.25f;
				m_text2_bottan_x -= 365;

				//�L�����N�^�[�{�^��
				m_character_bottan_x -= 300;
				m_character2_bottan_x -= 280;
				m_character_size += 0.3f;
				m_character2_size += 0.15f;

				//�}�E�X�t���[��
				m_mouse_Flame = 0;

				m_Bottan_Flag = 3;
			}

			//�{�^���P��I�����Ă���Ƃ��{�^���Q��
			if (m_Bottan_Flag == 1)
			{
				//�����{�^��
				m_explain_bottan_x -= 290;
				m_explain_size -= 0.3f;
				m_explain2_size -= 0.15f;
				m_explain2_bottan_x -= 320;

				//�A�C�e���{�^��
				m_text_bottan_x -= 300;
				m_text_size += 0.3f;
				m_text2_size += 0.25f;
				m_text2_bottan_x -= 230;

				//�L�����N�^�[�{�^��
				m_character_bottan_x -= 300;
				m_character2_bottan_x -= 300;

				//�}�E�X�t���[��
				m_mouse_Flame = 0;

				m_Bottan_Flag = 2;
			}
		}

		
	}

}