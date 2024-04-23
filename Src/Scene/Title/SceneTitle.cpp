
#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../../Transparent/Transparent.h"
#include "../../Collision/Collision.h"
#include "../../Transparent/Transparent.h"

//�摜�ǂݍ���
#define TITEL_BACK_PATH	"Data/Title/BackGround.png"
#define TITEL_GROUND_PATH "Data/Title/ground.png"
#define TITLE_PATH	"Data/Title/Title.png"
#define TITLE_ENTER_PATH "Data/Title/Enter.png"

//=============================
// �^�C�g���V�[��
//=============================

//������
void TITLE::Init()
{
	//�n���h���̏�����
	m_BackHndl = 0;			//�w�i
	m_GroundHndl = 0;		//�n��
	m_TitleHndl = 0;		//�^�C�g����
	m_EnterHndl = 0;		//�G���^�[
	m_BGMHndl = -1;			//�^�C�g�����BGM

	//�n�ʂ̃X���C�h�p�̕ϐ��̏�����
	m_GroundPosX = 0;
	m_GroundMaxPosX = 1280;

	//�G���^�[�̓_�ŗp�̕ϐ��̏�����
	m_blink = 0;
	
	//�v���C���[������
	c_player.Init();
	c_player.DefaultValue();

	//�^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//���[�h
void TITLE::Load()
{
	m_BGMHndl = LoadSoundMem(TITLE_BGM);
	m_BackHndl = LoadGraph(TITEL_BACK_PATH);
	m_GroundHndl = LoadGraph(TITEL_GROUND_PATH);
	m_TitleHndl = LoadGraph(TITLE_PATH);
	m_EnterHndl = LoadGraph(TITLE_ENTER_PATH);

	//�v���C���[���[�h
	c_player.Load();
}

void TITLE::Sound()
{
	PlaySoundMem(m_BGMHndl, DX_PLAYTYPE_LOOP);
}

//�ʏ폈��
void TITLE::Step()
{
	
	//�n�ʂ̃X�N���[��
	m_GroundPosX -= 4;
	m_GroundMaxPosX -= 4;
	if (m_GroundPosX <= -1280) {
		m_GroundPosX = 1280;
	}
	if (m_GroundMaxPosX <= -1280) {
		m_GroundMaxPosX = 1280;
	}

	m_blink = Transparent(m_blink, 1);

	c_player.Animation();

	//���C�����j���[�V�[���ւ̑J��
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
	DrawGraph(0, 0, m_BackHndl, true);
	DrawGraph(m_GroundPosX, 500, m_GroundHndl, true);
	DrawGraph(m_GroundMaxPosX, 500, m_GroundHndl, true);
	DrawGraph(300, 50, m_TitleHndl, true);
	
	//�_�ŏ����i�G���^�[�j
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_blink);
	DrawGraph(370, 350, m_EnterHndl, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_blink);

	c_player.Draw();

}

//��������
void TITLE::Fin()
{
	//�폜
	DeleteSoundMem(m_BGMHndl);

	c_player.Fin();

	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//INIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}

