#pragma once

#include "ScenePlay.h"
#include "../../Common.h"

//=============================
// �v���C�V�[��
//=============================

//������
void PLAY::Init()
{
	player.Init();				//�v���C���[�̏���������
	player.DefaultValue();		//�v���C���[�̏����l�ݒ�
	m_map.Init();				//�}�b�v������

	//�w�i���W
	m_BG_x[0] = WINDOW_WIDTH/2;
	m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	m_BG_y = WINDOW_HEIGHT/2;

	//�w�i�ړ���
	m_BG_move_x = 0;

	//�R�C��������
	InitCoin();
	

	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//���[�h
void PLAY::Load()
{
	m_ImageHandle[0] = LoadGraph(PLAY_PATH[0]);			//�v���C�w�i
	m_ImageHandle[1] = LoadGraph(PLAY_PATH[1]);			//�v���C�w�i2
	m_ImageHandle[2] = LoadGraph(PLAY_PATH[2]);			//�R�C��
	player.Load();				//�v���C���[�̓ǂݍ���

}

//�ʏ폈��
void PLAY::Step()
{	
	player.Step();				//�v���C���[�̒ʏ폈��

	//�w�i�X�N���[������
	m_BG_x[0] -= PLAYER_SPEED;
	m_BG_x[1] -= PLAYER_SPEED;
	m_BG_move_x -= PLAYER_SPEED;

	if (m_BG_x[0] <= -(WINDOW_WIDTH / 2))
	{
		m_BG_x[0] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	}
	else if (m_BG_x[1] <= -(WINDOW_WIDTH / 2))
	{
		m_BG_x[1] = WINDOW_WIDTH + (WINDOW_WIDTH / 2);
	}

	//�}�b�v�̓����蔻��
	MapCollision(-m_BG_move_x);

	//�R�C�������蔻��
	CoinCollision(-m_BG_move_x);

	//�v���C���[�̍��W���X�V
	player.UpdatePos();

	//���U���g�V�[���ւ̑J��
	//Enter�L�[�����ꂽ�Ȃ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�V�[���t���O�����U���g�V�[���ɕύX
		m_SceneFlag = 0;
		//�v���C�㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}

}

//�`�揈��
void PLAY::Draw()
{
	//�w�i�`��
	DrawRotaGraph(m_BG_x[0], m_BG_y, 1.0f, 0.0f, m_ImageHandle[0], true);
	DrawRotaGraph(m_BG_x[1], m_BG_y, 1.0f, 0.0f, m_ImageHandle[1], true);

	m_map.Draw(-m_BG_move_x);	//�}�b�v�`��

	player.Draw();				//�v���C���[�̕`�揈��

	//�R�C��
	DrawCoin(m_BG_move_x);

	//�f�o�b�O
	SetFontSize(30);
	SetFontSize(16);
}

//�㏈��
void PLAY::Fin()
{
	//SceneFlag��0�̎�
	if (m_SceneFlag == 0)
	{
		//�v���CINIT�ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
	}
}

//�}�b�v�̓����蔻��
void PLAY::MapCollision(int mapmove)
{
	//�v���C���[
	//Y�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			//�u���b�N�ȊO�͏������Ȃ�
			if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//�ǂ̕����ɐi��ł������`�F�b�N
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			//��`�̓����蔻��p�̃f�[�^������
			//�v���C���[�̏��
			int Ax = player.GetPosX() - 20 - mapmove;
			int Ay = player.GetPosY() - 10;
			int Aw = PLAYER_WIDTH * 2;
			int Ah = PLAYER_HEIGHT * 2;

			//�I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
			Ay = player.GetNextPosY();
			Ax = player.GetPosX();

			//�������Ă��邩�`�F�b�N
			if (IsHitRect(Ax + mapmove, Ay, Aw, Ah, Bx + mapmove, By, Bw, Bh)) {

				// ������̏C��
				if (dirArray[0]) {
					// �߂荞�ݗʂ��v�Z����
					int overlap = By + Bh - Ay;
					player.SetNextPosY(Ay + overlap);

					//�V��ɂ����牟���Ԃ�
					player.PlayerCeiling();

				}
				//�������̏C��
				if (dirArray[1]) {
					// �߂荞�ݗʂ��v�Z����
					int overlap = Ay + Ah - By;
					player.SetNextPosY(Ay - overlap);

					//����������
					player.PlayerLanding();

				}
			}
		}
	}

	// X�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAP_DATA_Y; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_DATA_X; mapIndexX++)
		{
			// �u���b�N�ȊO�͏������Ȃ�
			if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == MAPCHIP_NONE)
				continue;

			//�ǂ̕����ɐi��ł������`�F�b�N
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			//�v���C���[�̏��
			int Ax = player.GetPosX() - 20 - mapmove;
			int Ay = player.GetPosY() - 10;
			int Aw = PLAYER_WIDTH * 2;
			int Ah = PLAYER_HEIGHT * 2;

			//�I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAP_SIZE + 20 - mapmove;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE + 10;

			//X�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			// �������Ă��邩�`�F�b�N
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				// �������̏C��
				if (dirArray[2]) {
					// �߂荞�ݗʂ��v�Z����
					int overlap = Bx + Bw - Ax;
					player.SetNextPosX(Ax + overlap);
				}
				// �E�����̏C��
				if (dirArray[3]) {
					// �߂荞�ݗʂ��v�Z����
					int overlap = Ax + Aw - Bx;
					player.SetNextPosX(Ax - overlap);
				}
			}
		}
	}
}

//�R�C�����W������
void PLAY::InitCoin()
{
	for (int coin_num; coin_num < COIN_NUM; coin_num++)
	{
		m_coin_x[coin_num] = COIN_PLACE[coin_num][0];
		m_coin_y[coin_num] = COIN_PLACE[coin_num][1];
		CoinFlag[coin_num] = 1;
	}
}

//�R�C�������蔻��
void PLAY::CoinCollision(int mapmove)
{
	for (int coin_num = 0; coin_num < COIN_NUM; coin_num++)
	{
		//�R�C�����`�悳��Ă�����
		if (CoinFlag[coin_num] == 1)
		{
			////�������Ă��邩�`�F�b�N
			//if (IsHitRect()) 
			//{
			//	//�R�C���`��t���Ooff
			//	CoinFlag[coin_num] = 0;

			//}
		}
	}
}

//�R�C���`��
void PLAY::DrawCoin(int mapmove)
{
	for (int coin_num; coin_num < COIN_NUM; coin_num++)
	{
		if (CoinFlag[coin_num] == 1)
		{
			DrawRotaGraph(m_coin_x[coin_num] + mapmove, m_coin_y[coin_num], 1.0f, 0.0f, m_ImageHandle[2], true);
		}
	}
}
