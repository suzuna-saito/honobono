#include "Training.h"
#include "Pool.h"
#include "Camera.h"
#include "Play.h"
#include "BackGround.h"
#include "Sound.h"
#include "Common.h"
#include "Fish.h"
#include "Timing.h"
#include "Input.h"

// 定数
const int TRAINING_POS_X = 155;  // 練習中のテキスト座標X
const int TRAINING_POS_Y = 50;  // 練習中のテキスト座標Y

const int SKIP_TIME = 50;    // スキップテキストを描画し始める時間
const int SKIP_POS_X = 150;   // スキップテキスト座標X
const int SKIP_POS_Y = 130;  // スキップテキスト座標Y

const int ARROW_POS_X = 1400;
const int ARROW_POS_Y = 120;

const int TEXT_POS_X = 440;
const int TEXT_POS_Y = 220;

const int FIRST_TIME = 50;  // 最初のセリフだけ少し出す時間を早くするための初期値
const int NEXT_TIME = 100;  // 次のセリフを出す時間

const int MAX = 5;          // リアクションの数
const int GOOD_MAX = 2;
const int BAD_MAX = 1;

// コンストラクタ
Training::Training()
	: mPlayBGM1(nullptr)
	, mModelHandle(-1)
	, mPos(VGet(0.0f, 5.9f, 0.0f))
	, mRot(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, mDance(VGet(0.0f, 0.0f, 0.0))
	, mTime(FIRST_TIME)
	, mFirstDrawFlag(true)
	, mSkipDrawFlag(false)
	, mPlayDrawFlag(false)
	, mEndDrawFlag(false)
	, mFastForwardDrawFlag(true)
	, mNowDia(zero)
	, mDrawDia(0)
	, mDrawReaction(0)
	, mPerfectCount(0)
{
	SetScene(training);

	mModelHandle = MV1LoadModel("data/model/fish/player02.mv1");
	// 魚生成
	fish = new Fish(mModelHandle, mPos, mRot, mDance);

	// プール生成
	pool = new Pool();

	// リズムボタンUI生成
	timing = new Timing();

	// 背景の生成
	backGround = new BackGround();

	// カメラの生成
	camera = new Camera();
	camera->TrainingCameraUpdate();
	camera->CameraSet();


	// サウンドの生成
	mPlayBGM1 = new Sound("data/newSound/bgm/kari.mp3");

	// テキスト画像のロード
	mTrainingText = LoadGraph("data/model/TrainingAsset/TrainingText.png");
	mSkipText = LoadGraph("data/model/TutorialAsset/skipText.png");
	mFastForward = LoadGraph("data/model/TrainingAsset/FastForward.png");
	mNowFastForward = LoadGraph("data/model/TrainingAsset/NowFastForward.png");
	mArrow = LoadGraph("data/model/TrainingAsset/Arrow.png");
}

// デストラクタ
Training::~Training()
{
	// 魚削除
	delete fish;
	// プール削除
	delete pool;
	// リズムボタンUI削除
	delete timing;
	// 背景の削除
	delete(backGround);

	// サウンドの停止、削除
	mPlayBGM1->StopMusic();
	delete mPlayBGM1;

	// 画像の削除
	DeleteGraph(mTrainingText);
	DeleteGraph(mSkipText);
	DeleteGraph(mDrawDia);
	DeleteGraph(mDrawReaction);
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Training::Update()
{

	UpdateKey();

	// 音楽の再生
	mPlayBGM1->PlayBackBGM();


	mTime++;

	if (mNowDia == skipEnd || mNowDia == playEnd)
	{
		mPlayBGM1->StopMusic();

		return new Play();
	}

	// スキップする?
	if (mNowDia == stop)
	{
		// スキップの文字が描画されているときにスペースが押されたら
		if (Key[KEY_INPUT_SPACE] == 1)
		{
			timing->Init();

			// スキップ時のセリフが出るように設定する
			mNowDia = skipZero;

			mPlayDrawFlag = false;
			mSkipDrawFlag = true;

			mTime = FIRST_TIME;
		}
	}

	// 早送り
	if ((mNowDia != stop && mPerfectCount != 5) || (mNowDia >= endOne && mPerfectCount == 5))
	{
		mFastForwardDrawFlag = true;

		// →キーが押されたら早送りフラグを
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			mFastForwardDrawFlag = false;

			mTime += 10;
		}
	}


	// セリフが全て描画されたら
	if (mNowDia == stop)
	{
		mPlayDrawFlag = true;

		// リズムボタンUI更新
		timing->Update(1, GetScene());
	}


	// perfectを5回取ったら
	if (mPerfectCount == 5 && mNowDia == stop)
	{
		timing->Init();
		// シーン遷移前のセリフが出るように設定する
		mNowDia = endZero;

		mPlayDrawFlag = false;
		mEndDrawFlag = true;
		mTime = FIRST_TIME+20;
	}

	// 魚の更新
	fish->Updata(timing->GetJudg(), false, GetScene());

	// 最初のセリフたち
	if (mFirstDrawFlag && mTime >= NEXT_TIME)
	{
		switch (mNowDia)
		{
		case zero:
			mNowDia = one;
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue01.png");
			break;
		case one:
			mNowDia = two;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue02.png");
			break;
		case two:
			mNowDia = three;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue03.png");
			break;
		case three:
			mNowDia = four;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue04.png");
			break;
		case four:
			mNowDia = five;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue05.png");
			break;
		case five:
			mNowDia = six;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue06.png");
			break;
		case six:
			mNowDia = stop;
			DeleteGraph(mDrawDia);
			mFirstDrawFlag = false;
			break;
		default:
			break;
		}

		mTime = 0;
	}


	// スキップされたとき
	if (mSkipDrawFlag && mTime >= NEXT_TIME)
	{
		switch (mNowDia)
		{
		case skipZero:
			mNowDia = skipOne;
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip01.png");
			break;
		case skipOne:
			mNowDia = skipTwo;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip02.png");
			break;
		case skipTwo:
			mNowDia = skipThree;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip03.png");
			break;
		case skipThree:
			mNowDia = skipFour;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip04.png");
			break;
		case skipFour:
			mNowDia = skipFive;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip05.png");
			break;
		case skipFive:
			mNowDia = skipEnd;
			DeleteGraph(mDrawDia);
			break;
		default:
			break;
		}
		
		mTime = 0;
	}

	// プレイ中のリアクション
	if (mPlayDrawFlag)
	{
		switch (timing->GetJudg())    // 判定が
		{
		case 2:                       // perfectだったら
			mDrawReaction = GetRand(MAX);             // ランダムでリアクションを表示

			switch (mDrawReaction)
			{
			case successOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success01.png");
				break;
			case successTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success02.png");
				break;
			case successThree:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success03.png");
				break;
			case successFour:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success04.png");
				break;
			case successFive:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success05.png");
				break;
			case successSix:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success06.png");
				break;
			default:
				break;
			}
			// perfectのカウントを1プラスする
			mPerfectCount++;
			break;
		case 1:                  // goodだったら
			mDrawReaction = GetRand(GOOD_MAX);             // ランダムでリアクションを表示

			switch (mDrawReaction)
			{
			case goodOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Good01.png");
				break;
			case goodTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Good02.png");
				break;
			case goodThree:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad01.png");
				break;
			default:
				break;
			}
			break;
		case 0:                  // badだったら
			mDrawReaction = GetRand(BAD_MAX);             // ランダムでリアクションを表示

			switch (mDrawReaction)
			{
			case badOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad01.png");
				break;
			case badTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad02.png");
				break;
			default:
				break;
			}
			break;
		case 3:          // 何も押されていなかったら
			mDrawReaction = GetRand(BAD_MAX);             // ランダムでリアクションを表示

			switch (mDrawReaction)
			{
			case badOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Not01.png");
				break;
			case badTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad02.png");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		mTime = 0;
	}
	

	// perfectを5回取った時のセリフ
	if (mEndDrawFlag && mTime >= NEXT_TIME)
	{
		switch (mNowDia)
		{
		case endZero:
			DeleteGraph(mDrawReaction);
			mNowDia = endOne;
			DeleteGraph(mDrawDia);
			mTime = FIRST_TIME;
			break;
		case endOne:
			mNowDia = endTwo;
			DeleteGraph(mDrawReaction);
			mDrawDia = LoadGraph("data/model/TrainingAsset/End01.png");
			mTime = 30;
			break;
		case endTwo:
			mNowDia = endThree;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/End02.png");
			break;
		case endThree:
			mNowDia = endFour;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/End03.png");
			break;
		case endFour:
			mNowDia = playEnd;
			DeleteGraph(mDrawDia);
			break;
		default:
			break;
		}

		mTime = 0;
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Training::Draw()
{
	// 背景の生成
	backGround->Draw();
	// 魚描画
	fish->Draw(0);
	// プール描画
	pool->Draw();
	// リズムボタンUI描画
	timing->Draw();

	// 練習中という文字描画
	DrawGraph(TRAINING_POS_X, TRAINING_POS_Y, mTrainingText, TRUE);

	// 描画するセリフがあるとき
	if (mNowDia != stop)
	{
		// セリフの描画
		DrawGraph(TEXT_POS_X, TEXT_POS_Y, mDrawDia, TRUE);

		// 早送りボタンが押されていなかったら
		if (mFastForwardDrawFlag && mNowDia != endZero)
		{
			// 矢印（→）キーで早送りテキスト
			DrawGraph(SKIP_POS_X, SKIP_POS_Y, mFastForward, TRUE);
		}
		// 押されていたら
		else if (!mFastForwardDrawFlag && mNowDia != endZero)
		{
			// 早送り中テキスト
			DrawGraph(SKIP_POS_X, SKIP_POS_Y, mNowFastForward, TRUE);
			// 早送り中画像
			DrawGraph(ARROW_POS_X, ARROW_POS_Y, mArrow, TRUE);
		}
	}
	else if (mNowDia == stop)
	{
		// スキップテキストの描画
		DrawGraph(SKIP_POS_X, SKIP_POS_Y, mSkipText, TRUE);
	}

	if (mPlayDrawFlag)
	{
		// リアクションの描画
		DrawGraph(TEXT_POS_X, TEXT_POS_Y, mDrawReaction, TRUE);
	}
}

