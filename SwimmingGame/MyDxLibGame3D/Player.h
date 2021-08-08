//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "DxLib.h"


/// <summary>
/// プレイヤークラス
/// </summary>
class Player
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新関数
	void Draw();			// 描画関数

	// モデルハンドルのgetter
	int GetModelHandle(){ return mModelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return mPos; }
	void SetPos(const VECTOR _set) { mPos = _set; }

	// ポジションY軸のみのgetter
	float GetPosY() { return mPosY; }

	// ディレクションのgetter/setter.
	const VECTOR& GetDir() const { return mDir; }
	void SetDir(const VECTOR _set) { mDir = _set; }

	// あたり判定半径の取得.
	float GetHitRadius() { return mHitRadius; }

	// その時のそれぞれの変数の値を返す、それぞれのgetter
	int GetHp() { return mHP; }
	float GetSizePoint() { return mSizePoint; }
	bool GetMoveFlag() { return mMoveFlag; }
	int GetFadeCount() { return mFadeCount; }

	// それぞれの変数に代入する、それぞれのsetter
	void SetHp(int _hp) { mHP = _hp; }
	void SetSizePoint(float _SP) { mSizePoint = _SP; }
	void SetDrawFlag(bool _DF) { mDrawFlag = _DF; }

private:
	int		mModelHandle;	         // モデルハンドル.
	int     mHPImg[3];                // HPの画像ハンドル配列
	int     mRightVectorGraph[2];     // 右矢印画像ハンドル
	int     mLeftVectorGraph[2];      // 左矢印画像ハンドル

	VECTOR	mPos;			// ポジション.

	VECTOR	mVelocity;		// 移動力.

	VECTOR	mDir;			// 回転方向.
	
	float	mHitRadius;		// あたり判定の半径.

	float mPosY;             // Y座標
	int  mHP;                // 残機
	bool mHitFlag;
	bool mMoveFlag;          // プレイヤーが動いたかを管理
	float mHPSize;           // Hp画像の大きさ
	float mSizePoint;        // Hp画像の大きさを変える値
	bool mDrawFlag;          // 描画するか
	int mRMoveFlag;          // 右矢印を光らせるか
	int mLMoveFlag;          // 左矢印を光らせるか

	int mFadeCount;

};

#endif // _PLAYER_H_