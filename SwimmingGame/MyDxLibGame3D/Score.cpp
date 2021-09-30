#include "Score.h"

// 定数
const int RESULT_POS_X = 580;   // リザルトの時のスコア左上頂点X
const int RESULT_POS_Y = 400;   // リザルトの時のスコア左上頂点Y
const int RESULT_POS_02X = 780; // リザルトの時のスコア右下頂点座標X
const int RESULT_POS_02Y = 500; // リザルトの時のスコア右下頂点座標Y

const int RESULT_NUM_X = RESULT_POS_02X+20;   // リザルトの時の数字左上頂点座標X
const int RESULT_NUM_Y = RESULT_POS_Y;        // リザルトの時の数字左上頂点座標Y
const int RESULT_NUM_02Y = RESULT_POS_02Y;    // リザルトの時の数字右下頂点座標Y

const int RESULT_NUM_SPACE = 100;             // リザルトの時の数字の間隔
const int DRAW_PLUS_SCORE = 50;               // 加算値スコアの描画時間

/// <summary>
/// コンストラクタ
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
	mResultPosX = RESULT_NUM_X;
	mScore = 0;
	mTmpScore = 0;
	mScoreFlag = false;
	NUMBER_NUM = 10;
	mPlusScore = 0;
	mPlusPosX = 300;
	mPlusPosY = 170;
	mScoreCount = 0;
	mPlusNumPosX = 380;
	mPlusNumPosY = 200;
	mPlusNumSpace = 60;
	mDrawPlusNum = false;

	for (i = 0; i < DIGIT_NUM; i++)
	{
		mS[i] = 0;
	}

	for (i = 0; i < DIGIT_NUM - 1; i++)
	{
		mPlusS[i] = 0;
	}

	LoadDivGraph("data/newUI/number.png", 10, 5, 2, 80, 100, mNumberHandle, true);
	mScoreHandle = LoadGraph("data/newUI/score.png", true);

	mScoreBar = LoadGraph("data/newUI/ScoreBar.png", true);
	mPlusHandle = LoadGraph("data/newUI/Plus.png", true);
}

/// <summary>
/// デストラクタ
/// </summary>
Score::~Score()
{
	for (i = 0; i < NUMBER_NUM; i++)
	{
		DeleteGraph(mNumberHandle[i]);
	}
	DeleteGraph(mScoreHandle);
	DeleteGraph(mScoreBar);
	DeleteGraph(mPlusHandle);
}

/// <summary>
/// スコア描画
/// </summary>
void Score::Draw(int _nowScene)
{
	// プレイシーンとリザルトシーンによって描画する大きさを変える
	switch (_nowScene)
	{
	case 3:   // プレイシーン

		DrawGraph(mScorePosX, mScorePosY + mScoreBarPosY, mScoreBar, true);

		DrawGraph(mScorePosX, mScorePosY, mScoreHandle, true);
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

		// 加算値を描画してもいいなら
		if (mDrawPlusNum)
		{
			// プラスの画像を描画
			DrawGraph(mPlusPosX, mPlusPosY, mPlusHandle, true);
			// 加算値を描画
			for (i = 0; i < DIGIT_NUM - 1; i++)
			{
				for (j = 0; j < NUMBER_NUM; j++)
				{
					if (mPlusS[i] == j)
					{
						DrawRotaGraph(mPlusNumPosX + mPlusNumSpace * i, mPlusNumPosY, 0.8, 0, mNumberHandle[j], true, false, false);
					}
				}
			}
		}
		break;

	case 5:   // リザルトシーン
		DrawExtendGraph(RESULT_POS_X, RESULT_POS_Y, RESULT_POS_02X, RESULT_POS_02Y,
			mScoreHandle, true);

		NUM_SPACE = RESULT_NUM_SPACE;

		for (i = 0; i < DIGIT_NUM; i++)
		{
			for (j = 0; j < NUMBER_NUM; j++)
			{
				if (mS[i] == j)
				{
					DrawExtendGraph(mResultPosX + NUM_SPACE * i, RESULT_NUM_Y, mResultPosX + NUM_SPACE * i + NUM_SPACE, RESULT_NUM_02Y, mNumberHandle[j], true);
				}
			}
		}
		break;

	default:
		break;
	}
	
}

/// <summary>
/// スコアの計算
/// </summary>
void Score::Update()
{
	// スコアのソート
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

	// 加算値のソート
	for (i = DIGIT_NUM - 2; i >= 0; i--)
	{
		mPlusS[i] = mPlusScore % 10;
		tmp = mPlusScore % 10;
		mPlusScore = (mPlusScore - tmp) / 10;
	}
}

/// <summary>
/// カウントを計測する関数
/// </summary>
void Score::Count()
{
	// 加算値が描画されていたら
	if (mDrawPlusNum)
	{
		// 加算値描画時間をカウントする
		mScoreCount++;
	}

	// 加算値描画時間が終わったら
	if (mScoreCount > DRAW_PLUS_SCORE)
	{
		// カウントを0
		mScoreCount = 0;
		// 描画許可をfalse
		mDrawPlusNum = false;
	}
}


/// <summary>
/// スコアの計算の割合をもらう
/// </summary>
/// <param name="_BaseScore">スコアに掛ける割合</param>
void Score::SetRadiusScore(int* _BaseScore)
{
	// スコアを格納してよかったら
	if (mScoreFlag)
	{
		// 加算値の変数に値を格納
		mPlusScore = *_BaseScore * 10;
		// スコアの変数に値を格納
		mScore += *_BaseScore * 10;
		// 加算値描画許可をtrueに
		mDrawPlusNum = true;
		Update();
	}
	Count();
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
