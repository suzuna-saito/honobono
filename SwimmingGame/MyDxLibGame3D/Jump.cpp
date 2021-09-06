#include "Jump.h"

//----------------------
//�萔
//----------------------
const float JUMP_UP_Y = 0.5f;      // �W�����v��������Y���̉��Z�l
const float JUMP_DOWN_Y = 0.25f;   // �W�����v�������Y���̌��Z�l

const float JUMP_UP_Z = 0.25f;     // �W�����v��������z���̉��Z�l
const float JUMP_DOWN_Z = 0.2f;    // �W�����v��������z���̌��Z�l

const float JUMP_UP_X = 0.25f;
const float JUMP_DOWN_X = 0.2f;

const float FIRST_MAX = 3.0f;     // 1��ڃW�����v�̍ő�W�����v��
const float SECOND_MAX = 5.0f;    // 2��ڃW�����v�̍ő�W�����v��
const float THIRD_MAX = 8.0f;     // ��э��݂̍ő�W�����v��

const float INIT_POS_Y = 20.0f;    // �W�����v��̍���(�v���C���[����)
const float INIT_POS_Y2 = 15.0f;   // �W�����v��̍���
const float INIT_POS_Y3 = 9.0f;    // �W�����v��̍���

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Jump::Jump()
	: mPos(VGet(0.0f, 0.0f, 0.0f))
	, mPosNpc(VGet(0.0f, 0.0f, 0.0f))
	, mVelocity(VGet(0.0f, 0.0f, 0.0f))
	, mVelocityNpc(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMax(FIRST_MAX)
	, mJumpMaxNpc(FIRST_MAX)
	, mFirstJump(true)
	, mSecondJump(false)
	, mThirdJump(false)
	, mFirstJumpNpc(true)
	, mSecondJumpNpc(false)
	, mThirdJumpNpc(false)
	, mJumpUpNow(false)
	, mJumpUpNowNpc(false)
	, mIsGround(true)
	, mIsGroundNpc(true)
	, mGravity(0.2f)
	, mGravityNpc(0.005f)
	, mInitPos(0.0f)
	, mAdd(VGet(0.0f, 0.0f, 0.0f))
	, mSub(VGet(0.0f, 0.0f, 0.0f))
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
			mJumpMax =THIRD_MAX;
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
		if (!mIsGround && mPos.y <= 0.0f)
		{
			if (mPos.y <= 0.0f)
			{
				mVelocity = VGet(0.0f, 0.0f, 0.0f);
				mPos.y = 0.0f;              // �v�[���ɖ��܂��Ă����牟���߂�
				mIsGround = true;           // �n�ʂɐڒn���Ă��� 
				mThirdJump = false;         // ��э��݂̃W�����v���I������
			}
		}
	}
}



/*-----------------------NPC�֘A-------------------------------------*/

//-----------------------------------------------------------------------------
// @brief  NPC�̃W�����v�X�V.
//-----------------------------------------------------------------------------
void Jump::NpcJumpUpdate(VECTOR _pos, int _number)
{
	if (_number == 1 || _number == 4 || _number == 7 || _number == 10)
	{
		mInitPos = INIT_POS_Y3;
	}
	else if (_number == 0 || _number == 3 || _number == 6 || _number == 9)
	{
		mInitPos = INIT_POS_Y2;
	}
	else
	{
		mInitPos = INIT_POS_Y;
	}
	//----------------------------------------------------

	mAdd = VGet(0.0f, 0.0f, 0.0f);
	mSub = VGet(0.0f, 0.0f, 0.0f);

	if (_number == 0 || _number == 1)
	{
		mAdd = VGet(0.0f, 0.0f, JUMP_UP_Z);
		mSub = VGet(0.0f, 0.0f, JUMP_DOWN_Z);
	}
	else if (_number == 2 || _number == 3 || _number == 4)
	{
		mAdd = VGet(0.0f, 0.0f, -JUMP_UP_Z);
		mSub = VGet(0.0f, 0.0f, -JUMP_DOWN_Z);
	}
	else if (_number == 5 || _number == 6 || _number == 7)
	{
		mAdd = VGet(JUMP_UP_X, 0.0f, 0.0f);
		mSub = VGet(JUMP_DOWN_X, 0.0f, 0.0f);
	}
	else
	{
		mAdd = VGet(-JUMP_UP_X, 0.0f, 0.0f);
		mSub = VGet(-JUMP_DOWN_X, 0.0f, 0.0f);
	}
	SetPosNpc(_pos);

	// �W�����v�A�b�v�̍X�V
	NpcJumpUpUpdate();

	// �|�W�V�����X�V
	NpcJumpPosUpdate();
}

//-----------------------------------------------------------------------------
// @brief  NPC�̃W�����v�A�b�v�̍X�V.
//-----------------------------------------------------------------------------
void Jump::NpcJumpUpUpdate()
{
	// ���̍����ɍs���܂ŃW�����v�A�b�v���ɂ���
	if (mJumpUpNowNpc)
	{
		mIsGroundNpc = false; // �n�ʂɐڒn���Ă��Ȃ�

		if (!mThirdJumpNpc)   // ��э��݈ȊO��������Y�������グ�Ă���
		{
			mVelocityNpc = VGet(0.0f, JUMP_UP_Y, 0.0f);
		}
		else               // ��э��݂�������Y����Z�����グ��
		{
			mVelocityNpc = VAdd(VGet(0.0f, JUMP_UP_Y, 0.0f),mAdd);
		}

		// �ő�̍������X�V�A�ݒ�----------
		if (mSecondJumpNpc)   // 2��ڂ̃W�����v��������
		{
			mJumpMaxNpc = SECOND_MAX;
		}
		if (mThirdJumpNpc)    // ��э��݂̃W�����v��������
		{
			mJumpMaxNpc = THIRD_MAX;
		}
		//---------------------------

	}

	// �ݒ肵���ő�l����ɍs������--------------
	if (mPosNpc.y >= (mInitPos + mJumpMaxNpc))
	{
		mJumpUpNowNpc = false;    // �����オ��Ȃ��̂�UpNow��false�ɂ���

		// �W�����v�_�E���̍X�V�ɓ���
		NpcJumpDownUpdate();
	}
}

//-----------------------------------------------------------------------------
// @brief  NPC�̗����Ă鎞�̍X�V.
//-----------------------------------------------------------------------------
void Jump::NpcJumpDownUpdate()
{
	if (!mThirdJumpNpc) // ��э��݈ȊO��������Y�����������Ă���
	{
		if (mPosNpc.y >= (mInitPos + mJumpMaxNpc))
		{
			mVelocityNpc = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // ��э��݂�������Y����Z����������
	{
		if (mPosNpc.y >= (mInitPos + mJumpMaxNpc))
		{
			mVelocityNpc = VAdd(VGet(0.0f, -JUMP_DOWN_Y, 0.0f), mSub);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  NPC�̃|�W�V�����̍X�V.
//-----------------------------------------------------------------------------
void Jump::NpcJumpPosUpdate()
{
	// y���ɗ͂������������ɏd�͒l������
	if (mVelocityNpc.y != 0.0f)
	{
		mVelocityNpc.y = mVelocityNpc.y - (mGravityNpc / mPosNpc.y);
	}
	// �|�W�V�������X�V
	mPosNpc = VAdd(mPosNpc, mVelocityNpc);


	// �����ʒuor�v�[���܂ł������瓮�����~�ߎ��̃W�����v�Ɉڍs����
	if (!mThirdJumpNpc)
	{
		if (!mIsGroundNpc && mPosNpc.y <= mInitPos)
		{
			mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
			mPosNpc.y = mInitPos;
			mIsGroundNpc = true;          // �n�ʂɐڒn���Ă��� 

			if (mFirstJumpNpc)
			{
				mFirstJumpNpc = false;        // 1��ڂ̃W�����v���I������
				mSecondJumpNpc = true;        // 2��ڂ̃W�����v���ł���悤�ɂ���
			}
			else
			{
				mSecondJumpNpc = false;       // 1��ڂ̃W�����v���I������
				mThirdJumpNpc = true;         // ��э��݂̃W�����v���ł���悤�ɂ���
			}
		}
	}
	else// ��э��݂̏ꍇ
	{
		if (!mIsGroundNpc && mPosNpc.y <= 0.0f)
		{
			if (mPosNpc.y <= 0.0f)
			{
				mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
				mPosNpc.y = 0.0f;              // �v�[���ɖ��܂��Ă����牟���߂�
				mIsGroundNpc = true;           // �n�ʂɐڒn���Ă��� 
				mThirdJumpNpc = false;         // ��э��݂̃W�����v���I������
			}
		}
	}
}
