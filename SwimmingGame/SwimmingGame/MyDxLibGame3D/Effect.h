#pragma once
#include "DxLib.h"
#include "EffekseerForDXLib.h"

class Effect
{
private:
	int mEffectHandle;
	int mPlayingEffect;

public:
	Effect(const char* _SourceEffectHandle);

	virtual ~Effect();

	void Delete();

	void StopEffect();

	void PlayScaleEffect(VECTOR _EffectPos, VECTOR _Scale);
};

