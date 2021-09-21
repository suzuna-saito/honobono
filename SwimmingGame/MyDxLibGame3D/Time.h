#pragma once
#include "DxLib.h"

/// <summary>
/// 時間のクラス
/// </summary>
class Time
{
private:

	int mTimeCount;              // フレーム数

	LONGLONG mNowTime;           // 今のシステム時間
	LONGLONG mTime;              // 前のシステム時間
	float mDeltaTime;            // デルタタイム
	int mFPS;                    // FPS
	int mFPSCounter;             // FPSを数える
	LONGLONG mFPSCheckTime;      // システム時間を保存

public:
	// コンストラクタ
	Time();
	// デストラクタ
	~Time();

	// 更新
	void Update();

	// FPS数値を描画
	void CheckFPS();

	// デルタタイムの値を渡す
	float GetDeltaTime() { return mDeltaTime; }
	// フレーム数を渡す
	int GetTimeCount() { return mTimeCount; }
};