#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include"Input.h"
#include"Dance.h"

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

	mJump = new Jump();
	mDance = new Dance(mSetDancePos);
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
void Fish::Updata(int _judge)
{
	// ���Z�O
	if (!mJumpedInFlag)
	{
		//��э��݂̏���
		JumpUpdata(_judge);
	}
	// ���Z��
	else
	{
		//�A�[�e�B�X�e�B�b�N�X�C�~���O�̏���
		//DanceUpdata();

		// �W�����v�̏���
		JumpUpdata(_judge);
	}
	
	// �|�W�V�����̍X�V
	mPos = VAdd(mPos, mJump->GetVelocity());
}

/// <summary>
/// �W�����v�̍X�V����ꂽ�֐� : @saito
/// </summary>
void Fish::JumpUpdata(int _judge)
{
	// �{�^���������ꂽ��A�܂���timing�Q�[�W���k�����I�������W�����v����i���Ă������j
	if ((Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround()) && _judge != 4 ||
		_judge == 3)
	{
		// �W�����v�̍X�V������悤�ɂ���
		mJumpUpdataFlag = true;
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
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 4.5f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();

			// �����߂��c�H
			mPos.y = 4.5f;

			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;

			//�W�����v�̍X�V�������I��������Ƃ���������true�ɂ���
			mJumpedInFlag = true;
		}
	}

	// �W�����v�̎�
	else if (mJumpUpdataFlag && mJump->GetNowJump() == mJump->endDive)
	{
		// �W�����v�̍X�V
		mJump->JumpUpdate(_judge);

		// �����ʂ�0�ɂȂ�����
		if (mJump->GetGain() <= 0.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();

			// �W�����v�̍X�V���~�߂�
			mJumpUpdataFlag = false;
		}
	}
}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�̍X�V��������ꂽ�֐�
/// </summary>
void Fish::DanceUpdata()
{
	if (mDance->SetDancePos(mSetDancePos, mPos, mRotate))
	{
		
	}
	
}