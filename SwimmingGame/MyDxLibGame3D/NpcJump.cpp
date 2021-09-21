#include "NpcJump.h"

//----------------------
//�萔
//----------------------
const float JUMP_UP_Y = 0.5f;      // �W�����v��������Y���̉��Z�l
const float JUMP_DOWN_Y = 0.25f;   // �W�����v�������Y���̌��Z�l

const float JUMP_UP_Z = 0.25f;     // �W�����v��������z���̉��Z�l
const float JUMP_DOWN_Z = 0.2f;    // �W�����v��������z���̌��Z�l

const float JUMP_UP_X = 0.25f;     // �W�����v��������x���̉��Z�l
const float JUMP_DOWN_X = 0.2f;    // �W�����v��������x���̌��Z�l

const float FIRST_MAX = 3.0f;     // 1��ڃW�����v�̍ő�W�����v��
const float SECOND_MAX = 5.0f;    // 2��ڃW�����v�̍ő�W�����v��
const float THIRD_MAX = 8.0f;     // ��э��݂̍ő�W�����v��

const float INIT_POS_Y = 23.0f;    // �W�����v��̍���
const float INIT_POS_Y2 = 18.0f;   // �W�����v��̍���
const float INIT_POS_Y3 = 11.0f;    // �W�����v��̍���


//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
NpcJump::NpcJump()
	: mPosNpc(VGet(0.0f, 0.0f, 0.0f))
	, mVelocityNpc(VGet(0.0f, 0.0f, 0.0f))
	, mJumpMaxNpc(FIRST_MAX)
	, mFirstJumpNpc(true)
	, mSecondJumpNpc(false)
	, mThirdJumpNpc(false)
	, mJumpUpNowNpc(false)
	, mIsGroundNpc(true)
	, mInitPos(VGet(0.0f, 0.0f, 0.0f))
	, mGravityNpc(0.005f)
	, mAdd(VGet(0.0f, 0.0f, 0.0f))
	, mSub(VGet(0.0f, 0.0f, 0.0f))
{
}
//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
NpcJump::~NpcJump()
{
}

//-----------------------------------------------------------------------------
// @brief  NPC�̃W�����v�X�V.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpUpdate(VECTOR _pos, VECTOR _rotate)
{
	// ���̋��̃|�W�V�����̏����ʒu
	if (_pos.y == INIT_POS_Y3)
	{
		mInitPos.y = INIT_POS_Y3;
	}
	else if (_pos.y == INIT_POS_Y2)
	{
		mInitPos.y = INIT_POS_Y2;
	}
	else
	{
		mInitPos.y = INIT_POS_Y;
	}

	// ���̌����ɂ���Ĕ�э��ޕ�����������
	if (_rotate.y == 90.0f * DX_PI_F / 180.0f)
	{
		mAdd.z = JUMP_UP_Z;
		mSub.z = JUMP_DOWN_Z;
	}
	else if (_rotate.y == -90.0f * DX_PI_F / 180.0f)
	{
		mAdd.z = -JUMP_UP_Z;
		mSub.z = -JUMP_DOWN_Z;
	}
	else if (_rotate.y == 180.0f * DX_PI_F / 180.0f)
	{
		mAdd.x = JUMP_UP_X;
		mSub.x = JUMP_DOWN_X;
	}
	else
	{
		mAdd.x = -JUMP_UP_X;
		mSub.x = -JUMP_DOWN_X;
	}

	// �|�W�V�������Z�b�g
	SetPosNpc(_pos);

	// �W�����v�A�b�v�̍X�V
	NpcJumpUpUpdate();

	// �|�W�V�����X�V
	NpcJumpPosUpdate();

}

//-----------------------------------------------------------------------------
// @brief  NPC�̃W�����v�A�b�v�̍X�V.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpUpUpdate()
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
			mVelocityNpc = VAdd(VGet(0.0f, JUMP_UP_Y, 0.0f), mAdd);
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
	if (mPosNpc.y >= (mInitPos.y + mJumpMaxNpc))
	{
		mJumpUpNowNpc = false;    // �����オ��Ȃ��̂�UpNow��false�ɂ���

		// �W�����v�_�E���̍X�V�ɓ���
		NpcJumpDownUpdate();
	}
}

//-----------------------------------------------------------------------------
// @brief  NPC�̗����Ă鎞�̍X�V.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpDownUpdate()
{
	if (!mThirdJumpNpc) // ��э��݈ȊO��������Y�����������Ă���
	{
		if (mPosNpc.y >= (mInitPos.y + mJumpMaxNpc))
		{
			mVelocityNpc = VGet(0.0f, -JUMP_DOWN_Y, 0.0f);
		}
	}
	else            // ��э��݂�������Y����Z����������
	{
		if (mPosNpc.y >= (mInitPos.y + mJumpMaxNpc))
		{
			mVelocityNpc = VAdd(VGet(0.0f, -JUMP_DOWN_Y, 0.0f), mSub);
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  NPC�̃|�W�V�����̍X�V.
//-----------------------------------------------------------------------------
void NpcJump::NpcJumpPosUpdate()
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
		if (!mIsGroundNpc && mPosNpc.y <= mInitPos.y)
		{
			mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
			mPosNpc.y = mInitPos.y;
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
		if (!mIsGroundNpc)
		{
			if (mPosNpc.y <= 2.0f)
			{
				mVelocityNpc = VGet(0.0f, 0.0f, 0.0f);
				mPosNpc.y = 2.0f;              // �v�[���ɖ��܂��Ă����牟���߂�
				mIsGroundNpc = true;           // �n�ʂɐڒn���Ă��� 
				mThirdJumpNpc = false;         // ��э��݂̃W�����v���I������
			}
		}
	}
}
