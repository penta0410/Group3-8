
#include "DxLib.h"
#include "Scene/Scene.h"
#include "../Src/Scene/Title/SceneTitle.h"
#include "../Src/Scene/Play/ScenePlay.h"
#include "../Src/Scene/Clear/SceneClear.h"
#include "../Src/Scene/GameOver/SceneGameOver.h"
#include "Collision/Collision.h"
#include "Input/Input.h"
#include "Common.h"
#include "FPS/fps.h"
#include "Scene/StageSelect/StageSelect.h"
#include "Scene/Option/Option.h"
#include "Scene/Option/GameExplain.h"
#include "Scene/Meinmenu/MeinmenuScene.h"
#include "Scene/Menu/MenuScene.h"
#include "Scene/ItemConpos/ItemConpositeScene.h"
#include "Scene/Shop/ShopScene.h"

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

//�^�C�g���N���X�錾
TITLE title;

//�I�v�V�����N���X�錾
OPTION option;

//�Q�[�������N���X�錾
GAME_EXPLAIN game_explain;

//�X�e�[�W�Z���N�g�N���X�錾
STAGE_SELECT stage_select;

//���C�����j���[�N���X�錾
MEIN_MENU mein_menu;

//�V���b�v�N���X�錾
SHOP shop;

//���j���[�N���X�錾
MENU menu;

//�A�C�e�������N���X�錾
ITEM_CONPOS item_conpos;

//�v���C�V�[���N���X�錾
PLAY play;

//�N���A�N���X�錾
CLEAR clear;

//�Q�[���I�[�o�[�N���X�錾
GAME_OVER game_over;

//�Q�b�g�A�Z�b�g�֐��̃N���X
class  GetSet
{
public:

	//�Q�b�g���\�b�h
	void Get();

	//�Z�b�g���\�b�h
	void Set();

};
int MovieGraphHandle;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(false);

	//�E�B���h�E�T�C�Y��ύX

	if (title.m_start_animetion_flag == 1)
	{
		/*SetGraphMode(WINDOW2_WIDTH, WINDOW2_HEIGHT, 32);*/

		
	}
	else if (title.m_start_animetion_flag == 0)
	{
		SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	}

	//DX���C�u�����̏�����
	if(DxLib_Init() == -1)
	{
		return -1;
	}


	//�`�悷��X�N���[����ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//���͐��䏉����
	InitInput();
	

	//=====================================
	//�Q�[�����C�����[�v
	while(ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e���ɏ�����Ԃ�

		
		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// ���݂̎��Ԃ��A�O��̃t���[�������
		// 1000/60�~���b�i1/60�b�j�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (IsKeyPush(KEY_INPUT_ESCAPE))
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			

			//��ʂɕ\�����ꂽ���̂��������i�P���[�v�̂P�x�����s���j
			ClearDrawScreen();

			//���͐���X�e�b�v
			StepInput();

			//�V�[��ID�ɂ���ď����̐U�蕪��
			switch (g_CurrentSceneID)
			{
			case SCENE_ID_INIT_TITLE:
			{
				//�^�C�g��������
				title.InitTitle();
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				

				//�^�C�g���ʏ폈��
				title.StepTitle();
		
				//�^�C�g���`�揈��
				title.DrawTitle();
			
			}
			break;

			case SCENE_ID_FIN_TITLE:
			{
				//�^�C�g���㏈��
				title.FinTitle();
			}
			break;

			case SCENE_ID_INIT_OPTION:
			{
				//�I�v�V����������
				option.InitOption();

			}
			break;

			case SCENE_ID_LOOP_OPTION:
			{
				//�I�v�V�����ʏ폈��
				option.StepOption();

				//�I�v�V�����`�揈��
				option.DrawOption();
			}
			break;

			case SCENE_ID_FIN_OPTION:
			{
				//�I�v�V�����㏈��
				option.FinOption();
			}
			break;

			case SCENE_ID_INIT_GAME_EXPLAIN:
			{
				//�Q�[������������
				game_explain.InitGameExplain();
			}
			break;

			case SCENE_ID_LOOP_GAME_EXPLAIN:
			{ 
				//�Q�[�������ʏ폈��
				game_explain.StepGameExplain();

				//�Q�[�������`�揈��
				game_explain.DrawGameExplain();
			}
			break;

			case SCENE_ID_FIN_GAME_EXPLAIN:
			{
				//�Q�[�������㏈��
				game_explain.FinGameExplain();
			}
			break;

			case SCENE_ID_INIT_STAGE_SELECT:
			{
				//�X�e�[�W�Z���N�g������
				stage_select.InitStageSelect();

			}
			break;

			case SCENE_ID_LOOP_STAGE_SELECT:
			{
				//�X�e�[�W�Z���N�g�ʏ폈��
				stage_select.StepStageSelect();

				//�X�e�[�W�Z���N�g�`�揈��
				stage_select.DrawStageSelect(play.GetKoin(), play.GetHideKoin(), 
					play.GetPlayerRemain());
			}
			break;

			case SCENE_ID_FIN_STAGE_SELECT:
			{
				//�X�e�[�W�Z���N�g�㏈��
				stage_select.FinStageSelect();
			}
			break;

			//case SCENE_ID_INIT_MEIN_MENU:
			//{
			//	// �Q�[������������
			//	mein_menu.InitMeinMnu();
			//}
			//break;

			//case SCENE_ID_LOOP_MEIN_MENU:
			//{
			//	//���C�����j���[�ʏ폈��
			//	mein_menu.StepMeinMnu();

			//	//���C�����j���[�`�揈��
			//	mein_menu.DrawMeinMnu();
			//}
			//break;

			//case SCENE_ID_FIN_MEIN_MENU:
			//{
			//	//���C�����j���[�㏈��
			//	mein_menu.FinMeinMnu(1);
			//}
			//break;

			case SCENE_ID_INIT_MENU:
			{
				//�X�e�[�W�Z���N�g������
				menu.InitMenu();
			}
			break;


			case SCENE_ID_LOOP_MENU:
			{
				//�X�e�[�W�Z���N�g�ʏ폈��
				menu.StepMenu();

				//�X�e�[�W�Z���N�g�`�揈��
				menu.DrawMenu();
			}
			break;

			case SCENE_ID_FIN_MENU:
			{
				//�X�e�[�W�Z���N�g�㏈��
				menu.FinMenu();
			}
			break;

			case SCENE_ID_INIT_INVENTORY:
			{

			}
			break;

			case SCENE_ID_LOOP_INVENTORY:
			{

			}
			break;

			case SCENE_ID_FIN_INVENTORY:
			{

			}
			break;

			case SCENE_ID_INIT_ITEM_CONPOS:
			{
				//�A�C�e������������
				item_conpos.InitItemConpos();
			}
			break;

			case SCENE_ID_LOOP_ITEM_CONPOS:
			{
				//�A�C�e�������ʏ폈��
				item_conpos.StepItemConpos();

				//�A�C�e�������`�揈��
				item_conpos.DrawItemConpos();
			}
			break;

			case SCENE_ID_FIN_ITEM_CONPOS:
			{
				//�A�C�e�������㏈��
				item_conpos.FinItemConpos();
			}
			break;


			case SCENE_ID_INIT_SHOP:
			{
				//�V���b�v������
				shop.InitShop();
			}
			break;


			case SCENE_ID_LOOP_SHOP:
			{
				//�V���b�v�ʏ폈��
				shop.StepShop();

				//�V���b�v�`�揈��
				shop.DrawShop();
			}
			break;


			case SCENE_ID_FIN_SHOP:
			{
				//�V���b�v�㏈��
				shop.FinShop();
			}
			break;

			case SCENE_ID_INIT_PLAY:
			{
				//�v���C������  
				play.InitPlay();
			}
			break;

			case SCENE_ID_LOOP_PLAY:
			{
				//�v���C�`�揈��
				play.DrawPlay();

				//�v���C�ʏ폈��
				play.StepPlay();

			}
			break;

			case SCENE_ID_FIN_PLAY:
			{
				//�v���C�㏈��
				play.FinPlay();
			}
			break;

			case SCENE_ID_INIT_CLEAR:
			{

				//�N���A������
				clear.InitClear();

			}
			break;

			case SCENE_ID_LOOP_CLEAR:
			{
				//�N���A�ʏ폈��
				clear.StepClear();

				//�N���A�`�揈��
				clear.DrawClear(play.GetKoin(), play.GetHideKoin(), 
					play.GetPlayerRemain(), play.GetScore(), 
					play.GetGoalFlag(), play.GetKoinFlag(), play.GetDefeatFlag() );

			}
			break;

			case SCENE_ID_FIN_CLEAR:
			{
				//�N���A�㏈��
				clear.FinClear();
			}
			break;

			case SCENE_ID_INIT_GAMEOVER:
			{
				//�Q�[���I�[�o�[������
				game_over.InitGameOver();
			}
			break;

			case SCENE_ID_LOOP_GAMEOVER:
			{
				//�Q�[���I�[�o�[�ʏ폈��
				game_over.StepGameOver();

				//�Q�[���I�[�o�[�`�揈��
				game_over.DrawGameOver(play.GetKoin(), play.GetHideKoin(),
					play.GetPlayerRemain(), play.GetScore(),
					play.GetGoalFlag(), play.GetKoinFlag(), play.GetDefeatFlag());

			}
			break;

			case SCENE_ID_FIN_GAMEOVER:
			{

				//�Q�[���I�[�o�[�㏈��
				game_over.FinGameOver();

			}

			}//�V�[���U�蕪����switch���I��

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();

			//�t���b�v�֐��i���[�v�̏I���ɂP�x�����s���j
			ScreenFlip();

		}//�t���[�����[�g��if���I���

	}//���C�����[�v�̏I���

	//�Ō�ɂP�񂾂���鏈���������ɏ���
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

void GetSet::Get()
{

}

void GetSet::Set()
{

}
