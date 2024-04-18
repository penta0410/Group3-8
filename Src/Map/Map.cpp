#include "Map.h"
#include "DxLib.h"
#include <string.h>

const int MAX_DATA_LEN = 256;
Map::Map() {}
Map::~Map() {}

void Map::Init() {
	// 画像の読み込み
	imgHundle[MAPCHIP_BLOCK] = LoadGraph("Data/Play/図1.png");		//土ブロック
	imgHundle[MAPCHIP_KUSA] = LoadGraph("Data/Play/図2.png");		//草ブロック
	imgHundle[MAPCHIP_HATENA] = LoadGraph("Data/Play/図4.png");	//ハテナブロック
	imgHundle[MAPCHIP_HATENA_2] = LoadGraph("Data/Play/図5.png");		//はてなブロック（使用済み)
	imgHundle[MAPCHIP_KAGI] = LoadGraph("Data/Play/図11.png");		//鍵
	imgHundle[MAPCHIP_KAGIBLOCK] = LoadGraph("Data/Play/図10.png");	//鍵ブロック
	imgHundle[MAPCHIP_HAKO] = LoadGraph("Data/Play/図51.png");	//木箱


	ReadFile();
	isReadFile = true;

}

void Map::Draw(int mapmove) {

	for (int y = 0; y < MAP_DATA_Y; y++)
	{
		for (int x = 0; x < MAP_DATA_X; x++)
		{
			// ブロックを描画
			if (isReadFile) {
				int mapchipType = m_FileReadMapData[y][x];
				if (m_FileReadMapData[y][x] != MAPCHIP_NONE) {
					DrawGraph(x * MAP_SIZE - mapmove, y * MAP_SIZE, imgHundle[mapchipType], true);
				}
			}
		}
	}

}

//通常処理
void Map::Step()
{

}

//コインブロック処理
void Map::Koin()
{
	if (m_FileReadMapData[7][4])
	{
		m_FileReadMapData[7][4] = 3;
	}
}

// ファイルからの読み込み
void Map::ReadFile() {
	FILE* fp;
	fopen_s(&fp, "Data/Play/map.csv", "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// 数値部分を読み込む
		fscanf_s(fp, "%d", &m_FileReadMapData[mapIndexY][mapIndexX]);
		mapIndexX++;

		// 「,」を飛ばすために読み込みを実行
		char map = fgetc(fp);

		// EOFの場合は読み込み終了
		if (map == EOF)
		{
			break;
		}

		// 改行コードの場合は保存先を変更する
		if (map == '\n')
		{
			mapIndexY++;
			mapIndexX = 0;
		}
	}

	fclose(fp);
}