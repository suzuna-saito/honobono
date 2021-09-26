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
	/// �L���̕`��
	/// </summary>
	void Draw();


	/// <summary>
	/// �L���̃Z�b�g
	/// </summary>
	void SetPromo();

private:
	// �L����\��������|�W�V����
	const VECTOR mPromoDrawPos[16];
	// �L���̓y���\��������|�W�V�����P
	const VECTOR mBaseDrawPos1[2];
	// �L���̓y���\��������|�W�V�����Q
	const VECTOR mBaseDrawPos2[2];
	// �T�C�Y�̃Z�b�g
	const VECTOR mSetSize;

	//  �e�N�X�`��
	// �x�[�X
	int mBase;
	// �V���v���ȍL��
	int mSimple;
	// �t�@���\�b�N�̍L��
	int mFalsoc;
	// �w�Z�̍L��
	int mSchool;
	// �ق̂ڂ̂̍L��
	int mHonobono;
	// �R�[���̍L��
	int mKora;
	// ���{�̍L��
	int mJapan;
	// ��܂��̍L��
	int mYamako;


	// �L���̓y��
	int mPromo[16];
	// �L���̃x�[�X�P
	int mPromoBase1[2];
	// �L���̃x�[�X�Q
	int mPromoBase2[2];
};

