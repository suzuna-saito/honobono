#include "BackGround.h"

// 定数-------------------------------
const float WIDTH = 100.0f;    // 原点からの離れている長さ
const float CEILING = 140.0f;  // 天井の高さ
const float POS_Y = 70.0f;     // 壁のポジションｙ

const float SIZE_X = 10.0f;    // サイズを変更する際のｘ（天井と床はｚ軸にも使われている）
const float SIZE_Z = 7.0f;     // サイズを変更する際のｚ
// ------------------------------------


BackGround::BackGround()
	: mPos{ VGet(0.0f, CEILING, 0.0f),VGet(0.0f, 0.0f, 0.0f),VGet(WIDTH, POS_Y, 0.0f)
		  ,VGet(-WIDTH, POS_Y, 0.0f),VGet(0.0f, POS_Y, WIDTH),VGet(0.0f, POS_Y, -WIDTH) }
	, mSize{ VGet(SIZE_X, 1.0f, SIZE_X),VGet(SIZE_X, 1.0f, SIZE_X),VGet(SIZE_X, 1.0f, SIZE_Z)
		   ,VGet(SIZE_X, 1.0f, SIZE_Z),VGet(SIZE_X, 1.0f, SIZE_Z),VGet(SIZE_X, 1.0f, SIZE_Z) }
	, mRotate{ VGet(0.0f, 0.0f, 0.0f),VGet(0.0f, 0.0f, 0.0f)
			 ,VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 90.0f * DX_PI_F / 180.0f)
			 ,VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 90.0f * DX_PI_F / 180.0f)
			 ,VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f)
			 ,VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f) }
	, i(0)
	, WALL_NUM(6)
	, LIGHT_POS(VGet(0.0f, 70.0f, 0.0f))
	, LIGHT_ROTATE(VGet(0.0f, 0.0f, 0.0f))
{
	mModelHandle[0] = MV1LoadModel("data/model/Wall/UpWall.mqo");
	mModelHandle[1] = MV1LoadModel("data/model/Wall/DownWall.mqo");
	mModelHandle[2] = MV1LoadModel("data/model/Wall/BesideWall.mqo");
	mModelHandle[3] = MV1LoadModel("data/model/Wall/BesideWall.mqo");
	mModelHandle[4] = MV1LoadModel("data/model/Wall/VerticalWall.mqo");
	mModelHandle[5] = MV1LoadModel("data/model/Wall/VerticalWall.mqo");
	mTexture[0] = LoadGraph("data/model/Wall/Texture/SeaLevel.png", TRUE);
	mTexture[1] = LoadGraph("data/model/Wall/Texture/UnderSea.png", TRUE);
	mTexture[2] = LoadGraph("data/model/Wall/Texture/UnderWater01.png", TRUE);
	mTexture[3] = LoadGraph("data/model/Wall/Texture/UnderWater01.png", TRUE);
	mTexture[4] = LoadGraph("data/model/Wall/Texture/UnderWater02.png", TRUE);
	mTexture[5] = LoadGraph("data/model/Wall/Texture/UnderWater02.png", TRUE);
}

BackGround::~BackGround()
{
	MV1DeleteModel(*mModelHandle);
	DeleteGraph(*mTexture);
}

void BackGround::Draw()
{
	for (i = 0; i < WALL_NUM; i++)
	{
		MV1SetScale(mModelHandle[i], mSize[i]);
		MV1SetRotationXYZ(mModelHandle[i], mRotate[i]);
		MV1SetPosition(mModelHandle[i], mPos[i]);
		MV1SetTextureGraphHandle(mModelHandle[i], 0, mTexture[i], TRUE);
		MV1DrawModel(mModelHandle[i]);
	}
}
