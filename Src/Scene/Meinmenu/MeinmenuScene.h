#pragma once
#include "../Scene.h"

//メインメニュークラス
class MEIN_MENU : public SCENE_BASE
{
private:

	

	

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