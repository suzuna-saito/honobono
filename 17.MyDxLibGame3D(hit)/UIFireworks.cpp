#include "UIFireworks.h"

UIFireworks::UIFireworks()
	: mDrawFlag(false)
	, mDrawFlag2(false)
	, mDrawFlag3(false)
	, mDrawPosX(POS_X)
	, mDrawPosY(POS_Y)
	, clearCount(0)
	, time(TIME)
{
	fireworksImg = LoadGraph("data/Asset/hanabi.png");
	fireworksImg2 = LoadGraph("data/Asset/hanabi2.png");
	fireworksImg3 = LoadGraph("data/Asset/hanabi3.png");
}

UIFireworks::~UIFireworks()
{
	DeleteGraph(fireworksImg);
	DeleteGraph(fireworksImg2);
	DeleteGraph(fireworksImg3);
}

void UIFireworks::Update()
{
	clearCount++;
	// 一つ目の花火
	if (clearCount >= 1 && clearCount <= time / 3)
	{
		mDrawFlag = true;
	}
	// 二つ目の花火
	else if (clearCount >= TIME / 3 && clearCount <= time / 2)
	{
		mDrawFlag = false;
		mDrawFlag2 = true;
	}
	// 三つ目の花火
	else if (clearCount >= TIME / 2 && clearCount <= time - 1)
	{
		mDrawFlag2 = false;
		mDrawFlag3 = true;
	}
	else if (clearCount >= time)
	{
		mDrawFlag3 = false;
	}
}

void UIFireworks::Draw()
{
	int x, y;		// DrawExtendGraphを使う際に引数内を見やすくするために変数を作成
	if (mDrawFlag)
	{
		x = mDrawPosX - ADD_POS;
		y = mDrawPosY + ADD_POS;

		DrawExtendGraph(x, y, x + EXPANSION_X, y + EXPANSION_Y, fireworksImg, true);
	}
	else if (mDrawFlag2)
	{
		x = mDrawPosX + ADD_POS;
		y = mDrawPosY - ADD_POS;

		DrawExtendGraph(x, y, x + EXPANSION_X, y + EXPANSION_Y, fireworksImg2, true);
	}
	else if (mDrawFlag3)
	{
		x = mDrawPosX / 2;
		y = mDrawPosY / 2;

		DrawExtendGraph(x, y, x + EXPANSION3, y + EXPANSION3, fireworksImg3, true);
	}
}