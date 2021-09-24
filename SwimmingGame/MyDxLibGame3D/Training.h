#pragma once
#include "SceneBase.h"

// �O���錾
class Fish;
class Pool;
class Timing;
class BackGround;
class Camera;
class Play;
class Sound;
class Time;

/// <summary>
/// �v���C�V�[���̐����A�`��
/// </summary>
class Training : public SceneBase
{
public:
    /// �R���X�g���N�^
    Training();
    /// �f�X�g���N�^
    ~Training();

    /// <summary>
    /// �v���C�V�[���̍X�V����
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// �v���C�V�[���̕`��
    /// </summary>
    void Draw()override;

private:

    int mModelHandle;

    VECTOR mPos;
    VECTOR mRot;
    VECTOR mDance;

    // ���Y���{�^��
    Timing* timing = nullptr;
    // ��
    Fish* fish;
    // �v�[��
    Pool* pool = nullptr;
    // �o�b�N�O���E���h
    BackGround* backGround;
    // ���Ԃ̐���
    Time* time;

    Camera* camera;

    Sound* mPlayBGM1;
};