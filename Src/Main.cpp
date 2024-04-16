
#include "DxLib.h"
#include "Scene/Scene.h"
#include "../Src/Scene/Title/SceneTitle.h"
#include "../Src/Scene/Play/ScenePlay.h"
#include "../Src/Scene/Clear/SceneClear.h"
#include "../Src/Scene/GameOver/SceneGameOver.h"
#include "Collision/Collision.h"
#include "Input/Input.h"
#include "Common.h"
#include "FPS/fps.h"
#include "Scene/StageSelect/StageSelect.h"
#include "Scene/Option/Option.h"
#include "Scene/Option/GameExplain.h"
#include "Scene/Meinmenu/MeinmenuScene.h"
#include "Scene/Menu/MenuScene.h"
#include "Scene/ItemConpos/ItemConpositeScene.h"
#include "Scene/Shop/ShopScene.h"

//フレームレート情報変数
FrameRateInfo frameRateInfo;

//現在のシーンID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

//タイトルクラス宣言
TITLE title;

//オプションクラス宣言
OPTION option;

//ゲーム説明クラス宣言
GAME_EXPLAIN game_explain;

//ステージセレクトクラス宣言
STAGE_SELECT stage_select;

//メインメニュークラス宣言
MEIN_MENU mein_menu;

//ショップクラス宣言
SHOP shop;

//メニュークラス宣言
MENU menu;

//アイテム合成クラス宣言
ITEM_CONPOS item_conpos;

//プレイシーンクラス宣言
PLAY play;

//クリアクラス宣言
CLEAR clear;

//ゲームオーバークラス宣言
GAME_OVER game_over;

//ゲット、セット関数のクラス
class  GetSet
{
public:

	//ゲットメソッド
	void Get();

	//セットメソッド
	void Set();

};
int MovieGraphHandle;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(false);

	//ウィンドウサイズを変更

	if (title.m_start_animetion_flag == 1)
	{
		/*SetGraphMode(WINDOW2_WIDTH, WINDOW2_HEIGHT, 32);*/

		
	}
	else if (title.m_start_animetion_flag == 0)
	{
		SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	}

	//DXライブラリの初期化
	if(DxLib_Init() == -1)
	{
		return -1;
	}


	//描画するスクリーンを設定
	SetDrawScreen(DX_SCREEN_BACK);

	//入力制御初期化
	InitInput();
	

	//=====================================
	//ゲームメインループ
	while(ProcessMessage() != -1)
	{
		Sleep(1);	//システムに処理を返す

		
		//現在の時間を取得
		frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// 現在の時間が、前回のフレーム時より
		// 1000/60ミリ秒（1/60秒）以上経過していたら処理を実行する
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//フレーム数をカウント
			frameRateInfo.count++;

			if (IsKeyPush(KEY_INPUT_ESCAPE))
			{
				//エスケープキーが押されたら終了
				break;
			}

			

			//画面に表示されたものを初期化（１ループの１度だけ行う）
			ClearDrawScreen();

			//入力制御ステップ
			StepInput();

			//シーンIDによって処理の振り分け
			switch (g_CurrentSceneID)
			{
			case SCENE_ID_INIT_TITLE:
			{
				//タイトル初期化
				title.InitTitle();
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				

				//タイトル通常処理
				title.StepTitle();
		
				//タイトル描画処理
				title.DrawTitle();
			
			}
			break;

			case SCENE_ID_FIN_TITLE:
			{
				//タイトル後処理
				title.FinTitle();
			}
			break;

			case SCENE_ID_INIT_OPTION:
			{
				//オプション初期化
				option.InitOption();

			}
			break;

			case SCENE_ID_LOOP_OPTION:
			{
				//オプション通常処理
				option.StepOption();

				//オプション描画処理
				option.DrawOption();
			}
			break;

			case SCENE_ID_FIN_OPTION:
			{
				//オプション後処理
				option.FinOption();
			}
			break;

			case SCENE_ID_INIT_GAME_EXPLAIN:
			{
				//ゲーム説明初期化
				game_explain.InitGameExplain();
			}
			break;

			case SCENE_ID_LOOP_GAME_EXPLAIN:
			{ 
				//ゲーム説明通常処理
				game_explain.StepGameExplain();

				//ゲーム説明描画処理
				game_explain.DrawGameExplain();
			}
			break;

			case SCENE_ID_FIN_GAME_EXPLAIN:
			{
				//ゲーム説明後処理
				game_explain.FinGameExplain();
			}
			break;

			case SCENE_ID_INIT_STAGE_SELECT:
			{
				//ステージセレクト初期化
				stage_select.InitStageSelect();

			}
			break;

			case SCENE_ID_LOOP_STAGE_SELECT:
			{
				//ステージセレクト通常処理
				stage_select.StepStageSelect();

				//ステージセレクト描画処理
				stage_select.DrawStageSelect(play.GetKoin(), play.GetHideKoin(), 
					play.GetPlayerRemain());
			}
			break;

			case SCENE_ID_FIN_STAGE_SELECT:
			{
				//ステージセレクト後処理
				stage_select.FinStageSelect();
			}
			break;

			//case SCENE_ID_INIT_MEIN_MENU:
			//{
			//	// ゲーム説明初期化
			//	mein_menu.InitMeinMnu();
			//}
			//break;

			//case SCENE_ID_LOOP_MEIN_MENU:
			//{
			//	//メインメニュー通常処理
			//	mein_menu.StepMeinMnu();

			//	//メインメニュー描画処理
			//	mein_menu.DrawMeinMnu();
			//}
			//break;

			//case SCENE_ID_FIN_MEIN_MENU:
			//{
			//	//メインメニュー後処理
			//	mein_menu.FinMeinMnu(1);
			//}
			//break;

			case SCENE_ID_INIT_MENU:
			{
				//ステージセレクト初期化
				menu.InitMenu();
			}
			break;


			case SCENE_ID_LOOP_MENU:
			{
				//ステージセレクト通常処理
				menu.StepMenu();

				//ステージセレクト描画処理
				menu.DrawMenu();
			}
			break;

			case SCENE_ID_FIN_MENU:
			{
				//ステージセレクト後処理
				menu.FinMenu();
			}
			break;

			case SCENE_ID_INIT_INVENTORY:
			{

			}
			break;

			case SCENE_ID_LOOP_INVENTORY:
			{

			}
			break;

			case SCENE_ID_FIN_INVENTORY:
			{

			}
			break;

			case SCENE_ID_INIT_ITEM_CONPOS:
			{
				//アイテム合成初期化
				item_conpos.InitItemConpos();
			}
			break;

			case SCENE_ID_LOOP_ITEM_CONPOS:
			{
				//アイテム合成通常処理
				item_conpos.StepItemConpos();

				//アイテム合成描画処理
				item_conpos.DrawItemConpos();
			}
			break;

			case SCENE_ID_FIN_ITEM_CONPOS:
			{
				//アイテム合成後処理
				item_conpos.FinItemConpos();
			}
			break;


			case SCENE_ID_INIT_SHOP:
			{
				//ショップ初期化
				shop.InitShop();
			}
			break;


			case SCENE_ID_LOOP_SHOP:
			{
				//ショップ通常処理
				shop.StepShop();

				//ショップ描画処理
				shop.DrawShop();
			}
			break;


			case SCENE_ID_FIN_SHOP:
			{
				//ショップ後処理
				shop.FinShop();
			}
			break;

			case SCENE_ID_INIT_PLAY:
			{
				//プレイ初期化  
				play.InitPlay();
			}
			break;

			case SCENE_ID_LOOP_PLAY:
			{
				//プレイ描画処理
				play.DrawPlay();

				//プレイ通常処理
				play.StepPlay();

			}
			break;

			case SCENE_ID_FIN_PLAY:
			{
				//プレイ後処理
				play.FinPlay();
			}
			break;

			case SCENE_ID_INIT_CLEAR:
			{

				//クリア初期化
				clear.InitClear();

			}
			break;

			case SCENE_ID_LOOP_CLEAR:
			{
				//クリア通常処理
				clear.StepClear();

				//クリア描画処理
				clear.DrawClear(play.GetKoin(), play.GetHideKoin(), 
					play.GetPlayerRemain(), play.GetScore(), 
					play.GetGoalFlag(), play.GetKoinFlag(), play.GetDefeatFlag() );

			}
			break;

			case SCENE_ID_FIN_CLEAR:
			{
				//クリア後処理
				clear.FinClear();
			}
			break;

			case SCENE_ID_INIT_GAMEOVER:
			{
				//ゲームオーバー初期化
				game_over.InitGameOver();
			}
			break;

			case SCENE_ID_LOOP_GAMEOVER:
			{
				//ゲームオーバー通常処理
				game_over.StepGameOver();

				//ゲームオーバー描画処理
				game_over.DrawGameOver(play.GetKoin(), play.GetHideKoin(),
					play.GetPlayerRemain(), play.GetScore(),
					play.GetGoalFlag(), play.GetKoinFlag(), play.GetDefeatFlag());

			}
			break;

			case SCENE_ID_FIN_GAMEOVER:
			{

				//ゲームオーバー後処理
				game_over.FinGameOver();

			}

			}//シーン振り分けのswitch文終了

			//FPS計算
			CalcFPS();

			//FPS表示
			DrawFPS();

			//フリップ関数（ループの終わりに１度だけ行う）
			ScreenFlip();

		}//フレームレートのif文終わり

	}//メインループの終わり

	//最後に１回だけやる処理をここに書く
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

void GetSet::Get()
{

}

void GetSet::Set()
{

}
