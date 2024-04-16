#include "Item.h"
#include "DxLib.h"
#include <string.h>

Item::Item() {}
Item::~Item() {}

void Item::InitItem()
{

	//âÊëúÇÃì«Ç›çûÇ›
	m_ItemImageHandle[ITEM_1] = LoadGraph(ITEM_PATH);

	m_ItemImageHandle[ITEM_2] = LoadGraph(ITEM2_PATH); 

	m_ItemImageHandle[ITEM_3] = LoadGraph(ITEM3_PATH);

}