#pragma once
#include "DxLib.h"

/// <summary>
/// Player�N���X
/// </summary>
class Fish
{
private:

	int mMHandle;                   // Mob�摜�ϐ� 
	int MobFishTexture;             // Mob�e�N�X�`��

	VECTOR mMobPos[11];             // Mob�̍��W

	const VECTOR FISH_MOB_ROTATE[11];    // Mob�̉�]�p�x
	const int FISH_MOB_NUM;                  // ���̐�

public:
	// �R���X�g���N�^
	Fish();
	// �f�X�g���N�^
	virtual ~Fish();

	// �X�V�֐�
	void Update();
	// �`��֐�
	void Draw();
};