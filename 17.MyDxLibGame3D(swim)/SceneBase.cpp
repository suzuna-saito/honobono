#include "SceneBase.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

// コンストラクタ
SceneBase::SceneBase()
        :mIsScene(title)
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

// デストラクタ
SceneBase::~SceneBase()
{
}

// シーン変更
void SceneBase::ChangeScene()
{
}

// カーソルの位置更新
void SceneBase::PointUpdate()
{
}