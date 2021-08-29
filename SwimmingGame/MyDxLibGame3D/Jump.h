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
	/// <param name="_pos">��ԃI�u�W�F�N�g�̃|�W�V����</param>
	/// <param name="_rotate">��ԃI�u�W�F�N�g�̌���</param>
	void JumpUpdate(VECTOR _pos, VECTOR _rotate);

private:
	const float mGravity;// �d��

	VECTOR mPos;         // �|�W�V����
	VECTOR mVelocity;    // �ړ���.

	VECTOR mAdd;         // ���Z�l
	VECTOR mSub;         // ���Z�l

	float mJumpMax;      // y���̍ő�l

	bool mFirstJump;     // 1��ڂ̃W�����v�����邩
	bool mSecondJump;    // 2��ڂ̃W�����v�����邩
	bool mThirdJump;     // ��э��݂̃W�����v�����邩

	bool mJumpUpNow;     // �W�����v�A�b�v���Ă���

	bool mIsGround;      // �n�ʂƂ̐ڒn����

	VECTOR mInitPos;     // �����ʒu

	/// <summary>
	/// �W�����v�A�b�v����
	/// </summary>
	void JumpUpUpdate();
	/// <summary>
	/// �W�����v�_�E������
	/// </summary>
	void JumpDownUpdate();
	/// <summary>
	/// �ʒu�̍X�V����
	/// </summary>
	void JumpPosUpdate();

public:    // �Q�b�^�[�A�Z�b�^�[

	// �W�����v�����ǂ����̃t���O���Z�b�g����
	void SetJump(bool _jump) { mJumpUpNow = _jump; }
	// �n�ʂƐڒn���Ă��邩�ǂ���
	bool GetGround() { return mIsGround; }


	// �|�W�V�������Z�b�g
	void SetPos(VECTOR _pos) { mPos = _pos; }
	// �|�W�V�������Q�b�g
	VECTOR GetPos() { return mPos; }

	// 1��ڂ̃W�����v�t���O���Q�b�g
	bool GetFirst() { return mFirstJump; }
	// 2��ڂ̃W�����v�t���O���Q�b�g
	bool GetSecond() { return mSecondJump; }
	// 3��ڂ̃W�����v�t���O���Q�b�g
	bool GetThird() { return mThirdJump; }

};

