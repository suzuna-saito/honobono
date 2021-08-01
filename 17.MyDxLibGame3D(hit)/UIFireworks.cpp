#include "UIFireworks.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
UIFireworks::UIFireworks()
	: mDrawFlag(false)
	, mDrawFlag2(false)
	, mDrawFlag3(false)
	, mDrawPosX(POS_X)
	, mDrawPosY(POS_Y)
	, clearCount(0)
	, time(TIME)
{
	// �摜�ǂݍ���
	fireworksImg = LoadGraph("data/Asset/hanabi.png");
	fireworksImg2 = LoadGraph("data/Asset/hanabi2.png");
	fireworksImg3 = LoadGraph("data/Asset/hanabi3.png");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
UIFireworks::~UIFireworks()
{
	// �摜������������폜
	DeleteGraph(fireworksImg);
	DeleteGraph(fireworksImg2);
	DeleteGraph(fireworksImg3);
}

/// <summary>
/// �X�V
/// </summary>
void UIFireworks::Update()
{
	clearCount++;
	// ��ڂ̉ԉ�
	if (clearCount >= 1 && clearCount <= time / 3)
	{
		// 1�ڂ̉ԉΕ`��t���O���u�^�v�ɂ���
		mDrawFlag = true;
	}
	// ��ڂ̉ԉ�
	else if (clearCount >= TIME / 3 && clearCount <= time / 2)
	{
		// 1�ڂ̉ԉΕ`��t���O���u�U�v�ɂ���
		mDrawFlag = false;
		// 2�ڂ̉ԉΕ`��t���O���u�^�v�ɂ���
		mDrawFlag2 = true;
	}
	// �O�ڂ̉ԉ�
	else if (clearCount >= TIME / 2 && clearCount <= time - 1)
	{
		// 2�ڂ̉ԉΕ`��t���O���u�U�v�ɂ���
		mDrawFlag2 = false;
		// 3�ڂ̉ԉΕ`��t���O���u�^�v�ɂ���
		mDrawFlag3 = true;
	}
	else if (clearCount >= time)
	{
		// 3�ڂ̉ԉΕ`��t���O���u�U�v�ɂ���
		mDrawFlag3 = false;
	}
}

/// <summary>
/// �`��
/// </summary>
void UIFireworks::Draw()
{
	int x, y;		// DrawExtendGraph���g���ۂɈ����������₷�����邽�߂ɕϐ����쐬
	// 1�ڂ̉ԉΕ`��t���O����������
	if (mDrawFlag)
	{
		// �`��|�W�V�����̐ݒ�
		x = mDrawPosX - ADD_POS;
		y = mDrawPosY + ADD_POS;

		DrawExtendGraph(x, y, x + EXPANSION_X, y + EXPANSION_Y, fireworksImg, true);
	}
	// 2�ڂ̉ԉΕ`��t���O����������
	else if (mDrawFlag2)
	{
		// �`��|�W�V�����̐ݒ�
		x = mDrawPosX + ADD_POS;
		y = mDrawPosY - ADD_POS;

		DrawExtendGraph(x, y, x + EXPANSION_X, y + EXPANSION_Y, fireworksImg2, true);
	}
	// 3�ڂ̉ԉΕ`��t���O����������
	else if (mDrawFlag3)
	{
		// �`��|�W�V�����̐ݒ�
		x = mDrawPosX / 2;
		y = mDrawPosY / 2;

		DrawExtendGraph(x, y, x + EXPANSION3, y + EXPANSION3, fireworksImg3, true);
	}
}