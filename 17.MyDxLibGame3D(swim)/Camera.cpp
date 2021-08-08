﻿//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "Camera.h"

//カメラによる表示範囲の一番近い位置
const float CAMERA_NEAR = 0.1f;
//カメラによる表示範囲の一番遠い位置
const float CAMERA_FAR = 100.0f;

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
	:mPos(VGet(0,0,0))
{
	//奥行0.1～1000までをカメラの描画範囲とする（パースを調整してる。NearとFarの値）
	SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

/// <summary>
/// カメラの更新関数
/// カメラが動くのであればここでどうぞ
/// </summary>
void Camera::Update()
{

}