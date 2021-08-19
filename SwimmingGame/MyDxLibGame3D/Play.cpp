#include "Play.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Player.h"
#include "UIGoal.h"
#include "HitChecker.h"
#include "Pool.h"
#include "Fish.h"
#include "Timing.h"
#include "Camera.h"


// コンストラクタ
Play::Play()
	:startCount(0)
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
	// 魚生成
	fish = new Fish();
	// リズムボタンUI生成
	timing = new Timing();

	camera = new Camera();
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
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Play::Update()
{
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

	///////////////////////////////////////////////////////////////////////////////
	// ↓とりあえずシーン遷移しないようにコメントアウト

	//// シーン遷移条件(クリア)
	//if (uiGoal->GetGoalFlag())
	//{
	//	// 条件を満たしていたら次のシーンを生成してそのポインタを返す
	//	return new GameClear();
	//}
	//// シーン遷移条件(オーバー)
	//else if(player->GetHp() == 0)
	//{
	//	// 条件を満たしていたら次のシーンを生成してそのポインタを返す
	//	return new GameOver();
	//}
	///////////////////////////////////////////////////////////////////////////////

	// プレイヤー制御.
	player->Update();

	startCount++;

	if (startCount >= 60)
	{
		// 魚の制御
		fish->Update();
	}
	// 残りゴール距離の更新
	uiGoal->Update();

	// ヒットのチェック.
	//hit->Check(*player, *obstructManager);

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Play::Draw()
{
	// プール描画
	pool->Draw();
	// 魚描画
	fish->Draw();
	// リズムボタンUI描画
	timing->Draw();
	// プレイヤー描画.
	player->Draw();
	//// 当たり判定UIの描画
	//hit->Draw(*player);
	// UI(ゴール)の描画
	uiGoal->Draw();


	// 真ん中の位置が分かりやすくなるように一本の線を表示（デバック用）
	DrawLine3D(VGet(0.0f, -25.0f, 0.0f), VGet(0.0f, 25.0f, 0.0f), GetColor(255, 0, 0));
}
