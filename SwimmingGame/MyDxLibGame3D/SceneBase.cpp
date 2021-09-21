#include "SceneBase.h"
#include "Score.h"

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
SceneBase::~SceneBase()
{
	delete(mScore);
}

// �X�V����
/// <return>���݂̃V�[���̃|�C���^</return>
SceneBase* SceneBase::Update()
{
	return nullptr;
}

// �`��
void SceneBase::Draw()
{
}

/// <summary>
/// �J�[�\���ʒu�X�V
/// </summary>
void SceneBase::PointUpdate()
{
	// �J�[�\���̈ʒu��ς���
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
