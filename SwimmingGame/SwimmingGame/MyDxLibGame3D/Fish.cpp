#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include"Input.h"

/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
	, mJumpUpdataFlag(false)
	, mJumpedInFlag(false)
{
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	mMoveState = NotMove;


	mJump = new Jump();
}

/// <summary>
/// デストラクタ
/// </summary>
Fish::~Fish()
{
	//処理なし
}

/// <summary>
/// 更新関数
/// </summary>
void Fish::Updata(int _judge, float _deltaTime, bool _startflag)
{
	// ジャンプの処理
	JumpUpdata(_judge, _startflag, _deltaTime);

	// 飛び込みが終わったとき
	if (mJumpedInFlag)
	{
		//アーティスティックスイミングの処理
		DanceUpdata();
	}

	//動いてほしい時に
	if (mMoveState == NowMove)
	{
		// ポジションの更新をする
		mPos = VAdd(mPos, mVelocity);

		/*VScale(mPos, _deltaTime);*/
	}
}

/// <summary>
/// ジャンプの更新を入れた関数 : @saito
/// </summary>
void Fish::JumpUpdata(int _judge, bool _startflag, float _deltaTime)
{
	// ボタンが押されたら、またはtimingゲージが縮小し終わったらジャンプする（ゲージが表示されてなかったらジャンプしない）
	if ((Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround()) && _judge != 4 ||
		_judge == 3)
	{
		// ジャンプの更新をするようにする
		mJumpUpdataFlag = true;

		mMoveState = NowMove;
	}

	// 飛び込みの時
	if (mJumpUpdataFlag && mJump->GetNowJump() != mJump->endDive)
	{
		//ジャンプの更新
		mJump->DiveUpdate(mRotate);

		// 今のジャンプが飛び込みじゃない、かつ、増加量が0になったら
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();
			// ジャンプの更新を止める
			mJumpUpdataFlag = false;
		}
		// 今のジャンプが飛び込みで、プールのところまでいったら
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 2.0f)
		{
			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();

			// 押し戻し…？
			mPos.y = 2.0f;

			// ジャンプの更新を止める
			mJumpUpdataFlag = false;

			//ジャンプの更新処理が終わったことを示すためtrueにする
			mJumpedInFlag = true;
		}
	}

	// ジャンプの時　（ゲージが表示されていない　または　演技するポジションに行ってなかったら動かない）
	else if (mJumpUpdataFlag && mJump->GetNowJump() == mJump->endDive && _judge != 0 && _startflag)
	{
		// ジャンプの更新
		mJump->JumpUpdate(_judge);

		mPos = VAdd(mPos, mJump->GetVelocity());

		// 5.0よりもポジションが低かったら
		if (mPos.y <= 5.5f)
		{
			mPos.y = 5.5f;

			// ジャンプパターンを更新する
			mJump->JumpSetUpdate();

			// ジャンプの更新を止める
			mJumpUpdataFlag = false;
		}
	}

	mPos = VAdd(mPos, mJump->GetVelocity());
}

/// <summary>
/// アーティスティックスイミングの更新処理を入れた関数
/// </summary>
void Fish::DanceUpdata()
{
	if (mSetDanceFlag)
	{
		mVelocity = MoveAimlessWandering(mPos);
	}
	else
	{
		mVelocity = MoveTargetPos(mSetDancePos, mPos, mRotate);
	}
}


//andou
/// <summary>
///  目標の座標まで移動する関数
/// </summary>
/// <param name="_mSetPos">ダンス集合時のポジション</param>
/// <param name="_mNowPos">モデルの現在のポジション</param>
/// <param name="_Rotate">魚が向いている方向のベクトル</param>
/// <returns>動いているときはfalse、動いていないときはtrueを返す</returns>
VECTOR Fish::MoveTargetPos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate)
{
	//移動ベクトルの計算
	VECTOR posToSetPos = VSub(_SetPos, _NowPos);
	VECTOR normPosToSetPos = VNorm(posToSetPos);
	mTempVelocity = VScale(normPosToSetPos, DANCE_VELOCITY);


	//止まるとき
	if (CheckStopped(_SetPos, _NowPos))
	{
		//動いてほしくないのでNotMoveにする
		mMoveState = NotMove;
		//ダンスを始めるために
		mDanceStartCount++;
		//ダンスカウントが100以上の時
		if (mDanceStartCount >= WAIT_DANCE_TIME_COUNT)
		{
			//ダンスを始められるのでtrueにする
			mSetDanceFlag = true;
		}

		return mTempVelocity;
	}
	else
	{
		//動いてほしいのでNowMoveにする
		mMoveState = NowMove;
		//この関数の上で計算したvelocityを返す
		return mTempVelocity;
	}
}

/// <summary>
/// ジャンプをしていないときの処理(反射処理)
/// </summary>
/// <param name="_nowPos">今のポジション</param>
/// <returns>移動ベクトルを返す</returns>
VECTOR Fish::MoveAimlessWandering(VECTOR& _nowPos)
{
	//動いてほしいのでNowMoveにする
	mMoveState = NowMove;
	//前にmTempVelocityを使っていた場合、Y軸を使用していると浮いてしまうので
	//一度Y軸を０にする
	mTempVelocity = VGet(mTempVelocity.x, 0.f, mTempVelocity.z);

	/*
	* プールの端に設定するとモデルが埋まってしまうので
	* ポジションではなくポジション＋デバックの球体の半径を判定とする
	*/
	//上下の判定
	if (_nowPos.x >= LINE_X - DEBUG_RADIUS
		|| _nowPos.x <= -LINE_X + DEBUG_RADIUS)
	{
		mTempVelocity.x = -mTempVelocity.x;
	}
	//左右の判定
	if (_nowPos.z >= LINE_Z - DEBUG_RADIUS
		|| _nowPos.z <= -LINE_Z + DEBUG_RADIUS)
	{
		mTempVelocity.z = -mTempVelocity.z;
	}

	return mTempVelocity;
}


/// <summary>
/// 移動したときに指定した位置に着いたかどうか
/// </summary>
/// <param name="_targetPos">指定した位置</param>
/// <param name="_nowPos">今のモデルの位置</param>
/// <returns>止まっていい時はtrue、止まってはいけない時はfalse</returns>
bool Fish::CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos)
{

	/*-----------モデルを止めるために停止範囲の距離の計算----------*/

	VECTOR posToSetPos = VSub(_targetPos, _nowPos);
	VECTOR normPosToSetPos = VNorm(posToSetPos);

	//mPosからmSetDancePosまでの距離の計算
	float PosSize = VSquareSize(posToSetPos);

	VECTOR StopRange = VScale(normPosToSetPos, DANCE_STOP_RANGE);

	//mSetDancePosからmStoprangeまでの距離の計算
	VECTOR normSetPosToPos = VNorm(VSub(_nowPos, _targetPos));
	StopRange = VScale(normSetPosToPos, DANCE_STOP_RANGE);

	float mStopRadiusSize = VSquareSize(StopRange);

	//mSetPosからmPosまでのベクトルの長さ(値は2乗)が
	//mSetPosからmStopRadiusまでのベクトルの長さ(値は2乗)より
	//大きい時に移動させる
	if (PosSize > mStopRadiusSize)
	{
		return false;
	}
	else if (PosSize <= mStopRadiusSize)
	{
		return true;
	}
}