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

///// <summary>
///// �`��֐�
///// </summary>
/*void Fish::Draw()
{

	// Mob���W�̃Z�b�g
	for (int i = 0; i < FISH_MOB_NUM; i++)
	{
		MV1SetPosition(mMHandle, mMobPos[i]);
		MV1SetRotationXYZ(mMHandle, FISH_MOB_ROTATE[i]);
		// Mob�摜�̕`��
		MV1DrawModel(mMHandle);
 
		//-------------------------------------------------
	}	//�ǂ̔z�񂪂ǂ̈ʒu�̋��������Ă���̂��̃f�o�b�N
	
	
	
	
	

	
	
	

	
	
	

	
	
	
	
	

	
	
	

	
	
	

	
	
	

	
	
	

	
	
	

	
	
	

	

	
	
	
*/