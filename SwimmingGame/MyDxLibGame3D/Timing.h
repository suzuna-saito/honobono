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
	void Update();

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

protected:
	

private:
	// 判定
	// 今の判定が何だったか
	judgement mJudge;


	//  フラグ
	// タイミングゲージを描画するフラグ管理
	bool mTimingDrawFlag;
	// タイミングゲージのクリック出来るかのフラグ管理
	bool mTimingFlag;
	// Reactionのフラグ管理
	bool mReactionFlag;

	//  ゲージ
	// ゲージの座標X
	int mGageX;
	// ゲージの座標Y
	int mGageY;
	// ゲージの中心座標X
	int mGageCX;
	// ゲージの中心座標Y
	int mGageCY;
	// 収縮するゲージの半径
	int mRadius;
	// 判定がパーフェクトになるゲージの半径
	int mGageRadius;
	// 半径の初期化
	int mRadiusInit;

	//  色
	// 黒色
	int	mBrack;
	// 白色
	int mWhite;

	//  リアクション
	// リアクションが描画される位置にあるフレームの画像
	int mFreamImg;
	// フレームの座標X
	int mFreamX;
	// フレームの座標Y
	int mFreamY;
	// 判定画像
	int mJudgeImg;
	// Perfect判定画像
	int mPerfectImg;
	// Good判定画像
	int mGoodImg;
	// Bad判定画像
	int mBadImg;
	// リアクションの座標X
	int mReactionX;
	// リアクションの座標Y
	int mReactionY;
	// ノーツ最大の大きさ
	int mMaxRadius;
	// パーフェクトの半径
	int mPerfectRadius;
	// バッドの半径
	int mBadRadius;

	// ランダムに格納する値をこれより下回らない
	int mBaseTime;
	// ランダムに格納する値の引数値
	int mBasePoint;
	// ノーツを出す次のタイミング
	int mRandomTime;
	// ランダムな値を格納していいかどうか
	bool mRandomFlag;
	// ノーツを開始させる時間
	int mNotesStartTime;
	// ノーツを終わらせる時間
	int mNotesEndTime;

	//  カウント
	// リアクションを描画する時間をカウントする
	int mReactionCount;
	// リアクションを描画する時間の最大値
	int mReactionCountMax;
	// カウントを初期化
	int mCountInit;
	// ノーツ開始までをはかるカウント
	int mCount;
	// 曲の経過カウント
	int mTimeCount;

	//  CSV
    // CSVファイルを格納
	char mCsv[24] = "data/CSV/TestTiming.csv";
	// ファイルのポインタ
	FILE* mFilePointer;
	// データを格納
	char mCsvData;

	float mNum;
	char mBuffer[10];
	float mCell[1][23];
	int mColumnNum;
	int mRawNum;
	bool mEofFlag;
	float mRhythm[23];

	//  スコア
	// Score処理フラグ
	bool mScoreFlag;
	// スコア
	int mScoreRadius;


	//  エフェクト
	// エフェクト画像
	int mEffectImg;       
	// パーフェクトエフェクト画像
	int mPerfectEffectImg;
	// グッドエフェクト画像
	int mGoodEffectImg;   
	// バッドエフェクト画像
	int mBadEffectImg;    
	// エフェクトの大きさ
	double mEffectScale;  
	// エフェクトのアングル
	double mEffectAngle;  
	// エフェクトがだんだん大きくなる時にプラスする値
	double mScalePlus;    
	// エフェクトが開店する時にプラスする値
	double mAngleRotate;  
	// エフェクトを発生させるフラグ
	bool mEffectFlag;
	// バッドになったか
	bool mBadFlag;


	//  サウンド
	// パーフェクトの時になる効果音
	class Sound* mPerfectSound;
	// グッドの時になる効果音
	class Sound* mGoodSound;
	// バッドの時になる効果音
	class Sound* mBadSound;

	int i = 0;

};

