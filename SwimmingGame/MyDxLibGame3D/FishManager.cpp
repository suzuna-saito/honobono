#include"FishManager.h"
#include"FishBase.h"
#include"Fish.h"
#include"Common.h"

/*
* ������L�[�����������̎��_�ł�
* ��э��ݑO�̋������̈ʒu�Ɣz��
* (�L�q��0�X�^�[�g�ł͂���܂���)
*				6,5,4
*	-----------------------------
*	|							|
*	|							|
*	|							|
*	|							|
* 7 |							|12
* 8 |							|11
* 9 |							|10
*	|							|
*	|							|
*	|							|
*	|							|
*	|							|
*	-----------------------------
*			1,player,3
*/

// �萔---------------------------------
const float F_POS_Y = 27.5f;  // ���̃|�W�V�������i��ԍ�����j
const float F_POS_2Y = 22.5f; // ���̃|�W�V�������i�^�񒆂̑�j
const float F_POS_3Y = 16.0f; // ���̃|�W�V�������i��ԉ��̑�j

const float F_POS_X = 28.0f;  // ���̃|�W�V�������i�^�񒆂̑�ƈ�ԉ��̑�̂����j
const float F_POS_2X = 25.0f; // ���̃|�W�V�������i��ԏ��̂����j

const float F_POS_Z = 47.0f;  // ���̃|�W�V�������i�^�񒆂̑�ƈ�ԉ��̑�̂����j
const float F_POS_2Z = 44.0f;  // ���̃|�W�V�������i��ԏ��̂����j

const float F_INTERVAL = 5.0f; // ���Ƌ��̊Ԋu

const float F_SET_POSITION_Y = 5.5f;
//----------------------------------------

/// <summary>
/// �R���X�g���N�^
/// </summary>
FishManager::FishManager()
	:mSourceModelHandle(-1)
	, mPlayerModelHandle(-1)
	, BEFORE_DIVING_POS{ VGet(-F_INTERVAL,F_POS_2Y,-F_POS_Z)   //1
						,VGet(0.0f, F_POS_Y, -F_POS_2Z)  //�v���C���[
						,VGet(F_INTERVAL,F_POS_3Y,-F_POS_Z)	//2
						,VGet(F_INTERVAL,F_POS_2Y,F_POS_Z)		//3
						,VGet(0.0f,F_POS_Y,F_POS_2Z)		//4
						,VGet(-F_INTERVAL,F_POS_3Y,F_POS_Z)	//5
						,VGet(-F_POS_X,F_POS_2Y,F_INTERVAL)	//6
						,VGet(-F_POS_2X,F_POS_Y,0.0f)	//7
						,VGet(-F_POS_X,F_POS_3Y,-F_INTERVAL)	//8
						,VGet(F_POS_X,F_POS_2Y,-F_INTERVAL)    //9
						,VGet(F_POS_2X,F_POS_Y,0.0f)	    //10
						,VGet(F_POS_X,F_POS_3Y,F_INTERVAL) }	//11

	, BEFORE_DIVING_ROTATE{ VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f)    //1
							,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //�v���C���[
							,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //2
							,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //3
							,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //4
							,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //5
							,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //6
							,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //7
							,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //8
							,VGet(0.0f, 0.0f,0.0f)    //9
							,VGet(0.0f,0.0f,0.0f)     //10
							,VGet(0.0f,0.0f,0.0f) }   //11

	, SET_DANCING_POS{ VGet(-10.0f,F_SET_POSITION_Y,20.0f),VGet(0.0f,F_SET_POSITION_Y,10.0f),VGet(10.0f,F_SET_POSITION_Y,20.0f)   	//1�A�v���C���[�A3
						,VGet(10.0f,F_SET_POSITION_Y,-20.0f),VGet(0.0f,F_SET_POSITION_Y,-10.0f),VGet(-10.f,F_SET_POSITION_Y,-20.0f)	//4�A5�A6
						,VGet(20.0f,F_SET_POSITION_Y,-12.5f),VGet(10.0f,F_SET_POSITION_Y,0.0f),VGet(20.0f,F_SET_POSITION_Y,12.5f)	    //7�A8�A9
						,VGet(-20.0f,F_SET_POSITION_Y,-12.5f),VGet(-10.0f,F_SET_POSITION_Y,0.0f),VGet(-20.0f,F_SET_POSITION_Y, 12.5f) }	//10�A11�A12
	, DEBUG_SPHERE_COLOR{ whiteColor ,0 ,yellowColor ,lightBlueColor ,yellowGreenColor ,
							orangeColor ,redColor ,greenColor ,purpleColor ,brownColor ,
								blueColor ,pinkColor }
	, mDanceStartFlag(false)
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		mFish[i] = NULL;
	}
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
FishManager::~FishManager()
{
}

/// <summary>
/// �������̐���
/// </summary>
void FishManager::CreatFish()
{
	// ���u
	mSourceModelHandle = MV1LoadModel("data/model/fish/npc.mv1");
	// �v���C���[
	mPlayerModelHandle = MV1LoadModel("data/model/fish/player02.mv1");


	for (int i = 0; i < FISH_NUM; i++)
	{
		// �v���C���[�̍쐬
		mFish[i] = new Fish(mPlayerModelHandle,
			BEFORE_DIVING_POS[i], BEFORE_DIVING_ROTATE[i], SET_DANCING_POS[i]);
	}
}

/// <summary>
/// �������̍폜
/// </summary>
void FishManager::DestroyFish()
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		delete mFish[i];
		mFish[i] = NULL;
	}

	MV1DeleteModel(mPlayerModelHandle);
	MV1DeleteModel(mSourceModelHandle);
}

/// <summary>
/// �X�V�֐�
/// </summary>
void FishManager::Updata(int _judge, float _delta, bool _startflag)
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		if (mFish[i] != NULL)
		{
			mFish[i]->Updata(_judge, _delta, _startflag);
		}
	}

	//�v���C���[���_���X�W�����̃|�W�V�����ɂ����Ƃ���flag���擾����
	mDanceStartFlag = mFish[1]->GetSetDancePosFlag();
}

/// <summary>
/// �`��֐�
/// </summary>
void FishManager::Draw()
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		if (mFish[i] != NULL)
		{
			mFish[i]->Draw(DEBUG_SPHERE_COLOR[i]);
		}
	}
}