#include "Score.h"

/// <summary>
/// コンストラクタ
/// </summary>
Score::Score()
{
	FONT_SIZE = 30;
	DIGIT_NUM = 5;
	NUM_POS = 110;
	NUM_SPACE = 40;
	i = j = 0;
	tmp = 0;
	mColor = GetColor(0, 0, 0);
	mScorePosX = 0;
	mScorePosY = 0;
	mScore = 0;
	mTmpScore = 0;
	mScoreFlag = false;
	NUMBER_NUM = 10;
	for (i = 0; i < DIGIT_NUM; i++)
	{
		mS[i] = 0;
	}

	LoadDivGraph("data/newUI/number.png", 10, 5, 2, 40, 50, mNumberHandle, true);
	mScoreHandle = LoadGraph("data/newUI/score.png", true);
}

/// <summary>
/// デストラクタ
/// </summary>
Score::~Score()
{
}

/// <summary>
/// スコア描画
/// </summary>
void Score::Draw()
{
	DrawGraph(mScorePosX, mScorePosY, mScoreHandle, true);
	for (i = 0; i < DIGIT_NUM; i++)
	{
		for (j = 0; j < NUMBER_NUM; j++)
		{
			if (mS[i] == j)
			{
				DrawGraph(NUM_POS + NUM_SPACE * i, mScorePosY, mNumberHandle[j], true);
			}
		}
	}
}

/// <summary>
/// スコアの計算
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
/// リザルト時のスコアの位置
/// </summary>
void Score::SetResultPosition()
{
	mScorePosX = 170;
	mScorePosY = 175;
	NUM_POS = mScorePosX + NUM_POS;
}

/// <summary>
/// スコアの計算の割合をもらう
/// </summary>
/// <param name="_BaseScore">スコアに掛ける割合</param>
void Score::SetRadiusScore(int* _BaseScore)
{
	if (mScoreFlag)
	{
		mScore += *_BaseScore * 10;
		Update();
	}
}

/// <summary>
/// スコアフラグをもらう
/// </summary>
/// <param name="_ScoreFlag">スコアフラグ</param>
void Score::SetScoreFlag(bool* _ScoreFlag)
{
	mScoreFlag = *_ScoreFlag;
}

/// <summary>
/// プレイ時のスコアをもらう
/// </summary>
/// <param name="_Score">プレイ時のスコア</param>
void Score::SetResultScore(int* _Score)
{
	mScore = *_Score;
	Update();
}
