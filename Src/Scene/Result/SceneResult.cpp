#include "SceneResult.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Collision/Collision.h"

//������
void RESULT::Init()
{

	//���U���g���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}
//���[�h
void RESULT::Load()
{

}

//�ʏ폈��
void RESULT::Step()
{

	//�^�C�g���V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O���^�C�g���V�[���ɕύX
		m_SceneFlag = 0;
		//���U���g�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

//�`�揈��
void RESULT::Draw()
{

	//�f�o�b�O
	SetFontSize(30);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "���U���g�V�[���ł��B", true);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "enter�Ń^�C�g���V�[��", true);
	SetFontSize(16);
}

//�㏈��
void RESULT::Fin()
{

	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//�v���CINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
}