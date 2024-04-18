#pragma once
#include "../Screen/Screen.h"

//マップパス
#define MAP_IMAGE_PATH	"Data/PlayImage/画像5.png"

//プレイ背景パス
#define PLAY_IMAGE_PATH	"Data/PlayImage/画像6.png"

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

public:
	Map();
	~Map();

	//ファイル読み込みフラグ
	bool isReadFile;

	//ファイルからのマップデータ
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };

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

