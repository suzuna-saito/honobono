#include "SceneBase.h"
#include "Camera.h"
#include "UIGoal.h"
#include "Player.h"
#include "Fade.h"

// コンストラクタ
SceneBase::SceneBase()
        :mIsScene(title)
	    ,Move(0.0f)
	    ,Size(1.0f)
	    ,SizePoint(0.0002f)
	    ,PointPosition(1)
	    ,Return(0)
	    ,Start(0)
	    ,End(0)
	    ,FadeFlag(false)
		,mChangeFlag(false)
        ,mShutDownFlag(false)
{
}

// デストラクタ
SceneBase::~SceneBase()
{
}

// シーン変更
void SceneBase::ChangeScene(UIGoal& uiGoal, Player& player)
{
	Camera* camera = new Camera;

	// ゲームスタートを選択でゲーム開始
	if (mIsScene == title && PointPosition == 1 && CheckHitKey(KEY_INPUT_RETURN))
	{
		Start = 1;
		// ゲームの状態を設定
		//mIsScene = play;
		mChangeFlag = true;
	}
	// ゴールしたら終了
	if (mIsScene == play)
	{
		// クリア画面へ
		if (uiGoal.GetGoalFlag() == true)
		{
			mIsScene = gameClear;
		}
		if (player.GetHp() == 0)
		{
			mIsScene = gameOver;
		}
	}

	// ゲーム終了を選択で終了
	if (PointPosition == 2 &&
		(mIsScene == title && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		End = 1;
		// ゲーム終了へ
		//mIsScene = gameEnd;
		mChangeFlag = true;

	}

	// タイトルへを選択でタイトルへ
	if (PointPosition == 1 &&
		(mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		// タイトルへ
		Return = 1;
		//mIsScene = title;
		mChangeFlag = true;

	}

}

// カーソルの位置更新
void SceneBase::PointUpdate()
{
	// カーソルの位置を変える
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		PointPosition = 2;
		mShutDownFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		PointPosition = 1;
		mShutDownFlag = false;
	}
}
