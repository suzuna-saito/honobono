#pragma once
#include "DxLib.h"

class Jump;

/// <summary>
/// Player�N���X
/// </summary>
class Fish
{
public:
	// �R���X�g���N�^
	Fish(VECTOR _pos,VECTOR _rotate);
	// �f�X�g���N�^
	virtual ~Fish();

	// �X�V�֐�
	void Update();
	// �`��֐�
	void Draw();

private:

	int mMHandle;                   // Mob�摜�ϐ� 
	int MobFishTexture;             // Mob�e�N�X�`��

	VECTOR mMobPos[11];             // Mob�̍��W

	const VECTOR FISH_MOB_ROTATE[11];    // Mob�̉�]�p�x
	const int FISH_MOB_NUM;                  // ���̐�

	 // �W�����v
	Jump* jump;
};