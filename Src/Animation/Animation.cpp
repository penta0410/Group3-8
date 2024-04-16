//#include "DxLib.h"
//#include "Animation.h"
//#include <string.h>
//#include "../Scene/Scene.h"
//#include "../Common.h"
////#include "../Player/Player.h"
//
////アニメーション初期化
//void Animation::InitAnimation(ANIMATION_TYPE type)
//{
//	
//	//すべてのアニメーションの情報の変数をクリア
//	for (int animation_index = 0; animation_index < ANIMATION_MAX_NUM;
//		animation_index++)
//	{
//		for (int anime_index = 0; anime_index < ANIMATION_NUM_MAX;
//			anime_index++)
//		{
//			//プレイヤー画像ハンドル
//			Animation_Handle[type][anime_index] = 0;
//		}
//
//		//x座標
//		m_x[animation_index] = 0;
//
//		//y座標
//		m_y[animation_index] = 0;
//
//		//使用フラグ
//		m_isUse[animation_index] = false;
//
//		//アニメ数
//		m_animeNum[animation_index] = 0;
//
//		//現在のアニメ番号
//		m_currentAnimeIndex[animation_index] = 0;
//
//		//一枚当たりの表時時間
//		m_changetime[animation_index] = 0.0f;
//
//		//現在のアニメ時間
//		m_currentChangetime[animation_index] = 0.0f;
//
//
//
//	}
//
//}
//
////アニメーション読み込み
//void Animation::LoadAnimation(ANIMATION_TYPE type, int anime_num)
//{
//	for (int create_index = 0; create_index < anime_num; create_index++)
//	{
//		for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//		{
//			//読み込まれていないアニメーション情報を見つける
//			if (Animation_Handle[anime_index][0] == 0)
//			{
//				//画像を分割読み込み
//				int success_flag = LoadDivGraph(AnimationFilePath[type],
//					AnimationImgNum[type],
//					AnimationImgSplitNum[type][0],
//					AnimationImgSplitNum[type][1],
//					AnimationImgSize[type][0],
//					AnimationImgSize[type][1],
//					Animation_Handle[type]);
//
//				//成功
//				if (success_flag == 0)
//				{
//					//アニメ数を格納
//					m_animeNum[anime_index] = AnimationImgNum[type];
//
//					//一枚当たりの表示時間を設定
//					m_changetime[anime_index] = AnimationChangeTime[type];
//
//					//アニメショーンの種類を設定
//					AnimationType[anime_index] = type;
//
//				}
//
//				//成否にかかわらず抜ける
//				break;
//
//			}
//		}
//	}
//
//}
//
////アニメーション通常処理
//void Animation::StepAnimation()
//{
//	for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//	{
//		//使用中ならアニメ機関を経過させて、アニメ番号を更新する
//		if (m_isUse[anime_index] == true)
//		{
//			//画像切り替えに必要な時間経過したら
//			if (m_currentChangetime[anime_index] >= m_changetime[anime_index])
//			{
//				m_currentAnimeIndex[anime_index]++;		//次の画像へ
//				m_currentChangetime[anime_index] = 0.0f;	//計測時間リセット
//			
//				//次の画像がないなら
//				if (m_currentAnimeIndex[anime_index] >= m_animeNum[anime_index])
//				{
//					//使用中フラグをoffに
//					m_isUse[anime_index] = false;
//
//
//					continue;
//				}
//			}
//
//			//時間更新
//			m_currentChangetime[anime_index] += 1.0f / FRAME_RATE;
//		}
//	}
//}
//
////アニメーション描画処理
//void Animation::DrawAnimation(ANIMATION_TYPE type)
//{
//
//	for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//	{
//		//使用中なら現在のアニメ番号で描画する
//		if (m_isUse[anime_index] == true)
//		{
//			DrawGraph(m_x[anime_index], m_y[anime_index],
//				Animation_Handle[type][m_currentAnimeIndex[anime_index]], true);
//		}
//	}
//}
//
////アニメーション描画（反転）処理
//void Animation::DrawTurnAnimation(ANIMATION_TYPE type)
//{
//	for (int anime_index = 0; anime_index < ANIMATION_MAX_NUM; anime_index++)
//	{
//		//使用中なら現在のアニメ番号で描画する
//		if (m_isUse[anime_index] == true)
//		{
//			DrawTurnGraph(m_x[anime_index], m_y[anime_index],
//				Animation_Handle[type][m_currentAnimeIndex[anime_index]], true);
//		}
//	}
//}
//
////アニメーションの後処理
//void Animation::FinAnimetion()
//{
//	//すべてのアニメーションを削除する
//	for (int animetion_index = 0; animetion_index < ANIMATION_MAX_NUM; animetion_index++)
//	{
//		//すべて削除する
//		for (int anime_index = 0; anime_index < ANIMATION_NUM_MAX; anime_index++)
//		{
//			//ゼロ以外なら削除する
//			if (Animation_Handle[animetion_index][anime_index] != 0)
//			{
//				//画像削除
//				DeleteGraph(Animation_Handle[animetion_index][anime_index]);
//			
//				//削除したらゼロを入れておく
//				Animation_Handle[animetion_index][anime_index] = 0;
//
//			}
//		}
//	}
//}
//
////アニメーションの再生
//void Animation::PlayAnimation(ANIMATION_TYPE type, float x, float y)
//{
//
//	//未使用アニメーションを探して再生
//	for (int animation_index = 0; animation_index < ANIMATION_MAX_NUM; animation_index++)
//	{
//		//使用中なら以下行わない
//		if (m_isUse[animation_index] == true)
//		{
//			continue;
//		}
//
//		//タイプが一致した
//		if (AnimationType[animation_index] == type)
//		{
//			//描画する座標を設定
//			m_x[animation_index] = x;
//			m_y[animation_index] = y;
//
//			//計測用の変数をクリア
//			m_currentAnimeIndex[animation_index] = 0;
//			m_currentChangetime[animation_index] = 0.0f;
//
//			//使用中にする
//			m_isUse[animation_index] = true;
//
//			break;
//		}
//	}
//
//}