#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include"Input.h"
#include<math.h>

//--------------------------------------
//aimlessWardering中に上下にウェーブしているときのスピード
const float WAVE_SPEED = 0.0025f;

/// <summary>
/// コンストラクタ
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
	, mJumpUpdataFlag(false)
	, mJumpedInFlag(false)
{
	//FishManagerの引数をFishのメンバ変数に代入
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	//動いてほしいかどうかをenumで判定する
	mMoveState = NotMove;

	////
	//mDanceState = NoStates;//@@@

	//ジャンプのクラスをインスタンス化
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
void Fish::Updata(int _judge, bool _startflag, int _nowScene)
{
	// 今のシーンがトレーニングか、プレイかで更新する処理を変える
	switch (_nowScene)
	{
	case 2: // トレーニングシーン
		TrainingJump(_judge);
		break;

	case 3:  // プレイシーン
		// ジャンプの処理
		JumpUpdata(_judge, _startflag);

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
		break;
	default:
		break;
	}
}

/// <summary>
/// プレイシーンのジャンプの更新を入れた関数 : @saito
/// </summary>
void Fish::JumpUpdata(int _judge, bool _startflag)
{
	// ボタンが押されたら、またはtimingゲージが縮小し終わったらジャンプする（ゲージが表示されてなかったらジャンプしない）
	if (((Key[KEY_INPUT_RIGHT] == 1 || Key[KEY_INPUT_LEFT] == 1) && mJump->GetIsGround() && _judge != 4 )||
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
		mJump->JumpUpdate(_judge,3);

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
/// トレーニングシーンのジャンプ更新
/// </summary>
void Fish::TrainingJump(int _judge)
{
	// ボタンが押されたら、またはtimingゲージが縮小し終わったらジャンプする（ゲージが表示されてなかったらジャンプしない）
	if ((Key[KEY_INPUT_RIGHT] == 1 || Key[KEY_INPUT_LEFT] == 1) && mJump->GetIsGround()&& _judge != 4)
	{
		// ジャンプの更新をするようにする
		mJumpUpdataFlag = true;

		// 初期化
		mJump->TrainingInit();
	}

	// ジャンプの時　（ゲージが表示されていないときは動かない）
	if (mJumpUpdataFlag && _judge != 0)
	{
		// ジャンプの更新
		mJump->JumpUpdate(_judge, 2);

		mPos = VAdd(mPos, mJump->GetVelocity());

		// 5.0よりもポジションが低かったら
		if (mPos.y <= 5.5f)
		{
			mPos.y = 5.5f;

			// 初期化
			mJump->TrainingInit();

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
	//もしダンスがスタートしていたら
	if (mDanceStartFlag)
	{
		//
		mVelocity = mTempAimlessVelocity;
	}
	//スタートしていなければ
	else
	{
		//目的の場所まで移動する関数が返す値をvelocityに入れる
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

		//ダンスを始めるためにフラグをtrueにする
		mDanceStartFlag = true;

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
/// 移動したときに指定した位置に着いたかどうか
/// </summary>
/// <param name="_targetPos">指定した位置</param>
/// <param name="_nowPos">今のモデルの位置</param>
/// <returns>止まっていい時はtrue、止まってはいけない時はfalse</returns>
bool Fish::CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos)
{
	/*-----------モデルを止めるために停止範囲の距離の計算----------*/
	VECTOR posToSetPos = VSub(_targetPos, _nowPos);//fishの今の座標から目標の座標までのベクトルを算出
	float PosSize = VSquareSize(posToSetPos);//posToSetPosを二乗の距離の値にする(ベクトルではなくfloatにする)
	/*
	* VSizeを使うと処理が重くなるため値の処理が重くならないようにVSquareSize()を使用する
	*/

	VECTOR setPosToPos = VSub(_nowPos, _targetPos);//fishの目標の座標から今の座標までのベクトルを算出
	VECTOR normSetPosToPos = VNorm(setPosToPos);//setPosToPosのベクトルを正規化
	VECTOR StopRange = VScale(normSetPosToPos, DANCE_STOP_RANGE);//normSetPosToPosのベクトルの大きさを1から0.25にする

	float mStopRadiusSize = VSquareSize(StopRange);//StopRangeをベクトルから距離にする

	/*
	* mSetPosからmPosまでのベクトルの長さ(値は2乗)が
	* mSetPosからmStopRadiusまでのベクトルの長さ(値は2乗)より
	* 大きい時、移動しなければならないのでtrue
	* 小さい時は移動する必要はないのでfalseを返す
	*/
	if (PosSize >= mStopRadiusSize)
	{
		return false;
	}
	else if (PosSize < mStopRadiusSize)
	{
		return true;
	}
}