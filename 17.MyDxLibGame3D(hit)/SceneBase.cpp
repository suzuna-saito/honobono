#include "SceneBase.h"
#include "Camera.h"
#include "UIGoal.h"
#include "Player.h"
#include "Fade.h"

// �R���X�g���N�^
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

// �f�X�g���N�^
SceneBase::~SceneBase()
{
}

// �V�[���ύX
void SceneBase::ChangeScene(UIGoal& uiGoal, Player& player)
{
	Camera* camera = new Camera;

	// �Q�[���X�^�[�g��I���ŃQ�[���J�n
	if (mIsScene == title && PointPosition == 1 && CheckHitKey(KEY_INPUT_RETURN))
	{
		Start = 1;
		// �Q�[���̏�Ԃ�ݒ�
		//mIsScene = play;
		mChangeFlag = true;
	}
	// �S�[��������I��
	if (mIsScene == play)
	{
		// �N���A��ʂ�
		if (uiGoal.GetGoalFlag() == true)
		{
			mIsScene = gameClear;
		}
		if (player.GetHp() == 0)
		{
			mIsScene = gameOver;
		}
	}

	// �Q�[���I����I���ŏI��
	if (PointPosition == 2 &&
		(mIsScene == title && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		End = 1;
		// �Q�[���I����
		//mIsScene = gameEnd;
		mChangeFlag = true;

	}

	// �^�C�g���ւ�I���Ń^�C�g����
	if (PointPosition == 1 &&
		(mIsScene == gameOver && CheckHitKey(KEY_INPUT_RETURN) ||
		mIsScene == gameClear && CheckHitKey(KEY_INPUT_RETURN)))
	{
		// �^�C�g����
		Return = 1;
		//mIsScene = title;
		mChangeFlag = true;

	}

}

// �J�[�\���̈ʒu�X�V
void SceneBase::PointUpdate()
{
	// �J�[�\���̈ʒu��ς���
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
