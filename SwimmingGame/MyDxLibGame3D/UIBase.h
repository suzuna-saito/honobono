#ifndef _UIBASE_H_
#define _UIBASE_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/
#include <DxLib.h>

/// <summary>
/// UI�x�[�X�̃N���X
/// </summary>
class UIBase
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	UIBase(int _chara);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~UIBase();

	virtual void Update();    //�X�V�֐�
	virtual void Draw();    //�`��֐�

private:
};

#endif //_UIBASE_H_