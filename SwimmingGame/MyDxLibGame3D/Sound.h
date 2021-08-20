#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

// �O���錾
class SceneBase;
class Timing;

/// <summary>
/// �����֌W�N���X
/// </summary>
class Sound
{
public:
	// �R���X�g���N�^
	Sound(const char* _filePath);
	// �f�X�g���N�^
	~Sound();

	/// <summary>
	/// �V�[�����Ƃŉ��y���Đ�����
	/// </summary>
/// < param name = "_scene"> �V�[���擾 </param>
	void PlayBGM();

	/// <summary>
	/// ���ʉ����Đ�����
	/// </summary>
	/// < param name = "_scene"> �V�[���擾 </param>
	void PlaySE();



	/// <summary>
	/// �Đ����Ă��鉹�y���~�߂�
	/// </summary>
	/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
	void StopMusic();

private:

	int mSoundHandle;

	// ��񂫂�̉�
	bool mOnceSoundFlag;

};

#endif //_SOUND_H_