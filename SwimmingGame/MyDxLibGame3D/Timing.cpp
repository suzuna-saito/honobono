// インクルード
#include "Timing.h"
#include "Input.h"
#include "Sound.h"
#include "Score.h"

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
	, buttonMoveRight(320)
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
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
	, mEffectAngle(0)
	, mEffectScale(1)
	, mEffectFlag(false)
	, mAngleRotate(15.0f * DX_PI_F / 180.0f)
	, mScalePlus(0.02)
	, mEffectImg(-1)
{
	// 画像読み込み
	freamImg = LoadGraph("data/newUI/frame.png");
	selectButtonImg = LoadGraph("data/newUI/UIfish.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/good.png");
	badImg = LoadGraph("data/newUI/bad.png");
	mPerfectEffectImg = LoadGraph("data/newUI/PerfectEffect.png");
	mGoodEffectImg = LoadGraph("data/newUI/GoodEffect.png");
	mBadEffectImg = LoadGraph("data/newUI/BadEffect.png");

	// 色
	color = GetColor(0, 0, 0);
	NormalGageColor = GetColor(255, 255, 255);
	mPushGageColor = GetColor(0, 255, 255);

	// サウンド
	mPerfectSound = new Sound("data/newSound/se/perfect.mp3");
	mGoodSound = new Sound("data/newSound/se/good.mp3");
	mBadSound = new Sound("data/newSound/se/bad.mp3");

	// スコア
	score = new Score();
}

// デストラクタ
Timing::~Timing()
{
	// 画像データ削除
	DeleteGraph(selectButtonImg);
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);

	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;
}

// 更新
void Timing::Update()
{
	UpdateKey();

	/* 今、まだ3つのゲージを別で描画できていないのでコメントアウトしてます */

	//// 左キーを押したらボタンが左に動く
	//if (Key[KEY_INPUT_LEFT] == 1)
	//{
	//	// ゲージの1番左側に来たらこれ以上移動できない
	//	if (buttonMoveLeft >= buttonX)
	//	{
	//		buttonX = buttonX;
	//	}
	//	else
	//	{
	//		buttonX = buttonX - movebutton;
	//	}
	//}
	//// 右キーを押したらボタンが右に動く
	//if (Key[KEY_INPUT_RIGHT] == 1)
	//{
	//	// ゲージの1番右側に来たらこれ以上移動できない
	//	if (buttonMoveRight <= buttonX)
	//	{
	//		buttonX = buttonX;
	//	}
	//	else
	//	{
	//		buttonX = buttonX + movebutton;
	//	}
	//}

	// スペースキーを押したらタイミングフラグが「真」となる
	if (Key[KEY_INPUT_SPACE] == 1)
	{
		TimingFlag = true;
		ScoreFlag = true;
	}
	// ボタンを押されタイミングフラグが「真」となったら
	if (TimingFlag)
	{
		// ボタンを押せた目印に色を変える
		mGageColor = mPushGageColor;
		// カウントをし続ける
		count++;
		// バッドの条件
		if (radius - gageRadius <= 25)
		{
			// エフェクト画像をバッドの画像に変える
			mEffectImg = mBadEffectImg;
			mEffectFlag = true;
			mBadSound->PlaySE();
			BadFlag = true;
		}
		// グッドの条件
		if (radius - gageRadius < 20)
		{
			// エフェクト画像をグッドの画像に変える
			mEffectImg = mGoodEffectImg;
			mEffectFlag = true;
			mGoodSound->PlaySE();
			GoodFlag = true;
		}
		// パーフェクトの条件
		if (radius - gageRadius <= 0 && radius - gageRadius < 10)
		{
			// エフェクト画像をパーフェクトの画像に変える
			mEffectImg = mPerfectEffectImg;
			mEffectFlag = true;
			mPerfectSound->PlaySE();
			PerfectFlag = true;
		}
		if (!(count < countMax))
		{
			if (ScoreFlag)
			{
				// スコアの計算
				// 半径の最大値から現在の半径を差を出し、その差にスコアくらいの数字を掛ける
				int n;
				n = radiusInit - radius;
				score->GetScore(&n);
				ScoreFlag = false;
			}
	
			// それ以外の場合はタイミングフラグを「偽」とする
			TimingFlag = false;
		}
	}
	// タイミングフラグが「偽」であるとき
	if (!TimingFlag)
	{
		mGageColor = NormalGageColor;
		// カウントを初期化する
		count = countInit;
		// フラグを「偽」にする
		BadFlag = false;
		GoodFlag = false;
		PerfectFlag = false;
		// エフェクトフラグと大きさを初期化
		mEffectFlag = false;
		mEffectScale = 1;
	}

	// エフェクトフラグが真なら大きさを拡大、回転させる
	if (mEffectFlag)
	{
		mEffectScale += mScalePlus;
		mEffectAngle += mAngleRotate;
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
		DrawCircle(gageCX + (1 * movebutton), gageCY, gageRadius, mGageColor, TRUE);

		// エフェクトフラグが真なら
		if (mEffectFlag)
		{
			// パーフェクト判定の位置の回りに出現させる
			DrawRotaGraph(gageCX + (1 * movebutton), gageCY, mEffectScale, mEffectAngle, mEffectImg, true, false, false);
		}

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

		// スコアを描画
		score->Draw();
	
	// 魚（自分が選んでいる操作出来るところを示すもの）の描画
	//DrawGraph(buttonX, buttonY, selectButtonImg, TRUE);
}

