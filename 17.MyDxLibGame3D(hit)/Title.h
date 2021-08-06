#pragma once
#include "SceneBase.h"

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
    // �J�����𐶐�.
    Camera* camera = new Camera();

    int mTitleText;    // �^�C�g���e�L�X�g
};