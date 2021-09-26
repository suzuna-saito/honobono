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
* 7 |							|12(現在リストラ中)
* 8 |							|11(現在リストラ中)
* 9 |							|10(現在リストラ中)
*	|							|
*	|							|
*	|							|
*	|							|
*	|							|
*	-----------------------------
*				1,2,3
*/

// 定数---------------------------------
const float F_POS_Y = 27.5f;  // 魚のポジションｙ（一番高い台）
const float F_POS_2Y = 22.5f; // 魚のポジションｙ（真ん中の台）
const float F_POS_3Y = 16.0f; // 魚のポジションｙ（一番下の台）

const float F_POS_X = 28.0f;  // 魚のポジションｚ（真ん中の台と一番下の台のｘ軸）
const float F_POS_2X = 25.0f; // 魚のポジションｚ（一番上台のｘ軸）

const float F_POS_Z = 47.0f;  // 魚のポジションｚ（真ん中の台と一番下の台のｚ軸）
const float F_POS_2Z = 44.0f;  // 魚のポジションｚ（一番上台のｚ軸）

const float F_INTERVAL = 5.0f; // 魚と魚の間隔

const float F_SET_POSITION_Y = 5.5f;
//----------------------------------------

/// <summary>
/// コンストラクタ
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


	/*一番最初に指定された位置に移動したときの形
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
	, SET_DANCING_POS{ VGet(-7.5f,F_SET_POSITION_Y,0.f),VGet(-5.f,F_SET_POSITION_Y,5.f),VGet(0.f,F_SET_POSITION_Y,7.5f)       //1、2、3
						,VGet(5.f,F_SET_POSITION_Y,5.f),VGet(0.f,F_SET_POSITION_Y,0.f),VGet(-5.f,F_SET_POSITION_Y,-5.f)       //4、5、6
						,VGet(0.f,F_SET_POSITION_Y,-7.5f),VGet(5.0f,F_SET_POSITION_Y,-5.f),VGet(7.5f,F_SET_POSITION_Y,0.f) }  //7、8、9
	, DEBUG_SPHERE_COLOR{ WHITE_COLOR ,BLACK_COLOR ,YELLOW_COLOR ,LIGHTBLUE_COLOR ,YELLOWGREEN_COLOR ,
							ORANGE_COULOR ,RED_COLOR ,GREEN_COLOR ,PURPLE_COLOR }
	, mDanceStartFlag(false)
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		//NULLだと０が入るので中身を空っぽにするためにnullptrにする
		mFish[i] = nullptr;
	}

	//全体が動く時のvelocity
	mWholeVelocity = VGet(0.25f, 0.f, 0.25f);
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
		//メモリを消す
		delete mFish[i];
		//NULLだと０が入るので中身を空っぽにするためにnullptrにする
		mFish[i] = nullptr;
	}

	//モデルの削除
	MV1DeleteModel(mPlayerModelHandle);
	MV1DeleteModel(mSourceModelHandle);
}

/// <summary>
/// 更新関数
/// </summary>
void FishManager::Updata(int _judge, float _delta, bool _startflag)
{
	for (int i = 0; i < FISH_NUM; i++)
	{
		if (mFish[i] != NULL)
		{
			//全員が指定した位置まで移動したとき(何かいい案あればください)
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
				//全体のダンススタートのフラグをtrueにする
				mDanceStartFlag = true;
			}
			//全員のダンススタートのフラグがtrueだった時
			if (mDanceStartFlag)
			{
				//集合した時の中心を基準として(この場合のインデックスは5)反射処理を行う
				mFish[i]->SetTempAimlessVelocity(MoveGroupAimlessWandering(mFish[5]));
			}

			mFish[i]->Updata(_judge, _delta, _startflag);
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

		//--------------------------------
		//全体の移動するときの当たり判定を可視化するためのデバック用描画
		DrawSphere3D(mFish[4]->GetPos(), 10.f, 5, PINK_COLOR, PINK_COLOR, false);
	}
}

/// <summary>
/// ダンス中の移動処理
/// </summary>
/// <param name="_nowPos">FishBaseを持った魚の変数</param>
/// <returns>ダンス中移動するためのベクトル</returns>
VECTOR FishManager::MoveGroupAimlessWandering(FishBase* _fish)
{
	//もしmDanceStartFlagがtrueだったら
	if (mDanceStartFlag
		&& (_fish->GetMoveState() == _fish->NowMove))
	{
		//左右の反射処理
		if (_fish->GetPos().x >= LINE_X - 12.5f
			|| _fish->GetPos().x <= -LINE_X + 7.5f)
		{
			mWholeVelocity.x = -mWholeVelocity.x;
		}
		//上下の反射処理
		if (_fish->GetPos().z >= LINE_Z - 10
			|| _fish->GetPos().z <= -LINE_Z + 7.5f)
		{
			mWholeVelocity.z = -mWholeVelocity.z;
		}

		//反射処理をした後、またはその前に設定された移動ベクトルを返す
		return mWholeVelocity;
	}

	//mDanceStartFlagがfalseだったときはベクトルが全部ゼロの状態にする
	return ZERO_VECTOR;
}