#pragma once
#include "DxLib.h"

class Promotion
{
public:

	// �R���X�g���N�^
	Promotion();
	// �f�X�g���N�^
	~Promotion();

	/// <summary>
	/// �L���̕\��
	/// </summary>
	void Draw();

private:
	// �\��������|�W�V����
	const VECTOR mDrawPos;

	// �V���v���ȍL��
	int mSimple;

	int mPromo;
};

