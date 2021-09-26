#include "Promotion.h"

// �萔
const int DRAW_X = 45;
const int DRAW_Y = 85;
const int DRAW_Y2 = 0;
const int PROMOBASE_NUM = 2;
const int PROMO_NUM = 16;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Promotion::Promotion()
	: mBaseDrawPos1{VGet(0.0f, 10.0f, 70.0f),       // �y��1
					VGet(0.0f, 10.0f, -70.0f),      // �y��1
}
	, mBaseDrawPos2{VGet(50.0f, 10.0f, 0.0f),       // �y��2
					VGet(-50.0f, 10.0f, 0.0f),      // �y��2
}
	, mPromoDrawPos{VGet(-25.0f, 10.0f,  69.0f),     // ���ʂP
					VGet(  0.0f, 10.0f,  69.0f),     // ���ʂQ
					VGet( 25.0f, 10.0f,  69.0f),     // ���ʂR
					VGet(-49.0f, 10.1f,  55.0f),     // ���P
					VGet(-49.0f, 10.1f,  30.0f),     // ���Q
					VGet(-49.0f, 10.1f,   5.0f),     // ���R
					VGet(-49.0f, 10.1f, -20.0f),     // ���S
					VGet(-49.0f, 10.1f, -45.0f),     // ���T
					VGet( 49.0f, 10.1f,  55.0f),     // �E�P
					VGet( 49.0f, 10.1f,  30.0f),     // �E�Q
					VGet( 49.0f, 10.1f,   5.0f),     // �E�R
					VGet( 49.0f, 10.1f, -20.0f),     // �E�S
					VGet( 49.0f, 10.1f, -45.0f),     // �E�T
					VGet(-25.0f, 10.1f, -69.0f),     // ��P
					VGet(  0.0f, 10.1f, -69.0f),     // ��Q
					VGet( 25.0f, 10.1f, -69.0f)      // ��R
}
	, mSetSize(VGet(0.05f, 0.05f, 0.1f))
	, mPromo{ -1 }
	, mPromoBase1{ -1 }
	, mPromoBase2{ -1 }
{
	// ���f���̃��[�h
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		mPromoBase1[i] = MV1LoadModel("data/promotion/untitled4.mv1");
		mPromoBase2[i] = MV1LoadModel("data/promotion/untitled3.mv1");
	}
	for (int i = 0; i < PROMO_NUM; i++)
	{
		mPromo[i] = MV1LoadModel("data/promotion/base.mv1");
	}

	// �摜�̃��[�h
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
/// �f�X�g���N�^
/// </summary>
Promotion::~Promotion()
{
	// ���f���f�[�^�̍폜
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

	// �摜�f�[�^�̍폜
	DeleteGraph(mSimple);
	DeleteGraph(mFalsoc);
	DeleteGraph(mSchool);
	DeleteGraph(mHonobono);
	DeleteGraph(mKora);
	DeleteGraph(mJapan);
	DeleteGraph(mYamako);
}

/// <summary>
/// �`��
/// </summary>
void Promotion::Draw()
{	
	// �|�W�V�����̃Z�b�g
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

	//// ��U
	//if (GetCameraAngleHRotate() == 0.0f)
	//{
	//}
}

/// <summary>
/// �L���̐ݒ�
/// </summary>
void Promotion::SetPromo()
{
	// �L���̓y��̃|�W�V�����E�傫���̃Z�b�g
	for (int i = 0; i < PROMOBASE_NUM; i++)
	{
		MV1SetScale(mPromoBase1[i], mSetSize);
		MV1SetScale(mPromoBase2[i], mSetSize);

		MV1SetPosition(mPromoBase1[i], mBaseDrawPos1[i]);
		MV1SetPosition(mPromoBase2[i], mBaseDrawPos2[i]);
	}
	MV1SetRotationXYZ(mPromoBase1[1], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));
	MV1SetRotationXYZ(mPromoBase2[1], VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0));

	// �L���̃|�W�V�����E�傫���̃Z�b�g
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

	//// ���f���Ƀe�N�X�`���\��t��
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
