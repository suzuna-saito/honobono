//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Player.h"
#include "ObstructBase.h"
#include "SceneBase.h"
#include "Hitchecker.h"

// 静的定数.
const float Player::COLIDE_DECEL_FAC	= 0.4f;			// 障害物にぶつかったときの減速率.

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	: modelHandle(-1)
	 , hitRadius(3.0f)  // もとは5.0
	 , Hp(3)            // 残機
	 , HitFlag(TRUE)
	 , DrawFlag(true)
	 , MoveFlag(FALSE)
	 , FadeCount(0)
{
	// ３Ｄモデルの読み込み

	modelHandle = MV1LoadModel("data/model/player/pika/pikapika.pmx");
	MV1SetScale(modelHandle, VGet(1.7f,1.7f,1.7f));   // モデルが少し小さかったので大きくした

	LoadDivGraph("data/Asset/HP.png", 3, 3, 1, 80, 80, HpImg, TRUE);        // HP画像の読み込み
	LoadDivGraph("data/Asset/RightVector2.png", 2, 2, 1, 75, 75, RightVectorGraph, TRUE);
	LoadDivGraph("data/Asset/LeftVector2.png", 2, 2, 1, 75, 75, LeftVectorGraph, TRUE);

	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1); 
	PosY = 0.0f;   // Y座標取得
	HpSize = 40;
	SizePoint = 0.1f;
	RMoveFlag = 0;
	LMoveFlag = 0;
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
	DeleteGraph(*HpImg);
	DeleteGraph(*RightVectorGraph);
	DeleteGraph(*LeftVectorGraph);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Player::Update()
{
	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// 右を押したら右に移動.
	if (Key & PAD_INPUT_RIGHT)
	{
		velocity = VGet(0.5,0,0);
		// 右の矢印を光らせる
		RMoveFlag = 1;
		MoveFlag = TRUE;
	}
	// 左を押したら左に移動.
	else if (Key & PAD_INPUT_LEFT)
	{
		velocity = VGet(-0.5,0,0);
		// 左の矢印を光らせる
		LMoveFlag = 1;
		MoveFlag = TRUE;
	}
	// 何も押していない場合は止まる
	else if (Key == 0 || !(Key & PAD_INPUT_RIGHT && Key & PAD_INPUT_LEFT))
	{
		velocity = VGet(0, 0, 0);
		dir = VGet(0, 0, 1);
		// どちらも光らせない
		RMoveFlag = 0;
		LMoveFlag = 0;
		MoveFlag = FALSE;
	}


	// 移動制限(もっといい方法がある気がする) てか当たり判定使ってやればいい
	if (pos.x > 25)
	{
		velocity = VGet(0, 0, 0);
		pos.x = pos.x - 0.025f;
	}
	if (pos.x < -40)
	{
		velocity = VGet(0, 0, 0);
		pos.x = pos.x + 0.025f;
	}

	
	// 上下方向にいかないようにベロシティを整える.
	velocity = VGet(velocity.x, 0, velocity.z);

	// ポジションを更新.
	pos = VAdd(pos, velocity);

	// 力をかけ終わったベロシティの方向にディレクションを調整.
	if (VSize(velocity) != 0)
	{
		dir = VNorm(velocity);
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

	// 向きに合わせて回転.
	MV1SetRotationZYAxis(modelHandle, dir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
	
	// モデルに向いてほしい方向に回転.
	MATRIX tmpMat = MV1GetMatrix(modelHandle);
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	tmpMat = MMult(tmpMat, rotYMat);
	MV1SetRotationMatrix(modelHandle, tmpMat);

	// Hpの大きさを拡大、縮小
	HpSize += SizePoint;

	if (HpSize > 45)
	{
		SizePoint *= -1;
	}
	else if (HpSize < 35)
	{
		SizePoint *= -1;
	}

	if (Hp == 0)
	{
		FadeCount++;
	}
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Player::Draw()
{
	// ３Ｄモデルの描画
	// ダメージを受けたら点滅させる
	if (DrawFlag)
	{
		MV1DrawModel(modelHandle);
	}

	// 矢印描画
	DrawGraph(0, 405, LeftVectorGraph[LMoveFlag], TRUE);
	DrawGraph(125, 405, RightVectorGraph[RMoveFlag], TRUE);

	// HPの描画
	if (Hp != 0)
	{
		for (int i = 0; i < Hp; i++)   // HPが減ったら表示数を減らす
		{
			int x = i * 50;
			// DrawExtendGraph _HP描画(サイズを小さくしました)
			if (Hp == 1)
			{
				DrawExtendGraph(x, 0, x + (int)HpSize, (int)HpSize, HpImg[2], TRUE);
			}
			else if (Hp == 2)
			{
				DrawExtendGraph(x, 0, x + (int)HpSize, (int)HpSize, HpImg[1], TRUE);
			}
			else
			{
				DrawExtendGraph(x, 0, x + (int)HpSize, (int)HpSize, HpImg[0], TRUE);
			}

		}
	}
}