#pragma once
#include "Camera.h"
#include "Time.h"
#include "BackGround.h"
#include "Pool.h"
#include "Fish.h"

/// <summary>
/// �v���C�N���X
/// </summary>
class Play
{
private:
	bool mEndFlag;              // �I���t���O

public:
	// �R���X�g���N�^
	Play();
	// �f�X�g���N�^
	~Play();

	// �v���C�V�[��
	void PlayScene();

	// �l��n��
	bool GetEndFlag() { return mEndFlag; }
};

