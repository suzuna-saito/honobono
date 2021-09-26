#pragma once
#include "DxLib.h"

class Score;

/// <summary>
/// �^�C�~���O�Q�[�W�̃N���X
/// </summary>
class Timing
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Timing();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Timing();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(bool _sound);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �X�R�A���擾
	/// </summary>
	/// <returns>���݂̃X�R�A��Ԃ�</returns>
	int GetRadius() { return mScoreRadius; }
	bool GetScoreFlag() { return mScoreFlag; }

	/// <summary>
	/// CSV�f�[�^�̓ǂݍ���
	/// </summary>
	void CSVRead();


	// ����
	enum judgement
	{
		bad,
		good,
		perfect,
		notDone,  // ����������Ȃ�����

		none      // �Q�[�W���o�ĂȂ�
	};

	// ����̎擾
	judgement GetJudg() { return mJudge; }

private:            // �����Ȃ��Ă����̂Ő��������ɒu���܂����B
	// ����
	// ���̔��肪����������
	judgement mJudge;

	int Count;

	//  �t���O
	bool mTimingDrawFlag;                 // �^�C�~���O�Q�[�W��`�悷��t���O�Ǘ�
	bool mTimingFlag;                     // �^�C�~���O�Q�[�W�̃N���b�N�o���邩�̃t���O�Ǘ�
	bool mReactionFlag;                   // Reaction�̃t���O�Ǘ�

	//  �Q�[�W
	int mGageX;                        // �Q�[�W�̍��WX
	int mGageY;                        // �Q�[�W�̍��WY
	int mGageCX;                       // �Q�[�W�̒��S���WX
	int mGageCY;                       // �Q�[�W�̒��S���WY
	int mRadius;                       // ���k����Q�[�W�̔��a
	int mGageRadius;                   // ���肪�p�[�t�F�N�g�ɂȂ�Q�[�W�̔��a
	int mRadiusInit;                   // ���a�̏�����

	int mImgDirection;                 // �Q�[�W�摜�̃����_���ɉE���������i�[����ϐ�
	int mBaseGagePoint;                // �ǂ��܂ł̐����������_���ɂ��邩
	int mRightGagePosX;                // �E�̃Q�[�W��X���W
	int mRightGagePosY;                // �E�̃Q�[�W��Y���W
	int mLeftGagePosX;                 // ���̃Q�[�W��X���W
	int mLeftGagePosY;                 // ���̃Q�[�W��Y���W

	//  �F
	int	mBrack;                      // ���F
	int mWhite;                      // ���F

	//  ���A�N�V����
	int mTimingImg[2];               // �^�C�~���O�Q�[�W�̉摜
	int mFreamImg;                   // ���A�N�V�������`�悳���ʒu�ɂ���t���[���̉摜
	int mFreamX;                     // �t���[���̍��WX
	int mFreamY;                     // �t���[���̍��WY
	int mJudgeImg;                   // ����摜
	int mPerfectImg;                 // Perfect����摜
	int mGoodImg;                    // Good����摜
	int mBadImg;                     // Bad����摜
	int mReactionX;                  // ���A�N�V�����̍��WX
	int mReactionY;                  // ���A�N�V�����̍��WY
	int mMaxRadius;                  // �m�[�c�ő�̑傫��
	float mPerfectSize;              // �p�[�t�F�N�g�̔��a
	float mBadSize;                  // �o�b�h�̔��a

	float mFrameSize;                // �t���[���̑傫��
	float mFrameShrinkPoint;         // ���k����l

	float mFrameMovePoint;           // �t���[����
	float mFrameShrinkGage;          // ���k����Q�[�W�̒l
	float mFrameSizeInit;            // �t���[���̏�����
	float mFrameMoveInit;            // �t���[��

	int mBaseTime;                   // �����_���Ɋi�[����l�������艺���Ȃ�
	int mBaseTimePoint;              // �����_���Ɋi�[����l�̈����l
	int mNoteTime[18];               // �m�[�c���o���^�C�~���O
	int mNoteCount;                  // �m�[�c���o������
	int mNotesStartTime;             // �m�[�c���J�n�����鎞��
	int mNotesEndTime;               // �m�[�c���I��点�鎞��
	const int NOTE_NUM;              // �m�[�c�̐�

	int mDifficultyCount;            // ��Փx���グ��J�E���g    
	const int END_TIME;              // �Ȃ̏I�Ղɓ��鎞��
	const int DIFFICULT_TIME;        // �Ȃ̃T�r�ɓ��鎞��

	//  �J�E���g
	int mReactionCount;              // ���A�N�V������`�悷�鎞�Ԃ��J�E���g����
	int mReactionCountMax;           // ���A�N�V������`�悷�鎞�Ԃ̍ő�l
	int mCountInit;                  // �J�E���g��������
	int mCount;                      // �m�[�c�J�n�܂ł��͂���J�E���g
	int mTimeCount;                  // �Ȃ̌o�߃J�E���g

	//  CSV
	char mCsv[24] = "data/CSV/TestTiming.csv";         // CSV�t�@�C�����i�[
	FILE* mFilePointer;                                // �t�@�C���̃|�C���^
	char mCsvData;                                     // �f�[�^���i�[

	float mNum;
	char mBuffer[10];
	float mCell[1][23];
	int mColumnNum;
	int mRawNum;
	bool mEofFlag;
	float mRhythm[23];

	//  �X�R�A
	bool mScoreFlag;        // Score�����t���O
	int mScoreRadius;       // �X�R�A
	float mScorePlus;       // �X�R�A�̉��Z�{��


	//  �G�t�F�N�g
	int mEffectImg;               // �G�t�F�N�g�摜      
	int mPerfectEffectImg;        // �p�[�t�F�N�g�G�t�F�N�g�摜
	int mGoodEffectImg;           // �O�b�h�G�t�F�N�g�摜
	int mBadEffectImg;            // �o�b�h�G�t�F�N�g�摜

	int mEffectPosY;              // �Q�[�W�𒆐S�̃G�t�F�N�gY���W(�Q�[�W�̒��S���班����ɂ�����)
	double mEffectScale;          // �G�t�F�N�g�̑傫��
	double mEffectAngle;          // �G�t�F�N�g�̃A���O��
	double mScalePlus;            // �G�t�F�N�g�����񂾂�傫���Ȃ鎞�Ƀv���X����l
	double mAngleRotate;          // �G�t�F�N�g���J�X���鎞�Ƀv���X����l
	bool mEffectFlag;             // �G�t�F�N�g�𔭐�������t���O

	//  �T�E���h
	class Sound* mPerfectSound;       // �p�[�t�F�N�g�̎��ɂȂ���ʉ�
	class Sound* mGoodSound;          // �O�b�h�̎��ɂȂ���ʉ�
	class Sound* mBadSound;           // �o�b�h�̎��ɂȂ���ʉ�

	int i = 0;

};

