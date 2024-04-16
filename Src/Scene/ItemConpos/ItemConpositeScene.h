#pragma once

//アイテム合成画面背景画像パス
#define ITEM_CONPOS_PATH	"Data/ItemcomposeImage/画像6.jpg"

//アイテムプラス画像パス
#define ITEM_PLUS_PATH	"Data/ItemcomposeImage/図1.png"

//はてな画像
#define QUESTION_PATH	"Data/ItemcomposeImage/図3.png"

//白枠画像
#define FLAME_PATH	"Data/ItemcomposeImage/図4.png"

//黒背景
#define BLACK_PATH	"Data/ItemcomposeImage/図2.png"

//アイテム合成画像枚数
#define ITEM_CONPOS_NUM (20)

class ITEM_CONPOS
{

private:

	

	//横線
	int m_w = 0;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標

	//ボタンサイズ
	int m_bottan_x[3] = { 0 };	//ｘ座標
	int m_bottan_y[3] = { 0 };	//y座標
	int m_bottan_r[3] = { 0 };		//半径
	int m_bottan_w = 0;	    //横
	int m_bottan_h = 0;	    //縦

	//インベントリフラグ
	int m_InventoryFlag = 0;

	//インベントリの中身
	int m_InventoryContents_X[4] = { 0 };
	int m_InventoryContents_Y[10] = { 0 };

	//インベントリの中身フラグ
	int m_InventoryContentsFlag_X[4] = { 0 };
	int m_InventoryContentsFlag_Y[10] = { 0 };

	//合成欄フラグ
	int m_FlameFlag1 = 0;
	int m_FlameFlag2 = 0;

	//合成欄アイテム選択フラグ
	int m_item1alreadyFlag = 0;
	int m_item2slreadyFlag = 0;

	//インベントリサイズ
	int m_Inventory_x = 0;
	int m_Inventory_y = 0;
	int m_Inventory_w = 0;
	int m_Inventory_h = 0;

public:

	//アイテム合成画像ハンドル
	int m_ItemCoposHandle[ITEM_CONPOS_NUM] = { 0 };

	//アイテム合成シーンからの遷移フラグ
	int m_ItemConposFlag = 0;

	//アイテム合成初期化
	void InitItemConpos();

	//アイテム合成通常処理
	void StepItemConpos();

	//アイテム合成描画処理
	void DrawItemConpos();

	//アイテム合成後処理
	void FinItemConpos();

	//マウスクリック処理
	void MouseClick();

	//インベントリ処理
	void Inventory();

};