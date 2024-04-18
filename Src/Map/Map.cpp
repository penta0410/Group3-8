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
	isReadFile2 = true;

	//�t�@�C���P�ǂݍ��ݏI���t���O
	ReadFileFlag_1 = 0;
	//�t�@�C��2�ǂݍ��ݏI���t���O
	ReadFileFlag_2 = 1;

	//�}�b�v�`�b�v�`��t���O
	DrawFlag_1 = 0;
	DrawFlag_2 = 1;

	increase = 1;
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
					move = x * MAP_SIZE - mapmove;
					DrawGraph(move, y * MAP_SIZE, imgHundle[mapchipType], true);

					if (move <= -11100)
					{
						move = x * MAP_SIZE - mapmove + 11200 * increase;
						increase += 1;
					}
					
				}
			}
		}
	}

	for (int y = 0; y < MAP_DATA_Y; y++)
	{
		for (int x = 0; x < MAP_DATA_X; x++)
		{
			if (isReadFile2)
			{
				int mapchipType = m_FileReadMapData[y][x];
				if (m_FileReadMapData2[y][x] != MAPCHIP_NONE) {
					move_2 = x * MAP_SIZE - mapmove + 11200;
					DrawGraph(move_2, y * MAP_SIZE, imgHundle[mapchipType], true);

					if (move_2 <= -11100)
					{
						move_2 = x * MAP_SIZE - mapmove + 11200 * increase;
						increase += 1;
					}

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

	FILE* fp_2;
	fopen_s(&fp_2, "Data/Play/map2.csv", "r");

	int mapIndexX_2 = 0;
	int mapIndexY_2 = 0;

	while (true) {
		// ���l������ǂݍ���
		fscanf_s(fp_2, "%d", &m_FileReadMapData2[mapIndexY_2][mapIndexX_2]);
		mapIndexX_2++;

		// �u,�v���΂����߂ɓǂݍ��݂����s
		char map = fgetc(fp_2);

		// EOF�̏ꍇ�͓ǂݍ��ݏI��
		if (map == EOF)
		{
			break;
		}

		// ���s�R�[�h�̏ꍇ�͕ۑ����ύX����
		if (map == '\n')
		{
			mapIndexY_2++;
			mapIndexX_2 = 0;
		}
	}

	fclose(fp_2);

}

