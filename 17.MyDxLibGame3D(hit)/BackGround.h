#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "DxLib.h"

#define SCROLL_SPEED 0.25     // �w�i�X�N���[���X�s�[�h(y��)
#define EXPANSION_SPEED 0.3f  // �w�i�g��X�s�[�h(z��)

class BackGround
{
public:
	// �R���X�g���N�^
	BackGround();

	// �f�X�g���N�^
	~BackGround();

	// �`��
	void Draw();

	// �X�N���[��
	void Scroll();

private:
	VECTOR DrawPos;   // �`����W
	float size;         // �T�C�Y
	int bg;           // �w�i�̃n���h��
};

#endif // _BACKGROUND_H_