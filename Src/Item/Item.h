#pragma once

//�A�C�e��1�摜�p�X
#define ITEM_PATH	"Data/PlayImage/item1.png"

//�A�C�e��2�摜�p�X
#define ITEM2_PATH	"Data/PlayImage/item2.png"

//�A�C�e��3�摜�p�X
#define ITEM3_PATH	"Data/PlayImage/item3.png"

//�A�C�e���摜����
const int ITEM_NUM = 20;

//�A�C�e���摜�ꗗ
enum ItemType {
	ITEM_NONE = -1,

	ITEM_1,
	ITEM_2,
	ITEM_3,

	ITEM_MAX
};

//�A�C�e���N���X
class Item
{
private:

	

	
public:
	Item();
	~Item();

	//�A�C�e���摜�n���h��
	int m_ItemImageHandle[ITEM_MAX] = { 0 };

	//�A�C�e��������
	void InitItem();

	
};