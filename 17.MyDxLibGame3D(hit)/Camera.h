//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"

/// <summary>
/// カメラの更新
/// </summary>
class Camera
{
public:
	Camera();							// コンストラクタ.
	virtual ~Camera();				    // デストラクタ.

	// カメラセット
	void CameraSet();

	// 描画位置確認用カメラ更新
	void TryDrawCameraUpdate();

	//------------------------------------
	// カメラ位置
	//------------------------------------
	// 一つ目のカメラ位置
	void FirstCameraUpdate();

	// カメラ原点位置セット
	void SetOriginCameraUpdate();

private:
	// カメラの奥行
	const float mNear;
	const float mFar;

	// カメラ
	VECTOR mPos;      //カメラ位置
	float mVAngle;	  //垂直方向アングル
	float mHAngle;	  //水平方向アングル
	float mTAngle;	  //捻り回転アングル
};

#endif // _CAMERA_H_