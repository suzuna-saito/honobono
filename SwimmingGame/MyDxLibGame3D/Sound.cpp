/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "Sound.h"

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
/// < param name = "_scene"> �V�[���擾 </param>
void Sound::PlayBGM()
{
	if (CheckSoundMem(mSoundHandle) != 1)
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_LOOP, TRUE);
	}
	
}

/// <summary>
/// �Q�[�����̌��ʉ��Đ�
/// </summary>
/// < param name = "_scene"> �V�[���擾 </param>
void Sound::PlaySE()
{
	if (CheckSoundMem(mSoundHandle) != 1)
	{
		PlaySoundMem(mSoundHandle, DX_PLAYTYPE_BACK, TRUE);
	}
	
}

/// <summary>
/// �Đ����Ă��鉹�y���~
/// </summary>
/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::StopMusic()
{
	StopSoundMem(mSoundHandle);
}