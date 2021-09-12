#ifndef _FISH_H_
#define _FISH_H_

#include "DxLib.h"
#include"FishBase.h"

class Jump;

/// <summary>
/// 魚一匹分のクラス
/// </summary>
class Fish :public FishBase
{
public:
	Fish(int _sourceModelHandle,
		VECTOR _pos, VECTOR _rotate, VECTOR _dancePos);		// コンストラクタ
	virtual ~Fish();										// デストラクタ

	void Updata();											// 更新関数

	//ジャンプの更新処理をいれた関数
	void JumpUpdata();

	//アーティスティックスイミングの更新処理をいれた関数
	void DanceUpdata();

	/// <summary>
	/// 目標の座標まで動く関数
	/// </summary>
	VECTOR MoveTargetPos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate);

	/// <summary>
	/// 止まっているときにtrue、止まっていないときにはfalseを返す
	/// </summary>
	bool CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos);

	Jump* mJump;             //ジャンプクラスを持った変数

private:

	bool mJumpUpdataFlag;    // ジャンプの更新をするかどうか
	bool mJumpedInFlag;      // ジャンプの更新が終わったかどうかを判定する変数(終わった：true、終わっていない:false)

	float mDeltaTime;
};

#endif // !_FISH_H_