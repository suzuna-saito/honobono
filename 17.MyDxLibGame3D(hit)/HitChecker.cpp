//-----------------------------------------------------------------------------
// @brief  ヒットチェック.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#include "HitChecker.h"
#include "Player.h"
#include "Satoshi.h"
#include "ObstructManager.h"
#include "ObstructBase.h"

// コンストラクタ
HitChecker::HitChecker()
{
	isHit = false;
	Count = 0;
	hp = 0;
	SizePoint = 0.1f;
	DrawFlag = true;
	DamageImg = LoadGraph("data/Asset/sweat.png");
}

// デストラクタ
HitChecker::~HitChecker()
{
	DeleteGraph(DamageImg);
}

// エフェクトを描画
void HitChecker::Draw(Player& player)
{
	// 当たって無敵状態中
	if (isHit && DamageImg > -1)
	{
		DrawBillboard3D(VGet(player.GetPos().x + 5.0f, 10.0f, player.GetPos().z), 0.0f, 0.0f, 5.0f, 0.0f, DamageImg, TRUE);
	}
}

//-----------------------------------------------------------------------------
// @brief  ヒットチェック処理.
//-----------------------------------------------------------------------------
void HitChecker::Check(Player& player, ObstructManager& obstructManager)
{
	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);

	// プレイヤーの体力値をもらってくる
	hp = player.GetHp();
	SizePoint = player.GetSizePoint();

	// 当たっていないまたはヒットの状態が終わった
	if(!isHit)
	{ 
		for (int i = 0; i < LINE_OBSTRUCT_COL; i++)
		{
			for (int j = 0; j < LINE_OBSTRUCT_RAW; j++)
			{
				ObstructBase* obstruct = obstructManager.GetObstruct(j, i);
				if (obstruct != NULL)
				{
					VECTOR yZeroObstruct = VGet(obstruct->GetPos().x, 0, obstruct->GetPos().z);
					VECTOR yZeroBall = VGet(obstructManager.GetBallPos().x, 0, obstructManager.GetBallPos().z);
					// お互いのポジションと半径の距離が重なったら当たっていることになる.
					VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);
					VECTOR playerToBall = VSub(yZeroBall, yZeroPlayer);
					//printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);
					if (VSize(playerToObs) < player.GetHitRadius() + obstruct->GetHitRadius() ||
						VSize(playerToBall) < player.GetHitRadius() + obstruct->GetHitRadius())
					{
						// ヒットした
						isHit = true;
						// 体力を１減少
						hp--;
						
						if (hp == 2)
						{
							SizePoint *= 2;
						}
						else if (hp == 1)
						{
							SizePoint *= 3;
						}

						// プレイヤーの体力をセットし直す
						player.SetHp(hp);

						player.SetSizePoint(SizePoint);
						break;
					}
				}
			}
			if (isHit)
			{
				break;
			}
		}
	}
	else            // そうじゃなかったら
	{
		// 無敵状態の時間をカウント
		Count++;
		// 無敵状態になってから50フレームを超えたら
		if (Count > 100)
		{
			// 当たり判定復元
			isHit = false;
			// カウント０
			Count = 0;
		}

		if (Count % 2 == 0 && Count != 0)
		{
			DrawFlag = false;
		}
		else
		{
			DrawFlag = true;
		}
		player.SetDrawFlag(DrawFlag);
	}
}
