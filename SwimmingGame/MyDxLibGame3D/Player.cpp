//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#include "Player.h"
#include "Common.h"
#include "Input.h"

//----------------------
//定数
//----------------------
const float JUMP_UP_Y = 0.5f;      // ジャンプした時のY軸の加算値
const float JUMP_DOWN_Y = 0.25f;   // ジャンプした後のY軸の減算値

const float JUMP_UP_Z = 0.25f;     // ジャンプした時のz軸の加算値
const float JUMP_DOWN_Z = 0.2f;    // ジャンプした時のz軸の減算値

const float FIRST_MAX = 23.0f;     // 1回目ジャンプの最大ジャンプ力
const float SECOND_MAX = 25.0f;    // 2回目ジャンプの最大ジャンプ力
const float THIRD_MAX = 28.0f;     // 飛び込みの最大ジャンプ力

const float INIT_POS_Y = 20.0f;    // ジャンプ台の高さ


//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	: mPHandle(-1)
	, FISH_ROTATE(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, mPos(VGet(7.0f, 20.0f, -26.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mGravity(0.2f)
	, mFirstJump(true)
	, mSecondJump(false)
	, mThirdJump(false)
	, mJumpUpNow(false)
	, mIsGround(true)
{
	// 画像データの読み込み
	mPHandle = MV1LoadModel("data/model/fish/fish.mqo");
	mFishTexture = LoadGraph("data/model/fish/Fish.png");

	// 画像サイズ変更
	MV1SetScale(mPHandle, FISH_SIZE);

	MV1SetTextureGraphHandle(mPHandle, 0, mFishTexture, FALSE);
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
	// ボタンがおしっぱにならないようにする
	UpdateKey();

	if (mFirstJump)          // 1回目のジャンプ
	{
		FirstJumpUpdate();
	}
	else if (mSecondJump)    // 2回目のジャンプ
	{
		SecondJumpUpdate();
	}
	else if (mThirdJump)     // 飛び込みのジャンプ
	{
		ThirdJumpUpdate();
	}
}

//-----------------------------------------------------------------------------
// @brief  1回目のジャンプ更新.
//-----------------------------------------------------------------------------
void Player::FirstJumpUpdate()
{
	// ボタンが押された瞬間のみジャンプする
	if (Key[KEY_INPUT_SPACE] == 1 && mIsGround)
	{
		mJumpUpNow = true;
	}
	// 一定の高さに行くまでジャンプアップ中にする
	if (mJumpUpNow)
	{
		mVelocity = VGet(0.0f, JUMP_UP_Y, 0.0f);

		mIsGround = false;         // 地面に接地していない

		if (mPos.y >= FIRST_MAX)
		{
			mJumpUpNow = false;    // もう上がらないのでUpNowをfalseにする
		}

	}
	// 一定の高さまでいったら位置を下げていく
	if (mPos.y >= FIRST_MAX)
	{
		mVelocity = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
	}

	// ポジション更新
	mPos = VAdd(mPos, mVelocity);
	if (mVelocity.y != 0.0f)
	{
		mVelocity.y = mVelocity.y - (mGravity / mPos.y);
	}

	// 初期位置まで戻ったら動きを止め,2回目のジャンプに移行する
	if (!mIsGround && mPos.y <= INIT_POS_Y)
	{
		if (mPos.y <= INIT_POS_Y)
		{
			mVelocity = VGet(0.0f, 0.0f, 0.0f);
			mPos.y = INIT_POS_Y;
			mIsGround = true;          // 地面に接地している 
			mFirstJump = false;        // 1回目のジャンプを終了する
			mSecondJump = true;        // 2回目のジャンプができるようにSecondJumpをtrueにする
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  2回目のジャンプ更新.
//-----------------------------------------------------------------------------
void Player::SecondJumpUpdate()
{
	// ボタンが押された瞬間のみジャンプする
	if (Key[KEY_INPUT_SPACE] == 1 && mIsGround)
	{
		mJumpUpNow = true;
	}
	// 一定の高さに行くまでジャンプアップ中にする
	if (mJumpUpNow)
	{
		mVelocity = VGet(0.0f, JUMP_UP_Y, 0.0f);

		mIsGround = false;         // 地面に接地していない

		if (mPos.y >= SECOND_MAX)
		{
			mJumpUpNow = false;    // もう上がらないのでUpNowをfalseにする
		}

	}
	// 一定の高さまでいったら位置を下げていく
	if (mPos.y >= SECOND_MAX)
	{
		mVelocity = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
	}

	// ポジション更新
	mPos = VAdd(mPos, mVelocity);
	if (mVelocity.y != 0.0f)
	{
		mVelocity.y = mVelocity.y - (mGravity / mPos.y);
	}

	// 初期位置まで戻ったら動きを止め,飛び込みのジャンプに移行する
	if (!mIsGround && mPos.y <= INIT_POS_Y)
	{
		if (mPos.y <= INIT_POS_Y)
		{
			mVelocity = VGet(0.0f, 0.0f, 0.0f);
			mPos.y = INIT_POS_Y;
			mIsGround = true;           // 地面に接地している 
			mSecondJump = false;        // 2回目のジャンプを終了する
			mThirdJump = true;          // 飛び込みジャンプができるようにSecondJumpをtrueにする
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  飛び込みジャンプ更新.
//-----------------------------------------------------------------------------
void Player::ThirdJumpUpdate()
{
	// ボタンが押された瞬間のみジャンプする
	if (Key[KEY_INPUT_SPACE] == 1 && mIsGround)
	{
		mJumpUpNow = true;
	}
	// 一定の高さに行くまでジャンプアップ中にする
	if (mJumpUpNow)
	{
		mVelocity = VGet(0.0f, JUMP_UP_Y, JUMP_UP_Z);

		mIsGround = false;         // 地面に接地していない

		if (mPos.y >= THIRD_MAX)
		{
			mJumpUpNow = false;    // もう上がらないのでUpNowをfalseにする
		}

	}
	// 一定の高さまでいったら位置を下げていく
	if (mPos.y >= THIRD_MAX)
	{
		mVelocity = VGet(0.0f, -JUMP_DOWN_Y, JUMP_DOWN_Z);
	}

	// ポジション更新
	mPos = VAdd(mPos, mVelocity);
	// y軸に力がかかった時に重力地
	if (mVelocity.y != 0.0f)
	{
		mVelocity.y = mVelocity.y - (mGravity / mPos.y);
	}

	// プールまでいったら動きを止める
	if (!mIsGround && mPos.y <= 0.0f)
	{
		if (mPos.y <= 0.0f)
		{
			mVelocity = VGet(0.0f, 0.0f, 0.0f);
			mPos.y = 0.0f;              // プールに埋まっていたら押し戻す
			mIsGround = true;           // 地面に接地している 
			mThirdJump = false;         // 飛び込みのジャンプを終了する
		}
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

