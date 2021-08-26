#pragma once
#include "DxLib.h"

class Score
{
public:
	// コンストラクタ
	Score();
	// デストラクタ
	virtual ~Score();

	// スコアの描画
	void Draw();
	
	// スコアの計算
	void Update();

	// スコアの割合をもらう
	void GetScore(int* _BaseScore);

	// リザルトにスコアを渡す
	int GetResult() { return mScore; }

protected:

	// 計算用
	int i;
	int tmp;

	// 文字色
	int mColor;

	int mScorePosX, mScorePosY;          // スコアの位置
	int mTmpScore;                       // 計算用
	int mS[5];                           // 描画用スコア
	int mScore;                          // スコア
	
	int FONT_SIZE;                       // 文字サイズ

	int NUM_POS;                         // スコアの数字の位置
	int NUM_SPACE;                       // 数字の間隔
	int DIGIT_NUM;                       // 桁数
};

