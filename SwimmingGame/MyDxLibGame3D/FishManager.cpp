#include"FishManager.h"
#include"FishBase.h"
#include"Fish.h"
#include"Common.h"

/*
* 上方向キーを押した時の視点での
* 飛び込み前の魚たちの位置と配列
* (記述は0スタートではありません)
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


/// <summary>
/// コンストラクタ
/// </summary>
FishManager::FishManager()
	:mSourceModelHandle(-1)
	, mPlayerModelHandle(-1)
	, BEFORE_DIVING_POS{ VGet(-5.0f,18.0f,-22.0f)   //1
						,VGet(0.0f, 23.0f, -20.0f)  //プレイヤー
						,VGet(5.0f,11.0f,-22.0f)	//2
						,VGet(5.0f,18.0f,22.0f)		//3
						,VGet(0.0f,23.0f,20.0f)		//4
						,VGet(-5.0f,11.0f,22.0f)	//5
						,VGet(-12.0f,18.0f,5.0f)	//6
						,VGet(-10.0f,23.0f,0.0f)	//7
						,VGet(-12.0f,11.0f,-5.0f)	//8
						,VGet(12.0f,18.0f,-5.0f)    //9
						,VGet(10.0f,23.0f,0.0f)	    //10
						,VGet(12.0f,11.0f,5.0f) }	//11

	, BEFORE_DIVING_ROTATE{	VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f)    //1
							,VGet(0.0f,90.0f * DX_PI_F / 180.0f,0.0f)     //プレイヤー
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

	,SET_DANCING_POS{	VGet(-7.5f,2.0f,15.0f),VGet(0.0f,2.0f,7.5f),VGet(7.5f,2.0f,15.0f)   	//1、プレイヤー、3
						,VGet(7.5f,2.0f,-15.0f),VGet(0.0f,2.0f,-7.5f),VGet(-7.5f,2.0f,-15.0f)	//4、5、6
						,VGet(10.0f,2.0f,-7.5f),VGet(5.0f,2.0f,0.0f),VGet(10.0f,2.0f,7.5f)	    //7、8、9
						,VGet(-10.0f,2.0f,-7.5f),VGet(-5.0f,2.0f,0.0f),VGet(-10.0f,2.0f,7.5f) }	//10、11、12
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
/// デストラクタ
/// </summary>
FishManager::~FishManager()
{
}

/// <summary>
/// 魚たちの生成
/// </summary>
void FishManager::CreatFish()
{
	// モブ
	mSourceModelHandle = MV1LoadModel("data/model/fish/npc.mv1");
	// プレイヤー
	mPlayerModelHandle = MV1LoadModel("data/model/fish/player.mv1");
	

	for (int i = 0; i < FISH_NUM; i++)
	{
		if (i == 1)
		{
			// プレイヤーの作成
			mFish[i] = new Fish(mPlayerModelHandle,
				BEFORE_DIVING_POS[i], BEFORE_DIVING_ROTATE[i], SET_DANCING_POS[i]);
		}
		else
		{
			//魚たちの生成
			mFish[i] = new Fish(mSourceModelHandle,
				BEFORE_DIVING_POS[i], BEFORE_DIVING_ROTATE[i], SET_DANCING_POS[i]);
		}
	}

}

/// <summary>
/// 魚たちの削除
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
/// 更新関数
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
/// 描画関数
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