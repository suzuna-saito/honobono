#include "Dance.h"

//-------------------------------------------------
// 定数
//--------------------------------------------------
const float SET_DANCE_POS_VELOCITY = 0.5f;    //ダンス集合時の移動量
const float SET_DANCE_POS_RANGE = 0.25f;      //ダンス集合時の停止範囲
const VECTOR ZERO_VECTOR = VGet(0.0f, 0.0f, 0.0f);   //XYZに0が入っている定数

/// <summary>
/// コンストラクタ
/// </summary>
Dance::Dance(const VECTOR _setPos)
	: mRotate(ZERO_VECTOR)
	, mVelocity(ZERO_VECTOR)
	, mStopRange(ZERO_VECTOR)
{
	mSetDancePos = _setPos;
}

/// <summary>
/// デストラクタ
/// </summary>
Dance::~Dance()
{
}

//更新関数
void Dance::Updata()
{
}

/// <summary>
///  ダンス集合時のポジションに移動する関数
/// </summary>
/// <param name="_mSetPos">ダンス集合時のポジション</param>
/// <param name="_mNowPos">モデルの現在のポジション</param>
bool Dance::SetDancePos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate)
{
	//移動ベクトルの計算
	VECTOR posToSetPos = VSub(_SetPos, _NowPos);
	VECTOR normPosToSetPos = VNorm(posToSetPos);
	mVelocity = VScale(normPosToSetPos, SET_DANCE_POS_VELOCITY);

	/*-----------モデルを止めるために停止範囲の距離の計算----------*/

	//mPosからmSetDancePosまでの距離の計算
	float mPosSize = VSquareSize(posToSetPos);
	mStopRange = VScale(normPosToSetPos, SET_DANCE_POS_RANGE);

	//mSetDancePosからmStoprangeまでの距離の計算
	VECTOR normSetPosToPos = VNorm(VSub(_NowPos, _SetPos));
	mStopRange = VScale(normSetPosToPos, SET_DANCE_POS_RANGE);

	float mStopRadiusSize = VSquareSize(mStopRange);

	//mSetPosからmPosまでのベクトルの長さ(値は2乗)が
	//mSetPosからmStopRadiusまでのベクトルの長さ(値は2乗)より
	//大きい時に移動させる
	if (mPosSize > mStopRadiusSize)
	{
		_NowPos = VAdd(_NowPos, mVelocity);
		return false;
	}
	else if (mPosSize < mStopRadiusSize)
	{
		return true;
	}
}
