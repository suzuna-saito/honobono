#include "Timing.h"
#include "DxLib.h"

Timing::Timing()
	: TimingFlag(false)
	, PerfectFlag(false)
	, GoodFlag(false)
	, BadFlag(false)
	, gageX(50)
	, gageY(350)
	, gageCX(100)
	, gageCY(400)
	, buttonX(80)
	, buttonY(385)
	, freamX(490)
	, freamY(180)
	, radius(radiusInit)
	, gageRadius(20)
	, radiusInit(70)
	, reactionX(520)
	, reactionY(200)
	, count(countInit)
	, countInit(0)
	, countMax(50)
{
	// 画像読み込み
	freamImg = LoadGraph("data/newUI/8688.png");
	selectButtonImg = LoadGraph("data/newUI/UIfish.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/bad.png");
	badImg = LoadGraph("data/newUI/good.png");

	// 色
	color = GetColor(0, 0, 0);
	gageColor = GetColor(255, 255, 255);
	
}

Timing::~Timing()
{
	// 画像データ削除
	DeleteGraph(selectButtonImg);
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);
}

void Timing::Update()
{
	// スペースキーを押したらタイミングフラグが「真」となる
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		TimingFlag = true;
	}
	// Ａキーを押したらボタンが左に動く
	if (CheckHitKey(KEY_INPUT_A))
	{
		// ゲージの1番左側に来たらこれ以上移動できない
		if (120 >= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX - 200;
		}
	}
	// Ｄキーを押したらボタンが右に動く
	if (CheckHitKey(KEY_INPUT_D))
	{
		// ゲージの1番右側に来たらこれ以上移動できない
		if(320 <= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX + 200;
		}
	}

}

void Timing::Draw()
{
	// リアクション判定のフレームの描画
	DrawGraph(freamX, freamY, freamImg, TRUE);

	for (int i = 0; i < 3; i++)
	{
		// パーフェクト判定の位置となるゲージの描画
		DrawCircle(gageCX + (i * 200), gageCY, gageRadius, gageColor, TRUE);

		// ボタンが押されていない場合ループし続ける
		if(!TimingFlag)
		{
			// 半径が０になるまで収縮させる
			if(radius > 0)
			{
				// 収縮するゲージの描画
				DrawCircle(gageCX + (i * 200), gageCY, radius--, color, FALSE);
			}
			else
			{
				// 半径の大きさを初期化
				radius = radiusInit;
			}
		}
		// ボタンを押されタイミングフラグが「真」となったら
		if(TimingFlag)
		{
			// カウントをし続ける
			count++;
			// カウントが最大値になるまで描画
			if (count < countMax)
			{
				// バッドのリアクションを描画する条件
				if (radius - gageRadius <= 25)
				{
					DrawGraph(reactionX, reactionY, badImg, TRUE);
				}
				// グッドのリアクションを描画する条件
				if (radius - gageRadius > 20)
				{
					DrawGraph(reactionX, reactionY, goodImg, TRUE);
				}
				// パーフェクトのリアクションを描画する条件
				if (radius - gageRadius <= 0 && radius - gageRadius < 10)
				{
					DrawGraph(reactionX, reactionY, perfectImg, TRUE);
				}

				for (int i = 0; i < 3; i++)
				{
					// ゲージが止まる
					DrawCircle(gageCX + (i * 200), gageCY, radius, color, FALSE);
				}
			}
			else
			{
				// それ以外の場合はタイミングフラグを「偽」とする
				TimingFlag = false;
			}
		}
		// タイミングフラグが「偽」であるとき
		if(!TimingFlag)
		{ 
			// カウントを初期化する
			count = countInit;
		}
	}


	// 魚（自分が選んでいる操作出来るところを示すもの）の描画
	DrawGraph(buttonX, buttonY, selectButtonImg, TRUE);
}

