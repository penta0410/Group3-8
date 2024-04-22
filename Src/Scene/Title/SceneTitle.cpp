
#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"

//=============================
// �^�C�g���V�[��
//=============================

//������
void TITLE::Init()
{


	//�^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//���[�h
void TITLE::Load()
{

}

//�ʏ폈��
void TITLE::Step()
{

	//�v���C�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O���v���C�V�[���ɕύX
		m_SceneFlag = 0;
		//�^�C�g���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}

}

//�`�揈��
void TITLE::Draw()
{

	//�f�o�b�O
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�^�C�g���V�[���ł��B", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "enter�Ń��C�����j���[�V�[��", true);
	SetFontSize(16);
}

//��������
void TITLE::Fin()
{
	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

