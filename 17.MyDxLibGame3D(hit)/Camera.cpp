﻿//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
//#include "Player.h"
#include "Camera.h"

#define USE_LERP_CAMERA 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
	:pos(VGet(0,0,0))
{
	//奥行0.1～1000までをカメラの描画範囲とする（パースを調整してる。NearとFarの値）
	SetCameraNearFar(0.1f, 1000.0f);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

void Camera::PlayerUpdate()
{
	pos = VGet(0, 50, -40); //-1050-40

	// カメラの注視点を設定.
	SetCameraPositionAndTarget_UpVecY(pos, VGet(0, -40, 65));
	// プレイヤーを追尾する必要がないのでコンストラクタで固定したけど強引すぎ？？
}

void Camera::SceneUpdate()
{
	pos = VGet(0, 0, 0);

	SetCameraPositionAndTarget_UpVecY(pos, VGet(0, 400, -1000));
}
