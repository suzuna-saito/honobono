#include "Sound.h"
#include "SceneBase.h"
#include "Hitchecker.h"
#include "Player.h"

/// <summary>
/// コンストラクト
/// </summary>
Sound::Sound()
	:SoundFlag(false)
{
	// サウンドの読み込み
	// BGM
	titleBGM = LoadSoundMem("data/Sound/gameTitle_BGM.wav");
	gameBGM = LoadSoundMem("data/Sound/game_BGM.mp3");
	clearBGM = LoadSoundMem("data/Sound/gameClear_BGM.mp3");
	overBGM = LoadSoundMem("data/Sound/gameOver_BGM.mp3");

	// 効果音
	titleSound = LoadSoundMem("data/Sound/pikaTitle_SE.wav");
	clearSound = LoadSoundMem("data/Sound/pikaGlad_SE.mp3");
	overSound = LoadSoundMem("data/Sound/pikaSad_SE.wav");
	moveSound = LoadSoundMem("data/Sound/move_SE.mp3");
	damageSound = LoadSoundMem("data/Sound/damage_SE.mp3");
	goalSound = LoadSoundMem("data/Sound/goal_SE.wav");
}

/// <summary>
/// デストラクタ
/// </summary>
Sound::~Sound()
{
	// メモリに読み込んでいるサウンドデータをすべて削除
	InitSoundMem();
}


/// <summary>
/// 音楽を再生させる
/// </summary>
/// <param name="_scene"> シーンベースからシーンを拝借 </param>
void Sound::PlayBGM(SceneBase& _scene)
{
	// タイトルのBGM・効果音を再生
	if (_scene.GetScene() == _scene.title)
	{
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(titleSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// ゲームのBGMを再生
	if (_scene.GetScene() == _scene.play)
	{
		PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	// ゲームクリアのBGM・効果音を再生
	if (_scene.GetScene() == _scene.gameClear)
	{
		PlaySoundMem(clearBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(clearSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// ゲームオーバーのBGM・効果音を再生
	if (_scene.GetScene() == _scene.gameOver)
	{
		PlaySoundMem(overBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(overSound, DX_PLAYTYPE_BACK);
	}
}


/// <summary>
/// ゲーム内の効果音再生
/// </summary>
/// < param name = "_moveCheck"> プレイヤーが動いていることを確認 </param>
/// < param name = "_hitCheck">  プレイヤーがボールにぶつかったことを確認 </param>
/// < param name = "_movecheck"> プレイヤーがゴールしたことを確認 </param>
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{
	// 動いたら再生
	if (_moveCheck)
	{
		PlaySoundMem(moveSound, DX_PLAYTYPE_LOOP, FALSE);
	}
	// 動いていない時は再生しない
	else
	{
		StopSoundMem(moveSound);
	}

	// ぶつかったら再生
	if (_hitCheck && !SoundFlag)
	{
		PlaySoundMem(damageSound, DX_PLAYTYPE_BACK, FALSE);
		SoundFlag = true;
	}
	// ぶつかっていない時は再生しない
	else if(!_hitCheck)
	{
		StopSoundMem(damageSound);
		SoundFlag = false;
	}

	// ゴールしたら再生
	if (_goalCheck)
	{
		PlaySoundMem(goalSound, DX_PLAYTYPE_BACK, TRUE);
	}
	// ゴールしていない時は再生しない
	else
	{
		StopSoundMem(goalSound);
	}
}

/// <summary>
/// 再生している音楽を停止
/// </summary>
/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
void Sound::StopMusic(SceneBase& _scene)
{
	// タイトルのBGM・効果音を停止
	if (_scene.GetScene() == _scene.play ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(titleBGM);
		StopSoundMem(titleSound);
	}

	// ゲームののBGM・効果音を停止
	if (_scene.GetScene() == _scene.gameClear ||
		_scene.GetScene() == _scene.gameOver)
	{
		StopSoundMem(gameBGM);
		StopSoundMem(moveSound);
		StopSoundMem(damageSound);
		StopSoundMem(goalSound);
	}

	// ゲームクリアのBGM・効果音を停止
	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(clearBGM);
		StopSoundMem(clearSound);
	}

	// ゲームオーバーのBGM・効果音を停止
	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(overBGM);
		StopSoundMem(overSound);
	}
}
