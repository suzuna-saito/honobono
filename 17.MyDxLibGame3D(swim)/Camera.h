//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "DxLib.h"

/// <summary>
/// カメラクラス
/// </summary>
class Camera
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	/// <summary>
	/// ポジションのgetter/setter.
	/// </summary>
	/// <returns>その時のカメラの位置を返す</returns>
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

	void Update();    // カメラの更新関数


private:
	VECTOR	mPos;			// ポジション.

};

#endif // _CAMERA_H_