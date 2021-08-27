#include "Play.h"
#include "Player.h"
#include "HitChecker.h"
#include "Pool.h"
#include "FishManager.h"
#include "Timing.h"
#include "Camera.h"
#include "Result.h"
#include "BackGround.h"
#include "Sound.h"
#include "Score.h"

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
	,mWaterOutSound(nullptr)
{
	SetScene(play);

	// プレイヤーを生成.
	player = new Player();
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

	camera->FixedCameraRightUpdate();
	fishManager->CreatFish();

	mPlayBGM1 = new Sound("data/newSound/bgm/bgm_1.mp3");
	mPlayBGM2 = new Sound("data/newSound/bgm/bgm_2.mp3");
	mPlayBGM3 = new Sound("data/newSound/bgm/bgm_3.mp3");

	mWaterInSound = new Sound("data/newSound/se/in.mp3");
	mWaterOutSound = new Sound("data/newSound/se/out.mp3");
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
	// プレイヤーを削除.
	delete(player);
	// 背景の削除
	delete(backGround);
	mPlayBGM1->StopMusic();
	mPlayBGM2->StopMusic();
	mPlayBGM3->StopMusic();
	delete mPlayBGM1;
	delete mPlayBGM2;
	delete mPlayBGM3;

	delete mWaterInSound;
	delete mWaterOutSound;
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Play::Update()
{
	mPlayBGM1->PlayBGM();
	if (!mPlayBGM1->CheckBGM()) 
	{
		// リザルトにスコアを渡す
		mScore = SceneBase::mScore->GetResult();
		return new Result(&mScore);
	}

	// シーン遷移条件(デバック用：右シフトキーを押すと遷移)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
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
		camera->FixedCameraRightUpdate();
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

	// プレイヤー制御.
	player->Update();

	startCount++;

	if (startCount >= 60)
	{
		// 魚の制御
		fishManager->Updata();
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
	// プレイヤー描画.
	player->Draw();
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
	DrawLine3D(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 15.0f, 0.0f), redColor);
	//プールの左上端
	DrawLine3D(VGet(-15.0f, 0.0f, 25.0f), VGet(-15.0f, 15.0f, 25.0f), greenColor);
	//プールの左下端
	DrawLine3D(VGet(-15.0f, 0.0f, -25.0f), VGet(-15.0f, 15.0f, -25.0f), yellowColor);
	//プールの右上端
	DrawLine3D(VGet(15.0f, 0.0f, 25.0f), VGet(15.0f, 15.0f, 25.0f), purpleColor);
	//プールの右下端
	DrawLine3D(VGet(15.0f, 0.0f, -25.0f), VGet(15.0f, 15.0f, -25.0f), lightBlueColor);
}
