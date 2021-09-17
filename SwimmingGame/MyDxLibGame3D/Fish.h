#ifndef _FISH_H_
#define _FISH_H_

#include "DxLib.h"
#include"FishBase.h"

class Jump;

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

	//�W�����v�̍X�V���������ꂽ�֐�
	void JumpUpdata();

	//�A�[�e�B�X�e�B�b�N�X�C�~���O�̍X�V���������ꂽ�֐�
	void DanceUpdata();

	/// <summary>
	/// �ڕW�̍��W�܂œ����֐�
	/// </summary>
	VECTOR MoveTargetPos(const VECTOR _setPos, VECTOR& _nowPos, VECTOR& _rotate);

	//�v�[���������܂悤���������鏈��
	VECTOR MoveAimlessWandering(VECTOR& _nowPos);

	/// <summary>
	/// �~�܂��Ă���Ƃ���true�A�~�܂��Ă��Ȃ��Ƃ��ɂ�false��Ԃ�
	/// </summary>
	bool CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos);

	Jump* mJump;             //�W�����v�N���X���������ϐ�

	//-----------------------------------------------------------------------


private:

	bool mJumpUpdataFlag;    // �W�����v�̍X�V�����邩�ǂ���
	bool mJumpedInFlag;      // �W�����v�̍X�V���I��������ǂ����𔻒肷��ϐ�(�I������Ftrue�A�I����Ă��Ȃ�:false)

	float mDeltaTime;
};

#endif // !_FISH_H_