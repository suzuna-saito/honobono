#pragma once
#include "DxLib.h"

const int FISH_MOB_NUM = 11;    // 魚の数

/// <summary>
/// プレイヤークラスの定義
/// </summary>
class Player;

/// <summary>
/// Playerクラス
/// </summary>
class Fish
{
private:

	int mMHandle;                   // Mob画像変数 
	int MobFishTexture;             // Mobテクスチャ

	VECTOR mMobPos[FISH_MOB_NUM];             // Mobの座標

	bool mFirstJump;        // 1回目のジャンプをするか
	bool mSecondJump;       // 2回目のジャンプをするか
	bool mThirdJump;        // 飛び込みのジャンプをするか

	bool mJumpUpNow;        // ジャンプアップしている

	bool mIsGround;         // 地面との接地判定


	Player* mp;    //Playerのクラス変数

	VECTOR mVelocity;

	const VECTOR FISH_MOB_ROTATE[FISH_MOB_NUM];    // Mobの回転角度

public:
	// コンストラクタ
	Fish();
	// デストラクタ
	virtual ~Fish();

	// 更新関数
	void Update();
	// 描画関数
	void Draw();

	//プレイヤーと同じジャンプをするための関数
	//関数の中はプレイヤーのJump関数とほぼ同じです
	/// <summary>
	/// 1回目のジャンプ更新処理
	/// </summary>
	void FirstJumpUpdate(int _mobNum);
	/// <summary>
	/// 2回目のジャンプ更新処理
	/// </summary>
	void SecondJumpUpdate(int _mobNum);
	/// <summary>
	/// 飛び込みのジャンプ更新処理
	/// </summary>
	void ThirdJumpUpdate(int _mobNum);
};