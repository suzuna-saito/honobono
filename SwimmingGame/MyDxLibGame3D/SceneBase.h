#pragma once
#include "DxLib.h"

/// <summary>
/// �V�[���̊��N���X
/// </summary>
class SceneBase
{
public:
	// �R���X�g���N�^
	SceneBase();

	// �f�X�g���N�^
	~SceneBase();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	virtual SceneBase* Update();

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void Draw();

	// �J�[�\���ʒu�X�V
	void PointUpdate();

	// �V�[���̎��
	enum Scene
	{
		// �^�C�g��
		title,
		// �Q�[���v���C
		play,
		// �Q�[���N���A
		gameClear,
		// �Q�[���I�[�o�[
		gameOver,
		// �Q�[���I��
		gameEnd
	};

private:
	bool mShutDownFlag;

protected:
	int mIsScene;          // ���݂̃V�[��

	int mEnd;               // �Q�[���I�����I�����ꂽ
	int mStart;             // �Q�[���X�^�[�g���I�����ꂽ
	int mPointPosition;     // �J�[�\���ʒu
	float mMove;            // �L�����̓���
	float mSize;            // �L�����̑傫��
	float mSizePoint;       // �傫����ς���l
	const int mFontSize;    // �����̑傫��
	const int mUp;
	const int mDown;

	int mModel;        // ���C�����f��
	int mBallModel;    // �T�u���f��(����)
	int mBackGround;   // 3D�w�i
	int mKeyText1[2];     // �L�[�w���P
	int mKeyText2[2];     // �L�[�w���Q
	int mPointGraph;      // �J�[�\��
	int mCount;           // �Z�x�J�E���g
	int mColorAlpha;      // �ǉ�����Z���̒l
	int mReturn;            // �^�C�g���ւ��I�����ꂽ
//	bool mFadeFlag;         // �t�F�[�h���Ă��邩


public: // �Q�b�^�[�A�Z�b�^�[

	/// <summary>
	/// �V�[�����擾
	/// </summary>
	/// <returns>���݂̃V�[����Ԃ�</returns>
	int GetScene() { return mIsScene; }

	/// <summary>
	/// �V�[�����Z�b�g����
	/// </summary>
	/// <param name="_isScene">���݂̃V�[��</param>
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// �l��n��
	int GetStartPoint() { return mStart; }
	int GetReturnPoint() { return mReturn; }
	int GetEndPoint() { return mEnd; }
	int GetPointPosition() { return mPointPosition; }
};
