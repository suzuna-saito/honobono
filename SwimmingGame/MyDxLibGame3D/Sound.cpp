/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "Sound.h"
#include "SceneBase.h"
#include "Timing.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Sound::Sound(SceneBase& _scene)
	:mOnceSoundFlag(false)
{
	// �T�E���h�̓ǂݍ���
	// BGM
	mTitleBGM = LoadSoundMem("data/newSound/bgm/title.mp3");
	mGameBGM1 = LoadSoundMem("data/newSound/bgm/bgm_1.mp3");
	mGameBGM2 = LoadSoundMem("data/newSound/bgm/bgm_2.mp3");
	mGameBGM3 = LoadSoundMem("data/newSound/bgm/bgm_3.mp3");
	mResultBGM = LoadSoundMem("data/newSound/bgm/result.mp3");

	// ���ʉ�
	mTitleSound = LoadSoundMem("data/newSound/se/startSE.mp3");
	mPerfectSound = LoadSoundMem("data/newSound/se/perfect.mp3");
	mGoodSound = LoadSoundMem("data/newSound/se/good.mp3");
	mBadSound = LoadSoundMem("data/newSound/se/bad.mp3");
	mWaterInSound = LoadSoundMem("data/newSound/se/in.mp3");
	mWaterOutSound = LoadSoundMem("data/newSound/se/out.mp3");
	mResultSound = LoadSoundMem("data/newSound/se/resultSE.mp3");

	timing = new Timing();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Sound::~Sound()
{
	// �T�E���h�f�[�^�����ׂč폜
	InitSoundMem();
	delete timing;
}

/// <summary>
/// ���y���Đ�������
/// </summary>
/// < param name = "_scene"> �V�[���擾 </param>
void Sound::PlayBGM(SceneBase& _scene)
{
	// �^�C�g���̉��y
	if (_scene.GetScene() == _scene.title)
	{
		PlaySoundMem(mTitleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
	// �Q�[�����̉��y
	if (_scene.GetScene() == _scene.play)
	{
		PlaySoundMem(mGameBGM2, DX_PLAYTYPE_BACK, TRUE);
	}
	// ���U���g�̉��y
	if (_scene.GetScene() == _scene.gameClear)
	{
		PlaySoundMem(mResultBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
}

/// <summary>
/// �Q�[�����̌��ʉ��Đ�
/// </summary>
/// < param name = "_scene"> �V�[���擾 </param>
void Sound::PlaySE(SceneBase& _scene)
{
	// �^�C�g���̌��ʉ�
	if (_scene.GetScene() == _scene.title)
	{
		/*
		// �Q�[���X�^�[�g�̃{�^���������ꂽ��
		//if()
		{
			PlaySoundMem(mTitleSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// ����ȊO�͌��ʉ����~�߂�
		//else
		{
			StopSoundMem(mTitleSound);
		}
		*/
		
	}
	// �Q�[�����̌��ʉ�
	if (_scene.GetScene() == _scene.play)
	{
		/*
		// ��э���Ő��ɓ�������
		if()
		{
			PlaySoundMem(mWaterInSound,DX_PLAYTYPE_NORMAL);
		}
		// ����ȊO�͌��ʉ����~�߂�
		else
		{
			StopSoundMem(mWaterInSound);
		}
		// �V���N�����̐����Ԃ��̉�
		if()
		{
			PlaySoundMem(mWaterOutSound, DX_PLAYTYPE_NORMAL);
		}
		// ����ȊO�͌��ʉ����~�߂�
		else
		{
			StopSoundMem(mWaterOutSound);
		}
		*/

		// ���A�N�V�������p�[�t�F�N�g��������
		if (timing->PerfectFlag)
		{
			PlaySoundMem(mPerfectSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// ����ȊO���͌��ʉ����~�߂�
		else
		{
			StopSoundMem(mPerfectSound);
		}
		// ���A�N�V�������O�b�h��������
		if (timing->GoodFlag)
		{
			PlaySoundMem(mGoodSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// ����ȊO�͌��ʉ����~�߂�
		else
		{
			StopSoundMem(mGoodSound);
		}
		// ���A�N�V�������o�b�h��������
		if (timing->BadFlag)
		{
			PlaySoundMem(mBadSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// ����ȊO���͌��ʉ����~�߂�
		else
		{
			StopSoundMem(mBadSound);
		}
	}
	// ���U���g�̌��ʉ�
	if (_scene.GetScene() == _scene.gameClear)
	{
		/*
			// �X�R�A���o����
		{
			PlaySoundMem(mResultSound, DX_PLAYTYPE_BACK, TRUE);
		}
		// ����ȊO�͌��ʉ����~�߂�
		else
		{
			StopSoundMem(mResultSound);
		}
		*/
	}
}

/// <summary>
/// �Đ����Ă��鉹�y���~
/// </summary>
/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::StopMusic(SceneBase& _scene)
{
	// �^�C�g����BGM���~������
	if (_scene.GetScene() == _scene.play ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(mTitleBGM);
	}
	// �Q�[����BGM���~������
	if (_scene.GetScene() == _scene.gameClear ||
		_scene.GetScene() == _scene.gameOver)
	{
		StopSoundMem(mGameBGM2);
	}
	// ���U���g��BGM���~������
	if (_scene.GetScene() == _scene.title ||
		_scene.GetScene() == _scene.gameEnd)
	{
		StopSoundMem(mResultBGM);
	}
}
