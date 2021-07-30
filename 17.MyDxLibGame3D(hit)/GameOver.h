#pragma once
#include "DxLib.h"
#include "SceneBase.h"

class GameOver : public SceneBase
{
private:
	int Model;         // ���f��
	int BallModel;     // �T�u���f��
	int OverText;      // �Q�[���I�[�o�[�e�L�X�g
	int BackGround;    // 3D�w�i
	int KeyText1[2];   // �L�[�w���P
	int KeyText2[2];   // �L�[�w���Q
	int PointGraph;    // �J�[�\��
	int Count;	       // �Z�x�J�E���g
	int ColorAlpha;    // �ǉ�����Z���̒l

public:
	// �R���X�g���N�^
	GameOver();
	// �f�X�g���N�^
	~GameOver();
	// �`��
	void Draw(SceneBase& scene);
	// �X�V
	void Update();
};