#include "Satoshi.h"
#include "BackGround.h"
#include"DxLib.h"
#include"SceneBase.h"
#include "UIGoal.h"
#include "UIBase.h"

/// <summary>
/// コンストラクタ 
/// </summary>
Satoshi::Satoshi()
	:UIBase(satoshiImg)
	, satoshiImg(-1)
	, angle(0.0f)
	, centerX(0.5f)
	, centerY(0.5f)
	, x(-10.0f)
	, y(0.0f)
	, z(810.0f)
	, veloX(0.0f)
	, veloY(0.0f)
	, veloZ(0.0f)
	, size(300.0f)
	, posY(1800.0f)
	, posMax(140)
{
	if (satoshiImg == -1)
	{
		satoshiImg = LoadGraph("data/Asset/SatoshiDot.png");
	}

	// サトシ(ゴール)のポジション設定
	pos = VGet(x, y, z);

	// 背景のスクロールと同じ速さで移動
	velocity = VGet(veloX, veloY, veloZ);
}

/// <summary>
/// デストラクタ 
/// </summary>
Satoshi::~Satoshi()
{
	// サトシの画像削除
	DeleteGraph(satoshiImg);
}

/// <summary>
/// 更新
/// </summary>
/// <param name="scene"> ゲームシーンに入ってから描画するため </param>
/// <param name="uiGoal"> プレイヤーとの距離を測るため </param>
void Satoshi::Update(UIGoal& _uiGoal)
{
	// サトシ移動開始位置
	if (_uiGoal.GetUIPosY() <= posMax)
	{
		// 背景のスクロールと同じ速さで移動
		velocity = VGet(veloX, -SCROLL_SPEED * 2, -EXPANSION_SPEED);
	}
	// サトシのポジションに速度追加
	pos = VAdd(pos, velocity);
}

/// <summary>
/// 描画
/// </summary>
void Satoshi::Draw()
{
	// サトシの描画
	DrawBillboard3D(pos, centerX, centerY, size, angle, satoshiImg, true);
}
