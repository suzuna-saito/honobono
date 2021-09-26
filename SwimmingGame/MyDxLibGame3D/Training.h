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

    // ���̃Z���t
    enum nowDia
    {
        zero,
        one,
        two,
        three,
        four,
        five,
        six,

        skipZero,
        skipOne,
        skipTwo,
        skipThree,
        skipFour,
        skipFive,

        skipEnd, // �X�L�b�v���̃Z���t��S�ďo���I�����

        endZero,
        endOne,
        endTwo,
        endThree,
        endFour,

        playEnd, // perfect��5���������Ƃ̃Z���t���o���I�����

        stop     // �Z���t���o���̂��~�߂�
    };

    // �v���C���̃��A�N�V����
    // perfect
    enum perfectDia
    {
        successOne,
        successTwo,
        successThree,
        successFour,
        successFive,
        successSix,
    };
    enum goodDia
    {
        goodOne,
        goodTwo,
        goodThree
    };
    enum badDia
    {
        badOne,
        badTwo
    };
    enum nonDia
    {
        nonOne,
        nonTwo
    };

private:

    int mModelHandle;     // ���̃n���h��

    VECTOR mPos;          // ���̃|�W�V����
    VECTOR mRot;          // ���̌���
    VECTOR mDance;        // �_���X�|�W�V�����͂Ȃ����A�����Ƃ��ēn�����ߕϐ����쐬

    int mTime;            // ���Ԍv���p

    int mTrainingText;    // ���K���e�L�X�g
    int mSkipText;        // �X�L�b�v�e�L�X�g
    int mFastForward;     // ������e�L�X�g
    int mNowFastForward;  // �����蒆�e�L�X�g
    int mArrow;           // �O�p�̍Đ��{�^���݂����Ȃ��

    bool mFirstDrawFlag;        // �ŏ��̃Z���t������`�悷��t���O
    bool mSkipDrawFlag;         // �X�L�b�v���̃e�L�X�g��`�悷��t���O
    bool mPlayDrawFlag;         // ���K���̎��̃e�L�X�g��`�悷��t���O
    bool mFastForwardDrawFlag;  // �����蒆�̃e�L�X�g��`�悷��t���O
    bool mEndDrawFlag;          // �V�[���J�ڎ��̃e�L�X�g�`��t���O

    int mNowDia;          // ���̃Z���t
    int mPlayNowDia;      // �v���C���̃Z���t

    int mDrawDia;         // �\��������Z���t
    int mDrawReaction;    // �\�������郊�A�N�V����

    int mPerfectCount;    // perfect��������񐔂��J�E���g

    // ���Y���{�^��
    Timing* timing = nullptr;
    // ��
    Fish* fish;
    // �v�[��
    Pool* pool = nullptr;
    // �o�b�N�O���E���h
    BackGround* backGround;
    // �J����
    Camera* camera;
    // �T�E���h
    Sound* mPlayBGM1;
};