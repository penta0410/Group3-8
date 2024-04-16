#pragma once

//�A�C�e��������ʔw�i�摜�p�X
#define ITEM_CONPOS_PATH	"Data/ItemcomposeImage/�摜6.jpg"

//�A�C�e���v���X�摜�p�X
#define ITEM_PLUS_PATH	"Data/ItemcomposeImage/�}1.png"

//�͂Ăȉ摜
#define QUESTION_PATH	"Data/ItemcomposeImage/�}3.png"

//���g�摜
#define FLAME_PATH	"Data/ItemcomposeImage/�}4.png"

//���w�i
#define BLACK_PATH	"Data/ItemcomposeImage/�}2.png"

//�A�C�e�������摜����
#define ITEM_CONPOS_NUM (20)

class ITEM_CONPOS
{

private:

	

	//����
	int m_w = 0;

	//�}�E�X���W
	int m_Mouse_x = 0;	//�����W
	int m_Mouse_y = 0;	//y���W

	//�{�^���T�C�Y
	int m_bottan_x[3] = { 0 };	//�����W
	int m_bottan_y[3] = { 0 };	//y���W
	int m_bottan_r[3] = { 0 };		//���a
	int m_bottan_w = 0;	    //��
	int m_bottan_h = 0;	    //�c

	//�C���x���g���t���O
	int m_InventoryFlag = 0;

	//�C���x���g���̒��g
	int m_InventoryContents_X[4] = { 0 };
	int m_InventoryContents_Y[10] = { 0 };

	//�C���x���g���̒��g�t���O
	int m_InventoryContentsFlag_X[4] = { 0 };
	int m_InventoryContentsFlag_Y[10] = { 0 };

	//�������t���O
	int m_FlameFlag1 = 0;
	int m_FlameFlag2 = 0;

	//�������A�C�e���I���t���O
	int m_item1alreadyFlag = 0;
	int m_item2slreadyFlag = 0;

	//�C���x���g���T�C�Y
	int m_Inventory_x = 0;
	int m_Inventory_y = 0;
	int m_Inventory_w = 0;
	int m_Inventory_h = 0;

public:

	//�A�C�e�������摜�n���h��
	int m_ItemCoposHandle[ITEM_CONPOS_NUM] = { 0 };

	//�A�C�e�������V�[������̑J�ڃt���O
	int m_ItemConposFlag = 0;

	//�A�C�e������������
	void InitItemConpos();

	//�A�C�e�������ʏ폈��
	void StepItemConpos();

	//�A�C�e�������`�揈��
	void DrawItemConpos();

	//�A�C�e�������㏈��
	void FinItemConpos();

	//�}�E�X�N���b�N����
	void MouseClick();

	//�C���x���g������
	void Inventory();

};