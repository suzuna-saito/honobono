#include "Sound.h"
#include "SceneBase.h"
#include "Hitchecker.h"
#include "Player.h"

// コンストラクト
Sound::Sound()
	:SoundFlag(false)
{
	// サウンドを読み込み
	// BGM
	titleBGM = LoadSoundMem("data/Sound/gameTitle_BGM.wav");
	gameBGM = LoadSoundMem("data/Sound/game_BGM.mp3");
	clearBGM = LoadSoundMem("data/Sound/gameClear_BGM.mp3");
	overBGM = LoadSoundMem("data/Sound/gameOver_BGM.mp3");

	// SE
	titleSound = LoadSoundMem("data/Sound/pikaTitle_SE.wav");
	clearSound = LoadSoundMem("data/Sound/pikaGlad_SE.mp3");
	overSound = LoadSoundMem("data/Sound/pikaSad_SE.wav");
	moveSound = LoadSoundMem("data/Sound/move_SE.mp3");
	damageSound = LoadSoundMem("data/Sound/damage_SE.mp3");
	goalSound = LoadSoundMem("data/Sound/goal_SE.wav");
}

// デストラクタ
Sound::~Sound()
{
	// サウンドデータをすべて削除
	InitSoundMem();
}


// 音楽を再生させる
void Sound::PlayBGM(SceneBase& _scene)
{
	// タイトルの音楽
	if (_scene.GetScene() == _scene.title)
	{
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(titleSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// ゲーム中の音楽
	if (_scene.GetScene() == _scene.play)
	{
		PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	// ゲームクリアの音楽
	if (_scene.GetScene() == _scene.gameClear)
	{
		PlaySoundMem(clearBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(clearSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// ゲームオーバーの音楽
	if (_scene.GetScene() == _scene.gameOver)
	{
		PlaySoundMem(overBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(overSound, DX_PLAYTYPE_BACK);
	}
}


// 効果音再生
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{

	// 動いたら再生
	if (_moveCheck)
	{
		PlaySoundMem(moveSound, DX_PLAYTYPE_LOOP, FALSE);
	}
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
	else
	{
		StopSoundMem(goalSound);
	}
}


// 音楽を止める
void Sound::StopMusic(SceneBase& _scene)
{
	if (_scene.GetScene() == _scene.play ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(titleBGM);
		StopSoundMem(titleSound);
	}

	if (_scene.GetScene() == _scene.gameClear ||
		_scene.GetScene() == _scene.gameOver)
	{
		StopSoundMem(gameBGM);
		StopSoundMem(moveSound);
		StopSoundMem(damageSound);
		StopSoundMem(goalSound);
	}

	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(clearBGM);
		StopSoundMem(clearSound);
	}

	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(overBGM);
		StopSoundMem(overSound);
	}
}
