
#include <math.h>
#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"

//=============================
// �v���C�V�[��
//=============================

//������
void PLAY::Init()
{
	player.Init();				//�v���C���[�̏���������
	player.DefaultValue();		//�v���C���[�̏����l�ݒ�

	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//���[�h
void PLAY::Load()
{
	player.Load();				//�v���C���[�̓ǂݍ���
}

//�ʏ폈��
void PLAY::Step()
{	
	player.Step();				//�v���C���[�̒ʏ폈��

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