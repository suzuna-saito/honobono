#pragma once
#include "DxLib.h"

class Score
{
public:
	// �R���X�g���N�^
	Score();
	// �f�X�g���N�^
	virtual ~Score();

	// �X�R�A�̕`��
	void Draw();
	
	// �X�R�A�̌v�Z
	void Update();

	// �X�R�A�̊��������炤
	void GetScore(int* _BaseScore);

	// ���U���g�ɃX�R�A��n��
	int GetResult() { return mScore; }

protected:

	// �v�Z�p
	int i;
	int tmp;

	// �����F
	int mColor;

	int mScorePosX, mScorePosY;          // �X�R�A�̈ʒu
	int mTmpScore;                       // �v�Z�p
	int mS[5];                           // �`��p�X�R�A
	int mScore;                          // �X�R�A
	
	int FONT_SIZE;                       // �����T�C�Y

	int NUM_POS;                         // �X�R�A�̐����̈ʒu
	int NUM_SPACE;                       // �����̊Ԋu
	int DIGIT_NUM;                       // ����
};

