#pragma once
#include "DxLib.h"

class Promotion
{
public:

	// コンストラクタ
	Promotion();
	// デストラクタ
	~Promotion();

	/// <summary>
	/// 広告の表示
	/// </summary>
	void Draw();

private:
	// 表示させるポジション
	const VECTOR mDrawPos;

	// シンプルな広告
	int mSimple;

	int mPromo;
};

