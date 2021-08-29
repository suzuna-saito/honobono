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
	// �P��ځA�Q��ځA��э��݂����ꂩ�̃t���O��true��������(�I����Ă��Ȃ���Ԃ�������)
	if (mJump->GetFirst() || mJump->GetSecond() || mJump->GetThird())
	{
		// �{�^���������ꂽ��W�����v����
		// �܂���timing�Q�[�W���k�����I������珟��ɃW�����v����i���Ă������j
		if ((Key[KEY_INPUT_SPACE] == 1 && mJump->GetGround())/*||
			(mTiming->GetRadius() <= 1 && mJump->GetGround())*/)
		{
			// �W�����v�����ǂ����̃t���O��true�ɂ���
			mJump->SetJump(true);
		}

		// �W�����v�̍X�V������
		mJump->JumpUpdate(mPos, mRotate);
		// �|�W�V�����̍X�V
		mPos = mJump->GetPos();
	}
	///* �S�ẴW�����v���I�������v���C���[��0�̏��ɍs���܂Œ��i������
	//else if (mPos.z <= 0.0f)
	//{
	//	mVelocity = VGet(0.0f, 0.0f, 0.2f);
	//	mPos = VAdd(mPos, mVelocity);
	//}*/
}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃Z�b�g�|�W�V����
/// </summary>
/// <param name="_setPos">�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃|�W�V����</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
