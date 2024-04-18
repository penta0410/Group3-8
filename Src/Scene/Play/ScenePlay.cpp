#pragma once

#include "ScenePlay.h"
#include "../../Common.h"

//=============================
// �v���C�V�[��
//=============================

//������
void PLAY::Init()
{
	player.Init();				//�v���C���[�̏���������
	player.DefaultValue();		//�v���C���[�̏����l�ݒ�

	//�w�i���W
	m_BG_x[0] = WINDOW_WIDTH/2;
	m_BG_y[0] = WINDOW_HEIGHT/2;
	m_BG_x[1] = WINDOW_WIDTH + WINDOW_WIDTH / 2;
	m_BG_y[1] = WINDOW_HEIGHT + WINDOW_HEIGHT / 2;

	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//���[�h
void PLAY::Load()
{
	m_ImageHandle[0] = LoadGraph(PLAY_PATH[0]);			//�v���C�w�i
	player.Load();				//�v���C���[�̓ǂݍ���
}

//�ʏ폈��
void PLAY::Step()
{	
	player.Step();				//�v���C���[�̒ʏ폈��
	player.GetPosX();

	//���U���g�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O�����U���g�V�[���ɕύX
		m_SceneFlag = 0;
		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

}

//�`�揈��
void PLAY::Draw()
{
	//�w�i�`��
	DrawRotaGraph(m_BG_x[0], m_BG_y[0], 1.0f, 0.0f, m_ImageHandle[0], true);

	player.Draw();				//�v���C���[�̕`�揈��

	

	//�f�o�b�O
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�v���C�V�[���ł��B", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "enter�Ń��U���g�V�[��", true);
	SetFontSize(16);
}

//�㏈��
void PLAY::Fin()
{
	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//�v���CINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}