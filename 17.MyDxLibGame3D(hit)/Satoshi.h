#ifndef _SATOSHI_H_
#define _SATOSHI_H_

#include"DxLib.h"
#include "UIBase.h"

class SceneBase;
class UIGoal;

/// <summary>
/// �S�[���n�_�ɃT�g�V��`�悷��N���X
/// </summary>
class Satoshi : UIBase
{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Satoshi();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Satoshi();
	
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="scene"> �Q�[���V�[���ɓ����Ă���`�悷�邽�� </param>
    /// <param name="uiGoal"> �v���C���[�Ƃ̋����𑪂邽�� </param>
	void Update(UIGoal& _uiGoal);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �T�g�V�̍��WY���擾 
	/// </summary>
	/// <returns>�T�g�V�̍��W��Ԃ�</returns>
	float GetPosY() { return posY; }

private:
	// �`����W
	VECTOR pos;
	// �ړ����x�x�N�g��
	VECTOR velocity;
	// ���WX
	float x;
	// ���WY
	float y;
	// ���WZ
	float z;        
	// �ړ�����Ƃ��̍��WX
	float veloX;            
	// �ړ�����Ƃ��̍��WY
	float veloY;
	// �ړ�����Ƃ��̍��WZ
	float veloZ;
	// �摜�n���h��
	int satoshiImg;
	// �摜�T�C�Y
	float size;
	// �摜�̉�]�p�x
	float angle; 
	// �摜�̒��S���WX
	float centerX;
	// �摜�̒��S���WY
	float centerY;
	//float hitRadius;
	// Y���W
	float posY;
	// Y���W��Max�l
	float posMax;

};

#endif // !_SATOSHI_H_

