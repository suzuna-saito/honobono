#include "SceneBase.h"
#include "Score.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneBase::SceneBase()
	: mUp(1)
	, mDown(2)
	, mFontSize(36)
	, mCount(0)
	, mColorAlpha(5)
	, mMove(0.0f)
	, mSize(1.0f)
	, mSizePoint(0.0002f)
	, mPointPosition(1)
	, mReturn(0)
	, mStart(0)
	, mEnd(0)
	//, mFadeFlag(false)
	//, mChangeFlag(false)
	, mShutDownFlag(false)
	, mScore(new Score())
{
	mPointGraph = LoadGraph("data/Asset/mejirushi.png");
}

/// <summary>
/// デストラクタ
/// </summary>
SceneBase::~SceneBase()
{
	delete(mScore);
}

// 更新処理
/// <return>現在のシーンのポインタ</return>
SceneBase* SceneBase::Update()
{
	return nullptr;
}

// 描画
void SceneBase::Draw()
{
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
