#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "DxLib.h"

/// <summary>
/// �w�i�N���X
/// </summary>
class BackGround
{
public:
	// �R���X�g���N�^
	BackGround();

	// �f�X�g���N�^
	~BackGround();

	// �X�V�֐�
	/*
	* ����(�X�N���[�������铙)�̂ł���΂�����
	*/
	void Update();

	// �`��
	void Draw();


private:
	VECTOR mDrawPos;   // �`����W
	float mSize;         // �T�C�Y
	int mBackGroundImage;    // �w�i�̃n���h��
};

#endif // _BACKGROUND_H_