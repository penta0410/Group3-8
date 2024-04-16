#include "DxLib.h"
#include "StageSelect.h"
#include "../Scene.h"
#include "../../Score/Score.h"
#include "../../Input/Input.h"
#include "../Meinmenu/MeinmenuScene.h"
//=============================
// �X�e�[�W�Z���N�g�V�[��
//=============================


MEIN_MENU m_meinmenu;

//�X�e�[�W�Z���N�g������
void STAGE_SELECT::InitStageSelect()
{
	//���C�����j���[
	m_meinmenu.InitMeinMnu();

	//�X�e�[�W�Z���N�g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_STAGE_SELECT;

	//�X�e�[�W�Z���N�g��ʉ摜
	m_StageSelectImageHandle[0] = LoadGraph(STAGE_SELECT_BACK_PATH);
	
	//�X�e�[�W�Z���N�g�A�C�R���摜
	m_StageSelectImageHandle[1] = LoadGraph(STAGE_SELECT_STAGE_ICON_PATH);

	//�X�e�[�W�Z���N�g�A�C�R���w�i�摜
	m_StageSelectImageHandle[2] = LoadGraph(STAGE_SELECT_ICON_BACKGROUND_PATH);

	
	

	LoadDivGraph(PLAYER_STAND_PATH, 12,
		10, 2, 80, 96, m_playerhandle);

	//�v���C���[�c�@�摜
	m_StageSelectImageHandle[6] = LoadGraph(PLAYER_REMAIN_PATH);

	//��
	m_StageSelectImageHandle[4] = LoadGraph(STAGE_SELECT_LOAD_PATH);

	//�v���C���[���\�����摜�p�X
	m_StageSelectImageHandle[5] = LoadGraph(PLAYER_INFO_FIELD);

	//�R�C���摜
	m_StageSelectImageHandle[7] = LoadGraph(KOIN_PATH);

	//�B���R�C���摜
	m_StageSelectImageHandle[8] = LoadGraph(HIDE_KOIN_PATH);

	//�A�C�e���摜
	m_StageSelectImageHandle[9] = LoadGraph(ITEM_PATH);

	//�X�e�[�W�A�C�R���摜
	m_StageSelectImageHandle[10] = LoadGraph(STAGE_ICON_PATH);

	//�X�e�[�W�Z���N�g����n���h��
	m_Stageselect_Movie_handle = LoadGraph(STAGE_SELECT_MOVIE_PATH);

	//�X�e�[�W�P�����n���h��
	m_StageSelectImageHandle[11] = LoadGraph(STAGE_1_PATH);

	//���[�f�B���O���
	m_StageSelectImageHandle[12] = LoadGraph("Data/StageSelectImage/0125 (1)(1).mp4");

	m_StageMoveFlag = 1;

	//�X�e�[�W�Z���N�g�V�[���t���O
	m_StageSelectFlag = 0;

}

//�X�e�[�W�Z���N�g�ʏ폈��
void STAGE_SELECT::StepStageSelect()
{
	//���C�����j���[����
	//�X�e�[�W�Z���N�g�t���O���P�̎�
	if (m_StageSelectFlag == 1)
	{
		//���C�����j���[����
		m_meinmenu.StepMeinMnu();
	}

	//�X�e�[�W�Z���N�g����
	if (m_StageSelectFlag == 0)
	{
		//�v���C�V�[���ւ̑J��
		//Enter�L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_RETURN))
		{
			m_StageSelectFlag = 0;
			//�X�e�[�W�Z���N�g�㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_STAGE_SELECT;
		}

		//���C�����j���[��
		//tab�L�[�����ꂽ�Ȃ�
		if (IsKeyPush(KEY_INPUT_TAB))
		{
			m_StageSelectFlag = 1;
		}

		//�v���C���[�ړ�
		//���ړ�����
		//��
		if (IsKeyPush(KEY_INPUT_A) == 1)
		{
			//�v���C���[���X�e�[�W�Q�ɂ���Ƃ��X�e�[�W�P�̈ʒu��
			if (m_Stage_Flag == 2)
			{
				m_player_move_x -= 320;
				m_player_move_y -= 200;

				m_Stage_Flag = 1;
			}
			//�v���C���[���X�e�[�W�R�ɂ���Ƃ��X�e�[�W�Q�̈ʒu��
			if (m_Stage_Flag == 3)
			{
				m_player_move_x -= 320;
				m_player_move_y += 200;

				m_Stage_Flag = 2;
			}
		}

		//�E
		if (IsKeyPush(KEY_INPUT_D) == 1)
		{
			//�v���C���[���X�e�[�W�Q�ɂ���Ƃ��X�e�[�W�R��
			if (m_Stage_Flag == 2)
			{
				m_player_move_x += 320;
				m_player_move_y -= 200;

				m_Stage_Flag = 3;
			}
			//�v���C���[���X�e�[�W�P�ɂ���Ƃ��X�e�[�W�Q��
			if (m_Stage_Flag == 1)
			{
				m_player_move_x += 320;
				m_player_move_y += 200;

				m_Stage_Flag = 2;
			}


		}
	}
}

//�X�e�[�W�Z���N�g�`�揈��
void STAGE_SELECT::DrawStageSelect(int koin, int hidekoin, int playerremain)
{
	if (m_meinmenu.GetReturnFlag() == 0 && m_StageMoveFlag == 1)
	{
		PlayMovieToGraph(m_StageSelectImageHandle[12]);

		//�X�e�[�W�Z���N�g�J�ڕ`��
		DrawGraph(0, 0, m_StageSelectImageHandle[12], true);

	}

	if ((GetMovieStateToGraph(m_StageSelectImageHandle[12])) == 0)
	{
		m_StageMoveFlag = 0;

		PlayMovieToGraph(m_Stageselect_Movie_handle);

		//�X�e�[�W�Z���N�g����`��
		DrawGraph(0, 0, m_Stageselect_Movie_handle, true);

		if ((GetMovieStateToGraph(m_Stageselect_Movie_handle)) == 0) {
			//����Đ��ʒu��������
			SeekMovieToGraph(m_Stageselect_Movie_handle, 0);
			PlayMovieToGraph(m_Stageselect_Movie_handle);
		}

		//��1
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawRotaGraph(330, 450, 0.43f, 0.56f, m_StageSelectImageHandle[4], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//��2
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawRotaGraph(660, 460, 0.43f, 2.57f, m_StageSelectImageHandle[4], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�X�e�[�W�Z���N�g�A�C�R��
		//�X�e�[�W�P
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawRotaGraph(180, 350, 0.46f, 0.0f, m_StageSelectImageHandle[2], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawRotaGraph(181, 349, 0.66f, 0.0f, m_StageSelectImageHandle[1], true);

		//�X�e�[�W�t���O���P�̎���
		if (m_Stage_Flag == 1)
		{
			//�X�e�[�W�A�C�R��
			DrawRotaGraph(220, 200, 0.8f, 0.0f, m_StageSelectImageHandle[10], true);

			//�X�e�[�W�P����
			DrawRotaGraph(170, 130, 0.9f, -0.1f, m_StageSelectImageHandle[11], true);

		}

		//�X�e�[�W2
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawRotaGraph(500, 550, 0.46f, 0.0f, m_StageSelectImageHandle[2], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawRotaGraph(501, 549, 0.66f, 0.0f, m_StageSelectImageHandle[1], true);

		//�X�e�[�W3
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawRotaGraph(820, 350, 0.46f, 0.0f, m_StageSelectImageHandle[2], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawRotaGraph(821, 349, 0.66f, 0.0f, m_StageSelectImageHandle[1], true);

		//�v���C���[���\����
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 80);
		DrawRotaGraph(90, 55, 0.22f, 0.0f, m_StageSelectImageHandle[5], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//�v���C���[
		DrawRotaGraph(180 + m_player_move_x, 315 + m_player_move_y, 1.0f, 0.0f, m_playerhandle[0], true);

		//�v���C���[�c�@
		DrawRotaGraph(215, 55, 0.66f, 0.0f, m_StageSelectImageHandle[6], true);

		//�R�C��
		DrawRotaGraph(150, 55, 0.45f, 0.0f, m_StageSelectImageHandle[7], true);

		//�B���R�C��
		DrawRotaGraph(90, 55, 0.70f, 0.0f, m_StageSelectImageHandle[8], true);

		//�R�C�������`��
		DrawFormatString(170, 60, GetColor(255, 255, 255), "X%d", koin, true);

		//�B���R�C�������`��
		DrawFormatString(110, 60, GetColor(255, 255, 255), "X%d", hidekoin, true);

		//�v���C���[�c�@���`��
		DrawFormatString(235, 60, GetColor(255, 255, 255), "X%d", playerremain, true);

		//���C�����j���[�`��
		//�X�e�[�W�Z���N�g�t���O���P�̎�
		if (m_StageSelectFlag == 1)
		{
			m_meinmenu.DrawMeinMnu();	//�����Ă�
		}
	}

}

//�X�e�[�W�Z���N�g�㏈��
void STAGE_SELECT::FinStageSelect()
{

	

	DeleteGraph(m_StageSelectImageHandle[12]);

	DeleteGraph(m_Stageselect_Movie_handle);

	//���C�����j���[
	if (m_StageSelectFlag == 1)
	{
		m_meinmenu.FinMeinMnu();
	}

	if (m_StageSelectFlag == 0 && m_Stage_Flag == 1)
	{

		//�v���C�V�[��INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

//�Z�b�g�t���O
void STAGE_SELECT::SetFlag(int flag)
{

	m_StageMoveFlag = flag;

}