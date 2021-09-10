//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"
#include "Time.h"

/// <summary>
/// カメラの更新
/// </summary>
class Camera:public Time
{
public:
	Camera();							// コンストラクタ.
	virtual ~Camera();				    // デストラクタ.

	// カメラセット
	void CameraSet();

	// 飛び込む前のカメラ更新
	void DivingCameraUpdate(Time& _time);

	// 描画位置確認用カメラ更新
	void TryDrawCameraUpdate();

	//------------------------------------
	// カメラ位置
	//------------------------------------
	// カメラ原点位置セット
	void SetOriginCameraUpdate();

	// 確認用カメラ @saito
	void FixedCameraUpUpdate();
	void FixedCameraRightUpdate(float _posZ);
	void FixedCameraBackUpdate(float _posZ, float _angleX);
private:
	int i;
	float mTimeCount;     // カメラ更新時間

	// カメラの奥行
	const float mNear;
	const float mFar;

	// カメラ
	VECTOR mPos;      // カメラ位置
	VECTOR mAngle;    // カメラ角度
};

#endif // _CAMERA_H_