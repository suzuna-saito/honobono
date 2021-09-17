#ifndef _FISHBASE_H_
#define _FISHBASE_H_

//�O���錾
#include "DxLib.h"

/// <summary>
/// FishBase�N���X
/// </summary>
class FishBase
{
public:
	FishBase(int _sourceModelHandle);	// �R���X�g���N�^

	virtual ~FishBase();										// �f�X�g���N�^

	virtual void Updata(int _judge) = 0;									// �X�V�֐�(�������z�֐�)

	virtual void Draw(int _debugColor);							// �`��֐�

	/*----���ꂼ���setter / getter -----*/

	int GetModelHandle() { return mModelHandle; }				//���f���n���h���̎擾

	//�|�W�V������setter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

	//������setter/getter
	void SetRotate(const VECTOR _setRotate) { mRotate = _setRotate; }
	const VECTOR& GetRotate()const { return mRotate; }

	//�A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̍��W��getter
	const VECTOR& GetDancePos()const { return mSetDancePos; }

	//�_���X�W�����̃|�W�V�����ɂ���Ƃ��̃t���O��getter
	const bool GetSetDancePosFlag() { return mSetDanceFlag; }


	enum MoveState
	{
		NowMove,            //�������Ă���
		NotMove,            //�����Ă��Ȃ�
	};


protected:

	int		mModelHandle;		// ���f���n���h���ϐ� 

	VECTOR	mPos;				// ���W
	VECTOR	mVelocity;			// ���ۂɈړ�����ړ��x�N�g��
	VECTOR  mTempVelocity;      // ���̈ړ��x�N�g��
	VECTOR	mRotate;			// ���f���������Ă���p�x
	VECTOR	mSetDancePos;		//�V���N�����ł������|�W�V����

	MoveState mMoveState;     //�ړ����Ă��邩�ǂ����̃X�e�[�^�X
	bool mSetDanceFlag;   //�A�[�e�B�X�e�B�b�N�X�C�~���O���n�߂��鎞��true�A�n�܂�Ȃ��Ƃ���false

	int mDanceStartCount;
};

#endif // !_FISHBASE_H_