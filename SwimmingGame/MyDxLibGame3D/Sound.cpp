/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "Sound.h"

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
	if (CheckSoundMem(mSoundHandle) != 1)
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_LOOP, TRUE);
	}
	
}

/// <summary>
/// 一周流れると流れなくなるBGM
/// </summary>
void Sound::PlayBackBGM()
{
	if (CheckSoundMem(mSoundHandle) != 1)
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}
}

/// <summary>
/// ゲーム内の効果音再生
/// </summary>
/// < param name = "_scene"> シーン取得 </param>
void Sound::PlaySE()
{
	//再生されていなかったら再生する
	if (CheckSoundMem(mSoundHandle) != 1)
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}
}

/// <summary>
/// 再生している音楽を停止
/// </summary>
/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
void Sound::StopMusic()
{
	StopSoundMem(mSoundHandle);
}

/// <summary>
/// 音楽が再生されているかどうか
/// </summary>
/// <returns>再生されていない：0  再生されている：1</returns>
int Sound::CheckBGM()
{
	if (!CheckSoundMem(mSoundHandle))
	{
		return false;
	}
	else if (CheckSoundMem(mSoundHandle))
	{
		return true;
	}
}
