//#pragma once
//
////�A�j���[�V�����ő哯���Đ���
//#define ANIMATION_MAX_NUM (20)
//
////��̃A�j���[�V�����̍ő吔
//#define ANIMATION_NUM_MAX	(20)
//
////�v���C���[�A�j���[�V�������
//enum PlayerAnimationType {
//	PLAYER_ANIMATION_TYPE_STAND,
//	PLAYER_ANIMATION_TYPE_WALK,
//	PLAYER_ANIMATION_TYPE_RUN,
//	PLAYER_ANIMATION_TYPE_JUMP,
//	PLAYER_ANIMATION_TYPE_MIDAIR,
//	PLAYER_ANIMATION_TYPE_FALL,
//	PLAYER_ANIMATION_TYPE_LANDING,
//	PLAYER_ANIMATION_TYPE_DAMAGE,
//
//	PLAYER_ANIMATION_TYPE_MAX,
//};
//
////�v���C���[�̃A�j���[�V�����̏��
//enum PlayerState {
//	PLAYER_STATE_STAND,
//	PLAYER_STATE_WALK,
//	PLAYER_STATE_RUN,
//	PLAYER_STATE_JUMP,
//	PLAYER_STATE_MIDAIR,
//	PLAYER_STATE_FALL,
//};
//
////�A�j���[�V�����t�@�C���p�X
//const char* ANIMATION_PATH[PLAYER_ANIMATION_TYPE_MAX] =
//{
//	PLAYER_STAND_PATH,
//	PLAYER_WALK_PATH,
//	PLAYER_RUN_PATH,
//	PLAYER_JUMP_PATH,
//	PLAYER_MIDAIR_PATH,
//	PLAYER_FALL_PATH,
//	PLAYER_LANDING_PATH,
//	PLAYER_DAMAGE_PATH,
//};
//
////�A�j���[�V�����t���[����
//const int ANIMATION_FRAME_NUM[PLAYER_ANIMATION_TYPE_MAX] =
//{
//	PLAYER_STAND_FRAME_NUM,
//	PLAYER_WALK_FRAME_NUM,
//	PLAYER_RUN_FRAME_NUM,
//	PLAYER_JUMP_FRAME_NUM,
//	PLAYER_MIDAIR_FRAME_NUM,
//	PLAYER_FALL_FRAME_NUM,
//	PLAYER_LANDING_FRAME_NUM,
//	PLAYER_DAMAGE_FRAME_NUM,
//
//};
//
////�A�j���[�V�����X�V����
//const int ANIMATION_FRAME_TIME[PLAYER_ANIMATION_TYPE_MAX] =
//{
//	PLAYER_STAND_FRAME_TIME,
//	PLAYER_WALK_FRAME_TIME,
//	PLAYER_RUN_FRAME_TIME,
//	PLAYER_JUMP_FRAME_TIME,
//	PLAYER_MIDAIR_FRAME_TIME,
//	PLAYER_FALL_FRAME_TIME,
//	PLAYER_LANDING_FRAME_TIME,
//	PLAYER_DAMAGE_FRAME_TIME,
//
//};
//
////���[�v�t���O
//const bool ANIMATION_LOOP_FLG[PLAYER_ANIMATION_TYPE_MAX] =
//{
//	true, true, true, true, false, true, false, false
//};
//
//
//
//
//
////�A�j���[�V�����N���X
//class Animation 
//{
//
//private:
//
//	//�v���C���[�A�j���[�V�������
//	PlayerAnimationType now_animation;
//
//	//�v���C���[�A�j���|�V�������
//	PlayerState state;
//
//	//�A�j���[�V�����摜�n���h��
//	int Animation_Handle[PLAYER_ANIMATION_TYPE_MAX][ANIMATION_NUM_MAX] = { 0, 0 };
//
//	//�摜�g�p�t���O
//	bool m_isUse[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//�A�j����
//	int m_animeNum[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//���݂̃A�j���ԍ�
//	int m_currentAnimeIndex[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//�ꖇ������̕\������
//	float m_changetime[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//���݂̃A�j������
//	float m_currentChangetime[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//
//public:
//
//	//�A�j���[�V����������
//	void InitAnimation(ANIMATION_TYPE type);
//
//	//�A�j���[�V�����ǂݍ���
//	void LoadAnimation(ANIMATION_TYPE type, int anime_num);
//
//	//�A�j���[�V�����ʏ폈��
//	void StepAnimation();
//
//	//�A�j���[�V�����`�揈��
//	void DrawAnimation(ANIMATION_TYPE type);
//
//	//�A�j���[�V�����`��i���]�j����
//	void DrawTurnAnimation(ANIMATION_TYPE type);
//
//	//�A�j���[�V�����I������
//	void FinAnimetion();
//
//	//�A�j���[�V�����̍Đ�
//	void PlayAnimation(ANIMATION_TYPE type, float x, float y);
//
//};