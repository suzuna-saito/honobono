#include "Play.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Player.h"
#include "UIGoal.h"
#include "HitChecker.h"
#include "Pool.h"
#include "Fish.h"
#include "Timing.h"
#include "Camera.h"


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

	camera = new Camera();
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
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Play::Update()
{
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

	///////////////////////////////////////////////////////////////////////////////
	// ���Ƃ肠�����V�[���J�ڂ��Ȃ��悤�ɃR�����g�A�E�g

	//// �V�[���J�ڏ���(�N���A)
	//if (uiGoal->GetGoalFlag())
	//{
	//	// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
	//	return new GameClear();
	//}
	//// �V�[���J�ڏ���(�I�[�o�[)
	//else if(player->GetHp() == 0)
	//{
	//	// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
	//	return new GameOver();
	//}
	///////////////////////////////////////////////////////////////////////////////

	// �v���C���[����.
	player->Update();

	startCount++;

	if (startCount >= 60)
	{
		// ���̐���
		fish->Update();
	}
	// �c��S�[�������̍X�V
	uiGoal->Update();

	// �q�b�g�̃`�F�b�N.
	//hit->Check(*player, *obstructManager);

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void Play::Draw()
{
	// �v�[���`��
	pool->Draw();
	// ���`��
	fish->Draw();
	// ���Y���{�^��UI�`��
	timing->Draw();
	// �v���C���[�`��.
	player->Draw();
	//// �����蔻��UI�̕`��
	//hit->Draw(*player);
	// UI(�S�[��)�̕`��
	uiGoal->Draw();


	// �^�񒆂̈ʒu��������₷���Ȃ�悤�Ɉ�{�̐���\���i�f�o�b�N�p�j
	DrawLine3D(VGet(0.0f, -25.0f, 0.0f), VGet(0.0f, 25.0f, 0.0f), GetColor(255, 0, 0));
}
