#include "Score.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Score::Score()
{
	FONT_SIZE = 30;
	DIGIT_NUM = 5;
	NUM_POS = 220;
	NUM_SPACE = 80;
	mScoreBarPosY = 50;
	mNumPosY = 30;
	i = j = 0;
	tmp = 0;
	mColor = GetColor(0, 0, 0);
	mScorePosX = 50;
	mScorePosY = 80;
	mScore = 0;
	mTmpScore = 0;
	mScoreFlag = false;
	NUMBER_NUM = 10;
	for (i = 0; i < DIGIT_NUM; i++)
	{
		mS[i] = 0;
	}

	LoadDivGraph("data/newUI/number.png", 10, 5, 2, 80, 100, mNumberHandle, true);
	mScoreHandle = LoadGraph("data/newUI/score.png", true);
	mScoreBar = LoadGraph("data/newUI/ScoreBar.png", true);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Score::~Score()
{
}

/// <summary>
/// �X�R�A�`��
/// </summary>
void Score::Draw()
{
	// �o�[��`��
	DrawGraph(mScorePosX, mScorePosY + mScoreBarPosY, mScoreBar, true);
	// �X�R�A��`��
	DrawGraph(mScorePosX, mScorePosY, mScoreHandle, true);
	// ������`��
	for (i = 0; i < DIGIT_NUM; i++)
	{
		for (j = 0; j < NUMBER_NUM; j++)
		{
			if (mS[i] == j)
			{
				DrawGraph(NUM_POS + NUM_SPACE * i, mScorePosY - mNumPosY, mNumberHandle[j], true);
			}
		}
	}
}

/// <summary>
/// �X�R�A�̌v�Z
/// </summary>
void Score::Update()
{
	mTmpScore = mScore;
	if (mScore <= 99900)
	{
		for (i = DIGIT_NUM - 1; i >= 0; i--)
		{
			mS[i] = mTmpScore % 10;
			tmp = mTmpScore % 10;
			mTmpScore = (mTmpScore - tmp) / 10;
		}
	}
}

/// <summary>
/// ���U���g���̃X�R�A�̈ʒu
/// </summary>
void Score::SetResultPosition()
{
	mScorePosX = 170;
	mScorePosY = 175;
	NUM_POS = mScorePosX + NUM_POS;
}

/// <summary>
/// �X�R�A�̌v�Z�̊��������炤
/// </summary>
/// <param name="_BaseScore">�X�R�A�Ɋ|���銄��</param>
void Score::SetRadiusScore(int* _BaseScore)
{
	if (mScoreFlag)
	{
		mScore += *_BaseScore * 10;
		Update();
	}
}

/// <summary>
/// �X�R�A�t���O�����炤
/// </summary>
/// <param name="_ScoreFlag">�X�R�A�t���O</param>
void Score::SetScoreFlag(bool* _ScoreFlag)
{
	mScoreFlag = *_ScoreFlag;
}

/// <summary>
/// �v���C���̃X�R�A�����炤
/// </summary>
/// <param name="_Score">�v���C���̃X�R�A</param>
void Score::SetResultScore(int* _Score)
{
	mScore = *_Score;
	Update();
}
