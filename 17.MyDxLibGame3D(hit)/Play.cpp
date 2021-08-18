#include "Play.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Play::Play()
	: mEndFlag(false)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Play::~Play()
{
}

/// <summary>
/// �v���C�V�[��
/// </summary>
void Play::PlayScene()
{
	// �J�����𐶐�.
	Camera* camera = new Camera();
	// ���Ԃ𐶐�
	Time* time = new Time();
	// �w�i�𐶐�
	BackGround* background = new BackGround();
	// �t�B�[���h�𐶐�
	Pool* pool = new Pool();
	// �v���C���[�𐶐�
	Fish* fish = new Fish();

	// �v���C�V�[�����[�v
	while (!ProcessMessage())
	{
		ClearDrawScreen();

		time->Update();

		camera->DivingCameraUpdate(*time);
		camera->CameraSet();

		background->Draw();
		pool->Draw();
		fish->Draw();

		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			mEndFlag = true;
			break;
		}
	}

	// �J�������폜.
	delete(camera);
	// ���Ԃ��폜.
	delete(time);
	// �w�i���폜
	delete(background);
	// �t�B�[���h���폜.
	delete(pool);
	// �v���C���[���폜.
	delete(fish);
}
