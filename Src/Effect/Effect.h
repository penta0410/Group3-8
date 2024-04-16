
#ifndef __EFFECT_H__
#define __EFFECT_H__

//エフェクトの種類
enum EFFECT_TYPE
{
	EFFECT_TYPE_EXPLOSION = 0,	//爆発
	EFFECT_TYPE_RECOVERY,		//回復
	PLAYER_STAND,				//プレイヤー待機アニメーション

	EFFECT_TYPE_NUM,
};

//一度に表示できるエフェクト最大数
#define EFFECT_MAX_NUM		(20)

//エフェクトのアニメ最大数
#define EFFECT_ANIME_MAX_NUM	(4)	

//エフェクト情報
struct EffectInfo
{
	EFFECT_TYPE	effectType;	//エフェクトの種類

	int	handle[EFFECT_ANIME_MAX_NUM];	//画像ハンドル

	int x, y;		//座標
	bool isUse;		//使用フラグ

	int animeNum;			//アニメ数
	int currentAnimeIndex;	//現在のアニメ番号

	float changeTime;		//１枚あたりの表示時間
	float currentChangeTime;	//現在のアニメ時間

	
	//エフェクトの読み込み
	//引数	：ファイルパス, エフェクト種類, アニメ総数, 横画像数, 縦画像数, 分割後の横サイズ, 分割後の縦サイズ
	void LoadEffect(EFFECT_TYPE type, int create_num);

	//エフェクトの初期化
	void InitEffect();

	//エフェクト通常処理
	void StepEffect();

	//エフェクト描画処理
	void DrawEffect();

	//エフェクト描画（反転）処理
	void DrawTurnEffect();

	//エフェクトの後処理
	void FinEffect();

	//エフェクトの再生
	//引数	：エフェクトの種類, Ｘ座標, Ｙ座標, １枚あたりの表示時間
	void PlayEffect(EFFECT_TYPE type, float x, float y);

};

//エフェクト情報
static EffectInfo effectInfo[EFFECT_MAX_NUM];

//エフェクトのファイルパス
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/EffectExplosion.png",
	"Data/Effect/EffectRecovery.png",
	"Data/PlayImage/tewi_material01.png",

};

//各エフェクトのアニメ数
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
	3,	//EFFECT_TYPE_RECOVERY

	12,	//プレイヤー待機アニメーション

};

//各エフェクトの画像分割数 [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
	{ 2, 2,},	//EFFECT_TYPE_RECOVERY

	{ 10, 5,},	//プレイヤー待機アニメーション

};

//エフェクトの画像サイズ
const int effectImageSize[EFFECT_TYPE_NUM][2] =
{
	{64, 64,},	//EFFECT_TYPE_EXPLOSION
	{32, 32,},	//EFFECT_TYPE_RECOVERY

	{80, 96,},	//プレイヤー待機アニメーション
};

//各エフェクトのアニメ画像切り替え時間
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
	0.1f,	//EFFECT_TYPE_RECOVERY

	0.1f,	//プレイヤー待機アニメーション

};



class Effect
{


public:

	
	
};

#endif
