#include "Play.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Player.h"
#include "UIGoal.h"
#include "HitChecker.h"
#include "Pool.h"
#include "FishBase.h"
#include "FishManager.h"
#include "Timing.h"

// �R���X�g���N�^
Play::Play()
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
	// ����������
	fish = new FishManager();
	// ���Y���{�^��UI����
	timing = new Timing();

	//mob�������̐���
	fish->CreatMobFish();
}

// �f�X�g���N�^
Play::~Play()
{
	//mob�������̍폜
	fish->DestroyMobFish();

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
	// �c��S�[�������̍X�V
	uiGoal->Update();

	//���u���X�V
	fish->Updata();

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
}
