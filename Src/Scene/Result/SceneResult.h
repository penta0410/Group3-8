#pragma once
#include "../Scene.h"

//���U���g�N���X
class RESULT : public SCENE_BASE
{
private:



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