#include "Time.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Time::Time()
	: mTimeCount(0)
	, mNowTime(0)
	, mDeltaTime(0.000001f)
	, mFPS(0)
	, mFPSCounter(0)
{
	// �V�X�e�����Ԃ��擾
	mTime = GetNowHiPerformanceCount();
	mFPSCheckTime = GetNowHiPerformanceCount();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Time::~Time()
{
}

/// <summary>
/// ���Ԃ̍X�V
/// </summary>
void Time::Update()
{
	// �t���[�������擾
	mTimeCount++;
	// ���݂̃V�X�e�����Ԃ��擾
	mNowTime = GetNowHiPerformanceCount();

	// �O��擾�������Ԃ���o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g
	// (GetNowHiPerformanceCount�Ŏ擾�ł���l�̓}�C�N���b�P�ʂȂ̂�1000000�Ŋ��邱�Ƃŕb�P�ʂɂȂ�j
	mDeltaTime = (mNowTime - mTime) / 1000000.0f;

	// ����擾�������Ԃ�ۑ�
	mTime = mNowTime;

	// FPS�֌W�̏���(1�b�o�߂���ԂɎ��s���ꂽ���C�����[�v�̉񐔂�FPS�Ƃ���)
	mFPSCounter++;
	if (mNowTime - mFPSCheckTime > 1000000)
	{
		mFPS = mFPSCounter;
		mFPSCounter = 0;
		mFPSCheckTime = mNowTime;
	}
}

/// <summary>
/// FPS���l��`��
/// </summary>
void Time::CheckFPS()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS : %d", mFPS);
}
