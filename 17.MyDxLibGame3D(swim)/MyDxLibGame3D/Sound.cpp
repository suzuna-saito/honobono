/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "Sound.h"
#include"SceneBase.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Sound::Sound(SceneBase& _scene)
	:mOnceSoundFlag(false)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Sound::~Sound()
{
}

/// <summary>
/// ���y���Đ�������
/// </summary>
/// <param name="_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::PlayBGM(SceneBase& _scene)
{
}

/// <summary>
/// �Q�[�����̌��ʉ��Đ�
/// </summary>
/// < param name = "_moveCheck"> �v���C���[�������Ă��邱�Ƃ��m�F </param>
/// < param name = "_hitCheck">  �v���C���[���{�[���ɂԂ��������Ƃ��m�F </param>
/// < param name = "_movecheck"> �v���C���[���S�[���������Ƃ��m�F </param>
void Sound::PlaySE(bool _moveCheck, bool _hitCheck, bool _goalCheck)
{
}

/// <summary>
/// �Đ����Ă��鉹�y���~
/// </summary>
/// < param name = "_scene"> �V�[���x�[�X����V�[����q�� </param>
void Sound::StopMusic(SceneBase& _scene)
{
}
