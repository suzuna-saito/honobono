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

	void Updata(int _judge, bool _startflag, int _nowScene);											// �X�V�֐�

	//�W�����v�̍X�V���������ꂽ�֐�
	void JumpUpdata(int _judge, bool _startflag);

	void TrainingJump(int _judge);

	//�A�[�e�B�X�e�B�b�N�X�C�~���O�̍X�V���������ꂽ�֐�
	void DanceUpdata();

	/// <summary>
	/// �ڕW�̍��W�܂œ����֐�
	/// </summary>
	VECTOR MoveTargetPos(const VECTOR _setPos, VECTOR& _nowPos, VECTOR& _rotate);

	/// <summary>
	/// �~�܂��Ă���Ƃ���true�A�~�܂��Ă��Ȃ��Ƃ��ɂ�false��Ԃ�
	/// </summary>
	bool CheckStopped(const VECTOR _targetPos, const VECTOR _nowPos);

	Jump* mJump;             //�W�����v�N���X���������ϐ�

	//-----------------------------------------------------------------------


private:

	bool mJumpUpdataFlag;    // �W�����v�̍X�V�����邩�ǂ���
	bool mJumpedInFlag;      // �W�����v�̍X�V���I��������ǂ����𔻒肷��ϐ�(�I������Ftrue�A�I����Ă��Ȃ�:false)
};

#endif // !_FISH_H_