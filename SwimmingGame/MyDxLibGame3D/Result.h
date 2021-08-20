#pragma once
#include "SceneBase.h"

class Camera;

/// <summary>
/// ���U���g�V�[���̐����A�`��
/// </summary>
class Result : public SceneBase
{
public:
    /// �R���X�g���N�^
    Result();
    /// �f�X�g���N�^
    ~Result();

    /// <summary>
    /// ���U���g�V�[���̍X�V����
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
   /// �J�[�\���̍X�V����
   /// </summary>
    void CursorUpdate();

    /// <summary>
    /// ���U���g�V�[���̕`��
    /// </summary>
    void Draw()override;

	// ���̋���
	void FishMove();

private:
	int i;
	int mAlpha;                           // �J�[�\���A���t�@�l
	int mTextAlpha;                       // �e�L�X�g�A���t�@�l
	int mCount;                           // �J�[�\���A���t�@�l�J�E���g
	int mTextCount;                       // �e�L�X�g�A���t�@�l
	int mCursorPoint;                     // �J�[�\���ʒu
	float mRotatePoint[2];                // ��]�l
	bool mEndFlag;                        // �I���t���O

	int mBackGroundGraph;                 // �w�i�摜
	int mFishModel;                       // �����f��
	int mTextModel[3];                    // �e�L�X�g���f��
	int mTexture;                         // �e�N�X�`��
	int mCursor;                          // �J�[�\���摜

	VECTOR mFishPos[2];                   // ���̈ʒu
	VECTOR mTextPos[3];                   // �e�L�X�g�̈ʒu

	int mBackPosX;                        // �w�i���WX
	int mBackPosY;                        // �w�i���WY

	VECTOR mFishRotate[2];                // ���̉�]�p�x

	VECTOR mFishSize[2];                  // ���̃T�C�Y
	VECTOR mTextSize[3];                  // �e�L�X�g�̃T�C�Y
	VECTOR mCursorPos;                    // �J�[�\���ʒu

	const float POINT_X, POINT_Y;         // 3D�摜�̒��S
	const float SIZE;                     // 3D�摜�̃T�C�Y
	const float ANGLE;                    // 3D�摜�̊p�x

	const int FISH_NUM;                   // ���̐�
	const int TEXT_NUM;                   // �e�L�X�g�̐�
	const int BACK_EXTEND_X;              // �w�i�̊g��X
	const int BACK_EXTEND_Y;              // �w�i�̊g��Y
	const float CURSOR_SIZE;              // �J�[�\���T�C�Y
	const float CURSOR_ANGLE;             // �J�[�\���p�x

	const int TITLE;                      // �^�C�g��
	const int EXIT;                       // �I��
	const int ALPHA_MAX_POINT;            // �A���t�@�l�̍ő�l
	const int ALPHA_MIN_POINT;            // �A���t�@�l�̍ŏ��l
	const int FONT_SIZE;                  // �����̃T�C�Y

	const VECTOR MAX_SIZE;                // ���̊g��k���ő�l
	const VECTOR MIN_SIZE;                // ���̊g��k���ŏ��l

    Camera* camera;

	class Sound* mResultBGM;
	class Sound* mResultSE;
	class Sound* mRestartSE;
	class Sound* mCancelSE;
public: // �Q�b�^�[�A�Z�b�^�[
};