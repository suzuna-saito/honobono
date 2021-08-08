#pragma once
#include "DxLib.h"

/// <summary>
/// Poolクラス
/// </summary>
class Pool
{
private:
	int mPoolHandle;                       // プール画像変数
	int mPoolWaterHandle;                  // プールの水画像変数
	int mDivingBoardHandle;                // 飛び込み台画像変数
	int i;

	VECTOR mPoolPos;                       // プールの位置
	VECTOR mWaterPos;                      // 水の位置
	VECTOR mDivingBoardPos[4];                // 飛び込み台の位置

	const VECTOR POOL_SIZE;                // プールのサイズ
	const VECTOR WATER_SIZE;               // 水のサイズ
	const VECTOR DIVINGBOARD_SIZE;         // 飛び込み台のサイズ
	const VECTOR DIVINGBOARD_ROTATE[4];
	const int DIVINGBOARD_NUM;

public:
	// コンストラクタ
	Pool();
	// デストラクタ
	virtual ~Pool();
	// 描画関数
	void Draw();
};