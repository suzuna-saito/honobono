#include "Jump.h"

//----------------------
//定数
//----------------------
const float JUMP_UP_Y = 0.5f;      // ジャンプした時のY軸の加算値
const float JUMP_DOWN_Y = 0.25f;   // ジャンプした後のY軸の減算値

const float JUMP_UP_Z = 0.2f;     // ジャンプした時のz軸の加算値
const float JUMP_DOWN_Z = 0.2f;    // ジャンプした時のz軸の減算値

const float JUMP_UP_X = 0.15f;     // ジャンプした時のx軸の加算値
const float JUMP_DOWN_X = 0.025f;    // ジャンプした時のx軸の減算値

const float FIRST_MAX = 3.0f;     // 1回目ジャンプの最大ジャンプ力
const float SECOND_MAX = 5.0f;    // 2回目ジャンプの最大ジャンプ力
const float THIRD_MAX = 8.0f;     // 飛び込みの最大ジャンプ力

const float INIT_POS_Y = 23.0f;    // ジャンプ台の高さ
const float INIT_POS_Y2 = 18.0f;   // ジャンプ台の高さ
const float INIT_POS_Y3 = 11.0f;    // ジャンプ台の高さ


//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Jump::Jump()
	: mPos(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMax(FIRST_MAX)
	, mFirstJump(true)
	, mSecondJump(false)
	, mThirdJump(false)
	, mJumpUpNow(false)
	, mIsGround(true)
	, mInitPos(VGet(0.0f, 0.0f, 0.0f))
	, mGravity(0.0007f)
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
// @brief  NPCのジャンプ更新.
//-----------------------------------------------------------------------------
void Jump::JumpUpdate(VECTOR _pos,VECTOR _rotate)
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
	else if (_pos.y == INIT_POS_Y)
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

	// 今のポジションをセット
	SetPos(_pos);

	// ジャンプアップの更新
	JumpUpUpdate();

	// ポジション更新
	JumpPosUpdate();

}

//-----------------------------------------------------------------------------
// @brief  NPCのジャンプアップの更新.
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
			mVelocity = VAdd(VGet(0.0f, JUMP_UP_Y, 0.0f), mAdd);
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
	if (mPos.y >= (mInitPos.y + mJumpMax))
	{
		mJumpUpNow = false;    // もう上がらないのでUpNowをfalseにする

		// ジャンプダウンの更新に入る
		JumpDownUpdate();
	}
}

//-----------------------------------------------------------------------------
// @brief  NPCの落ちてる時の更新.
//-----------------------------------------------------------------------------
void Jump::JumpDownUpdate()
{
	if (!mThirdJump) // 飛び込み以外だったらY軸だけ下げていく
	{
		if (mPos.y >= (mInitPos.y + mJumpMax))
		{
			mVelocity = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // 飛び込みだったらY軸とZ軸を下げる
	{
		if (mPos.y >= (mInitPos.y + mJumpMax))
		{
			mVelocity = VAdd(VGet(0.0f, -JUMP_DOWN_Y, 0.0f), mSub);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  NPCのポジションの更新.
//-----------------------------------------------------------------------------
void Jump::JumpPosUpdate()
{
	// y軸に力がかかった時に重力値をつける
	if (mVelocity.y != 0.0f)
	{
		mVelocity.y = mVelocity.y - (mGravity * mPos.y);
	}
	// ポジションを更新
	mPos = VAdd(mPos, mVelocity);


	// 初期位置orプールまでいったら動きを止め次のジャンプに移行する
	if (!mThirdJump)
	{
		if (!mIsGround && mPos.y <= mInitPos.y)
		{
			mVelocity = VGet(0.0f, 0.0f, 0.0f);
			mPos.y = mInitPos.y;
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
