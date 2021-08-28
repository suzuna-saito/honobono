#include "NpcJump.h"

//----------------------
//定数
//----------------------
const float JUMP_UP_Y = 0.5f;      // ジャンプした時のY軸の加算値
const float JUMP_DOWN_Y = 0.25f;   // ジャンプした後のY軸の減算値

const float JUMP_UP_Z = 0.25f;     // ジャンプした時のz軸の加算値
const float JUMP_DOWN_Z = 0.2f;    // ジャンプした時のz軸の減算値

const float JUMP_UP_X = 0.25f;     // ジャンプした時のx軸の加算値
const float JUMP_DOWN_X = 0.2f;    // ジャンプした時のx軸の減算値

const float FIRST_MAX = 3.0f;     // 1回目ジャンプの最大ジャンプ力
const float SECOND_MAX = 5.0f;    // 2回目ジャンプの最大ジャンプ力
const float THIRD_MAX = 8.0f;     // 飛び込みの最大ジャンプ力

const float INIT_POS_Y = 23.0f;    // ジャンプ台の高さ
const float INIT_POS_Y2 = 18.0f;   // ジャンプ台の高さ
const float INIT_POS_Y3 = 11.0f;    // ジャンプ台の高さ


//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
NpcJump::NpcJump()
	: mPosNpc(VGet(0.0f, 0.0f, 0.0f))
	, mVelocityNpc(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMaxNpc(FIRST_MAX)
	, mFirstJumpNpc(true)
	, mSecondJumpNpc(false)
	, mThirdJumpNpc(false)
	, mJumpUpNowNpc(false)
	, mIsGroundNpc(true)
	, mInitPos(VGet(0.0f, 0.0f, 0.0f))
	, mGravityNpc(0.005f)
	, mAdd(VGet(0.0f, 0.0f, 0.0f))
	, mSub(VGet(0.0f, 0.0f, 0.0f))
{
}
//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
NpcJump::~NpcJump()
{
}

//-----------------------------------------------------------------------------
// @brief  NPCのジャンプ更新.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpUpdate(VECTOR _pos, VECTOR _rotate)
{
	// その魚のポジションの初期位置
	if (_pos.y == INIT_POS_Y3)
	{
		mInitPos.y = INIT_POS_Y3;
	}
	else if (_pos.y == INIT_POS_Y2)
	{
		mInitPos.y = INIT_POS_Y2;
	}
	else
	{
		mInitPos.y = INIT_POS_Y;
	}

	// 魚の向きによって飛び込む方向を換える
	if (_rotate.y == 90.0f * DX_PI_F / 180.0f)
	{
		mAdd.z = JUMP_UP_Z;
		mSub.z = JUMP_DOWN_Z;
	}
	else if (_rotate.y == -90.0f * DX_PI_F / 180.0f)
	{
		mAdd.z = -JUMP_UP_Z;
		mSub.z = -JUMP_DOWN_Z;
	}
	else if (_rotate.y == 180.0f * DX_PI_F / 180.0f)
	{
		mAdd.x = JUMP_UP_X;
		mSub.x = JUMP_DOWN_X;
	}
	else
	{
		mAdd.x = -JUMP_UP_X;
		mSub.x = -JUMP_DOWN_X;
	}

	// ポジションをセット
	SetPosNpc(_pos);

	// ジャンプアップの更新
	NpcJumpUpUpdate();

	// ポジション更新
	NpcJumpPosUpdate();

}

//-----------------------------------------------------------------------------
// @brief  NPCのジャンプアップの更新.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpUpUpdate()
{
	// 一定の高さに行くまでジャンプアップ中にする
	if (mJumpUpNowNpc)
	{
		mIsGroundNpc = false; // 地面に接地していない

		if (!mThirdJumpNpc)   // 飛び込み以外だったらY軸だけ上げていく
		{
			mVelocityNpc = VGet(0.0f, JUMP_UP_Y, 0.0f);
		}
		else               // 飛び込みだったらY軸とZ軸を上げる
		{
			mVelocityNpc = VAdd(VGet(0.0f, JUMP_UP_Y, 0.0f), mAdd);
		}

		// 最大の高さを更新、設定----------
		if (mSecondJumpNpc)   // 2回目のジャンプだったら
		{
			mJumpMaxNpc = SECOND_MAX;
		}
		if (mThirdJumpNpc)    // 飛び込みのジャンプだったら
		{
			mJumpMaxNpc = THIRD_MAX;
		}
		//---------------------------

	}

	// 設定した最大値より上に行ったら--------------
	if (mPosNpc.y >= (mInitPos.y + mJumpMaxNpc))
	{
		mJumpUpNowNpc = false;    // もう上がらないのでUpNowをfalseにする

		// ジャンプダウンの更新に入る
		NpcJumpDownUpdate();
	}
}

//-----------------------------------------------------------------------------
// @brief  NPCの落ちてる時の更新.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpDownUpdate()
{
	if (!mThirdJumpNpc) // 飛び込み以外だったらY軸だけ下げていく
	{
		if (mPosNpc.y >= (mInitPos.y + mJumpMaxNpc))
		{
			mVelocityNpc = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // 飛び込みだったらY軸とZ軸を下げる
	{
		if (mPosNpc.y >= (mInitPos.y + mJumpMaxNpc))
		{
			mVelocityNpc = VAdd(VGet(0.0f, -JUMP_DOWN_Y, 0.0f), mSub);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  NPCのポジションの更新.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpPosUpdate()
{
	// y軸に力がかかった時に重力値をつける
	if (mVelocityNpc.y != 0.0f)
	{
		mVelocityNpc.y = mVelocityNpc.y - (mGravityNpc / mPosNpc.y);
	}
	// ポジションを更新
	mPosNpc = VAdd(mPosNpc, mVelocityNpc);


	// 初期位置orプールまでいったら動きを止め次のジャンプに移行する
	if (!mThirdJumpNpc)
	{
		if (!mIsGroundNpc && mPosNpc.y <= mInitPos.y)
		{
			mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
			mPosNpc.y = mInitPos.y;
			mIsGroundNpc = true;          // 地面に接地している 

			if (mFirstJumpNpc)
			{
				mFirstJumpNpc = false;        // 1回目のジャンプを終了する
				mSecondJumpNpc = true;        // 2回目のジャンプができるようにする
			}
			else
			{
				mSecondJumpNpc = false;       // 1回目のジャンプを終了する
				mThirdJumpNpc = true;         // 飛び込みのジャンプができるようにする
			}
		}
	}
	else// 飛び込みの場合
	{
		if (!mIsGroundNpc)
		{
			if (mPosNpc.y <= 2.0f)
			{
				mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
				mPosNpc.y = 2.0f;              // プールに埋まっていたら押し戻す
				mIsGroundNpc = true;           // 地面に接地している 
				mThirdJumpNpc = false;         // 飛び込みのジャンプを終了する
			}
		}
	}
}
