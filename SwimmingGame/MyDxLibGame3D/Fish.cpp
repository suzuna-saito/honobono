#include "Fish.h"
#include "Common.h"
#include"Player.h"
#include"Input.h"

//�萔
const float JUMP_UP_Y = 0.5f;      // �W�����v��������Y���̉��Z�l
const float JUMP_DOWN_Y = 0.25f;   // �W�����v�������Y���̌��Z�l

const float JUMP_UP_Z = 0.25f;     // �W�����v��������z���̉��Z�l
const float JUMP_DOWN_Z = 0.2f;    // �W�����v��������z���̌��Z�l

const float FIRST_MAX = 23.0f;     // 1��ڃW�����v�̍ő�W�����v��
const float SECOND_MAX = 25.0f;    // 2��ڃW�����v�̍ő�W�����v��
const float THIRD_MAX = 28.0f;     // ��э��݂̍ő�W�����v��

const float INIT_POS_Y = 20.0f;    // �W�����v��̍���

const float GRAVITY = 0.2f;    //�d��


/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish::Fish()
	//�eMbb�̌����Ă������
	: FISH_MOB_ROTATE{VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)    //1
					,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //2
					,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //3
	                ,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //4
					,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //5
					,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //6
	                ,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //7
					,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //8
					,VGet(0.0f, 0.0f,0.0f)    //9
	                ,VGet(0.0f,0.0f,0.0f)     //10
					,VGet(0.0f,0.0f,0.0f)     //11
					}
	//�eMobFish�̔�э��݈ʒu
	, mMobPos{		VGet(1.5f,15.0f,-28.0f)     //1
					,VGet(12.0f,9.0f,-28.0f)	//2
					,VGet(-7.0f,20.0f,26.0f)	//3
					,VGet(-2.0f,15.0f,28.0f)	//4
					,VGet(-12.0f,9.0f,29.0f)	//5
					,VGet(-16.0f,20.0f,-7.0f)	//6
					,VGet(-17.0f,15.0f,-2.0f)	//7
					,VGet(-17.0f,9.0f,-12.0f)	//8
					,VGet(16.0f,20.0f,7.0f)     //9
					,VGet(17.0f,15.0f,2.0f)	    //10
					,VGet(17.0f,9.0f,12.0f)	    //11
			}
{
	// �摜�f�[�^�̓ǂݍ���
	mMHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");
	MobFishTexture = LoadGraph("data/model/fish/MobFish.png");

	// �摜�T�C�Y�ύX
	MV1SetScale(mMHandle, FISH_SIZE);
	MV1SetTextureGraphHandle(mMHandle, 0, MobFishTexture, FALSE);

	mp = new Player();
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

