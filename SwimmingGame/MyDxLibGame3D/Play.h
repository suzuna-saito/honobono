#pragma once
#include "SceneBase.h"

// �O���錾
class FishManager;
class Pool;
class Timing;
class BackGround;
class UIGoal;
class HitChecker;
class Camera;
class Result;
class BackGround;
class Time;
class Sound;

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
    // �X�R�A��ێ�����ϐ�
    int mScore;

    // ��(���u)
    FishManager* fishManager =  nullptr ;
    // �v�[��
    Pool* pool = nullptr;
    // ���Y���{�^��
    Timing* timing = nullptr;
	// UI�i�S�[��
	UIGoal* uiGoal;
	// �����蔻��
	HitChecker* hit;
    // �o�b�N�O���E���h
    BackGround* backGround;
    // ���Ԃ̐���
    Time* time;

    // ���U���g�V�[��
    Result* result;

    Camera* camera;

    Sound* mPlayBGM1;
    Sound* mPlayBGM2;
    Sound* mPlayBGM3;
   
    // ��э���Ő��̓��������̉�
    Sound* mWaterInSound;
    // �V���N���ł���Ղ���Ղ��鉹
    Sound* mWaterOutSound;

};