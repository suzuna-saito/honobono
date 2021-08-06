#include "SceneBase.h"
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

// �R���X�g���N�^
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

// �f�X�g���N�^
SceneBase::~SceneBase()
{
}

// �V�[���ύX
void SceneBase::ChangeScene()
{
}

// �J�[�\���̈ʒu�X�V
void SceneBase::PointUpdate()
{
}