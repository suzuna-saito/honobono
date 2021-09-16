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
	void Update();

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


protected:
	

private:
	//  �t���O
	// �^�C�~���O�Q�[�W��`�悷��t���O�Ǘ�
	bool mTimingDrawFlag;
	// �^�C�~���O�Q�[�W�̃N���b�N�o���邩�̃t���O�Ǘ�
	bool mTimingFlag;
	// Reaction�̃t���O�Ǘ�
	bool mReactionFlag;

	//  �Q�[�W
	// �Q�[�W�̍��WX
	int mGageX;
	// �Q�[�W�̍��WY
	int mGageY;
	// �Q�[�W�̒��S���WX
	int mGageCX;
	// �Q�[�W�̒��S���WY
	int mGageCY;
	// ���k����Q�[�W�̔��a
	int mRadius;
	// ���肪�p�[�t�F�N�g�ɂȂ�Q�[�W�̔��a
	int mGageRadius;
	// ���a�̏�����
	int mRadiusInit;

	//  �F
	// ���F
	int	mBrack;
	// ���F
	int mWhite;

	//  ���A�N�V����
	// ���A�N�V�������`�悳���ʒu�ɂ���t���[���̉摜
	int mFreamImg;
	// �t���[���̍��WX
	int mFreamX;
	// �t���[���̍��WY
	int mFreamY;
	// ����摜
	int mJudgeImg;
	// Perfect����摜
	int mPerfectImg;
	// Good����摜
	int mGoodImg;
	// Bad����摜
	int mBadImg;
	// ���A�N�V�����̍��WX
	int mReactionX;
	// ���A�N�V�����̍��WY
	int mReactionY;
	// �m�[�c�ő�̑傫��
	int mMaxRadius;
	// �p�[�t�F�N�g�̔��a
	int mPerfectRadius;
	// �o�b�h�̔��a
	int mBadRadius;

	// �����_���Ɋi�[����l�������艺���Ȃ�
	int mBaseTime;
	// �����_���Ɋi�[����l�̈����l
	int mBasePoint;
	// �m�[�c���o�����̃^�C�~���O
	int mRandomTime;
	// �����_���Ȓl���i�[���Ă������ǂ���
	bool mRandomFlag;
	// �m�[�c���J�n�����鎞��
	int mNotesStartTime;
	// �m�[�c���I��点�鎞��
	int mNotesEndTime;

	//  �J�E���g
	// ���A�N�V������`�悷�鎞�Ԃ��J�E���g����
	int mReactionCount;
	// ���A�N�V������`�悷�鎞�Ԃ̍ő�l
	int mReactionCountMax;
	// �J�E���g��������
	int mCountInit;
	// �m�[�c�J�n�܂ł��͂���J�E���g
	int mCount;
	// �Ȃ̌o�߃J�E���g
	int mTimeCount;

	//  CSV
    // CSV�t�@�C�����i�[
	char mCsv[24] = "data/CSV/TestTiming.csv";
	// �t�@�C���̃|�C���^
	FILE* mFilePointer;
	// �f�[�^���i�[
	char mCsvData;

	float mNum;
	char mBuffer[10];
	float mCell[1][23];
	int mColumnNum;
	int mRawNum;
	bool mEofFlag;
	float mRhythm[23];

	//  �X�R�A
	// Score�����t���O
	bool mScoreFlag;
	// �X�R�A
	int mScoreRadius;


	//  �G�t�F�N�g
	// �G�t�F�N�g�摜
	int mEffectImg;       
	// �p�[�t�F�N�g�G�t�F�N�g�摜
	int mPerfectEffectImg;
	// �O�b�h�G�t�F�N�g�摜
	int mGoodEffectImg;   
	// �o�b�h�G�t�F�N�g�摜
	int mBadEffectImg;    
	// �G�t�F�N�g�̑傫��
	double mEffectScale;  
	// �G�t�F�N�g�̃A���O��
	double mEffectAngle;  
	// �G�t�F�N�g�����񂾂�傫���Ȃ鎞�Ƀv���X����l
	double mScalePlus;    
	// �G�t�F�N�g���J�X���鎞�Ƀv���X����l
	double mAngleRotate;  
	// �G�t�F�N�g�𔭐�������t���O
	bool mEffectFlag;
	// �o�b�h�ɂȂ�����
	bool mBadFlag;


	//  �T�E���h
	// �p�[�t�F�N�g�̎��ɂȂ���ʉ�
	class Sound* mPerfectSound;
	// �O�b�h�̎��ɂȂ���ʉ�
	class Sound* mGoodSound;
	// �o�b�h�̎��ɂȂ���ʉ�
	class Sound* mBadSound;

	int i = 0;

};

