#pragma once
#include "../Screen/Screen.h"

// �e�}�b�v�̃f�[�^��
const int MAP_DATA_Y = 20;
const int MAP_DATA_X = 200;

// �}�b�v�T�C�Y
const int MAP_SIZE = 56;

// �}�b�v�`�b�v�摜�ꗗ
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

// �}�b�v�N���X
class Map
{
private:

	Screen m_screen;

	// �摜�n���h��
	int imgHundle[MAPCHIP_MAX];

	int move = 0;

	int move_2 = 0;

	int increase = 0;

public:
	Map();
	~Map();

	//�t�@�C���ǂݍ��݃t���O
	bool isReadFile;
	bool isReadFile2;

	//�t�@�C������̃}�b�v�f�[�^
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };
	int m_FileReadMapData2[MAP_DATA_Y][MAP_DATA_X] = { 0 };

	//�t�@�C���P�ǂݍ��ݏI���t���O
	int ReadFileFlag_1 = 0;
	//�t�@�C��2�ǂݍ��ݏI���t���O
	int ReadFileFlag_2 = 0;

	//�}�b�v�`�b�v�`��t���O
	int DrawFlag_1 = 0;
	int DrawFlag_2 = 0;
	
	//������
	void Init();

	//�ʏ폈��
	void Step();
	
	//�R�C���u���b�N����
	void Koin();

	//�`��
	void Draw(int mapmove);

	//�t�@�C������̓ǂݍ���
	void ReadFile();
};

