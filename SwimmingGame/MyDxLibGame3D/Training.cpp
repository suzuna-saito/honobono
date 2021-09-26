#include "Training.h"
#include "Pool.h"
#include "Camera.h"
#include "Play.h"
#include "BackGround.h"
#include "Sound.h"
#include "Common.h"
#include "Fish.h"
#include "Timing.h"
#include "Input.h"

// �萔
const int TRAINING_POS_X = 155;  // ���K���̃e�L�X�g���WX
const int TRAINING_POS_Y = 50;  // ���K���̃e�L�X�g���WY

const int SKIP_TIME = 50;    // �X�L�b�v�e�L�X�g��`�悵�n�߂鎞��
const int SKIP_POS_X = 150;   // �X�L�b�v�e�L�X�g���WX
const int SKIP_POS_Y = 130;  // �X�L�b�v�e�L�X�g���WY

const int ARROW_POS_X = 1400;
const int ARROW_POS_Y = 120;

const int TEXT_POS_X = 440;
const int TEXT_POS_Y = 220;

const int FIRST_TIME = 50;  // �ŏ��̃Z���t���������o�����Ԃ𑁂����邽�߂̏����l
const int NEXT_TIME = 100;  // ���̃Z���t���o������

const int MAX = 5;          // ���A�N�V�����̐�
const int GOOD_MAX = 2;
const int BAD_MAX = 1;

// �R���X�g���N�^
Training::Training()
	: mPlayBGM1(nullptr)
	, mModelHandle(-1)
	, mPos(VGet(0.0f, 5.9f, 0.0f))
	, mRot(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, mDance(VGet(0.0f, 0.0f, 0.0))
	, mTime(FIRST_TIME)
	, mFirstDrawFlag(true)
	, mSkipDrawFlag(false)
	, mPlayDrawFlag(false)
	, mEndDrawFlag(false)
	, mFastForwardDrawFlag(true)
	, mNowDia(zero)
	, mDrawDia(0)
	, mDrawReaction(0)
	, mPerfectCount(0)
{
	SetScene(training);

	mModelHandle = MV1LoadModel("data/model/fish/player02.mv1");
	// ������
	fish = new Fish(mModelHandle, mPos, mRot, mDance);

	// �v�[������
	pool = new Pool();

	// ���Y���{�^��UI����
	timing = new Timing();

	// �w�i�̐���
	backGround = new BackGround();

	// �J�����̐���
	camera = new Camera();
	camera->TrainingCameraUpdate();
	camera->CameraSet();


	// �T�E���h�̐���
	mPlayBGM1 = new Sound("data/newSound/bgm/kari.mp3");

	// �e�L�X�g�摜�̃��[�h
	mTrainingText = LoadGraph("data/model/TrainingAsset/TrainingText.png");
	mSkipText = LoadGraph("data/model/TutorialAsset/skipText.png");
	mFastForward = LoadGraph("data/model/TrainingAsset/FastForward.png");
	mNowFastForward = LoadGraph("data/model/TrainingAsset/NowFastForward.png");
	mArrow = LoadGraph("data/model/TrainingAsset/Arrow.png");
}

// �f�X�g���N�^
Training::~Training()
{
	// ���폜
	delete fish;
	// �v�[���폜
	delete pool;
	// ���Y���{�^��UI�폜
	delete timing;
	// �w�i�̍폜
	delete(backGround);

	// �T�E���h�̒�~�A�폜
	mPlayBGM1->StopMusic();
	delete mPlayBGM1;

	// �摜�̍폜
	DeleteGraph(mTrainingText);
	DeleteGraph(mSkipText);
	DeleteGraph(mDrawDia);
	DeleteGraph(mDrawReaction);
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Training::Update()
{

	UpdateKey();

	// ���y�̍Đ�
	mPlayBGM1->PlayBackBGM();


	mTime++;

	if (mNowDia == skipEnd || mNowDia == playEnd)
	{
		mPlayBGM1->StopMusic();

		return new Play();
	}

	// �X�L�b�v����?
	if (mNowDia == stop)
	{
		// �X�L�b�v�̕������`�悳��Ă���Ƃ��ɃX�y�[�X�������ꂽ��
		if (Key[KEY_INPUT_SPACE] == 1)
		{
			timing->Init();

			// �X�L�b�v���̃Z���t���o��悤�ɐݒ肷��
			mNowDia = skipZero;

			mPlayDrawFlag = false;
			mSkipDrawFlag = true;

			mTime = FIRST_TIME;
		}
	}

	// ������
	if ((mNowDia != stop && mPerfectCount != 5) || (mNowDia >= endOne && mPerfectCount == 5))
	{
		mFastForwardDrawFlag = true;

		// ���L�[�������ꂽ�瑁����t���O��
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			mFastForwardDrawFlag = false;

			mTime += 10;
		}
	}


	// �Z���t���S�ĕ`�悳�ꂽ��
	if (mNowDia == stop)
	{
		mPlayDrawFlag = true;

		// ���Y���{�^��UI�X�V
		timing->Update(1, GetScene());
	}


	// perfect��5��������
	if (mPerfectCount == 5 && mNowDia == stop)
	{
		timing->Init();
		// �V�[���J�ڑO�̃Z���t���o��悤�ɐݒ肷��
		mNowDia = endZero;

		mPlayDrawFlag = false;
		mEndDrawFlag = true;
		mTime = FIRST_TIME+20;
	}

	// ���̍X�V
	fish->Updata(timing->GetJudg(), false, GetScene());

	// �ŏ��̃Z���t����
	if (mFirstDrawFlag && mTime >= NEXT_TIME)
	{
		switch (mNowDia)
		{
		case zero:
			mNowDia = one;
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue01.png");
			break;
		case one:
			mNowDia = two;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue02.png");
			break;
		case two:
			mNowDia = three;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue03.png");
			break;
		case three:
			mNowDia = four;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue04.png");
			break;
		case four:
			mNowDia = five;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue05.png");
			break;
		case five:
			mNowDia = six;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Dialogue06.png");
			break;
		case six:
			mNowDia = stop;
			DeleteGraph(mDrawDia);
			mFirstDrawFlag = false;
			break;
		default:
			break;
		}

		mTime = 0;
	}


	// �X�L�b�v���ꂽ�Ƃ�
	if (mSkipDrawFlag && mTime >= NEXT_TIME)
	{
		switch (mNowDia)
		{
		case skipZero:
			mNowDia = skipOne;
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip01.png");
			break;
		case skipOne:
			mNowDia = skipTwo;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip02.png");
			break;
		case skipTwo:
			mNowDia = skipThree;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip03.png");
			break;
		case skipThree:
			mNowDia = skipFour;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip04.png");
			break;
		case skipFour:
			mNowDia = skipFive;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/Skip05.png");
			break;
		case skipFive:
			mNowDia = skipEnd;
			DeleteGraph(mDrawDia);
			break;
		default:
			break;
		}
		
		mTime = 0;
	}

	// �v���C���̃��A�N�V����
	if (mPlayDrawFlag)
	{
		switch (timing->GetJudg())    // ���肪
		{
		case 2:                       // perfect��������
			mDrawReaction = GetRand(MAX);             // �����_���Ń��A�N�V������\��

			switch (mDrawReaction)
			{
			case successOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success01.png");
				break;
			case successTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success02.png");
				break;
			case successThree:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success03.png");
				break;
			case successFour:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success04.png");
				break;
			case successFive:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success05.png");
				break;
			case successSix:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Success06.png");
				break;
			default:
				break;
			}
			// perfect�̃J�E���g��1�v���X����
			mPerfectCount++;
			break;
		case 1:                  // good��������
			mDrawReaction = GetRand(GOOD_MAX);             // �����_���Ń��A�N�V������\��

			switch (mDrawReaction)
			{
			case goodOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Good01.png");
				break;
			case goodTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Good02.png");
				break;
			case goodThree:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad01.png");
				break;
			default:
				break;
			}
			break;
		case 0:                  // bad��������
			mDrawReaction = GetRand(BAD_MAX);             // �����_���Ń��A�N�V������\��

			switch (mDrawReaction)
			{
			case badOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad01.png");
				break;
			case badTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad02.png");
				break;
			default:
				break;
			}
			break;
		case 3:          // ����������Ă��Ȃ�������
			mDrawReaction = GetRand(BAD_MAX);             // �����_���Ń��A�N�V������\��

			switch (mDrawReaction)
			{
			case badOne:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Not01.png");
				break;
			case badTwo:
				DeleteGraph(mDrawReaction);
				mDrawReaction = LoadGraph("data/model/TrainingAsset/Bad02.png");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		mTime = 0;
	}
	

	// perfect��5���������̃Z���t
	if (mEndDrawFlag && mTime >= NEXT_TIME)
	{
		switch (mNowDia)
		{
		case endZero:
			DeleteGraph(mDrawReaction);
			mNowDia = endOne;
			DeleteGraph(mDrawDia);
			mTime = FIRST_TIME;
			break;
		case endOne:
			mNowDia = endTwo;
			DeleteGraph(mDrawReaction);
			mDrawDia = LoadGraph("data/model/TrainingAsset/End01.png");
			mTime = 30;
			break;
		case endTwo:
			mNowDia = endThree;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/End02.png");
			break;
		case endThree:
			mNowDia = endFour;
			DeleteGraph(mDrawDia);
			mDrawDia = LoadGraph("data/model/TrainingAsset/End03.png");
			break;
		case endFour:
			mNowDia = playEnd;
			DeleteGraph(mDrawDia);
			break;
		default:
			break;
		}

		mTime = 0;
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void Training::Draw()
{
	// �w�i�̐���
	backGround->Draw();
	// ���`��
	fish->Draw(0);
	// �v�[���`��
	pool->Draw();
	// ���Y���{�^��UI�`��
	timing->Draw();

	// ���K���Ƃ��������`��
	DrawGraph(TRAINING_POS_X, TRAINING_POS_Y, mTrainingText, TRUE);

	// �`�悷��Z���t������Ƃ�
	if (mNowDia != stop)
	{
		// �Z���t�̕`��
		DrawGraph(TEXT_POS_X, TEXT_POS_Y, mDrawDia, TRUE);

		// ������{�^����������Ă��Ȃ�������
		if (mFastForwardDrawFlag && mNowDia != endZero)
		{
			// ���i���j�L�[�ő�����e�L�X�g
			DrawGraph(SKIP_POS_X, SKIP_POS_Y, mFastForward, TRUE);
		}
		// ������Ă�����
		else if (!mFastForwardDrawFlag && mNowDia != endZero)
		{
			// �����蒆�e�L�X�g
			DrawGraph(SKIP_POS_X, SKIP_POS_Y, mNowFastForward, TRUE);
			// �����蒆�摜
			DrawGraph(ARROW_POS_X, ARROW_POS_Y, mArrow, TRUE);
		}
	}
	else if (mNowDia == stop)
	{
		// �X�L�b�v�e�L�X�g�̕`��
		DrawGraph(SKIP_POS_X, SKIP_POS_Y, mSkipText, TRUE);
	}

	if (mPlayDrawFlag)
	{
		// ���A�N�V�����̕`��
		DrawGraph(TEXT_POS_X, TEXT_POS_Y, mDrawReaction, TRUE);
	}
}

