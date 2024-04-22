#pragma once
#include "../Scene.h"
#include "../../Player/Player.h"

const char RESULT_PATH[] = { "" };			//リザルトの画像パス


//リザルトクラス
class RESULT : public SCENE_BASE
{
private:
	//クラス宣言
	Player player;

	int ImageHandle;


public:

	//初期化
	void Init() override;
	//ロード
	void Load() override;
	//通常処理
	void Step()	override;
	//描画処理
	void Draw() override;
	//後処理
	void Fin() override;

};