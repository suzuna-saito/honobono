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
	~Camera();							// デストラクタ.
										
	/// プレイ時のカメラの位置、注視点の更新
	void PlayerUpdate();

	/// プレイ時以外のカメラの位置、注視点の更新
	void SceneUpdate();

private:
	// カメラの奥行
	const float mNear;
	const float mFar;     

	// カメラ位置
	const VECTOR mPlayPos;      
	const VECTOR mOthersPos;

	// カメラの注視点
	const VECTOR mPlayTarget;  
	const VECTOR mOthersTarget;
};

#endif // _CAMERA_H_