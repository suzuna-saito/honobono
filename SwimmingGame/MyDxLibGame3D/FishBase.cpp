#include "FishBase.h"
#include<math.h>
#include<Windows.h>

// ���̃T�C�Y�ύX�l
const VECTOR FISH_SIZE = (VGet(0.2f, 0.2f, 0.2f));


/// <summary>
/// �R���X�g���N�^
/// </summary>
FishBase::FishBase(int _sourceModelHandle, int _sourceModelTexture)
	:mModelHandle(-1)
	, mModelFishTexture(-1)
	, mPos(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mRotate(VGet(0.0f, 0.0f, 0.0f))
	, mSetDancePos(VGet(0.0f, 0.0f, 0.0f))
	, mInPoolFlag(false)
{
	// �摜�f�[�^�̓ǂݍ���
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);
	mModelFishTexture = _sourceModelTexture;

	if (mModelHandle < 0)
	{
		printfDx("���f���f�[�^�ǂݍ��݂Ɏ��s. sourceID : %d", _sourceModelHandle);
	}
	else if (mModelFishTexture < 0)
	{
		printfDx("�e�N�X�`���f�[�^�ǂݍ��݂Ɏ��s. sourceID : %d", _sourceModelTexture);
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
	// �摜�f�[�^�̏���
	MV1DeleteModel(mModelHandle);
	DeleteGraph(mModelFishTexture);
}

/// <summary>
/// �X�V�֐�
/// </summary>
void FishBase::Updata(FishBase* _mobFish)
{
	if (_mobFish->mPos.y != 0.0f)
	{
		_mobFish->SetDancePos(_mobFish->mSetDancePos);
	}
}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃|�W�V�����Ɉړ�����
/// </summary>
/// <param name="_setDancePos">�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���|�W�V����</param>
void FishBase::SetDancePos(VECTOR _setDancePos)
{
	//�J�n���̃|�W�V������������|�W�V�����ƈႤ�̂ł���΍X�V���s��Ȃ�
	if (VSize(_setDancePos) != VSize(mPos))
	{
		return;
	}
	else 
	{
		//�����ڂ̌���
		mRotate = VGet(0.0f, 0.0f, 0.0f);
		
		//�J�n���̈ړ�������P�ʃx�N�g����
		mVelocity = VNorm(VSub(_setDancePos, mPos));
		//���̕�����velocity�������ړ�
		mPos = VAdd(mVelocity, mPos);
	}
}


/// <summary>
/// �`��֐�
/// </summary>
void FishBase::Draw()
{
	//�|�W�V������ݒ肵�ĕ`�悷��
	MV1SetPosition(mModelHandle, mPos);
	//���f���̌�����ݒ肵�ĕ`�悷��
	MV1SetRotationXYZ(mModelHandle, mRotate);

	//���f����`�悷��
	MV1DrawModel(mModelHandle);

	//// Mob���W�̃Z�b�g
	//for (int i = 0; i < FISH_MOB_NUM; i++)
	//{
	//	MV1SetPosition(mMHandle, mMobPos[i]);
	//	MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
	//	// Mob�摜�̕`��
	//	MV1DrawModel(mMHandle);
	//}
}

