#pragma once
#include "DxLib.h"

/// <summary>
/// ��э��݃W�����v
/// </summary>
class Jump
{
public:
	Jump();        // �R���X�g���N�^
	~Jump();       // �f�X�g���N�^

	/// <summary>
	/// �W�����v�X�V����
	/// </summary>
	/// <param name="_rotate">��ԃI�u�W�F�N�g�̌���</param>
	void JumpUpdata(VECTOR _rotate);
	
	/// <summary>
	/// �W�����v�p�^�[���̍X�V����
	/// </summary>
	/// <param name="_pos">�~�܂�ʒu</param>
	void JumpSetUpdata();

	// �W�����v�̎��
	enum NowJump
	{
		// 1��ڂ̃W�����v
		firstJump,
		// 2��ڂ̃W�����v
		secondJump,
		// ��э��݃W�����v
		thirdJump,

		// �S�ẴW�����v���I������
		endJump
	};

private:

	VECTOR mVelocity;    // �ړ���.
	VECTOR mChange;      // �ړ�����

	float mJumpMax;      // y���̍ő呝����

	float mGain;         // ���̑�����

	NowJump mNowJump;    // ���̃W�����v

	bool mJumpUp;        // �オ�邱�Ƃ��o����

	bool mIsGround;      // �n�ʂƂ̐ڒn����
	
	const float mGravity;// �d��

	/// <summary>
	/// �W�����v�̏���
	/// </summary>
	void JumpNowUpdata();

public:    // �Q�b�^�[�A�Z�b�^�[
	// �n�ʂƐڒn���Ă��邩�ǂ���
	bool GetIsGround() { return mIsGround; }

	// �ړ��͂�Ԃ�
	VECTOR GetVelocity() { return mVelocity; }

	// �����ʂ�Ԃ�
	float GetGain() { return mGain; }

	// ���Ȃ�̃W�����v���s���Ă��邩��Ԃ�
	NowJump GetNowJump() { return mNowJump; }
};

