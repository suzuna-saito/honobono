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

// �R���X�g���N�^
Play::Play()
	:startCount(0)
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
	// ������
	fish = new Fish();
	// ���Y���{�^��UI����
	timing = new Timing();

	// �w�i�̐���
	backGround = new BackGround();
	// ���Ԃ̐���
	time = new Time();

	camera = new Camera();

	camera->FixedCameraRightUpdate();
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
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Play::Update()
{
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
	//backGround->Draw();
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
