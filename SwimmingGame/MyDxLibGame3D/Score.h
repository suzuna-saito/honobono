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

	// リザルト時のスコアの位置
	void SetResultPosition();

	// スコアの割合をもらう
	void SetRadiusScore(int* _BaseScore);
	// スコアフラグをもらう
	void SetScoreFlag(bool* _ScoreFlag);
	// プレイ時のスコアをもらう
	void SetResultScore(int* _Score);

	// リザルトにスコアを渡す
	int GetResult() { return mScore; }

protected:

	// 計算用
	int i, j;
	int tmp;

	// 文字色
	int mColor;

	int mScorePosX, mScorePosY;          // スコアの位置
	int mTmpScore;                       // 計算用
	int mS[5];                           // 描画用スコア
	int mScore;                          // スコア

	int mScoreHandle;                    // スコアの文字画像
	int mNumberHandle[10];               // 数字の画像
	int NUMBER_NUM;                      // 数字の数

	bool mScoreFlag;                     // スコアフラグ
	
	int FONT_SIZE;                       // 文字サイズ

	int NUM_POS;                         // スコアの数字の位置
	int NUM_SPACE;                       // 数字の間隔
	int DIGIT_NUM;                       // 桁数
};

