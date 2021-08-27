#ifndef _FISH_H_
#define _FISH_H_

#include "DxLib.h"
#include"FishBase.h"

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

	//アーティスティックスイミング開始時のセットポジション
	void SetDancePos(const VECTOR _setPos);

private:
};

#endif // !_FISH_H_