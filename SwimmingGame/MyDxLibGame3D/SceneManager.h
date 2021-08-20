#pragma once

// �O���錾
class Camera;
class SceneBase;
class Sound;
class Fade;

/// <summary>
/// �t�F�[�h�C���t�F�[�h�A�E�g�̏��
/// </summary>
enum class FadeState : int
{
	Empty,
	FadeIn,
	FadeOut,
	NonFadeInOut,
};

/// <summary>
/// �V�[�����Ǘ�
/// </summary>
class SceneManager
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SceneManager();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SceneManager();

	/// <summary>
    /// �V�[���Ǘ��̍X�V
    /// </summary>
	bool UpdateScene();

	/// <summary>
	/// �t�F�[�h�C�����̍X�V
	/// </summary>
	void UpdateFadeInCase();
	
	/// <summary>
	/// �t�F�[�h�A�E�g���̍X�V
	/// </summary>
	void UpdateFadeOutCase();

	/// <summary>
	/// �t�F�[�h�C���A�E�g���Ă��Ȃ����̍X�V
	/// </summary>
	void UpdateNonFadeInOutCase();

private:
	// �J����
	Camera* camera = nullptr;
	// ���݂̃V�[��
	SceneBase* nowScene = nullptr;
	// ���̃V�[��
	SceneBase* nextScene = nullptr;
	// ���̃V�[�����t�F�[�h�C���A�E�g�����̂��߂Ɉꎞ�ۑ����邽�߂̃|�C���^
	SceneBase* saveNextScene = nullptr;
	// �T�E���h
	Sound* sound = nullptr;
	// �t�F�[�h�C���A�E�g
	Fade* fade = nullptr;
	// �t�F�[�h�C���A�E�g�̏��
	FadeState fadeState = FadeState::Empty;

};