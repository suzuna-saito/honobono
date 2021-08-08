#include "Timing.h"
#include "DxLib.h"

Timing::Timing()
	: TimingFlag(false)
	, PerfectFlag(false)
	, GoodFlag(false)
	, BadFlag(false)
	, gageX(50)
	, gageY(350)
	, gageCX(100)
	, gageCY(400)
	, buttonX(80)
	, buttonY(385)
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
{
	// �摜�ǂݍ���
	freamImg = LoadGraph("data/newUI/8688.png");
	selectButtonImg = LoadGraph("data/newUI/UIfish.png");
	perfectImg = LoadGraph("data/newUI/perfect.png");
	goodImg = LoadGraph("data/newUI/bad.png");
	badImg = LoadGraph("data/newUI/good.png");

	// �F
	color = GetColor(0, 0, 0);
	gageColor = GetColor(255, 255, 255);
	
}

Timing::~Timing()
{
	// �摜�f�[�^�폜
	DeleteGraph(selectButtonImg);
	DeleteGraph(perfectImg);
	DeleteGraph(goodImg);
	DeleteGraph(badImg);
}

void Timing::Update()
{
	// �X�y�[�X�L�[����������^�C�~���O�t���O���u�^�v�ƂȂ�
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		TimingFlag = true;
	}
	// �`�L�[����������{�^�������ɓ���
	if (CheckHitKey(KEY_INPUT_A))
	{
		// �Q�[�W��1�ԍ����ɗ����炱��ȏ�ړ��ł��Ȃ�
		if (120 >= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX - 200;
		}
	}
	// �c�L�[����������{�^�����E�ɓ���
	if (CheckHitKey(KEY_INPUT_D))
	{
		// �Q�[�W��1�ԉE���ɗ����炱��ȏ�ړ��ł��Ȃ�
		if(320 <= buttonX)
		{
			buttonX = buttonX;
		}
		else
		{
			buttonX = buttonX + 200;
		}
	}

}

void Timing::Draw()
{
	// ���A�N�V��������̃t���[���̕`��
	DrawGraph(freamX, freamY, freamImg, TRUE);

	for (int i = 0; i < 3; i++)
	{
		// �p�[�t�F�N�g����̈ʒu�ƂȂ�Q�[�W�̕`��
		DrawCircle(gageCX + (i * 200), gageCY, gageRadius, gageColor, TRUE);

		// �{�^����������Ă��Ȃ��ꍇ���[�v��������
		if(!TimingFlag)
		{
			// ���a���O�ɂȂ�܂Ŏ��k������
			if(radius > 0)
			{
				// ���k����Q�[�W�̕`��
				DrawCircle(gageCX + (i * 200), gageCY, radius--, color, FALSE);
			}
			else
			{
				// ���a�̑傫����������
				radius = radiusInit;
			}
		}
		// �{�^����������^�C�~���O�t���O���u�^�v�ƂȂ�����
		if(TimingFlag)
		{
			// �J�E���g����������
			count++;
			// �J�E���g���ő�l�ɂȂ�܂ŕ`��
			if (count < countMax)
			{
				// �o�b�h�̃��A�N�V������`�悷�����
				if (radius - gageRadius <= 25)
				{
					DrawGraph(reactionX, reactionY, badImg, TRUE);
				}
				// �O�b�h�̃��A�N�V������`�悷�����
				if (radius - gageRadius > 20)
				{
					DrawGraph(reactionX, reactionY, goodImg, TRUE);
				}
				// �p�[�t�F�N�g�̃��A�N�V������`�悷�����
				if (radius - gageRadius <= 0 && radius - gageRadius < 10)
				{
					DrawGraph(reactionX, reactionY, perfectImg, TRUE);
				}

				for (int i = 0; i < 3; i++)
				{
					// �Q�[�W���~�܂�
					DrawCircle(gageCX + (i * 200), gageCY, radius, color, FALSE);
				}
			}
			else
			{
				// ����ȊO�̏ꍇ�̓^�C�~���O�t���O���u�U�v�Ƃ���
				TimingFlag = false;
			}
		}
		// �^�C�~���O�t���O���u�U�v�ł���Ƃ�
		if(!TimingFlag)
		{ 
			// �J�E���g������������
			count = countInit;
		}
	}


	// ���i�������I��ł��鑀��o����Ƃ�����������́j�̕`��
	DrawGraph(buttonX, buttonY, selectButtonImg, TRUE);
}

