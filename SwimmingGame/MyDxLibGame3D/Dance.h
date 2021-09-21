#pragma once
#include"DxLib.h"

/// <summary>
/// �A�[�e�B�X�e�B�b�N�X�C�~���O�N���X
/// </summary>
class Dance
{
public:
	Dance(const VECTOR _SetPos);                         //�R���X�g���N�^
	~Dance();                        //�f�X�g���N�^

	void Updata();                   //�X�V�֐�

	/// <summary>
	/// �_���X�W�����̃|�W�V����
	/// </summary>
	VECTOR SetDancePos(const VECTOR _SetPos, VECTOR& _NowPos, VECTOR& _Rotate);

	//---------���ꂼ���getter--------------	
	//�ړ��ʂ�\���x�N�g����Ԃ�
	VECTOR GetVelocity() { return mVelocity; }

	//��]�x�N�g����Ԃ�
	VECTOR GetRotate() { return mRotate; }

	//�_���X�W�����Ƀ��f�����~�܂��Ă��邩�ǂ����̃t���O��getter
	const bool GetStopSetPosFlag() { return mStopFlag; }

private:
	VECTOR mVelocity;                   //�ړ��ʂ�\���x�N�g��
	VECTOR mRotate;                     //���f���̉�]

	VECTOR mSetDancePos;                //���̑���ɖ߂�ׂ̃|�W�V�����x�N�g��

	VECTOR mStopRange;                  //���f�����~�܂�͈�

	//Dance�������Ă��邻�̋����~�܂��Ă���Ƃ���true�A�����Ă���Ƃ���false
	bool mStopFlag;
};