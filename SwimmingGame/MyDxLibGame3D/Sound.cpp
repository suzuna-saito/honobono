/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "Sound.h"
#include "SceneBase.h"
#include "Timing.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sound::Sound(SceneBase& _scene)
	:mOnceSoundFlag(false)
{
	// サウンドの読み込み
	// BGM
	mTitleBGM = LoadSoundMem("data/newSound/bgm/title.mp3");
	mGameBGM1 = LoadSoundMem("data/newSound/bgm/bgm_1.mp3");
	mGameBGM2 = LoadSoundMem("data/newSound/bgm/bgm_2.mp3");
	mGameBGM3 = LoadSoundMem("data/newSound/bgm/bgm_3.mp3");
	mResultBGM = LoadSoundMem("data/newSound/bgm/result.mp3");

	// 効果音
	mTitleSound = LoadSoundMem("data/newSound/se/startSE.mp3");
	mPerfectSound = LoadSoundMem("data/newSound/se/perfect.mp3");
	mGoodSound = LoadSoundMem("data/newSound/se/good.mp3");
	mBadSound = LoadSoundMem("data/newSound/se/bad.mp3");
	mWaterInSound = LoadSoundMem("data/newSound/se/in.mp3");
	mWaterOutSound = LoadSoundMem("data/newSound/se/out.mp3");
	mResultSound = LoadSoundMem("data/newSound/se/resultSE.mp3");

	timing = new Timing();
}

/// <summary>
/// デストラクタ
/// </summary>
Sound::~Sound()
{
	// サウンドデータをすべて削除
	InitSoundMem();
	delete timing;
}

/// <summary>
/// 音楽を再生させる
/// </summary>
/// < param name = "_scene"> シーン取得 </param>
void Sound::PlayBGM(SceneBase& _scene)
{
	// タイトルの音楽
	if (_scene.GetScene() == _scene.title)
	{
		PlaySoundMem(mTitleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
	// ゲーム中の音楽
	if (_scene.GetScene() == _scene.play)
	{
		PlaySoundMem(mGameBGM2, DX_PLAYTYPE_BACK, TRUE);
	}
	// リザルトの音楽
	if (_scene.GetScene() == _scene.gameClear)
	{
		PlaySoundMem(mResultBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
}

/// <summary>
/// ゲーム内の効果音再生
/// </summary>
/// < param name = "_scene"> シーン取得 </param>
void Sound::PlaySE(SceneBase& _scene)
{
	// タイトルの効果音
	if (_scene.GetScene() == _scene.title)
	{
		/*
		// ゲームスタートのボタンが押されたら
		//if()
		{
			PlaySoundMem(mTitleSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// それ以外は効果音を止める
		//else
		{
			StopSoundMem(mTitleSound);
		}
		*/
		
	}
	// ゲーム中の効果音
	if (_scene.GetScene() == _scene.play)
	{
		/*
		// 飛び込んで水に入った時
		if()
		{
			PlaySoundMem(mWaterInSound,DX_PLAYTYPE_NORMAL);
		}
		// それ以外は効果音を止める
		else
		{
			StopSoundMem(mWaterInSound);
		}
		// シンクロ中の水しぶきの音
		if()
		{
			PlaySoundMem(mWaterOutSound, DX_PLAYTYPE_NORMAL);
		}
		// それ以外は効果音を止める
		else
		{
			StopSoundMem(mWaterOutSound);
		}
		*/

		// リアクションがパーフェクトだったら
		if (timing->PerfectFlag)
		{
			PlaySoundMem(mPerfectSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// それ以外時は効果音を止める
		else
		{
			StopSoundMem(mPerfectSound);
		}
		// リアクションがグッドだったら
		if (timing->GoodFlag)
		{
			PlaySoundMem(mGoodSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// それ以外は効果音を止める
		else
		{
			StopSoundMem(mGoodSound);
		}
		// リアクションがバッドだったら
		if (timing->BadFlag)
		{
			PlaySoundMem(mBadSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// それ以外時は効果音を止める
		else
		{
			StopSoundMem(mBadSound);
		}
	}
	// リザルトの効果音
	if (_scene.GetScene() == _scene.gameClear)
	{
		/*
			// スコアが出たら
		{
			PlaySoundMem(mResultSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// それ以外は効果音を止める
		else
		{
			StopSoundMem(mResultSound);
		}
		*/
	}
}

/// <summary>
/// 再生している音楽を停止
/// </summary>
/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
void Sound::StopMusic(SceneBase& _scene)
{
	// タイトルのBGMを停止させる
	if (_scene.GetScene() == _scene.play ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(mTitleBGM);
	}
	// ゲームのBGMを停止させる
	if (_scene.GetScene() == _scene.gameClear ||
		_scene.GetScene() == _scene.gameOver)
	{
		StopSoundMem(mGameBGM2);
	}
	// リザルトのBGMを停止させる
	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(mResultBGM);
	}
}
