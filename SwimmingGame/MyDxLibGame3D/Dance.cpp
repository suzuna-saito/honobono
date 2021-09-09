#include "Dance.h"

//-------------------------------------------------
// �萔
//--------------------------------------------------
const float SET_DANCE_POS_VELOCITY = 0.5f;    //�_���X�W�����̈ړ���
const float SET_DANCE_POS_RANGE = 0.25f;      //�_���X�W�����̒�~�͈�
const VECTOR ZERO_VECTOR = VGet(0.0f, 0.0f, 0.0f);   //XYZ��0�������Ă���萔

/// <summary>
/// �R���X�g���N�^
/// </summary>
Dance::Dance(const VECTOR _setPos)
	: mRotate(ZERO_VECTOR)
	, mVelocity(ZERO_VECTOR)
	, mStopRange(ZERO_VECTOR)
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
bool Dance::SetDancePos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate)
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
		_NowPos = VAdd(_NowPos, mVelocity);
		return false;
	}
	else if (mPosSize < mStopRadiusSize)
	{
		return true;
	}
}
