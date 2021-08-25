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

	// �X�R�A��n��
	Score* GetScore() { return score; }
	// Perfect�̃t���O�Ǘ�
	bool PerfectFlag;
	// Good�̃t���O�Ǘ�
	bool GoodFlag;
	// Bad�̃t���O�Ǘ�
	bool BadFlag;


	// <summary>
	/// ���A�N�V�������擾
	/// </summary>
	/// <returns>���݂̃��A�N�V������Ԃ�</returns>
//	int GetReaction() { return mIsReaction; }


	/// <summary>
	/// ���A�N�V�������Z�b�g����
	/// </summary>
	/// <param name="_isScene">���݂̃��A�N�V����</param>
//	void SetReaction(int _isReaction) { mIsReaction = _isReaction; }

protected:
	// ���݂̃��A�N�V������Ԃ�
//	int mIsReaction;

private:
	// �^�C�~���O�̃t���O�Ǘ�
	bool TimingFlag;
	// ���i�������I��ł��鑀��o����Ƃ�����������́j
	int selectButtonImg;
	// �{�^���̍��WX
	int buttonX;
	// �{�^���̍��WY
	int buttonY;
	// �{�^�����ő哮����͈�(��)
	int buttonMoveLeft;
	// �{�^�����ő哮����͈�(�E)
	int buttonMoveRight;
	// �{�^���̓�����͈�
	int movebutton;

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
	// ���肪�p�[�t�F�N�g�ɂȂ�Q�[�W�̐F
	int NormalGageColor;
	// ���k����Q�[�W�̐F
	int	color;

	// �{�^�����������Ƃ��ƒʏ펞�̃p�[�t�F�N�g�G���A�̐F
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

	// ���A�N�V������`�悷�鎞�Ԃ��J�E���g����
	int count;
	// ���A�N�V������`�悷�鎞�Ԃ̍ő�l
	int countMax;
	// �J�E���g��������
	int countInit;


	// Perfect���A�N�V�����̉摜
	int perfectImg;
	//Good���A�N�V�����̉摜
	int goodImg;
	// Bad���A�N�V�����̉摜
	int badImg;

	int mEffectImg;                        // �`�悷��G�t�F�N�g
	int mPerfectEffectImg;                 // �p�[�t�F�N�g�̃G�t�F�N�g 
	int mGoodEffectImg;                    // �O�b�h�̃G�t�F�N�g
	int mBadEffectImg;                     // �o�b�h�̃G�t�F�N�g
    double mEffectScale;                   // �G�t�F�N�g�̑傫��
	double mEffectAngle;                   // �G�t�F�N�g�̉�]�p�x
	double mScalePlus;                     // �傫���̑����l
	double mAngleRotate;                   // ��]������x����
	bool mEffectFlag;                      // �G�t�F�N�g��`�悷�邩

	// Score�����t���O
	bool ScoreFlag;

	class Score* score;

	class Sound* mPerfectSound;
	class Sound* mGoodSound;
	class Sound* mBadSound;
};

