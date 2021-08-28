#pragma once
#include "DxLib.h"

/// <summary>
/// NPC�̃W�����v
/// </summary>
class NpcJump
{
public:
	NpcJump();        // �R���X�g���N�^
	~NpcJump();       // �f�X�g���N�^

	/// <summary>
	/// 1��ڂ̃W�����v�X�V����
	/// </summary>
	/// <param name="_pos">��ԃI�u�W�F�N�g�̃|�W�V����</param>
	void NpcJumpUpdate(VECTOR _pos, VECTOR _rotate);

private:
	const float mGravityNpc;// NPC�ɂ�����d��

	float mNpcInitPos;         // Npc�̏����ʒu

	VECTOR mPosNpc;         // NPC�̃|�W�V����
	VECTOR mVelocityNpc;	// NPC�̈ړ���.

	VECTOR mAdd;
	VECTOR mSub;

	float mJumpMaxNpc;      // NPC��y���̍ő�l

	bool mFirstJumpNpc;     // NPC��1��ڂ̃W�����v�����邩
	bool mSecondJumpNpc;    // NPC��2��ڂ̃W�����v�����邩
	bool mThirdJumpNpc;     // NPC����э��݂̃W�����v�����邩

	bool mJumpUpNowNpc;     // NPC���W�����v�A�b�v���Ă���

	bool mIsGroundNpc;      // NPC�̒n�ʂƂ̐ڒn����

	VECTOR mInitPos;

	/// <summary>
	/// �W�����v�A�b�v����
	/// </summary>
	void NpcJumpUpUpdate();
	/// <summary>
	/// �W�����v�_�E������
	/// </summary>
	void NpcJumpDownUpdate();
	/// <summary>
	/// �ʒu�̍X�V����
	/// </summary>
	void NpcJumpPosUpdate();

public:    // �Q�b�^�[�A�Z�b�^�[

	// NPC���W�����v�����ǂ����̃t���O���Z�b�g����
	void SetJumpNpc(bool _jump) { mJumpUpNowNpc = _jump; }
	bool GetGroundNpc() { return mIsGroundNpc; }


	// NPC�̃|�W�V�������Z�b�g
	void SetPosNpc(VECTOR _pos) { mPosNpc = _pos; }
	// NPC�̃|�W�V�������Q�b�g
	VECTOR GetPosNpc() { return mPosNpc; }

	// NPC��1��ڂ̃W�����v�t���O���Q�b�g
	bool GetFirstNpc() { return mFirstJumpNpc; }
	// NPC��2��ڂ̃W�����v�t���O���Q�b�g
	bool GetSecondNpc() { return mSecondJumpNpc; }
	// NPC��3��ڂ̃W�����v�t���O���Q�b�g
	bool GetThirdNpc() { return mThirdJumpNpc; }

};

