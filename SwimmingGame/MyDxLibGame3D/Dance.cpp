#include "Dance.h"
#include"Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Dance::Dance(const VECTOR _setPos)
	: mRotate(ZERO_VECTOR)
	, mVelocity(ZERO_VECTOR)
	, mStopRange(ZERO_VECTOR)
	, mStopFlag(false)
{
	mSetDancePos = _setPos;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Dance::~Dance()
{
}

//�X�V�֐�
void Dance::Updata()
{
}

/// <summary>
///  �_���X�W�����̃|�W�V�����Ɉړ�����֐�
/// </summary>
/// <param name="_mSetPos">�_���X�W�����̃|�W�V����</param>
/// <param name="_mNowPos">���f���̌��݂̃|�W�V����</param>
/// <param name="_Rotate">���������Ă�������̃x�N�g��</param>
/// <returns>�����Ă���Ƃ���false�A�����Ă��Ȃ��Ƃ���true��Ԃ�</returns>
VECTOR Dance::MoveTargetPos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate)
{
	//�ړ��x�N�g���̌v�Z
	VECTOR posToSetPos = VSub(_SetPos, _NowPos);
	VECTOR normPosToSetPos = VNorm(posToSetPos);
	mVelocity = VScale(normPosToSetPos, SET_DANCE_POS_VELOCITY);

	/*-----------���f�����~�߂邽�߂ɒ�~�͈͂̋����̌v�Z----------*/

	//mPos����mSetDancePos�܂ł̋����̌v�Z
	float mPosSize = VSquareSize(posToSetPos);
	mStopRange = VScale(normPosToSetPos, SET_DANCE_POS_RANGE);

	//mSetDancePos����mStoprange�܂ł̋����̌v�Z
	VECTOR normSetPosToPos = VNorm(VSub(_NowPos, _SetPos));
	mStopRange = VScale(normSetPosToPos, SET_DANCE_POS_RANGE);

	float mStopRadiusSize = VSquareSize(mStopRange);

	//mSetPos����mPos�܂ł̃x�N�g���̒���(�l��2��)��
	//mSetPos����mStopRadius�܂ł̃x�N�g���̒���(�l��2��)���
	//�傫�����Ɉړ�������
	if (mPosSize > mStopRadiusSize)
	{
		mStopFlag = false;
		return mVelocity;
	}
	else if (mPosSize <= mStopRadiusSize)
	{
		mStopFlag = true;
		return mVelocity;
	}
}
