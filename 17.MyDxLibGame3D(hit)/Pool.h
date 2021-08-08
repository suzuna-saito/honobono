#pragma once
#include "DxLib.h"

/// <summary>
/// Pool�N���X
/// </summary>
class Pool
{
private:
	int mPoolHandle;                       // �v�[���摜�ϐ�
	int mPoolWaterHandle;                  // �v�[���̐��摜�ϐ�
	int mDivingBoardHandle;                // ��э��ݑ�摜�ϐ�
	int i;

	VECTOR mPoolPos;                       // �v�[���̈ʒu
	VECTOR mWaterPos;                      // ���̈ʒu
	VECTOR mDivingBoardPos[4];                // ��э��ݑ�̈ʒu

	const VECTOR POOL_SIZE;                // �v�[���̃T�C�Y
	const VECTOR WATER_SIZE;               // ���̃T�C�Y
	const VECTOR DIVINGBOARD_SIZE;         // ��э��ݑ�̃T�C�Y
	const VECTOR DIVINGBOARD_ROTATE[4];
	const int DIVINGBOARD_NUM;

public:
	// �R���X�g���N�^
	Pool();
	// �f�X�g���N�^
	virtual ~Pool();
	// �`��֐�
	void Draw();
};