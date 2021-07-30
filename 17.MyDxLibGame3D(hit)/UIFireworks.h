#pragma once
#include <DxLib.h>
#include "UIBase.h"

const int POS_X = 150;		// Xの座標
const int POS_Y = 100;		// Yの座標

const int ADD_POS = 150;		// 描画ポジションを少しずらすための値

const int EXPANSION_X = 230;// 一つ目と二つ目の花火の拡大値X
const int EXPANSION_Y = 250;// 一つ目と二つ目の花火の拡大値Y
const int EXPANSION3 = 400;	// 三つ目の花火の拡大値

const int TIME = 240;		// 花火を出すタイミング(最大)

// 花火の描画

class UIFireworks
{
public:
	UIFireworks();		// コンストラクタ
	~UIFireworks();		// デストラクタ

	// _drawcount
	// 花火を描画するタイミングを図るためのカウント
	void Update();

	void Draw();

	int GetclearCount() { return clearCount; }
	const int time;				// 花火を出すタイミング(最大)

private:
	int fireworksImg;		// 花火の画像読み込み
	int fireworksImg2;		// 花火の画像読み込み2
	int fireworksImg3;		// 花火の画像読み込み3

	bool mDrawFlag;			// 一つ目の花火を描画するかどうか
	bool mDrawFlag2;		// 二つ目の花火を描画するかどうか
	bool mDrawFlag3;		// 三つ目の花火を描画するかどうか

	const int mDrawPosX;		// 描画させるポジションX
	const int mDrawPosY;		// 描画させるポジションY

	int clearCount;				// クリアしてたった時間
};