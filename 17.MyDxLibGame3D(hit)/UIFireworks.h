#pragma once
#include <DxLib.h>
#include "UIBase.h"

const int POS_X = 150;		// X�̍��W
const int POS_Y = 100;		// Y�̍��W

const int ADD_POS = 150;		// �`��|�W�V�������������炷���߂̒l

const int EXPANSION_X = 230;// ��ڂƓ�ڂ̉ԉ΂̊g��lX
const int EXPANSION_Y = 250;// ��ڂƓ�ڂ̉ԉ΂̊g��lY
const int EXPANSION3 = 400;	// �O�ڂ̉ԉ΂̊g��l

const int TIME = 240;		// �ԉ΂��o���^�C�~���O(�ő�)

// �ԉ΂̕`��

class UIFireworks
{
public:
	UIFireworks();		// �R���X�g���N�^
	~UIFireworks();		// �f�X�g���N�^

	// _drawcount
	// �ԉ΂�`�悷��^�C�~���O��}�邽�߂̃J�E���g
	void Update();

	void Draw();

	int GetclearCount() { return clearCount; }
	const int time;				// �ԉ΂��o���^�C�~���O(�ő�)

private:
	int fireworksImg;		// �ԉ΂̉摜�ǂݍ���
	int fireworksImg2;		// �ԉ΂̉摜�ǂݍ���2
	int fireworksImg3;		// �ԉ΂̉摜�ǂݍ���3

	bool mDrawFlag;			// ��ڂ̉ԉ΂�`�悷�邩�ǂ���
	bool mDrawFlag2;		// ��ڂ̉ԉ΂�`�悷�邩�ǂ���
	bool mDrawFlag3;		// �O�ڂ̉ԉ΂�`�悷�邩�ǂ���

	const int mDrawPosX;		// �`�悳����|�W�V����X
	const int mDrawPosY;		// �`�悳����|�W�V����Y

	int clearCount;				// �N���A���Ă���������
};