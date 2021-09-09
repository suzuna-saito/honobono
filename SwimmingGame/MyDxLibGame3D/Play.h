#pragma once
#include "SceneBase.h"

// 前方宣言
class FishManager;
class Pool;
class Timing;
class BackGround;
class UIGoal;
class HitChecker;
class Camera;
class Result;
class BackGround;
class Time;
class Sound;
class Promotion;

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
    // スコアを保持する変数
    int mScore;

    // 魚(モブ)
    FishManager* fishManager =  nullptr ;
    // プール
    Pool* pool = nullptr;
    // リズムボタン
    Timing* timing = nullptr;
    // 広告
    Promotion* promo;
    // バックグラウンド
    BackGround* backGround;
    // 時間の生成
    Time* time;

    // リザルトシーン
    Result* result;

    Camera* camera;

    Sound* mPlayBGM1;
    Sound* mPlayBGM2;
    Sound* mPlayBGM3;
   
    // 飛び込んで水の入った時の音
    Sound* mWaterInSound;
    // シンクロでちゃぷちゃぷする音
    Sound* mWaterOutSound;


    /////// デバック用 /////////
    float test;
    float test02;
    float test03;

    void CameraPosUpDate();
};