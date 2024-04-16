#include "DxLib.h"
#include "ItemConpositeScene.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "../StageSelect/StageSelect.h"
#include "../Play/ScenePlay.h"
#include "../../Item/Item.h"
#include "../../Collision/Collision.h"

//=============================
// アイテム合成シーン
//=============================

Item m_item;

//アイテム合成初期化
void ITEM_CONPOS::InitItemConpos()
{

	//合成画面背景
	m_ItemCoposHandle[0] = LoadGraph(ITEM_CONPOS_PATH);

	//黒背景
	m_ItemCoposHandle[1] = LoadGraph(STAGE_SELECT_ICON_BACKGROUND_PATH);

	//プラス画像
	m_ItemCoposHandle[2] = LoadGraph(ITEM_PLUS_PATH);

	//はてな画像
	m_ItemCoposHandle[3] = LoadGraph(QUESTION_PATH);

	//白枠画像
	m_ItemCoposHandle[7] = LoadGraph(FLAME_PATH);

	//黒背景
	m_ItemCoposHandle[8] = LoadGraph(BLACK_PATH);

	//横線
	m_w = 0;

	//合成欄
	m_bottan_x[0] = 180;
	m_bottan_y[0] = 400;
	m_bottan_r[0] = 80;

	m_bottan_x[1] = 500;
	m_bottan_y[1] = 400;
	m_bottan_r[1] = 80;

	//合成欄フラグ
	m_FlameFlag1 = 0;
	m_FlameFlag2 = 0;

	//インベントリフラグ
	m_InventoryFlag = 0;

	//インベントリの中身
	m_InventoryContents_X[0] = 905;
	m_InventoryContents_X[1] = 1015;
	m_InventoryContents_X[2] = 1125;
	m_InventoryContents_X[3] = 1235;

	m_InventoryContents_Y[0] = 45;
	m_InventoryContents_Y[1] = 155;
	m_InventoryContents_Y[2] = 265;
	m_InventoryContents_Y[3] = 375;
	m_InventoryContents_Y[4] = 480;
	m_InventoryContents_Y[5] = 590;
	m_InventoryContents_Y[6] = 700;
	m_InventoryContents_Y[7] = 810;
	m_InventoryContents_Y[8] = 920;
	m_InventoryContents_Y[9] = 1030;

	//合成欄アイテム選択フラグ
	m_item1alreadyFlag = 0;
	m_item2slreadyFlag = 0;

	//インベントリサイズ
	m_Inventory_x = 830;
	m_Inventory_y = 0;
	m_Inventory_w = 500;
	m_Inventory_h = 2000;

	//マウス座標
	m_Mouse_x = 0;
	m_Mouse_y = 0;

	//アイテム初期化
	m_item.InitItem();

	//アイテム合成ループへ
	g_CurrentSceneID = SCENE_ID_LOOP_ITEM_CONPOS;

}

//アイテム合成通常処理
void ITEM_CONPOS::StepItemConpos()
{
	
	//メニューシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		m_ItemConposFlag = 0;

		//アイテム合成後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_ITEM_CONPOS;
	}

}

//アイテム合成描画処理
void ITEM_CONPOS::DrawItemConpos()
{

	//アイテム合成画面描画
	DrawRotaGraph(650, 380, 1.55f, 0.0f, m_ItemCoposHandle[0], true);

	//黒背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawRotaGraph(180, 400, 0.65f, 0.0f, m_ItemCoposHandle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//白枠
	if (m_FlameFlag1 == 1)
	{
		DrawRotaGraph(180, 400, 0.3f, 0.0f, m_ItemCoposHandle[7], true);
	}

	//黒背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawRotaGraph(500, 400, 0.65f, 0.0f, m_ItemCoposHandle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//白枠
	if (m_FlameFlag2 == 1)
	{
		DrawRotaGraph(500, 400, 0.3f, 0.0f, m_ItemCoposHandle[7], true);
	}

	//プラス画像
	DrawRotaGraph(340, 400, 0.2f, 0.0f, m_ItemCoposHandle[2], true);
	
	//はてな画像
	if (m_item1alreadyFlag == 1 && m_item2slreadyFlag == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220);
		DrawRotaGraph(340, 250, 0.4f, 0.0f, m_ItemCoposHandle[3], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//アイテムインベントリ
	if (m_InventoryFlag == 1)
	{
		//黒背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220);
		DrawRotaGraph(1200, 200, 0.8f, 0.0f, m_ItemCoposHandle[8], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//左
		DrawLine(960, 0, 960, 2000, GetColor(255, 255, 255), true);

		//真ん中
		DrawLine(1070, 0, 1070, 2000, GetColor(255, 255, 255), true);

		//右
		DrawLine(1180, 0, 1180, 2000, GetColor(255, 255, 255), true);

		//横線
		for (int i = 0; i < 2000; i += 110)
		{
			for (int s = 0; s < 20; s++)
			{
				DrawLine(845, 100 + i, 1300, 100 + i, GetColor(255, 255, 255), true);
			}
		}

		//インベントリ処理
		Inventory();

	}

	

	//マウスクリック処理
	MouseClick();

}

//アイテム合成後処理
void ITEM_CONPOS::FinItemConpos()
{

	if (m_ItemConposFlag == 0)
	{
		//メニューシーンINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_MENU;
	}

}

//マウスクリック処理
void ITEM_CONPOS::MouseClick()
{

	//マウス位置取得
	GetMousePoint(&m_Mouse_x, &m_Mouse_y);

	//アイテム合成欄１
	if (IsHitCircle(m_bottan_x[0], m_bottan_y[0], m_bottan_r[0], m_Mouse_x, m_Mouse_y, 1) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255),
			"合成に使うアイテムを\n一つ選んでください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//インベントリフラグをonに
			m_InventoryFlag = 1;

			//アイテム合成欄をonに
			m_FlameFlag1 = 1;

			//アイテム合成欄をoffに
			m_FlameFlag2 = 0;
		}
		else
		{
			//押されていない
		}
	}

	//アイテム合成欄２
	if (IsHitCircle(m_bottan_x[1], m_bottan_y[1], m_bottan_r[1], m_Mouse_x, m_Mouse_y, 1) == 1)
	{
		//文字背景
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
		SetFontSize(12);
		DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255),
			"合成に使うアイテムを\n一つ選んでください");

		//文字サイズをもとに
		SetFontSize(16);

		//左クリックしたとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//インベントリフラグをonに
			m_InventoryFlag = 1;

			//アイテム合成欄をonに
			m_FlameFlag2 = 1;

			//アイテム合成欄をoffに
			m_FlameFlag1 = 0;

		}
		else
		{
			//押されていない
		}
	}

	//アイテム合成欄off
	if (m_InventoryFlag == 1)
	{
		if (!IsHitCircle(m_bottan_x[0], m_bottan_y[0], m_bottan_r[0], m_Mouse_x, m_Mouse_y, 1) == 1
			&& !IsHitCircle(m_bottan_x[1], m_bottan_y[1], m_bottan_r[1], m_Mouse_x, m_Mouse_y, 1) == 1
			&& !IsHitRect(m_Inventory_x, m_Inventory_y, m_Inventory_w, m_Inventory_h,
				m_Mouse_x, m_Mouse_y, 1, 1) == 1)
		{
			//左クリックしたとき
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				//インベントリフラグをoffに
				m_InventoryFlag = 0;

				//アイテム合成欄をoffに
				m_FlameFlag1 = 0;

				//アイテム合成欄をoffに
				m_FlameFlag2 = 0;
			}
			else
			{
				//押されていない
			}
		}
	}

	////リトライボタン
	//if (IsHitRect(m_Inventory_x, m_Inventory_y, m_Inventory_w, m_Inventory_h,
	//	m_Mouse_x, m_Mouse_y, 1, 1) == 1)
	//{
	//	//文字背景
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	//	DrawBox(m_Mouse_x - 150, m_Mouse_y + 20, m_Mouse_x + 60, m_Mouse_y + 80, GetColor(0, 0, 0), true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//	//ボタン位置にマウスカーソルが来た時に表示するヒントテキスト
	//	SetFontSize(12);
	//	DrawFormatString(m_Mouse_x - 140, m_Mouse_y + 30, GetColor(255, 255, 255),
	//		"<リトライ>\nボタンを左クリックするか\nenter(エンター)キーを押してください");

	//	//文字サイズをもとに
	//	SetFontSize(16);

	//	//左クリックしたとき
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	//	{
	//		

	//	}
	//	else
	//	{
	//		//押されていない
	//	}
	//}

}

//インベントリ処理
void ITEM_CONPOS::Inventory()
{
	
	//アイテム1
	
	for (int item_y = 0; item_y < 10; item_y++)
	{
		for (int item_x = 0; item_x < 4; item_x++)
		{
			if (m_InventoryContentsFlag_X[item_x] == 0 && m_InventoryContentsFlag_Y[item_y] == 0)
			{
				DrawRotaGraph(m_InventoryContents_X[item_x], m_InventoryContents_Y[item_y], 0.8f, 0.0f, m_item.m_ItemImageHandle[0], true);
				
				m_InventoryContentsFlag_X[item_x] == 1;

			}
		}

		m_InventoryContentsFlag_Y[item_y] == 1;

	}

	//アイテム2
	for (int item_y = 0; item_y < 10; item_y++)
	{
		for (int item_x = 0; item_x < 4; item_x++)
		{
			if (m_InventoryContentsFlag_X[item_x] == 0 && m_InventoryContentsFlag_Y[item_y] == 0)
			{
				DrawRotaGraph(m_InventoryContents_X[item_x], m_InventoryContents_Y[item_y], 0.8f, 0.0f, m_item.m_ItemImageHandle[1], true);
			
				m_InventoryContentsFlag_X[item_x] == 1;

			}

		}

		m_InventoryContentsFlag_Y[item_y] == 1;

	}

	////アイテム3
	//for (int item_y = 0; item_y < 10; item_y++)
	//{
	//	for (int item_x = 0; item_x < 4; item_x++)
	//	{
	//		if (m_InventoryContentsFlag_X[item_x] == 0 && m_InventoryContentsFlag_Y[item_y] == 0)
	//		{
	//			DrawRotaGraph(m_InventoryContents_X[item_x] - 5, m_InventoryContents_Y[item_y], 0.8f, 0.0f, m_item.m_ItemImageHandle[2], true);
	//		
	//			m_InventoryContentsFlag_X[item_x] == 1;

	//		}

	//	}
	//
	//	m_InventoryContentsFlag_Y[item_y] == 1;

	//}


}