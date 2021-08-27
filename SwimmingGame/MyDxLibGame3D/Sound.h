#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
#include <sys/timeb.h>
#include <time.h>
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
	void PlayBGM();

	/// <summary>
	/// ��T�����Ƃ�މ��y(���Y���Q�[���p)
	/// </summary>
	void PlayBackBGM();

	/// <summary>
	/// ���ʉ����Đ�����
	/// </summary>
	void PlaySE();


	/// <summary>
	/// �Đ����Ă��鉹�y���~�߂�
	/// </summary>
	void StopMusic();

	/// <summary>
	/// ���y������Ă��邩�`�F�b�N����
	/// </summary>
	int CheckBGM();

private:

	// �T�E���h���i�[����n���h��
	int mSoundHandle;
	// ��񂫂�̉�
	bool mOnceSoundFlag;

};

#endif //_SOUND_H_