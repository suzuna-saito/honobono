#include"FishManager.h"
#include"FishBase.h"
#include"Fish.h"
#include"Common.h"


////各Mbbの向いている方向
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
////各MobFishの飛び込み位置
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
* 上方向キーを押した時の視点での
* 飛び込み前の魚たちの位置と配列
*				4,3,2
*	-----------------------------
*	|							|
*	|							|
*	|							|
*	|							|
* 5 |							|10
* 6 |							|9
* 7 |							|8
*	|							|
*	|							|
*	|							|
*	|							|
*	|							|
*	-----------------------------
*			0,player,1
*/


/// <summary>
/// コンストラクタ
/// </summary>
FishManager::FishManager()
	:mSourceModelHandle(-1)
	, BEFORE_DIVING_POS{ VGet(-5.0f,18.0f,-22.0f)   //1
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
	,SET_DANCING_POS{	VGet(-7.5f,0.0f,-12.5f),VGet(7.5f,0.0f,-12.5f)							//[0]、[1]
						,VGet(0.0f,0.0f,5.0f),VGet(7.5f,0.0f,12.5f),VGet(-7.5f,0.0f,-12.5f)		//[2]、[3]、[4]
						,VGet(-5.0f,0.0f,-10.0f),VGet(-7.5f,0.0f,10.0f),VGet(-7.5f,0.0f,-10.0f)	//[5]、[6]、[7]
						,VGet(7.5f,0.0f,10.0f),VGet(-7.5f,0.0f,-10.0f),VGet(5.0f,0.0f,0.0f) }	//[8]、[9]、[10]
	,DEBUG_SPHERE_COLOR{ whiteColor ,yellowColor ,lightBlueColor ,yellowGreenColor ,
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
	mSourceModelHandle = MV1LoadModel("data/model/fish/npc.mv1");

	for (int i = 0; i < FISH_NUM; i++)
	{
		//魚たちの生成
		mFish[i] = new Fish(mSourceModelHandle,
			BEFORE_DIVING_POS[i], BEFORE_DIVING_ROTATE[i], SET_DANCING_POS[i]);
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