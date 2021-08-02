#include "Fade.h"
#include "Common.h"
#include <DxLib.h>

const int F_TIME = 420;			// フェードインさせる時間(クリア時)
const int F_TIME2 = 150;		// フェードインさせる時間

/// <summary>
/// コンストラクタ
/// </summary>
Fade::Fade()
	: mfadeTime(F_TIME)
	, mfadeTime2(F_TIME2)
	, mAlphaMin(0)
	, mAlphaMax(255)
	, mAlphaVal(3)
	, mFadeCount(0)
{
	mEndFlag = false;
}

/// <summary>
/// デストラクタ
/// </summary>
Fade::~Fade()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="_InOut">フェードインアウトフラグ</param>
/// <param name="_color">色の構造体引数</param>
void Fade::Update(bool _InOut,Color _color)
{
	if (_InOut)
	{
		OutProcess(_color);
	}
	else
	{
		InProcess(_color);
	}
}

/// <summary>
/// フェードアウト更新
/// </summary>
/// <param name="_color">色の構造体引数</param>
void Fade::OutProcess(Color _color)
{
	// アルファ値の加算
	mAlphaMin += mAlphaVal;

	// アルファブレンド有効化(ここでアルファ値をセット)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaMin);

	// 画面全体に任意のカラーの四角形を描画
	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(_color.r, _color.g, _color.b), TRUE);

	// アルファブレンド無効化
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (mAlphaMin > 255)
	{
		mEndFlag = true;
	}
}

/// <summary>
/// フェードイン更新
/// </summary>
/// <param name="_color">色の構造体引数</param>
void Fade::InProcess(Color _color)
{
	// アルファ値の加算
	mAlphaMax -= mAlphaVal;

	// アルファブレンド有効化(ここでアルファ値をセット)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaMax);

	// 画面全体に任意のカラーの四角形を描画
	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(_color.r, _color.g, _color.b), TRUE);

	// アルファブレンド無効化
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (mAlphaMax < 0)
	{
		mEndFlag = true;
	}
}

/// <summary>
/// 初期化
/// </summary>
void Fade::Init()
{
	mAlphaMin = 0;
	mAlphaMax = 255;

	mEndFlag = false;

	mFadeCount = 0;
}
