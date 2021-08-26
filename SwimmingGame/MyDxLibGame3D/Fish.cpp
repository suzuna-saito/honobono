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

///// <summary>
///// 描画関数
///// </summary>
/*void Fish::Draw()
{

	// Mob座標のセット
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		MV1SetPosition(mMHandle, mMobPos[i]);
		MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
		// Mob画像の描画
		MV1DrawModel(mMHandle);
 
		//-------------------------------------------------
	}	//どの配列がどの位置の魚を示しているのかのデバック
	
	
	
	
	

	
	
	

	
	
	

	
	
	
	
	

	
	
	

	
	
	

	
	
	

	
	
	

	
	
	

	
	
	

	

	
	
	
*/