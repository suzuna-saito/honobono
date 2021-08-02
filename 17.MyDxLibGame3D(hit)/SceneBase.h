#pragma once
#include "DxLib.h"

class Camera;
class UIGoal;
class Player;
class Title;
class Fade;

/// <summary>
/// �V�[���J�ڂ̊�{�N���X
/// </summary>
class SceneBase
{
protected:
	int mIsScene;          // ���݂̃V�[��
	int mReturn;            // �^�C�g���ւ��I�����ꂽ
	int mEnd;               // �Q�[���I�����I�����ꂽ
	int mStart;             // �Q�[���X�^�[�g���I�����ꂽ
	int mPointPosition;     // �J�[�\���ʒu
	float mMove;            // �L�����̓���
	float mSize;            // �L�����̑傫��
	float mSizePoint;       // �傫����ς���l
	bool mFadeFlag;         // �t�F�[�h���Ă��邩
	const int mUp;
	const int mDown;

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
	void ChangeScene(UIGoal& _uiGoal, Player& _player);

	// ���݂̃V�[����Ԃ�
	int GetScene() { return mIsScene; }

	// _isScene ���݂̃V�[��
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// �J�[�\���ʒu�X�V
    void PointUpdate();

	// �l��n��
	int GetStartPoint() { return mStart; }
	int GetEndPoint() { return mEnd; }
	int GetReturnPoint() { return mReturn; }
	int GetPointPosition() { return mPointPosition; }

	bool GetChangeFlag() { return mChangeFlag; }
	void SetChangeFlag(bool _change) { mChangeFlag = _change; }

	bool GetShutDownFlag() { return mShutDownFlag; }

private:

	bool mChangeFlag;

	bool mShutDownFlag;


};
