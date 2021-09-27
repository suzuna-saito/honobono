// インクルード
#include "Timing.h"
#include "Input.h"
#include "Sound.h"
#include "Time.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Timing::Timing()
	: mTimingDrawFlag(false)
	, mTimingFlag(false)
	, mReactionFlag(true)
	, mScoreFlag(false)
	, mScoreRadius(0)
	, mScorePlus(1)
	, mGageX(50)
	, mGageY(350)
	, mGageCX(0)
	, mGageCY(0)
	, mRightGagePosX(1160)
	, mRightGagePosY(830)
	, mLeftGagePosX(760)
	, mLeftGagePosY(830)
	, mFreamX(490)
	, mFreamY(180)
	, mRadius(0)
	, mGageRadius(20)
	, mRadiusInit(0)
	, mMaxRadius(75)
	, mPerfectSize(0.40f)
	, mBadSize(0.70f)
	, mReactionX(520)
	, mReactionY(200)
	, mReactionCount(0)
	, mCountInit(0)
	, mReactionCountMax(30)
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
	, mCsvData(0)
	, mFilePointer(NULL)
	, mEffectPosY(100)
	, mEffectAngle(0)
	, mEffectScale(1)
	, mEffectFlag(false)
	, mAngleRotate(15.0f * DX_PI_F / 180.0f)
	, mScalePlus(0.02)
	, mEffectImg(-1)
	, mJudgeImg(-1)
	, mCount(0)
	, mBaseTimePoint(100)
	, mBaseTime(30)
	, mTimeCount(0)
	, mNotesStartTime(160)
	, mNotesEndTime(18)
	, mJudge(none)
	, mFrameSize(1)
	, mFrameShrinkPoint(0.0010f)
	, mFrameShrinkGage(0.250f)
	, mFrameSizeInit(1)
	, mFrameMoveInit(0.010f)
	, mFrameMovePoint(0.010f)
	, mBaseGagePoint(1)
	, mDifficultyCount()
	, mNoteCount(0)
	, mNoteTime{30, 30, 30,250,100,90,80,10,10,10,10,10,10,10,40,60,80,80}
	, END_TIME(1700)
	, DIFFICULT_TIME(1150)
	, NOTE_NUM(18)
{
	// 画像読み込み
	mTimingImg[0] = LoadGraph("data/newUI/RightTiming.png");      // 右
	mTimingImg[1] = LoadGraph("data/newUI/LeftTiming.png");       // 左
	mFreamImg = LoadGraph("data/newUI/frame2.png");
	mPerfectImg = LoadGraph("data/newUI/Perfect.png");
	mGoodImg = LoadGraph("data/newUI/Good.png");
	mBadImg = LoadGraph("data/newUI/Bad.png");
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

	fopen_s(&mFilePointer, "data/csv/bgm_1.csv", "r");
	CSVRead();

}


//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Timing::~Timing()
{
	for (i = 0; i < 2; i++)
	{
		DeleteGraph(mTimingImg[i]);
	}
	DeleteGraph(mFreamImg);
	DeleteGraph(mPerfectImg);
	DeleteGraph(mGoodImg);
	DeleteGraph(mBadImg);
	DeleteGraph(mPerfectEffectImg);
	DeleteGraph(mGoodEffectImg);
	DeleteGraph(mBadEffectImg);

	// サウンドデータの削除
	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;
}


//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Timing::Update(bool _sound,int _nowScene)
{
	// 判定
	mJudge = none;

	// 曲の経過時間をカウント
	mTimeCount++;


	// 今のシーンがプレイだったらゲージを早くする処理をする
	switch (_nowScene)
	{
	case 2:      // 練習の時一定のリズムで出るようにする
		mNoteCount = 0;

		// 円が出現するまでの時間をカウント
		mCount++;
		// カウントを減らしていく
		mDifficultyCount++;

		break;

	case 3:      // プレイ

		// 急に始まらないようスタート時間まで待ってからスタート
		if (mTimeCount > mNotesStartTime && mNoteCount != NOTE_NUM)
		{
			// 円が出現するまでの時間をカウント
			mCount++;
			// カウントを減らしていく
			mDifficultyCount++;
		}

		// 終盤だったらゲージを出す速さ,ゲージが縮む速さを少し早くする
		if (mDifficultyCount >= DIFFICULT_TIME && mDifficultyCount < END_TIME)
		{
			// だんだん縮む速さを上げる
			mFrameShrinkPoint = 0.0020f;
		}
		// サビだったらゲージを出す速さ,ゲージが縮む速さを割と早くする
		else if (mDifficultyCount >= END_TIME)
		{
			mFrameShrinkPoint = 0.00150f;
		}

		break;
	}

	// 次のノーツを格納するときが来たら
	if (mCount == mNoteTime[mNoteCount])
	{
		mTimingDrawFlag = true;
		// フレームを出す場所は右か左かを決める
		mImgDirection = GetRand(mBaseGagePoint);

		// 右か左のゲージにフレームやエフェクトの位置を合わせる
		// 右
		if (!mImgDirection)
		{
			mGageCX = mRightGagePosX;
			mGageCY = mRightGagePosY;
		}
		// 左
		else
		{
			mGageCX = mLeftGagePosX;
			mGageCY = mLeftGagePosY;
		}
	}

	// スコアフラグを「偽」にする
	mScoreFlag = false;

	// ゲージが描画されるフラグが立ったら
	if (mTimingDrawFlag)
	{
		// 左右キーとフレームの場所が合っていたらを押したらタイミングフラグ、スコアフラグが「真」となる
		if (Key[KEY_INPUT_LEFT] == 1 && mImgDirection || Key[KEY_INPUT_RIGHT] == 1 && !mImgDirection)
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
				// 判定はフレームのサイズで行っている
				// バッドの条件
				if (mFrameSize > mBadSize)
				{
					// エフェクト画像をバッドエフェクトにする
					mEffectImg = mBadEffectImg;
					// エフェクトフラグを「真」にする
					mEffectFlag = true;
					// バッドの効果音を流す
					mBadSound->PlaySE();
					// 判定画像の変数にバッドの画像を格納
					mJudgeImg = mBadImg;
					// 他にリアクションを判定しない
					mReactionFlag = false;

					// bad判定
					mJudge = bad;
				}
				// グッドの条件
				else if (mFrameSize > mPerfectSize && mFrameSize < mBadSize)
				{
					// エフェクト画像をグッドエフェクトにする
					mEffectImg = mGoodEffectImg;
					// エフェクトフラグを「真」にする
					mEffectFlag = true;
					// グッドの効果音を流す
					mGoodSound->PlaySE();
					// 判定画像の変数にグッドの画像を格納
					mJudgeImg = mGoodImg;
					// 他にリアクションを判定しない
					mReactionFlag = false;
					// good判定
					mJudge = good;
				}
				// パーフェクトの条件
				else if (mFrameSize < mPerfectSize)
				{
					// エフェクト画像をパーフェクトエフェクトにする
					mEffectImg = mPerfectEffectImg;
					// エフェクトフラグを「真」にする
					mEffectFlag = true;
					// パーフェクトの効果音を流す
					mPerfectSound->PlaySE();
					// 判定画像の変数にパーフェクトの画像を格納
					mJudgeImg = mPerfectImg;
					// 他にリアクションを判定しない
					mReactionFlag = false;

					// perfect判定
					mJudge = perfect;
				}
			}
			// タイミングフラグが「偽」であり、フレームサイズの最低値を超えたら
			else if (!mTimingFlag && mFrameSize < mFrameShrinkGage)
			{
				// エフェクト画像をバッドエフェクトにする
				mEffectImg = mBadEffectImg;
				// エフェクトフラグを「真」にする
				mEffectFlag = true;
				// バッドの効果音を流す
				mBadSound->PlaySE();
				// 判定画像の変数にバッドの画像を格納
				mJudgeImg = mBadImg;
				// 他にリアクションを判定しない
				mReactionFlag = false;
				// 何も押されなかった判定
				mJudge = notDone;
			}
		}

		// リアクションカウントが最大値ではないとき
		//if (!(mReactionCount < mReactionCountMax))
		//{

		// スコアを入れられるなら
		if (mScoreFlag)
		{
			// バッドまたは何もしていないだったら
			if (mJudge == bad || mJudge == notDone || mJudge == none)
			{
				// スコアの割合を0にする
				mScoreRadius = 0;
				// スコアの加算倍率を元に戻す
				mScorePlus = 1;
			}
			// パーフェクトだったら
			else if(mJudge == perfect)
			{
				// スコアの割合を100にする
				mScoreRadius = 100 * mScorePlus;
				// スコアの加算倍率を0.2増やす
				mScorePlus += 0.20f;
			}
			// グッドだったら
			else if (mJudge == good)
			{
				// スコアの割合を50にする
				mScoreRadius = 50 * mScorePlus;
				// スコアの加算倍率を0.1増やす
				mScorePlus += 0.10f;
			}
		}
		//}
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
			// 判定はバッドではない
			mJudge = none;
			// ノーツの次時間を格納できる
			if (mNoteCount < NOTE_NUM)
			{
				mNoteCount++;
			}
			// ノーツまでのカウントを初期化
			mCount = mCountInit;

			// フレームサイズを初期化
			mFrameSize = mFrameSizeInit;
			// フレームが動く値を初期化
			mFrameMovePoint = mFrameMoveInit;
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
	// タイミングゲージを描画するフラグが「真」となったら
	if (mTimingDrawFlag)
	{
		if (!mTimingFlag)
		{
			if (mFrameSize > mFrameShrinkGage)
			{
				// パーフェクト判定の位置となるゲージの描画
				/*DrawRotaGraph(mGageCX, mGageCY, 1, 0, mTimingImg[mImgDirection], true, false, false);*/

				// 拡大するゲージの描画
				/*DrawCircle(mGageCX, mGageCY, mRadius++, mBrack, FALSE, 2);*/

				// フレームを一瞬拡大して縮小する処理
				mFrameMovePoint -= mFrameShrinkPoint;
				mFrameSize += mFrameMovePoint;
				// フレームを描画
				DrawRotaGraph(mGageCX, mGageCY, (double)mFrameSize, 0, mFreamImg, true, false, false);
			}
		}
	}

	// 右と左のゲージ画像を描画
	DrawRotaGraph(mRightGagePosX, mRightGagePosY, 1, 0, mTimingImg[0], true, false, false);
	DrawRotaGraph(mLeftGagePosX, mLeftGagePosY, 1, 0, mTimingImg[1], true, false, false);

	/*DrawFormatString(200, 200, mWhite, "%d", mRadius);*/

	// エフェクトのフラグが「真」のとき
	if (mEffectFlag)
	{
		DrawRotaGraph(mGageCX, mGageCY, mEffectScale, mEffectAngle, mEffectImg, true, false, false);
	}

	// 判定画像を描画していなかったら
	if (!mReactionFlag)
	{
		// 描画
		DrawRotaGraph(mGageCX, mGageCY - mEffectPosY, 1, 0, mJudgeImg, true, false, false);
	}
	// 再生されている音楽の時間の確認（デバッグ用）
	//DrawFormatString(0, 300, mWhite, "Time:%d", mNoteTime[mNoteCount]);
}


//-----------------------------------------------------------------------------
// @brief  CSVデータの読み込み.
//-----------------------------------------------------------------------------
void Timing::CSVRead()
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

void Timing::Init()
{
	mTimingDrawFlag = false;
	mEffectFlag = false;
	mReactionFlag = true;
}
