#pragma once
#include "SceneBase.h"

// 前方宣言
class Fish;
class Pool;

/// <summary>
/// タイトルシーンの生成、描画
/// </summary>
class Title : public SceneBase
{
public:
    /// コンストラクタ
    Title();
    /// デストラクタ
    ~Title();

    /// <summary>
    /// タイトルシーンの更新処理
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// タイトルシーンの描画
    /// </summary>
    void Draw()override;

private:

    Fish* fish = nullptr;

    Pool* pool = nullptr;

    int mTitleText;    // タイトルテキスト
};