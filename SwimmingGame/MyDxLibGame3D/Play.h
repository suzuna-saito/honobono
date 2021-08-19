#pragma once
#include "SceneBase.h"

// 前方宣言
class Fish;
class Pool;
class Timing;
class BackGround;
class Player;
class HitChecker;

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
    // 魚
    Fish* fish = nullptr;
    // プール
    Pool* pool = nullptr;
    // リズムボタン
    Timing* timing = nullptr;
	// 背景
	BackGround* backGround;
	// プレイヤー
	Player* player;
	// UI（ゴール）
	//UIGoal* uiGoal;
	// 当たり判定
	HitChecker* hit;

};