#include "Fade.h"
#include "Common.h"
#include <DxLib.h>

const int F_TIME = 420;			// �t�F�[�h�C�������鎞��(�N���A��)
const int F_TIME2 = 150;		// �t�F�[�h�C�������鎞��

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
Fade::~Fade()
{
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_InOut">�t�F�[�h�C���A�E�g�t���O</param>
/// <param name="_color">�F�̍\���̈���</param>
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
/// �t�F�[�h�A�E�g�X�V
/// </summary>
/// <param name="_color">�F�̍\���̈���</param>
void Fade::OutProcess(Color _color)
{
	// �A���t�@�l�̉��Z
	mAlphaMin += mAlphaVal;

	// �A���t�@�u�����h�L����(�����ŃA���t�@�l���Z�b�g)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaMin);

	// ��ʑS�̂ɔC�ӂ̃J���[�̎l�p�`��`��
	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(_color.r, _color.g, _color.b), TRUE);

	// �A���t�@�u�����h������
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (mAlphaMin > 255)
	{
		mEndFlag = true;
	}
}

/// <summary>
/// �t�F�[�h�C���X�V
/// </summary>
/// <param name="_color">�F�̍\���̈���</param>
void Fade::InProcess(Color _color)
{
	// �A���t�@�l�̉��Z
	mAlphaMax -= mAlphaVal;

	// �A���t�@�u�����h�L����(�����ŃA���t�@�l���Z�b�g)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaMax);

	// ��ʑS�̂ɔC�ӂ̃J���[�̎l�p�`��`��
	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(_color.r, _color.g, _color.b), TRUE);

	// �A���t�@�u�����h������
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (mAlphaMax < 0)
	{
		mEndFlag = true;
	}
}

/// <summary>
/// ������
/// </summary>
void Fade::Init()
{
	mAlphaMin = 0;
	mAlphaMax = 255;

	mEndFlag = false;

	mFadeCount = 0;
}
