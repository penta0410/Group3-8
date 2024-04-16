#pragma once

//アイテム1画像パス
#define ITEM_PATH	"Data/PlayImage/item1.png"

//アイテム2画像パス
#define ITEM2_PATH	"Data/PlayImage/item2.png"

//アイテム3画像パス
#define ITEM3_PATH	"Data/PlayImage/item3.png"

//アイテム画像枚数
const int ITEM_NUM = 20;

//アイテム画像一覧
enum ItemType {
	ITEM_NONE = -1,

	ITEM_1,
	ITEM_2,
	ITEM_3,

	ITEM_MAX
};

//アイテムクラス
class Item
{
private:

	

	
public:
	Item();
	~Item();

	//アイテム画像ハンドル
	int m_ItemImageHandle[ITEM_MAX] = { 0 };

	//アイテム初期化
	void InitItem();

	
};