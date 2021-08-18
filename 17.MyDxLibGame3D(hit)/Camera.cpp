﻿//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Camera.h"

// -----------------------------------------------------------
//  @brief 定数
//------------------------------------------------------------
const float CAMERA_NEAR = 0.1f;                                     // カメラの奥行(最小)
const float CAMERA_FAR = 100.0f;                                    // カメラの奥行(最大)
const float CAMERA_FAZE[4] = { 5.0f,10.0f,15.0f,20.0f };            // カメラ切り替え時間
const VECTOR ORIGIN_CAMERA_POS = VGet(0.0f, 0.0f, 0.0f);            // カメラ原点位置
const VECTOR ORIGIN_CAMERA_ANGLE = VGet(0.0f, 0.0f, 0.0f);          // カメラ原点角度
const VECTOR PLAY_CAMERA_POS[4] = { VGet(20.0f, 30.0f, -30.0f),     // 一つ目のカメラ位置
									VGet(1.0f, 28.0f, -24.0f),		// 二つ目のカメラ位置
									VGet(0.0f, 5.0f, 18.0f),		// 三つ目のカメラ位置
									VGet(12.0f, 5.0f, 24.0f) };		// 四つ目のカメラ位置
const VECTOR PLAY_CAMERA_ANGLE[4] = { VGet(0.50f, -0.80f, 0.0f),    // 一つ目のカメラ角度
									  VGet(0.50f, 0.0f, 0.0f),		// 二つ目のカメラ角度
									  VGet(0.0f, 3.210f, 0.0f),		// 三つ目のカメラ角度
									  VGet(0.0f, -2.50f, 0.0f) };	// 四つ目のカメラ角度

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
	: mNear(CAMERA_NEAR)
	, mFar(CAMERA_FAR)
	, mPos(ORIGIN_CAMERA_POS)
	, mAngle(ORIGIN_CAMERA_ANGLE)
	, mTimeCount(0)
	, i(0)
{
	//奥行0.1～1000までをカメラの描画範囲とする（パースを調整してる。NearとFarの値）
	SetCameraNearFar(mNear, mFar);
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
	// カメラ位置セット
	SetCameraPositionAndAngle(mPos, mAngle.x, mAngle.y, mAngle.z);
}

/// <summary>
/// 飛び込む前のカメラ更新
/// </summary>
/// <param name="_time">Timeクラスのポインタ変数</param>
void Camera::DivingCameraUpdate(Time& _time)
{
	// DeltaTimeを取得
	float DeltaTime = _time.GetDeltaTime();

	// DeltaTimeを更新時間に加算
	mTimeCount += DeltaTime;

	// 一周が終わったらカメラ更新時間をリセット
	if (mTimeCount > CAMERA_FAZE[3])
	{
		mTimeCount = 0;
		i = 0;
	}

	if (mTimeCount > CAMERA_FAZE[i])
	{
		i++;
	}

	mPos = PLAY_CAMERA_POS[i];
	mAngle = PLAY_CAMERA_ANGLE[i];

	CameraSet();
}

/// <summary>
/// カメラ位置セット
/// </summary>


/// <summary>
/// カメラ原点位置セット
/// </summary>
void Camera::SetOriginCameraUpdate()
{
	mPos = ORIGIN_CAMERA_POS;
	mAngle = ORIGIN_CAMERA_ANGLE;
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
		mPos.y += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPos.y -= 0.10f;
	}
	// 左右
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPos.x += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPos.x -= 0.10f;
	}
	// 奥行き
	if (CheckHitKey(KEY_INPUT_Z))
	{
		mPos.z += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		mPos.z -= 0.10f;
	}

	// 角度変更
	// 垂直方向
	if (CheckHitKey(KEY_INPUT_W))
	{
		mAngle.x += 0.01f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		mAngle.x -= 0.01f;
	}
	// 水平方向
	if (CheckHitKey(KEY_INPUT_D))
	{
		mAngle.y += 0.01f;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		mAngle.y -= 0.01f;
	}
	// 捻り回転
	if (CheckHitKey(KEY_INPUT_E))
	{
		mAngle.z += 0.01f;
	}
	if (CheckHitKey(KEY_INPUT_Q))
	{
		mAngle.z -= 0.01f;
	}

	// カメラ座標を描画
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Pos( %f, %f, %f)\nAngle( %f, %f, %f)"
		, mPos.x
		, mPos.y
		, mPos.z
	    , mAngle.x
	    , mAngle.y
	    , mAngle.z);

	CameraSet();
}
