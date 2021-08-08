#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/
#include "SceneBase.h"

/// <summary>
/// �Q�[���N���A���̃N���X
/// �V�[�P���X�x�[�X�����ɂ��č쐬
/// </summary>
class GameClear : public SceneBase
{
private:
	int Model;        // ���C�����f��
	int ClearText;    // �T�u���f��(����)
	int BackGround;   // 3D�w�i
	int KeyText1[2];// �L�[�w���P
	int KeyText2[2];// �L�[�w���Q
	int PointGraph;// �J�[�\��
	int Count;	   // �Z�x�J�E���g
	int ColorAlpha;// �ǉ�����Z���̒l

public:
	// �R���X�g���N�^
	GameClear();
	// �f�X�g���N�^
	~GameClear();
	// �`��֐�
	void Draw(SceneBase& scene);
	// �X�V�֐�
	void Update();
};

#endif //_GAMECLEAR_H_