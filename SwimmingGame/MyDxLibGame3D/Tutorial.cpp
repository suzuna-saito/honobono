#include "Tutorial.h"
#include "Play.h"
#include "Camera.h"
#include "Sound.h"
#include "Time.h"
#include "Input.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Tutorial::Tutorial()
	: mStartTextAlpha(0)
	, mStartTextCount(6)
	, ALPHA_MAX_POINT(255)
	, ALPHA_MIN_POINT(0)
	, mBackPosX(0)
	, mBackPosY(0)
	, BACK_EXTEND_X(700)
	, BACK_EXTEND_Y(600)
	, mTutorialkPosX(80)
	, mTutorialPosY(130)
	, TUTORIAL_EXTEND_X(570)
	, TUTORIAL_EXTEND_Y(400)
	, mTime(1000)
	, mTimeMax(1000)
	, mGageX1(50)
	, mGageX2(600)
	, mGageY1(100)
	, mGageY2(130)
	, mStartTextPosX(15)
	, mStartTextPosY(25)
	, mSkipTextPosX(100)
	, mSkipTextPosY(150)
	, mSkipDrawTime(950)
	, mSkipDrawFlag(false)
	, mSkipFlag(false)
{
	// �V�[���ύX
	SetScene(tutorial);

	camera = new Camera();

	// �e�L�X�g�摜�̃��[�h
	mStartText = LoadGraph("data/model/TutorialAsset/startText.png");
	mSkipText = LoadGraph("data/model/TutorialAsset/skipText.png");

	// �摜�̃��[�h
	mBackGroundGraph = LoadGraph("data/model/TutorialAsset/tutorialBack.png");
	mTutorialGraph = LoadGraph("data/model/TutorialAsset/tutorial.png");

	// �T�E���h�̃��[�h
	mTutorialBGM = new Sound("data/newSound/bgm/tutorial.mp3");
	mTutorialSE = new Sound("data/newSound/se/tutorialSE.mp3");

	// �Q�[�W�̐F�̐ݒ�
	mWhite = GetColor(255, 255, 255);

	// BGM�̍Đ�
	mTutorialBGM->PlayBGM();

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Tutorial::~Tutorial()
{
	// �摜�̍폜
	DeleteGraph(mTutorialGraph);
	DeleteGraph(mBackGroundGraph);
	DeleteGraph(mStartText);
	DeleteGraph(mSkipText);
	// �T�E���h�f�[�^�̍폜
	mTutorialBGM->StopMusic();
	delete mTutorialBGM;
	delete mTutorialSE;
}


/// <summary>
/// �X�V
/// </summary>
SceneBase* Tutorial::Update()
{
	// ���Ԃ����炷
	mTime--;
	UpdateKey();
	// �V�[���J�ڂ̏���
	if (mSkipFlag || mTime < 0)
	{
		// �`���[�g���A����BGM���~�߂�
		mTutorialBGM->StopMusic();
		// ���ʉ����Đ�
		mTutorialSE->PlaySE();
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new Play();
	}

	TextUpdate();

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

void Tutorial::TextUpdate()
{
	// �X�L�b�v����
	if (mTime < mSkipDrawTime)
	{
		mSkipDrawFlag = true;

		// �X�L�b�v�̕������`�悳��Ă���Ƃ��ɃX�y�[�X�������ꂽ��
		if (Key[KEY_INPUT_SPACE] == 1)
		{
			mSkipFlag = true;  // �V�[���J�ڃt���O��true�ɂ���
		}
	}

	// �摜�̓����x��ύX
	if (mStartTextAlpha > ALPHA_MAX_POINT)
	{
		mStartTextCount *= -1;
	}
	else if (mStartTextAlpha < ALPHA_MIN_POINT)
	{
		mStartTextCount *= -1;
	}

	mStartTextAlpha += mStartTextCount;
}

	

/// <summary>
/// �`��
/// </summary>
void Tutorial::Draw()
{
	// �w�i�`��
	DrawGraph(mBackPosX, mBackPosY, mBackGroundGraph, TRUE);
	// �`���[�g���A���摜�̕`��
	//DrawExtendGraph(mTutorialkPosX, mTutorialPosY,
		//TUTORIAL_EXTEND_X, TUTORIAL_EXTEND_Y, mTutorialGraph, TRUE);

	// �e�L�X�g�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mStartTextAlpha);
	DrawGraph(mSkipTextPosX, mStartTextPosY, mStartText, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mStartTextAlpha);


	if (mSkipDrawFlag)
	{
		// �X�L�b�v�e�L�X�g�̕`��
		DrawGraph(mSkipTextPosX, mSkipTextPosY, mSkipText, TRUE);

	}

	//�g��`��
	DrawBox(mGageX1, mGageY1, mGageX1 + mGageX2, mGageY2, mWhite, FALSE);
	//���ԃQ�[�W��`��
	DrawBox(mGageX1, mGageY1, mGageX1 + mGageX2 * mTime / mTimeMax, mGageY2, mWhite, TRUE);

}