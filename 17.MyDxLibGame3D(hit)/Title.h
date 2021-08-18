#pragma once
#include "DxLib.h"
#include "Camera.h"

/// <summary>
/// �^�C�g���N���X
/// </summary>
class Title
{
private:
	int i;
	int mAlpha;                            // �J�[�\���A���t�@�l
	int mTextAlpha;						   // �e�L�X�g�A���t�@�l
	int mCount;							   // �J�[�\���A���t�@�l�J�E���g
	int mTextCount;						   // �e�L�X�g�A���t�@�l
	int mCursorPoint;					   // �J�[�\���ʒu
	bool mEndFlag;						   // �I���t���O

	int mBackGroundGraph;                  // �w�i�摜
	int mFishModel;						   // �����f��
	int mTextModel[3];					   // �e�L�X�g���f��
	int mTextTexture;					   // �e�N�X�`��
	int mCursor;						   // �J�[�\���摜

	VECTOR mFishPos[2];                    // ���̈ʒu
	VECTOR mTextPos[3];					   // �e�L�X�g�̈ʒu

	int mBackPosX;						   // �w�i���WX
	int mBackPosY;						   // �w�i���WY

	VECTOR mFishRotate[2];				   // ���̉�]�p�x

	VECTOR mFishSize[2];                   // ���̃T�C�Y
	VECTOR mTextSize[3];				   // �e�L�X�g�̃T�C�Y
	VECTOR mCursorPos;					   // �J�[�\���ʒu

	const float POINT_X, POINT_Y;		   // 3D�摜�̒��S
	const float SIZE;					   // 3D�摜�̃T�C�Y
	const float ANGLE;					   // 3D�摜�̊p�x

	const int FISH_NUM;                    // ���̐�
	const int TEXT_NUM;					   // �e�L�X�g�̐�
	const int BACK_EXTEND_X;			   // �w�i�̊g��X
	const int BACK_EXTEND_Y;			   // �w�i�̊g��Y
	const float CURSOR_SIZE;			   // �J�[�\���T�C�Y
	const float CURSOR_ANGLE;			   // �J�[�\���p�x

	const int GAME_START;				   // �Q�[���X�^�[�g
	const int EXIT;						   // �I��
	const int ALPHA_MAX_POINT;			   // �A���t�@�l�̍ő�l
	const int ALPHA_MIN_POINT;			   // �A���t�@�l�̍ŏ��l
	const int FONT_SIZE;				   // �����̃T�C�Y


	float mJympPower[2];                   // �W�����v��
	float mGravity;                        // �d��
	bool mJympFlag[2];                     // �W�����v�t���O
	float mKeepPower;                      // �W�����v�ʃ����_���l�Z�b�g�ϐ�

public:
	// �R���X�g���N�^
	Title();
	// �f�X�g���N�^
	virtual ~Title();

	// �^�C�g���V�[��
	void TitleScene();
	// �X�V
	void Update();
	// �`��
	void Draw();

	// ���̋���
	void FishMove();

	// �l��n��
	bool GetEndFlag() { return mEndFlag; }
};

