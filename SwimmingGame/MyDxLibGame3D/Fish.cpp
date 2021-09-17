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
void Fish::Updata(int _judge)
{
	// 演技前
	if (!mJumpedInFlag)
	{
		//飛び込みの処理
		JumpUpdata(_judge);
	}
	// 演技中
	else
	{
		//アーティスティックスイミングの処理
		//DanceUpdata();

		// ジャンプの処理
		JumpUpdata(_judge);
	}
	
	// ポジションの更新
	mPos = VAdd(mPos, mJump->GetVelocity());
}

/// <summary>
/// ジャンプの更新を入れた関数 : @saito
/// </summary>
void Fish::JumpUpdata(int _judge)
{
	// ボタンが押されたら、またはtimingゲージが縮小し終わったらジャンプする（ってしたい）
	if ((Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround()) && _judge != 4 ||
		_judge == 3)
	{
		// ジャンプの更新をするようにする
		mJumpUpdataFlag = true;
	}

	// 飛び込みの時
	if (mJumpUpdataFlag && mJump->GetNowJump() != mJump->endDive)
	{
		//ジャンプの更新
		mJump->DiveUpdate(mRotate);

		// 今のジャンプが飛び込みじゃない、かつ、増加量が0になったら
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();
			// ジャンプの更新を止める
			mJumpUpdataFlag = false;
		}
		// 今のジャンプが飛び込みで、プールのところまでいったら
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 4.5f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();

			// 押し戻し…？
			mPos.y = 4.5f;

			// ジャンプの更新を止める
			mJumpUpdataFlag = false;

			//ジャンプの更新処理が終わったことを示すためtrueにする
			mJumpedInFlag = true;
		}
	}

	// ジャンプの時
	else if (mJumpUpdataFlag && mJump->GetNowJump() == mJump->endDive)
	{
		// ジャンプの更新
		mJump->JumpUpdate(_judge);

		// 増加量が0になったら
		if (mJump->GetGain() <= 0.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();

			// ジャンプの更新を止める
			mJumpUpdataFlag = false;
		}
	}
}

/// <summary>
/// アーティスティックスイミングの更新処理を入れた関数
/// </summary>
void Fish::DanceUpdata()
{
	if (mDance->SetDancePos(mSetDancePos, mPos, mRotate))
	{
		
	}
	
}