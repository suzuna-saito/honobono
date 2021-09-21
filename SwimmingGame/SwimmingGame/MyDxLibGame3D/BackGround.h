#pragma once
#include "DxLib.h"

class BackGround
{
private:
	int mModelHandle[6];
	int mTexture[6];
	int i;

	VECTOR mPos[6];
	VECTOR mSize[6];
	VECTOR mRotate[6];

	const int WALL_NUM;
	const VECTOR LIGHT_POS;
	const VECTOR LIGHT_ROTATE;

public:
	BackGround();
	virtual ~BackGround();

	void Draw();
};