#include "Fish.h"
#include "Common.h"

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
}

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃Z�b�g�|�W�V����
/// </summary>
/// <param name="_setPos">�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃|�W�V����</param>
void Fish::SetDancePos(const VECTOR _setPos)
{

}
