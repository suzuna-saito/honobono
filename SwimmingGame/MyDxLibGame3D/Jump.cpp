#include "Jump.h"

//----------------------
//定数
//----------------------
const float JUMP_Y = 0.35f;          // ジャンプした時のY軸の加算値
const float JUMP_Z = 0.25f;         // ジャンプした時のz軸の加算値
const float JUMP_X = 0.15f;         // ジャンプした時のx軸の加算値

const float FIRST_MAX = 3.0f;        // 1回目ジャンプの最大ジャンプ力
const float SECOND_MAX = 5.0f;       // 2回目ジャンプの最大ジャンプ力
const float THIRD_MAX = 8.0f;        // 飛び込みの最大ジャンプ力

const float GOOD = 3.0f;           // goodの時のジャンプ力
const float PERFECT = 7.0f;        // perfectの時のジャンプ力


//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Jump::Jump()
	: mGravity(0.2f)
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMax(FIRST_MAX)
	, mGain(0.0f)
	, mJumpUp(true)
	, mIsGround(true)
	, mNowJump(firstJump)
	, mChange(VGet(0.0f, 0.0f, 0.0f))
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
void Jump::DiveUpdate(VECTOR _rotate)
{
	// 魚の向きによって飛び込む方向を換える
	switch ((int)_rotate.y)
	{
		case (int)(90.0f * DX_PI_F / 180.0f) :
			mChange.z = JUMP_Z;
			break;

			case(int)(-90.0f * DX_PI_F / 180.0f) :
				mChange.z = -JUMP_Z;
				break;

				case(int)(180.0f * DX_PI_F / 180.0f) :
					mChange.x = JUMP_X;
					break;

					case(int)(0.0f, 0.0f, 0.0f) :
						mChange.x = -JUMP_X;
						break;

					default:
						break;
	}

	// 飛び込みの更新
	DiveNowUpdate();
}

//-----------------------------------------------------------------------------
// @brief  飛び込みの更新.
//-----------------------------------------------------------------------------
void Jump::DiveNowUpdate()
{
	// 一定の高さに行くまでジャンプを上げていく
	if (mJumpUp)
	{
		mIsGround = false;           // 地面に接地していない

		if (mNowJump != thirdJump)   // 飛び込み以外だったらY軸だけ上げていく
		{
			mVelocity = VGet(0.0f, JUMP_Y, 0.0f);
		}
		else                         // 飛び込みだったらY軸とZ軸(またはx軸)を上げる
		{
			mVelocity = VAdd(VGet(0.0f, JUMP_Y, 0.0f), mChange);
		}

		// 設定した最大値より増加した量が上に行ったら
		if (mGain >= mJumpMax)
		{
			mJumpUp = false;       // もう上がらないのでfalseにする
		}
	}
	if (!mJumpUp) // 下げていく
	{
		if (mNowJump != thirdJump) // 飛び込み以外だったらY軸だけ下げていく
		{
			mVelocity = VGet(0.0f, -JUMP_Y, 0.0f);
		}
		else                       // 飛び込みだったらY軸とZ軸を下げる
		{
			mVelocity = VAdd(VGet(0.0f, -JUMP_Y, 0.0f), mChange);
		}
	}

	// 増加量の計算
	mGain += mVelocity.y;
}


//-----------------------------------------------------------------------------
// @brief  ジャンプの更新.
//-----------------------------------------------------------------------------
void Jump::JumpUpdate(int _jadge)
{
	switch (_jadge) // 判定
	{
	case 0:    // badの時
		mJumpMax = 0.0f;
		break;
	case 1:    // goodの時
		mJumpMax = GOOD;
		break;
	case 2:    // parfectの時
		mJumpMax = PERFECT;
		break;
	default:
		break;
	}

	// 一定の高さに行くまでジャンプを上げていく
	if (mJumpUp)
	{
		mIsGround = false;                     // 地面に接地していない

		mVelocity = VGet(0.0f, JUMP_Y, 0.0f);  // ヴェロシティを設定

		// 設定した最大値より増加した量が上に行ったら
		if (mGain >= mJumpMax)
		{
			mJumpUp = false;       // もう上がらないのでfalseにする
		}
	}
	if (!mJumpUp) // 下げていく
	{
		mVelocity = VGet(0.0f, -JUMP_Y, 0.0f);

	}

	// 増加量の計算
	mGain += mVelocity.y;
}

//-----------------------------------------------------------------------------
// @brief  ジャンプタイプの更新.
//-----------------------------------------------------------------------------
void Jump::JumpSetUpdate()
{
	mVelocity = VGet(0.0f, 0.0f, 0.0f);   // 移動力を初期値に戻す
	mIsGround = true;                     // 地面との接地判定
	mJumpUp = true;                       // 次のジャンプのためにtrueにする
	mGain = 0.0f;                         // 次のジャンプのために増加量を0.0fにする

	switch (mNowJump)           // 今のジャンプが
	{
	case firstJump:             // 1回目のジャンプだったら
		mNowJump = secondJump;  // 2回目のジャンプが出来るようにする
		mJumpMax = SECOND_MAX;  // 最大ジャンプ力の更新
		break;
	case secondJump:            // 2回目のジャンプだったら
		mNowJump = thirdJump;   // 飛び込みのジャンプが出来るようにする
		mJumpMax = THIRD_MAX;
		break;
	case thirdJump:             // 飛び込みのジャンプだったら
		mNowJump = endDive;     // ジャンプを終了する
		mJumpMax = 0.0f;
		break;
	default:
		mJumpMax = 0.0f;
		break;
	}
}