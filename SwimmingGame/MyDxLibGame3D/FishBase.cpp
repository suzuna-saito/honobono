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
	, mModelFishTexture(-1)
	, mPos(VGet(0.0f, 0.0f, 0.0f))
	, mRotate(VGet(0.0f, 0.0f, 0.0f))
	, mSetDancePos(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
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
	MV1SetTextureGraphHandle(mModelHandle, 0, mModelFishTexture, false);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
FishBase::~FishBase()
{
	// ���f���ƃe�N�X�`���f�[�^�̏���
	MV1DeleteModel(mModelHandle);
	DeleteGraph(mModelFishTexture);
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
	DrawSphere3D(mPos, debugRad, SPHERE_POLYGON_FINENESS, _debugColor, _debugColor, false);

}

