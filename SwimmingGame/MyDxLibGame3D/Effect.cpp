#include "Effect.h"

Effect::Effect(const char* _SourceEffectHandle)
	:mEffectHandle(-1)
	,mEffectPos(VGet(0,0,0))
	,mPlayingEffect(-1)
{
	mEffectHandle = LoadEffekseerEffect(_SourceEffectHandle);
}

Effect::~Effect()
{

}

void Effect::Delete()
{
	DeleteEffekseerEffect(mEffectHandle);
}

void Effect::StopEffect()
{
	StopEffekseer3DEffect(mPlayingEffect);
	mPlayingEffect = IsEffekseer3DEffectPlaying(mPlayingEffect);
}

void Effect::PlayEffect()
{
	mPlayingEffect = PlayEffekseer3DEffect(mEffectHandle, );

	SetScalePlayingEffekseer3DEffect(mPlayingEffect,)

	SetPosPlayingEffekseer3DEffect(mPlayingEffect, mEffectPos.x, mEffectPos.y, mEffectPos.z);
}
