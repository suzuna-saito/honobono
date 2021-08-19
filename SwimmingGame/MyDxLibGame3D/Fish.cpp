#include "Fish.h"
#include "Common.h"
#include"Player.h"
#include"Input.h"

//定数
const float JUMP_UP_Y = 0.5f;      // ジャンプした時のY軸の加算値
const float JUMP_DOWN_Y = 0.25f;   // ジャンプした後のY軸の減算値

const float JUMP_UP_Z = 0.25f;     // ジャンプした時のz軸の加算値
const float JUMP_DOWN_Z = 0.2f;    // ジャンプした時のz軸の減算値

const float FIRST_MAX = 23.0f;     // 1回目ジャンプの最大ジャンプ力
const float SECOND_MAX = 25.0f;    // 2回目ジャンプの最大ジャンプ力
const float THIRD_MAX = 28.0f;     // 飛び込みの最大ジャンプ力

const float INIT_POS_Y = 20.0f;    // ジャンプ台の高さ

const float GRAVITY = 0.2f;    //重力


/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish()
	//各Mbbの向いている方向
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
	//各MobFishの飛び込み位置
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
	// 画像データの読み込み
	mMHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");
	MobFishTexture = LoadGraph("data/model/fish/MobFish.png");

	// 画像サイズ変更
	MV1SetScale(mMHandle, FISH_SIZE);
	MV1SetTextureGraphHandle(mMHandle, 0, MobFishTexture, FALSE);

	mp = new Player();
}

/// <summary>
/// デストラクタ
/// </summary>
Fish::~Fish()
{
	// 画像データの消去
	MV1DeleteModel(mMHandle);
	DeleteGraph(MobFishTexture);
}

/// <summary>
/// 更新関数
/// </summary>
void Fish::Update()
{
}

/// <summary>
/// 描画関数
/// </summary>
void Fish::Draw()
{
	// Mob座標のセット
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		MV1SetPosition(mMHandle, mMobPos[i]);
		MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
		// Mob画像の描画
		MV1DrawModel(mMHandle);
	}
}

