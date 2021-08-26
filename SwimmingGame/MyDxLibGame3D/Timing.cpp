// �C���N���[�h
#include "Timing.h"
#include "Input.h"
#include "Sound.h"
#include "Score.h"

// �R���X�g���N�^
Timing::Timing()
	: TimingFlag(false)
	, PerfectFlag(false)
	, GoodFlag(false)
	, BadFlag(false)
	, ScoreFlag(false)
	, gageX(50)
	, gageY(350)
	, gageCX(100)
	, gageCY(400)
	, freamX(490)
	, freamY(180)
	, radius(radiusInit)
	, gageRadius(20)
	, radiusInit(70)
	, perfectRadius(5)
	, badRadius(20)
	, reactionX(520)
	, reactionY(200)
	, reactionCount(countInit)
	, countInit(0)
	, reactionCountMax(50)
	, mScore(0)
	, scoreMax(0)
	, scoreX(800)
	, scoreY(20)
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
	, filePointer(0)
	, csvData(0)
	, mEffectAngle(0)
	, mEffectScale(1)
	, mEffectFlag(false)
	, mAngleRotate(15.0f * DX_PI_F / 180.0f)
	, mScalePlus(0.02)
	, mEffectImg(-1)
{
	// �摜�ǂݍ���
	freamImg = LoadGraph("data/newUI/frame.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/good.png");
	badImg = LoadGraph("data/newUI/bad.png");
	goodImg = LoadGraph("data/newUI/good.png");
	badImg = LoadGraph("data/newUI/bad.png");
	mPerfectEffectImg = LoadGraph("data/newUI/PerfectEffect.png");
	mGoodEffectImg = LoadGraph("data/newUI/GoodEffect.png");
	mBadEffectImg = LoadGraph("data/newUI/BadEffect.png");

	// �F
	 brack = GetColor(0, 0, 0);
	 white = GetColor(255, 255, 255);

	 NormalGageColor = GetColor(255, 255, 255);
	 mPushGageColor = GetColor(0, 255, 255);

	// �T�E���h�̃��[�h
	mPerfectSound = new Sound("data/newSound/se/perfect.mp3");
	mGoodSound = new Sound("data/newSound/se/good.mp3");
	mBadSound = new Sound("data/newSound/se/bad.mp3");	

	mScorePtr = new Score();
}

// �f�X�g���N�^
Timing::~Timing()
{
	// �摜�f�[�^�폜
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);

	// �T�E���h�f�[�^�̍폜
	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;

	// CSV�f�[�^�̍폜
	delete csv;
}

// �X�V
void Timing::Update()
{
	UpdateKey();

	// �X�y�[�X�L�[����������^�C�~���O�t���O���u�^�v�ƂȂ�
	if (Key[KEY_INPUT_SPACE] == 1)
	{
		TimingFlag = true;
		ScoreFlag = true;
	}
	// �{�^����������^�C�~���O�t���O���u�^�v�ƂȂ�����
	if (TimingFlag)
	{
		mGageColor = mPushGageColor;

		// �J�E���g����������
		reactionCount++;
		// �o�b�h�̏���
		if (radius - gageRadius > badRadius)
		{
			mEffectImg = mBadEffectImg;
			mEffectFlag = true;
			// �o�b�h�̌��ʉ��𗬂�
			mBadSound->PlaySE();
			// �o�b�h�t���O���u�^�v�ɂ���
			BadFlag = true;
		}
		// �O�b�h�̏���
		else if (radius - gageRadius >= perfectRadius && radius - gageRadius <= badRadius)
		{
			mEffectImg = mGoodEffectImg;
			mEffectFlag = true;
			// �O�b�h�̌��ʉ��𗬂�
			mGoodSound->PlaySE();
			// �O�b�h�t���O���u�^�v�ɂ���
			GoodFlag = true;
		}
		// �p�[�t�F�N�g�̏���
		else if (radius - gageRadius < perfectRadius)
		{
			mEffectImg = mPerfectEffectImg;
			mEffectFlag = true;
			// �p�[�t�F�N�g�̌��ʉ��𗬂�
			mPerfectSound->PlaySE();
			// �p�[�t�F�N�g�t���O���u�^�v�ɂ���
			PerfectFlag = true;
		}
		// ���A�N�V�����J�E���g���ő�l�ł͂Ȃ��Ƃ�
		if (!(reactionCount < reactionCountMax))
		{
			// �X�R�A�̌v�Z
			// ���a�̍ő�l���猻�݂̔��a�������o���A���̍��ɃX�R�A���炢�̐������|����
			int n = 0;
			n = radiusInit - radius;
			scoreMax = n * 10;
			mScore = scoreMax + mScore;
	
			if (ScoreFlag)
			{
				int n;
				n = radiusInit - radius;
				mScorePtr->GetScore(&n);
				ScoreFlag = false;
			}
			// ����ȊO�̏ꍇ�̓^�C�~���O�t���O���u�U�v�Ƃ���
			TimingFlag = false;
		}
	}
	// �^�C�~���O�t���O���u�U�v�ł���Ƃ�
	if (!TimingFlag)
	{
		mGageColor = NormalGageColor;
		// �J�E���g������������
		reactionCount = countInit;
		// �t���O���u�U�v�ɂ���
		BadFlag = false;
		GoodFlag = false;
		PerfectFlag = false;

		mEffectFlag = false;
		mEffectScale = 1;
	}

	if (mEffectFlag)
	{
		mEffectScale += mScalePlus;
		mEffectAngle += mAngleRotate;
	}
}

// �`��
void Timing::Draw()
{
	// ���A�N�V��������̃t���[���̕`��
	DrawGraph(freamX, freamY, freamImg, TRUE);

	// �p�[�t�F�N�g����̈ʒu�ƂȂ�Q�[�W�̕`��
	DrawCircle(gageCX, gageCY, gageRadius, white, TRUE);

	//DrawCircle(gageCX + (1 * movebutton), gageCY, gageRadius, mGageColor, TRUE);

	if (mEffectFlag)
	{
		DrawRotaGraph(gageCX, gageCY, mEffectScale, mEffectAngle, mEffectImg, true, false, false);
	}


	// �{�^����������Ă��Ȃ��ꍇ���[�v��������
	if(!TimingFlag)
	{
		// ���a���O�ɂȂ�܂Ŏ��k������
		if(radius > 0)
		{
			// ���k����Q�[�W�̕`��
			DrawCircle(gageCX, gageCY, radius--, brack, FALSE);
		}
		else
		{
			// ���a�̑傫����������
			radius = radiusInit;
		}
	}
	// �{�^���������ꂽ��
	if (TimingFlag)
	{
		// �J�E���g���ő�l�ɂȂ�܂ŕ`��
		if (reactionCount < reactionCountMax)
		{
			// �o�b�h�t���O����������`�悷��
			if (BadFlag)
			{
				DrawGraph(reactionX, reactionY, badImg, TRUE);
			}
			// �O�b�h�t���O����������`�悷��
			if (GoodFlag)
			{
				DrawGraph(reactionX, reactionY, goodImg, TRUE);
			}
			// �p�[�t�F�N�g�t���O����������`�悷��
			if (PerfectFlag)
			{
				DrawGraph(reactionX, reactionY, perfectImg, TRUE);
			}
			// �Q�[�W���~�߂�
			DrawCircle(gageCX, gageCY, radius, brack, FALSE);
		}
	}
	else
	{
		// �Q�[�W��\�����Ȃ�
	}

	mScorePtr->Draw();

	// �X�R�A�̉�ʂ�\������
	DrawFormatString(scoreX, scoreY, white, "score : %d", mScore);
}

void Timing ::CSVRead()
{
	// �t�@�C���|�C���^�[��NULL�̎��f�o�b�O����߂�
	if (filePointer == NULL)																			//filePointer����̏ꍇ��
	{
		DebugBreak();																//�f�o�b�O���~
	}
	// �t�@�C���̒��̐��l��ǂݍ���
	while ((csvData = fgetc(filePointer)) != EOF)
	{
		// BGM���Đ����ꂽ���Ԃ�CSV�̒��̐��l����������
		//    �Q�[�W���p�[�t�F�N�g�̈ʒu�ɂ���悤�ɂ�����
		
	}

	// �t�@�C�������
	fclose(filePointer);
}
