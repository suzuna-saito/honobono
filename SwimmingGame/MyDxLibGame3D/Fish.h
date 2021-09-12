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

	Jump* mJump;             //ジャンプクラスを持った変数
	class Dance* mDance;           //ダンスクラスを持った変数

private:
	bool mJumpUpdataFlag;    // ジャンプの更新をするかどうか
	bool mJumpedInFlag;      // ジャンプの更新が終わったかどうかを判定する変数(終わった：true、終わっていない:false)

	float mDeltaTime;
};

#endif // !_FISH_H_