#include "Fish.h"

/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish()
	: FISH_SIZE(VGet(0.2f, 0.2f, 0.2f))
	, FISH_ROTATE(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, FISH_MOB_ROTATE{VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)
	                 ,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)
	                 ,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f, 0.0f,0.0f)
	                 ,VGet(0.0f,0.0f,0.0f),VGet(0.0f,0.0f,0.0f) }
	, FISH_MOB_NUM(11)
	, mPos(VGet(7.0f,20.0f,-26.0f))
	, mMobPos{ VGet(1.5f,15.0f,-28.0f),VGet(12.0f,9.0f,-28.0f),VGet(-7.0f,20.0f,26.0f)
	          ,VGet(-2.0f,15.0f,28.0f),VGet(-12.0f,9.0f,29.0f),VGet(-16.0f,20.0f,-7.0f)
	          ,VGet(-17.0f,15.0f,-2.0f),VGet(-17.0f,9.0f,-12.0f),VGet(16.0f,20.0f,7.0f)
	          ,VGet(17.0f,15.0f,2.0f),VGet(17.0f,9.0f,12.0f) }
	, i(0)
{
	// 画像データの読み込み
	mPHandle = MV1LoadModel("data/model/fish/fish.mqo");
	mMHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");
	FishTexture = LoadGraph("data/model/fish/Fish.png");
	MobFishTexture = LoadGraph("data/model/fish/MobFish.png");
	// 画像サイズ変更
	MV1SetScale(mPHandle, FISH_SIZE);
	MV1SetScale(mMHandle, FISH_SIZE);
	MV1SetTextureGraphHandle(mPHandle, 0, FishTexture, FALSE);
	MV1SetTextureGraphHandle(mMHandle, 0, MobFishTexture, FALSE);
}

/// <summary>
/// デストラクタ
/// </summary>
Fish::~Fish()
{
	// 画像データの消去
	MV1DeleteModel(mPHandle);
	MV1DeleteModel(mMHandle);
	DeleteGraph(FishTexture);
	DeleteGraph(MobFishTexture);
}

/// <summary>
/// 描画関数
/// </summary>
void Fish::Draw()
{
	MV1SetPosition(mPHandle, mPos);
	MV1SetRotationXYZ(mPHandle, FISH_ROTATE);
	// Player画像の描画
	MV1DrawModel(mPHandle);
	// Mob座標のセット
	for (i = 0; i < FISH_MOB_NUM; i++)
	{
		MV1SetPosition(mMHandle, mMobPos[i]);
		MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
		// Mob画像の描画
		MV1DrawModel(mMHandle);
	}
}

/// <summary>
/// 更新関数
/// </summary>
void Fish::Update()
{
}
