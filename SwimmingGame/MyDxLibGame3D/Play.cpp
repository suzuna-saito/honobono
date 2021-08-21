#include "Play.h"
#include "Player.h"
#include "UIGoal.h"
#include "HitChecker.h"
#include "Pool.h"
#include "Fish.h"
#include "Timing.h"
#include "Camera.h"
#include "Result.h"
#include "BackGround.h"
#include "Sound.h"

// �R���X�g���N�^
Play::Play()
	:startCount(0)
	, mPlayBGM1(nullptr)
	, mPlayBGM2(nullptr)
	, mPlayBGM3(nullptr)
	, mWaterInSound(nullptr)
	,mWaterOutSound(nullptr)
{
	SetScene(play);

	// �v���C���[�𐶐�.
	player = new Player();
	// UI�i�S�[���j�̐���
	uiGoal = new UIGoal();
	//// UI(�ԉ�)�̐���
	//new UIFireworks();
	// �����蔻��𐶐�
	hit = new HitChecker();

	// �v�[������
	pool = new Pool();

	// NPC��
	for (int i = 0; i < 11;i++)
	{
		// ������
		fish = new Fish();
	}
	
	// ���Y���{�^��UI����
	timing = new Timing();

	//sound = new Sound();

	// �w�i�̐���
	backGround = new BackGround();
	// ���Ԃ̐���
	time = new Time();

	camera = new Camera();

	camera->FixedCameraRightUpdate();

	mPlayBGM1 = new Sound("data/newSound/bgm/bgm_1.mp3");
	mPlayBGM2 = new Sound("data/newSound/bgm/bgm_2.mp3");
	mPlayBGM3 = new Sound("data/newSound/bgm/bgm_3.mp3");

	mWaterInSound = new Sound("data/newSound/se/in.mp3");
	mWaterOutSound = new Sound("data/newSound/se/out.mp3");

	// Update���n�܂�O�ɗ���(Loop���Ȃ��悤��)
	mPlayBGM1->PlayBackBGM();
}

// �f�X�g���N�^
Play::~Play()
{
	// �v�[���폜
	delete pool;
	// ���폜
	delete fish;
	// ���Y���{�^��UI�폜
	delete timing;
	// �����蔻��̍폜
	delete(hit);
	// UI�̍폜
	delete(uiGoal);
	//delete(uiFire);
	// �v���C���[���폜.
	delete(player);
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
	//if (CheckHitKey(KEY_INPUT_SPACE))        // �����������Œ�J����
	//{
	//	
	//}

	// ���y������Ă��邩�`�F�b�N
	if (!mPlayBGM1->CheckBGM())
	{
		// ����Ă��Ȃ������烊�U���g��
		return new Result();
	}

	// �V�[���J�ڏ���(�f�o�b�N�p�F�E�V�t�g�L�[�������ƑJ��)
	if (CheckHitKey(KEY_INPUT_RSHIFT))
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new Result();
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

	// �v���C���[����.
	player->Update();

	startCount++;

	if (startCount >= 60)
	{
		// ���̐���
		fish->Update();
	}
	
	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void Play::Draw()
{
	// �w�i�̐���
	backGround->Draw();
	// �v�[���`��
	pool->Draw();
	// ���`��
	fish->Draw();
	// ���Y���{�^��UI�`��
	timing->Draw();
	// �v���C���[�`��.
	player->Draw();


	// �^�񒆂̈ʒu��������₷���Ȃ�悤�Ɉ�{�̐���\���i�f�o�b�N�p�j
	DrawLine3D(VGet(0.0f, -25.0f, 0.0f), VGet(0.0f, 25.0f, 0.0f), GetColor(255, 0, 0));
}
