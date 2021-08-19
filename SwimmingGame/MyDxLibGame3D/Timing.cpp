// インクルード
#include "Timing.h"

// コンストラクタ
Timing::Timing()
	: TimingFlag(false)
	, PerfectFlag(false)
	, GoodFlag(false)
	, BadFlag(false)
	, ScoreFlag(false)
	, gageX(50)
	, gageY(350)
	, gageCX(100)
	, gageCY(400)
	, buttonX(80)
	, buttonY(385)
	, buttonMoveLeft(120)
	, buttonMoveRight(120)
	, movebutton(200)
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
	, score(0)
	, scoreMax(0)
	, scoreX(800)
	, scoreY(20)
{
	// 画像読み込み
	freamImg = LoadGraph("data/newUI/frame.png");
	selectButtonImg = LoadGraph("data/newUI/UIfish.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/bad.png");
	badImg = LoadGraph("data/newUI/good.png");

	// 色
	color = GetColor(255, 0, 0);
	gageColor = GetColor(255, 255, 255);
	
}

// デストラクタ
Timing::~Timing()
{
	// 画像データ削除
	DeleteGraph(selectButtonImg);
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);
}

// 更新
void Timing::Update()
{
	// Ａキーを押したらボタンが左に動く
	if (CheckHitKey(KEY_INPUT_A))
	{
		// ゲージの1番左側に来たらこれ以上移動できない
		if (buttonMoveLeft >= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX - movebutton;
		}
	}
	// Ｄキーを押したらボタンが右に動く
	if (CheckHitKey(KEY_INPUT_D))
	{
		// ゲージの1番右側に来たらこれ以上移動できない
		if (320 <= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX + movebutton;
		}
	}

	// スペースキーを押したらタイミングフラグが「真」となる
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		TimingFlag = true;
	}
	// ボタンを押されタイミングフラグが「真」となったら
	if (TimingFlag)
	{
		// カウントをし続ける
		count++;
		// バッドの条件
		if (radius - gageRadius <= 25)
		{
			BadFlag = true;
		}
		// グッドの条件
		if (radius - gageRadius > 20)
		{
			GoodFlag = true;
		}
		// パーフェクトの条件
		if (radius - gageRadius <= 0 && radius - gageRadius < 10)
		{
			PerfectFlag = true;
		}
		if (!(count < countMax))
		{
			// スコアの計算
			// 半径の最大値から現在の半径を差を出して、その差にスコアくらいの数字を掛ける
			int n;
			n = radiusInit - radius;
			scoreMax = n * 10;
			score = scoreMax + score;
	
			// それ以外の場合はタイミングフラグを「偽」とする
			TimingFlag = false;
		}
	}
}

// 描画
void Timing::Draw()
{
	// リアクション判定のフレームの描画
	DrawGraph(freamX, freamY, freamImg, TRUE);

	/*for (int i = 0; i < 3; i++)
	{*/
		// パーフェクト判定の位置となるゲージの描画
		DrawCircle(gageCX + (1 * movebutton), gageCY, gageRadius, gageColor, TRUE);

		// ボタンが押されていない場合ループし続ける
		if(!TimingFlag)
		{
			// 半径が０になるまで収縮させる
			if(radius > 0)
			{
				// 収縮するゲージの描画
				DrawCircle(gageCX + (1 * movebutton), gageCY, radius--, color, FALSE);
			}
			else
			{
				// 半径の大きさを初期化
				radius = radiusInit;
			}
		}
		if (TimingFlag)
		{
			// カウントが最大値になるまで描画
			if (count < countMax)
			{
				// バッドフラグが立ったら描画する
				if (BadFlag)
				{
					DrawGraph(reactionX, reactionY, badImg, TRUE);
				}
				// グッドフラグが立ったら描画する
				if (GoodFlag)
				{
					DrawGraph(reactionX, reactionY, goodImg, TRUE);

				}
				// パーフェクトフラグが立ったら描画する
				if (PerfectFlag)
				{
					DrawGraph(reactionX, reactionY, perfectImg, TRUE);
				}

				// ゲージを止める
				DrawCircle(gageCX + (1 * movebutton), gageCY, radius, color, FALSE);
			}
		}

		// タイミングフラグが「偽」であるとき
		if(!TimingFlag)
		{ 
			// カウントを初期化する
			count = countInit;
			// フラグを「偽」にする
			BadFlag = false;
			GoodFlag = false;
			PerfectFlag = false;
		}
	
	// スコアの画面を表示する
	DrawFormatString(scoreX, scoreY, gageColor, "score : %d", score);
	// 魚（自分が選んでいる操作出来るところを示すもの）の描画
	DrawGraph(buttonX, buttonY, selectButtonImg, TRUE);
}

