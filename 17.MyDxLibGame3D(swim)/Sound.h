#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

/// <summary>
/// �����֌W�N���X
/// </summary>
class Sound
{
public:
	// �R���X�g���N�^
	Sound();
	// �f�X�g���N�^
	~Sound();
	// ���y���Đ�
	void PlayBGM(int _scene);
	// ���ʉ����Đ�
	void PlaySE(bool _movecheck, bool _hitCheck, bool _goalCheck);
	// ���y���~�߂�
	void StopMusic(int _scene);

private:
	// �^�C�g��BGM
	int mTitleBGM;
	// �Q�[��BGM
	int mGameBGM;
	// �N���ABGM
	int mClearBGM;
	// �Q�[���I�[�o�[BGM
	int mOverBGM;
	// �^�C�g������Q�[����ʈړ�����Ƃ��̌��ʉ�
	int mTitleSound;
	// ���@�����E�Ɉړ������Ƃ��̌��ʉ�
	int mMoveSound;
	// ���@���G�@�ɂԂ������Ƃ��̌��ʉ�
	int mDamageSound;
	// �S�[���������̌��ʉ�
	int mGoalSound;
	// �Q�[���N���A���̌��ʉ�
	int mClearSound;
	// �Q�[���I�[�o�[���̌��ʉ�
	int mOverSound;
	// ��񂫂�̉�
	bool mOnceSoundFlag;
};

#endif //_SOUND_H_