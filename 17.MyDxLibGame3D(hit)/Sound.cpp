#include "Sound.h"
#include "SceneBase.h"
#include "Hitchecker.h"
#include "Player.h"

// �R���X�g���N�g
Sound::Sound()
	:SoundFlag(false)
{
	// �T�E���h��ǂݍ���
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

// �f�X�g���N�^
Sound::~Sound()
{
	// �T�E���h�f�[�^�����ׂč폜
	InitSoundMem();
}


// ���y���Đ�������
void Sound::PlayBGM(SceneBase& _scene)
{
	// �^�C�g���̉��y
	if (_scene.GetScene() == _scene.title)
	{
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(titleSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// �Q�[�����̉��y
	if (_scene.GetScene() == _scene.play)
	{
		PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	// �Q�[���N���A�̉��y
	if (_scene.GetScene() == _scene.gameClear)
	{
		PlaySoundMem(clearBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(clearSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// �Q�[���I�[�o�[�̉��y
	if (_scene.GetScene() == _scene.gameOver)
	{
		PlaySoundMem(overBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(overSound, DX_PLAYTYPE_BACK);
	}
}


// ���ʉ��Đ�
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{

	// ��������Đ�
	if (_moveCheck)
	{
		PlaySoundMem(moveSound, DX_PLAYTYPE_LOOP, FALSE);
	}
	else
	{
		StopSoundMem(moveSound);
	}

	// �Ԃ�������Đ�
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

	// �S�[��������Đ�
	if (_goalCheck)
	{
		PlaySoundMem(goalSound, DX_PLAYTYPE_BACK, TRUE);
	}
	else
	{
		StopSoundMem(goalSound);
	}
}


// ���y���~�߂�
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
