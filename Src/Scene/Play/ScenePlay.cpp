#pragma once

#include "ScenePlay.h"
#include "../../Common.h"

//=============================
// プレイシーン
//=============================

//初期化
void PLAY::Init()
{
	player.Init();				//プレイヤーの初期化処理
	player.DefaultValue();		//プレイヤーの初期値設定
	m_map.Init();				//マップ初期化

	//背景座標
	m_BG_x[0] = WINDOW_WIDTH/2;
	m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	m_BG_y = WINDOW_HEIGHT/2;
	//背景移動量
	m_BG_move_x = 0;


	
	
	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//ロード
void PLAY::Load()
{
	m_ImageHandle[0] = LoadGraph(PLAY_PATH[0]);			//プレイ背景
	m_ImageHandle[1] = LoadGraph(PLAY_PATH[1]);			//プレイ背景2
	player.Load();				//プレイヤーの読み込み
}

//通常処理
void PLAY::Step()
{	
	player.Step();				//プレイヤーの通常処理

	//背景スクロール処理
	m_BG_x[0] -= PLAYER_SPEED;
	m_BG_x[1] -= PLAYER_SPEED;
	m_BG_move_x -= PLAYER_SPEED;

	if (m_BG_x[0] <= -(WINDOW_WIDTH / 2))
	{
		m_BG_x[0] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	}
	else if (m_BG_x[1] <= -(WINDOW_WIDTH / 2))
	{
		m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	}

	//マップの当たり判定
	MapCollision(-m_BG_move_x);

	//プレイヤーの座標を更新
	player.UpdatePos();

	

	

	//リザルトシーンへの遷移
	//Enterキー押されたなら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//シーンフラグをリザルトシーンに変更
		m_SceneFlag = 0;
		//プレイ後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

}

//描画処理
void PLAY::Draw()
{
	//背景描画
	DrawRotaGraph(m_BG_x[0], m_BG_y, 1.0f, 0.0f, m_ImageHandle[0], true);
	DrawRotaGraph(m_BG_x[1], m_BG_y, 1.0f, 0.0f, m_ImageHandle[1], true);

	m_map.Draw(-m_BG_move_x);	//マップ描画

	player.Draw();				//プレイヤーの描画処理

	

	//デバッグ
	SetFontSize(30);
	SetFontSize(16);
}

//後処理
void PLAY::Fin()
{
	//SceneFlagが0の時
	if (m_SceneFlag == 0)
	{
		//プレイINITへ移動
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}

//マップの当たり判定
void PLAY::MapCollision(int mapmove)
{
	//プレイヤー
	//Y方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			//ブロック以外は処理しない
			if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//どの方向に進んでいたかチェック
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			//矩形の当たり判定用のデータを準備
			//プレイヤーの情報
			int Ax = player.GetPosX() - 20 - mapmove;
			int Ay = player.GetPosY() - 10;
			int Aw = PLAYER_WIDTH * 2;
			int Ah = PLAYER_HEIGHT * 2;

			//オブジェクトの情報
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//Y方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = player.GetNextPosY();
			Ax = player.GetPosX();

			//当たっているかチェック
			if (IsHitRect(Ax + mapmove, Ay, Aw, Ah, Bx + mapmove, By, Bw, Bh)) {

				// 上方向の修正
				if (dirArray[0]) {
					// めり込み量を計算する
					int overlap = By + Bh - Ay;
					player.SetNextPosY(Ay + overlap);

					//天井についたら押し返す
					player.PlayerCeiling();

				}

				//下方向の修正
				if (dirArray[1]) {
					// めり込み量を計算する
					int overlap = Ay + Ah - By;
					player.SetNextPosY(Ay - overlap);

					//落下したら
					player.PlayerLanding();

				}

				////アイテムブロック
				////左から一つ目
				//if (m_ItemBlock_x[0] < m_Player.GetPosX() + PLAYER_SIZE_W - 40 &&
				//	m_Player.GetPosX() - 300 < m_ItemBlock_x[0] + (m_ItemBlock_w - 30))
				//{
				//	if (dirArray[0] && ItemBlockFlag[0] == 1)
				//	{
				//		m_Map.m_FileReadMapData[7][4] = 3;
				//		m_itemFlag[0] = 1;
				//		ItemBlockFlag[0] = 0;

				//	}
				//}

				////左から二つ目
				//if (m_ItemBlock_x[1] + 290 < m_Player.GetPosX() + PLAYER_SIZE_W - 40 &&
				//	m_Player.GetPosX() - 300 < m_ItemBlock_x[1] + (m_ItemBlock_w - 30))
				//{

				//	if (dirArray[0] && ItemBlockFlag[1] == 1)
				//	{
				//		m_Map.m_FileReadMapData[7][5] = 3;
				//		m_itemFlag[1] = 1;

				//		ItemBlockFlag[1] = 0;

				//	}

				//}

			}
		}
	}

	// X方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			// ブロック以外は処理しない
			if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//どの方向に進んでいたかチェック
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			//プレイヤーの情報
			int Ax = player.GetPosX() - 20 - mapmove;
			int Ay = player.GetPosY() - 10;
			int Aw = PLAYER_WIDTH * 2;
			int Ah = PLAYER_HEIGHT * 2;

			//オブジェクトの情報
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//X方向のみに移動したと仮定した座標で当たり判定をチェック
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			// 当たっているかチェック
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				// 左方向の修正
				if (dirArray[2]) {
					// めり込み量を計算する
					int overlap = Bx + Bw - Ax;
					player.SetNextPosX(Ax + overlap);
				}

				// 右方向の修正
				if (dirArray[3]) {
					// めり込み量を計算する
					int overlap = Ax + Aw - Bx;
					player.SetNextPosX(Ax - overlap);
				}
			}
		}
	}

	////敵
	////Y方向のみ当たり判定をチェックする
	//for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	//{
	//	for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
	//	{
	//		//ブロック以外は処理しない
	//		if (m_Map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
	//			continue;


	//		//どの方向に進んでいたかチェック
	//		bool dirArray[4] = { false,false,false,false };
	//		m_enemy.GetMoveDirection(dirArray);


	//		//矩形の当たり判定用のデータを準備
	//		//敵の情報
	//		int Ax = m_enemy.GetPosX() - 30;
	//		int Ay = m_enemy.GetPosY() - 30;
	//		int Aw = ENEMY_W + 30;
	//		int Ah = ENEMY_H + 30;

	//		//オブジェクトの情報
	//		int Bx = mapIndexX * MAP_SIZE - 240;
	//		int By = mapIndexY * MAP_SIZE + 30;
	//		int Bw = MAP_SIZE - 30;
	//		int Bh = MAP_SIZE;

	//		//Y方向のみに移動したと仮定した座標で当たり判定をチェックします
	//		Ay = m_enemy.GetNextPosY();
	//		Ax = m_enemy.GetPosX();

	//		//当たっているかチェック
	//		if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
	//		{

	//			// 上方向の修正
	//			if (dirArray[0]) {
	//				// めり込み量を計算する
	//				int overlap = By + Bh - Ay;
	//				m_enemy.SetPosY(Ay + overlap);
	//			}

	//			//下方向の修正
	//			if (dirArray[1]) {
	//				// めり込み量を計算する
	//				int overlap = Ay + Ah - By;
	//				m_enemy.SetPosY(Ay - overlap);
	//			}
	//		}
	//	}
	//}

	//// X方向のみ当たり判定をチェックする
	//for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	//{
	//	for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
	//	{
	//		// ブロック以外は処理しない
	//		if (m_Map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
	//			continue;

	//		//どの方向に進んでいたかチェック
	//		bool dirArray[4] = { false,false,false,false };
	//		m_enemy.GetMoveDirection(dirArray);

	//		//敵の情報
	//		int Ax = m_enemy.GetPosX() - 30;
	//		int Ay = m_enemy.GetPosY() - 30;
	//		int Aw = ENEMY_W;
	//		int Ah = ENEMY_H;

	//		//オブジェクトの情報
	//		int Bx = mapIndexX * MAP_SIZE - 240;
	//		int By = mapIndexY * MAP_SIZE + 30;
	//		int Bw = MAP_SIZE - 30;
	//		int Bh = MAP_SIZE;

	//		//X方向のみに移動したと仮定した座標で当たり判定をチェック
	//		Ay = m_enemy.GetPosY();
	//		Ax = m_enemy.GetPosX();

	//		// 当たっているかチェック
	//		if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh))
	//		{

	//			// 左方向の修正
	//			if (dirArray[2]) {
	//				// めり込み量を計算する
	//				int overlap = Bx + Bw - Ax;
	//				m_enemy.SetPosX(Ax + overlap);
	//			}

	//			// 右方向の修正
	//			if (dirArray[3]) {
	//				// めり込み量を計算する
	//				int overlap = Ax + Aw - Bx;
	//				m_enemy.SetPosX(Ax - overlap);
	//			}
	//		}
	//	}
	//}

}