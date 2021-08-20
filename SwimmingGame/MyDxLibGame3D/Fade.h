#pragma once
struct Color;

/// <summary>
/// �t�F�[�h�̃N���X
/// </summary>
class Fade
{
public:
	Fade();			// �R���X�g���N�^
	~Fade();		// �f�X�g���N�^

	bool Draw(bool _InOut,Color _color);   // �X�V

	bool OutProcess(Color _color);	// �t�F�[�h�A�E�g�X�V
	bool InProcess(Color _color);	// �t�F�[�h�C���X�V

	void Init();				// �`��

	/*int GetFadeCount() { return mFadeCount; }*/

	int mfadeTime;				// �t�F�[�h�C�������鎞��(�N���A��)
	int mfadeTime2;				// 

	int mFadeCount;				// �J�E���g

	bool GetEndFlag() { return mEndFlag; }

private:
	bool mEndFlag;              // �t�F�[�h�I���
	int mAlphaMax;				// �A���t�@�l�̉��Z
	int mAlphaMin;				// �A���t�@�l�̌��Z
	const int mAlphaVal;		// �A���t�@�ω��l
};