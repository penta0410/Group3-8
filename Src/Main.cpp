
#include "DxLib.h"
#include "Scene/Scene.h"
#include "../Src/Scene/Title/SceneTitle.h"
#include "../Src/Scene/Play/ScenePlay.h"
#include "../Src/Scene/Result/SceneResult.h"
#include "Common.h"
#include "FPS/fps.h"
#include "Scene/Meinmenu/MeinmenuScene.h"
#include "Input/Input.h"

//フレームレート情報変数
FrameRateInfo frameRateInfo;

//最初のシーンID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

//タイトルクラス宣言
TITLE title;
//メインメニュークラス宣言
MEIN_MENU meinmenu;
//プレイシーンクラス宣言
PLAY play;
//リザルトシーンクラス宣言
RESULT result;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);
	//ウィンドウサイズを変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

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
				title.Init();
				title.Load();
				title.Sound();
			}	break;
			case SCENE_ID_LOOP_TITLE:
			{
				//タイトル通常処理
				title.Step();
				//タイトル描画処理
				title.Draw();
			}	break;
			case SCENE_ID_FIN_TITLE:
			{
				//タイトル後処理
				title.Fin();
			}	break;
			case SCENE_ID_INIT_MEIN_MENU:
			{
				// ゲーム説明初期化
				meinmenu.Init();
			}	break;
			case SCENE_ID_LOOP_MEIN_MENU:
			{
				//メインメニュー通常処理
				meinmenu.Step();
				//メインメニュー描画処理
				meinmenu.Draw();
			}	break;
			case SCENE_ID_FIN_MEIN_MENU:
			{
				//メインメニュー後処理
				meinmenu.Fin();
			}	break;
			case SCENE_ID_INIT_PLAY:
			{
				//プレイ初期化  
				play.Init();
				play.Load();
				play.Sound();

			}	break;
			case SCENE_ID_LOOP_PLAY:
			{
				//プレイ描画処理
				play.Draw();
				//プレイ通常処理
				play.Step();
			}	break;
			case SCENE_ID_FIN_PLAY:
			{
				//プレイ後処理
				play.Fin();
			}	break;
			case SCENE_ID_INIT_RESULT:
			{
				//リザルト初期化  
				result.Init(play.GetCoin());
				//リザルト読み込み
				result.Load();

				result.Sound();
			}   break;
			case SCENE_ID_LOOP_RESULT:
			{
				//リザルト描画処理
				result.Draw();
				//リザルト通常処理
				result.Step();
			}	break;
			case SCENE_ID_FIN_RESULT:
			{
				//リザルト後処理
				result.Fin();
			}   break;
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
