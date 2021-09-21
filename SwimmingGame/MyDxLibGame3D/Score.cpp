#include "Score.h"

// �萔
const int RESULT_POS_X = 580;   // ���U���g�̎��̃X�R�A���㒸�_X
const int RESULT_POS_Y = 400;   // ���U���g�̎��̃X�R�A���㒸�_Y
const int RESULT_POS_02X = 780; // ���U���g�̎��̃X�R�A�E�����_���WX
const int RESULT_POS_02Y = 500; // ���U���g�̎��̃X�R�A�E�����_���WY

const int RESULT_NUM_X = RESULT_POS_02X+20;   // ���U���g�̎��̐������㒸�_���WX
const int RESULT_NUM_Y = RESULT_POS_Y;        // ���U���g�̎��̐������㒸�_���WY
const int RESULT_NUM_02Y = RESULT_POS_02Y;    // ���U���g�̎��̐����E�����_���WY

const int RESULT_NUM_SPACE = 100;             // ���U���g�̎��̐����̊Ԋu

/// <summary>
/// �R���X�g���N�^
/// </summary>
Score::Score()
{
	FONT_SIZE = 30;
	DIGIT_NUM = 5;
	NUM_POS = 110;
	NUM_SPACE = 40;
	i = j = 0;
	tmp = 0;
	mColor = GetColor(0, 0, 0);
	mScorePosX = 0;
	mScorePosY = 0;
	mResultPosX = RESULT_NUM_X;
	mScore = 0;
	mTmpScore = 0;
	mScoreFlag = false;
	NUMBER_NUM = 10;
	for (i = 0; i < DIGIT_NUM; i++)
	{
		mS[i] = 0;
	}

	LoadDivGraph("data/newUI/number.png", 10, 5, 2, 40, 50, mNumberHandle, true);
	mScoreHandle = LoadGraph("data/newUI/score.png", true);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Score::~Score()
{
}

/// <summary>
/// �X�R�A�`��
/// </summary>
void Score::Draw(int _nowScene)
{
	// �v���C�V�[���ƃ��U���g�V�[���ɂ���ĕ`�悷��傫����ς���
	switch (_nowScene)
	{
	case 2:   // �v���C�V�[��
		DrawGraph(mScorePosX, mScorePosY, mScoreHandle, true);
		for (i = 0; i < DIGIT_NUM; i++)
		{
			for (j = 0; j < NUMBER_NUM; j++)
			{
				if (mS[i] == j)
				{
					DrawGraph(NUM_POS + NUM_SPACE * i, mScorePosY, mNumberHandle[j], true);
				}
			}
		}
		break;

	case 4:   // ���U���g�V�[��
		DrawExtendGraph(RESULT_POS_X, RESULT_POS_Y, RESULT_POS_02X, RESULT_POS_02Y,
			mScoreHandle, true);

		NUM_SPACE = RESULT_NUM_SPACE;

		for (i = 0; i < DIGIT_NUM; i++)
		{
			for (j = 0; j < NUMBER_NUM; j++)
			{
				if (mS[i] == j)
				{
					DrawExtendGraph(mResultPosX + NUM_SPACE * i, RESULT_NUM_Y, mResultPosX + NUM_SPACE * i + NUM_SPACE, RESULT_NUM_02Y, mNumberHandle[j], true);
				}
			}
		}
		break;

	default:
		break;
	}
	
}

/// <summary>
/// �X�R�A�̌v�Z
/// </summary>
void Score::Update()
{
	mTmpScore = mScore;
	if (mScore <= 99900)
	{
		for (i = DIGIT_NUM - 1; i >= 0; i--)
		{
			mS[i] = mTmpScore % 10;
			tmp = mTmpScore % 10;
			mTmpScore = (mTmpScore - tmp) / 10;
		}
	}
}


/// <summary>
/// �X�R�A�̌v�Z�̊��������炤
/// </summary>
/// <param name="_BaseScore">�X�R�A�Ɋ|���銄��</param>
void Score::SetRadiusScore(int* _BaseScore)
{
	if (mScoreFlag)
	{
		mScore += *_BaseScore * 10;
		Update();
	}
}

/// <summary>
/// �X�R�A�t���O�����炤
/// </summary>
/// <param name="_ScoreFlag">�X�R�A�t���O</param>
void Score::SetScoreFlag(bool* _ScoreFlag)
{
	mScoreFlag = *_ScoreFlag;
}

/// <summary>
/// �v���C���̃X�R�A�����炤
/// </summary>
/// <param name="_Score">�v���C���̃X�R�A</param>
void Score::SetResultScore(int* _Score)
{
	mScore = *_Score;
	Update();
}
