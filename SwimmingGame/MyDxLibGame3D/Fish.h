#pragma once
#include "DxLib.h"

class Jump;

/// <summary>
/// Playerクラス
/// </summary>
class Fish
{
public:
	// コンストラクタ
	Fish(VECTOR _pos,VECTOR _rotate);
	// デストラクタ
	virtual ~Fish();

	// 更新関数
	void Update();
	// 描画関数
	void Draw();

private:

	int mMHandle;                   // Mob画像変数 
	int MobFishTexture;             // Mobテクスチャ

	VECTOR mMobPos[11];             // Mobの座標

	const VECTOR FISH_MOB_ROTATE[11];    // Mobの回転角度
	const int FISH_MOB_NUM;                  // 魚の数

	 // ジャンプ
	Jump* jump;
};