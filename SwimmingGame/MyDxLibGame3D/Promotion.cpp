#include "Promotion.h"

// 定数
const int DRAW_X = 45;
const int DRAW_Y = 15;
const int DRAW_Y2 = 0;

Promotion::Promotion()
	: mDrawPos(VGet(0.0f, 13.0f, 68.0f))  // 表示させるポジション
	, mPromo(-1)
{
	mPromo = MV1LoadModel("data/promotion/untitled.mv1");

	// 一番シンプルな画像
	mSimple = LoadGraph("data/promotion/sinkuro.jpg");
}

Promotion::~Promotion()
{
}

void Promotion::Draw()
{
	MV1SetScale(mPromo, VGet(0.005f,0.005f,0.01f));
	/*MV1SetRotationXYZ(mPromo, VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f));*/
	MV1SetPosition(mPromo, mDrawPos);
	MV1SetTextureGraphHandle(mPromo, 0, mSimple, TRUE);
	MV1DrawModel(mPromo);

	// 3D空間に画像を描画          ↓左上頂点↓     ↓右上頂点↓    ↓右下頂点↓    ↓左下頂点↓
	/*DrawModiBillboard3D(mDrawPos, -DRAW_X, DRAW_Y, DRAW_X, DRAW_Y, DRAW_X, DRAW_Y2, -DRAW_X, DRAW_Y2, mSimple, TRUE);*/

	//DrawBillboard3D(mDrawPos, 0.5f, 0.5f, 50.0f,  0.0f, mSimple, TRUE);

	

	//// 一旦
	//if (GetCameraAngleHRotate() == 0.0f)
	//{
	//}
}
