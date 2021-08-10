//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Camera.h"

// -----------------------------------------------------------
//  @brief 定数
//------------------------------------------------------------
const float CAMERA_NEAR = 0.1f;                                     // カメラの奥行(最小)
const float CAMERA_FAR = 100.0f;                                    // カメラの奥行(最大)
const VECTOR ORIGIN_CAMERA_POS = VGet(0.0f, 0.0f, 0.0f);            // 確認用カメラ原点位置
const VECTOR BESIDE_CAMERA_POS = VGet(44.0f, 18.0f, -10.0f);      // 確認用カメラ（横固定）@saito
const VECTOR FIRST_CAMERA_POS = VGet(20.0f, 30.0f, -30.0f);         // 一つ目のカメラ

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
	: mNear(CAMERA_NEAR)
	, mFar(CAMERA_FAR)
	, mPos(ORIGIN_CAMERA_POS)
	, mVAngle(0.0f)
	, mHAngle(0.0f)
	, mTAngle(0.0f)
{
	//奥行0.1～1000までをカメラの描画範囲とする（パースを調整してる。NearとFarの値）
	SetCameraNearFar(mNear, mFar);
	FixedCameraUpdate();
	CameraSet();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

/// <summary>
/// カメラセット
/// </summary>
void Camera::CameraSet()
{
	SetCameraPositionAndAngle(mPos, mVAngle, mHAngle, mTAngle);
}

/// <summary>
/// 一つ目のカメラ位置セット
/// </summary>
void Camera::FirstCameraUpdate()
{
	mPos = FIRST_CAMERA_POS;
	mVAngle = 0.5f;
	mHAngle = -0.8f;
	mTAngle = 0.0f;
}

/// <summary>
/// カメラ原点位置セット
/// </summary>
void Camera::SetOriginCameraUpdate()
{
	mPos = ORIGIN_CAMERA_POS;
	mVAngle = 0.0f;
	mHAngle = 0.0f;
	mTAngle = 0.0f;
}


/// <summary>
/// 横からの固定カメラ（飛び込み確認用）@saito
/// </summary>
void Camera::FixedCameraUpdate()
{
	mPos = BESIDE_CAMERA_POS;
	mVAngle = 3.0f;
	mHAngle = 1.8f;
	mTAngle = -3.1f;
}

/// <summary>
/// 描画確認用カメラ更新(自分で動かせるカメラを呼び出す)
/// 描画状態を確認したいとき呼出し
/// </summary>
void Camera::TryDrawCameraUpdate()
{
	// 上下左右奥行き移動
	// 上下
	if(CheckHitKey(KEY_INPUT_UP))
	{
		mPos.y += 1;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPos.y -= 1;
	}
	// 左右
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPos.x += 1;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPos.x -= 1;
	}
	// 奥行き
	if (CheckHitKey(KEY_INPUT_Z))
	{
		mPos.z += 1;
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		mPos.z -= 1;
	}

	// 角度変更
	// 垂直方向
	if (CheckHitKey(KEY_INPUT_W))
	{
		mVAngle += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		mVAngle -= 0.10f;
	}
	// 水平方向
	if (CheckHitKey(KEY_INPUT_D))
	{
		mHAngle += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		mHAngle -= 0.10f;
	}
	// 捻り回転
	if (CheckHitKey(KEY_INPUT_E))
	{
		mTAngle += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_Q))
	{
		mTAngle -= 0.10f;
	}

	// カメラ座標を描画
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Pos( %f, %f, %f)\nAngle( %f, %f, %f)"
		, mPos.x
		, mPos.y
		, mPos.z
	    , mVAngle
	    , mHAngle
	    , mTAngle);

	// カメラ位置変更
	SetCameraPositionAndAngle(mPos, mVAngle, mHAngle, mTAngle);
}
