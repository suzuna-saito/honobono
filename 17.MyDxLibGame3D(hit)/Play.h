#pragma once
#include "SceneBase.h"
#include "BackGround.h"
#include "Player.h"
#include "UIGoal.h"
#include "UIFireworks.h"
#include "Satoshi.h"
#include "ObstructManager.h"
#include "Hitchecker.h"


/// <summary>
/// �v���C�V�[���̐����A�`��
/// </summary>
class Play : public SceneBase
{
public:
    /// �R���X�g���N�^
    Play();
    /// �f�X�g���N�^
    ~Play();

    /// <summary>
    /// �v���C�V�[���̍X�V����
    /// </summary>
    SceneBase* Update()override;

    /// <summary>
    /// �v���C�V�[���̕`��
    /// </summary>
    void Draw()override;

private:
	// �w�i�𐶐�.
	BackGround* backGround;
	// �v���C���[�𐶐�.
	Player* player;
	// UI�i�S�[���j�̐���
	UIGoal* uiGoal;
	// UI(�ԉ�)�̐���
	UIFireworks* uiFire;
	// �T�g�V�𐶐�
	Satoshi* satoshi;
	// ��Q���𐶐�.
	ObstructManager* obstructManager;
	// �����蔻��𐶐�
	HitChecker* hit;
};