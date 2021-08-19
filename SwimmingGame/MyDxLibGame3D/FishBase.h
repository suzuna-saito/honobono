#pragma once
#include "DxLib.h"

/// <summary>
/// FishBase�N���X
/// </summary>
class FishBase
{
protected:

	int mModelHandle;                   // ��Mob�摜�ϐ� 
	int mModelFishTexture;             // ��Mob�e�N�X�`��

	VECTOR mPos;             // ���̍��W

	VECTOR mVelocity;     //�ړ����x

	VECTOR mRotate;    // Mob�̃��f���������Ă���p�x

	VECTOR mSetDancePos;    //�V���N�����ł������|�W�V����

	bool mInPoolFlag;    //�v�[���ɓ����Ă��邩�ǂ����̃t���O

public:
	// �R���X�g���N�^
	FishBase(int _sourceModelHandle, int _sourceModelTexture);
	// �f�X�g���N�^
	virtual ~FishBase();

	// �X�V�֐�
	virtual void Updata(FishBase* _mobFish);

	// �V���N���ōł������ʒu�̐ݒ�
	void SetDancePos(VECTOR _setDancePos);

	// �`��֐�
	virtual void Draw();

	//���f���n���h���̎擾
	int GetModelHandle() { return mModelHandle; }

	//�|�W�V������setter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

	//������setter/getter
	void SetRotate(const VECTOR _setRotate) { mRotate = _setRotate; }
};