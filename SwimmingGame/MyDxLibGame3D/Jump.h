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
	/// <param name="_pos">飛ぶオブジェクトのポジション</param>
	/// <param name="_rotate">飛ぶオブジェクトの向き</param>
	void JumpUpdate(VECTOR _pos, VECTOR _rotate);

private:
	const float mGravity;// 重力

	VECTOR mPos;         // ポジション
	VECTOR mVelocity;    // 移動力.

	VECTOR mAdd;         // 加算値
	VECTOR mSub;         // 減算値

	float mJumpMax;      // y軸の最大値

	bool mFirstJump;     // 1回目のジャンプをするか
	bool mSecondJump;    // 2回目のジャンプをするか
	bool mThirdJump;     // 飛び込みのジャンプをするか

	bool mJumpUpNow;     // ジャンプアップしている

	bool mIsGround;      // 地面との接地判定

	VECTOR mInitPos;     // 初期位置

	/// <summary>
	/// ジャンプアップ処理
	/// </summary>
	void JumpUpUpdate();
	/// <summary>
	/// ジャンプダウン処理
	/// </summary>
	void JumpDownUpdate();
	/// <summary>
	/// 位置の更新処理
	/// </summary>
	void JumpPosUpdate();

public:    // ゲッター、セッター

	// ジャンプ中かどうかのフラグをセットする
	void SetJump(bool _jump) { mJumpUpNow = _jump; }
	// 地面と接地しているかどうか
	bool GetGround() { return mIsGround; }


	// ポジションをセット
	void SetPos(VECTOR _pos) { mPos = _pos; }
	// ポジションをゲット
	VECTOR GetPos() { return mPos; }

	// 1回目のジャンプフラグをゲット
	bool GetFirst() { return mFirstJump; }
	// 2回目のジャンプフラグをゲット
	bool GetSecond() { return mSecondJump; }
	// 3回目のジャンプフラグをゲット
	bool GetThird() { return mThirdJump; }

};

