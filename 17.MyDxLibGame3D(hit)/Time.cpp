#include "Time.h"

/// <summary>
/// コンストラクタ
/// </summary>
Time::Time()
	: mTimeCount(0)
	, mNowTime(0)
	, mDeltaTime(0.000001f)
	, mFPS(0)
	, mFPSCounter(0)
{
	// システム時間を取得
	mTime = GetNowHiPerformanceCount();
	mFPSCheckTime = GetNowHiPerformanceCount();
}

/// <summary>
/// デストラクタ
/// </summary>
Time::~Time()
{
}

/// <summary>
/// 時間の更新
/// </summary>
void Time::Update()
{
	// フレーム数を取得
	mTimeCount++;
	// 現在のシステム時間を取得
	mNowTime = GetNowHiPerformanceCount();

	// 前回取得した時間から経過時間を秒に変換してセット
	// (GetNowHiPerformanceCountで取得できる値はマイクロ秒単位なので1000000で割ることで秒単位になる）
	mDeltaTime = (mNowTime - mTime) / 1000000.0f;

	// 今回取得した時間を保存
	mTime = mNowTime;

	// FPS関係の処理(1秒経過する間に実行されたメインループの回数をFPSとする)
	mFPSCounter++;
	if (mNowTime - mFPSCheckTime > 1000000)
	{
		mFPS = mFPSCounter;
		mFPSCounter = 0;
		mFPSCheckTime = mNowTime;
	}
}

/// <summary>
/// FPS数値を描画
/// </summary>
void Time::CheckFPS()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS : %d", mFPS);
}
