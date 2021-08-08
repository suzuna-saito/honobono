#pragma once
#include "SceneBase.h"

// �O���錾
class Fish;
class Pool;
class Timing;
class BackGround;
class Player;
class UIGoal;
class HitChecker;

/// <summary>
/// �v���C�V�[���̐����A�`��
/// </summary>
class Play : public SceneBase
{
public:
    /// �R���X�g���N�^
    Play();
    /// �f�X�g���N�^
    ~Play();

    /// <summary>
    /// �v���C�V�[���̍X�V����
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// �v���C�V�[���̕`��
    /// </summary>
    void Draw()override;

private:
    // ��
    Fish* fish = nullptr;
    // �v�[��
    Pool* pool = nullptr;
    // ���Y���{�^��
    Timing* timing = nullptr;
	// �w�i
	BackGround* backGround;
	// �v���C���[
	Player* player;
	// UI�i�S�[��
	UIGoal* uiGoal;
	// �����蔻��
	HitChecker* hit;
};