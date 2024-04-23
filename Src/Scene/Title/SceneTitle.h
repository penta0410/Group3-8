#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"

const char TITLE_BGM[] = { "Data/Sound/Title/ks011.wav" };		//�^�C�g����ʂ�BGM

//�^�C�g���N���X
class TITLE : public SCENE_BASE 
{
private:
	int m_BackHndl;
	int m_GroundHndl;
	int m_TitleHndl;
	int m_EnterHndl;
	int m_BGMHndl;

	//�n�ʂ̃X���C�h�p�̕ϐ�
	int m_GroundPosX;
	int m_GroundMaxPosX;

	//�G���^�[�̓_�ŗp�̕ϐ�
	int m_blink;
	

public:
	Player c_player;

	//������
	void Init() override;
	//���[�h
	void Load() override;
	//�ʏ폈��
	void Step()	override;
	//�`�揈��
	void Draw() override;
	//�㏈��
	void Fin() override;

	//���y�𗬂������̏���
	void Sound();

};

