#pragma once
#include "Title.h"
#include "Play.h"
#include "Result.h"

// ���ꂼ��̃V�[���N���X��錾
class Title;
class Play;
class Result;

/// <summary>
/// SceneBase�N���X
/// </summary>
class SceneBase : public Title, public Play, public Result
{
private:
	bool mEndFlag;               // �Q�[���I���t���O

public:
	// �R���X�g���N�^
	SceneBase();
	// �f�X�g���N�^
	~SceneBase();

	// �Q�[��
	void Game();
};

