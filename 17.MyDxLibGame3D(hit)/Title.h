#pragma once
#include "SceneBase.h"
#include "DxLib.h"

/// <summary>
/// �^�C�g���V�[���̃N���X
/// </summary>
class Title : public SceneBase
{
private:
	int mModel;        // ���C�����f��
	int mBallModel;    // �T�u���f��(����)
	int mBackGround;   // 3D�w�i
	int mTitleText;    // �^�C�g���e�L�X�g
	int mKeyText1[2];     // �L�[�w���P
	int mKeyText2[2];     // �L�[�w���Q
	int mPointGraph;      // �J�[�\��
	int mCount;           // �Z�x�J�E���g
	int mColorAlpha;      // �ǉ�����Z���̒l
	const int mFontSize;  // �����̑傫��

public:
	// �R���X�g���N�^
	Title();
	// �f�X�g���N�^
	virtual ~Title();
	// �`��
	void Draw(SceneBase& _scene);
	// �X�V
	void Update();
};