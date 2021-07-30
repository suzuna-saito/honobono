#pragma once
struct Color;
class Fade
{
public:
	Fade();			// コンストラクタ
	~Fade();		// デストラクタ

	void Update(bool _InOut,Color _color);

	void OutProcess(Color _color);	// フェードアウト更新
	void InProcess(Color _color);	// フェードイン更新

	void Init();				// 描画

	/*int GetFadeCount() { return mFadeCount; }*/

	int fadeTime;				// フェードインさせる時間(クリア時)
	int fadeTime2;				// 

	int mFadeCount;				// カウント

	bool GetEndFlag() { return mEndFlag; }

private:
	bool mEndFlag;
	int mAlphaMax;				// アルファ値の加算
	int mAlphaMin;				// アルファ値の減算
	const int mAlphaVal;		// アルファ変化値
};