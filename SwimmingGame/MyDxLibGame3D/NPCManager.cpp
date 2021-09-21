#include "NPCManager.h"
#include"NPCBase.h"
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

/// <summary>
/// �R���X�g���N�^
/// </summary>
NPCManager::NPCManager()
	:mModelSourceHandle(-1)
	,mPos(VGet(0.0f,0.0f,0.0f))
	,mVelocity(VGet(0.0f,0.0f,0.0f))
{
	//���f���̏�����
	for (int i = 0; i < NPC_NUM; i++)
	{
		mNPC[i] = NULL;
	}
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
NPCManager::~NPCManager()
{
}

/// <summary>
/// NPC�̐���
/// </summary>
void NPCManager::CreatNPC()
{
	//���f���̃��[�h
	mModelSourceHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");

	for (int i = 0; i < NPC_NUM; i++)
	{
		//NPC�̃x�[�X�̐���
		mNPC[i] = new NPCBase(mModelSourceHandle);

		//NPC�̈ʒu�̏�����
	}
}


void NPCManager::DestroyNPC()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		delete(mNPC[i]);
		mNPC[i] = NULL;
	}
	MV1DeleteModel(mModelSourceHandle);
}

//�X�V�֐�
void NPCManager::Update()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		if (mNPC[i] != NULL)
		{
			mNPC[i]->Update();
		}
	}
}


//�`��֐�
void NPCManager::Draw()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		if (mNPC[i] != NULL)
		{
			mNPC[i]->Draw();
		}
	}
}