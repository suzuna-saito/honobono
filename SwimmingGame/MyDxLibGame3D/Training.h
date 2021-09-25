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

    // 今のセリフ
    enum nowDia
    {
        zero,
        one,
        two,
        three,
        four,
        five,
        six,

        skipZero,
        skipOne,
        skipTwo,
        skipThree,
        skipFour,
        skipFive,

        skipEnd, // スキップ時のセリフを全て出し終わった

        endZero,
        endOne,
        endTwo,
        endThree,
        endFour,

        playEnd, // perfectを5回取ったあとのセリフを出し終わった

        stop     // セリフを出すのを止める
    };

    // プレイ中のリアクション
    // perfect
    enum perfectDia
    {
        successOne,
        successTwo,
        successThree,
        successFour,
        successFive,
        successSix,
    };
    enum goodDia
    {
        goodOne,
        goodTwo,
        goodThree
    };
    enum badDia
    {
        badOne,
        badTwo
    };
    enum nonDia
    {
        nonOne,
        nonTwo
    };

private:

    int mModelHandle;     // 魚のハンドル

    VECTOR mPos;          // 魚のポジション
    VECTOR mRot;          // 魚の向き
    VECTOR mDance;        // ダンスポジションはないが、引数として渡すため変数を作成

    int mTime;            // 時間計測用

    int mTrainingText;    // 練習中テキスト
    int mSkipText;        // スキップテキスト


    bool mFirstDrawFlag;  // 最初のセリフたちを描画するフラグ
    bool mSkipDrawFlag;   // スキップ時のテキストを描画するフラグ
    bool mPlayDrawFlag;   // 練習中の時のテキストを描画するフラグ
    bool mEndDrawFlag;    // シーン遷移時のテキスト描画フラグ

    int mNowDia;          // 今のセリフ
    int mPlayNowDia;      // プレイ中のセリフ

    int mDrawDia;         // 表示させるセリフ
    int mDrawReaction;    // 表示させるリアクション

    int mPerfectCount;    // perfectを取った回数をカウント

    // リズムボタン
    Timing* timing = nullptr;
    // 魚
    Fish* fish;
    // プール
    Pool* pool = nullptr;
    // バックグラウンド
    BackGround* backGround;
    // カメラ
    Camera* camera;
    // サウンド
    Sound* mPlayBGM1;
};