#include "Score.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Score::Score()
{
	FONT_SIZE = 30;
	DIGIT_NUM = 5;
	NUM_POS = 110;
	NUM_SPACE = 30;
	i = 0;
	tmp = 0;
	mColor = GetColor(0, 0, 0);
	mScorePosX = 0;
	mScorePosY = 0;
	mScore = 0;
	mTmpScore = 0;
	for (i = 0; i < DIGIT_NUM; i++)
	{
		mS[i] = 0;
	}
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
	SetFontSize(FONT_SIZE);
	DrawString(mScorePosX, mScorePosY, "SCORE:", mColor);
	for (i = 0; i < DIGIT_NUM; i++)
	{
		DrawFormatString(NUM_POS + NUM_SPACE * i, mScorePosY, mColor, "%d", mS[i]);
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
/// �X�R�A�̌v�Z�̊��������炤
/// </summary>
/// <param name="_BaseScore">�X�R�A�Ɋ|���銄��</param>
void Score::GetScore(int* _BaseScore)
{
	mScore += *_BaseScore * 10;
	Update();
}