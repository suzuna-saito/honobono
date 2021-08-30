#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include "Input.h"
#include "Timing.h"

/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
{
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	mVelocity = VGet(0.0f, 0.0f, 0.0f);

	mJumpFlag = false;

	mJump = new Jump();

	mTiming = new Timing();
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
	// 全てのジャンプが終わっていない状態で
	// ボタンが押されたら、またはtimingゲージが縮小し終わったらジャンプする（ってしたい）
	if (mJump->GetNowJump() != mJump->endJump &&
		(Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround())/*||
		(mTiming->GetRadius() <= 1 && mJump->GetIsGround())*/)
	{
		// ジャンプの更新をするようにする
		mJumpFlag = true;
	}

	if (mJumpFlag)
	{
		//ジャンプの更新
		mJump->JumpUpdate(mRotate);

		// 今のジャンプが飛び込みじゃない、かつ、増加量が0になったら
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();
			// ジャンプの更新を止める
			mJumpFlag = false;
		}
		// 今のジャンプが飛び込みで、プールのところまでいったら
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 2.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();

			// 押し戻し…？
			mPos.y = 2.0f;

			// ジャンプの更新を止める
			mJumpFlag = false;
		}
	}

	// ポジションの更新
	mPos = VAdd(mPos, mJump->GetVelocity());
}

/// <summary>
/// アーティスティックスイミング開始時のセットポジション
/// </summary>
/// <param name="_setPos">アーティスティックスイミング開始時のポジション</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
