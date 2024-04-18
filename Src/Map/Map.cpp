#include "Map.h"
#include "DxLib.h"
#include <string.h>

const int MAX_DATA_LEN = 256;
Map::Map() {}
Map::~Map() {}

void Map::Init() {
	// �摜�̓ǂݍ���
	imgHundle[MAPCHIP_BLOCK] = LoadGraph("Data/Play/�}1.png");		//�y�u���b�N
	imgHundle[MAPCHIP_KUSA] = LoadGraph("Data/Play/�}2.png");		//���u���b�N
	imgHundle[MAPCHIP_HATENA] = LoadGraph("Data/Play/�}4.png");	//�n�e�i�u���b�N
	imgHundle[MAPCHIP_HATENA_2] = LoadGraph("Data/Play/�}5.png");		//�͂Ăȃu���b�N�i�g�p�ς�)
	imgHundle[MAPCHIP_KAGI] = LoadGraph("Data/Play/�}11.png");		//��
	imgHundle[MAPCHIP_KAGIBLOCK] = LoadGraph("Data/Play/�}10.png");	//���u���b�N
	imgHundle[MAPCHIP_HAKO] = LoadGraph("Data/Play/�}51.png");	//�ؔ�


	ReadFile();
	isReadFile = true;

}

void Map::Draw(int mapmove) {

	for (int y = 0; y < MAP_DATA_Y; y++)
	{
		for (int x = 0; x < MAP_DATA_X; x++)
		{
			// �u���b�N��`��
			if (isReadFile) {
				int mapchipType = m_FileReadMapData[y][x];
				if (m_FileReadMapData[y][x] != MAPCHIP_NONE) {
					DrawGraph(x * MAP_SIZE - mapmove, y * MAP_SIZE, imgHundle[mapchipType], true);
				}
			}
		}
	}

}

//�ʏ폈��
void Map::Step()
{

}

//�R�C���u���b�N����
void Map::Koin()
{
	if (m_FileReadMapData[7][4])
	{
		m_FileReadMapData[7][4] = 3;
	}
}

// �t�@�C������̓ǂݍ���
void Map::ReadFile() {
	FILE* fp;
	fopen_s(&fp, "Data/Play/map.csv", "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// ���l������ǂݍ���
		fscanf_s(fp, "%d", &m_FileReadMapData[mapIndexY][mapIndexX]);
		mapIndexX++;

		// �u,�v���΂����߂ɓǂݍ��݂����s
		char map = fgetc(fp);

		// EOF�̏ꍇ�͓ǂݍ��ݏI��
		if (map == EOF)
		{
			break;
		}

		// ���s�R�[�h�̏ꍇ�͕ۑ����ύX����
		if (map == '\n')
		{
			mapIndexY++;
			mapIndexX = 0;
		}
	}

	fclose(fp);
}