//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _OBSTRUCT_MANAGER_H_
#define _OBSTRUCT_MANAGER_H_
#include "Common.h"

/// <summary>
/// 各クラスの定義
/// </summary>
class ObstructBase;
class Player;
class UIGoal;

// 障害物の数.
const int LINE_OBSTRUCT_COL = 7;
const int LINE_OBSTRUCT_RAW = 60;

const float OBSTRUCT_SPACE_D = 50.0f;    // 障害物の縦間隔.
const float  OBSTRUCT_SPACE_W = 20.0f;    // 障害物の横間隔.

/// <summary>
/// オブジェクトの全てをまとめるクラス
/// </summary>
class ObstructManager final
{
public:
	ObstructManager();				// コンストラクタ.
	~ObstructManager();				// デストラクタ.

	void CreateObstructs();			// 障害物生成.
	void DestroyObstructs();		// 障害物削除.

	void Update(Player& _player, UIGoal& _uiGoal);					// 更新.
	void Draw();					// 描画.
	VECTOR GetBallPos() { return mBallPos; }

	// 指定番号の障害物を取得.
	ObstructBase* GetObstruct(int _raw, int _col);

private:
	ObstructBase* mObstructs[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];
	int mBallHandle;                 // ボールの画像

	int mFloatModelSourceHandle;		// 浮遊モデルの大本のハンドル.
	/*int staticModelSourceHandle;*/	// 静止モデルの大本のハンドル.
	VECTOR mBallPos;                   // ボールの位置
	VECTOR mVelocity;                  // 速度
	bool mBallFlag;                    // ボール出現フラグ
	float mRotationX;                  // 回転角度
};

#endif // _OBSTRUCT_MANAGER_H_