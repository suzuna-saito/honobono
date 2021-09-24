#ifndef _FISH_MANAGER_H_
#define _FISH_MANAGER_H_

#include"DxLib.h"

//�萔
const int FISH_NUM = 12;    // ���̐�

/// <summary>
/// ���̃x�[�X/�����N���X�̑O���錾
/// </summary>
class FishBase;
class Dance;

/// <summary>
/// �������̂܂Ƃ߃N���X
/// </summary>
class FishManager final
{
public:
	FishManager();					//�R���X�g���N�^
	~FishManager();					//�f�X�g���N�^

	void CreatFish();				//�������̐���
	void DestroyFish();				//�������̍폜

	void Updata(int _judge, float _deltaTime, bool _startflag, int _nowScene);					//�X�V�֐�

	void Draw();					//�`��֐�

	//�_���X���n�߂Ă��������ǂ����̃t���O��getter
	const bool GetStopFlag()const { return mDanceStartFlag; }

private:
	FishBase* mFish[FISH_NUM];		//�������̔z��

	int mSourceModelHandle;			//�������̃��f���n���h���ϐ�
	int mPlayerModelHandle;         //�v���C���[�̃��f���n���h���ϐ�

	//�_���X���n�܂�܂ł̃t���O��true�̂Ƃ��n�߂���Afalse�̎��͎n�߂��Ȃ�
	bool mDanceStartFlag;


	const VECTOR BEFORE_DIVING_POS[FISH_NUM];	//���ꂼ��̋������̍��W
	const VECTOR BEFORE_DIVING_ROTATE[FISH_NUM];//���ꂼ��̋������̌���
	const VECTOR SET_DANCING_POS[FISH_NUM];		//���ꂼ��̋������̃A�[�e�B�X�e�B�b�N�X�C�~���O�J�n���̍��W

	//---------------�f�o�b�N�p�ϐ�-------------
	const int DEBUG_SPHERE_COLOR[FISH_NUM];		//���ꂼ��̋�������DrawSphere3D�f�o�b�N�p�̐F
};


#endif // !_FISH_MANAGER_H_
