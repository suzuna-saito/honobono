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
ObstructBase::ObstructBase(int _sourceModelHandle)
	: mModelHandle(-1)
	, mHitRadius(5.0f)
	, mRotationX(0.0f)
	, mVelocity(VGet(0,0,0))
	, mPos(VGet(0,0,0))
	, mBallPos(VGet(0,0,0))
{
	// ３Ｄモデルの読み込み
#if USE_MODEL_DUPLICATE
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);
	if (mModelHandle < 0)
	{
		printfDx("データ読み込みに失敗. sourceId:%d", _sourceModelHandle);
	}
#else
	mModelHandle = MV1LoadModel("data/model/obstructStatic/obstructStatic.pmd");
	if (mModelHandle < 0)
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
	MV1DeleteModel(mModelHandle);
}

// 更新
void ObstructBase::Update(UIGoal &_uiGoal)
{
	// ボールの速度
	SpeedUp(_uiGoal);
	// 位置を更新
	MV1SetPosition(mModelHandle, mPos);
	mPos = VAdd(mPos, mVelocity);

	//回転の値の増加
	mRotationX -= BALL_ROTATION_X;

	//モデルの回転関数
	MV1SetRotationXYZ(mModelHandle, VGet(mRotationX, 0.0f, 0.0f));
}
//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void ObstructBase::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(mModelHandle);
	MV1SetScale(mModelHandle, VGet( MODEL_SCALE, MODEL_SCALE, MODEL_SCALE));

}

// ボールの速度調整
void ObstructBase::SpeedUp(UIGoal& _uiGoal)
{
	if (_uiGoal.GetUIPosY() < 240.0f)     // 中級速度
	{
		mVelocity = VGet(0.0f, 0.0f, BALL_Z_SPEED - 0.3);
	}
	if (_uiGoal.GetUIPosY() < 185.0f)     // 上級速度
	{
		mVelocity = VGet(0.0f, 0.0f, BALL_Z_SPEED - 0.5);
	}
}
