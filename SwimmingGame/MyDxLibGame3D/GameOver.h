#pragma once
#include "SceneBase.h"

/// <summary>
/// ゲームオーバーシーンのクラス
/// </summary>
class GameOver : public SceneBase
{
public:
    /// コンストラクタ
    GameOver();
    /// デストラクタ
    ~GameOver();

    /// <summary>
    /// ゲームオーバーシーンの更新処理
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// ゲームオーバーシーンの描画
    /// </summary>
    void Draw()override;


private:

	int mOverText;            // ゲームオーバーテキスト
};