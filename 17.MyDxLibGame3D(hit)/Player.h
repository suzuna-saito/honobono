//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class ObstructBase;
class SceneBase;
class HitChecker;

class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle(){ return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	float GetPosY() { return PosY; }

	// ディレクションのgetter/setter.
	const VECTOR& GetDir() const { return dir; }
	void SetDir(const VECTOR set) { dir = set; }

	// あたり判定半径の取得.
	float GetHitRadius() { return hitRadius; }

	// 値を渡す
	int GetHp() { return Hp; }
	float GetSizePoint() { return SizePoint; }
	bool GetMoveFlag() { return MoveFlag; }
	int GetFadeCount() { return FadeCount; }

	// 値を受け取る
	void SetHp(int hp) { Hp = hp; }
	void SetSizePoint(float SP) { SizePoint = SP; }
	void SetDrawFlag(bool DF) { DrawFlag = DF; }

private:
	int		modelHandle;	         // モデルハンドル.
	int     HpImg[3];                // HPの画像読み込み
	int     RightVectorGraph[2];     // 右矢印画像
	int     LeftVectorGraph[2];      // 左矢印画像

	VECTOR	pos;			// ポジション.

	VECTOR	velocity;		// 移動力.

	VECTOR	dir;			// 回転方向.
	
	float	hitRadius;		// あたり判定の半径.

	float PosY;             // Y座標
	int  Hp;                // 残機
	bool HitFlag;
	bool MoveFlag;          // プレイヤーが動いたかを管理
	float HpSize;           // Hp画像の大きさ
	float SizePoint;        // Hp画像の大きさを変える値
	bool DrawFlag;          // 描画するか
	int RMoveFlag;          // 右矢印を光らせるか
	int LMoveFlag;          // 左矢印を光らせるか

	int FadeCount;

	// 静的定数.
	static const float COLIDE_DECEL_FAC;
};

#endif // _PLAYER_H_