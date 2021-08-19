#pragma once
#include "DxLib.h"

const int FISH_MOB_NUM = 11;    // ���̐�

/// <summary>
/// �v���C���[�N���X�̒�`
/// </summary>
class Player;

/// <summary>
/// Player�N���X
/// </summary>
class Fish
{
private:

	int mMHandle;                   // Mob�摜�ϐ� 
	int MobFishTexture;             // Mob�e�N�X�`��

	VECTOR mMobPos[FISH_MOB_NUM];             // Mob�̍��W

	bool mFirstJump;        // 1��ڂ̃W�����v�����邩
	bool mSecondJump;       // 2��ڂ̃W�����v�����邩
	bool mThirdJump;        // ��э��݂̃W�����v�����邩

	bool mJumpUpNow;        // �W�����v�A�b�v���Ă���

	bool mIsGround;         // �n�ʂƂ̐ڒn����


	Player* mp;    //Player�̃N���X�ϐ�

	VECTOR mVelocity;

	const VECTOR FISH_MOB_ROTATE[FISH_MOB_NUM];    // Mob�̉�]�p�x

public:
	// �R���X�g���N�^
	Fish();
	// �f�X�g���N�^
	virtual ~Fish();

	// �X�V�֐�
	void Update();
	// �`��֐�
	void Draw();

	//�v���C���[�Ɠ����W�����v�����邽�߂̊֐�
	//�֐��̒��̓v���C���[��Jump�֐��Ƃقړ����ł�
	/// <summary>
	/// 1��ڂ̃W�����v�X�V����
	/// </summary>
	void FirstJumpUpdate(int _mobNum);
	/// <summary>
	/// 2��ڂ̃W�����v�X�V����
	/// </summary>
	void SecondJumpUpdate(int _mobNum);
	/// <summary>
	/// ��э��݂̃W�����v�X�V����
	/// </summary>
	void ThirdJumpUpdate(int _mobNum);
};