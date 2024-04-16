//#pragma once
//
////アニメーション最大同時再生数
//#define ANIMATION_MAX_NUM (20)
//
////一つのアニメーションの最大数
//#define ANIMATION_NUM_MAX	(20)
//
////プレイヤーアニメーション種類
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
////プレイヤーのアニメーションの状態
//enum PlayerState {
//	PLAYER_STATE_STAND,
//	PLAYER_STATE_WALK,
//	PLAYER_STATE_RUN,
//	PLAYER_STATE_JUMP,
//	PLAYER_STATE_MIDAIR,
//	PLAYER_STATE_FALL,
//};
//
////アニメーションファイルパス
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
////アニメーションフレーム数
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
////アニメーション更新時間
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
////ループフラグ
//const bool ANIMATION_LOOP_FLG[PLAYER_ANIMATION_TYPE_MAX] =
//{
//	true, true, true, true, false, true, false, false
//};
//
//
//
//
//
////アニメーションクラス
//class Animation 
//{
//
//private:
//
//	//プレイヤーアニメーション種類
//	PlayerAnimationType now_animation;
//
//	//プレイヤーアニメ－ション状態
//	PlayerState state;
//
//	//アニメーション画像ハンドル
//	int Animation_Handle[PLAYER_ANIMATION_TYPE_MAX][ANIMATION_NUM_MAX] = { 0, 0 };
//
//	//画像使用フラグ
//	bool m_isUse[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//アニメ数
//	int m_animeNum[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//現在のアニメ番号
//	int m_currentAnimeIndex[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//一枚当たりの表示時間
//	float m_changetime[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//	//現在のアニメ時間
//	float m_currentChangetime[PLAYER_ANIMATION_TYPE_MAX] = { 0 };
//
//
//public:
//
//	//アニメーション初期化
//	void InitAnimation(ANIMATION_TYPE type);
//
//	//アニメーション読み込み
//	void LoadAnimation(ANIMATION_TYPE type, int anime_num);
//
//	//アニメーション通常処理
//	void StepAnimation();
//
//	//アニメーション描画処理
//	void DrawAnimation(ANIMATION_TYPE type);
//
//	//アニメーション描画（反転）処理
//	void DrawTurnAnimation(ANIMATION_TYPE type);
//
//	//アニメーション終了処理
//	void FinAnimetion();
//
//	//アニメーションの再生
//	void PlayAnimation(ANIMATION_TYPE type, float x, float y);
//
//};