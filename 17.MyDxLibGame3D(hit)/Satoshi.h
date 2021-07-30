#ifndef _SATOSHI_H_
#define _SATOSHI_H_

#include"DxLib.h"

class SceneBase;
class UIGoal;

class Satoshi
{
public:
	// �R���X�g���N�^
	Satoshi();
	// �f�X�g���N�^
	~Satoshi();
	
	// �X�V
	void Update(SceneBase& scene, UIGoal& uiGoal);
	void Draw();

	float GetPosY() { return PosY; }

private:
	VECTOR pos;             // �`����W
	VECTOR velocity;        // �ړ����x�x�N�g��
	int satoshiGraphHandle; // �摜�n���h��
	float size;               // �摜�T�C�Y
	float angle;            // �摜�̉�]�p�x
	float centerX, centerY; // �`�悷��摜�̒��S���W
	float hitRadius;
	float PosY;             // Y���W
};

#endif // !_SATOSHI_H_

