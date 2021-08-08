/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "Sound.h"
#include"SceneBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sound::Sound(SceneBase& _scene)
	:mOnceSoundFlag(false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
Sound::~Sound()
{
}

/// <summary>
/// 音楽を再生させる
/// </summary>
/// <param name="_scene"> シーンベースからシーンを拝借 </param>
void Sound::PlayBGM(SceneBase& _scene)
{
}

/// <summary>
/// ゲーム内の効果音再生
/// </summary>
/// < param name = "_moveCheck"> プレイヤーが動いていることを確認 </param>
/// < param name = "_hitCheck">  プレイヤーがボールにぶつかったことを確認 </param>
/// < param name = "_movecheck"> プレイヤーがゴールしたことを確認 </param>
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{
}

/// <summary>
/// 再生している音楽を停止
/// </summary>
/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
void Sound::StopMusic(SceneBase& _scene)
{
}
