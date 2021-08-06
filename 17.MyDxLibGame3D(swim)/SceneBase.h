#ifndef _SCENEBASE_H_
#define _SCENEBASE_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/
#include "DxLib.h"

/// <summary>
/// �V�[�P���X�x�[�X�N���X
/// </summary>
class SceneBase
{
public:
	// �R���X�g���N�^
	SceneBase();

	// �f�X�g���N�^
	virtual ~SceneBase();

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

	// �V�[����ς���
	void ChangeScene();

	// ���݂̃V�[����Ԃ�
	int GetScene() { return mIsScene; }

	// _isScene ���݂̃V�[��
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// �J�[�\���ʒu�X�V
    void PointUpdate();

	// ���̎��̂��ꂼ��̕ϐ��̒l��Ԃ�
	int GetStartPoint() { return mStart; }
	int GetEndPoint() { return mEnd; }
	int GetReturnPoint() { return mReturn; }
	int GetPointPosition() { return mPointPosition; }

	//mChangeFlag��setter/getter
	bool GetChangeFlag() { return mChangeFlag; }
	void SetChangeFlag(bool _change) { mChangeFlag = _change; }

	bool GetShutDownFlag() { return mShutDownFlag; }

protected:
	int mIsScene;          // ���݂̃V�[��
	int mReturn;            // �^�C�g���ւ��I�����ꂽ
	int mEnd;               // �Q�[���I�����I�����ꂽ
	int mStart;             // �Q�[���X�^�[�g���I�����ꂽ
	int mPointPosition;     // �J�[�\���ʒu
	float mMove;            // �L�����̓���
	float mSize;            // �L�����̑傫��
	float mSizePoint;       // �傫����ς���l

	bool mFadeFlag;

private:

	bool mChangeFlag;
	bool mShutDownFlag;
};

#endif //_SCENEBASE_H_