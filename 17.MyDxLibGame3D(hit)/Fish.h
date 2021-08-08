#pragma once
#include "DxLib.h"

/// <summary>
/// Player�N���X
/// </summary>
class Fish
{
private:

	int mPHandle;                   // Player�摜�ϐ�
	int mMHandle;                   // Mob�摜�ϐ� 
	int FishTexture;                // Player�e�N�X�`��
	int MobFishTexture;             // Mob�e�N�X�`��
	int i;

	VECTOR mPos;                    // Player�̍��W
	VECTOR mMobPos[11];             // Mob�̍��W

	const VECTOR FISH_SIZE;              // Player&Mob�T�C�Y
	const VECTOR FISH_ROTATE;            // Player�̉�]�p�x
	const VECTOR FISH_MOB_ROTATE[11];    // Mob�̉�]�p�x
	const int FISH_MOB_NUM;                  // ���̐�

public:
	// �R���X�g���N�^
	Fish();
	// �f�X�g���N�^
	virtual ~Fish();

	// �`��֐�
	void Draw();
	// �X�V�֐�
	void Update();
};