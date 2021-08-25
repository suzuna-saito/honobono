#include "Fish.h"
#include "Common.h"
#include "Jump.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish::Fish()
	: FISH_MOB_ROTATE{ VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)
					 ,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)
					 ,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f, 0.0f,0.0f)
					 ,VGet(0.0f,0.0f,0.0f),VGet(0.0f,0.0f,0.0f) }
	, FISH_MOB_NUM(11)
	, mMobPos{ VGet(-5.0f,18.0f,-22.0f),VGet(5.0f,11.0f,-22.0f)// ���A�E
			  ,VGet(5.0f,18.0f,22.0f),VGet(0.0f,23.0f,20.0f),VGet(-5.0f,11.0f,22.0f) // ���A�^�񒆁A�E
			  ,VGet(-12.0f,18.0f,5.0f),VGet(-10.0f,23.0f,0.0f),VGet(-12.0f,11.0f,-5.0f) // ���A�^�񒆁A�E
			  ,VGet(12.0f,18.0f,-5.0f),VGet(10.0f,23.0f,0.0f),VGet(12.0f,11.0f,5.0f) } // ���A�^�񒆁A�E
{
	// �摜�f�[�^�̓ǂݍ���
	mMHandle = MV1LoadModel("data/model/fish/npc.mv1");
	// �摜�T�C�Y�ύX
	MV1SetScale(mMHandle, FISH_SIZE);

	// �W�����v�𐶐�.
	jump = new Jump();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Fish::~Fish()
{
	// �摜�f�[�^�̏���
	MV1DeleteModel(mMHandle);
	DeleteGraph(MobFishTexture);
}

/// <summary>
/// �X�V�֐�
/// </summary>
void Fish::Update()
{
	//for (int i = 0; i < FISH_MOB_NUM; i++)
	//{
	//	if (jump->GetGroundNpc())
	//	{
	//		jump->SetJumpNpc(true);
	//	}

	//	// �P��ځA�Q��ځA��э��݂����ꂩ�̃t���O��true��������
	//	if (jump->GetFirstNpc() || jump->GetSecondNpc() || jump->GetThirdNpc())
	//	{
	//		// �W�����v�̍X�V������
	//		jump->NpcJumpUpdate(mMobPos[i],i);
	//	}

	//	mMobPos[i] = jump->GetPosNpc();
	//}
}

/// <summary>
/// �`��֐�
/// </summary>
void Fish::Draw()
{
	// Mob���W�̃Z�b�g
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		MV1SetPosition(mMHandle, mMobPos[i]);
		MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
		// Mob�摜�̕`��
		MV1DrawModel(mMHandle);
	}
}
