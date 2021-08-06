#pragma once
#include "SceneBase.h"

/// <summary>
/// ゲームクリアシーンのクラス
/// </summary>
class GameClear : public SceneBase
{
public:
    /// コンストラクタ
    GameClear();
    /// デストラクタ
    ~GameClear();

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
    Camera* camera = new Camera();

	int mClearText;             
};