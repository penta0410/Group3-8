#pragma once
#include "../Screen/Screen.h"

// 各マップのデータ数
const int MAP_DATA_Y = 20;
const int MAP_DATA_X = 200;

// マップサイズ
const int MAP_SIZE = 56;

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

	MAPCHIP_MAX
};

// マップクラス
class Map
{
private:

	Screen m_screen;

	// 画像ハンドル
	int imgHundle[MAPCHIP_MAX];

	int move = 0;

	int move_2 = 0;

	int increase = 0;

public:
	Map();
	~Map();

	//ファイル読み込みフラグ
	bool isReadFile;
	bool isReadFile2;

	//ファイルからのマップデータ
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };
	int m_FileReadMapData2[MAP_DATA_Y][MAP_DATA_X] = { 0 };

	//ファイル１読み込み終了フラグ
	int ReadFileFlag_1 = 0;
	//ファイル2読み込み終了フラグ
	int ReadFileFlag_2 = 0;

	//マップチップ描画フラグ
	int DrawFlag_1 = 0;
	int DrawFlag_2 = 0;
	
	//初期化
	void Init();

	//通常処理
	void Step();
	
	//コインブロック処理
	void Koin();

	//描画
	void Draw(int mapmove);

	//ファイルからの読み込み
	void ReadFile();
};

