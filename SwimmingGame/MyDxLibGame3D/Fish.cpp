#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include"Input.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
	, mJumpUpdataFlag(false)
	, mJumpedInFlag(false)
{
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	mMoveState = NotMove;

	mJump = new Jump();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Fish::~Fish()
{
	//�����Ȃ�
}

/// <summary>
/// �X�V�֐�
/// </summary>
void Fish::Updata()
{
	//�����Ă���Ƃ���
	if (mMoveState == NowMove)
	{
		// �|�W�V�����̍X�V������
		mPos = VAdd(mPos, mVelocity);
	}

	if (!mJumpedInFlag)
	{
		//��э��݂̏���
		JumpUpdata();
	}
	else
	{
		//�A�[�e�B�X�e�B�b�N�X�C�~���O�̏���
		DanceUpdata();
	}
}

/// <summary>
/// �W�����v�̍X�V����ꂽ�֐� : @saito
/// </summary>
void Fish::JumpUpdata()
{
	// �S�ẴW�����v���I����Ă��Ȃ���Ԃ�
	// �{�^���������ꂽ��A�܂���timing�Q�[�W���k�����I�������W�����v����i���Ă������j
	if (mJump->GetNowJump() != mJump->endJump &&
		(Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround())/*||
		(mTiming->GetRadius() <= 1 && mJump->GetIsGround())*/)
	{
		// �W�����v�̍X�V������悤�ɂ���
		mJumpUpdataFlag = true;
	}

	if (mJumpUpdataFlag)
	{
		//�W�����v�̍X�V
		mJump->JumpUpdate(mRotate);

		// ���̃W�����v����э��݂���Ȃ��A���A�����ʂ�0�ɂȂ�����
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();
			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;
		}
		// ���̃W�����v����э��݂ŁA�v�[���̂Ƃ���܂ł�������
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 0.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();

			// �����߂��c�H
			mPos.y = 0.0f;

			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;

			//�W�����v�̍X�V�������I��������Ƃ���������true�ɂ���
			mJumpedInFlag = true;
		}
	}

	mMoveState = NowMove;
	mVelocity = mJump->GetVelocity();
}


/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O���̍X�V��������ꂽ�֐�
/// </summary>
void Fish::DanceUpdata()
{
	mVelocity = MoveTargetPos(mSetDancePos, mPos, mRotate);
}


//andou
/// <summary>
///  �ڕW�̍��W�܂ňړ�����֐�
/// </summary>
/// <param name="_mSetPos">�_���X�W�����̃|�W�V����</param>
/// <param name="_mNowPos">���f���̌��݂̃|�W�V����</param>
/// <param name="_Rotate">���������Ă�������̃x�N�g��</param>
/// <returns>�����Ă���Ƃ���false�A�����Ă��Ȃ��Ƃ���true��Ԃ�</returns>
VECTOR Fish::MoveTargetPos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate)
{
	//�ړ��x�N�g���̌v�Z
	VECTOR posToSetPos = VSub(_SetPos, _NowPos);
	VECTOR normPosToSetPos = VNorm(posToSetPos);
	mVelocity = VScale(normPosToSetPos, SET_DANCE_POS_VELOCITY);

	//�~�܂�Ƃ�
	if (CheckStopped(_SetPos, _NowPos))
	{
		mMoveState = NotMove;
		return mVelocity;
	}
	else
	{
		mMoveState = NowMove;
		return mVelocity;
	}
}


/// <summary>
/// �ړ������Ƃ��Ɏw��̈ʒu�ɒ��������ǂ���
/// </summary>
/// <param name="_targetPos">�w�肵���ʒu</param>
/// <param name="_nowPos">���̃��f���̈ʒu</param>
/// <returns>�~�܂��Ă�������true�A�~�܂��Ă͂����Ȃ�����false</returns>
bool Fish::CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos)
{
	VECTOR posToSetPos = VSub(_targetPos, _nowPos);
	VECTOR normPosToSetPos = VNorm(posToSetPos);

	/*-----------���f�����~�߂邽�߂ɒ�~�͈͂̋����̌v�Z----------*/

	//mPos����mSetDancePos�܂ł̋����̌v�Z
	float PosSize = VSquareSize(posToSetPos);

	VECTOR StopRange = VScale(normPosToSetPos, SET_DANCE_POS_RANGE);

	//mSetDancePos����mStoprange�܂ł̋����̌v�Z
	VECTOR normSetPosToPos = VNorm(VSub(_nowPos, _targetPos));
	StopRange = VScale(normSetPosToPos, SET_DANCE_POS_RANGE);

	float mStopRadiusSize = VSquareSize(StopRange);

	//mSetPos����mPos�܂ł̃x�N�g���̒���(�l��2��)��
	//mSetPos����mStopRadius�܂ł̃x�N�g���̒���(�l��2��)���
	//�傫�����Ɉړ�������
	if (PosSize > mStopRadiusSize)
	{
		return false;
	}
	else if (PosSize <= mStopRadiusSize)
	{
		return true;
	}
}