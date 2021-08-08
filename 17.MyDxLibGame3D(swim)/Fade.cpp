/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "Fade.h"

const int CLEAR_FADEIN_TIME = 420;			// フェードインさせる時間(クリア時)
const int START_FADEIN_TIME = 150;		// フェードインさせる時間(多分開始時)
const int ALPHA_VALOCITY = 3;    //アルファ変化定数

Fade::Fade()
	: mClearFadeInTime(CLEAR_FADEIN_TIME)
	, mStartFadeInTime(START_FADEIN_TIME)
	, mAlphaMin(0)
	, mAlphaMax(255)
	, mAlphaVal(ALPHA_VALOCITY)
	, mFadeCount(0)
	,mEndFlag(false)
{
}

Fade::~Fade()
{
}

void Fade::Update(bool _InOut, Color _color)
{
}


void Fade::OutProcess(Color _color)
{
}

void Fade::InProcess(Color _color)
{
}

void Fade::Draw()
{
}
