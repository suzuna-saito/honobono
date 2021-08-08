#ifndef _FADE_H_
#define _FADE_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include<DxLib.h>

/// <summary>
/// ���̎O���F�A���ꂼ��̒l
/// �����̒l��ς��邱�ƂŐF���ω�
/// </summary>
struct Color
{
	float m_red;
	float m_green;
	float m_blue;
};

/// <summary>
/// �t�F�[�h�C���E�t�F�[�h�A�E�g�N���X
/// </summary>
class Fade
{
public:
	Fade();			// �R���X�g���N�^
	~Fade();		// �f�X�g���N�^

	void Update(bool _InOut,Color _color);    //�X�V�֐�

	void OutProcess(Color _color);	// �t�F�[�h�A�E�g�X�V
	void InProcess(Color _color);	// �t�F�[�h�C���X�V

	void Draw();				// �`��֐�

	/*int GetFadeCount() { return mFadeCount; }*/


	bool GetEndFlag() { return mEndFlag; }

private:
	bool mEndFlag;
	int mAlphaMax;				// �A���t�@�l�̉��Z
	int mAlphaMin;				// �A���t�@�l�̌��Z
	const int mAlphaVal;		// �A���t�@�ω��l
	int mClearFadeInTime;				// �t�F�[�h�C�������鎞��(�N���A��)
	int mStartFadeInTime;				// �t�F�[�h�C�������鎞��(�����J�n��)

	int mFadeCount;				// �J�E���g

};

#endif //_FADE_H_