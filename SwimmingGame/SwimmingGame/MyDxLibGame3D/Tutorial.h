#pragma once
#include "SceneBase.h"

class Tutorial : public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Tutorial();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Tutorial();

	/// <summary>
	/// �`���[�g���A���V�[���̍X�V
	/// </summary>
	SceneBase* Update()override;

	/// <summary>
	/// �e�L�X�g�̍X�V
	/// </summary>
	void TextUpdate();


	/// <summary>
	/// �`���[�g���A���V�[���̕`��
	/// </summary>
	void Draw()override;

private:
	//  �w�i
	// �w�i�摜
	int mBackGroundGraph; 
	// �w�i���WX
	int mBackPosX;
	// �w�i���WY
	int mBackPosY;
	// �w�i�̊g��X
	const int BACK_EXTEND_X;
	// �w�i�̊g��Y
	const int BACK_EXTEND_Y;

	//  �`���[�g���A��
	// �`���[�g���A���摜
	int mTutorialGraph;
	// �`���[�g���A�����WX
	int mTutorialkPosX;
	// �`���[�g���A�����WY
	int mTutorialPosY;
	// �`���[�g���A���̊g��X
	const int TUTORIAL_EXTEND_X;
	// �`���[�g���A���̊g��Y
	const int TUTORIAL_EXTEND_Y;


	//  �e�L�X�g
	// �X�^�[�g�e�L�X�g
	int mStartText;
	// �X�^�[�g�e�L�X�g�̍��WX
	int mStartTextPosX;
	// �X�^�[�g�e�L�X�g�̍��WY
	int mStartTextPosY;
	// �X�^�[�g�e�L�X�g�A���t�@�l
	int mStartTextAlpha;
	// �X�^�[�g�e�L�X�g�A���t�@�l�J�E���g
	int mStartTextCount;
	// �A���t�@�l�̍ő�l
	const int ALPHA_MAX_POINT;
	// �A���t�@�l�̍ŏ��l
	const int ALPHA_MIN_POINT;
	// �X�L�b�v�e�L�X�g
	int mSkipText;
	// �X�L�b�v�e�L�X�g�̍��WX
	int mSkipTextPosX;
	// �X�L�b�v�e�L�X�g�̍��WX
	int mSkipTextPosY;
	// �X�L�b�v�e�L�X�g���`�悳���t���O
	bool mSkipDrawFlag;


	//  ���ԃQ�[�W
	// �Q�[�W��\�����鎞��
	int mTime;
	// �Q�[�W��\�����鎞�Ԃ̍ő�l
	int mTimeMax;
	// �X�L�b�v�e�L�X�g��`�悷�鎞��
	int mSkipDrawTime;
	// �Q�[�W�̐F
	int mWhite;
	// �Q�[�W�̍��WX1
	int mGageX1;
	// �Q�[�W�̍��WY
	int mGageY1;
	// �Q�[�W�̍��WX2
	int mGageX2;
	// �Q�[�W�̍��WY2
	int mGageY2;



	//  �T�E���h
	// �`���[�g���A����BGM
	class Sound* mTutorialBGM;
	// �`���[�g���A���̌��ʉ�
	class Sound* mTutorialSE;

	class Camera* camera;

	class Time* time;


};

