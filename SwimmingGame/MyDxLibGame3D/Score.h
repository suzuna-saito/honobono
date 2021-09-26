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
	void Draw(int _nowScene);
	
	// スコアの計算
	void Update();

	// カウントを計測する関数
	void Count();

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
	int mResultPosX;                     // リザルト時のスコアの位置
	int mTmpScore;                       // 計算用
	int mS[5];                           // 描画用スコア
	int mScore;                          // スコア
	int mPlusScore;                      // 加算値
	int mPlusS[4];                       // 描画用加算値

	int mScoreHandle;                    // スコアの文字画像
	int mNumberHandle[10];               // 数字の画像
	int mScoreBar;                       // スコアの下にあるバーの画像
	int mPlusHandle;                     // プラス画像
	int NUMBER_NUM;                      // 数字の数

	bool mScoreFlag;                     // スコアフラグ
	
	int FONT_SIZE;                       // 文字サイズ

	int mNumPosY;                        // スコアの位置から見た数字のY座標
	int NUM_POS;                         // スコアの数字の位置
	int NUM_SPACE;                       // 数字の間隔
	int DIGIT_NUM;                       // 桁数

	int mScoreBarPosY;                   // スコアの位置から見たバーのY座標

	int mPlusPosX;                       // プラス画像のX座標
	int mPlusPosY;                       // プラス画像のY座標
	int mPlusNumPosX;                    // 加算値のX座標
	int mPlusNumPosY;                    // 加算値のY座標
	int mPlusNumSpace;                   // 加算値の数字の感覚

	bool mDrawPlusNum;                   // 加算値描画許可

	int mScoreCount;                     // 加算値の描画時間カウント変数
};

