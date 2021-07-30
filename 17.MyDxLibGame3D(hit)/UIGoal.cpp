#include "UIGoal.h"
#include "UIBase.h"
#include "Player.h"
#include "Satoshi.h"

// コンストラクタ
UIGoal::UIGoal()
	:UIBase(goalImg)
{
	goalImg = LoadGraph("data/Asset/satoshi.png");
	baseImg = LoadGraph("data/Asset/base.png");
	playerImg = LoadGraph("data/Asset/pikachu.png");

	PosY1 = 0;
	PosY2 = 0;

	Dy = 0;

	MainPosY = 0;
	UIPosY = 340;
	GoalFlag = FALSE;
}

// デストラクタ
UIGoal::~UIGoal()
{

}

// 距離の比率を出す
void UIGoal::GetDy(Player& player, Satoshi& satoshi)
{
	// この流れでUIとGAMEの距離の比率が出ます
	// 一応どこでも呼び出せるようにするため関数を作りました
	// PlayerにPosYとGetPosY関数の追加
	// SatoshiにPosYとGetPosY関数の追加
	// mainのほうのSceneBase生成の後に呼び出しています

	PosY1 = satoshi.GetPosY();
	PosY2 = player.GetPosY();

	MainPosY = PosY1 - PosY2;
	Dy = (UIPosY - 90) / MainPosY;

	// 画像がサトシが2D、ピカチュウが3Dでの表示
	// ゲームのほうの位置表示が変わっているので、下記の計算で速度調整をかけてます
	// 距離が変わったら変えてください
	Dy *= 0.255f;

	// サトシはZ座標で計算を行っています(距離差を出すため元の500で計算してます)
	// 	 ゲームの距離 = サトシZ座標(PosY1) - ピカチュウのY座標(PosY2)
	//   距離の比率 = UIのピカチュウのY - UIのサトシのY / ゲームの距離
	// 上下移動は考えていない計算です
	// 時間がないので、ここまでですみません
}

// 更新内容
void UIGoal::Update()
{
	// UIの位置から距離の比率を引く
	UIPosY -= Dy;

	// UIの距離でゴール計算してます
	// SceneBaseのほうでクリア画面に遷移するようにしました
	if (UIPosY <= 120)
	{
		GoalFlag = TRUE;
	}
}

// 描画内容
void UIGoal::Draw()
{
	DrawGraph(550, 50, baseImg, FALSE);
	DrawGraph(560, 90, goalImg, TRUE);
	DrawGraph(560, (int)UIPosY, playerImg, TRUE);

}