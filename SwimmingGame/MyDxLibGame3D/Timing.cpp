// インクルード
#include "Timing.h"
#include "Input.h"
#include "Sound.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Timing::Timing()
	: mTimingDrawFlag(false)
	, mTimingFlag(false)
	, mReactionFlag(true)
	, mScoreFlag(false)
	, mScoreRadius(0)
	, mGageX(50)
	, mGageY(350)
	, mGageCX(100)
	, mGageCY(400)
	, mFreamX(490)
	, mFreamY(180)
	, mRadius(70)
	, mGageRadius(20)
	, mRadiusInit(70)
	, mPerfectRadius(5)
	, mBadRadius(20)
	, mReactionX(520)
	, mReactionY(200)
	, mReactionCount(0)
	, mCountInit(0)
	, mReactionCountMax(50)
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
	, mCsvData(0)
	, mFilePointer(NULL)
	, mEffectAngle(0)
	, mEffectScale(1)
	, mEffectFlag(false)
	, mAngleRotate(15.0f * DX_PI_F / 180.0f)
	, mScalePlus(0.02)
	, mEffectImg(-1)
	, mCount(0.0f)
{
	// 画像読み込み
	mFreamImg = LoadGraph("data/newUI/frame.png");
	mPerfectEffectImg = LoadGraph("data/newUI/PerfectEffect.png");
	mGoodEffectImg = LoadGraph("data/newUI/GoodEffect.png");
	mBadEffectImg = LoadGraph("data/newUI/BadEffect.png");

	// 色
	 mBrack = GetColor(0, 0, 0);
	 mWhite = GetColor(255, 255, 255);

	// サウンドのロード
	mPerfectSound = new Sound("data/newSound/se/perfect.mp3");
	mGoodSound = new Sound("data/newSound/se/good.mp3");
	mBadSound = new Sound("data/newSound/se/bad.mp3");	

	fopen_s(&mFilePointer, "data/csv/bgm_1.csv","r");
	CSVRead();
}


//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Timing::~Timing()
{
	// サウンドデータの削除
	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;
}


//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Timing::Update()
{
	// カウント
	mCount++;
	// 
	mCountPack = mCount / 1000;

	// 
	if (mCountPack == mRhythm[i])
	{
		// タイミングゲージ描画フラグを「真」にする
		mTimingDrawFlag = true;
	}

	UpdateKey();

	// スコアフラグを「偽」にする
	mScoreFlag = false;

	// ゲージが描画されるフラグが立ったら
	if (mTimingDrawFlag)
	{
		// スペースキーを押したらタイミングフラグ、スコアフラグが「真」となる
		if (Key[KEY_INPUT_SPACE] == 1)
		{
			mTimingFlag = true;
			mScoreFlag = true;
		}
		if (!mReactionFlag)
		{
			// カウントをし続ける
			mReactionCount++;
		}
		if (mReactionFlag)
		{
			// ボタンを押されタイミングフラグが「真」となったら
			if (mTimingFlag)
			{
				// バッドの条件
				if (mRadius - mGageRadius > mBadRadius)
				{
					// エフェクト画像をバッドエフェクトにする
					mEffectImg = mBadEffectImg;
					// エフェクトフラグを「真」にする
					mEffectFlag = true;
					// バッドの効果音を流す
					mBadSound->PlaySE();
					// 他にリアクションを判定しない
					mReactionFlag = false;
				}
				// グッドの条件
				if (mRadius - mGageRadius >= mPerfectRadius && mRadius - mGageRadius <= mBadRadius)
				{
					// エフェクト画像をグッドエフェクトにする
					mEffectImg = mGoodEffectImg;
					// エフェクトフラグを「真」にする
					mEffectFlag = true;
					// グッドの効果音を流す
					mGoodSound->PlaySE();
					// 他にリアクションを判定しない
					mReactionFlag = false;
				}
				// パーフェクトの条件
				if (mRadius - mGageRadius < mPerfectRadius)
				{
					// エフェクト画像をパーフェクトエフェクトにする
					mEffectImg = mPerfectEffectImg;
					// エフェクトフラグを「真」にする
					mEffectFlag = true;
					// パーフェクトの効果音を流す
					mPerfectSound->PlaySE();
					// 他にリアクションを判定しない
					mReactionFlag = false;
				}
			}
			// タイミングフラグが「偽」であり、ゲージの半径が０になったら
			else if (!mTimingFlag && mRadius == 0)
			{
				// エフェクト画像をバッドエフェクトにする
				mEffectImg = mBadEffectImg;
				// エフェクトフラグを「真」にする
				mEffectFlag = true;
				// バッドの効果音を流す
				mBadSound->PlaySE();
				// 他にリアクションを判定しない
				mReactionFlag = false;
			}
		}
		
		// リアクションカウントが最大値ではないとき
		//if (!(mReactionCount < mReactionCountMax))
		{
			if (mScoreFlag)
			{
				// 
				mScoreRadius = mRadiusInit - mRadius;
			}
		}
		// リアクションカウントが最大値を超えたら
		if (mReactionCount == mReactionCountMax)
		{
			// タイミングフラグを「偽」とする
			mTimingFlag = false;
			// タイミングゲージを描画しない
			mTimingDrawFlag = false;
			// 次のゲージ用
			i++;
			// リアクションを判定できるようにする
			mReactionFlag = true;
		}
		// エフェクトのフラグが「真」のとき
		if (mEffectFlag)
		{
			// エフェクトを大きくさせながら回転させる
			mEffectScale += mScalePlus;
			mEffectAngle += mAngleRotate;
		}
	}

	// ゲージが描画されるフラグが「偽」であったら
	if (!mTimingDrawFlag)
	{
		// 初期化
		mRadius = mRadiusInit;
		mReactionCount = mCountInit;
		mEffectScale = 1;

		// フラグを「偽」にする
		mTimingFlag = false;
		mEffectFlag = false;
	}
}


//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Timing::Draw()
{
	// パーフェクト判定の位置となるゲージの描画
	DrawCircle(mGageCX, mGageCY, mGageRadius, mWhite, TRUE);

	// タイミングゲージを描画するフラグが「真」となったら
	if (mTimingDrawFlag)
	{
		if (!mTimingFlag)
		{
			// 半径が０になるまで収縮
			if (mRadius > 0)
			{
				// 収縮するゲージの描画
				DrawCircle(mGageCX, mGageCY, mRadius--, mBrack, FALSE, 2);
			}
		}
	}
	
	// エフェクトのフラグが「真」のとき
	if (mEffectFlag)
	{
		DrawRotaGraph(mGageCX, mGageCY, mEffectScale, mEffectAngle, mEffectImg, true, false, false);
	}
	// 再生されている音楽の時間の確認（デバッグ用）
	DrawFormatString(0, 30, mWhite, "Time:%f", mCountPack);
}


//-----------------------------------------------------------------------------
// @brief  CSVデータの読み込み.
//-----------------------------------------------------------------------------
void Timing ::CSVRead()
{
	// ファイルポインターがNULLの時デバッグをやめる
	if (mFilePointer == NULL)
	{
		//デバッグ中止
		DebugBreak();
	}
	//memset関数でメモリにbufferをセットし、sizeof演算子で要素数を決める
	memset(mBuffer, 0, sizeof(mBuffer));

	while (1)
	{
		while (1)
		{
			// fgetc関数でfilepointerから文字を読んでcsvDataに格納
			mCsvData = fgetc(mFilePointer);
			if (mCsvData == EOF)
			{
				// EndOfFileを検出して
				mEofFlag = true;
				// ループを抜ける
				break;
			}
			//区切りか改行でなければ
			if (mCsvData != ',' && mCsvData != '\n')
			{
				//strcat_s関数でbufferに連結し、const char関数で書き換える
				strcat_s(mBuffer, (const char*)&mCsvData);
			}
			else
			{
				// atof関数でbufferをfloat型に直して、ローカル変数numに代入
				mNum = atof(mBuffer);
				mRhythm[mRawNum] = mNum;
				////////////////////////////////
				// numに目的の数字が入ったので何かする
				// num番目のチップ画像のハンドルを取得
				//cell[columnNum][rawNum] = num;
				////////////////////////////////
				// 
				// bufferをリセット
				memset(mBuffer, 0, sizeof(mBuffer));
				// 区切りか改行なのでループを抜ける
				break;
			}
		}
		// 1マップ分になったら
		if (mEofFlag)
		{
			// ループを抜ける
			break;
		}
		// 区切りを検出したら
		if (mCsvData == ',')
		{
			// 列の数を増やす
			//columnNum++;
		}
		// 改行だったら
		if (mCsvData == '\n')
		{
			// 行を増やす
			mRawNum++;
			// 列を0にする
			mColumnNum = 0;
		}
	}
	// ファイルを閉じる
	fclose(mFilePointer);
}