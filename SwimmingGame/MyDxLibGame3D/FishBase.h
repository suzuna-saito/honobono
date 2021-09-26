#ifndef _FISHBASE_H_
#define _FISHBASE_H_

//前方宣言
#include "DxLib.h"

/// <summary>
/// FishBaseクラス
/// </summary>
class FishBase
{
public:
	FishBase(int _sourceModelHandle);	// コンストラクタ

	virtual ~FishBase();										// デストラクタ

	virtual void Updata(int _judge, float _deltaTime, bool _startflag) = 0;									// 更新関数(純粋仮想関数)

	virtual void Draw(int _debugColor);							// 描画関数

	/*----それぞれのsetter / getter -----*/

	int GetModelHandle() { return mModelHandle; }				//モデルハンドルの取得

	//ポジションのsetter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

	//向きのsetter/getter
	void SetRotate(const VECTOR _setRotate) { mRotate = _setRotate; }
	const VECTOR& GetRotate()const { return mRotate; }

	//移動ベクトルのsetter
	void SetTempAimlessVelocity(const VECTOR _setVelo) { mTempAimlessVelocity = _setVelo; }

	//アーティスティックスイミング開始時の座標のgetter
	const VECTOR& GetDancePos()const { return mSetDancePos; }

	//ダンス集合時のポジションにいるときのフラグのgetter
	const bool GetDancePosFlag() { return mDanceStartFlag; }

	//動いているかどうかのステータス
	enum MoveState
	{
		NowMove,            //今動いている
		NotMove,            //動いていない
	};

	//動いているかどうかのステータスのgetter
	const MoveState GetMoveState()const { return mMoveState; }

protected:

	int		mModelHandle;		// モデルハンドル変数 

	VECTOR	mPos;				// 座標
	VECTOR	mVelocity;			// 実際に移動する移動ベクトル
	VECTOR  mTempVelocity;      // 仮の移動ベクトル
	VECTOR  mTempAimlessVelocity;  //ダンス中の仮の移動ベクトル
	VECTOR	mRotate;			// モデルが向いている角度
	VECTOR	mSetDancePos;		//シンクロ時最も多いポジション

	MoveState mMoveState;     //移動しているかどうかのステータス

	bool mDanceStartFlag;   //アーティスティックスイミングが始められる時はtrue、始まらないときはfalse

	//float mWaveRadius;　　　　　　// ウェーブ処理をするためのラジアン角を入れる変数、未実装 andou
};

#endif // !_FISHBASE_H_