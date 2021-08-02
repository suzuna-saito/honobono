#include "SceneBase.h"
#include "Camera.h"
#include "UIGoal.h"
#include "Player.h"
#include "Fade.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneBase::SceneBase()
        :mIsScene(title)
	    , mUp(1)
	    , mDown(2)
	    ,mMove(0.0f)
	    ,mSize(1.0f)
	    ,mSizePoint(0.0002f)
	    ,mPointPosition(1)
	    ,mReturn(0)
	    ,mStart(0)
	    ,mEnd(0)
	    ,mFadeFlag(false)
		,mChangeFlag(false)
        ,mShutDownFlag(false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneBase::~SceneBase()
{
}

/// <summary>
/// シーンを変える
/// </summary>
/// <param name="_uiGoal">UIGoalクラスのポインタ</param>
/// <param name="_player">Playerクラスのポインタ</param>
void SceneBase::ChangeScene(UIGoal& _uiGoal, Player& _player)
{
	Camera* camera = new Camera;

	// ゲームスタートを選択でゲーム開始
	if (mIsScene == title && mPointPosition == mUp && CheckHitKey(KEY_INPUT_RETURN))
	{
		mStart = 1;
		// ゲームの状態を設定
		//mIsScene = play;
		mChangeFlag = true;
	}
	// ゴールしたら終了
	if (mIsScene == play)
	{
		// クリア画面へ
		if (_uiGoal.GetGoalFlag() == true)
		{
			mIsScene = gameClear;
		}
		if (_player.GetHp() == 0)
		{
			mIsScene = gameOver;
		}
	}

	// ゲーム終了を選択で終了
	if (mPointPosition == mDown &&
		(mIsScene == title && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		mEnd = 1;
		// ゲーム終了へ
		//mIsScene = gameEnd;
		mChangeFlag = true;

	}

	// タイトルへを選択でタイトルへ
	if (mPointPosition == mUp &&
		(mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		// タイトルへ
		mReturn = 1;
		//mIsScene = title;
		mChangeFlag = true;

	}

}

/// <summary>
/// カーソル位置更新
/// </summary>
void SceneBase::PointUpdate()
{
	// カーソルの位置を変える
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPointPosition = mDown;
		mShutDownFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mPointPosition = mUp;
		mShutDownFlag = false;
	}
}
