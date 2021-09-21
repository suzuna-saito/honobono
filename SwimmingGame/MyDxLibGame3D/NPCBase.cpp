#include "NPCBase.h"
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

//NPC�̃��f���̊g��\���̑傫��
const float NPC_MODEL_SCALE = 1.0f;

/// <summary>
/// NPC�̃R���X�g���N�^
/// </summary>
NPCBase::NPCBase(int _sourceModelHandle)
	:mPos(VGet(0.0f,0.0f,0.0f))
	,mVelocity(VGet(0.0f,0.0f,0.0f))
{
	//���f���n���h���̃R�s�[
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);
	if (mModelHandle < 0)
	{
		//���f���n���h���̓ǂݍ��݂����s�����ꍇ�̕\��
		printfDx("�f�[�^�ǂݍ��ݎ��s. sourceID:%d", _sourceModelHandle);
	}
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
NPCBase::~NPCBase()
{
	//���f���̍폜
	MV1DeleteModel(mModelHandle);
}


/// <summary>
/// �X�V�֐�
/// </summary>
void NPCBase::Update()
{
	//���f����set
	MV1SetPosition(mModelHandle, mPos);
}

/// <summary>
/// �`��֐�
/// </summary>
void NPCBase::Draw()
{
	//���f���̑傫���̕ύX
	MV1SetScale(mModelHandle, VGet(NPC_MODEL_SCALE, NPC_MODEL_SCALE, NPC_MODEL_SCALE));

	//���f���̕\��
	MV1DrawModel(mModelHandle);
}