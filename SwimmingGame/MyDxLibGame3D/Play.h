#pragma once
#include "SceneBase.h"


// 前方宣言
class FishManager;
class Pool;
class Timing;
class BackGround;
class Player;
class HitChecker;
class Camera;
class Result;
class BackGround;
class Time;
class Sound;

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
    // 魚が動き始めるまでのカウント
    int startCount;

    // スコアを保持する変数
    int mScore;

    // 魚(モブ)
    FishManager* fishManager =  nullptr ;
    // プール
    Pool* pool = nullptr;
    // リズムボタン
    Timing* timing = nullptr;
    // 魚(プレイヤー)
	Player* player;
	// 当たり判定
	HitChecker* hit;
    // バックグラウンド
    BackGround* backGround;
    // 時間の生成
    Time* mtime;

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


};