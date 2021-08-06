#include "Play.h"
#include "GameClear.h"
#include "GameOver.h"

// �R���X�g���N�^
Play::Play()
{
	SetScene(play);

	// �Q�[���p�J�����ʒu��ݒ�
	camera->PlayerUpdate();
	// ��Q���𐶐�.
	obstructManager->CreateObstructs();
}

// �f�X�g���N�^
Play::~Play()
{
	// �J�������폜.
	delete(camera);
	// �w�i�̍폜
	delete(backGround);
	// �����蔻��̍폜
	delete(hit);
	// UI�̍폜
	delete(uiGoal);
	delete(uiFire);
	// �v���C���[���폜.
	delete(player);
	// �T�g�V�̍폜
	delete(satoshi);
	// ��Q�����폜.
	obstructManager->DestroyObstructs();
	delete(obstructManager);
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Play::Update()
{
	// �V�[���J�ڏ���(�N���A)
	if (&UIGoal::GetGoalFlag)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new GameClear();
	}
	// �V�[���J�ڏ���(�I�[�o�[)
	else if(&Player::GetHp == 0)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new GameOver();
	}

	// �w�i
	backGround->Scroll();
	// �v���C���[����.
	player->Update();
	// �T�g�V�̐���
	satoshi->Update(*uiGoal);
	// ��Q������.
	obstructManager->Update(*player, *uiGoal);
	// �c��S�[�������̍X�V
	uiGoal->Update();

	// �q�b�g�̃`�F�b�N.
	hit->Check(*player, *obstructManager);

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void Play::Draw()
{
	// �w�i
	backGround->Draw();
	// �T�g�V�̕`��
	satoshi->Draw();
	// ��Q���`��.
	obstructManager->Draw();
	// �v���C���[�`��.
	player->Draw();
	// �����蔻��UI�̕`��
	hit->Draw(*player);
	// UI(�S�[��)�̕`��
	uiGoal->Draw();
}
