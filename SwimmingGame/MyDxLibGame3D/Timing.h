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

	void fps();

protected:
	

private:
	//  �t���O
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

	//  �F
	// ���F
	int	brack;
	// ���F
	int white;

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
	int count = 0;

	//  �X�R�A
	// Score�����t���O
	bool ScoreFlag;
	// 
	class Score* mScorePtr;


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


	//  CSV
	// CSV�t�@�C�����i�[
	char csv[24] = "data/CSV/TestTiming.csv";
	// �t�@�C���̃|�C���^
	FILE* filePointer;
	// �f�[�^���i�[
	int csvData;


	//  �T�E���h
	// �p�[�t�F�N�g�̎��ɂȂ���ʉ�
	class Sound* mPerfectSound;
	// �O�b�h�̎��ɂȂ���ʉ�
	class Sound* mGoodSound;
	// �o�b�h�̎��ɂȂ���ʉ�
	class Sound* mBadSound;
};

