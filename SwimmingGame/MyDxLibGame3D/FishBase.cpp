#include "FishBase.h"
#include<math.h>
#include<Windows.h>

// 魚のサイズ変更値
const VECTOR FISH_SIZE = (VGet(0.2f, 0.2f, 0.2f));


/// <summary>
/// コンストラクタ
/// </summary>
FishBase::FishBase(int _sourceModelHandle, int _sourceModelTexture)
	:mModelHandle(-1)
	, mModelFishTexture(-1)
	, mPos(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mRotate(VGet(0.0f, 0.0f, 0.0f))
	, mSetDancePos(VGet(0.0f, 0.0f, 0.0f))
	, mInPoolFlag(false)
{
	// 画像データの読み込み
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);
	mModelFishTexture = _sourceModelTexture;

	if (mModelHandle < 0)
	{
		printfDx("モデルデータ読み込みに失敗. sourceID : %d", _sourceModelHandle);
	}
	else if (mModelFishTexture < 0)
	{
		printfDx("テクスチャデータ読み込みに失敗. sourceID : %d", _sourceModelTexture);
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
	// 画像データの消去
	MV1DeleteModel(mModelHandle);
	DeleteGraph(mModelFishTexture);
}

/// <summary>
/// 更新関数
/// </summary>
void FishBase::Updata(FishBase* _mobFish)
{
	if (_mobFish->mPos.y != 0.0f)
	{
		_mobFish->SetDancePos(_mobFish->mSetDancePos);
	}
}

/// <summary>
/// アーティスティックスイミング開始時のポジションに移動する
/// </summary>
/// <param name="_setDancePos">アーティスティックスイミング開始時ポジション</param>
void FishBase::SetDancePos(VECTOR _setDancePos)
{
	//開始時のポジションが今いるポジションと違うのであれば更新を行わない
	if (VSize(_setDancePos) != VSize(mPos))
	{
		return;
	}
	else 
	{
		//見た目の向き
		mRotate = VGet(0.0f, 0.0f, 0.0f);
		
		//開始時の移動方向を単位ベクトル化
		mVelocity = VNorm(VSub(_setDancePos, mPos));
		//その方向にvelocity分だけ移動
		mPos = VAdd(mVelocity, mPos);
	}
}


/// <summary>
/// 描画関数
/// </summary>
void FishBase::Draw()
{
	//ポジションを設定して描画する
	MV1SetPosition(mModelHandle, mPos);
	//モデルの向きを設定して描画する
	MV1SetRotationXYZ(mModelHandle, mRotate);

	//モデルを描画する
	MV1DrawModel(mModelHandle);

	//// Mob座標のセット
	//for (int i = 0; i < FISH_MOB_NUM; i++)
	//{
	//	MV1SetPosition(mMHandle, mMobPos[i]);
	//	MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
	//	// Mob画像の描画
	//	MV1DrawModel(mMHandle);
	//}
}

