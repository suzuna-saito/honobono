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
	/// 飛び込みの更新処理
	/// </summary>
	/// <param name="_rotate">飛ぶオブジェクトの向き</param>
	void DiveUpdate(VECTOR _rotate);

	/// <summary>
	/// ジャンプパターンの更新処理
	/// </summary>
	void JumpSetUpdate();

	/// <summary>
	/// ジャンプの更新
	/// </summary>
	/// <param name="_jadge">タイミング判定</param>
	void JumpUpdate(int _jadge);


	// ジャンプの種類
	enum NowDive
	{
		// 1回目のジャンプ
		firstJump,
		// 2回目のジャンプ
		secondJump,
		// 飛び込みジャンプ
		thirdJump,

		// 飛び込みが終了した
		endDive
	};

private:

	VECTOR mVelocity;    // 移動力.
	VECTOR mChange;      // 移動方向

	float mJumpMax;      // y軸の最大増加量

	float mGain;         // 今の増加量

	NowDive mNowJump;    // 今のジャンプ

	bool mJumpUp;        // 上がることが出来る

	bool mIsGround;      // 地面との接地判定

	const float mGravity;// 重力

	/// <summary>
	/// ジャンプの処理
	/// </summary>
	void DiveNowUpdate();

public:    // ゲッター、セッター
	// 地面と接地しているかどうか
	bool GetIsGround() { return mIsGround; }

	// 移動力を返す
	VECTOR GetVelocity() { return mVelocity; }

	// 増加量を返す
	float GetGain() { return mGain; }

	// 今なんのジャンプが行われているかを返す
	NowDive GetNowJump() { return mNowJump; }
};