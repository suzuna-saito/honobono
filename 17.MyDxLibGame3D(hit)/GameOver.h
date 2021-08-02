#pragma once
#include "DxLib.h"
#include "SceneBase.h"

/// <summary>
/// �Q�[���I�[�o�[�V�[���̃N���X
/// </summary>
class GameOver : public SceneBase
{
private:
	int mModel;               // ���f��
	int mBallModel;           // �T�u���f��
	int mOverText;            // �Q�[���I�[�o�[�e�L�X�g
	int mBackGround;          // 3D�w�i
	int mKeyText1[2];         // �L�[�w���P
	int mKeyText2[2];         // �L�[�w���Q
	int mPointGraph;          // �J�[�\��
	int mCount;	              // �Z�x�J�E���g
	int mColorAlpha;          // �ǉ�����Z���̒l
	const int mFontSize;      // �����̑傫��

public:
	// �R���X�g���N�^
	GameOver();
	// �f�X�g���N�^
	~GameOver();
	// �`��
	void Draw(SceneBase& _scene);
	// �X�V
	void Update();
};