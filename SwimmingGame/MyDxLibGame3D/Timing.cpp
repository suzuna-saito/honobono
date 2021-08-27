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
	, freamX(490)
	, freamY(180)
	, radius(70)
	, gageRadius(20)
	, radiusInit(70)
	, perfectRadius(5)
	, badRadius(20)
	, reactionX(520)
	, reactionY(200)
	, reactionCount(0)
	, countInit(0)
	, reactionCountMax(50)
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
	, csvData(0)
	, filePointer(NULL)
	, mEffectAngle(0)
	, mEffectScale(1)
	, mEffectFlag(false)
	, mAngleRotate(15.0f * DX_PI_F / 180.0f)
	, mScalePlus(0.02)
	, mEffectImg(-1)
{
	// 画像読み込み
	freamImg = LoadGraph("data/newUI/frame.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/good.png");
	badImg = LoadGraph("data/newUI/bad.png");
	goodImg = LoadGraph("data/newUI/good.png");
	badImg = LoadGraph("data/newUI/bad.png");
	mPerfectEffectImg = LoadGraph("data/newUI/PerfectEffect.png");
	mGoodEffectImg = LoadGraph("data/newUI/GoodEffect.png");
	mBadEffectImg = LoadGraph("data/newUI/BadEffect.png");

	// 色
	 brack = GetColor(0, 0, 0);
	 white = GetColor(255, 255, 255);

	// サウンドのロード
	mPerfectSound = new Sound("data/newSound/se/perfect.mp3");
	mGoodSound = new Sound("data/newSound/se/good.mp3");
	mBadSound = new Sound("data/newSound/se/bad.mp3");	

	mScorePtr = new Score();
}

// デストラクタ
Timing::~Timing()
{
	// 画像データ削除
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);

	// サウンドデータの削除
	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;
}

// 更新
void Timing::Update()
{
	UpdateKey();

	// スペースキーを押したらタイミングフラグが「真」となる
	if (Key[KEY_INPUT_SPACE] == 1)
	{
		TimingFlag = true;
		ScoreFlag = true;
	}
	// ボタンを押されタイミングフラグが「真」となったら
	if (TimingFlag)
	{
		// カウントをし続ける
		reactionCount++;
		// バッドの条件
		if (radius - gageRadius > badRadius)
		{
			mEffectImg = mBadEffectImg;
			mEffectFlag = true;
			// バッドの効果音を流す
			mBadSound->PlaySE();
			// バッドフラグを「真」にする
			BadFlag = true;
		}
		// グッドの条件
		else if (radius - gageRadius >= perfectRadius && radius - gageRadius <= badRadius)
		{
			mEffectImg = mGoodEffectImg;
			mEffectFlag = true;
			// グッドの効果音を流す
			mGoodSound->PlaySE();
			// グッドフラグを「真」にする
			GoodFlag = true;
		}
		// パーフェクトの条件
		else if (radius - gageRadius < perfectRadius)
		{
			mEffectImg = mPerfectEffectImg;
			mEffectFlag = true;
			// パーフェクトの効果音を流す
			mPerfectSound->PlaySE();
			// パーフェクトフラグを「真」にする
			PerfectFlag = true;
		}
		// リアクションカウントが最大値ではないとき
		if (!(reactionCount < reactionCountMax))
		{
			// スコアの計算
			if (ScoreFlag)
			{
				int n;
				n = radiusInit - radius;
				mScorePtr->GetScore(&n);
				ScoreFlag = false;
			}
			// それ以外の場合はタイミングフラグを「偽」とする
			TimingFlag = false;
		}
	}
	// タイミングフラグが「偽」であるとき
	if (!TimingFlag)
	{
		// カウントを初期化する
		reactionCount = countInit;
		// フラグを「偽」にする
		BadFlag = false;
		GoodFlag = false;
		PerfectFlag = false;

		mEffectFlag = false;
		mEffectScale = 1;
	}
	// エフェクトのフラグが「真」のとき
	if (mEffectFlag)
	{
		// エフェクトを大きくさせながら回転させる
		mEffectScale += mScalePlus;
		mEffectAngle += mAngleRotate;
	}
}

// 描画
void Timing::Draw()
{
	// リアクション判定のフレームの描画
	DrawGraph(freamX, freamY, freamImg, TRUE);

	// パーフェクト判定の位置となるゲージの描画
	DrawCircle(gageCX, gageCY, gageRadius, white, TRUE);

	// エフェクトのフラグが「真」のとき
	if (mEffectFlag)
	{
		DrawRotaGraph(gageCX, gageCY, mEffectScale, mEffectAngle, mEffectImg, true, false, false);
	}

	// ボタンが押されていない場合ループし続ける
	if (!TimingFlag)
	{
		// 半径が０になるまで収縮
		if (radius > 0)
		{
			// 収縮するゲージの描画
			DrawCircle(gageCX, gageCY, radius--, brack, FALSE);
		}
		else
		{
			// 半径の大きさを初期化
			radius = radiusInit;
		}
	}
	// ボタンが押されたら
	if (TimingFlag)
	{
		// カウントが最大値になるまで描画
		if (reactionCount < reactionCountMax)
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
			DrawCircle(gageCX, gageCY, radius, brack, FALSE);
		}
	}
	else
	{
		// ゲージを表示しない
	}
	// スコアを描画
	mScorePtr->Draw();
}

void Timing ::CSVRead()
{
	// ファイルポインターがNULLの時デバッグをやめる
	if (filePointer == NULL)
	{
		//デバッグ中止
		DebugBreak();
	}
	// ファイルの中の数値を読み込む
	while ((csvData = fgetc(filePointer)) != EOF)
	{
		// BGMが再生された時間とCSVの中の数値が同じ時に
		//    ゲージがパーフェクトの位置にいるようにしたい
	}

	// ファイルを閉じる
	fclose(filePointer);
}