/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "UIGoal.h"

// �R���X�g���N�^
UIGoal::UIGoal()
	:UIBase(mGoalImg)
{
}

// �f�X�g���N�^
UIGoal::~UIGoal()
{

}

// �����̔䗦���o��
/*
* �K�v�����Ȃ̂ŊہX�c���Ă����܂�
*/
void UIGoal::GetDy(Player& _player, Satoshi& _satoshi)
{
	// ���̗����UI��GAME�̋����̔䗦���o�܂�
	// �ꉞ�ǂ��ł��Ăяo����悤�ɂ��邽�ߊ֐������܂���
	// Player��PosY��GetPosY�֐��̒ǉ�
	// Satoshi��PosY��GetPosY�֐��̒ǉ�
	// main�̂ق���SceneBase�����̌�ɌĂяo���Ă��܂�

	PosY1 = satoshi.GetPosY();
	PosY2 = player.GetPosY();

	MainPosY = PosY1 - PosY2;
	Dy = (UIPosY - 90) / MainPosY;

	// �摜���T�g�V��2D�A�s�J�`���E��3D�ł̕\��
	// �Q�[���̂ق��̈ʒu�\�����ς���Ă���̂ŁA���L�̌v�Z�ő��x�����������Ă܂�
	// �������ς������ς��Ă�������
	Dy *= 0.255f;

	// �T�g�V��Z���W�Ōv�Z���s���Ă��܂�(���������o�����ߌ���500�Ōv�Z���Ă܂�)
	// 	 �Q�[���̋��� = �T�g�VZ���W(PosY1) - �s�J�`���E��Y���W(PosY2)
	//   �����̔䗦 = UI�̃s�J�`���E��Y - UI�̃T�g�V��Y / �Q�[���̋���
	// �㉺�ړ��͍l���Ă��Ȃ��v�Z�ł�
	// ���Ԃ��Ȃ��̂ŁA�����܂łł��݂܂���
}

// �X�V���e
void UIGoal::Update()
{
}

// �`����e
void UIGoal::Draw()
{
}