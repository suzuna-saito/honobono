//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once

class ObstructManager;
class Player;
class Satoshi;

class HitChecker
{
protected:
	int Count;             // 無敵状態カウント
	int DamageImg;         // ダメージエフェクト
	int hp;                // 体力
	float SizePoint;
	bool DrawFlag;
	bool isHit;            // 当たり判定

public:

	// コンストラクタ
	HitChecker();
	// デストラクタ
	~HitChecker();

	// エフェクトを描画
	void Draw(Player& player);
	// 当たり判定
	void Check(Player& player, ObstructManager& obstructManager);

	bool GetisHit() { return isHit; }
};