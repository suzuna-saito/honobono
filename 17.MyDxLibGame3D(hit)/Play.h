#pragma once
#include "SceneBase.h"
#include "BackGround.h"
#include "Player.h"
#include "UIGoal.h"
#include "UIFireworks.h"
#include "Satoshi.h"
#include "ObstructManager.h"
#include "Hitchecker.h"


/// <summary>
/// プレイシーンの生成、描画
/// </summary>
class Play : public SceneBase
{
public:
    /// コンストラクタ
    Play();
    /// デストラクタ
    ~Play();

    /// <summary>
    /// プレイシーンの更新処理
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// プレイシーンの描画
    /// </summary>
    void Draw()override;

private:
	// 背景を生成.
	BackGround* backGround;
	// プレイヤーを生成.
	Player* player;
	// UI（ゴール）の生成
	UIGoal* uiGoal;
	// UI(花火)の生成
	UIFireworks* uiFire;
	// サトシを生成
	Satoshi* satoshi;
	// 障害物を生成.
	ObstructManager* obstructManager;
	// 当たり判定を生成
	HitChecker* hit;
};