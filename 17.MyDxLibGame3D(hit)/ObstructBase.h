//-----------------------------------------------------------------------------
// @brief  障害物基底クラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
//共通してるのでObstructの子たちに継承させるクラス

#ifndef _OBSTRUCT_BASE_H_
#define _OBSTRUCT_BASE_H_

#include "DxLib.h"
#include "Common.h"
/// <summary>
/// UIのクラスの定義
/// </summary>
class UIGoal;

/// <summary>
/// オブジェクトのベースクラスの定義
/// </summary>
class ObstructBase
{
public:
	ObstructBase(int _sourceModelHandle);    // コンストラクタ.
	virtual ~ObstructBase();    // デストラクタ.

	virtual void Update(UIGoal& _uiGoal);    // 更新.
	virtual void Draw();    // 描画.
	virtual void SpeedUp(UIGoal& _uiGoal);    //スピードが上がる

	// モデルハンドルの取得.
	int GetModelHandle(){ return mModelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return mPos; }
	void SetPos(const VECTOR _set) { mPos = _set; }
	float GetHitRadius() { return mHitRadius; }

protected:
	int		mModelHandle;    // モデルハンドル.
	VECTOR	mPos;    // ポジション.
	float	mHitRadius;    // あたり判定の半径.
	VECTOR mVelocity;    // 速度
	VECTOR mBallPos;    // ボールの位置
private:
	float mRotationX;    // 回転角度
};

#endif // _OBSTACLE_BASE_H_