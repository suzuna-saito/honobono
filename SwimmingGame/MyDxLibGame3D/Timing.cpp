// �C���N���[�h
#include "Timing.h"
#include "Input.h"
#include "Sound.h"
#include "Score.h"
#include <time.h>

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Timing::Timing()
	: mTimingDrawFlag(false)
	, mTimingFlag(false)
	, mReactionFlag(true)
	, mScoreFlag(false)
	, mGageX(50)
	, mGageY(350)
	, mGageCX(100)
	, mGageCY(400)
	, mFreamX(490)
	, mFreamY(180)
	, mRadius(70)
	, mGageRadius(20)
	, mRadiusInit(70)
	, mPerfectRadius(5)
	, mBadRadius(20)
	, mReactionX(520)
	, mReactionY(200)
	, mReactionCount(0)
	, mCountInit(0)
	, mReactionCountMax(50)
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
	, mCsvData(0)
	, mFilePointer(NULL)
	, mEffectAngle(0)
	, mEffectScale(1)
	, mEffectFlag(false)
	, mAngleRotate(15.0f * DX_PI_F / 180.0f)
	, mScalePlus(0.02)
	, mEffectImg(-1)
	, mCount(0.0f)
{
	// �摜�ǂݍ���
	mFreamImg = LoadGraph("data/newUI/frame.png");
	mPerfectEffectImg = LoadGraph("data/newUI/PerfectEffect.png");
	mGoodEffectImg = LoadGraph("data/newUI/GoodEffect.png");
	mBadEffectImg = LoadGraph("data/newUI/BadEffect.png");

	// �F
	 mBrack = GetColor(0, 0, 0);
	 mWhite = GetColor(255, 255, 255);

	// �T�E���h�̃��[�h
	mPerfectSound = new Sound("data/newSound/se/perfect.mp3");
	mGoodSound = new Sound("data/newSound/se/good.mp3");
	mBadSound = new Sound("data/newSound/se/bad.mp3");	

	mScorePtr = new Score();

	fopen_s(&mFilePointer, "data/csv/bgm_1.csv","r");
	CSVRead();
}


//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Timing::~Timing()
{
	// �T�E���h�f�[�^�̍폜
	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;
}


//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Timing::Update()
{
	// �J�E���g
	mCount++;
	// 
	mCountPack = mCount / 1000;

	// 
	if (mCountPack == mRhythm[i])
	{
		// �^�C�~���O�Q�[�W�`��t���O���u�^�v�ɂ���
		mTimingDrawFlag = true;
	}


	UpdateKey();
	// �Q�[�W���`�悳���t���O����������
	if (mTimingDrawFlag)
	{
		// �X�y�[�X�L�[����������^�C�~���O�t���O�A�X�R�A�t���O���u�^�v�ƂȂ�
		if (Key[KEY_INPUT_SPACE] == 1)
		{
			mTimingFlag = true;
			mScoreFlag = true;
		}
		if (!mReactionFlag)
		{
			// �J�E���g����������
			mReactionCount++;
		}
		if (mReactionFlag)
		{
			// �{�^����������^�C�~���O�t���O���u�^�v�ƂȂ�����
			if (mTimingFlag)
			{
				// �o�b�h�̏���
				if (mRadius - mGageRadius > mBadRadius)
				{
					// �G�t�F�N�g�摜���o�b�h�G�t�F�N�g�ɂ���
					mEffectImg = mBadEffectImg;
					// �G�t�F�N�g�t���O���u�^�v�ɂ���
					mEffectFlag = true;
					// �o�b�h�̌��ʉ��𗬂�
					mBadSound->PlaySE();
					// ���Ƀ��A�N�V�����𔻒肵�Ȃ�
					mReactionFlag = false;
				}
				// �O�b�h�̏���
				if (mRadius - mGageRadius >= mPerfectRadius && mRadius - mGageRadius <= mBadRadius)
				{
					// �G�t�F�N�g�摜���O�b�h�G�t�F�N�g�ɂ���
					mEffectImg = mGoodEffectImg;
					// �G�t�F�N�g�t���O���u�^�v�ɂ���
					mEffectFlag = true;
					// �O�b�h�̌��ʉ��𗬂�
					mGoodSound->PlaySE();
					// ���Ƀ��A�N�V�����𔻒肵�Ȃ�
					mReactionFlag = false;
				}
				// �p�[�t�F�N�g�̏���
				if (mRadius - mGageRadius < mPerfectRadius)
				{
					// �G�t�F�N�g�摜���p�[�t�F�N�g�G�t�F�N�g�ɂ���
					mEffectImg = mPerfectEffectImg;
					// �G�t�F�N�g�t���O���u�^�v�ɂ���
					mEffectFlag = true;
					// �p�[�t�F�N�g�̌��ʉ��𗬂�
					mPerfectSound->PlaySE();
					// ���Ƀ��A�N�V�����𔻒肵�Ȃ�
					mReactionFlag = false;
				}
			}
			// �^�C�~���O�t���O���u�U�v�ł���A�Q�[�W�̔��a���O�ɂȂ�����
			else if (!mTimingFlag && mRadius == 0)
			{
				// �G�t�F�N�g�摜���o�b�h�G�t�F�N�g�ɂ���
				mEffectImg = mBadEffectImg;
				// �G�t�F�N�g�t���O���u�^�v�ɂ���
				mEffectFlag = true;
				// �o�b�h�̌��ʉ��𗬂�
				mBadSound->PlaySE();
				// ���Ƀ��A�N�V�����𔻒肵�Ȃ�
				mReactionFlag = false;
			}
		}
		
		// ���A�N�V�����J�E���g���ő�l�ł͂Ȃ��Ƃ�
		if (!(mReactionCount < mReactionCountMax))
		{
			// �X�R�A�̌v�Z
			if (mScoreFlag)
			{
				int n;
				n = mRadiusInit - mRadius;
				mScorePtr->GetScore(&n);
				mScoreFlag = false;
			}
		}
		// ���A�N�V�����J�E���g���ő�l�𒴂�����
		if (mReactionCount == mReactionCountMax)
		{
			// �^�C�~���O�t���O���u�U�v�Ƃ���
			mTimingFlag = false;
			// �^�C�~���O�Q�[�W��`�悵�Ȃ�
			mTimingDrawFlag = false;
			// ���̃Q�[�W�p
			i++;
			// ���A�N�V�����𔻒�ł���悤�ɂ���
			mReactionFlag = true;
		}
		// �G�t�F�N�g�̃t���O���u�^�v�̂Ƃ�
		if (mEffectFlag)
		{
			// �G�t�F�N�g��傫�������Ȃ����]������
			mEffectScale += mScalePlus;
			mEffectAngle += mAngleRotate;
		}
	}

	// �Q�[�W���`�悳���t���O���u�U�v�ł�������
	if (!mTimingDrawFlag)
	{
		// ������
		mRadius = mRadiusInit;
		mReactionCount = mCountInit;
		mEffectScale = 1;

		// �t���O���u�U�v�ɂ���
		mTimingFlag = false;
		mEffectFlag = false;
	}
}


//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void Timing::Draw()
{
	// �p�[�t�F�N�g����̈ʒu�ƂȂ�Q�[�W�̕`��
	DrawCircle(mGageCX, mGageCY, mGageRadius, mWhite, TRUE);

	// �^�C�~���O�Q�[�W��`�悷��t���O���u�^�v�ƂȂ�����
	if (mTimingDrawFlag)
	{
		if (!mTimingFlag)
		{
			// ���a���O�ɂȂ�܂Ŏ��k
			if (mRadius > 0)
			{
				// ���k����Q�[�W�̕`��
				DrawCircle(mGageCX, mGageCY, mRadius--, mBrack, FALSE, 2);
			}
		}
	}
	
	// �G�t�F�N�g�̃t���O���u�^�v�̂Ƃ�
	if (mEffectFlag)
	{
		DrawRotaGraph(mGageCX, mGageCY, mEffectScale, mEffectAngle, mEffectImg, true, false, false);
	}
	// �Đ�����Ă��鉹�y�̎��Ԃ̊m�F�i�f�o�b�O�p�j
	DrawFormatString(0, 30, mWhite, "Time:%f", mCountPack);
	// �X�R�A��`��
	mScorePtr->Draw();
}


//-----------------------------------------------------------------------------
// @brief  CSV�f�[�^�̓ǂݍ���.
//-----------------------------------------------------------------------------
void Timing ::CSVRead()
{
	// �t�@�C���|�C���^�[��NULL�̎��f�o�b�O����߂�
	if (mFilePointer == NULL)
	{
		//�f�o�b�O���~
		DebugBreak();
	}
	//memset�֐��Ń�������buffer���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�
	memset(mBuffer, 0, sizeof(mBuffer));

	while (1)
	{
		while (1)
		{
			// fgetc�֐���filepointer���當����ǂ��csvData�Ɋi�[
			mCsvData = fgetc(mFilePointer);
			if (mCsvData == EOF)
			{
				// EndOfFile�����o����
				mEofFlag = true;
				// ���[�v�𔲂���
				break;
			}
			//��؂肩���s�łȂ����
			if (mCsvData != ',' && mCsvData != '\n')
			{
				//strcat_s�֐���buffer�ɘA�����Aconst char�֐��ŏ���������
				strcat_s(mBuffer, (const char*)&mCsvData);
			}
			else
			{
				// atof�֐���buffer��float�^�ɒ����āA���[�J���ϐ�num�ɑ��
				mNum = atof(mBuffer);
				mRhythm[mRawNum] = mNum;
				////////////////////////////////
				// num�ɖړI�̐������������̂ŉ�������
				// num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
				//cell[columnNum][rawNum] = num;
				////////////////////////////////
				// 
				// buffer�����Z�b�g
				memset(mBuffer, 0, sizeof(mBuffer));
				// ��؂肩���s�Ȃ̂Ń��[�v�𔲂���
				break;
			}
		}
		// 1�}�b�v���ɂȂ�����
		if (mEofFlag)
		{
			// ���[�v�𔲂���
			break;
		}
		// ��؂�����o������
		if (mCsvData == ',')
		{
			// ��̐��𑝂₷
			//columnNum++;
		}
		// ���s��������
		if (mCsvData == '\n')
		{
			// �s�𑝂₷
			mRawNum++;
			// ���0�ɂ���
			mColumnNum = 0;
		}
	}
	// �t�@�C�������
	fclose(mFilePointer);
}