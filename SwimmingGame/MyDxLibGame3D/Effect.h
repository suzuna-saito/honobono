#pragma once
#include "DxLib.h"
#include "EffekseerForDXLib.h"

class Effect
{
private:
	VECTOR mEffectPos;

	int mEffectHandle;
	int mPlayingEffect;

public:
	Effect(const char* _SourceEffectHandle);

	virtual ~Effect();

	void Delete();

	void StopEffect();

	void PlayEffect();
};

