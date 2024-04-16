#ifndef __PLAYER_H__
#define __PLAYER_H__
//#include "../Scene/Play/ScenePlay.h"

//プレイヤー画像パス
#define PLAYER_STAND_PATH	"Data/PlayImage/playerstand.png"	//プレイヤー待機画像
#define PLAYER_WALK_PATH	"Data/PlayImage/playerwalk.png"		//プレイヤー歩き画像
#define PLAYER_RUN_PATH		"Data/PlayImage/playerrun.png"		//プレイヤー走り画像
#define PLAYER_JUMP_PATH	"Data/PlayImage/playerjump.png"		//プレイヤージャンプ画像
#define PLAYER_MIDAIR_PATH	"Data/PlayImage/playermidair.png"	//プレイヤー空中画像
#define PLAYER_FALL_PATH	"Data/PlayImage/playerfall.png"		//プレイヤー落下画像
#define PLAYER_LANDING_PATH	"Data/PlayImage/playerlanding.png"	//プレイヤー着地画像
#define PLAYER_DAMAGE_PATH	"Data/PlayImage/playerdamage.png"	//プレイヤーダメージ画像
#define PLAYER_ATTACK_PATH	"Data/PlayImage/plaayerattack.png"	//プレイヤアタック画像

//画像総数
#define PLAYER_IMAGE_NUM	(200)

//アニメーション画像総数
const int PLAYER_ANIMATION_NUM = 30;

// 各アニメーションのフレーム数
#define PLAYER_STAND_FRAME_NUM	(12)	//待機
#define PLAYER_WALK_FRAME_NUM	(10)	//歩き
#define PLAYER_RUN_FRAME_NUM	(6)		//走り
#define PLAYER_JUMP_FRAME_NUM	(2)		//ジャンプ
#define PLAYER_MIDAIR_FRAME_NUM	(3)		//空中	
#define PLAYER_FALL_FRAME_NUM	(3)		//落下
#define PLAYER_LANDING_FRAME_NUM	(3)		//着地
#define PLAYER_DAMAGE_FRAME_NUM		(4)		//ダメージ
#define PLAYER_ATTACK_FRAME_NUM		(3)		//アタック

// 各アニメーションの更新時間
#define PLAYER_STAND_FRAME_TIME	(5)	//待機
#define PLAYER_WALK_FRAME_TIME	(5)	//歩き
#define PLAYER_RUN_FRAME_TIME	(3)		//走り
#define PLAYER_JUMP_FRAME_TIME	(1)		//ジャンプ
#define PLAYER_MIDAIR_FRAME_TIME	(2)		//空中	
#define PLAYER_FALL_FRAME_TIME	(2)		//落下
#define PLAYER_LANDING_FRAME_TIME	(5)		//着地
#define PLAYER_DAMAGE_FRAME_TIME		(3)		//ダメージ
#define PLAYER_ATTACK_FRAME_TIME		(2)		//アタック

// 落下開始アニメーションに切り替える値
#define ANIM_CHANGE_MIDAIR_VAL -0.8f

// 落下アニメーションに切り替える値
#define ANIM_CHANGE_FALL_VAL 0.8f


//プレイヤーサイズ
#define PLAYER_W	(80)
#define PLAYER_H	(96)

// 重力
#define GRAVITY 1.225f

// 移動量
#define MOVE_X 4.0f

// ジャンプ力
#define JUMP_POWER 25.0f

// 落下速度上限
#define FALL_MAX 10.0f

//プレイヤーアニメーション種類
enum PlayerAnimationType {

	PLAYER_ANIMATION_TYPE_STAND = 0,
	PLAYER_ANIMATION_TYPE_WALK,
	PLAYER_ANIMATION_TYPE_RUN,
	PLAYER_ANIMATION_TYPE_JUMP,
	PLAYER_ANIMATION_TYPE_MIDAIR,
	PLAYER_ANIMATION_TYPE_FALL,
	PLAYER_ANIMATION_TYPE_LANDING,
	PLAYER_ANIMATION_TYPE_DAMAGE,
	PLAYER_ANIMATION_TYPE_ATTACK,

	PLAYER_ANIMATION_TYPE_MAX,
};

//プレイヤーのアニメーションの状態
enum PlayerState {
	PLAYER_STATE_STAND = 0,
	PLAYER_STATE_WALK,
	PLAYER_STATE_RUN,
	PLAYER_STATE_JUMP,
	PLAYER_STATE_MIDAIR,
	PLAYER_STATE_FALL,
	PLAYER_STATE_LANDING,
	PLAYER_STATE_DAMAGE,
	PLAYER_STATE_ATTACK,

};



//アニメーションフレーム数
const int ANIMATION_FRAME_NUM[PLAYER_ANIMATION_TYPE_MAX] =
{
	PLAYER_STAND_FRAME_NUM,
	PLAYER_WALK_FRAME_NUM,
	PLAYER_RUN_FRAME_NUM,
	PLAYER_JUMP_FRAME_NUM,
	PLAYER_MIDAIR_FRAME_NUM,
	PLAYER_FALL_FRAME_NUM,
	PLAYER_LANDING_FRAME_NUM,
	PLAYER_DAMAGE_FRAME_NUM,
	PLAYER_ATTACK_FRAME_NUM,

};

//アニメーション更新時間
const int ANIMATION_FRAME_TIME[PLAYER_ANIMATION_TYPE_MAX] =
{
	PLAYER_STAND_FRAME_TIME,
	PLAYER_WALK_FRAME_TIME,
	PLAYER_RUN_FRAME_TIME,
	PLAYER_JUMP_FRAME_TIME,
	PLAYER_MIDAIR_FRAME_TIME,
	PLAYER_FALL_FRAME_TIME,
	PLAYER_LANDING_FRAME_TIME,
	PLAYER_DAMAGE_FRAME_TIME,
	PLAYER_ATTACK_FRAME_TIME,

};

//各アニメーションの画像分割数
const int AnimationImgSplitNum[PLAYER_ANIMATION_TYPE_MAX][2] =
{
	{10, 2,},	//プレイヤー待機アニメーション
	{10, 1,},	//プレイヤー歩くアニメーション
	{6, 1,},	//プレイヤー走るアニメーション
	{2, 1,},	//プレイヤージャンプアニメーション
	{3, 1,},	//プレイヤー空中アニメーション
	{3, 1,},	//プレイヤー落下アニメーション
	{3, 1,},	//プレイヤー着地アニメーション
	{4, 1,},	//プレイヤーダメージアニメーション
	{5, 1,},	//プレイヤーアタックアニメーション

};

//各アニメーションの画像サイズ
const int AnimationImgSize[1][2] =
{
	{80,96},	//プレイヤー画像サイズ


};

class Player
{
private:

	/*PLAY play;*/
	//プレイヤー画像ハンドル
	int animation_handle[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//アニメーション画像フラグ
	int animation_flag[PLAYER_ANIMATION_TYPE_MAX]
		[PLAYER_ANIMATION_NUM] = { 0 };

	//アニメーションフレーム
	int animation_flame = 0;

	//プレイヤーの座標
	float m_posX = 0.0f;
	float m_posY = 0.0f;

	//移動後の座標
	float m_nextPosX = 0.0f;
	float m_nextPosY = 0.0f;

	//移動前の座標
	float old_pos_x = 0.0f;
	float old_pos_y = 0.0f;

	//プレイヤー移動量
	float m_move_x = 0;
	float m_move_y = 0;

	//プレイヤー画像反転フラグ
	int m_PlayerVisualDirection = 0;

	//プレイヤーアニメーション種類
	PlayerAnimationType now_animation;

	//プレイヤーアニメ－ション状態
	PlayerState state;
	
	//アニメーション変更フラグ
	int m_player_animationflag = 0;

	//変更する前の状態
	int m_animation_before = 0;

	//重力フラグ
	bool isGravity = false;

	//プレイヤーのHP
	int m_HP = 0;

	//プレイヤー移動フラグ
	int m_PlayerMoveFlag = 0;

	//描画フラグ
	int m_drawflag = 0;

	//攻撃フレーム
	int m_attack = 0;

	//攻撃フラグ
	int m_attackFlag = 0;

	//攻撃アニメーションフレーム
	int m_attack_frame = 0;

	//マウス座標
	int m_Mouse_x = 0;	//ｘ座標
	int m_Mouse_y = 0;	//y座標


public:
	Player();
	~Player();

	//プレイヤー初期化
	void Init();

	//プレイヤー読み込み
	void LoadPlayer();

	//プレイヤー更新
	void StepPlayer();

	//プレイヤー通常処理
	void Control();

	//プレイヤー攻撃処理
	int PlayerAttack(int mapmove, int m_x, int m_y);

	//プレイヤー描画処理
	void Draw(int mapmove);

	//プレイヤー終了処理
	void FinPlayer();

	//プレイヤー落下前チェック
	void StepPlayerMidAir();

	//プレイヤー落下更新
	void StepPlayerFall();


	//プレイヤー着地処理
	void PlayerLanding();

	//プレイヤー天井処理
	void PlayerCeiling();

	//プレイヤーがジャンプ可能かどうか
	bool CanJumpPlayer();

	//プレイヤーが空中状態かどうか
	bool IsAirPlayer();

	//移動後の座標を取得
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	//現在の座標を取得
	int GetPosX() { return m_posX; }
	int GetPosY() { return m_posY; }

	//座標を更新
	void UpdatePos();

	//移動後の座標を設定
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posY);

	//進んでいる方向をチェック
	//上下左右
	void GetMoveDirection(bool* _dirArray);

	//プレイヤーHP取得
	int GetHP() { return m_HP; }

	//プレイヤーのHPを設定
	void SetHP(int hp);
	
	//プレイヤー移動フラグの状態を取得
	int  GetPlayerMoveFlag() { return m_PlayerMoveFlag; }

	//プレイヤー移動フラグの状態を設定
	void SetPlayerMoveFlag(int flag);

};




#endif
