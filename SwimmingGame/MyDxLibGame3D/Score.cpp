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
const int DRAW_PLUS_SCORE = 50;               // ���Z�l�X�R�A�̕`�掞��

/// <summary>
/// �R���X�g���N�^
/// </summary>
Score::Score()
{
	FONT_SIZE = 30;
	DIGIT_NUM = 5;
	NUM_POS = 220;
	NUM_SPACE = 80;
	mScoreBarPosY = 50;
	mNumPosY = 30;
	i = j = 0;
	tmp = 0;
	mColor = GetColor(0, 0, 0);
	mScorePosX = 50;
	mScorePosY = 80;
	mResultPosX = RESULT_NUM_X;
	mScore = 0;
	mTmpScore = 0;
	mScoreFlag = false;
	NUMBER_NUM = 10;
	mPlusScore = 0;
	mPlusPosX = 300;
	mPlusPosY = 170;
	mScoreCount = 0;
	mPlusNumPosX = 380;
	mPlusNumPosY = 200;
	mPlusNumSpace = 60;
	mDrawPlusNum = false;

	for (i = 0; i < DIGIT_NUM; i++)
	{
		mS[i] = 0;
	}

	for (i = 0; i < DIGIT_NUM - 1; i++)
	{
		mPlusS[i] = 0;
	}

	LoadDivGraph("data/newUI/number.png", 10, 5, 2, 80, 100, mNumberHandle, true);
	mScoreHandle = LoadGraph("data/newUI/score.png", true);

	mScoreBar = LoadGraph("data/newUI/ScoreBar.png", true);
	mPlusHandle = LoadGraph("data/newUI/Plus.png", true);
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
	case 3:   // �v���C�V�[��

		DrawGraph(mScorePosX, mScorePosY + mScoreBarPosY, mScoreBar, true);

		DrawGraph(mScorePosX, mScorePosY, mScoreHandle, true);
		for (i = 0; i < DIGIT_NUM; i++)
		{
			for (j = 0; j < NUMBER_NUM; j++)
			{
				if (mS[i] == j)
				{
					DrawGraph(NUM_POS + NUM_SPACE * i, mScorePosY - mNumPosY, mNumberHandle[j], true);
				}
			}
		}

		// ���Z�l��`�悵�Ă������Ȃ�
		if (mDrawPlusNum)
		{
			// �v���X�̉摜��`��
			DrawGraph(mPlusPosX, mPlusPosY, mPlusHandle, true);
			// ���Z�l��`��
			for (i = 0; i < DIGIT_NUM - 1; i++)
			{
				for (j = 0; j < NUMBER_NUM; j++)
				{
					if (mPlusS[i] == j)
					{
						DrawRotaGraph(mPlusNumPosX + mPlusNumSpace * i, mPlusNumPosY, 0.8, 0, mNumberHandle[j], true, false, false);
					}
				}
			}
		}
		break;

	case 5:   // ���U���g�V�[��
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
	// �X�R�A�̃\�[�g
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

	// ���Z�l�̃\�[�g
	for (i = DIGIT_NUM - 2; i >= 0; i--)
	{
		mPlusS[i] = mPlusScore % 10;
		tmp = mPlusScore % 10;
		mPlusScore = (mPlusScore - tmp) / 10;
	}
}

/// <summary>
/// �J�E���g���v������֐�
/// </summary>
void Score::Count()
{
	// ���Z�l���`�悳��Ă�����
	if (mDrawPlusNum)
	{
		// ���Z�l�`�掞�Ԃ��J�E���g����
		mScoreCount++;
	}

	// ���Z�l�`�掞�Ԃ��I�������
	if (mScoreCount > DRAW_PLUS_SCORE)
	{
		// �J�E���g��0
		mScoreCount = 0;
		// �`�拖��false
		mDrawPlusNum = false;
	}
}


/// <summary>
/// �X�R�A�̌v�Z�̊��������炤
/// </summary>
/// <param name="_BaseScore">�X�R�A�Ɋ|���銄��</param>
void Score::SetRadiusScore(int* _BaseScore)
{
	// �X�R�A���i�[���Ă悩������
	if (mScoreFlag)
	{
		// ���Z�l�̕ϐ��ɒl���i�[
		mPlusScore = *_BaseScore * 10;
		// �X�R�A�̕ϐ��ɒl���i�[
		mScore += *_BaseScore * 10;
		// ���Z�l�`�拖��true��
		mDrawPlusNum = true;
		Update();
	}
	Count();
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
