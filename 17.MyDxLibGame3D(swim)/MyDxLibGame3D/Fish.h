#pragma once
#include "DxLib.h"

/// <summary>
/// Playerクラス
/// </summary>
class Fish
{
private:

	int mPHandle;                   // Player画像変数
	int mMHandle;                   // Mob画像変数 
	int FishTexture;                // Playerテクスチャ
	int MobFishTexture;             // Mobテクスチャ
	int i;

	VECTOR mPos;                    // Playerの座標
	VECTOR mMobPos[11];             // Mobの座標

	const VECTOR FISH_SIZE;              // Player&Mobサイズ
	const VECTOR FISH_ROTATE;            // Playerの回転角度
	const VECTOR FISH_MOB_ROTATE[11];    // Mobの回転角度
	const int FISH_MOB_NUM;                  // 魚の数

public:
	// コンストラクタ
	Fish();
	// デストラクタ
	virtual ~Fish();

	// 描画関数
	void Draw();
	// 更新関数
	void Update();
};