//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"


// クラスの参照
class ObstructBase;
class SceneBase;
class HitChecker;

/// <summary>
/// プレイヤーの更新、描画
/// </summary>
class Player final
{
public:
	Player();               // コンストラクタ.
	~Player();              // デストラクタ.

	void Update();          // 更新.
	void Draw();            // 描画.

private:
	int	mModelHandle;	         // モデルハンドル.
	int mHpImg[3];               // HPの画像読み込み
	int mRightVectorGraph[2];    // 右矢印画像
	int mLeftVectorGraph[2];     // 左矢印画像

	VECTOR  mPos;			// ポジション.
	VECTOR  mVelocity;		// 移動力.
	VECTOR  mDir;			// 回転方向.
	
	const float mHitRadius;	 // あたり判定の半径.
	float mPosY;             // プレイヤーY座標
	int  mHp;                // 残機
	float mHpSize;           // Hp画像の大きさ
	float mSizePoint;        // Hp画像の大きさを変える値
	bool mMoveFlag;          // プレイヤーが動いたか
	bool mDrawFlag;          // 描画するか
	bool mRMoveFlag;         // 右矢印を光らせるか
	bool mLMoveFlag;         // 左矢印を光らせるか
	

public: // ゲッター、セッター
	// ポジションのgetter
	// <return>今のプレイヤーのポジションを返す</return>
	const VECTOR& GetPos() const { return mPos; }
	// Y座標のポジションのgetter
	// <return>今のプレイヤーのY座標のポジションを返す</return>
	float GetPosY() { return mPosY; }
	// あたり判定半径のgetter.
	// <return>プレイヤーの当たり判定の半径を返す</return>
	float GetHitRadius() { return mHitRadius; }
	// HPのgetter.
	// <return>プレイヤーの残機を返す</return>
	int GetHp() { return mHp; }
	// HP画像の大きさのgetter.
	// <return>HP画像の大きさを変える値を返す</return>
	float GetSizePoint() { return mSizePoint; }
	// プレイヤーが移動しているかのフラグのgetter.
	// <return>プレイヤーが動いていたらtrue,動いていなかったらfalseを返す</return>
	bool GetMoveFlag() { return mMoveFlag; }


	// HPのsetter.
	/// <param name="hp">プレイヤーの残機を渡す</param>
	void SetHp(int hp) { mHp = hp; }
	// HP画像の大きさのsetter.
	/// <param name="sp">HP画像の大きさを渡す</param>
	void SetSizePoint(float sp) { mSizePoint = sp; }
	// プレイヤー描画フラグのsetter.
	/// <param name="df">プレイヤーが描画されている = true,プレイヤーが描画されていない = false</param>
	void SetDrawFlag(bool df) { mDrawFlag = df; }
};

#endif // _PLAYER_H_