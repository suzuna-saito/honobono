#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "DxLib.h"

// �w�i�X�N���[���X�s�[�h(y��)
#define SCROLL_SPEED 0.25
// �w�i�g��X�s�[�h(z��)
#define EXPANSION_SPEED 0.3f

/// <summary>
/// �Q�[�����w�i�̃N���X
/// </summary>
class BackGround
{
public:
	/// <summary>
	/// �R���X�g���N�^ 
	/// </summary>
	BackGround();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~BackGround();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �X�N���[��
	/// </summary>
	void Scroll();

private:
	// �`����W
	VECTOR DrawPos;
	// 1���ڂ̍��WX
	float x1;
	// 1���ڂ̍��WY
	float y1;
	// 1���ڂ̍��WZ
	float z1;
	// 2���ڂ̍��WX
	float x2;
	// 2���ڂ̍��WY
	float y2;
	// 2���ڂ̍��WZ
	float z2;
	// �摜�̒��S���WX
	float cx;
	// �摜�̒��S���WY
	float cy;
	// �摜�̃T�C�Y
	float size;
	// 2���ڂ̉摜�̃T�C�Y
	float size2;
	// �A���O��
	float angle;
	// �w�i�̃n���h��
	int bg;
	// �X�N���[����MAX�̒l
	int scrMax;
	// �X�N���[���̍��W�̏�����
	float scrInitY;
	// �X�N���[���̍��WZ�̏�����
	float scrInitZ;
};

#endif // _BACKGROUND_H_