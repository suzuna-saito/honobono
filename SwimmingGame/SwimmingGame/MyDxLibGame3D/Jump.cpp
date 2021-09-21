#include "Jump.h"

//----------------------
//�萔
//----------------------
const float JUMP_Y = 0.35f;          // �W�����v��������Y���̉��Z�l
const float JUMP_Z = 0.25f;         // �W�����v��������z���̉��Z�l
const float JUMP_X = 0.15f;         // �W�����v��������x���̉��Z�l

const float FIRST_MAX = 3.0f;        // 1��ڃW�����v�̍ő�W�����v��
const float SECOND_MAX = 5.0f;       // 2��ڃW�����v�̍ő�W�����v��
const float THIRD_MAX = 8.0f;        // ��э��݂̍ő�W�����v��

const float GOOD = 3.0f;           // good�̎��̃W�����v��
const float PERFECT = 7.0f;        // perfect�̎��̃W�����v��


//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Jump::Jump()
	: mGravity(0.2f)
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMax(FIRST_MAX)
	, mGain(0.0f)
	, mJumpUp(true)
	, mIsGround(true)
	, mNowJump(firstJump)
	, mChange(VGet(0.0f, 0.0f, 0.0f))
{
}
//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Jump::~Jump()
{
}

//-----------------------------------------------------------------------------
// @brief  �W�����v�X�V.
//-----------------------------------------------------------------------------
void Jump::DiveUpdate(VECTOR _rotate)
{
	// ���̌����ɂ���Ĕ�э��ޕ�����������
	switch ((int)_rotate.y)
	{
		case (int)(90.0f * DX_PI_F / 180.0f) :
			mChange.z = JUMP_Z;
			break;

			case(int)(-90.0f * DX_PI_F / 180.0f) :
				mChange.z = -JUMP_Z;
				break;

				case(int)(180.0f * DX_PI_F / 180.0f) :
					mChange.x = JUMP_X;
					break;

					case(int)(0.0f, 0.0f, 0.0f) :
						mChange.x = -JUMP_X;
						break;

					default:
						break;
	}

	// ��э��݂̍X�V
	DiveNowUpdate();
}

//-----------------------------------------------------------------------------
// @brief  ��э��݂̍X�V.
//-----------------------------------------------------------------------------
void Jump::DiveNowUpdate()
{
	// ���̍����ɍs���܂ŃW�����v���グ�Ă���
	if (mJumpUp)
	{
		mIsGround = false;           // �n�ʂɐڒn���Ă��Ȃ�

		if (mNowJump != thirdJump)   // ��э��݈ȊO��������Y�������グ�Ă���
		{
			mVelocity = VGet(0.0f, JUMP_Y, 0.0f);
		}
		else                         // ��э��݂�������Y����Z��(�܂���x��)���グ��
		{
			mVelocity = VAdd(VGet(0.0f, JUMP_Y, 0.0f), mChange);
		}

		// �ݒ肵���ő�l��葝�������ʂ���ɍs������
		if (mGain >= mJumpMax)
		{
			mJumpUp = false;       // �����オ��Ȃ��̂�false�ɂ���
		}
	}
	if (!mJumpUp) // �����Ă���
	{
		if (mNowJump != thirdJump) // ��э��݈ȊO��������Y�����������Ă���
		{
			mVelocity = VGet(0.0f, -JUMP_Y, 0.0f);
		}
		else                       // ��э��݂�������Y����Z����������
		{
			mVelocity = VAdd(VGet(0.0f, -JUMP_Y, 0.0f), mChange);
		}
	}

	// �����ʂ̌v�Z
	mGain += mVelocity.y;
}


//-----------------------------------------------------------------------------
// @brief  �W�����v�̍X�V.
//-----------------------------------------------------------------------------
void Jump::JumpUpdate(int _jadge)
{
	switch (_jadge) // ����
	{
	case 0:    // bad�̎�
		mJumpMax = 0.0f;
		break;
	case 1:    // good�̎�
		mJumpMax = GOOD;
		break;
	case 2:    // parfect�̎�
		mJumpMax = PERFECT;
		break;
	default:
		break;
	}

	// ���̍����ɍs���܂ŃW�����v���グ�Ă���
	if (mJumpUp)
	{
		mIsGround = false;                     // �n�ʂɐڒn���Ă��Ȃ�

		mVelocity = VGet(0.0f, JUMP_Y, 0.0f);  // ���F���V�e�B��ݒ�

		// �ݒ肵���ő�l��葝�������ʂ���ɍs������
		if (mGain >= mJumpMax)
		{
			mJumpUp = false;       // �����オ��Ȃ��̂�false�ɂ���
		}
	}
	if (!mJumpUp) // �����Ă���
	{
		mVelocity = VGet(0.0f, -JUMP_Y, 0.0f);

	}

	// �����ʂ̌v�Z
	mGain += mVelocity.y;
}

//-----------------------------------------------------------------------------
// @brief  �W�����v�^�C�v�̍X�V.
//-----------------------------------------------------------------------------
void Jump::JumpSetUpdate()
{
	mVelocity = VGet(0.0f, 0.0f, 0.0f);   // �ړ��͂������l�ɖ߂�
	mIsGround = true;                     // �n�ʂƂ̐ڒn����
	mJumpUp = true;                       // ���̃W�����v�̂��߂�true�ɂ���
	mGain = 0.0f;                         // ���̃W�����v�̂��߂ɑ����ʂ�0.0f�ɂ���

	switch (mNowJump)           // ���̃W�����v��
	{
	case firstJump:             // 1��ڂ̃W�����v��������
		mNowJump = secondJump;  // 2��ڂ̃W�����v���o����悤�ɂ���
		mJumpMax = SECOND_MAX;  // �ő�W�����v�͂̍X�V
		break;
	case secondJump:            // 2��ڂ̃W�����v��������
		mNowJump = thirdJump;   // ��э��݂̃W�����v���o����悤�ɂ���
		mJumpMax = THIRD_MAX;
		break;
	case thirdJump:             // ��э��݂̃W�����v��������
		mNowJump = endDive;     // �W�����v���I������
		mJumpMax = 0.0f;
		break;
	default:
		mJumpMax = 0.0f;
		break;
	}
}