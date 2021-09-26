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
* 7 |							|12(���݃��X�g����)
* 8 |							|11(���݃��X�g����)
* 9 |							|10(���݃��X�g����)
*	|							|
*	|							|
*	|							|
*	|							|
*	|							|
*	-----------------------------
*				1,2,3
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
						,VGet(0.0f, F_POS_Y, -F_POS_2Z)        //2
						,VGet(F_INTERVAL,F_POS_3Y,-F_POS_Z)    //3
						,VGet(-F_POS_X,F_POS_2Y,F_INTERVAL)    //4
						,VGet(-F_POS_2X,F_POS_Y,0.0f)          //5
						,VGet(-F_POS_X,F_POS_3Y,-F_INTERVAL)   //6
						,VGet(F_POS_X, F_POS_2Y, -F_INTERVAL)  //7
						,VGet(F_POS_2X, F_POS_Y, 0.0f)	       //8
						,VGet(F_POS_X, F_POS_3Y, F_INTERVAL) } //9

	, BEFORE_DIVING_ROTATE{ VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f)    //1
							,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //2
							,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //3
							,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //4
							,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //5
							,VGet(0.0f,180.0f * DX_PI_F / 180.0f,0.0f)    //6
							,VGet(0.0f, 0.0f,0.0f)                        //7
							,VGet(0.0f,0.0f,0.0f)                         //8
							,VGet(0.0f,0.0f,0.0f) }                       //9


	/*��ԍŏ��Ɏw�肳�ꂽ�ʒu�Ɉړ������Ƃ��̌`
	* 				6,5,4
	*    -------------------------------
	* 	|                               |
	* 	|                               |
	* 	|                               |
	* 	|                               |
	* 7 |            3   6   9          |
	* 8 |                               |
	* 9 |        2   5   8              |
	* 	|                               |
	* 	|      1   4   7                |
	* 	|                               |
	* 	|                               |
	* 	|                               |
	*    -------------------------------
	* 				1,2,3
	*/
	, SET_DANCING_POS{ VGet(-7.5f,F_SET_POSITION_Y,0.f),VGet(-5.f,F_SET_POSITION_Y,5.f),VGet(0.f,F_SET_POSITION_Y,7.5f)       //1�A2�A3
						,VGet(5.f,F_SET_POSITION_Y,5.f),VGet(0.f,F_SET_POSITION_Y,0.f),VGet(-5.f,F_SET_POSITION_Y,-5.f)       //4�A5�A6
						,VGet(0.f,F_SET_POSITION_Y,-7.5f),VGet(5.0f,F_SET_POSITION_Y,-5.f),VGet(7.5f,F_SET_POSITION_Y,0.f) }  //7�A8�A9
	, DEBUG_SPHERE_COLOR{ WHITE_COLOR ,BLACK_COLOR ,YELLOW_COLOR ,LIGHTBLUE_COLOR ,YELLOWGREEN_COLOR ,
							ORANGE_COULOR ,RED_COLOR ,GREEN_COLOR ,PURPLE_COLOR }
	, mDanceStartFlag(false)
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		//NULL���ƂO������̂Œ��g������ۂɂ��邽�߂�nullptr�ɂ���
		mFish[i] = nullptr;
	}

	//�S�̂���������velocity
	mWholeVelocity = VGet(0.25f, 0.f, 0.25f);
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
		//�������̐���
		mFish[i] = new Fish(mSourceModelHandle,
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
		//������������
		delete mFish[i];
		//NULL���ƂO������̂Œ��g������ۂɂ��邽�߂�nullptr�ɂ���
		mFish[i] = nullptr;
	}

	//���f���̍폜
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
			//�S�����w�肵���ʒu�܂ňړ������Ƃ�(���������Ă���΂�������)
			if (mFish[0]->GetDancePosFlag()
				&& mFish[1]->GetDancePosFlag()
				&& mFish[2]->GetDancePosFlag()
				&& mFish[3]->GetDancePosFlag()
				&& mFish[4]->GetDancePosFlag()
				&& mFish[5]->GetDancePosFlag()
				&& mFish[6]->GetDancePosFlag()
				&& mFish[7]->GetDancePosFlag()
				&& mFish[8]->GetDancePosFlag())
			{
				//�S�̂̃_���X�X�^�[�g�̃t���O��true�ɂ���
				mDanceStartFlag = true;
			}
			//�S���̃_���X�X�^�[�g�̃t���O��true��������
			if (mDanceStartFlag)
			{
				//�W���������̒��S����Ƃ���(���̏ꍇ�̃C���f�b�N�X��5)���ˏ������s��
				mFish[i]->SetTempAimlessVelocity(MoveGroupAimlessWandering(mFish[5]));
			}

			mFish[i]->Updata(_judge, _delta, _startflag);
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

		//--------------------------------
		//�S�̂̈ړ�����Ƃ��̓����蔻����������邽�߂̃f�o�b�N�p�`��
		DrawSphere3D(mFish[4]->GetPos(), 10.f, 5, PINK_COLOR, PINK_COLOR, false);
	}
}

/// <summary>
/// �_���X���̈ړ�����
/// </summary>
/// <param name="_nowPos">FishBase�����������̕ϐ�</param>
/// <returns>�_���X���ړ����邽�߂̃x�N�g��</returns>
VECTOR FishManager::MoveGroupAimlessWandering(FishBase* _fish)
{
	//����mDanceStartFlag��true��������
	if (mDanceStartFlag
		&& (_fish->GetMoveState() == _fish->NowMove))
	{
		//���E�̔��ˏ���
		if (_fish->GetPos().x >= LINE_X - 12.5f
			|| _fish->GetPos().x <= -LINE_X + 7.5f)
		{
			mWholeVelocity.x = -mWholeVelocity.x;
		}
		//�㉺�̔��ˏ���
		if (_fish->GetPos().z >= LINE_Z - 10
			|| _fish->GetPos().z <= -LINE_Z + 7.5f)
		{
			mWholeVelocity.z = -mWholeVelocity.z;
		}

		//���ˏ�����������A�܂��͂��̑O�ɐݒ肳�ꂽ�ړ��x�N�g����Ԃ�
		return mWholeVelocity;
	}

	//mDanceStartFlag��false�������Ƃ��̓x�N�g�����S���[���̏�Ԃɂ���
	return ZERO_VECTOR;
}