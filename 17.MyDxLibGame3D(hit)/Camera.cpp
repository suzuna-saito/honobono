//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Camera.h"

// -----------------------------------------------------------
//  @brief 定数
//------------------------------------------------------------
const float CAMERA_NEAR = 0.1f;                                     // カメラの奥行(最小)
const float CAMERA_FAR = 100.0f;                                    // カメラの奥行(最大)
const float FIRST_FAZE = 5.0f;                                      // 一つ目の切り替え時間
const float SECOND_FAZE = 10.0f;                                    // 二つ目の切り替え時間
const float THIRD_FAZE = 15.0f;                                     // 三つ目の切り替え時間
const float END_FAZE = 20.0f;                                       // 最初に戻る時間
const VECTOR ORIGIN_CAMERA_POS = VGet(0.0f, 0.0f, 0.0f);            // 確認用カメラ原点位置
const VECTOR FIRST_CAMERA_POS = VGet(20.0f, 30.0f, -30.0f);         // 一つ目のカメラ
const VECTOR SECOND_CAMERA_POS = VGet(1.0f, 28.0f, -24.0f);         // 二つ目のカメラ
const VECTOR THIRD_CAMERA_POS = VGet(0.0f, 5.0f, 18.0f);            // 三つ目のカメラ
const VECTOR FOURTH_CAMERA_POS = VGet(12.0f, 5.0f, 24.0f);          // 四つ目のカメラ位置

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
	: mNear(CAMERA_NEAR)
	, mFar(CAMERA_FAR)
	, mPos(ORIGIN_CAMERA_POS)
	, mVAngle(0.0f)
	, mHAngle(0.0f)
	, mTAngle(0.0f)
	, mTimeCount(0)
{
	//奥行0.1～1000までをカメラの描画範囲とする（パースを調整してる。NearとFarの値）
	SetCameraNearFar(mNear, mFar);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

/// <summary>
/// カメラセット
/// </summary>
void Camera::CameraSet(Time& _time)
{
	// 一周が終わったらカメラ更新時間をリセット
	if (mTimeCount > END_FAZE)
	{
		mTimeCount = 0;
	}

	// 飛び込むときと飛び込んだ後でフラグと飛び込んだ後のカメラ関数を
	// DivingCameraUpdateのように立てれば、どちらかの関数にしか入らないようにできます
	// if文をなるべく読み込ませないようにしました。
	DivingCameraUpdate(_time);

	// カメラ位置セット
	SetCameraPositionAndAngle(mPos, mVAngle, mHAngle, mTAngle);
}

/// <summary>
/// 飛び込む前のカメラ更新
/// </summary>
/// <param name="_time">Timeクラスのポインタ変数</param>
void Camera::DivingCameraUpdate(Time& _time)
{
	// DeltaTimeを取得
	float DeltaTime = _time.GetDeltaTime();

	// DeltaTimeを更新時間に加算
	mTimeCount += DeltaTime;

	// 時間になったらカメラ位置切り替え
	if (mTimeCount < FIRST_FAZE)
	{
		FirstCameraUpdate();
	}
	else if(FIRST_FAZE < mTimeCount && mTimeCount < SECOND_FAZE)
	{
		SecondCameraUpdate();
	}
	else if (SECOND_FAZE < mTimeCount && mTimeCount < THIRD_FAZE)
	{
		ThirdCameraUpdate();
	}
	else if (THIRD_FAZE < mTimeCount && mTimeCount < END_FAZE)
	{
		FourthCameraUpdate();
	}
}

/// <summary>
/// カメラ位置セット
/// </summary>
void Camera::FirstCameraUpdate()
{
	mPos = FIRST_CAMERA_POS;
	mVAngle = 0.5f;
	mHAngle = -0.8f;
	mTAngle = 0.0f;
}
void Camera::SecondCameraUpdate()
{
	mPos = SECOND_CAMERA_POS;
	mVAngle = 0.5f;
	mHAngle = 0.0f;
	mTAngle = 0.0f;
}
void Camera::ThirdCameraUpdate()
{
	mPos = THIRD_CAMERA_POS;
	mVAngle = 0.0f;
	mHAngle = 3.210f;
	mTAngle = 0.0f;
}
void Camera::FourthCameraUpdate()
{
	mPos = FOURTH_CAMERA_POS;
	mVAngle = 0.0f;
	mHAngle = -2.50f;
	mTAngle = 0.0f;
}

/// <summary>
/// カメラ原点位置セット
/// </summary>
void Camera::SetOriginCameraUpdate()
{
	mPos = ORIGIN_CAMERA_POS;
	mVAngle = 0.0f;
	mHAngle = 0.0f;
	mTAngle = 0.0f;
}

/// <summary>
/// 描画確認用カメラ更新(自分で動かせるカメラを呼び出す)
/// 描画状態を確認したいとき呼出し
/// </summary>
void Camera::TryDrawCameraUpdate()
{
	// 上下左右奥行き移動
	// 上下
	if(CheckHitKey(KEY_INPUT_UP))
	{
		mPos.y += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPos.y -= 0.10f;
	}
	// 左右
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPos.x += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPos.x -= 0.10f;
	}
	// 奥行き
	if (CheckHitKey(KEY_INPUT_Z))
	{
		mPos.z += 0.10f;
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		mPos.z -= 0.10f;
	}

	// 角度変更
	// 垂直方向
	if (CheckHitKey(KEY_INPUT_W))
	{
		mVAngle += 0.01f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		mVAngle -= 0.01f;
	}
	// 水平方向
	if (CheckHitKey(KEY_INPUT_D))
	{
		mHAngle += 0.01f;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		mHAngle -= 0.01f;
	}
	// 捻り回転
	if (CheckHitKey(KEY_INPUT_E))
	{
		mTAngle += 0.01f;
	}
	if (CheckHitKey(KEY_INPUT_Q))
	{
		mTAngle -= 0.01f;
	}

	// カメラ座標を描画
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Pos( %f, %f, %f)\nAngle( %f, %f, %f)"
		, mPos.x
		, mPos.y
		, mPos.z
	    , mVAngle
	    , mHAngle
	    , mTAngle);

	// カメラ位置変更
	SetCameraPositionAndAngle(mPos, mVAngle, mHAngle, mTAngle);
}
