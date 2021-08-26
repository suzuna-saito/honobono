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

	Score* GetScore() { return mScorePtr; }

	/// <summary>
	/// CSV�f�[�^�̓ǂݍ���
	/// </summary>
	void CSVRead();

protected:
	

private:
	//  �t���O
	// �^�C�~���O�Q�[�W�����k����t���O�Ǘ�
	bool TimingShrinkFlag;
	// �^�C�~���O�Q�[�W�̃N���b�N�o���邩�̃t���O�Ǘ�
	bool TimingFlag;
	
	// Perfect�̃t���O�Ǘ�
	bool PerfectFlag;
	// Good�̃t���O�Ǘ�
	bool GoodFlag;
	// Bad�̃t���O�Ǘ�
	bool BadFlag;

	//  �Q�[�W
	// �Q�[�W�̍��WX
	int gageX;
	// �Q�[�W�̍��WY
	int gageY;
	// �Q�[�W�̒��S���WX
	int gageCX;
	// �Q�[�W�̒��S���WY
	int gageCY;
	// ���k����Q�[�W�̔��a
	int radius;
	// ���肪�p�[�t�F�N�g�ɂȂ�Q�[�W�̔��a
	int gageRadius;
	// ���a�̏�����
	int radiusInit;

	int NormalGageColor;
	//  
	// ���F
	int	brack;
	// ���F
	int white;
	
	int mGageColor;
	int mPushGageColor;

	//  ���A�N�V����
	// ���A�N�V�������`�悳���ʒu�ɂ���t���[���̉摜
	int freamImg;
	// �t���[���̍��WX
	int freamX;
	// �t���[���̍��WY
	int freamY;
	// ���A�N�V�����̍��WX
	int reactionX;
	// ���A�N�V�����̍��WY
	int reactionY;
	// �p�[�t�F�N�g���A�N�V�����̉摜
	int perfectImg;
	// �p�[�t�F�N�g�̔��a
	int perfectRadius;
	// �O�b�h���A�N�V�����̉摜
	int goodImg;
	// �o�b�h���A�N�V�����̉摜
	int badImg;
	// �o�b�h�̔��a
	int badRadius;


	//  �J�E���g
	// ���A�N�V������`�悷�鎞�Ԃ��J�E���g����
	int reactionCount;
	// ���A�N�V������`�悷�鎞�Ԃ̍ő�l
	int reactionCountMax;
	// �J�E���g��������
	int countInit;
	


	//  �X�R�A
	// ���݂̃X�R�A
	int mScore;
	// �X�R�A���ؓ��ꂷ��ϐ�
	int scoreMax;

	int mEffectImg;       
	int mPerfectEffectImg;
	int mGoodEffectImg;   
	int mBadEffectImg;    
	double mEffectScale;  
	double mEffectAngle;  
	double mScalePlus;    
	double mAngleRotate;  
	bool mEffectFlag;

	// Score�����t���O
	bool ScoreFlag;
	// �X�R�A��`�悷����WX
	int scoreX;
	// �X�R�A��`�悷����WY
	int scoreY;

	//  CSV
	// CSV�t�@�C�����i�[
	char csv[24] = "data/CSV/TestTiming.csv";
	// �t�@�C���̃|�C���^
	FILE* filePointer;
	// �f�[�^���i�[
	int csvData;


	class Score* mScorePtr;

	//  �T�E���h
	// �p�[�t�F�N�g�̎��ɂȂ���ʉ�
	class Sound* mPerfectSound;
	// �O�b�h�̎��ɂȂ���ʉ�
	class Sound* mGoodSound;
	// �o�b�h�̎��ɂȂ���ʉ�
	class Sound* mBadSound;
};

