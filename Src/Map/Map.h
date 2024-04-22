#pragma once
#include "../Screen/Screen.h"
#include "../Player/Player.h"

// 各マップのデータ数
const int MAP_DATA_Y = 20;
const int MAP_DATA_X = 1000;

// マップサイズ
const int MAP_SIZE = 56;

//トラップダメージ
const int TRAP_DAMAGE = 10;

//コイン枚数
const int COIN_NUM = 300;

// マップチップ画像一覧
enum MapChipType {
	MAPCHIP_NONE = -1,

	MAPCHIP_BLOCK,
	MAPCHIP_KUSA,
	MAPCHIP_HATENA,
	MAPCHIP_HATENA_2,
	MAPCHIP_KAGI,
	MAPCHIP_KAGIBLOCK,
	MAPCHIP_HAKO,
	MAPCHIP_COIN,
	MAPCHIP_TRAP,
	MAPCHIP_HEART,

	MAPCHIP_MAX
};

// マップクラス
class Map
{
private:

	Screen m_screen;
	Player player;

	// 画像ハンドル
	int imgHundle[MAPCHIP_MAX];

	int move = 0;

	int move_2 = 0;

	int increase = 0;

	//コイン描画フラグ
	int CoinFlag[COIN_NUM];

public:
	Map();
	~Map();

	//ファイル読み込みフラグ
	bool isReadFile;


	//ファイルからのマップデータ
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };


	//ファイル１読み込み終了フラグ
	int ReadFileFlag_1 = 0;
	

	//マップチップ描画フラグ
	int DrawFlag_1 = 0;
	
	
	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw(int mapmove);

	//ファイルからの読み込み
	void ReadFile();

	//コイン通常処理
	void CoinStep(int x, int y);

	//ハート通常処理
	void HeartStep(int x, int y);
	
};

