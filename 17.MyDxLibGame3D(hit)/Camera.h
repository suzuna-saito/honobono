//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"
#include "Time.h"

/// <summary>
/// カメラのクラス
/// </summary>
class Camera : public Time
{
public:
	Camera();							// コンストラクタ.
	virtual ~Camera();				    // デストラクタ.

	// カメラセット
	void CameraSet(Time& _time);

	// 飛び込む前のカメラ更新
	void DivingCameraUpdate(Time& _time);

	// 描画位置確認用カメラ更新
	void TryDrawCameraUpdate();

	//------------------------------------
	// カメラ位置
	//------------------------------------
	// 一つ目のカメラ位置
	void FirstCameraUpdate();
	// 二つ目のカメラ位置
	void SecondCameraUpdate();
	// 三つ目のカメラ位置
	void ThirdCameraUpdate();
	// 四つ目のカメラ位置
	void FourthCameraUpdate();
	// カメラ原点位置セット
	void SetOriginCameraUpdate();

private:
	float mTimeCount;     // カメラ更新時間

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