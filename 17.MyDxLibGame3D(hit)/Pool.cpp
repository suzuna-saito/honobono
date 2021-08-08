#include "Pool.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Pool::Pool()
	:POOL_SIZE(VGet( 0.15f, 0.15f, 0.15f))
	,WATER_SIZE(VGet( 1.5f, 1.5f, 1.5f))
	,DIVINGBOARD_SIZE(VGet( 0.60f, 0.60f, 0.60f))
	,DIVINGBOARD_NUM(4)
	,DIVINGBOARD_ROTATE{VGet( 0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f)
	                   ,VGet( 0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f)
	                   ,VGet( 0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f)
	                   ,VGet( 0.0f, 0.0f, 0.0f)}
	,mPoolPos(VGet( 0.0f, 0.0f, 0.0f))
	,mWaterPos(VGet( 0.0f, 2.0f, 0.0f))
	,mDivingBoardPos{VGet( 0.0f, 3.0f, -27.0f),VGet( -17.0f, 3.0f, 0.0f)
	                ,VGet( 17.0f, 3.0f, 0.0f), VGet( 0.0f, 3.0f, 27.0f)}
	,i(0)
{
	// �摜�̓ǂݍ���
	mPoolHandle = MV1LoadModel("data/model/Pool/Outpool_OFFroop_dainashi.mqo");
	mPoolWaterHandle = MV1LoadModel("data/model/Pool/water.x");
	mDivingBoardHandle = MV1LoadModel("data/model/Pool/DivingBoard.mqo");

	// ���W�̃Z�b�g
	MV1SetPosition(mPoolHandle, mPoolPos);
	MV1SetPosition(mPoolWaterHandle, mWaterPos);

	// �T�C�Y�̕ύX
	MV1SetScale(mPoolHandle, POOL_SIZE);
	MV1SetScale(mPoolWaterHandle, WATER_SIZE);
	MV1SetScale(mDivingBoardHandle, DIVINGBOARD_SIZE);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Pool::~Pool()
{
	// �摜�f�[�^����
	MV1DeleteModel(mPoolHandle);
	MV1DeleteModel(mPoolWaterHandle);
	MV1DeleteModel(mDivingBoardHandle);
}

/// <summary>
/// �`��ϐ�
/// </summary>
void Pool::Draw()
{
	// �摜�̕`��
	MV1DrawModel(mPoolHandle);
	MV1DrawModel(mPoolWaterHandle);
	for (i = 0; i < DIVINGBOARD_NUM; i++)
	{
		MV1SetPosition(mDivingBoardHandle, mDivingBoardPos[i]);
		MV1SetRotationXYZ(mDivingBoardHandle, DIVINGBOARD_ROTATE[i]);
		MV1DrawModel(mDivingBoardHandle);
	}
}