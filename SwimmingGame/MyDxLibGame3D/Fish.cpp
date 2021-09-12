#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include"Input.h"
#include"Dance.h"

/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
	, mJumpUpdataFlag(false)
	, mJumpedInFlag(false)
{
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	mJump = new Jump();
	mDance = new Dance(mSetDancePos);
}

/// <summary>
/// デストラクタ
/// </summary>
Fish::~Fish()
{
	//処理なし
}

/// <summary>
/// 更新関数
/// </summary>
void Fish::Updata()
{
	if (mMoveFlag)
	{
		// ポジションの更新
		mPos = VAdd(mPos, mVelocity);
	}

	if (!mJumpedInFlag)
	{
		//飛び込みの処理
		JumpUpdata();
	}
	else
	{
		//アーティスティックスイミングの処理
		DanceUpdata();
	}
	
}

/// <summary>
/// ジャンプの更新を入れた関数 : @saito
/// </summary>
void Fish::JumpUpdata()
{
	// 全てのジャンプが終わっていない状態で
	// ボタンが押されたら、またはtimingゲージが縮小し終わったらジャンプする（ってしたい）
	if (mJump->GetNowJump() != mJump->endJump &&
		(Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround())/*||
		(mTiming->GetRadius() <= 1 && mJump->GetIsGround())*/)
	{
		// ジャンプの更新をするようにする
		mJumpUpdataFlag = true;
	}

	if (mJumpUpdataFlag)
	{
		//ジャンプの更新
		mJump->JumpUpdate(mRotate);

		// 今のジャンプが飛び込みじゃない、かつ、増加量が0になったら
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();
			// ジャンプの更新を止める
			mJumpUpdataFlag = false;
		}
		// 今のジャンプが飛び込みで、プールのところまでいったら
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 0.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();

			// 押し戻し…？
			mPos.y = 0.0f;

			// ジャンプの更新を止める
			mJumpUpdataFlag = false;

			//ジャンプの更新処理が終わったことを示すためtrueにする
			mJumpedInFlag = true;
		}
	}

	mVelocity = mJump->GetVelocity();
}

/// <summary>
/// アーティスティックスイミングの更新処理を入れた関数
/// </summary>
void Fish::DanceUpdata()
{
	//もし魚が移動をし終わったとき
	if (mDance->GetStopSetPosFlag())
	{
		mMoveFlag = false;
		mSetDancePosFlag = true;
	}
	//移動し終わっていないとき
	else
	{
		mMoveFlag = true;
		mVelocity = mDance->MoveTargetPos(mSetDancePos, mPos, mRotate);
		mSetDancePosFlag = false;
	}
}