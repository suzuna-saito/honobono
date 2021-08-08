#include "Play.h"
#include "GameClear.h"
#include "GameOver.h"

// コンストラクタ
Play::Play()
{
	SetScene(play);

	// 背景を生成.
	backGround = new BackGround();
	// プレイヤーを生成.
	player = new Player();
	// UI（ゴール）の生成
	uiGoal = new UIGoal();
	//// UI(花火)の生成
	//new UIFireworks();
	// サトシを生成
	satoshi = new Satoshi();
	// 障害物を生成.
	obstructManager = new ObstructManager();
	// 当たり判定を生成
	hit = new HitChecker();
	// 障害物を生成.
	obstructManager->CreateObstructs();
}

// デストラクタ
Play::~Play()
{
	// 背景の削除
	delete(backGround);
	// 当たり判定の削除
	delete(hit);
	// UIの削除
	delete(uiGoal);
	//delete(uiFire);
	// プレイヤーを削除.
	delete(player);
	// サトシの削除
	delete(satoshi);
	// 障害物を削除.
	obstructManager->DestroyObstructs();
	delete(obstructManager);
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Play::Update()
{
	// シーン遷移条件(クリア)
	if (uiGoal->GetGoalFlag())
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new GameClear();
	}
	// シーン遷移条件(オーバー)
	else if(player->GetHp() == 0)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new GameOver();
	}

	// 背景
	backGround->Scroll();
	// プレイヤー制御.
	player->Update();
	// サトシの制御
	satoshi->Update(*uiGoal);
	// 障害物制御.
	obstructManager->Update(*player, *uiGoal);
	// 残りゴール距離の更新
	uiGoal->Update();

	// ヒットのチェック.
	hit->Check(*player, *obstructManager);

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Play::Draw()
{
	// 背景
	backGround->Draw();
	// サトシの描画
	satoshi->Draw();
	// 障害物描画.
	obstructManager->Draw();
	// プレイヤー描画.
	player->Draw();
	// 当たり判定UIの描画
	hit->Draw(*player);
	// UI(ゴール)の描画
	uiGoal->Draw();
}
