#pragma once

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
	int gageColor;
	// ���k����Q�[�W�̐F
	int	color;

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

	//  Perfect
	// Perfect�̃t���O�Ǘ�
	bool PerfectFlag;
	// Perfect���A�N�V�����̉摜
	int perfectImg;

	//  Good
	// Good�̃t���O�Ǘ�
	bool GoodFlag;
	//Good���A�N�V�����̉摜
	int goodImg;

	//  Bad
	// Bad�̃t���O�Ǘ�
	bool BadFlag;
	// Bad���A�N�V�����̉摜
	int badImg;

	// �X�R�A
	int score;
	// �X�R�A���ؓ��ꂷ��ϐ�
	int scoreMax;
	// Score�����t���O
	bool ScoreFlag;
	// 
	int scoreX;
	// 
	int scoreY;
	
};

