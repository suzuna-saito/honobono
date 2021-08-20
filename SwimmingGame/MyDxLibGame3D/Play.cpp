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

// コンストラクタ
Play::Play()
	:startCount(0)
	,ENDTIME(10000 * 2)
{
	SetScene(play);

	mTime = GetNowCount();

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
	// 魚生成
	fish = new Fish();
	// リズムボタンUI生成
	timing = new Timing();

	// 背景の生成
	backGround = new BackGround();
	// 時間の生成
	time = new Time();

	camera = new Camera();

	camera->FixedCameraRightUpdate();
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
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Play::Update()
{
	// シーン遷移条件(デバック用：右シフトキーを押すと遷移)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Result();
	}

	// カメラの更新（デバック用）
	if (CheckHitKey(KEY_INPUT_UP))        // ↑押したら上固定カメラ
	{
		camera->FixedCameraUpUpdate();
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))// →押したら右固定カメラ
	{
		camera->FixedCameraRightUpdate();
	}

	time->Update();
	
	camera->DivingCameraUpdate(*time);
	camera->CameraSet();

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
	
	if (GetNowCount() - mTime > ENDTIME)
	{
		return new Result();
	}
	else
	{
		// シーンが変更されていなかったら自分のポインタを返す
		return this;
	}
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
