#ifndef _FISH_H_
#define _FISH_H_

#include "DxLib.h"
#include"FishBase.h"

class Jump;
class Timing;

/// <summary>
/// ����C���̃N���X
/// </summary>
class Fish :public FishBase
{
public:
	Fish(int _sourceModelHandle,
		VECTOR _pos, VECTOR _rotate, VECTOR _dancePos);		// �R���X�g���N�^
	virtual ~Fish();										// �f�X�g���N�^

	void Updata();											// �X�V�֐�

	//�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̃Z�b�g�|�W�V����
	void SetDancePos(const VECTOR _setPos);

	Jump* mJump;

	Timing* mTiming;

private:
};

#endif // !_FISH_H_