#pragma once
#include "DxLib.h"

class Camera;
class UIGoal;
class Player;
class Title;
class Fade;

class SceneBase
{
protected:
	int mIsScene;          // ���݂̃V�[��
	int Return;            // �^�C�g���ւ��I�����ꂽ
	int End;               // �Q�[���I�����I�����ꂽ
	int Start;             // �Q�[���X�^�[�g���I�����ꂽ
	int PointPosition;     // �J�[�\���ʒu
	float Move;            // �L�����̓���
	float Size;            // �L�����̑傫��
	float SizePoint;       // �傫����ς���l
	bool FadeFlag;

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
	void ChangeScene(UIGoal& uiGoal, Player& player);

	// ���݂̃V�[����Ԃ�
	int GetScene() { return mIsScene; }

	// _isScene ���݂̃V�[��
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// �J�[�\���ʒu�X�V
    void PointUpdate();

	// �l��n��
	int GetStartPoint() { return Start; }
	int GetEndPoint() { return End; }
	int GetReturnPoint() { return Return; }
	int GetPointPosition() { return PointPosition; }

	bool GetChangeFlag() { return mChangeFlag; }
	void SetChangeFlag(bool _change) { mChangeFlag = _change; }

	bool GetShutDownFlag() { return mShutDownFlag; }

private:

	bool mChangeFlag;

	bool mShutDownFlag;


};
