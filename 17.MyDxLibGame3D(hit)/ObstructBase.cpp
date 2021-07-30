//-----------------------------------------------------------------------------
// @brief  障害物基底クラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "ObstructBase.h"
#include "UIGoal.h"

#define USE_MODEL_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
ObstructBase::ObstructBase(int sourceModelHandle)
	: modelHandle(-1)
	, hitRadius(5.0f)
	, rotationX(0.0f)
	, velocity(VGet(0,0,0))
	, pos(VGet(0,0,0))
	, BallPos(VGet(0,0,0))
{
	// ３Ｄモデルの読み込み
#if USE_MODEL_DUPLICATE
	modelHandle = MV1DuplicateModel(sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("データ読み込みに失敗. sourceId:%d", sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("data/model/obstructStatic/obstructStatic.pmd");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:データ読み込みに失敗");
	}
#endif
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
ObstructBase::~ObstructBase()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}

// 更新
void ObstructBase::Update(UIGoal &uiGoal)
{
	// ボールの速度
	SpeedUp(uiGoal);
	// 位置を更新
	MV1SetPosition(modelHandle, pos);
	pos = VAdd(pos, velocity);

	//回転の値の増加
	rotationX -= BALL_ROTATION_X;

	//モデルの回転関数
	MV1SetRotationXYZ(modelHandle, VGet(rotationX, 0.0f, 0.0f));
}
//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void ObstructBase::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
	MV1SetScale(modelHandle, VGet( MODEL_SCALE, MODEL_SCALE, MODEL_SCALE));

}

// ボールの速度調整
void ObstructBase::SpeedUp(UIGoal& uiGoal)
{
	if (uiGoal.GetUIPosY() < 240.0f)     // 中級速度
	{
		velocity = VGet(0.0f, 0.0f, BALL_Z_SPEED - 0.3);
	}
	if (uiGoal.GetUIPosY() < 185.0f)     // 上級速度
	{
		velocity = VGet(0.0f, 0.0f, BALL_Z_SPEED - 0.5);
	}
}
