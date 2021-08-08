#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

// �O���錾
class SceneBase;

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
	/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
	/// <return> �ǂݍ���ł��鉹�y���Đ� </return> 
	void PlayBGM(SceneBase& _scene);

	/// <summary>
	/// ���ʉ����Đ�����
	/// </summary>
	/// < param name = "_moveCheck"> �v���C���[�������Ă��邱�Ƃ��m�F </param>
	/// < param name = "_hitCheck">  �v���C���[���{�[���ɂԂ��������Ƃ��m�F </param>
	/// < param name = "_movecheck"> �v���C���[���S�[���������Ƃ��m�F </param>
	void PlaySE(bool _movecheck, bool _hitCheck, bool _goalCheck);

	/// <summary>
	/// �Đ����Ă��鉹�y���~�߂�
	/// </summary>
	/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
	void StopMusic(SceneBase& _scene);

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