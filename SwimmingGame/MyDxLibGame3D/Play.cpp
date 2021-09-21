#include "Play.h"
#include "HitChecker.h"
#include "Pool.h"
#include "FishManager.h"
#include "Timing.h"
#include "Camera.h"
#include "Result.h"
#include "BackGround.h"
#include "Sound.h"
#include "Score.h"
#include "Common.h"


// コンストラクタ
Play::Play()
	:startCount(0)
	, mScore(0)
	, mScoreRadius(0)
	, mScoreFlag(false)
	, mPlayBGM1(nullptr)
	, mPlayBGM2(nullptr)
	, mPlayBGM3(nullptr)
	, mWaterInSound(nullptr)
	, mWaterOutSound(nullptr)
	, mWaitDanceCount(WAIT_DANCE_TIME_COUNT)
{
	SetScene(play);

	// 当たり判定を生成
	hit = new HitChecker();

	// プール生成
	pool = new Pool();

	// 魚生成
	fishManager = new FishManager();

	// リズムボタンUI生成
	timing = new Timing();

	// 背景の生成
	backGround = new BackGround();
	// 時間の生成
	time = new Time();

	camera = new Camera();

	fishManager->CreatFish();

	mPlayBGM1 = new Sound("data/newSound/bgm/bgm_1.wav");
	mPlayBGM2 = new Sound("data/newSound/bgm/bgm_2.mp3");
	mPlayBGM3 = new Sound("data/newSound/bgm/bgm_3.mp3");

	mWaterInSound = new Sound("data/newSound/se/in.mp3");
	mWaterOutSound = new Sound("data/newSound/se/out.mp3");

	//アーティスティックスイミング時の音楽のコンストラクタ
	mDancePlaySE = new Sound("data/newsound/bgm/BGM_3.wav");

	mPlayBGM1->PlayBackBGM();

	///// デバック用 //////
	test = 0.0f;
	test02 = 0.0f;
	test03 = 0.0f;
}

// デストラクタ
Play::~Play()
{
	//魚たちの配列の削除
	fishManager->DestroyFish();

	// 魚削除
	delete fishManager;
	// プール削除
	delete pool;
	// リズムボタンUI削除
	delete timing;
	// 当たり判定の削除
	delete(hit);
	// 背景の削除
	delete(backGround);
	mPlayBGM1->StopMusic();
	mPlayBGM2->StopMusic();
	mPlayBGM3->StopMusic();


	//音楽の停止
	mDancePlaySE->StopMusic();

	delete mPlayBGM1;
	delete mPlayBGM2;
	delete mPlayBGM3;

	//メモリの削除
	delete mDancePlaySE;

	delete mWaterInSound;
	delete mWaterOutSound;
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Play::Update()
{
	if (!mPlayBGM1->CheckBGM()
		&& !mDancePlaySE->CheckBGM())
	{
		mPlayBGM1->StopMusic();
		mDancePlaySE->StopMusic();
		// リザルトにスコアを渡す
		mScore = SceneBase::mScore->GetResult();
		return new Result(&mScore);
	}

	// シーン遷移条件(デバック用：右シフトキーを押すと遷移)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
		mPlayBGM1->StopMusic();
		mDancePlaySE->StopMusic();
		// リザルトにスコアを渡す
		mScore = SceneBase::mScore->GetResult();
		return new Result(&mScore);
	}

	time->Update();

	camera->DivingCameraUpdate(*time);
	camera->CameraSet();

	// カメラの更新（デバック用）
	if (CheckHitKey(KEY_INPUT_UP))        // ↑押したら上固定カメラ
	{
		camera->FixedCameraUpUpdate();
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))// →押したら右固定カメラ
	{
		camera->FixedCameraRightUpdate(test02);
		CameraPosUpDate();                // 引数（test02）の更新
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) // ↓押したらプレイヤーの後ろ固定カメラ
	{
		camera->FixedCameraBackUpdate(test, test03);
		CameraPosUpDate();                // 引数（test）の更新
	}

	// リズムボタンUI更新
	timing->Update();
	// スコアの割合をもらってくる
	mScoreRadius = timing->GetRadius();
	// スコアのフラグをもらう
	mScoreFlag = timing->GetScoreFlag();

	// スコアにフラグを渡す
	SceneBase::mScore->SetScoreFlag(&mScoreFlag);
	// スコアに割合を渡す
	SceneBase::mScore->SetRadiusScore(&mScoreRadius);


	startCount++;
	if (startCount >= 60)
	{
		// 魚の制御
		fishManager->Updata(timing->GetJudg(), time->GetDeltaTime(), fishManager->GetStopFlag());

		//andou
		//ダンスを始めてもいいかのフラグがtrueだったとき
		if (fishManager->GetStopFlag())
		{
			//ダンスを始めるまでのカウントを引いていく
			mWaitDanceCount--;

			//カウントが０以下になったら
			if (mWaitDanceCount <= 0)
			{
				//飛び込む前に流れていた音楽を止める
				mPlayBGM1->StopMusic();
				//ダンス時の音楽を流す
				mDancePlaySE->PlayBackBGM();
			}
		}

	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Play::Draw()
{
	// 背景の生成
	backGround->Draw();
	// 魚描画
	fishManager->Draw();
	// プール描画
	pool->Draw();
	// リズムボタンUI描画
	timing->Draw();

	SceneBase::mScore->Draw();

	//それぞれの位置が分かりやすくなるように一本の線を表示（デバック用）
	int redColor = GetColor(255, 0, 0);				//真ん中の色
	int greenColor = GetColor(0, 255, 0);			//左上の色
	int yellowColor = GetColor(255, 255, 0);		//左下の色
	int purpleColor = GetColor(128, 0, 128);		//右上の色
	int lightBlueColor = GetColor(0, 255, 255);		//右下の色

	//プールの真ん中
	DrawLine3D(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, LINE_Y, 0.0f), redColor);
	//プールの左上端
	DrawLine3D(VGet(-LINE_X, 0.0f, LINE_Z), VGet(-LINE_X, LINE_Y, LINE_Z), greenColor);
	//プールの左下端
	DrawLine3D(VGet(-LINE_X, 0.0f, -LINE_Z), VGet(-LINE_X, LINE_Y, -LINE_Z), yellowColor);
	//プールの右上端
	DrawLine3D(VGet(LINE_X, 0.0f, LINE_Z), VGet(LINE_X, LINE_Y, LINE_Z), purpleColor);
	//プールの右下端
	DrawLine3D(VGet(LINE_X, 0.0f, -LINE_Z), VGet(LINE_X, LINE_Y, -LINE_Z), lightBlueColor);
}



/////////// デバック用 //////////////

/// <summary>
/// カメラの位置をずらす引数を更新
/// </summary>
void Play::CameraPosUpDate()
{
	switch ((int)GetCameraPosition().x)
	{
	case 60:
		if ((CheckHitKey(KEY_INPUT_D)))       // dが押されたら右に進む
		{
			test02 += 0.5f;
		}
		else if ((CheckHitKey(KEY_INPUT_A))) // aが押されたら左に進む
		{
			test02 -= 0.5f;
		}
		break;

	case 0:
		if ((CheckHitKey(KEY_INPUT_W)))       // ｗが押されたら前に進む
		{
			test += 0.5f;
		}
		else if ((CheckHitKey(KEY_INPUT_S))) // ｓが押されたら後ろに下がる
		{
			test -= 0.5f;
		}
		if ((CheckHitKey(KEY_INPUT_Q)))      // qが押されたら下を向く
		{
			test03 += 0.01;
		}
		else if ((CheckHitKey(KEY_INPUT_E))) // eが押されたら上を向く
		{
			test03 -= 0.01;
		}
		break;
	default:
		break;
	}
}
