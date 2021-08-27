#include "Fish.h"
#include "Common.h"
#include "NpcJump.h"

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

	mNpcJump = new NpcJump();
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
	if (mNpcJump->GetGroundNpc())
	{
		mNpcJump->SetJumpNpc(true);
	}

	// �P��ځA�Q��ځA��э��݂����ꂩ�̃t���O��true��������
	if (mNpcJump->GetFirstNpc() || mNpcJump->GetSecondNpc() || mNpcJump->GetThirdNpc())
	{
		// �W�����v�̍X�V������
		mNpcJump->NpcJumpUpdate(GetPos(), GetRotate());

		// �|�W�V�������Z�b�g
		SetPos(mNpcJump->GetPosNpc());
	}


}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃Z�b�g�|�W�V����
/// </summary>
/// <param name="_setPos">�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃|�W�V����</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
