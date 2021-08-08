#ifndef _TITLE_H_
#define _TITLE_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/
#include "SceneBase.h"

/// <summary>
/// �^�C�g���V�[���N���X
/// �V�[�P���X�x�[�X�����ɂ��č쐬
/// </summary>
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

#endif //_TITLE_H_