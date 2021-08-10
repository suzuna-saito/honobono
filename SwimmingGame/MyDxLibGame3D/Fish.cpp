#include "Fish.h"
#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish()
	: FISH_MOB_ROTATE{VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)
	                 ,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)
	                 ,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f, 0.0f,0.0f)
	                 ,VGet(0.0f,0.0f,0.0f),VGet(0.0f,0.0f,0.0f) }
	, FISH_MOB_NUM(11)
	, mMobPos{ VGet(1.5f,15.0f,-28.0f),VGet(12.0f,9.0f,-28.0f),VGet(-7.0f,20.0f,26.0f)
	          ,VGet(-2.0f,15.0f,28.0f),VGet(-12.0f,9.0f,29.0f),VGet(-16.0f,20.0f,-7.0f)
	          ,VGet(-17.0f,15.0f,-2.0f),VGet(-17.0f,9.0f,-12.0f),VGet(16.0f,20.0f,7.0f)
	          ,VGet(17.0f,15.0f,2.0f),VGet(17.0f,9.0f,12.0f) }
{
	// 画像データの読み込み
	mMHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");
	MobFishTexture = LoadGraph("data/model/fish/MobFish.png");
	// 画像サイズ変更
	MV1SetScale(mMHandle, FISH_SIZE);
	MV1SetTextureGraphHandle(mMHandle, 0, MobFishTexture, FALSE);
}

/// <summary>
/// デストラクタ
/// </summary>
Fish::~Fish()
{
	// 画像データの消去
	MV1DeleteModel(mMHandle);
	DeleteGraph(MobFishTexture);
}

/// <summary>
/// 更新関数
/// </summary>
void Fish::Update()
{

}

/// <summary>
/// 描画関数
/// </summary>
void Fish::Draw()
{
	// Mob座標のセット
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		MV1SetPosition(mMHandle, mMobPos[i]);
		MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
		// Mob画像の描画
		MV1DrawModel(mMHandle);
	}
}

