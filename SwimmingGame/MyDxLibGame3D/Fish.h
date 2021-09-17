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

	void Updata(int _judge);											// �X�V�֐�

	//�W�����v�̍X�V���������ꂽ�֐�
	void JumpUpdata(int _judge);

	//�A�[�e�B�X�e�B�b�N�X�C�~���O�̍X�V���������ꂽ�֐�
	void DanceUpdata();

	Jump* mJump;             //�W�����v�N���X���������ϐ�
	class Dance* mDance;           //�_���X�N���X���������ϐ�

private:
	bool mJumpUpdataFlag;    // �W�����v�̍X�V�����邩�ǂ���
	bool mJumpedInFlag;      // �W�����v�̍X�V���I��������ǂ����𔻒肷��ϐ�(�I������Ftrue�A�I����Ă��Ȃ�:false)

	bool mSetDancePosFlag;   // mSetDancePos�̃|�W�V�����ɋ�������Ƃ���true�ɂ���A���Ȃ��Ƃ���false

	float mDeltaTime;
};

#endif // !_FISH_H_