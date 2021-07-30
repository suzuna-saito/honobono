//-----------------------------------------------------------------------------
// @brief  障害物基底クラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
//共通してるのでObstructの子たちに継承させるクラス

#ifndef _OBSTRUCT_BASE_H_
#define _OBSTRUCT_BASE_H_

#include "DxLib.h"
#include "Common.h"

class UIGoal;

class ObstructBase
{
public:
	ObstructBase(int sourceModelHandle);	// コンストラクタ.
	virtual ~ObstructBase();				// デストラクタ.

	virtual void Update(UIGoal& uiGoal);				// 更新.
	virtual void Draw();					// 描画.
	virtual void SpeedUp(UIGoal& uiGoal);

	// モデルハンドルの取得.
	int GetModelHandle(){ return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }
	float GetHitRadius() { return hitRadius; }

protected:
	int		modelHandle;					// モデルハンドル.
	VECTOR	pos;							// ポジション.
	float	hitRadius;						// あたり判定の半径.
	VECTOR velocity;                        // 速度
	VECTOR BallPos;                         // ボールの位置
private:
	float rotationX;                        // 回転角度
};

#endif // _OBSTACLE_BASE_H_