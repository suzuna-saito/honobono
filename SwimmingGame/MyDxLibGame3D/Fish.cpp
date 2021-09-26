#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include"Input.h"
#include<math.h>

//--------------------------------------
//aimlessWardering���ɏ㉺�ɃE�F�[�u���Ă���Ƃ��̃X�s�[�h
const float WAVE_SPEED = 0.0025f;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
	, mJumpUpdataFlag(false)
	, mJumpedInFlag(false)
{
	//FishManager�̈�����Fish�̃����o�ϐ��ɑ��
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	//�����Ăق������ǂ�����enum�Ŕ��肷��
	mMoveState = NotMove;

	////
	//mDanceState = NoStates;//@@@

	//�W�����v�̃N���X���C���X�^���X��
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
void Fish::Updata(int _judge, float _deltaTime, bool _startflag)
{
	// �W�����v�̏���
	JumpUpdata(_judge, _startflag, _deltaTime);

	// ��э��݂��I������Ƃ�
	if (mJumpedInFlag)
	{
		//�A�[�e�B�X�e�B�b�N�X�C�~���O�̏���
		DanceUpdata();
	}

	//�����Ăق�������
	if (mMoveState == NowMove)
	{
		// �|�W�V�����̍X�V������
		mPos = VAdd(mPos, mVelocity);

		/*VScale(mPos, _deltaTime);*/
	}
}

/// <summary>
/// �W�����v�̍X�V����ꂽ�֐� : @saito
/// </summary>
void Fish::JumpUpdata(int _judge, bool _startflag, float _deltaTime)
{
	// �{�^���������ꂽ��A�܂���timing�Q�[�W���k�����I�������W�����v����i�Q�[�W���\������ĂȂ�������W�����v���Ȃ��j
	if ((Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround()) && _judge != 4 ||
		_judge == 3)
	{
		// �W�����v�̍X�V������悤�ɂ���
		mJumpUpdataFlag = true;

		mMoveState = NowMove;
	}

	// ��э��݂̎�
	if (mJumpUpdataFlag && mJump->GetNowJump() != mJump->endDive)
	{
		//�W�����v�̍X�V
		mJump->DiveUpdate(mRotate);

		// ���̃W�����v����э��݂���Ȃ��A���A�����ʂ�0�ɂȂ�����
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();
			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;
		}
		// ���̃W�����v����э��݂ŁA�v�[���̂Ƃ���܂ł�������
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 2.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();

			// �����߂��c�H
			mPos.y = 2.0f;

			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;

			//�W�����v�̍X�V�������I��������Ƃ���������true�ɂ���
			mJumpedInFlag = true;
		}
	}

	// �W�����v�̎��@�i�Q�[�W���\������Ă��Ȃ��@�܂��́@���Z����|�W�V�����ɍs���ĂȂ������瓮���Ȃ��j
	else if (mJumpUpdataFlag && mJump->GetNowJump() == mJump->endDive && _judge != 0 && _startflag)
	{
		// �W�����v�̍X�V
		mJump->JumpUpdate(_judge);

		mPos = VAdd(mPos, mJump->GetVelocity());

		// 5.0�����|�W�V�������Ⴉ������
		if (mPos.y <= 5.5f)
		{
			mPos.y = 5.5f;

			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();

			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;
		}
	}

	mPos = VAdd(mPos, mJump->GetVelocity());
}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�̍X�V��������ꂽ�֐�
/// </summary>
void Fish::DanceUpdata()
{
	//�����_���X���X�^�[�g���Ă�����
	if (mDanceStartFlag)
	{
		//
		mVelocity = mTempAimlessVelocity;
	}
	//�X�^�[�g���Ă��Ȃ����
	else
	{
		//�ړI�̏ꏊ�܂ňړ�����֐����Ԃ��l��velocity�ɓ����
		mVelocity = MoveTargetPos(mSetDancePos, mPos, mRotate);
	}
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
	mTempVelocity = VScale(normPosToSetPos, DANCE_VELOCITY);


	//�~�܂�Ƃ�
	if (CheckStopped(_SetPos, _NowPos))
	{
		//�����Ăق����Ȃ��̂�NotMove�ɂ���
		mMoveState = NotMove;

		//�_���X���n�߂邽�߂Ƀt���O��true�ɂ���
		mDanceStartFlag = true;

		return mTempVelocity;
	}
	else
	{
		//�����Ăق����̂�NowMove�ɂ���
		mMoveState = NowMove;
		//���̊֐��̏�Ōv�Z����velocity��Ԃ�
		return mTempVelocity;
	}
}


/// <summary>
/// �ړ������Ƃ��Ɏw�肵���ʒu�ɒ��������ǂ���
/// </summary>
/// <param name="_targetPos">�w�肵���ʒu</param>
/// <param name="_nowPos">���̃��f���̈ʒu</param>
/// <returns>�~�܂��Ă�������true�A�~�܂��Ă͂����Ȃ�����false</returns>
bool Fish::CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos)
{
	/*-----------���f�����~�߂邽�߂ɒ�~�͈͂̋����̌v�Z----------*/
	VECTOR posToSetPos = VSub(_targetPos, _nowPos);//fish�̍��̍��W����ڕW�̍��W�܂ł̃x�N�g�����Z�o
	float PosSize = VSquareSize(posToSetPos);//posToSetPos����̋����̒l�ɂ���(�x�N�g���ł͂Ȃ�float�ɂ���)
	/*
	* VSize���g���Ə������d���Ȃ邽�ߒl�̏������d���Ȃ�Ȃ��悤��VSquareSize()���g�p����
	*/

	VECTOR setPosToPos = VSub(_nowPos, _targetPos);//fish�̖ڕW�̍��W���獡�̍��W�܂ł̃x�N�g�����Z�o
	VECTOR normSetPosToPos = VNorm(setPosToPos);//setPosToPos�̃x�N�g���𐳋K��
	VECTOR StopRange = VScale(normSetPosToPos, DANCE_STOP_RANGE);//normSetPosToPos�̃x�N�g���̑傫����1����0.25�ɂ���

	float mStopRadiusSize = VSquareSize(StopRange);//StopRange���x�N�g�����狗���ɂ���

	/*
	* mSetPos����mPos�܂ł̃x�N�g���̒���(�l��2��)��
	* mSetPos����mStopRadius�܂ł̃x�N�g���̒���(�l��2��)���
	* �傫�����A�ړ����Ȃ���΂Ȃ�Ȃ��̂�true
	* ���������͈ړ�����K�v�͂Ȃ��̂�false��Ԃ�
	*/
	if (PosSize >= mStopRadiusSize)
	{
		return false;
	}
	else if (PosSize < mStopRadiusSize)
	{
		return true;
	}
}