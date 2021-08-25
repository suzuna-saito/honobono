#include "Play.h"
#include "Player.h"
#include "UIGoal.h"
#include "HitChecker.h"
#include "Pool.h"
#include "Fish.h"
#include "Timing.h"
#include "Camera.h"
#include "Result.h"
#include "BackGround.h"
#include "Sound.h"

// コンストラクタ
Play::Play()
	:startCount(0)
	, mScore(0)
	, mPlayBGM1(nullptr)
	, mPlayBGM2(nullptr)
	, mPlayBGM3(nullptr)
	, mWaterInSound(nullptr)
	,mWaterOutSound(nullptr)
{
	SetScene(play);

	// プレイヤーを生成.
	player = new Player();
	// UI（ゴール）の生成
	uiGoal = new UIGoal();
	//// UI(花火)の生成
	//new UIFireworks();
	// 当たり判定を生成
	hit = new HitChecker();

	// プール生成
	pool = new Pool();

	// NPC分
	for (int i = 0; i < 11;i++)
	{
		// 魚生成
		fish = new Fish();
	}

	// リズムボタンUI生成
	timing = new Timing();

	//sound = new Sound();

	// 背景の生成
	backGround = new BackGround();
	// 時間の生成
	time = new Time();

	camera = new Camera();

	camera->FixedCameraRightUpdate();

	mPlayBGM1 = new Sound("data/newSound/bgm/bgm_1.mp3");
	mPlayBGM2 = new Sound("data/newSound/bgm/bgm_2.mp3");
	mPlayBGM3 = new Sound("data/newSound/bgm/bgm_3.mp3");

	mWaterInSound = new Sound("data/newSound/se/in.mp3");
	mWaterOutSound = new Sound("data/newSound/se/out.mp3");

	// Updateが始まる前に流す(Loopしないように)
	mPlayBGM1->PlayBackBGM();
}

// デストラクタ
Play::~Play()
{
	// プール削除
	delete pool;
	// 魚削除
	delete fish;
	// リズムボタンUI削除
	delete timing;
	// 当たり判定の削除
	delete(hit);
	// UIの削除
	delete(uiGoal);
	//delete(uiFire);
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
	//if (CheckHitKey(KEY_INPUT_SPACE))        // ↑押したら上固定カメラ
	//{
	//	
	//}

	// 音楽が流れているかチェック
	if (!mPlayBGM1->CheckBGM())
	{
		// スコアをもらう
		mScore = timing->GetScore()->GetResult();
		// 流れていなかったらリザルトへ
		return new Result(mScore);
	}

	// シーン遷移条件(デバック用：右シフトキーを押すと遷移)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
		// スコアをもらう
		mScore = timing->GetScore()->GetResult();
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Result(mScore);
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

	// プレイヤー制御.
	player->Update();

	startCount++;

	if (startCount >= 60)
	{
		// 魚の制御
		fish->Update();
	}
	
	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Play::Draw()
{
	// 背景の生成
	backGround->Draw();
	// プール描画
	pool->Draw();
	// 魚描画
	fish->Draw();
	// リズムボタンUI描画
	timing->Draw();
	// プレイヤー描画.
	player->Draw();


	// 真ん中の位置が分かりやすくなるように一本の線を表示（デバック用）
	DrawLine3D(VGet(0.0f, -25.0f, 0.0f), VGet(0.0f, 25.0f, 0.0f), GetColor(255, 0, 0));
}
