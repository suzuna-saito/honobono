#pragma once
#include "DxLib.h"

/// <summary>
/// 飛び込みジャンプ
/// </summary>
class Jump
{
public:
	Jump();        // コンストラクタ
	~Jump();       // デストラクタ

	/// <summary>
	/// ジャンプ更新処理
	/// </summary>
	/// <param name="_rotate">飛ぶオブジェクトの向き</param>
	void JumpUpdate(VECTOR _rotate);

	/// <summary>
	/// ジャンプパターンの更新処理
	/// </summary>
	/// <param name="_pos">止まる位置</param>
	void JumpSetUpdate();

	// ジャンプの種類
	enum NowJump
	{
		// 1回目のジャンプ
		firstJump,
		// 2回目のジャンプ
		secondJump,
		// 飛び込みジャンプ
		thirdJump,

		// 全てのジャンプが終了した
		endJump
	};

private:

	VECTOR mVelocity;    // 移動力.
	VECTOR mChange;      // 移動方向

	float mJumpMax;      // y軸の最大増加量

	float mGain;         // 今の増加量

	NowJump mNowJump;    // 今のジャンプ

	bool mJumpUp;        // 上がることが出来る

	bool mIsGround;      // 地面との接地判定

	const float mGravity;// 重力

	/// <summary>
	/// ジャンプの処理
	/// </summary>
	void JumpNowUpdate();

public:    // ゲッター、セッター
	// 地面と接地しているかどうか
	bool GetIsGround() { return mIsGround; }

	// 移動力を返す
	VECTOR GetVelocity() { return mVelocity; }

	// 増加量を返す
	float GetGain() { return mGain; }

	// 今なんのジャンプが行われているかを返す
	NowJump GetNowJump() { return mNowJump; }
};