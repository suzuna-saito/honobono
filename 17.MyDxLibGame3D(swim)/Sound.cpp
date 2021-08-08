/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "Sound.h"

// コンストラクト
Sound::Sound()
	:mOnceSoundFlag(false)
{
}

// デストラクタ
Sound::~Sound()
{
}


// 音楽を再生させる
void Sound::PlayBGM(int _scene)
{
}


// 効果音再生
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{
}


// 音楽を止める
void Sound::StopMusic(int _scene)
{
}
