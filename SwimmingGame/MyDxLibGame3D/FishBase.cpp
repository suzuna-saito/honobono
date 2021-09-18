#include "FishBase.h"
#include "Common.h"
#include<math.h>
#include<Windows.h>

//---------Debug�p�萔-----------------
const int SPHERE_POLYGON_FINENESS = 5;

/// <summary>
/// �R���X�g���N�^
/// </summary>
FishBase::FishBase(int _sourceModelHandle)
	:mModelHandle(-1)
	, mPos(ZERO_VECTOR)
	, mRotate(ZERO_VECTOR)
	, mSetDancePos(ZERO_VECTOR)
	, mVelocity(ZERO_VECTOR)
	, mTempVelocity(ZERO_VECTOR)
	, mSetDanceFlag(false)
	, mDanceStartCount(0)
{
	// �摜�f�[�^�̓ǂݍ���
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);

	//���f���������Ă��Ȃ��������Ƃ�
	if (mModelHandle < 0)
	{
		printfDx("���f���f�[�^�ǂݍ��݂Ɏ��s. sourceID : %d", _sourceModelHandle);
	}

	// �摜�T�C�Y�ύX
	MV1SetScale(mModelHandle, FISH_SIZE);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
FishBase::~FishBase()
{
	// ���f���ƃe�N�X�`���f�[�^�̏���
	MV1DeleteModel(mModelHandle);
}


/// <summary>
/// �`��֐�
/// </summary>
void FishBase::Draw(int _debugColor)
{
	//�|�W�V������ݒ�
	MV1SetPosition(mModelHandle, mPos);
	//���f���̌�����ݒ�
	MV1SetRotationXYZ(mModelHandle, mRotate);

	//���f����`�悷��
	MV1DrawModel(mModelHandle);

	//------------------------------------------------
	//�f�o�b�N�pDrawSphere3D
	//DrawSphere3D(mPos, DEBUG_RADIUS, SPHERE_POLYGON_FINENESS, _debugColor, _debugColor, false);

}

