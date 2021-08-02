#pragma once
#include "SceneBase.h"
#include "DxLib.h"

/// <summary>
/// �Q�[���N���A�V�[���̃N���X
/// </summary>
class GameClear : public SceneBase
{
private:
	int mModel;                 // ���C�����f��
	int mClearText;             // �T�u���f��(����)
	int mBackGround;            // 3D�w�i
	int mKeyText1[2];           // �L�[�w���P
	int mKeyText2[2];           // �L�[�w���Q
	int mPointGraph;            // �J�[�\��
	int mCount;	                // �Z�x�J�E���g
	int mColorAlpha;            // �ǉ�����Z���̒l
	const int mFontSize;        // �����̑傫��

public:
	// �R���X�g���N�^
	GameClear();
	// �f�X�g���N�^
	~GameClear();
	// �`��
	void Draw(SceneBase& _scene);
	// �X�V
	void Update();
};