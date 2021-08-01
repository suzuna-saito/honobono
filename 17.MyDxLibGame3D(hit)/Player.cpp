//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Player.h"
#include "ObstructBase.h"
#include "SceneBase.h"
#include "Hitchecker.h"


// -----------------------------------------------------------
//  @brief 定数
//------------------------------------------------------------
const float HIT_RADIUS = 3.0f;                     // 当たり判定の半径
const VECTOR EXPANDING = VGet(1.7f, 1.7f, 1.7f);   // プレイヤーを描画するときの拡大値

const float X_VELOCITY = 0.5f;                     // x方向の移動力
const int POS_MAX = 25;                            // ポジションの移動制限（最大）
const int POS_MIN = -40;                            // ポジションの移動制限（最小）
const float PUSH_BACK = 0.025f;                    // 押し戻しの値

const int MAX_HP = 3;                              // HPの初期値
const int HP_SIZE = 40;                            // HPの描画サイズの初期値
const int MAX_SIZE = 45;                           // HPの描画サイズの最大値
const int MIN_SIZE = 35;                           // HPの描画サイズの最小値
const float SIZE_POINT = 0.1f;                     // HPの描画サイズの大きさを変える値
const int HP_MOVE = 50;                            // HPの描画させる座標の変更値

const int R_POS[] = { 125,405 };                   // 右の矢印の座標
const int L_POS[] = { 0,405 };                     // 左の矢印の座標

const int DRAW_HP[] = { 3,3,1,80,80 };             // Hp画像の、分割総数、横向きに対する分割数と縦に対する分割数、分割された画像一つの大きさ
const int DRAW_VEL[] = { 2,2,1,75,75 };            // 矢印画像の、分割総数、横向きに対する分割数と縦に対する分割数、分割された画像一つの大きさ

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	: mHitRadius(HIT_RADIUS)
	, mModelHandle(-1)
	, mPos(VGet(0,0,0))
	, mPosY(0.0f)
	, mVelocity(VGet(0, 0, 0))
	, mDir(VGet(0, 0, 1))
	, mHp(MAX_HP)
	, mHpSize(HP_SIZE)
	, mSizePoint(SIZE_POINT)
	, mDrawFlag(true)
	, mMoveFlag(false)
	, mRMoveFlag(false)
	, mLMoveFlag(false)
{
	// プレイヤー３Ｄモデルの読み込み
	mModelHandle = MV1LoadModel("data/model/player/pika/pikapika.pmx");
	// モデルの拡大描画
	MV1SetScale(mModelHandle, EXPANDING);  
	
	// HP画像の読み込み
	LoadDivGraph("data/Asset/HP.png", DRAW_HP[0], DRAW_HP[1], DRAW_HP[2], DRAW_HP[3], DRAW_HP[4], mHpImg, TRUE);
	// 左矢印の読み込み
	LoadDivGraph("data/Asset/RightVector2.png", DRAW_VEL[0], DRAW_VEL[1], DRAW_VEL[2], DRAW_VEL[3], DRAW_VEL[4], mRightVectorGraph, TRUE);
	// 右矢印の読み込み
	LoadDivGraph("data/Asset/LeftVector2.png", DRAW_VEL[0], DRAW_VEL[1], DRAW_VEL[2], DRAW_VEL[3], DRAW_VEL[4], mLeftVectorGraph, TRUE);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(mModelHandle);
	DeleteGraph(*mHpImg);
	DeleteGraph(*mRightVectorGraph);
	DeleteGraph(*mLeftVectorGraph);
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
		mVelocity.x = X_VELOCITY;
		// 右の矢印を光らせる
		mRMoveFlag = true;
		mMoveFlag = true;
	}
	// 左を押したら左に移動.
	else if (Key & PAD_INPUT_LEFT)
	{
		mVelocity.x = -X_VELOCITY;
		// 左の矢印を光らせる
		mLMoveFlag = true;
		mMoveFlag = true;
	}
	// 何も押していない場合は止まる
	else if (Key == 0 || !(Key & PAD_INPUT_RIGHT && Key & PAD_INPUT_LEFT))
	{
		mVelocity = VGet(0, 0, 0);
		mDir = VGet(0, 0, 1);
		// 矢印をどちらも光らせない
		mRMoveFlag = false;
		mLMoveFlag = false;
		mMoveFlag = false;
	}


	// 移動制限
	if (mPos.x > POS_MAX)
	{
		mVelocity = VGet(0, 0, 0);
		mPos.x = mPos.x - PUSH_BACK;
	}
	if (mPos.x < POS_MIN)
	{
		mVelocity = VGet(0, 0, 0);
		mPos.x = mPos.x + PUSH_BACK;
	}

	
	// 上下方向にいかないようにベロシティを整える.
	mVelocity = VGet(mVelocity.x, 0, mVelocity.z);

	// ポジションを更新.
	mPos = VAdd(mPos, mVelocity);

	// 力をかけ終わったベロシティの方向にディレクションを調整.
	if (VSize(mVelocity) != 0)
	{
		mDir = VNorm(mVelocity);
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(mModelHandle, mPos);

	// 向きに合わせて回転.
	MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
	
	// モデルに向いてほしい方向に回転.
	MATRIX tmpMat = MV1GetMatrix(mModelHandle);
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	tmpMat = MMult(tmpMat, rotYMat);
	MV1SetRotationMatrix(mModelHandle, tmpMat);

	// Hpの大きさを拡大、縮小
	mHpSize += mSizePoint;
	
	// 一定数大きくなったら小さくする
	if (mHpSize > MAX_SIZE)
	{
		mSizePoint *= -1;
	}
	// 一定数小さくなったら大きくする
	else if (mHpSize < MIN_SIZE)
	{
		mSizePoint *= -1;
	}
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Player::Draw()
{
	// ３Ｄモデルの描画
	// ダメージを受けたら点滅させる
	if (mDrawFlag)
	{
		MV1DrawModel(mModelHandle);
	}

	// 矢印描画
	DrawGraph(L_POS[0], L_POS[1], mLeftVectorGraph[mLMoveFlag], TRUE);
	DrawGraph(R_POS[0], R_POS[1], mRightVectorGraph[mRMoveFlag], TRUE);

	// HPの描画
	if (mHp != 0)
	{
		for (int i = 0; i < mHp; i++)   // HPが減ったら表示数を減らす
		{
			int x = i * HP_MOVE;
			// DrawExtendGraph _HP描画(サイズを小さくしました)
			if (mHp == 1)
			{
				DrawExtendGraph(x, 0, x + (int)mHpSize, (int)mHpSize, mHpImg[2], TRUE);
			}
			else if (mHp == 2)
			{
				DrawExtendGraph(x, 0, x + (int)mHpSize, (int)mHpSize, mHpImg[1], TRUE);
			}
			else
			{
				DrawExtendGraph(x, 0, x + (int)mHpSize, (int)mHpSize, mHpImg[0], TRUE);
			}

		}
	}
}