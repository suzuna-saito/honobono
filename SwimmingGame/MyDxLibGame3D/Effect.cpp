#include "Effect.h"

Effect::Effect(const char* _SourceEffectHandle)
	:mEffectHandle(-1)
	,mPlayingEffect(-1)
{
	mEffectHandle = LoadEffekseerEffect(_SourceEffectHandle, 1.0);
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

void Effect::PlayScaleEffect(VECTOR _EffectPos, VECTOR _Scale)
{
	mPlayingEffect = PlayEffekseer3DEffect(mEffectHandle);

	SetScalePlayingEffekseer3DEffect(mPlayingEffect, _Scale.x, _Scale.y, _Scale.z);

	SetPosPlayingEffekseer3DEffect(mPlayingEffect, _EffectPos.x, _EffectPos.y, _EffectPos.z);
}
