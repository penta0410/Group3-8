#pragma once

//�V���b�v�摜�w�i
#define SHOP_BACK_PATH	"Data/Shop/�}1.jpg"

//�V���b�v�摜����
#define SHOP_NUM	(10)

class SHOP
{

private:

	//�V���b�v�V�[������̑J�ڃt���O
	int m_ShopFlag = 0;

	//�V���b�v�摜�n���h��
	int m_Shophandle[SHOP_NUM] = { 0 };

public:

	

	//�V���b�v������
	void InitShop();

	//�V���b�v�ʏ폈��
	void StepShop();

	//�V���b�v�`�揈��
	void DrawShop();

	//�V���b�v�㏈��
	void FinShop();

};
