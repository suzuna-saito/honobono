#pragma once
#include "SceneBase.h"

// 前方宣言
class Fish;
class Pool;
class Timing;
class BackGround;
class Camera;
class Play;
class Sound;
class Time;

/// <summary>
/// プレイシーンの生成、描画
/// </summary>
class Training : public SceneBase
{
public:
    /// コンストラクタ
    Training();
    /// デストラクタ
    ~Training();

    /// <summary>
    /// プレイシーンの更新処理
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// プレイシーンの描画
    /// </summary>
    void Draw()override;

private:

    int mModelHandle;

    VECTOR mPos;
    VECTOR mRot;
    VECTOR mDance;

    // リズムボタン
    Timing* timing = nullptr;
    // 魚
    Fish* fish;
    // プール
    Pool* pool = nullptr;
    // バックグラウンド
    BackGround* backGround;
    // 時間の生成
    Time* time;

    Camera* camera;

    Sound* mPlayBGM1;
};