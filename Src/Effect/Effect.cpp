
#include <DxLib.h>
#include "Effect.h"
#include "../Common.h"



//エフェクトの読み込み
//引数	：ファイルパス, エフェクト種類, アニメ総数, 横画像数, 縦画像数, 分割後の横サイズ, 分割後の縦サイズ
void EffectInfo::LoadEffect(EFFECT_TYPE type, int create_num)
{
	for (int create_index = 0; create_index < create_num; create_index++)
	{
		for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
		{
			//読み込みしていないエフェクト情報を見つける
			//（ひとつ目の画像ハンドルがゼロなら読み込みされてない）
			if (effectInfo[effect_index].handle[0] == 0)
			{
				//画像を分割読み込み
				int success_flg = LoadDivGraph(effectFilePath[type],
					effectAnimeImgNum[type],
					effectImageSplitNum[type][0],
					effectImageSplitNum[type][1],
					effectImageSize[type][0],
					effectImageSize[type][1],
					effectInfo[effect_index].handle);

				//成功した
				if (success_flg == 0)
				{
					//アニメ数を格納
					effectInfo[effect_index].animeNum = effectAnimeImgNum[type];

					//１枚当たりの表示時間を設定
					effectInfo[effect_index].changeTime = effectChageTime[type];

					//エフェクトの種類を設定
					effectInfo[effect_index].effectType = type;
				}

				//成否にかかわらず抜ける
				break;
			}
		}
	}
}

//エフェクトの初期化
void EffectInfo::InitEffect()
{
	//すべてのエフェクト情報の変数をクリアする（ゼロにする）
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		for(int anime_index = 0; anime_index < EFFECT_ANIME_MAX_NUM; anime_index++)
			effectInfo[effect_index].handle[anime_index] = 0;

		effectInfo[effect_index].x = effectInfo[effect_index].y = 0;
		effectInfo[effect_index].isUse = false;
		effectInfo[effect_index].animeNum = 0;
		effectInfo[effect_index].currentAnimeIndex = 0;
		effectInfo[effect_index].changeTime = 0.0f;
		effectInfo[effect_index].currentChangeTime = 0.0f;
	}
}

//エフェクト通常処理
void EffectInfo::StepEffect()
{
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中ならアニメ時間を経過させて、アニメ番号を更新する
		if(effectInfo[effect_index].isUse == true)
		{
			//画像切り替わるに必要な時間経過したら
			if(effectInfo[effect_index].currentChangeTime >= effectInfo[effect_index].changeTime)
			{
				effectInfo[effect_index].currentAnimeIndex++;		//次の画像へ
				effectInfo[effect_index].currentChangeTime = 0.0f;	//計測時間リセット

				//次の画像がもし無いなら
				if(effectInfo[effect_index].currentAnimeIndex >= effectInfo[effect_index].animeNum)
				{
					//使用中フラグをOFFに
					effectInfo[effect_index].isUse = false;

					//以下の処理は不要
					continue;
				}
			}

			//時間更新
			effectInfo[effect_index].currentChangeTime += 1.0f / FRAME_RATE;
		}
	}
}

//エフェクト描画処理
void EffectInfo::DrawEffect()
{
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中なら現在のアニメ番号で描画する
		if(effectInfo[effect_index].isUse == true)
		{
			DrawRotaGraph(effectInfo[effect_index].x, 
						  effectInfo[effect_index].y,
						  1.0,
						  0.0, 
						  effectInfo[effect_index].handle[effectInfo[effect_index].currentAnimeIndex],
						  true
						  );
		}
	}
}

//エフェクト描画（反転）処理
void EffectInfo::DrawTurnEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中なら現在のアニメ番号で描画する
		if (effectInfo[effect_index].isUse == true)
		{
			DrawTurnGraph(effectInfo[effect_index].x,
				effectInfo[effect_index].y,
				effectInfo[effect_index].handle[effectInfo[effect_index].currentAnimeIndex],
				true
			);
		}
	}
}
//エフェクトの後処理
void EffectInfo::FinEffect()
{
	//すべてのエフェクトを削除する
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//すべて削除する
		for(int anime_index = 0; anime_index < EFFECT_ANIME_MAX_NUM; anime_index++)
		{
			//ゼロ以外なら削除する
			if(effectInfo[effect_index].handle[anime_index] != 0)
			{
				//画像削除
				DeleteGraph(effectInfo[effect_index].handle[anime_index]);

				//削除したらゼロを入れておく
				effectInfo[effect_index].handle[anime_index] = 0;
			}
		}
	}
}

//エフェクトの再生
//引数	：エフェクトの種類, Ｘ座標, Ｙ座標, １枚あたりの表示時間
void EffectInfo::PlayEffect(EFFECT_TYPE type, float x, float y)
{
	//未使用エフェクトを探して再生
	for(int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//使用中なら以下行わない
		if(effectInfo[effect_index].isUse == true)
			continue;

		//タイプが一致した
		if(effectInfo[effect_index].effectType == type)
		{
			effectInfo[effect_index].x = x;	//座標設定
			effectInfo[effect_index].y = y;

			//計測用の変数をクリア
			effectInfo[effect_index].currentAnimeIndex = 0;
			effectInfo[effect_index].currentChangeTime = 0.0f;

			effectInfo[effect_index].isUse = true;	//使用中にする

			break;	//抜ける
		}
	}
}

