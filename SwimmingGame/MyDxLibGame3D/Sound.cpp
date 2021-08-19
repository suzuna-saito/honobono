/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "Sound.h"
#include"FishBase.h"
#include"SceneBase.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Sound::Sound(SceneBase& _scene)
	:mOnceSoundFlag(false)
{
	//�T�E���h�ǂݍ���
	//�A�[�e�B�X�e�B�b�N�X�C�~���O��BGM�ƃV���[�g.verBGM
	mDanceBGM = LoadSoundMem("data/Sound/�������V���C�j���O�X�^�[.mp3");
	mDanceShortBGM = LoadSoundMem("data/Sound/�������V���[�g�V���C�j���O�X�^�[.mp3");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Sound::~Sound()
{
	//�T�E���h�f�[�^��S�č폜
	InitSoundMem();
}

/// <summary>
/// ���y���Đ�������
/// </summary>
/// <param name="_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::PlayBGM(SceneBase& _scene)
{
	//�A�[�e�B�X�e�B�b�N�X�C�~���O����BGM
	if (_scene.GetScene() == _scene.DanceGame)
	{
		PlaySoundMem(mDanceBGM, DX_PLAYTYPE_BACK, true);
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
}

/// <summary>
/// �Đ����Ă��鉹�y���~
/// </summary>
/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::StopMusic(SceneBase& _scene)
{
	//�A�[�e�B�X�e�B�b�N�X�C�~���O���ȊO�͎~�߂�
	if (_scene.GetScene() != _scene.DanceGame)
	{
		StopSoundMem(mDanceBGM);
	}
}
