#include"FishManager.h"
#include"FishBase.h"

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

/// <summary>
/// �R���X�g���N�^
/// </summary>
FishManager::FishManager()
	:mModelSourceHandle(-1)
	,mModelSourceTexture(-1)
{
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		mMobFish[i] = NULL;
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
void FishManager::CreatMobFish()
{
	mModelSourceHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");
    mModelSourceTexture = LoadGraph("data/model/fish/MobFish.png");

	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		//�������̐���
		mMobFish[i] = new FishBase(mModelSourceHandle, mModelSourceTexture);

		//�ʒu�ƌ����̏�����
		switch (i)
		{
		case 0:	mMobFish[i]->SetPos(VGet(1.5f, 15.0f, -28.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));
			break;

		case 1:	mMobFish[i]->SetPos(VGet(12.0f, 9.0f, -28.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 2:	mMobFish[i]->SetPos(VGet(-7.0f, 20.0f, 26.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 3:	mMobFish[i]->SetPos(VGet(-2.0f, 15.0f, 28.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 4:	mMobFish[i]->SetPos(VGet(-12.0f, 9.0f, 29.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 5: mMobFish[i]->SetPos(VGet(-16.0f, 20.0f, -7.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 6: mMobFish[i]->SetPos(VGet(-17.0f, 15.0f, -2.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 7: mMobFish[i]->SetPos(VGet(-17.0f, 9.0f, -12.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 8: mMobFish[i]->SetPos(VGet(16.0f, 20.0f, 7.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 0.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 9: mMobFish[i]->SetPos(VGet(17.0f, 15.0f, 2.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 0.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		case 10: mMobFish[i]->SetPos(VGet(17.0f, 9.0f, 12.0f));
			mMobFish[i]->SetRotate(VGet(0.0f, 0.0f, 0.0f));
			mMobFish[i]->SetDancePos(VGet(0.0f, 0.0f, 0.0f));

			break;

		default:
			break;
		}
	}

}

/// <summary>
/// �������̍폜
/// </summary>
void FishManager::DestroyMobFish()
{
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		delete[] mMobFish;
		mMobFish[i] = NULL;
	}

	MV1DeleteModel(mModelSourceHandle);
	DeleteGraph(mModelSourceTexture);
}

/// <summary>
/// �X�V�֐�
/// </summary>
void FishManager::Updata()
{
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		if (mMobFish[i] != NULL)
		{
			mMobFish[i]->Updata(mMobFish[i]);
		}
	}
}

/// <summary>
/// �`��֐�
/// </summary>
void FishManager::Draw()
{
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		if (mMobFish != NULL)
		{
			mMobFish[i]->Draw();
		}
	}
}