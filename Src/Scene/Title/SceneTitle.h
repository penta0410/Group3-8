#pragma once
#include "../Scene.h"

//�^�C�g���N���X
class TITLE : public SCENE_BASE 
{
private:
	int m_BackHndl;
	int m_GroundHndl;
	int m_TitleHndl;
	int m_EnterHndl;

	//�n�ʂ̃X���C�h�p�̕ϐ�
	int m_GroundPosX;
	int m_GroundMaxPosX;

	//�G���^�[�̓_�ŗp�̕ϐ�
	int m_blink;
	int m_blinkflag;
public:

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

};

