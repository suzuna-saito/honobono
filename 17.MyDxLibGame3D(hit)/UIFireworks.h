#include <DxLib.h>
#include "UIBase.h"

// X�̍��W
const int POS_X = 150;
// Y�̍��W
const int POS_Y = 100;		

// �`��|�W�V�������������炷���߂̒l
const int ADD_POS = 150;

// ��ڂƓ�ڂ̉ԉ΂̊g��lX
const int EXPANSION_X = 230;
// ��ڂƓ�ڂ̉ԉ΂̊g��lY
const int EXPANSION_Y = 250;
// �O�ڂ̉ԉ΂̊g��l
const int EXPANSION3 = 400;	
// �ԉ΂��o���^�C�~���O(�ő�)
const int TIME = 240;		

/// <summary>
/// �S�[������ɏo���ԉ΂̉��o�̃N���X
/// </summary>
class UIFireworks
{
public:
	// �R���X�g���N�^
	UIFireworks();
	// �f�X�g���N�^
	~UIFireworks();

	// �X�V
	void Update();
	// �`��
	void Draw();

	/// <summary>
	/// �S�[������ɉԉ΂����ԍ��ŕ`�悷��
	/// </summary>
	/// <returns> �ԉ΂����ԍ��ŏo�����߂̃J�E���^�[ </returns>
	int GetclearCount() { return clearCount; }
	// �ԉ΂��o���^�C�~���O(�ő�)
	const int time;

private:
	// �ԉ΂̉摜�ǂݍ���
	int fireworksImg;
	// �ԉ΂̉摜�ǂݍ���2
	int fireworksImg2;
	// �ԉ΂̉摜�ǂݍ���3
	int fireworksImg3;

	// 1�ڂ̉ԉ΂̕`��t���O
	bool mDrawFlag;
	// 2�ڂ̉ԉ΂̕`��t���O
	bool mDrawFlag2;
	// 3�ڂ̉ԉ΂̕`��t���O
	bool mDrawFlag3;

	// �`�悳����|�W�V����X
	const int mDrawPosX;
	// �`�悳����|�W�V����Y
	const int mDrawPosY;

	// �N���A���Ă���������
	int clearCount;				
};