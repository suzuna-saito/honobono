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

	Score* GetScore() { return mScorePtr; }

	/// <summary>
	/// CSVデータの読み込み
	/// </summary>
	void CSVRead();

	void fps();

protected:
	

private:
	//  フラグ
	// タイミングゲージのクリック出来るかのフラグ管理
	bool TimingFlag;
	
	// Perfectのフラグ管理
	bool PerfectFlag;
	// Goodのフラグ管理
	bool GoodFlag;
	// Badのフラグ管理
	bool BadFlag;

	//  ゲージ
	// ゲージの座標X
	int gageX;
	// ゲージの座標Y
	int gageY;
	// ゲージの中心座標X
	int gageCX;
	// ゲージの中心座標Y
	int gageCY;
	// 収縮するゲージの半径
	int radius;
	// 判定がパーフェクトになるゲージの半径
	int gageRadius;
	// 半径の初期化
	int radiusInit;

	//  色
	// 黒色
	int	brack;
	// 白色
	int white;

	//  リアクション
	// リアクションが描画される位置にあるフレームの画像
	int freamImg;
	// フレームの座標X
	int freamX;
	// フレームの座標Y
	int freamY;
	// リアクションの座標X
	int reactionX;
	// リアクションの座標Y
	int reactionY;
	// パーフェクトリアクションの画像
	int perfectImg;
	// パーフェクトの半径
	int perfectRadius;
	// グッドリアクションの画像
	int goodImg;
	// バッドリアクションの画像
	int badImg;
	// バッドの半径
	int badRadius;


	//  カウント
	// リアクションを描画する時間をカウントする
	int reactionCount;
	// リアクションを描画する時間の最大値
	int reactionCountMax;
	// カウントを初期化
	int countInit;
	int count = 0;

	//  スコア
	// Score処理フラグ
	bool ScoreFlag;
	// 
	class Score* mScorePtr;


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


	//  CSV
	// CSVファイルを格納
	char csv[24] = "data/CSV/TestTiming.csv";
	// ファイルのポインタ
	FILE* filePointer;
	// データを格納
	int csvData;


	//  サウンド
	// パーフェクトの時になる効果音
	class Sound* mPerfectSound;
	// グッドの時になる効果音
	class Sound* mGoodSound;
	// バッドの時になる効果音
	class Sound* mBadSound;
};

