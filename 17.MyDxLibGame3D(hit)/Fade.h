#pragma once
struct Color;
class Fade
{
public:
	Fade();			// �R���X�g���N�^
	~Fade();		// �f�X�g���N�^

	void Update(bool _InOut,Color _color);

	void OutProcess(Color _color);	// �t�F�[�h�A�E�g�X�V
	void InProcess(Color _color);	// �t�F�[�h�C���X�V

	void Init();				// �`��

	/*int GetFadeCount() { return mFadeCount; }*/

	int fadeTime;				// �t�F�[�h�C�������鎞��(�N���A��)
	int fadeTime2;				// 

	int mFadeCount;				// �J�E���g

	bool GetEndFlag() { return mEndFlag; }

private:
	bool mEndFlag;
	int mAlphaMax;				// �A���t�@�l�̉��Z
	int mAlphaMin;				// �A���t�@�l�̌��Z
	const int mAlphaVal;		// �A���t�@�ω��l
};