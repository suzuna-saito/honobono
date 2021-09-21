//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class Jump;

/// <summary>
/// プレイヤークラス
/// </summary>
class Player
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新関数
	void Draw();			// 描画関数

public:
	int mPHandle;                   // Player画像変数

	VECTOR mPos;			// ポジション.
	VECTOR mVelocity;       // 移動力

	const VECTOR FISH_ROTATE;// Playerの回転角度

	const float mAdvance;         // 前進する値

	 // ジャンプ
	Jump* jump;
};

#endif // _PLAYER_H_