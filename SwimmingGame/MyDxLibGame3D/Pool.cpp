#include "Pool.h"

// 定数-----------------------
const float P_SIZE = 0.325f;   // プールのサイズ
const float W_SIZE = 3.3f;     // 水のサイズ
const float D_SIZE = 0.6f;     // ダイビングボードのサイズ

const float D_POS_X = 33.5f; // ダイビングボードのポジションｘ
const float D_POS_Y = 7.5f;  // ダイビングボードのポジションｙ
const float D_POS_Z = 52.0f; // ダイビングボードのポジションｚ

const float W_HEIGHT = 5.0f; // 水の高さ
//----------------------------


/// <summary>
/// コンストラクタ
/// </summary>
Pool::Pool()
	:POOL_SIZE(VGet(P_SIZE, P_SIZE, P_SIZE))
	, WATER_SIZE(VGet(W_SIZE, W_SIZE, W_SIZE))
	, DIVINGBOARD_SIZE(VGet(D_SIZE, D_SIZE, D_SIZE))
	, DIVINGBOARD_NUM(4)
	, DIVINGBOARD_ROTATE{ VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f)
					   ,VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f)
					   ,VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f)
					   ,VGet(0.0f, 0.0f, 0.0f) }
	, mPoolPos(VGet(0.0f, 0.0f, 0.0f))
	, mWaterPos(VGet(0.0f, W_HEIGHT, 0.0f))
	, mDivingBoardPos{ VGet(-1.0f, D_POS_Y, -D_POS_Z),VGet(-D_POS_X, D_POS_Y, 1.0f)
					,VGet(D_POS_X, D_POS_Y, -1.0f), VGet(1.0f, D_POS_Y, D_POS_Z) }
	, i(0)
{
	// 画像の読み込み
	mPoolHandle = MV1LoadModel("data/model/Pool/Outpool_OFFroop_dainashi.mqo");
	mPoolWaterHandle = MV1LoadModel("data/model/Pool/water.x");
	mDivingBoardHandle = MV1LoadModel("data/model/Pool/DivingBoard.mqo");

	// 座標のセット
	MV1SetPosition(mPoolHandle, mPoolPos);
	MV1SetPosition(mPoolWaterHandle, mWaterPos);

	// サイズの変更
	MV1SetScale(mPoolHandle, POOL_SIZE);
	MV1SetScale(mPoolWaterHandle, WATER_SIZE);
	MV1SetScale(mDivingBoardHandle, DIVINGBOARD_SIZE);
}

/// <summary>
/// デストラクタ
/// </summary>
Pool::~Pool()
{
	// 画像データ消去
	MV1DeleteModel(mPoolHandle);
	MV1DeleteModel(mPoolWaterHandle);
	MV1DeleteModel(mDivingBoardHandle);
}

/// <summary>
/// 描画変数
/// </summary>
void Pool::Draw()
{
	// 画像の描画
	MV1DrawModel(mPoolHandle);
	MV1DrawModel(mPoolWaterHandle);
	for (i = 0; i < DIVINGBOARD_NUM; i++)
	{
		MV1SetPosition(mDivingBoardHandle, mDivingBoardPos[i]);
		MV1SetRotationXYZ(mDivingBoardHandle, DIVINGBOARD_ROTATE[i]);
		MV1DrawModel(mDivingBoardHandle);
	}
}
