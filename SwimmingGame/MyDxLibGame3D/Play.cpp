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
	,mWaterOutSound(nullptr)
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

	camera->FixedCameraRightUpdate();
	fishManager->CreatFish();

	mPlayBGM1 = new Sound("data/newSound/bgm/bgm_1.mp3");
	mPlayBGM2 = new Sound("data/newSound/bgm/bgm_2.mp3");
	mPlayBGM3 = new Sound("data/newSound/bgm/bgm_3.mp3");

	mWaterInSound = new Sound("data/newSound/se/in.mp3");
	mWaterOutSound = new Sound("data/newSound/se/out.mp3");
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
	delete mPlayBGM1;
	delete mPlayBGM2;
	delete mPlayBGM3;

	delete mWaterInSound;
	delete mWaterOutSound;
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Play::Update()
{
	mPlayBGM1->PlayBackBGM();
	if (!mPlayBGM1->CheckBGM()) 
	{
		// ���U���g�ɃX�R�A��n��
		mScore = SceneBase::mScore->GetResult();
		return new Result(&mScore);
	}

	// �V�[���J�ڏ���(�f�o�b�N�p�F�E�V�t�g�L�[�������ƑJ��)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
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
		camera->FixedCameraRightUpdate();
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
		fishManager->Updata();
	}
	
	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void Play::Draw()
{
	// �w�i�̐���
	//backGround->Draw();
	// ���`��
	fishManager->Draw();
	// �v�[���`��
	pool->Draw();
	// ���Y���{�^��UI�`��
	timing->Draw();

	SceneBase::mScore->Draw();
	
	//���ꂼ��̈ʒu��������₷���Ȃ�悤�Ɉ�{�̐���\���i�f�o�b�N�p�j
	int redColor = GetColor(255, 0, 0);				//�^�񒆂̐F
	int greenColor = GetColor(0, 255, 0);			//����̐F
	int yellowColor = GetColor(255, 255, 0);		//�����̐F
	int purpleColor = GetColor(128, 0, 128);		//�E��̐F
	int lightBlueColor = GetColor(0, 255, 255);		//�E���̐F

	//�v�[���̐^��
	DrawLine3D(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 15.0f, 0.0f), redColor);
	//�v�[���̍���[
	DrawLine3D(VGet(-15.0f, 0.0f, 25.0f), VGet(-15.0f, 15.0f, 25.0f), greenColor);
	//�v�[���̍����[
	DrawLine3D(VGet(-15.0f, 0.0f, -25.0f), VGet(-15.0f, 15.0f, -25.0f), yellowColor);
	//�v�[���̉E��[
	DrawLine3D(VGet(15.0f, 0.0f, 25.0f), VGet(15.0f, 15.0f, 25.0f), purpleColor);
	//�v�[���̉E���[
	DrawLine3D(VGet(15.0f, 0.0f, -25.0f), VGet(15.0f, 15.0f, -25.0f), lightBlueColor);
}
