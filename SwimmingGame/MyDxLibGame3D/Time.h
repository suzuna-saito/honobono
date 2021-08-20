#pragma once
#include "DxLib.h"

/// <summary>
/// ���Ԃ̃N���X
/// </summary>
class Time
{
private:

	int mTimeCount;              // �t���[����

	LONGLONG mNowTime;           // ���̃V�X�e������
	LONGLONG mTime;              // �O�̃V�X�e������
	float mDeltaTime;            // �f���^�^�C��
	int mFPS;                    // FPS
	int mFPSCounter;             // FPS�𐔂���
	LONGLONG mFPSCheckTime;      // �V�X�e�����Ԃ�ۑ�

public:
	// �R���X�g���N�^
	Time();
	// �f�X�g���N�^
	~Time();

	// �X�V
	void Update();

	// FPS���l��`��
	void CheckFPS();

	// �f���^�^�C���̒l��n��
	float GetDeltaTime() { return mDeltaTime; }
	// �t���[������n��
	int GetTimeCount() { return mTimeCount; }
};