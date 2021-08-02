#include "SceneBase.h"
#include "Camera.h"
#include "UIGoal.h"
#include "Player.h"
#include "Fade.h"

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
SceneBase::~SceneBase()
{
}

/// <summary>
/// �V�[����ς���
/// </summary>
/// <param name="_uiGoal">UIGoal�N���X�̃|�C���^</param>
/// <param name="_player">Player�N���X�̃|�C���^</param>
void SceneBase::ChangeScene(UIGoal& _uiGoal, Player& _player)
{
	Camera* camera = new Camera;

	// �Q�[���X�^�[�g��I���ŃQ�[���J�n
	if (mIsScene == title && mPointPosition == mUp && CheckHitKey(KEY_INPUT_RETURN))
	{
		mStart = 1;
		// �Q�[���̏�Ԃ�ݒ�
		//mIsScene = play;
		mChangeFlag = true;
	}
	// �S�[��������I��
	if (mIsScene == play)
	{
		// �N���A��ʂ�
		if (_uiGoal.GetGoalFlag() == true)
		{
			mIsScene = gameClear;
		}
		if (_player.GetHp() == 0)
		{
			mIsScene = gameOver;
		}
	}

	// �Q�[���I����I���ŏI��
	if (mPointPosition == mDown &&
		(mIsScene == title && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		mEnd = 1;
		// �Q�[���I����
		//mIsScene = gameEnd;
		mChangeFlag = true;

	}

	// �^�C�g���ւ�I���Ń^�C�g����
	if (mPointPosition == mUp &&
		(mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		// �^�C�g����
		mReturn = 1;
		//mIsScene = title;
		mChangeFlag = true;

	}

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
