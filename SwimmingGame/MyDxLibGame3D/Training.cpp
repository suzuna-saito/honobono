#include "Training.h"
#include "Pool.h"
#include "Camera.h"
#include "Play.h"
#include "BackGround.h"
#include "Time.h"
#include "Timing.h"
#include "Sound.h"
#include "Common.h"
#include "Fish.h"
#include "Input.h"

// �R���X�g���N�^
Training::Training()
	: mPlayBGM1(nullptr)
	, mModelHandle(-1)
	, mPos(VGet(0.0f, 5.5f, 0.0f))
	, mRot(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, mDance(VGet(0.0f, 0.0f, 0.0))
{
	SetScene(training);

	// �v�[������
	pool = new Pool();

	mModelHandle = MV1LoadModel("data/model/fish/player02.mv1");
	// ������
	fish = new Fish(mModelHandle, mPos, mRot, mDance);

	// ���Y���{�^��UI����
	timing = new Timing();


	time = new Time();

	// �w�i�̐���
	backGround = new BackGround();

	camera = new Camera();

	camera->TrainingCameraUpdate();
	camera->CameraSet();

	mPlayBGM1 = new Sound("data/newSound/bgm/kari.mp3");

	mPlayBGM1->PlayBackBGM();
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
	delete time;
	// �w�i�̍폜
	delete(backGround);
	mPlayBGM1->StopMusic();


	delete mPlayBGM1;

}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Training::Update()
{
	UpdateKey();

	if (Key[KEY_INPUT_SPACE] == 1)
	{
		mPlayBGM1->StopMusic();

		return new Play();
	}

	time->Update();

	// ���Y���{�^��UI�X�V
 	timing->Update(1);

	fish->Updata(timing->GetJudg(), time->GetDeltaTime(), false, GetScene());

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
}

