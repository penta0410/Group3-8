#pragma once
#include "../Screen/Screen.h"

//�}�b�v�p�X
#define MAP_IMAGE_PATH	"Data/PlayImage/�摜5.png"

//�v���C�w�i�p�X
#define PLAY_IMAGE_PATH	"Data/PlayImage/�摜6.png"

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

public:
	Map();
	~Map();

	//�t�@�C���ǂݍ��݃t���O
	bool isReadFile;

	//�t�@�C������̃}�b�v�f�[�^
	int m_FileReadMapData[MAP_DATA_Y][MAP_DATA_X] = { 0 };

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

