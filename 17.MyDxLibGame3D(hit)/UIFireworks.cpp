#include "UIFireworks.h"

/// <summary>
/// コンストラクタ
/// </summary>
UIFireworks::UIFireworks()
	: mDrawFlag(false)
	, mDrawFlag2(false)
	, mDrawFlag3(false)
	, mDrawPosX(POS_X)
	, mDrawPosY(POS_Y)
	, clearCount(0)
	, time(TIME)
{
	// 画像読み込み
	fireworksImg = LoadGraph("data/Asset/hanabi.png");
	fireworksImg2 = LoadGraph("data/Asset/hanabi2.png");
	fireworksImg3 = LoadGraph("data/Asset/hanabi3.png");
}

/// <summary>
/// デストラクタ
/// </summary>
UIFireworks::~UIFireworks()
{
	// 画像をメモリから削除
	DeleteGraph(fireworksImg);
	DeleteGraph(fireworksImg2);
	DeleteGraph(fireworksImg3);
}

/// <summary>
/// 更新
/// </summary>
void UIFireworks::Update()
{
	clearCount++;
	// 一つ目の花火
	if (clearCount >= 1 && clearCount <= time / 3)
	{
		// 1つ目の花火描画フラグを「真」にする
		mDrawFlag = true;
	}
	// 二つ目の花火
	else if (clearCount >= TIME / 3 && clearCount <= time / 2)
	{
		// 1つ目の花火描画フラグを「偽」にする
		mDrawFlag = false;
		// 2つ目の花火描画フラグを「真」にする
		mDrawFlag2 = true;
	}
	// 三つ目の花火
	else if (clearCount >= TIME / 2 && clearCount <= time - 1)
	{
		// 2つ目の花火描画フラグを「偽」にする
		mDrawFlag2 = false;
		// 3つ目の花火描画フラグを「真」にする
		mDrawFlag3 = true;
	}
	else if (clearCount >= time)
	{
		// 3つ目の花火描画フラグを「偽」にする
		mDrawFlag3 = false;
	}
}

/// <summary>
/// 描画
/// </summary>
void UIFireworks::Draw()
{
	int x, y;		// DrawExtendGraphを使う際に引数内を見やすくするために変数を作成
	// 1つ目の花火描画フラグが立ったら
	if (mDrawFlag)
	{
		// 描画ポジションの設定
		x = mDrawPosX - ADD_POS;
		y = mDrawPosY + ADD_POS;

		DrawExtendGraph(x, y, x + EXPANSION_X, y + EXPANSION_Y, fireworksImg, true);
	}
	// 2つ目の花火描画フラグが立ったら
	else if (mDrawFlag2)
	{
		// 描画ポジションの設定
		x = mDrawPosX + ADD_POS;
		y = mDrawPosY - ADD_POS;

		DrawExtendGraph(x, y, x + EXPANSION_X, y + EXPANSION_Y, fireworksImg2, true);
	}
	// 3つ目の花火描画フラグが立ったら
	else if (mDrawFlag3)
	{
		// 描画ポジションの設定
		x = mDrawPosX / 2;
		y = mDrawPosY / 2;

		DrawExtendGraph(x, y, x + EXPANSION3, y + EXPANSION3, fireworksImg3, true);
	}
}