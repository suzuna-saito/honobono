#pragma once
#include "SceneBase.h"

/// <summary>
/// �Q�[���I�[�o�[�V�[���̃N���X
/// </summary>
class GameOver : public SceneBase
{
public:
    /// �R���X�g���N�^
    GameOver();
    /// �f�X�g���N�^
    ~GameOver();

    /// <summary>
    /// �Q�[���I�[�o�[�V�[���̍X�V����
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// �Q�[���I�[�o�[�V�[���̕`��
    /// </summary>
    void Draw()override;


private:

	int mOverText;            // �Q�[���I�[�o�[�e�L�X�g
};