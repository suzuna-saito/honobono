#pragma once
#include "SceneBase.h"
#include "DxLib.h"

class Title : public SceneBase
{
private:
	int Model;        // ���C�����f��
	int BallModel;    // �T�u���f��(����)
	int BackGround;   // 3D�w�i
	int TitleText;    // �^�C�g���e�L�X�g
	int KeyText1[2];     // �L�[�w���P
	int KeyText2[2];     // �L�[�w���Q
	int PointGraph;      // �J�[�\��
	int Count;           // �Z�x�J�E���g
	int ColorAlpha;      // �ǉ�����Z���̒l

public:
	// �R���X�g���N�^
	Title();
	// �f�X�g���N�^
	virtual ~Title();
	// �`��
	void Draw(SceneBase& scene);
	// �X�V
	void Update();
};