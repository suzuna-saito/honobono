/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/
#include "Sound.h"

// �萔
const int VOLUME = 100;


/// <summary>
/// �R���X�g���N�^
/// </summary>
Sound::Sound(const char* _filePath)
	:mOnceSoundFlag(false)
{
	// �T�E���h�̓ǂݍ���
	mSoundHandle = LoadSoundMem(_filePath);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Sound::~Sound()
{
	DeleteSoundMem(mSoundHandle);
}

/// <summary>
/// ���y���Đ�������
/// </summary>
void Sound::PlayBGM()
{
	//�Đ�����Ă��Ȃ�������Đ�����
	if (!CheckSoundMem(mSoundHandle))
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_LOOP, TRUE);
	}

	// ���ʒ���
	ChangeVolumeSoundMem(VOLUME, mSoundHandle);
}

/// <summary>
/// ��T�����Ƃ�މ��y(���Y���Q�[���p)
/// </summary>
void Sound::PlayBackBGM()
{
	//�Đ�����Ă��Ȃ�������Đ�����
	if (!CheckSoundMem(mSoundHandle))
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}

	// ���ʒ���
	ChangeVolumeSoundMem(VOLUME, mSoundHandle);
}

/// <summary>
/// �Q�[�����̌��ʉ��Đ�
/// </summary>
void Sound::PlaySE()
{
	//�Đ�����Ă��Ȃ�������Đ�����
	if (!CheckSoundMem(mSoundHandle))
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}

	// ���ʒ���
	ChangeVolumeSoundMem(VOLUME, mSoundHandle);
}

/// <summary>
/// �Đ����Ă��鉹�y���~
/// </summary>
void Sound::StopMusic()
{
	StopSoundMem(mSoundHandle);
}

/// <summary>
/// ���y���Đ�����Ă��邩�ǂ���
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
