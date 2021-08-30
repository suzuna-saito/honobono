#include "Fish.h"
#include "Common.h"
#include "Jump.h"
#include "Input.h"
#include "Timing.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish::Fish(int _sourceModelHandle,
	VECTOR _pos, VECTOR _rotate, VECTOR _dancePos)
	:FishBase(_sourceModelHandle)
{
	mPos = _pos;
	mRotate = _rotate;
	mSetDancePos = _dancePos;

	mVelocity = VGet(0.0f, 0.0f, 0.0f);

	mJumpFlag = false;

	mJump = new Jump();

	mTiming = new Timing();
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
	// �S�ẴW�����v���I����Ă��Ȃ���Ԃ�
	// �{�^���������ꂽ��A�܂���timing�Q�[�W���k�����I�������W�����v����i���Ă������j
	if (mJump->GetNowJump() != mJump->endJump &&
		(Key[KEY_INPUT_SPACE] == 1 && mJump->GetIsGround())/*||
		(mTiming->GetRadius() <= 1 && mJump->GetIsGround())*/)
	{
		// �W�����v�̍X�V������悤�ɂ���
		mJumpFlag = true;
	}

	if (mJumpFlag)
	{
		//�W�����v�̍X�V
		mJump->JumpUpdate(mRotate);

		// ���̃W�����v����э��݂���Ȃ��A���A�����ʂ�0�ɂȂ�����
		if (mJump->GetNowJump() != mJump->thirdJump && mJump->GetGain() <= 0.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();
			// �W�����v�̍X�V���~�߂�
			mJumpFlag = false;
		}
		// ���̃W�����v����э��݂ŁA�v�[���̂Ƃ���܂ł�������
		else if (mJump->GetNowJump() == mJump->thirdJump && mPos.y <= 2.0f)
		{
			// �W�����v�p�^�[�����X�V����
			mJump->JumpSetUpdate();

			// �����߂��c�H
			mPos.y = 2.0f;

			// �W�����v�̍X�V���~�߂�
			mJumpFlag = false;
		}
	}

	// �|�W�V�����̍X�V
	mPos = VAdd(mPos, mJump->GetVelocity());
}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃Z�b�g�|�W�V����
/// </summary>
/// <param name="_setPos">�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃|�W�V����</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
