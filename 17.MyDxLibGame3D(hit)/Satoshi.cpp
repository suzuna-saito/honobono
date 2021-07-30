#include "Satoshi.h"
#include "BackGround.h"
#include"DxLib.h"
#include"SceneBase.h"
#include "UIGoal.h"

// コンストラクタ
Satoshi::Satoshi()
	:satoshiGraphHandle(-1)
	, angle(0.0f)
	, centerX(0.5f), centerY(0.5f)
{
	if (satoshiGraphHandle == -1)
	{
		satoshiGraphHandle = LoadGraph("data/Asset/SatoshiDot.png");
	}

	pos = VGet(-10, 0, 810);  // 元は340,0,500
	PosY = 1800.0f; // Y座標取得
	size = 300;    // 元は300
	hitRadius = 0;

	// 背景のスクロールと同じ速さで移動
	velocity = VGet(0.0f, 0.0f, 0.0f);
}

// デストラクタ
Satoshi::~Satoshi()
{
}

// 更新
void Satoshi::Update(SceneBase& scene, UIGoal& uiGoal)
{
	// サトシ移動開始位置
	if (uiGoal.GetUIPosY() <= 140)
	{
		// 背景のスクロールと同じ速さで移動
		velocity = VGet(0.0f, -SCROLL_SPEED * 2, -EXPANSION_SPEED);
	}

	pos = VAdd(pos, velocity);
}

void Satoshi::Draw()
{
	DrawBillboard3D(pos, centerX, centerY, size, angle, satoshiGraphHandle, true);
}
