#include "Promotion.h"

// 定数
const int DRAW_X = 45;
const int DRAW_Y = 85;
const int DRAW_Y2 = 0;
const int PROMOBASE_NUM = 2;
const int PROMO_NUM = 16;

/// <summary>
/// コンストラクタ
/// </summary>
Promotion::Promotion()
	: mBaseDrawPos1{VGet(0.0f, 10.0f, 70.0f),       // 土台1
					VGet(0.0f, 10.0f, -70.0f),      // 土台1
}
	, mBaseDrawPos2{VGet(50.0f, 10.0f, 0.0f),       // 土台2
					VGet(-50.0f, 10.0f, 0.0f),      // 土台2
}
	, mPromoDrawPos{VGet(-25.0f, 10.0f,  69.0f),     // 正面１
					VGet(  0.0f, 10.0f,  69.0f),     // 正面２
					VGet( 25.0f, 10.0f,  69.0f),     // 正面３
					VGet(-49.0f, 10.1f,  55.0f),     // 左１
					VGet(-49.0f, 10.1f,  30.0f),     // 左２
					VGet(-49.0f, 10.1f,   5.0f),     // 左３
					VGet(-49.0f, 10.1f, -20.0f),     // 左４
					VGet(-49.0f, 10.1f, -45.0f),     // 左５
					VGet( 49.0f, 10.1f,  55.0f),     // 右１
					VGet( 49.0f, 10.1f,  30.0f),     // 右２
					VGet( 49.0f, 10.1f,   5.0f),     // 右３
					VGet( 49.0f, 10.1f, -20.0f),     // 右４
					VGet( 49.0f, 10.1f, -45.0f),     // 右５
					VGet(-25.0f, 10.1f, -69.0f),     // 後１
					VGet(  0.0f, 10.1f, -69.0f),     // 後２
					VGet( 25.0f, 10.1f, -69.0f)      // 後３
}
	, mSetSize(VGet(0.05f, 0.05f, 0.1f))
	, mPromo{ -1 }
	, mPromoBase1{ -1 }
	, mPromoBase2{ -1 }
{
	// モデルのロード
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		mPromoBase1[i] = MV1LoadModel("data/promotion/untitled4.mv1");
		mPromoBase2[i] = MV1LoadModel("data/promotion/untitled3.mv1");
	}
	for (int i = 0; i < PROMO_NUM; i++)
	{
		mPromo[i] = MV1LoadModel("data/promotion/base.mv1");
	}

	// 画像のロード
	mBase = LoadGraph("data/promotion/Texture/base.png");
	mSimple = LoadGraph("data/promotion/Texture/sinkuro.png");
	mFalsoc = LoadGraph("data/promotion/Texture/falsoc2.png");
	mSchool = LoadGraph("data/promotion/Texture/gakkou2.png");
	mHonobono = LoadGraph("data/promotion/Texture/honobono.png");
	mKora = LoadGraph("data/promotion/Texture/ko-ra2.png");
	mJapan = LoadGraph("data/promotion/Texture/nihon.png");
	mYamako = LoadGraph("data/promotion/Texture/yamako2.png");	
}

/// <summary>
/// デストラクタ
/// </summary>
Promotion::~Promotion()
{
	// モデルデータの削除
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		MV1DeleteModel(mPromoBase1[i]);
		mPromoBase1[i] = NULL;
	}
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		MV1DeleteModel(mPromoBase2[i]);
		mPromoBase2[i] = NULL;
	}
	for (int i = 0; i < PROMO_NUM; i++)
	{
		MV1DeleteModel(mPromo[i]);
		mPromo[i] = NULL;
	}

	// 画像データの削除
	DeleteGraph(mSimple);
	DeleteGraph(mFalsoc);
	DeleteGraph(mSchool);
	DeleteGraph(mHonobono);
	DeleteGraph(mKora);
	DeleteGraph(mJapan);
	DeleteGraph(mYamako);
}

/// <summary>
/// 描画
/// </summary>
void Promotion::Draw()
{	
	// ポジションのセット
	SetPromo();
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		MV1DrawModel(mPromoBase1[i]);
		MV1DrawModel(mPromoBase2[i]);
	}
	
	for (int i = 0; i < PROMO_NUM; i++)
	{
		MV1DrawModel(mPromo[i]);
	}

	//// 一旦
	//if (GetCameraAngleHRotate() == 0.0f)
	//{
	//}
}

/// <summary>
/// 広告の設定
/// </summary>
void Promotion::SetPromo()
{
	// 広告の土台のポジション・大きさのセット
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		MV1SetScale(mPromoBase1[i], mSetSize);
		MV1SetScale(mPromoBase2[i], mSetSize);

		MV1SetPosition(mPromoBase1[i], mBaseDrawPos1[i]);
		MV1SetPosition(mPromoBase2[i], mBaseDrawPos2[i]);
	}
	MV1SetRotationXYZ(mPromoBase1[1], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromoBase2[1], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));

	// 広告のポジション・大きさのセット
	for (int i = 0; i < PROMO_NUM; i++)
	{
		MV1SetScale(mPromo[i], mSetSize);
		MV1SetPosition(mPromo[i], mPromoDrawPos[i]);
	}
	MV1SetRotationXYZ(mPromo[3], VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[4], VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[5], VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[6], VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[7], VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0));

	MV1SetRotationXYZ(mPromo[8], VGet(0.0f,  90.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[9], VGet(0.0f,  90.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[10], VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[11], VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[12], VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0));

	MV1SetRotationXYZ(mPromo[13], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[14], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromo[15], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));

	//// モデルにテクスチャ貼り付け
	MV1SetTextureGraphHandle(mPromo[0], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[1], 0, mHonobono, TRUE);
	MV1SetTextureGraphHandle(mPromo[2], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[3], 0, mSchool, TRUE);
	MV1SetTextureGraphHandle(mPromo[4], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[5], 0, mKora, TRUE);
	MV1SetTextureGraphHandle(mPromo[6], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[7], 0, mHonobono, FALSE);
	MV1SetTextureGraphHandle(mPromo[8], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[9], 0, mJapan, TRUE);
	MV1SetTextureGraphHandle(mPromo[10], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[11], 0, mYamako, FALSE);
	MV1SetTextureGraphHandle(mPromo[12], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[13], 0, mSchool, TRUE);
	MV1SetTextureGraphHandle(mPromo[14], 0, mSimple, TRUE);
	MV1SetTextureGraphHandle(mPromo[15], 0, mFalsoc, TRUE);

}
