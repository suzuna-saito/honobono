#pragma once
#include "SceneBase.h"

/// <summary>
/// �Q�[���N���A�V�[���̃N���X
/// </summary>
class GameClear : public SceneBase
{
public:
    /// �R���X�g���N�^
    GameClear();
    /// �f�X�g���N�^
    ~GameClear();

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

	int mClearText;             
};