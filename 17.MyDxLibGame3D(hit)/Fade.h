#pragma once
struct Color;

/// <summary>
/// フェードのクラス
/// </summary>
class Fade
{
public:
	Fade();			// コンストラクタ
	~Fade();		// デストラクタ

	bool Draw(bool _InOut,Color _color);   // 更新

	bool OutProcess(Color _color);	// フェードアウト更新
	bool InProcess(Color _color);	// フェードイン更新

	void Init();				// 描画

	/*int GetFadeCount() { return mFadeCount; }*/

	int mfadeTime;				// フェードインさせる時間(クリア時)
	int mfadeTime2;				// 

	int mFadeCount;				// カウント

	bool GetEndFlag() { return mEndFlag; }

private:
	bool mEndFlag;              // フェード終わり
	int mAlphaMax;				// アルファ値の加算
	int mAlphaMin;				// アルファ値の減算
	const int mAlphaVal;		// アルファ変化値
};