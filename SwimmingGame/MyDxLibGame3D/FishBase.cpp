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
	, mModelFishTexture(-1)
	, mPos(VGet(0.0f, 0.0f, 0.0f))
	, mRotate(VGet(0.0f, 0.0f, 0.0f))
	, mSetDancePos(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
{
	// 画像データの読み込み
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);

	if (mModelHandle < 0)
	{
		printfDx("モデルデータ読み込みに失敗. sourceID : %d", _sourceModelHandle);
	}

	// 画像サイズ変更
	MV1SetScale(mModelHandle, FISH_SIZE);
	MV1SetTextureGraphHandle(mModelHandle, 0, mModelFishTexture, false);
}

/// <summary>
/// デストラクタ
/// </summary>
FishBase::~FishBase()
{
	// モデルとテクスチャデータの消去
	MV1DeleteModel(mModelHandle);
	DeleteGraph(mModelFishTexture);
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
	DrawSphere3D(mPos, debugRad, SPHERE_POLYGON_FINENESS, _debugColor, _debugColor, false);

}

