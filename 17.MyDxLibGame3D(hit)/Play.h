#pragma once
#include "Camera.h"
#include "Time.h"
#include "BackGround.h"
#include "Pool.h"
#include "Fish.h"

/// <summary>
/// プレイクラス
/// </summary>
class Play
{
private:
	bool mEndFlag;              // 終了フラグ

public:
	// コンストラクタ
	Play();
	// デストラクタ
	~Play();

	// プレイシーン
	void PlayScene();

	// 値を渡す
	bool GetEndFlag() { return mEndFlag; }
};

