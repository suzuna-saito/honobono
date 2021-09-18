#include "FishBase.h"
#include "Common.h"
#include<math.h>
#include<Windows.h>

//---------Debug用定数-----------------
const int SPHERE_POLYGON_FINENESS = 5;

/// <summary>
/// コンストラクタ
/// </summary>
FishBase::FishBase(int _sourceModelHandle)
	:mModelHandle(-1)
	, mPos(ZERO_VECTOR)
	, mRotate(ZERO_VECTOR)
	, mSetDancePos(ZERO_VECTOR)
	, mVelocity(ZERO_VECTOR)
	, mTempVelocity(ZERO_VECTOR)
	, mSetDanceFlag(false)
	, mDanceStartCount(0)
{
	// 画像データの読み込み
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);

	//モデルが入っていないかったとき
	if (mModelHandle < 0)
	{
		printfDx("モデルデータ読み込みに失敗. sourceID : %d", _sourceModelHandle);
	}

	// 画像サイズ変更
	MV1SetScale(mModelHandle, FISH_SIZE);
}

/// <summary>
/// デストラクタ
/// </summary>
FishBase::~FishBase()
{
	// モデルとテクスチャデータの消去
	MV1DeleteModel(mModelHandle);
}


/// <summary>
/// 描画関数
/// </summary>
void FishBase::Draw(int _debugColor)
{
	//ポジションを設定
	MV1SetPosition(mModelHandle, mPos);
	//モデルの向きを設定
	MV1SetRotationXYZ(mModelHandle, mRotate);

	//モデルを描画する
	MV1DrawModel(mModelHandle);

	//------------------------------------------------
	//デバック用DrawSphere3D
	//DrawSphere3D(mPos, DEBUG_RADIUS, SPHERE_POLYGON_FINENESS, _debugColor, _debugColor, false);

}

