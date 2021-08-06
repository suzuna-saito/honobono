#ifndef _FADE_H_
#define _FADE_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include<DxLib.h>

/// <summary>
/// 光の三原色、それぞれの値
/// ここの値を変えることで色が変化
/// </summary>
struct Color
{
	float m_red;
	float m_green;
	float m_blue;
};

/// <summary>
/// フェードイン・フェードアウトクラス
/// </summary>
class Fade
{
public:
	Fade();			// コンストラクタ
	~Fade();		// デストラクタ

	void Update(bool _InOut,Color _color);    //更新関数

	void OutProcess(Color _color);	// フェードアウト更新
	void InProcess(Color _color);	// フェードイン更新

	void Draw();				// 描画関数

	/*int GetFadeCount() { return mFadeCount; }*/


	bool GetEndFlag() { return mEndFlag; }

private:
	bool mEndFlag;
	int mAlphaMax;				// アルファ値の加算
	int mAlphaMin;				// アルファ値の減算
	const int mAlphaVal;		// アルファ変化値
	int mClearFadeInTime;				// フェードインさせる時間(クリア時)
	int mStartFadeInTime;				// フェードインさせる時間(多分開始時)

	int mFadeCount;				// カウント

};

#endif //_FADE_H_