/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "Sound.h"

// 定数
const int VOLUME = 100;


/// <summary>
/// コンストラクタ
/// </summary>
Sound::Sound(const char* _filePath)
	:mOnceSoundFlag(false)
{
	// サウンドの読み込み
	mSoundHandle = LoadSoundMem(_filePath);
}

/// <summary>
/// デストラクタ
/// </summary>
Sound::~Sound()
{
	DeleteSoundMem(mSoundHandle);
}

/// <summary>
/// 音楽を再生させる
/// </summary>
void Sound::PlayBGM()
{
	//再生されていなかったら再生する
	if (!CheckSoundMem(mSoundHandle))
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_LOOP, TRUE);
	}

	// 音量調整
	ChangeVolumeSoundMem(VOLUME, mSoundHandle);
}

/// <summary>
/// 一週流れるとやむ音楽(リズムゲーム用)
/// </summary>
void Sound::PlayBackBGM()
{
	//再生されていなかったら再生する
	if (!CheckSoundMem(mSoundHandle))
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}

	// 音量調整
	ChangeVolumeSoundMem(VOLUME, mSoundHandle);
}

/// <summary>
/// ゲーム内の効果音再生
/// </summary>
void Sound::PlaySE()
{
	//再生されていなかったら再生する
	if (!CheckSoundMem(mSoundHandle))
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}

	// 音量調整
	ChangeVolumeSoundMem(VOLUME, mSoundHandle);
}

/// <summary>
/// 再生している音楽を停止
/// </summary>
void Sound::StopMusic()
{
	StopSoundMem(mSoundHandle);
}

/// <summary>
/// 音楽が再生されているかどうか
/// </summary>
int Sound::CheckBGM()
{
	if (CheckSoundMem(mSoundHandle))
	{
		return true;
	}
	else
	{
		return false;
	}
}
