#include "Sound.h"
#include "SceneBase.h"
#include "Hitchecker.h"
#include "Player.h"

/// <summary>
/// �R���X�g���N�g
/// </summary>
Sound::Sound()
	:SoundFlag(false)
{
	// �T�E���h�̓ǂݍ���
	// BGM
	titleBGM = LoadSoundMem("data/Sound/gameTitle_BGM.wav");
	gameBGM = LoadSoundMem("data/Sound/game_BGM.mp3");
	clearBGM = LoadSoundMem("data/Sound/gameClear_BGM.mp3");
	overBGM = LoadSoundMem("data/Sound/gameOver_BGM.mp3");

	// ���ʉ�
	titleSound = LoadSoundMem("data/Sound/pikaTitle_SE.wav");
	clearSound = LoadSoundMem("data/Sound/pikaGlad_SE.mp3");
	overSound = LoadSoundMem("data/Sound/pikaSad_SE.wav");
	moveSound = LoadSoundMem("data/Sound/move_SE.mp3");
	damageSound = LoadSoundMem("data/Sound/damage_SE.mp3");
	goalSound = LoadSoundMem("data/Sound/goal_SE.wav");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Sound::~Sound()
{
	// �������ɓǂݍ���ł���T�E���h�f�[�^�����ׂč폜
	InitSoundMem();
}


/// <summary>
/// ���y���Đ�������
/// </summary>
/// <param name="_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::PlayBGM(SceneBase& _scene)
{
	// �^�C�g����BGM�E���ʉ����Đ�
	if (_scene.GetScene() == _scene.title)
	{
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(titleSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// �Q�[����BGM���Đ�
	if (_scene.GetScene() == _scene.play)
	{
		PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	// �Q�[���N���A��BGM�E���ʉ����Đ�
	if (_scene.GetScene() == _scene.gameClear)
	{
		PlaySoundMem(clearBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(clearSound, DX_PLAYTYPE_BACK, TRUE);
	}

	// �Q�[���I�[�o�[��BGM�E���ʉ����Đ�
	if (_scene.GetScene() == _scene.gameOver)
	{
		PlaySoundMem(overBGM, DX_PLAYTYPE_LOOP, TRUE);
		PlaySoundMem(overSound, DX_PLAYTYPE_BACK);
	}

	if (_scene.GetScene() == _scene.gameEnd)
	{
	}
}


/// <summary>
/// �Q�[�����̌��ʉ��Đ�
/// </summary>
/// < param name = "_moveCheck"> �v���C���[�������Ă��邱�Ƃ��m�F </param>
/// < param name = "_hitCheck">  �v���C���[���{�[���ɂԂ��������Ƃ��m�F </param>
/// < param name = "_movecheck"> �v���C���[���S�[���������Ƃ��m�F </param>
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{
	// ��������Đ�
	if (_moveCheck)
	{
		PlaySoundMem(moveSound, DX_PLAYTYPE_LOOP, FALSE);
	}
	// �����Ă��Ȃ����͍Đ����Ȃ�
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
	// �Ԃ����Ă��Ȃ����͍Đ����Ȃ�
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
	// �S�[�����Ă��Ȃ����͍Đ����Ȃ�
	else
	{
		StopSoundMem(goalSound);
	}
}

/// <summary>
/// �Đ����Ă��鉹�y���~
/// </summary>
/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::StopMusic(SceneBase& _scene)
{
	// �^�C�g����BGM�E���ʉ����~
	if (_scene.GetScene() == _scene.play ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(titleBGM);
		StopSoundMem(titleSound);
	}

	// �Q�[���̂�BGM�E���ʉ����~
	if (_scene.GetScene() == _scene.gameClear ||
		_scene.GetScene() == _scene.gameOver)
	{
		StopSoundMem(gameBGM);
		StopSoundMem(moveSound);
		StopSoundMem(damageSound);
		StopSoundMem(goalSound);
	}

	// �Q�[���N���A��BGM�E���ʉ����~
	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(clearBGM);
		StopSoundMem(clearSound);
	}

	// �Q�[���I�[�o�[��BGM�E���ʉ����~
	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(overBGM);
		StopSoundMem(overSound);
	}
}
