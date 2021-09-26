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
	void Draw(int _nowScene);
	
	// �X�R�A�̌v�Z
	void Update();

	// �J�E���g���v������֐�
	void Count();

	// �X�R�A�̊��������炤
	void SetRadiusScore(int* _BaseScore);
	// �X�R�A�t���O�����炤
	void SetScoreFlag(bool* _ScoreFlag);
	// �v���C���̃X�R�A�����炤
	void SetResultScore(int* _Score);

	// ���U���g�ɃX�R�A��n��
	int GetResult() { return mScore; }

protected:

	// �v�Z�p
	int i, j;
	int tmp;

	// �����F
	int mColor;

	int mScorePosX, mScorePosY;          // �X�R�A�̈ʒu
	int mResultPosX;                     // ���U���g���̃X�R�A�̈ʒu
	int mTmpScore;                       // �v�Z�p
	int mS[5];                           // �`��p�X�R�A
	int mScore;                          // �X�R�A
	int mPlusScore;                      // ���Z�l
	int mPlusS[4];                       // �`��p���Z�l

	int mScoreHandle;                    // �X�R�A�̕����摜
	int mNumberHandle[10];               // �����̉摜
	int mScoreBar;                       // �X�R�A�̉��ɂ���o�[�̉摜
	int mPlusHandle;                     // �v���X�摜
	int NUMBER_NUM;                      // �����̐�

	bool mScoreFlag;                     // �X�R�A�t���O
	
	int FONT_SIZE;                       // �����T�C�Y

	int mNumPosY;                        // �X�R�A�̈ʒu���猩��������Y���W
	int NUM_POS;                         // �X�R�A�̐����̈ʒu
	int NUM_SPACE;                       // �����̊Ԋu
	int DIGIT_NUM;                       // ����

	int mScoreBarPosY;                   // �X�R�A�̈ʒu���猩���o�[��Y���W

	int mPlusPosX;                       // �v���X�摜��X���W
	int mPlusPosY;                       // �v���X�摜��Y���W
	int mPlusNumPosX;                    // ���Z�l��X���W
	int mPlusNumPosY;                    // ���Z�l��Y���W
	int mPlusNumSpace;                   // ���Z�l�̐����̊��o

	bool mDrawPlusNum;                   // ���Z�l�`�拖��

	int mScoreCount;                     // ���Z�l�̕`�掞�ԃJ�E���g�ϐ�
};
