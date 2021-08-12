#pragma once
#include "DxLib.h"

/// <summary>
/// �W�����v�֌W
/// </summary>
class Jump
{
public:
	Jump();        // �R���X�g���N�^
	~Jump();       // �f�X�g���N�^

	// �v���C���[�֘A ------------------------------------------
	/// <summary>
	/// �W�����v�X�V����
	/// </summary>
	/// <param name="_pos">��ԃI�u�W�F�N�g�̃|�W�V����</param>
	void JumpUpdate(VECTOR _pos);

	// NPC�֘A --------------------------------------------------
	/// <summary>
	/// 1��ڂ̃W�����v�X�V����
	/// </summary>
	/// <param name="_pos">��ԃI�u�W�F�N�g�̃|�W�V����</param>
	void NpcJumpUpdate(VECTOR _pos,int _number);
	//-----------------------------------------------------------

private:
	const float mGravity;   // �d��

	const float mGravityNpc;// NPC�ɂ�����d��

	float mInitPos;         // ���̃I�u�W�F�N�g�̏����ʒu

	// �v���C���[�֘A ---------------------------------
	VECTOR mPos;            // �|�W�V����
	VECTOR mVelocity;		// �ړ���.

	float mJumpMax;         // y���̍ő�l

	bool mFirstJump;        // 1��ڂ̃W�����v�����邩
	bool mSecondJump;       // 2��ڂ̃W�����v�����邩
	bool mThirdJump;        // ��э��݂̃W�����v�����邩

	bool mJumpUpNow;        // �W�����v�A�b�v���Ă���

	bool mIsGround;         // �n�ʂƂ̐ڒn����
	//-------------------------------------------------

	// NPC�֘A----------------------------------------
	VECTOR mPosNpc;         // NPC�̃|�W�V����
	VECTOR mVelocityNpc;	// NPC�̈ړ���.

	float mAdd;
	float mSub;

	float mJumpMaxNpc;      // NPC��y���̍ő�l

	bool mFirstJumpNpc;     // NPC��1��ڂ̃W�����v�����邩
	bool mSecondJumpNpc;    // NPC��2��ڂ̃W�����v�����邩
	bool mThirdJumpNpc;     // NPC����э��݂̃W�����v�����邩

	bool mJumpUpNowNpc;     // NPC���W�����v�A�b�v���Ă���

	bool mIsGroundNpc;      // NPC�̒n�ʂƂ̐ڒn����
	//-------------------------------------------------

	// �v���C���[�֘A ---------------------------------
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
	//-------------------------------------------------


	// NPC�֘A ---------------------------------
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
	//-------------------------------------------------

public:    // �Q�b�^�[�A�Z�b�^�[

	// �v���C���[�֘A ---------------------------------
	
	// �W�����v�����ǂ����̃t���O���Z�b�g����
	void SetJump(bool _jump) { mJumpUpNow = _jump; }

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

	// �ڒn������Q�b�g
	bool GetGround() { return mIsGround; }

	//-------------------------------------------------
	
	// NPC�֘A----------------------------------------
	
	// NPC���W�����v�����ǂ����̃t���O���Z�b�g����
	void SetJumpNpc(bool _jump) { mJumpUpNowNpc = _jump; }

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

	// NPC�̐ڒn������Q�b�g
	bool GetGroundNpc() { return mIsGroundNpc; }

	//-------------------------------------------------
};
