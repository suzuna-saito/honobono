#pragma once
#include "DxLib.h"

/// <summary>
/// ジャンプ関係
/// </summary>
class Jump
{
public:
	Jump();        // コンストラクタ
	~Jump();       // デストラクタ

	// プレイヤー関連 ------------------------------------------
	/// <summary>
	/// ジャンプ更新処理
	/// </summary>
	/// <param name="_pos">飛ぶオブジェクトのポジション</param>
	void JumpUpdate(VECTOR _pos);

private:
	const float mGravity;   // 重力

	float mInitPos;         // そのオブジェクトの初期位置

	VECTOR mPos;            // ポジション
	VECTOR mVelocity;		// 移動力.

	float mJumpMax;         // y軸の最大値

	bool mFirstJump;        // 1回目のジャンプをするか
	bool mSecondJump;       // 2回目のジャンプをするか
	bool mThirdJump;        // 飛び込みのジャンプをするか

	bool mJumpUpNow;        // ジャンプアップしている

	bool mIsGround;         // 地面との接地判定

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

	// 接地判定をゲット
	bool GetGround() { return mIsGround; }
};
