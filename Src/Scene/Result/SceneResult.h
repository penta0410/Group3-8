#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"

const char RESULT_PATH[] = { "" };			//���U���g�̉摜�p�X


//���U���g�N���X
class RESULT : public SCENE_BASE
{
private:
	//�N���X�錾
	Player player;

	int ImageHandle;


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