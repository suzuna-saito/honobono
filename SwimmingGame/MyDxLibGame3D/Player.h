//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"


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
	int mFishTexture;                // Playerテクスチャ

	VECTOR	mPos;			// ポジション.
	VECTOR	mVelocity;		// 移動力.

	const float mGravity;   // 重力

	const VECTOR FISH_ROTATE;// Playerの回転角度

	bool mFirstJump;        // 1回目のジャンプをするか
	bool mSecondJump;       // 2回目のジャンプをするか
	bool mThirdJump;        // 飛び込みのジャンプをするか

	bool mJumpUpNow;        // ジャンプアップしている

	bool mIsGround;         // 地面との接地判定

	/// <summary>
    /// 1回目のジャンプ更新処理
    /// </summary>
	void FirstJumpUpdate();
	/// <summary>
	/// 2回目のジャンプ更新処理
	/// </summary>
	void SecondJumpUpdate();
	/// <summary>
	/// 飛び込みのジャンプ更新処理
	/// </summary>
	void ThirdJumpUpdate();
};

#endif // _PLAYER_H_