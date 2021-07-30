//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _OBSTRUCT_MANAGER_H_
#define _OBSTRUCT_MANAGER_H_
#include "Common.h"


class ObstructBase;
class Player;
class UIGoal;

// 障害物の数.
#define LINE_OBSTRUCT_COL 7
#define LINE_OBSTRUCT_RAW 60

#define OBSTRUCT_SPACE_D 50.0f // 障害物の縦間隔.
#define OBSTRUCT_SPACE_W 20.0f // 障害物の横間隔.

class ObstructManager final
{
public:
	ObstructManager();				// コンストラクタ.
	~ObstructManager();				// デストラクタ.

	void CreateObstructs();			// 障害物生成.
	void DestroyObstructs();		// 障害物削除.

	void Update(Player& player, UIGoal& uiGoal);					// 更新.
	void Draw();					// 描画.
	VECTOR GetBallPos() { return BallPos; }

	// 指定番号の障害物を取得.
	ObstructBase* GetObstruct(int raw, int col);

private:
	ObstructBase* obstructs[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];
	int BallHandle;                 // ボールの画像

	int floatModelSourceHandle;		// 浮遊モデルの大本のハンドル.
	/*int staticModelSourceHandle;*/	// 静止モデルの大本のハンドル.
	VECTOR BallPos;                   // ボールの位置
	VECTOR Velocity;                  // 速度
	bool BallFlag;                    // ボール出現フラグ
	float rotationX;                  // 回転角度
};

#endif // _OBSTRUCT_MANAGER_H_