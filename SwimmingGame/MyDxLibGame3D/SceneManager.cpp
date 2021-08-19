// �C���N���[�h
#include "SceneManager.h"
#include "Title.h"
#include "Camera.h"
#include "Sound.h"
#include "Common.h"
#include "Fade.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneManager::SceneManager()
    // �J��������
	: camera(new Camera())
	// ���݂̃V�[���̐���
	, nowScene(new Title())
	// ���̃V�[���Ɍ��݂̃V�[����ۑ�
	, nextScene(nowScene)
	// ���݂̃V�[�����ꎞ�ۑ�
	, saveNextScene(nowScene)
	// �T�E���h�̐���
	, sound(new Sound(*nowScene))
	// �t�F�[�h�C���A�E�g����
	, fade(new Fade())
	// �t�F�[�h�C���A�E�g�̏�Ԃ��t�F�[�h�C���A�E�g���Ă��Ȃ���ԂɕύX
	, fadeState(FadeState::NonFadeInOut)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneManager::~SceneManager()
{
	// �J�����폜
	delete camera;
    // �V�[���폜
	delete nowScene;
	// �T�E���h�폜
	delete sound;
	// �t�F�[�h�C���A�E�g�폜
	delete fade;
}

/// <summary>
/// �V�[���Ǘ��̍X�V
/// </summary>
bool SceneManager::UpdateScene()
{
	// �V�[���̍X�V����
    // ���݂Ǝ��̃V�[�����r���邽�߂�SceneBase�N���X�|�C���^
	// Update�̖߂�l�Ŏ��̃V�[���̃|�C���^���Ԃ��Ă���
	nextScene = nowScene->Update();

	// �t�F�[�h�̏�Ԃ��݂āA�t�F�[�h�C���A�E�g���s��
	switch (fadeState)
	{
	// �t�F�[�h�C�����Ă��鎞
	case FadeState::FadeIn:

		// �t�F�[�h�C�����̍X�V
		UpdateFadeInCase();

		break;
	// �t�F�[�h�A�E�g���Ă��鎞
	case FadeState::FadeOut:

		// �t�F�[�h�A�E�g���̍X�V
		UpdateFadeOutCase();

		break;
    // �t�F�[�h�C���A�E�g���Ă��Ȃ���
	case FadeState::NonFadeInOut:

		// �t�F�[�h�C���A�E�g���Ă��Ȃ����̍X�V
		UpdateNonFadeInOutCase();

		break;
	}

	// �Q�[���I����ԂɂȂ�����X�V���~�߂�
	if (nowScene->GetScene() == nowScene->gameEnd)
	{
		return false;
	}

	return true;
}

/// <summary>
/// �t�F�[�h�C�����̍X�V
/// </summary>
void SceneManager::UpdateFadeInCase()
{
	// �ꎞ�ۑ������V�[����`��
	saveNextScene->Draw();

	// �t�F�[�h�C���`��
	// �t�F�[�h�C�����I�������t�F�[�h�C���A�E�g���Ă��Ȃ���Ԃɐ؂�ւ���
	if (fade->Draw(false, WHITE))
	{
		fadeState = FadeState::NonFadeInOut;
	}
}

/// <summary>
/// �t�F�[�h�A�E�g���̍X�V
/// </summary>
void SceneManager::UpdateFadeOutCase()
{
	// ���݂̃V�[����`��
	nowScene->Draw();

	// �t�F�[�h�A�E�g�`��
	// �t�F�[�h�A�E�g���I�������t�F�[�h�C���̏�Ԃɐ؂�ւ���
	if (fade->Draw(true, WHITE))
	{
		fadeState = FadeState::FadeIn;
	}
}

/// <summary>
/// �t�F�[�h�C���A�E�g���Ă��Ȃ����̍X�V
/// </summary>
void SceneManager::UpdateNonFadeInOutCase()
{
	// ���݂̃V�[����`��
	nowScene->Draw();


	//camera->TryDrawCameraUpdate();

    // �V�[�����ς���Ă����玟�̃V�[�����ꎞ�ۑ����āA�J�����̃A���O���A�t�F�[�h�C���A�E�g�̏�Ԃ�؂�ւ���
	if (nextScene != nowScene)
	{
		// ���̃V�[�����ꎞ�ۑ�
		saveNextScene = nextScene;
		// �t�F�[�h�C���̏�Ԃɐ؂�ւ���
		fadeState = FadeState::FadeIn;
	}

	// �t�F�[�h�C���A�E�g���I�������A���y�A�V�[����؂�ւ��āA�t�F�[�h�C���A�E�g������
	if (saveNextScene != nowScene)
	{
		// ���y���~�߂�
		sound->StopMusic(*saveNextScene);
		// ���݂̃V�[�������
		delete nowScene;
		// ���݂̃V�[���Ɉꎞ�ۑ������V�[����ۑ�
		nowScene = saveNextScene;
		// ���y���Đ�
		sound->PlayBGM(*nowScene);
		// ���ʉ��̍Đ�
		sound->PlaySE(*nowScene);

		// �t�F�[�h�C���A�E�g������
		fade->Init();
	}
}
