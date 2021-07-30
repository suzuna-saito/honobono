#pragma once
#include <DxLib.h>

// �V�[����BGM�؂�ւ��Ɏg�p
class SceneBase;
// �v���C���[�̓����m�F�Ɏg�p
class Hitchecker;
class Player;

class Sound
{
public:
	// �R���X�g���N�^
	Sound();
	// �f�X�g���N�^
	~Sound();
	// ���y���Đ�
	void PlayBGM(SceneBase& _scene);
	// ���ʉ����Đ�
	void PlaySE(bool _movecheck, bool _hitCheck, bool _goalCheck);
	// ���y���~�߂�
	void StopMusic(SceneBase& _scene);

private:
	// �^�C�g��BGM
	int titleBGM;
	// �Q�[��BGM
	int gameBGM;
	// �N���ABGM
	int clearBGM;
	// �Q�[���I�[�o�[BGM
	int overBGM;
	// �^�C�g������Q�[����ʈړ�����Ƃ��̌��ʉ�
	int titleSound;
	// ���@�����E�Ɉړ������Ƃ��̌��ʉ�
	int moveSound;
	// ���@���G�@�ɂԂ������Ƃ��̌��ʉ�
	int damageSound;
	// �S�[���������̌��ʉ�
	int goalSound;
	// �Q�[���N���A���̌��ʉ�
	int clearSound;
	// �Q�[���I�[�o�[���̌��ʉ�
	int overSound;
	// ��񂫂�̉�
	bool SoundFlag;
};