/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/
#include "Fade.h"

const int CLEAR_FADEIN_TIME = 420;			// �t�F�[�h�C�������鎞��(�N���A��)
const int START_FADEIN_TIME = 150;		// �t�F�[�h�C�������鎞��(�����J�n��)
const int ALPHA_VALOCITY = 3;    //�A���t�@�ω��萔

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
