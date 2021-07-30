﻿//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"

//class Player;

class Camera
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }

	void PlayerUpdate();
	void SceneUpdate();

private:
	VECTOR	pos;			// ポジション.

};

#endif // _CAMERA_H_