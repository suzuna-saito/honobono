#pragma once
#include "SceneBase.h"

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
    // カメラを生成.
    Camera* camera;

    int mTitleText;    // タイトルテキスト
};