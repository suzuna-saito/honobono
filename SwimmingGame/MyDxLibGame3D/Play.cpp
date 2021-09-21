#include "Play.h"
#include "HitChecker.h"
#include "Pool.h"
#include "FishManager.h"
#include "Timing.h"
#include "Camera.h"
#include "Result.h"
#include "BackGround.h"
#include "Sound.h"
#include "Score.h"
#include "Common.h"


// �R���X�g���N�^
Play::Play()
	:startCount(0)
	, mScore(0)
	, mScoreRadius(0)
	, mScoreFlag(false)
	, mPlayBGM1(nullptr)
	, mPlayBGM2(nullptr)
	, mPlayBGM3(nullptr)
	, mWaterInSound(nullptr)
	, mWaterOutSound(nullptr)
	, mWaitDanceCount(WAIT_DANCE_TIME_COUNT)
{
	SetScene(play);

	// �����蔻��𐶐�
	hit = new HitChecker();

	// �v�[������
	pool = new Pool();

	// ������
	fishManager = new FishManager();

	// ���Y���{�^��UI����
	timing = new Timing();

	// �w�i�̐���
	backGround = new BackGround();
	// ���Ԃ̐���
	time = new Time();

	camera = new Camera();

	fishManager->CreatFish();

	mPlayBGM1 = new Sound("data/newSound/bgm/bgm_1.wav");
	mPlayBGM2 = new Sound("data/newSound/bgm/bgm_2.mp3");
	mPlayBGM3 = new Sound("data/newSound/bgm/bgm_3.mp3");

	mWaterInSound = new Sound("data/newSound/se/in.mp3");
	mWaterOutSound = new Sound("data/newSound/se/out.mp3");

	//�A�[�e�B�X�e�B�b�N�X�C�~���O���̉��y�̃R���X�g���N�^
	mDancePlaySE = new Sound("data/newsound/bgm/BGM_3.wav");

	mPlayBGM1->PlayBackBGM();

	///// �f�o�b�N�p //////
	test = 0.0f;
	test02 = 0.0f;
	test03 = 0.0f;
}

// �f�X�g���N�^
Play::~Play()
{
	//�������̔z��̍폜
	fishManager->DestroyFish();

	// ���폜
	delete fishManager;
	// �v�[���폜
	delete pool;
	// ���Y���{�^��UI�폜
	delete timing;
	// �����蔻��̍폜
	delete(hit);
	// �w�i�̍폜
	delete(backGround);
	mPlayBGM1->StopMusic();
	mPlayBGM2->StopMusic();
	mPlayBGM3->StopMusic();


	//���y�̒�~
	mDancePlaySE->StopMusic();

	delete mPlayBGM1;
	delete mPlayBGM2;
	delete mPlayBGM3;

	//�������̍폜
	delete mDancePlaySE;

	delete mWaterInSound;
	delete mWaterOutSound;
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Play::Update()
{
	if (!mPlayBGM1->CheckBGM()
		&& !mDancePlaySE->CheckBGM())
	{
		mPlayBGM1->StopMusic();
		mDancePlaySE->StopMusic();
		// ���U���g�ɃX�R�A��n��
		mScore = SceneBase::mScore->GetResult();
		return new Result(&mScore);
	}

	// �V�[���J�ڏ���(�f�o�b�N�p�F�E�V�t�g�L�[�������ƑJ��)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
		mPlayBGM1->StopMusic();
		mDancePlaySE->StopMusic();
		// ���U���g�ɃX�R�A��n��
		mScore = SceneBase::mScore->GetResult();
		return new Result(&mScore);
	}

	time->Update();

	camera->DivingCameraUpdate(*time);
	camera->CameraSet();

	// �J�����̍X�V�i�f�o�b�N�p�j
	if (CheckHitKey(KEY_INPUT_UP))        // �����������Œ�J����
	{
		camera->FixedCameraUpUpdate();
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))// ����������E�Œ�J����
	{
		camera->FixedCameraRightUpdate(test02);
		CameraPosUpDate();                // �����itest02�j�̍X�V
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) // ����������v���C���[�̌��Œ�J����
	{
		camera->FixedCameraBackUpdate(test, test03);
		CameraPosUpDate();                // �����itest�j�̍X�V
	}

	// ���Y���{�^��UI�X�V
	timing->Update();
	// �X�R�A�̊�����������Ă���
	mScoreRadius = timing->GetRadius();
	// �X�R�A�̃t���O�����炤
	mScoreFlag = timing->GetScoreFlag();

	// �X�R�A�Ƀt���O��n��
	SceneBase::mScore->SetScoreFlag(&mScoreFlag);
	// �X�R�A�Ɋ�����n��
	SceneBase::mScore->SetRadiusScore(&mScoreRadius);


	startCount++;
	if (startCount >= 60)
	{
		// ���̐���
		fishManager->Updata(timing->GetJudg(), time->GetDeltaTime(), fishManager->GetStopFlag());

		//andou
		//�_���X���n�߂Ă��������̃t���O��true�������Ƃ�
		if (fishManager->GetStopFlag())
		{
			//�_���X���n�߂�܂ł̃J�E���g�������Ă���
			mWaitDanceCount--;

			//�J�E���g���O�ȉ��ɂȂ�����
			if (mWaitDanceCount <= 0)
			{
				//��э��ޑO�ɗ���Ă������y���~�߂�
				mPlayBGM1->StopMusic();
				//�_���X���̉��y�𗬂�
				mDancePlaySE->PlayBackBGM();
			}
		}

	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void Play::Draw()
{
	// �w�i�̐���
	backGround->Draw();
	// ���`��
	fishManager->Draw();
	// �v�[���`��
	pool->Draw();
	// ���Y���{�^��UI�`��
	timing->Draw();

	SceneBase::mScore->Draw(GetScene());

	//���ꂼ��̈ʒu��������₷���Ȃ�悤�Ɉ�{�̐���\���i�f�o�b�N�p�j
	int redColor = GetColor(255, 0, 0);				//�^�񒆂̐F
	int greenColor = GetColor(0, 255, 0);			//����̐F
	int yellowColor = GetColor(255, 255, 0);		//�����̐F
	int purpleColor = GetColor(128, 0, 128);		//�E��̐F
	int lightBlueColor = GetColor(0, 255, 255);		//�E���̐F

	//�v�[���̐^��
	DrawLine3D(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, LINE_Y, 0.0f), redColor);
	//�v�[���̍���[
	DrawLine3D(VGet(-LINE_X, 0.0f, LINE_Z), VGet(-LINE_X, LINE_Y, LINE_Z), greenColor);
	//�v�[���̍����[
	DrawLine3D(VGet(-LINE_X, 0.0f, -LINE_Z), VGet(-LINE_X, LINE_Y, -LINE_Z), yellowColor);
	//�v�[���̉E��[
	DrawLine3D(VGet(LINE_X, 0.0f, LINE_Z), VGet(LINE_X, LINE_Y, LINE_Z), purpleColor);
	//�v�[���̉E���[
	DrawLine3D(VGet(LINE_X, 0.0f, -LINE_Z), VGet(LINE_X, LINE_Y, -LINE_Z), lightBlueColor);
}



/////////// �f�o�b�N�p //////////////

/// <summary>
/// �J�����̈ʒu�����炷�������X�V
/// </summary>
void Play::CameraPosUpDate()
{
	switch ((int)GetCameraPosition().x)
	{
	case 60:
		if ((CheckHitKey(KEY_INPUT_D)))       // d�������ꂽ��E�ɐi��
		{
			test02 += 0.5f;
		}
		else if ((CheckHitKey(KEY_INPUT_A))) // a�������ꂽ�獶�ɐi��
		{
			test02 -= 0.5f;
		}
		break;

	case 0:
		if ((CheckHitKey(KEY_INPUT_W)))       // ���������ꂽ��O�ɐi��
		{
			test += 0.5f;
		}
		else if ((CheckHitKey(KEY_INPUT_S))) // ���������ꂽ����ɉ�����
		{
			test -= 0.5f;
		}
		if ((CheckHitKey(KEY_INPUT_Q)))      // q�������ꂽ�牺������
		{
			test03 += 0.01;
		}
		else if ((CheckHitKey(KEY_INPUT_E))) // e�������ꂽ��������
		{
			test03 -= 0.01;
		}
		break;
	default:
		break;
	}
}
