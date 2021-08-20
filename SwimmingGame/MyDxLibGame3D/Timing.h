#pragma once
#include "DxLib.h"

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

	// Perfectのフラグ管理
	bool PerfectFlag;
	// Goodのフラグ管理
	bool GoodFlag;
	// Badのフラグ管理
	bool BadFlag;


	// <summary>
	/// リアクションを取得
	/// </summary>
	/// <returns>現在のリアクションを返す</returns>
//	int GetReaction() { return mIsReaction; }


	/// <summary>
	/// リアクションをセットする
	/// </summary>
	/// <param name="_isScene">現在のリアクション</param>
//	void SetReaction(int _isReaction) { mIsReaction = _isReaction; }

protected:
	// 現在のリアクションを返す
//	int mIsReaction;

private:
	// タイミングのフラグ管理
	bool TimingFlag;
	// 魚（自分が選んでいる操作出来るところを示すもの）
	int selectButtonImg;
	// ボタンの座標X
	int buttonX;
	// ボタンの座標Y
	int buttonY;
	// ボタンが最大動ける範囲(左)
	int buttonMoveLeft;
	// ボタンが最大動ける範囲(右)
	int buttonMoveRight;
	// ボタンの動ける範囲
	int movebutton;

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
	// 判定がパーフェクトになるゲージの色
	int gageColor;
	// 収縮するゲージの色
	int	color;

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

	// リアクションを描画する時間をカウントする
	int count;
	// リアクションを描画する時間の最大値
	int countMax;
	// カウントを初期化
	int countInit;


	// Perfectリアクションの画像
	int perfectImg;
	//Goodリアクションの画像
	int goodImg;
	// Badリアクションの画像
	int badImg;

	// スコア
	int score;
	// スコアを借入れする変数
	int scoreMax;
	// Score処理フラグ
	bool ScoreFlag;
	// スコアを描画する座標X
	int scoreX;
	// スコアを描画する座標Y
	int scoreY;

	class Sound* mPerfectSound;
	class Sound* mGoodSound;
	class Sound* mBadSound;
};

