#include"FishManager.h"
#include"FishBase.h"
#include"Fish.h"
#include"Common.h"


////�eMbb�̌����Ă������
//: FISH_MOB_ROTATE{ VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)    //1
//				,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //2
//				,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //3
//				,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //4
//				,VGet(0.0f,-90.0f * DX_PI_F / 180.0f,0.0f)    //5
//				,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //6
//				,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //7
//				,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //8
//				,VGet(0.0f, 0.0f,0.0f)    //9
//				,VGet(0.0f,0.0f,0.0f)     //10
//				,VGet(0.0f,0.0f,0.0f)     //11
//}
////�eMobFish�̔�э��݈ʒu
//, mMobPos{ VGet(1.5f,15.0f,-28.0f)     //1
//				,VGet(12.0f,9.0f,-28.0f)	//2
//				,VGet(-7.0f,20.0f,26.0f)	//3
//				,VGet(-2.0f,15.0f,28.0f)	//4
//				,VGet(-12.0f,9.0f,29.0f)	//5
//				,VGet(-16.0f,20.0f,-7.0f)	//6
//				,VGet(-17.0f,15.0f,-2.0f)	//7
//				,VGet(-17.0f,9.0f,-12.0f)	//8
//				,VGet(16.0f,20.0f,7.0f)     //9
//				,VGet(17.0f,15.0f,2.0f)	    //10
//				,VGet(17.0f,9.0f,12.0f)	    //11
//}

/*
* ������L�[�����������̎��_�ł�
* ��э��ݑO�̋������̈ʒu�Ɣz��
*				5,4,3
*	-----------------------------
*	|							|
*	|							|
*	|							|
*	|							|
* 6 |							|11
* 7 |							|10
* 8 |							|9
*	|							|
*	|							|
*	|							|
*	|							|
*	|							|
*	-----------------------------
*			0,player,2
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
	, BEFORE_DIVING_ROTATE{	VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f)    //1
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
	,SET_DANCING_POS{	VGet(-7.5f,0.0f,-12.5f),VGet(7.5f,0.0f,-12.5f)							//[0]�A[1]
						,VGet(0.0f,0.0f,5.0f),VGet(7.5f,0.0f,12.5f),VGet(-7.5f,0.0f,-12.5f)		//[2]�A[3]�A[4]
						,VGet(-5.0f,0.0f,-10.0f),VGet(-7.5f,0.0f,10.0f),VGet(-7.5f,0.0f,-10.0f)	//[5]�A[6]�A[7]
						,VGet(7.5f,0.0f,10.0f),VGet(-7.5f,0.0f,-10.0f),VGet(5.0f,0.0f,0.0f) }	//[8]�A[9]�A[10]
	,DEBUG_SPHERE_COLOR{ whiteColor ,0 ,yellowColor ,lightBlueColor ,yellowGreenColor ,
							orangeColor ,redColor ,greenColor ,purpleColor ,brownColor ,
								blueColor ,pinkColor }
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
	mPlayerModelHandle = MV1LoadModel("data/model/fish/player.mv1");
	

	for (int i = 0; i < FISH_NUM; i++)
	{
		if (i == 1)
		{
			// �v���C���[�̍쐬
			mFish[i] = new Fish(mPlayerModelHandle,
				BEFORE_DIVING_POS[i], BEFORE_DIVING_ROTATE[i], SET_DANCING_POS[i]);
		}
		else
		{
			//�������̐���
			mFish[i] = new Fish(mSourceModelHandle,
				BEFORE_DIVING_POS[i], BEFORE_DIVING_ROTATE[i], SET_DANCING_POS[i]);
		}
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
void FishManager::Updata()
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		if (mFish[i] != NULL)
		{
			mFish[i]->Updata();
		}
	}
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