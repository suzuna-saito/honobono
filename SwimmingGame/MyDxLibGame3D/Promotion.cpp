#include "Promotion.h"

// �萔
const int DRAW_X = 45;
const int DRAW_Y = 15;
const int DRAW_Y2 = 0;

Promotion::Promotion()
	: mDrawPos(VGet(0.0f, 13.0f, 68.0f))  // �\��������|�W�V����
	, mPromo(-1)
{
	mPromo = MV1LoadModel("data/promotion/untitled.mv1");

	// ��ԃV���v���ȉ摜
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

	// 3D��Ԃɉ摜��`��          �����㒸�_��     ���E�㒸�_��    ���E�����_��    ���������_��
	/*DrawModiBillboard3D(mDrawPos, -DRAW_X, DRAW_Y, DRAW_X, DRAW_Y, DRAW_X, DRAW_Y2, -DRAW_X, DRAW_Y2, mSimple, TRUE);*/

	//DrawBillboard3D(mDrawPos, 0.5f, 0.5f, 50.0f,  0.0f, mSimple, TRUE);

	

	//// ��U
	//if (GetCameraAngleHRotate() == 0.0f)
	//{
	//}
}
