#include "Fish.h"
#include "Common.h"
#include "NpcJump.h"

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

	mNpcJump = new NpcJump();
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
	if (mNpcJump->GetGroundNpc())
	{
		mNpcJump->SetJumpNpc(true);
	}

	// １回目、２回目、飛び込みいずれかのフラグがtrueだったら
	if (mNpcJump->GetFirstNpc() || mNpcJump->GetSecondNpc() || mNpcJump->GetThirdNpc())
	{
		// ジャンプの更新をする
		mNpcJump->NpcJumpUpdate(GetPos(), GetRotate());

		// ポジションをセット
		SetPos(mNpcJump->GetPosNpc());
	}


}

/// <summary>
/// アーティスティックスイミング開始時のセットポジション
/// </summary>
/// <param name="_setPos">アーティスティックスイミング開始時のポジション</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
