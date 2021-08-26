#include "Fish.h"
#include "Common.h"

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
}

/// <summary>
/// アーティスティックスイミング開始時のセットポジション
/// </summary>
/// <param name="_setPos">アーティスティックスイミング開始時のポジション</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
