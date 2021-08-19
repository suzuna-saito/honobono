// �C���N���[�h
#include "Timing.h"

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
	, buttonMoveRight(120)
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
{
	// �摜�ǂݍ���
	freamImg = LoadGraph("data/newUI/frame.png");
	selectButtonImg = LoadGraph("data/newUI/UIfish.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/bad.png");
	badImg = LoadGraph("data/newUI/good.png");

	// �F
	color = GetColor(255, 0, 0);
	gageColor = GetColor(255, 255, 255);
	
}

// �f�X�g���N�^
Timing::~Timing()
{
	// �摜�f�[�^�폜
	DeleteGraph(selectButtonImg);
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);
}

// �X�V
void Timing::Update()
{
	// �`�L�[����������{�^�������ɓ���
	if (CheckHitKey(KEY_INPUT_A))
	{
		// �Q�[�W��1�ԍ����ɗ����炱��ȏ�ړ��ł��Ȃ�
		if (buttonMoveLeft >= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX - movebutton;
		}
	}
	// �c�L�[����������{�^�����E�ɓ���
	if (CheckHitKey(KEY_INPUT_D))
	{
		// �Q�[�W��1�ԉE���ɗ����炱��ȏ�ړ��ł��Ȃ�
		if (320 <= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX + movebutton;
		}
	}

	// �X�y�[�X�L�[����������^�C�~���O�t���O���u�^�v�ƂȂ�
	if (CheckHitKey(KEY_INPUT_SPACE))
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
			BadFlag = true;
		}
		// �O�b�h�̏���
		if (radius - gageRadius > 20)
		{
			GoodFlag = true;
		}
		// �p�[�t�F�N�g�̏���
		if (radius - gageRadius <= 0 && radius - gageRadius < 10)
		{
			PerfectFlag = true;
		}
		if (!(count < countMax))
		{
			// �X�R�A�̌v�Z
			// ���a�̍ő�l���猻�݂̔��a�������o���āA���̍��ɃX�R�A���炢�̐������|����
			int n;
			n = radiusInit - radius;
			scoreMax = n * 10;
			score = scoreMax + score;
	
			// ����ȊO�̏ꍇ�̓^�C�~���O�t���O���u�U�v�Ƃ���
			TimingFlag = false;
		}
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

		// �^�C�~���O�t���O���u�U�v�ł���Ƃ�
		if(!TimingFlag)
		{ 
			// �J�E���g������������
			count = countInit;
			// �t���O���u�U�v�ɂ���
			BadFlag = false;
			GoodFlag = false;
			PerfectFlag = false;
		}
	
	// �X�R�A�̉�ʂ�\������
	DrawFormatString(scoreX, scoreY, gageColor, "score : %d", score);
	// ���i�������I��ł��鑀��o����Ƃ�����������́j�̕`��
	DrawGraph(buttonX, buttonY, selectButtonImg, TRUE);
}

