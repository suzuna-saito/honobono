// �C���N���[�h
#include "Timing.h"
#include "Input.h"
#include "Sound.h"

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
	, buttonX(80)
	, buttonY(385)
	, buttonMoveLeft(120)
	, buttonMoveRight(320)
	, movebutton(200)
	, freamX(490)
	, freamY(180)
	, radius(radiusInit)
	, gageRadius(20)
	, radiusInit(70)
	, reactionX(520)
	, reactionY(200)
	, count(countInit)
	, countInit(0)
	, countMax(50)
	, score(0)
	, scoreMax(0)
	, scoreX(800)
	, scoreY(20)
	, mPerfectSound(nullptr)
	, mGoodSound(nullptr)
	, mBadSound(nullptr)
{
	// �摜�ǂݍ���
	freamImg = LoadGraph("data/newUI/frame.png");
	selectButtonImg = LoadGraph("data/newUI/UIfish.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/bad.png");
	badImg = LoadGraph("data/newUI/good.png");

	// �F
	color = GetColor(0, 0, 0);
	gageColor = GetColor(255, 255, 255);

	// �T�E���h
	mPerfectSound = new Sound("data/newSound/se/perfect.mp3");
	mGoodSound = new Sound("data/newSound/se/good.mp3");
	mBadSound = new Sound("data/newSound/se/bad.mp3");
	
}

// �f�X�g���N�^
Timing::~Timing()
{
	// �摜�f�[�^�폜
	DeleteGraph(selectButtonImg);
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);

	delete mPerfectSound;
	delete mGoodSound;
	delete mBadSound;
}

// �X�V
void Timing::Update()
{
	UpdateKey();

	/* ���A�܂�3�̃Q�[�W��ʂŕ`��ł��Ă��Ȃ��̂ŃR�����g�A�E�g���Ă܂� */

	//// ���L�[����������{�^�������ɓ���
	//if (Key[KEY_INPUT_LEFT] == 1)
	//{
	//	// �Q�[�W��1�ԍ����ɗ����炱��ȏ�ړ��ł��Ȃ�
	//	if (buttonMoveLeft >= buttonX)
	//	{
	//		buttonX = buttonX;
	//	}
	//	else
	//	{
	//		buttonX = buttonX - movebutton;
	//	}
	//}
	//// �E�L�[����������{�^�����E�ɓ���
	//if (Key[KEY_INPUT_RIGHT] == 1)
	//{
	//	// �Q�[�W��1�ԉE���ɗ����炱��ȏ�ړ��ł��Ȃ�
	//	if (buttonMoveRight <= buttonX)
	//	{
	//		buttonX = buttonX;
	//	}
	//	else
	//	{
	//		buttonX = buttonX + movebutton;
	//	}
	//}

	// �X�y�[�X�L�[����������^�C�~���O�t���O���u�^�v�ƂȂ�
	if (Key[KEY_INPUT_SPACE] == 1)
	{
		TimingFlag = true;
	}
	// �{�^����������^�C�~���O�t���O���u�^�v�ƂȂ�����
	if (TimingFlag)
	{
		// �J�E���g����������
		count++;
		// �o�b�h�̏���
		if (radius - gageRadius <= 25)
		{
			mBadSound->PlaySE();
			BadFlag = true;
		}
		// �O�b�h�̏���
		if (radius - gageRadius > 20)
		{
			mGoodSound->PlaySE();
			GoodFlag = true;
		}
		// �p�[�t�F�N�g�̏���
		if (radius - gageRadius <= 0 && radius - gageRadius < 10)
		{
			mPerfectSound->PlaySE();
			PerfectFlag = true;
		}
		if (!(count < countMax))
		{
			// �X�R�A�̌v�Z
			// ���a�̍ő�l���猻�݂̔��a�������o���A���̍��ɃX�R�A���炢�̐������|����
			int n;
			n = radiusInit - radius;
			scoreMax = n * 10;
			score = scoreMax + score;
	
			// ����ȊO�̏ꍇ�̓^�C�~���O�t���O���u�U�v�Ƃ���
			TimingFlag = false;
		}
	}
	// �^�C�~���O�t���O���u�U�v�ł���Ƃ�
	if (!TimingFlag)
	{
		// �J�E���g������������
		count = countInit;
		// �t���O���u�U�v�ɂ���
		BadFlag = false;
		GoodFlag = false;
		PerfectFlag = false;
	}
}

// �`��
void Timing::Draw()
{
	// ���A�N�V��������̃t���[���̕`��
	DrawGraph(freamX, freamY, freamImg, TRUE);

	/*for (int i = 0; i < 3; i++)
	{*/
		// �p�[�t�F�N�g����̈ʒu�ƂȂ�Q�[�W�̕`��
		DrawCircle(gageCX + (1 * movebutton), gageCY, gageRadius, gageColor, TRUE);

		// �{�^����������Ă��Ȃ��ꍇ���[�v��������
		if(!TimingFlag)
		{
			// ���a���O�ɂȂ�܂Ŏ��k������
			if(radius > 0)
			{
				// ���k����Q�[�W�̕`��
				DrawCircle(gageCX + (1 * movebutton), gageCY, radius--, color, FALSE);
			}
			else
			{
				// ���a�̑傫����������
				radius = radiusInit;
			}
		}
		if (TimingFlag)
		{
			// �J�E���g���ő�l�ɂȂ�܂ŕ`��
			if (count < countMax)
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
				DrawCircle(gageCX + (1 * movebutton), gageCY, radius, color, FALSE);
			}
		}

		
	
	// �X�R�A�̉�ʂ�\������
	DrawFormatString(scoreX, scoreY, gageColor, "score : %d", score);
	// ���i�������I��ł��鑀��o����Ƃ�����������́j�̕`��
	//DrawGraph(buttonX, buttonY, selectButtonImg, TRUE);
}
