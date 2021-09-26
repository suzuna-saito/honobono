#pragma once
#include "DxLib.h"

/// <summary>
/// NPCのジャンプ
/// </summary>
class NpcJump
{
public:
	NpcJump();        // コンストラクタ
	~NpcJump();       // デストラクタ

	/// <summary>
	/// 1回目のジャンプ更新処理
	/// </summary>
	/// <param name="_pos">飛ぶオブジェクトのポジション</param>
	void NpcJumpUpdate(VECTOR _pos, VECTOR _rotate);

private:
	const float mGravityNpc;// NPCにかかる重力

	float mNpcInitPos;         // Npcの初期位置

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

	VECTOR mInitPos;

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

public:    // ゲッター、セッター

	// NPCがジャンプ中かどうかのフラグをセットする
	void SetJumpNpc(bool _jump) { mJumpUpNowNpc = _jump; }
	bool GetGroundNpc() { return mIsGroundNpc; }


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

};

