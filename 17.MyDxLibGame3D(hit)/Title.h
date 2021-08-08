#pragma once
#include "SceneBase.h"

// �O���錾
class Fish;
class Pool;

/// <summary>
/// �^�C�g���V�[���̐����A�`��
/// </summary>
class Title : public SceneBase
{
public:
    /// �R���X�g���N�^
    Title();
    /// �f�X�g���N�^
    ~Title();

    /// <summary>
    /// �^�C�g���V�[���̍X�V����
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// �^�C�g���V�[���̕`��
    /// </summary>
    void Draw()override;

private:

    Fish* fish = nullptr;

    Pool* pool = nullptr;

    int mTitleText;    // �^�C�g���e�L�X�g
};