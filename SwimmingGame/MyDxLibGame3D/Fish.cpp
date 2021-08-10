#include "Fish.h"
#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish::Fish()
	: FISH_MOB_ROTATE{VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)
	                 ,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)
	                 ,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f),VGet(0.0f, 0.0f,0.0f)
	                 ,VGet(0.0f,0.0f,0.0f),VGet(0.0f,0.0f,0.0f) }
	, FISH_MOB_NUM(11)
	, mMobPos{ VGet(1.5f,15.0f,-28.0f),VGet(12.0f,9.0f,-28.0f),VGet(-7.0f,20.0f,26.0f)
	          ,VGet(-2.0f,15.0f,28.0f),VGet(-12.0f,9.0f,29.0f),VGet(-16.0f,20.0f,-7.0f)
	          ,VGet(-17.0f,15.0f,-2.0f),VGet(-17.0f,9.0f,-12.0f),VGet(16.0f,20.0f,7.0f)
	          ,VGet(17.0f,15.0f,2.0f),VGet(17.0f,9.0f,12.0f) }
{
	// �摜�f�[�^�̓ǂݍ���
	mMHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");
	MobFishTexture = LoadGraph("data/model/fish/MobFish.png");
	// �摜�T�C�Y�ύX
	MV1SetScale(mMHandle, FISH_SIZE);
	MV1SetTextureGraphHandle(mMHandle, 0, MobFishTexture, FALSE);
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

