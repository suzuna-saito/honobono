﻿//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#include "Player.h"
#include "Common.h"
#include "Input.h"
#include "Jump.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	: mPHandle(-1)
	, FISH_ROTATE(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, mPos(VGet(7.0f, 20.0f, -26.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mAdvance(0.05f)
{
	// 画像データの読み込み
	mPHandle = MV1LoadModel("data/model/fish/fish.mqo");
	mFishTexture = LoadGraph("data/model/fish/Fish.png");

	// 画像サイズ変更
	MV1SetScale(mPHandle, FISH_SIZE);

	MV1SetTextureGraphHandle(mPHandle, 0, mFishTexture, FALSE);

	// ジャンプを生成.
	jump = new Jump();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	// 画像データの消去
	MV1DeleteModel(mPHandle);
	DeleteGraph(mFishTexture);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Player::Update()
{
	// １回目、２回目、飛び込みいずれかのフラグがtrueだったら
	if (jump->GetFirst() || jump->GetSecond() || jump->GetThird())
	{
		// ボタンが押された瞬間のみジャンプする
		if (Key[KEY_INPUT_SPACE] == 1 && jump->GetGround())
		{
			jump->SetJump(true);
		}

		// ジャンプの更新をする
		jump->JumpUpdate(mPos);
		// ポジションの更新
		mPos = jump->GetPos();
	}
	// 全てのジャンプが終わったらプレイヤーが0の所に行くまで直進させる
	else if (mPos.z <= 0.0f)
	{
		mVelocity = VGet(0.0f, 0.0f, mAdvance);
		mPos = VAdd(mPos, mVelocity);
	}

}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Player::Draw()
{
	MV1SetPosition(mPHandle, mPos);
	MV1SetRotationXYZ(mPHandle, FISH_ROTATE);

	// Player画像の描画
	MV1DrawModel(mPHandle);
}

