#include "Jump.h"

//----------------------
//�萔
//----------------------
const float JUMP_UP_Y = 0.5f;      // �W�����v��������Y���̉��Z�l
const float JUMP_DOWN_Y = 0.25f;   // �W�����v�������Y���̌��Z�l

const float JUMP_UP_Z = 0.25f;     // �W�����v��������z���̉��Z�l
const float JUMP_DOWN_Z = 0.2f;    // �W�����v��������z���̌��Z�l

const float FIRST_MAX = 3.0f;     // 1��ڃW�����v�̍ő�W�����v��
const float SECOND_MAX = 5.0f;    // 2��ڃW�����v�̍ő�W�����v��
const float THIRD_MAX = 8.0f;     // ��э��݂̍ő�W�����v��

const float INIT_POS_Y = 23.0f;    // �W�����v��̍���(�v���C���[����)
const float INIT_POS_Y2 = 18.0f;   // �W�����v��̍���
const float INIT_POS_Y3 = 11.0f;    // �W�����v��̍���

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Jump::Jump()
	: mPos(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMax(FIRST_MAX)
	, mFirstJump(true)
	, mSecondJump(false)
	, mThirdJump(false)
	, mJumpUpNow(false)
	, mIsGround(true)
	, mGravity(0.2f)
	, mInitPos(0.0f)
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
void Jump::JumpUpdate(VECTOR _pos)
{
	SetPos(_pos);

	// �W�����v�A�b�v�̍X�V
	JumpUpUpdate();

	// �|�W�V�����X�V
	JumpPosUpdate();
}

//-----------------------------------------------------------------------------
// @brief  �W�����v�A�b�v�̍X�V.
//-----------------------------------------------------------------------------
void Jump::JumpUpUpdate()
{
	// ���̍����ɍs���܂ŃW�����v�A�b�v���ɂ���
	if (mJumpUpNow)
	{
		mIsGround = false; // �n�ʂɐڒn���Ă��Ȃ�

		if (!mThirdJump)   // ��э��݈ȊO��������Y�������グ�Ă���
		{
			mVelocity = VGet(0.0f, JUMP_UP_Y, 0.0f);
		}
		else               // ��э��݂�������Y����Z�����グ��
		{

			mVelocity = VGet(0.0f, JUMP_UP_Y, JUMP_UP_Z);
		}

		// �ő�̍������X�V�A�ݒ�----------
		if (mSecondJump)   // 2��ڂ̃W�����v��������
		{
			mJumpMax = SECOND_MAX;
		}
		if (mThirdJump)    // ��э��݂̃W�����v��������
		{
			mJumpMax = THIRD_MAX;
		}
		//---------------------------

	}

	// �ݒ肵���ő�l����ɍs������--------------
	if (mPos.y >= (INIT_POS_Y + mJumpMax))
	{
		mJumpUpNow = false;    // �����オ��Ȃ��̂�UpNow��false�ɂ���

		// �W�����v�_�E���̍X�V�ɓ���
		JumpDownUpdate();
	}
}
//-----------------------------------------------------------------------------
// @brief  �����Ă鎞�̍X�V.
//-----------------------------------------------------------------------------
void Jump::JumpDownUpdate()
{
	if (!mThirdJump) // ��э��݈ȊO��������Y�����������Ă���
	{
		if (mPos.y >= (INIT_POS_Y + mJumpMax))
		{
			mVelocity = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // ��э��݂�������Y����Z����������
	{
		if (mPos.y >= (INIT_POS_Y + mJumpMax))
		{
			mVelocity = VGet(0.0f, -JUMP_DOWN_Y, JUMP_DOWN_Z);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  �|�W�V�����̍X�V.
//-----------------------------------------------------------------------------
void Jump::JumpPosUpdate()
{
	// y���ɗ͂������������ɏd�͒l������
	if (mVelocity.y != 0.0f)
	{
		mVelocity.y = mVelocity.y - (mGravity / mPos.y);
	}
	// �|�W�V�������X�V
	mPos = VAdd(mPos, mVelocity);


	// �����ʒuor�v�[���܂ł������瓮�����~�ߎ��̃W�����v�Ɉڍs����
	if (!mThirdJump)
	{
		if (!mIsGround && mPos.y <= INIT_POS_Y)
		{
			mVelocity = VGet(0.0f, 0.0f, 0.0f);
			mPos.y = INIT_POS_Y;
			mIsGround = true;          // �n�ʂɐڒn���Ă��� 

			if (mFirstJump)
			{
				mFirstJump = false;        // 1��ڂ̃W�����v���I������
				mSecondJump = true;        // 2��ڂ̃W�����v���ł���悤�ɂ���
			}
			else
			{
				mSecondJump = false;       // 2��ڂ̃W�����v���I������
				mThirdJump = true;         // ��э��݂̃W�����v���ł���悤�ɂ���
			}
		}
	}
	else// ��э��݂̏ꍇ
	{
		if (!mIsGround)
		{
			if (mPos.y <= 2.0f)
			{
				mVelocity = VGet(0.0f, 0.0f, 0.0f);
				mPos.y = 2.0f;              // �v�[���ɖ��܂��Ă����牟���߂�
				mIsGround = true;           // �n�ʂɐڒn���Ă��� 
				mThirdJump = false;         // ��э��݂̃W�����v���I������
			}
		}
	}
}
