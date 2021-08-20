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

	// NPC関連 --------------------------------------------------
	/// <summary>
	/// 1回目のジャンプ更新処理
	/// </summary>
	/// <param name="_pos">飛ぶオブジェクトのポジション</param>
	void NpcJumpUpdate(VECTOR _pos,int _number);
	//-----------------------------------------------------------

private:
	const float mGravity;   // 重力

	const float mGravityNpc;// NPCにかかる重力

	float mInitPos;         // そのオブジェクトの初期位置

	// プレイヤー関連 ---------------------------------
	VECTOR mPos;            // ポジション
	VECTOR mVelocity;		// 移動力.

	float mJumpMax;         // y軸の最大値

	bool mFirstJump;        // 1回目のジャンプをするか
	bool mSecondJump;       // 2回目のジャンプをするか
	bool mThirdJump;        // 飛び込みのジャンプをするか

	bool mJumpUpNow;        // ジャンプアップしている

	bool mIsGround;         // 地面との接地判定
	//-------------------------------------------------

	// NPC関連----------------------------------------
	VECTOR mPosNpc;         // NPCのポジション
	VECTOR mVelocityNpc;	// NPCの移動力.

	VECTOR mAdd;
	VECTOR mSub;

	float mJumpMaxNpc;      // NPCのy軸の最大値

	bool mFirstJumpNpc;     // NPCが1回目のジャンプをするか
	bool mSecondJumpNpc;    // NPCが2回目のジャンプをするか
	bool mThirdJumpNpc;     // NPCが飛び込みのジャンプをするか

	bool mJumpUpNowNpc;     // NPCがジャンプアップしている

	bool mIsGroundNpc;      // NPCの地面との接地判定
	//-------------------------------------------------

	// プレイヤー関連 ---------------------------------
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
	//-------------------------------------------------


	// NPC関連 ---------------------------------
	/// <summary>
	/// ジャンプアップ処理
	/// </summary>
	void NpcJumpUpUpdate();
	/// <summary>
	/// ジャンプダウン処理
	/// </summary>
	void NpcJumpDownUpdate();
	/// <summary>
	/// 位置の更新処理
	/// </summary>
	void NpcJumpPosUpdate();
	//-------------------------------------------------

public:    // ゲッター、セッター

	// プレイヤー関連 ---------------------------------
	
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

	//-------------------------------------------------
	
	// NPC関連----------------------------------------
	
	// NPCがジャンプ中かどうかのフラグをセットする
	void SetJumpNpc(bool _jump) { mJumpUpNowNpc = _jump; }

	// NPCのポジションをセット
	void SetPosNpc(VECTOR _pos) { mPosNpc = _pos; }
	// NPCのポジションをゲット
	VECTOR GetPosNpc() { return mPosNpc; }

	// NPCの1回目のジャンプフラグをゲット
	bool GetFirstNpc() { return mFirstJumpNpc; }
	// NPCの2回目のジャンプフラグをゲット
	bool GetSecondNpc() { return mSecondJumpNpc; }
	// NPCの3回目のジャンプフラグをゲット
	bool GetThirdNpc() { return mThirdJumpNpc; }

	// NPCの接地判定をゲット
	bool GetGroundNpc() { return mIsGroundNpc; }

	//-------------------------------------------------
};
