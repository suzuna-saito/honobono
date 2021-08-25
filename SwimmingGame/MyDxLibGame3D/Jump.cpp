#include "Jump.h"

//----------------------
//定数
//----------------------
const float JUMP_UP_Y = 0.5f;      // ジャンプした時のY軸の加算値
const float JUMP_DOWN_Y = 0.25f;   // ジャンプした後のY軸の減算値

const float JUMP_UP_Z = 0.25f;     // ジャンプした時のz軸の加算値
const float JUMP_DOWN_Z = 0.2f;    // ジャンプした時のz軸の減算値

const float JUMP_UP_X = 0.25f;
const float JUMP_DOWN_X = 0.2f;

const float FIRST_MAX = 3.0f;     // 1回目ジャンプの最大ジャンプ力
const float SECOND_MAX = 5.0f;    // 2回目ジャンプの最大ジャンプ力
const float THIRD_MAX = 8.0f;     // 飛び込みの最大ジャンプ力

const float INIT_POS_Y = 23.0f;    // ジャンプ台の高さ(プレイヤーこれ)
const float INIT_POS_Y2 = 18.0f;   // ジャンプ台の高さ
const float INIT_POS_Y3 = 11.0f;    // ジャンプ台の高さ

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Jump::Jump()
	: mPos(VGet(0.0f, 0.0f, 0.0f))
	, mPosNpc(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mVelocityNpc(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMax(FIRST_MAX)
	, mJumpMaxNpc(FIRST_MAX)
	, mFirstJump(true)
	, mSecondJump(false)
	, mThirdJump(false)
	, mFirstJumpNpc(true)
	, mSecondJumpNpc(false)
	, mThirdJumpNpc(false)
	, mJumpUpNow(false)
	, mJumpUpNowNpc(false)
	, mIsGround(true)
	, mIsGroundNpc(true)
	, mGravity(0.2f)
	, mGravityNpc(0.005f)
	, mInitPos(0.0f)
	, mAdd(VGet(0.0f, 0.0f, 0.0f))
	, mSub(VGet(0.0f, 0.0f, 0.0f))
{
}
//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Jump::~Jump()
{
}

//-----------------------------------------------------------------------------
// @brief  ジャンプ更新.
//-----------------------------------------------------------------------------
void Jump::JumpUpdate(VECTOR _pos)
{
	SetPos(_pos);

	// ジャンプアップの更新
	JumpUpUpdate();

	// ポジション更新
	JumpPosUpdate();
}

//-----------------------------------------------------------------------------
// @brief  ジャンプアップの更新.
//-----------------------------------------------------------------------------
void Jump::JumpUpUpdate()
{
	// 一定の高さに行くまでジャンプアップ中にする
	if (mJumpUpNow)
	{
		mIsGround = false; // 地面に接地していない

		if (!mThirdJump)   // 飛び込み以外だったらY軸だけ上げていく
		{
			mVelocity = VGet(0.0f, JUMP_UP_Y, 0.0f);
		}
		else               // 飛び込みだったらY軸とZ軸を上げる
		{

			mVelocity = VGet(0.0f, JUMP_UP_Y, JUMP_UP_Z);
		}

		// 最大の高さを更新、設定----------
		if (mSecondJump)   // 2回目のジャンプだったら
		{
			mJumpMax = SECOND_MAX;
		}
		if (mThirdJump)    // 飛び込みのジャンプだったら
		{
			mJumpMax = THIRD_MAX;
		}
		//---------------------------

	}

	// 設定した最大値より上に行ったら--------------
	if (mPos.y >= (INIT_POS_Y + mJumpMax))
	{
		mJumpUpNow = false;    // もう上がらないのでUpNowをfalseにする

		// ジャンプダウンの更新に入る
		JumpDownUpdate();
	}
}
//-----------------------------------------------------------------------------
// @brief  落ちてる時の更新.
//-----------------------------------------------------------------------------
void Jump::JumpDownUpdate()
{
	if (!mThirdJump) // 飛び込み以外だったらY軸だけ下げていく
	{
		if (mPos.y >= (INIT_POS_Y + mJumpMax))
		{
			mVelocity = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // 飛び込みだったらY軸とZ軸を下げる
	{
		if (mPos.y >= (INIT_POS_Y + mJumpMax))
		{
			mVelocity = VGet(0.0f, -JUMP_DOWN_Y, JUMP_DOWN_Z);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  ポジションの更新.
//-----------------------------------------------------------------------------
void Jump::JumpPosUpdate()
{
	// y軸に力がかかった時に重力値をつける
	if (mVelocity.y != 0.0f)
	{
		mVelocity.y = mVelocity.y - (mGravity / mPos.y);
	}
	// ポジションを更新
	mPos = VAdd(mPos, mVelocity);



	// 初期位置orプールまでいったら動きを止め次のジャンプに移行する
	if (!mThirdJump)
	{
		if (!mIsGround && mPos.y <= INIT_POS_Y)
		{
			mVelocity = VGet(0.0f, 0.0f, 0.0f);
			mPos.y = INIT_POS_Y;
			mIsGround = true;          // 地面に接地している 

			if (mFirstJump)
			{
				mFirstJump = false;        // 1回目のジャンプを終了する
				mSecondJump = true;        // 2回目のジャンプができるようにする
			}
			else
			{
				mSecondJump = false;       // 2回目のジャンプを終了する
				mThirdJump = true;         // 飛び込みのジャンプができるようにする
			}
		}
	}
	else// 飛び込みの場合
	{
		if (!mIsGround)
		{
			if (mPos.y <= 2.0f)
			{
				mVelocity = VGet(0.0f, 0.0f, 0.0f);
				mPos.y = 2.0f;              // プールに埋まっていたら押し戻す
				mIsGround = true;           // 地面に接地している 
				mThirdJump = false;         // 飛び込みのジャンプを終了する
			}
		}
	}
}



/*-----------------------NPC関連-------------------------------------*/

//-----------------------------------------------------------------------------
// @brief  NPCのジャンプ更新.
//-----------------------------------------------------------------------------
void Jump::NpcJumpUpdate(VECTOR _pos, int _number)
{
	if (_number == 1 || _number == 4 || _number == 7 || _number == 10)
	{
		mInitPos = INIT_POS_Y3;
	}
	else if (_number == 0 || _number == 3 || _number == 6 || _number == 9)
	{
		mInitPos = INIT_POS_Y2;
	}
	else
	{
		mInitPos = INIT_POS_Y;
	}
	//----------------------------------------------------

	if (_number == 0 || _number == 1)
	{
		mAdd = VGet(0.0f, 0.0f, JUMP_UP_Z);
		mSub = VGet(0.0f, 0.0f, JUMP_DOWN_Z);
	}
	else if (_number == 2 || _number == 3 || _number == 4)
	{
		mAdd = VGet(0.0f, 0.0f, -JUMP_UP_Z);
		mSub = VGet(-JUMP_DOWN_Z, 0.0f, 0.0f);
	}
	else if (_number == 5 || _number == 6 || _number == 7)
	{
		mAdd = VGet(JUMP_UP_X, 0.0f, 0.0f);
		mSub = VGet(JUMP_DOWN_X, 0.0f, 0.0f);
	}
	else
	{
		mAdd = VGet(-JUMP_UP_X, 0.0f, 0.0f);
		mSub = VGet(-JUMP_DOWN_X, 0.0f, 0.0f);
	}
	SetPosNpc(_pos);

	// ジャンプアップの更新
	NpcJumpUpUpdate();

	// ポジション更新
	NpcJumpPosUpdate();
}

//-----------------------------------------------------------------------------
// @brief  NPCのジャンプアップの更新.
//-----------------------------------------------------------------------------
void Jump::NpcJumpUpUpdate()
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
	if (mPosNpc.y >= (mInitPos + mJumpMaxNpc))
	{
		mJumpUpNowNpc = false;    // もう上がらないのでUpNowをfalseにする

		// ジャンプダウンの更新に入る
		NpcJumpDownUpdate();
	}
}

//-----------------------------------------------------------------------------
// @brief  NPCの落ちてる時の更新.
//-----------------------------------------------------------------------------
void Jump::NpcJumpDownUpdate()
{
	if (!mThirdJumpNpc) // 飛び込み以外だったらY軸だけ下げていく
	{
		if (mPosNpc.y >= (mInitPos + mJumpMaxNpc))
		{
			mVelocityNpc = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // 飛び込みだったらY軸とZ軸を下げる
	{
		if (mPosNpc.y >= (mInitPos + mJumpMaxNpc))
		{
			mVelocityNpc = VAdd(VGet(0.0f, -JUMP_DOWN_Y, 0.0f), mSub);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  NPCのポジションの更新.
//-----------------------------------------------------------------------------
void Jump::NpcJumpPosUpdate()
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
		if (!mIsGroundNpc && mPosNpc.y <= mInitPos)
		{
			mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
			mPosNpc.y = mInitPos;
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
		if (!mIsGroundNpc && mPosNpc.y <= 0.0f)
		{
			if (mPosNpc.y <= 0.0f)
			{
				mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
				mPosNpc.y = 0.0f;              // プールに埋まっていたら押し戻す
				mIsGroundNpc = true;           // 地面に接地している 
				mThirdJumpNpc = false;         // 飛び込みのジャンプを終了する
			}
		}
	}
}
