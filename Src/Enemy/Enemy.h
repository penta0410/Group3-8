#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../Screen/Screen.h"

//敵1画像パス
#define ENEMY_IMAGE_PATH  "Data/PlayImage/enemy.png"

//敵画像枚数
#define ENEMYI_IMAGE_NUMBER	 (1)

//敵１
#define ENEMY_MAX_NUM		(3)	    //敵1の数
#define ENEMY_WIDTH		(600)		//敵が出現できる横幅
#define ENEMY_ORIGIN_WIDTH	(400)	//原点から離れるｘ
#define ENEMY_HP	(100)			//敵１のHP
#define ENEMY_DAMAGE   (5)			//敵１の攻撃力
#define ENEMY_BODY_DAMAGE   (20)	//敵１の体のダメージ
#define ENEMY_POINT		(5)		//敵1のポイント
const int  ENEMY_W = 60;	//幅
const int  ENEMY_H = 30;	//高さ

class Enemy
{
private:

	//敵画像ハンドル
	int m_EnemyImageHandle[ENEMYI_IMAGE_NUMBER] = { 0 };

	

	//敵座標
	int m_enemy_x = 0;	//x座標
	int m_enemy_y = 0;	//y座標

	// 移動量
	int m_speedY = 0;
	int m_speedX = 0;

	//移動後の座標
	int m_nextPosX;
	int m_nextPosY;

	// 重力フラグ
	bool isGravity = false;

	//敵のHP
	int m_HP = 100;

public:
	Enemy();
	~Enemy();

	

	//敵初期化
	void Init();

	//敵通常処理
	void Step();

	//敵描画処理
	void Draw(int mapmove);

	//現在の座標を取得
	int GetPosX() { return m_enemy_x; }
	int GetPosY() { return m_enemy_y; }

	//移動後の座標を取得
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//座標を更新
	void UpdatePos();

	//座標を設定
	void SetPosX(int x);
	void SetPosY(int y);

	//進んでいる方向をチェック
	//上下左右
	void GetMoveDirection(bool* _dirArray);

	//敵HP取得
	int GetHP() { return m_HP; }

	//敵のHPを設定
	void SetHP(int hp);

	
};
#endif
