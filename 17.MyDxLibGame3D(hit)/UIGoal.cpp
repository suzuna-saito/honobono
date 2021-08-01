#include "UIGoal.h"
#include "UIBase.h"
#include "Player.h"
#include "Satoshi.h"

/// <summary>
/// コンストラクタ 
/// </summary>
UIGoal::UIGoal()
	:UIBase(goalImg)
	, goalX(560)
	, goalY(90)
	, baseX(550)
	, baseY(50)
	, playerX(560)
	, playerY(340)
	, PosY1(0.0f)
	, PosY2(0.0f)
	, distanceRatio(0.0f)
	, MainPosY(0.0f)
	, GoalFlag(FALSE)
	, playerMaxY(120)
	, ratio(0.255f)
{
	// 画像読み込み
	goalImg = LoadGraph("data/Asset/satoshi.png");
	baseImg = LoadGraph("data/Asset/base.png");
	playerImg = LoadGraph("data/Asset/pikachu.png");
}

/// <summary>
/// デストラクタ 
/// </summary>
UIGoal::~UIGoal()
{
	// 画像を消す
	DeleteGraph(goalImg);
	DeleteGraph(baseImg);
	DeleteGraph(playerImg);
}

/// <summary>
/// 距離の比率を出す 
/// </summary>
/// <param name="player"> プレイヤーの座標取得のため使用 </param>
/// <param name="satoshi"> サトシの座標取得のため使用 </param>
void UIGoal::GetDy(Player& player, Satoshi& satoshi)
{
	// SatoshiにPosYとGetPosY関数の追加
	PosY1 = satoshi.GetPosY();
	// PlayerにPosYとGetPosY関数の追加
	PosY2 = player.GetPosY();

	// ゲーム内の距離 = サトシZ座標(PosY1) - ピカチュウのY座標(PosY2)
	MainPosY = PosY1 - PosY2;
	// 距離の比率
	distanceRatio = (playerY - goalY) / MainPosY;	
	// ゲームのほうの位置表示が変わっているので、速度調整
	distanceRatio *= ratio;
}

/// <summary>
/// 更新
/// </summary>
void UIGoal::Update()
{
	// UIの位置から距離の比率を引く
	playerY -= distanceRatio;

	// UIの距離でゴール計算
	// SceneBaseのほうでクリア画面に遷移
	if (playerY <= playerMaxY)
	{
		// ゴールフラグを「真」にする
		GoalFlag = TRUE;
	}
}

/// <summary>
/// 描画
/// </summary>
void UIGoal::Draw()
{
	DrawGraph(baseX, baseY, baseImg, FALSE);
	DrawGraph(goalX, goalY, goalImg, TRUE);
	DrawGraph(playerX, playerY, playerImg, TRUE);

}