#pragma once
#include"DxLib.h"

/// <summary>
/// アーティスティックスイミングクラス
/// </summary>
class Dance
{
public:
	Dance(const VECTOR _SetPos);                         //コンストラクタ
	~Dance();                        //デストラクタ

	void Updata();                   //更新関数

	/// <summary>
	/// ダンス集合時のポジション
	/// </summary>
	VECTOR SetDancePos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate);

	//---------それぞれのgetter--------------	
	//移動量を表すベクトルを返す
	VECTOR GetVelocity() { return mVelocity; }

	//回転ベクトルを返す
	VECTOR GetRotate() { return mRotate; }

	//ダンス集合時にモデルが止まっているかどうかのフラグのgetter
	const bool GetStopSetPosFlag() { return mStopFlag; }

private:
	VECTOR mVelocity;                   //移動量を表すベクトル
	VECTOR mRotate;                     //モデルの回転

	VECTOR mSetDancePos;                //元の隊列に戻る為のポジションベクトル

	VECTOR mStopRange;                  //モデルが止まる範囲

	//Danceを持っているその魚が止まっているときはtrue、動いているときはfalse
	bool mStopFlag;
};