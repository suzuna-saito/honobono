﻿//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "ObstructManager.h"
#include "ObstructBase.h"
#include "ObstructFloat.h"
#include "Player.h"
#include "UIGoal.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
ObstructManager::ObstructManager()
	: floatModelSourceHandle(-1)
{
	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			obstructs[i][j] = NULL;
		}
	}
	BallHandle = NULL;
	BallPos = VGet(0.0f, 0.0f, 0.0f);
	BallFlag = false;
	Velocity = VGet(0.0f, 0.0f, BALL_Z_SPEED * 3);
	rotationX = 0.0f;
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
ObstructManager::~ObstructManager()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  障害物生成.
//-----------------------------------------------------------------------------
void ObstructManager::CreateObstructs()
{
	floatModelSourceHandle = MV1LoadModel("data/model/ball/monsterBall.pmx");

	// 障害物の配置図データとしてのlinemapを用意する.
	// 1のところに障害物を表示
	// 緩急
	int line0000000[LINE_OBSTRUCT_COL] = { 0,0,0,0,0,0,0 };
	// 初級
	int line0001000[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,0 };
	int line0110000[LINE_OBSTRUCT_COL] = { 0,1,1,0,0,0,0 };
	int line0000110[LINE_OBSTRUCT_COL] = { 0,0,0,0,1,1,0 };
	int line1000001[LINE_OBSTRUCT_COL] = { 1,0,0,0,0,0,1 };
	int line0010100[LINE_OBSTRUCT_COL] = { 0,0,1,0,1,0,0 };
	int line0100010[LINE_OBSTRUCT_COL] = { 0,1,0,0,0,1,0 };
	// 中級
	int line1100011[LINE_OBSTRUCT_COL] = { 1,1,0,0,0,1,1 };
	int line0011100[LINE_OBSTRUCT_COL] = { 0,0,1,1,1,0,0 };
	int line1010010[LINE_OBSTRUCT_COL] = { 1,0,1,0,0,1,0 };
	int line0100101[LINE_OBSTRUCT_COL] = { 0,1,0,0,1,0,1 };
	int line0111000[LINE_OBSTRUCT_COL] = { 0,1,1,1,0,0,0 };
	int line0001110[LINE_OBSTRUCT_COL] = { 0,0,0,1,1,1,0 };
	// 上級
	int line1010101[LINE_OBSTRUCT_COL] = { 1,0,1,0,1,0,1 };
	int line1101011[LINE_OBSTRUCT_COL] = { 1,1,0,1,0,1,1 };
	int line0111110[LINE_OBSTRUCT_COL] = { 0,1,1,1,1,1,0 };
	int line0001111[LINE_OBSTRUCT_COL] = { 0,0,0,1,1,1,1 };
	int line1111000[LINE_OBSTRUCT_COL] = { 1,1,1,1,0,0,0 };
	int line0110110[LINE_OBSTRUCT_COL] = { 0,1,1,0,1,1,0 };
	

	int* lineMap[LINE_OBSTRUCT_RAW] =
	{
		line1010101,         // 60
        line1101011,         // 59
        line0001111,         // 58
        line1111000,         // 57
        line1010101,         // 56
        line1111000,         // 55
        line0001111,         // 54
        line1101011,         // 53
        line0110110,         // 52
        line1010101,         // 51
        line0111110,         // 50
        line0001111,         // 49
        line1111000,         // 48
        line1010101,         // 47
        line1101011,         // 46
        line1010101,         // 45
        line0111110,         // 44
        line0110110,         // 43
        line0001111,         // 42
        line1111000,         // 41
        line0000000,         // 40
        line0000000,         // 39
        line0011100,         // 38
        line0100101,         // 37
        line1010010,         // 36
		line0011100,	     // 35
		line1100011,	     // 34
		line0100101,	     // 33
		line0111000,	     // 32
		line1100011,	     // 31
		line0001110,         // 30
        line1010010,         // 29	
        line1100011,         // 28	
        line0011100,         // 27	
        line1010010,         // 26	
        line0100101,         // 25	
        line1100011,         // 24	
        line0001110,         // 23	
        line0111000,         // 22	
        line0011100,         // 21	
        line0000000,         // 20	
        line0000000,         // 19	
        line0010100,         // 18	
        line0100010,         // 17	
        line0001000,         // 16	
        line0000110,         // 15	
        line0110000,         // 14	
        line0010100,         // 13	
        line1000001,         // 12	
        line0100010,         // 11	
        line0010100,         // 10	
        line0000110,         // 9	
        line0001000,         // 8	
        line0110000,         // 7	
        line0010100,         // 6	
        line0100010,         // 5
        line0001000,         // 4
		line0000110,         // 3
		line0110000,         // 2
		line0001000,         // 1
	};

	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		int* nowLine = lineMap[i];
		//VECTOR temVelo;
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if(nowLine[j] == 1)
			{
				obstructs[i][j] = new ObstructFloat(floatModelSourceHandle);
			}
			else
			{
				obstructs[i][j] = NULL;
			}

			// 位置の初期化.
			if (obstructs[i][j] != NULL)
			{
				obstructs[i][j]->SetPos(
					VGet(
						(OBSTRUCT_SPACE_W * j) - (OBSTRUCT_SPACE_W * LINE_OBSTRUCT_COL * 0.5f),
						0.0f,
						150.0f + (OBSTRUCT_SPACE_D * LINE_OBSTRUCT_RAW) - (OBSTRUCT_SPACE_D * i)
						)
					);
			}
		}
	}

	BallHandle = MV1LoadModel("data/model/ball/monsterBall.pmx");
}

//-----------------------------------------------------------------------------
// @brief  障害物削除.
//-----------------------------------------------------------------------------
void ObstructManager::DestroyObstructs()
{

	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if (obstructs[i][j] != NULL)
			{
				delete(obstructs[i][j]);
				obstructs[i][j] = NULL;
			}
		}
	}
	MV1DeleteModel(BallHandle);
	MV1DeleteModel(floatModelSourceHandle);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void ObstructManager::Update(Player& player, UIGoal& uiGoal)
{
	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if (obstructs[i][j] != NULL)
			{
				obstructs[i][j]->Update(uiGoal);
			}
		}
	}

	// プレイヤー位置用ボールの移動
	if (BallFlag)
	{
		BallPos = VAdd(BallPos, Velocity);
		MV1SetPosition(BallHandle, BallPos);
	}
	else           // プレイヤーのx座標にセット
	{
		BallPos = VGet(player.GetPos().x, 0.0f, 300.0f);
		MV1SetPosition(BallHandle, BallPos);
		BallFlag = true;
	}

	// 画面外またはプレイヤーが所定の位置まで来たらボールを消す
	if (BallPos.z < -200.0f || uiGoal.GetUIPosY() <= 130)
	{
		BallFlag = false;
	}

	//回転の値の増加
	rotationX -= BALL_ROTATION_X;

	//モデルの回転関数
	MV1SetRotationXYZ(BallHandle, VGet(rotationX, 0.0f, 0.0f));
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void ObstructManager::Draw()
{
	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if (obstructs[i][j] != NULL)
			{
				obstructs[i][j]->Draw();
			}
		}
	}

	// ボール出現可能なら描画
	if (BallFlag)
	{
		MV1DrawModel(BallHandle);
		MV1SetScale(BallHandle, VGet(MODEL_SCALE, MODEL_SCALE, MODEL_SCALE));
	}
}

//-----------------------------------------------------------------------------
// @brief  指定番号の障害物を取得.
//-----------------------------------------------------------------------------
ObstructBase* ObstructManager::GetObstruct(int raw, int col)
{
	return obstructs[raw][col];
}