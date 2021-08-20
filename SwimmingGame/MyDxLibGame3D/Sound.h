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
	Sound(SceneBase& _scene);
	// �f�X�g���N�^
	~Sound();

	/// <summary>
	/// �V�[�����Ƃŉ��y���Đ�����
	/// </summary>
/// < param name = "_scene"> �V�[���擾 </param>
	void PlayBGM(SceneBase& _scene);

	/// <summary>
	/// ���ʉ����Đ�����
	/// </summary>
	/// < param name = "_scene"> �V�[���擾 </param>
	void PlaySE(SceneBase& _scene);



	/// <summary>
	/// �Đ����Ă��鉹�y���~�߂�
	/// </summary>
	/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
	void StopMusic(SceneBase& _scene);

private:

	// �^�C�g��BGM
	int mTitleBGM;
	// �Q�[��BGM_1
	int mGameBGM1;
	// �Q�[��BGM_2
	int mGameBGM2;
	// �Q�[��BGM_3
	int mGameBGM3;
	// ���U���gBGM
	int mResultBGM;

	// �^�C�g������Q�[����ʈړ�����Ƃ��̌��ʉ�
	int mTitleSound;
	// �p�[�t�F�N�g���̌��ʉ�
	int mPerfectSound;
	// �O�b�h���̌��ʉ�
	int mGoodSound;
	// �o�b�h���̌��ʉ�
	int mBadSound;
	// ��э���Ő��̓��������̉�
	int mWaterInSound;
	// �V���N���ł���Ղ���Ղ��鉹
	int mWaterOutSound;
	// ���U���g�łȂ���ʉ�
	int mResultSound;

	// ��񂫂�̉�
	bool mOnceSoundFlag;

	// ���Y���{�^��
	Timing* timing;
	
};

#endif //_SOUND_H_