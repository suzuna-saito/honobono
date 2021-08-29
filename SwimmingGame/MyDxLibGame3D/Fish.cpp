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
	// １回目、２回目、飛び込みいずれかのフラグがtrueだったら(終わっていない状態だったら)
	if (mJump->GetFirst() || mJump->GetSecond() || mJump->GetThird())
	{
		// ボタンが押されたらジャンプする
		// またはtimingゲージが縮小し終わったら勝手にジャンプする（ってしたい）
		if ((Key[KEY_INPUT_SPACE] == 1 && mJump->GetGround())/*||
			(mTiming->GetRadius() <= 1 && mJump->GetGround())*/)
		{
			// ジャンプ中かどうかのフラグをtrueにする
			mJump->SetJump(true);
		}

		// ジャンプの更新をする
		mJump->JumpUpdate(mPos, mRotate);
		// ポジションの更新
		mPos = mJump->GetPos();
	}
	///* 全てのジャンプが終わったらプレイヤーが0の所に行くまで直進させる
	//else if (mPos.z <= 0.0f)
	//{
	//	mVelocity = VGet(0.0f, 0.0f, 0.2f);
	//	mPos = VAdd(mPos, mVelocity);
	//}*/
}

/// <summary>
/// アーティスティックスイミング開始時のセットポジション
/// </summary>
/// <param name="_setPos">アーティスティックスイミング開始時のポジション</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
