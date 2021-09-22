#pragma once
#include "DxLib.h"

class Score;

/// <summary>
/// タイミングゲージのクラス
/// </summary>
class Timing
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Timing();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Timing();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(bool _sound);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// スコアを取得
	/// </summary>
	/// <returns>現在のスコアを返す</returns>
	int GetRadius() { return mScoreRadius; }
	bool GetScoreFlag() { return mScoreFlag; }

	/// <summary>
	/// CSVデータの読み込み
	/// </summary>
	void CSVRead();


	// 判定
	enum judgement
	{
		bad,
		good,
		perfect,
		notDone,  // 何も押されなかった

		none      // ゲージが出てない
	};

	// 判定の取得
	judgement GetJudg() { return mJudge; }

private:            // 長くなってきたので説明を横に置きました。
	// 判定
	// 今の判定が何だったか
	judgement mJudge;


	//  フラグ
	bool mTimingDrawFlag;                 // タイミングゲージを描画するフラグ管理
	bool mTimingFlag;                     // タイミングゲージのクリック出来るかのフラグ管理
	bool mReactionFlag;                   // Reactionのフラグ管理

	//  ゲージ
	int mGageX;                        // ゲージの座標X
	int mGageY;                        // ゲージの座標Y
	int mGageCX;                       // ゲージの中心座標X
	int mGageCY;                       // ゲージの中心座標Y
	int mRadius;                       // 収縮するゲージの半径
	int mGageRadius;                   // 判定がパーフェクトになるゲージの半径
	int mRadiusInit;                   // 半径の初期化

	int mImgDirection;                 // ゲージ画像のランダムに右か左かを格納する変数
	int mBaseGagePoint;                // どこまでの数字をランダムにするか
	int mRightGagePosX;                // 右のゲージのX座標
	int mRightGagePosY;                // 右のゲージのY座標
	int mLeftGagePosX;                 // 左のゲージのX座標
	int mLeftGagePosY;                 // 左のゲージのY座標

	//  色
	int	mBrack;                      // 黒色
	int mWhite;                      // 白色

	//  リアクション
	int mTimingImg[2];               // タイミングゲージの画像
	int mFreamImg;                   // リアクションが描画される位置にあるフレームの画像
	int mFreamX;                     // フレームの座標X
	int mFreamY;                     // フレームの座標Y
	int mJudgeImg;                   // 判定画像
	int mPerfectImg;                 // Perfect判定画像
	int mGoodImg;                    // Good判定画像
	int mBadImg;                     // Bad判定画像
	int mReactionX;                  // リアクションの座標X
	int mReactionY;                  // リアクションの座標Y
	int mMaxRadius;                  // ノーツ最大の大きさ
	float mPerfectSize;              // パーフェクトの半径
	float mBadSize;                  // バッドの半径

	float mFrameSize;                // フレームの大きさ
	float mFrameShrinkPoint;         // 収縮する値

	float mFrameMovePoint;           // フレームの
	float mFrameShrinkGage;          // 収縮するゲージの値
	float mFrameSizeInit;            // フレームの初期化
	float mFrameMoveInit;            // フレーム

	int mBaseTime;                   // ランダムに格納する値をこれより下回らない
	int mBaseTimePoint;              // ランダムに格納する値の引数値
	int mRandomTime;                 // ノーツを出す次のタイミング
	bool mRandomFlag;                // ランダムな値を格納していいかどうか
	int mNotesStartTime;             // ノーツを開始させる時間
	int mNotesEndTime;               // ノーツを終わらせる時間

	int mDifficultyCount;            // 難易度を上げるカウント    

	//  カウント
	int mReactionCount;              // リアクションを描画する時間をカウントする
	int mReactionCountMax;           // リアクションを描画する時間の最大値
	int mCountInit;                  // カウントを初期化
	int mCount;                      // ノーツ開始までをはかるカウント
	int mTimeCount;                  // 曲の経過カウント

	//  CSV
	char mCsv[24] = "data/CSV/TestTiming.csv";         // CSVファイルを格納
	FILE* mFilePointer;                                // ファイルのポインタ
	char mCsvData;                                     // データを格納

	float mNum;
	char mBuffer[10];
	float mCell[1][23];
	int mColumnNum;
	int mRawNum;
	bool mEofFlag;
	float mRhythm[23];

	//  スコア
	bool mScoreFlag;        // Score処理フラグ
	int mScoreRadius;       // スコア


	//  エフェクト
	int mEffectImg;               // エフェクト画像      
	int mPerfectEffectImg;        // パーフェクトエフェクト画像
	int mGoodEffectImg;           // グッドエフェクト画像
	int mBadEffectImg;            // バッドエフェクト画像

	int mEffectPosY;              // ゲージを中心のエフェクトY座標(ゲージの中心から少し上にあげる)
	double mEffectScale;          // エフェクトの大きさ
	double mEffectAngle;          // エフェクトのアングル
	double mScalePlus;            // エフェクトがだんだん大きくなる時にプラスする値
	double mAngleRotate;          // エフェクトが開店する時にプラスする値
	bool mEffectFlag;             // エフェクトを発生させるフラグ

	//  サウンド
	class Sound* mPerfectSound;       // パーフェクトの時になる効果音
	class Sound* mGoodSound;          // グッドの時になる効果音
	class Sound* mBadSound;           // バッドの時になる効果音

	int i = 0;

};

