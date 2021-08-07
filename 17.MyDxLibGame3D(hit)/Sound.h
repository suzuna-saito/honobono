#include <DxLib.h>

class SceneBase;    // �V�[����BGM�؂�ւ��Ɏg�p
class Hitchecker;   // �v���C���[�̓����m�F�Ɏg�p
class Player;       // �v���C���[�̓����m�F�Ɏg�p

/// <summary>
/// �Q�[�������y�̃N���X
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
	// ���y���Đ����邩���Ǘ�����t���O
	bool SoundFlag;
};