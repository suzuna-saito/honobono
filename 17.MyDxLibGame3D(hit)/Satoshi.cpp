#include "Satoshi.h"
#include "BackGround.h"
#include"DxLib.h"
#include"SceneBase.h"
#include "UIGoal.h"
#include "UIBase.h"

/// <summary>
/// �R���X�g���N�^ 
/// </summary>
Satoshi::Satoshi()
	:UIBase(satoshiImg)
	, satoshiImg(-1)
	, angle(0.0f)
	, centerX(0.5f)
	, centerY(0.5f)
	, x(-10.0f)
	, y(0.0f)
	, z(810.0f)
	, veloX(0.0f)
	, veloY(0.0f)
	, veloZ(0.0f)
	, size(300.0f)
	, posY(1800.0f)
	, posMax(140)
{
	if (satoshiImg == -1)
	{
		satoshiImg = LoadGraph("data/Asset/SatoshiDot.png");
	}

	// �T�g�V(�S�[��)�̃|�W�V�����ݒ�
	pos = VGet(x, y, z);

	// �w�i�̃X�N���[���Ɠ��������ňړ�
	velocity = VGet(veloX, veloY, veloZ);
}

/// <summary>
/// �f�X�g���N�^ 
/// </summary>
Satoshi::~Satoshi()
{
	// �T�g�V�̉摜�폜
	DeleteGraph(satoshiImg);
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="scene"> �Q�[���V�[���ɓ����Ă���`�悷�邽�� </param>
/// <param name="uiGoal"> �v���C���[�Ƃ̋����𑪂邽�� </param>
void Satoshi::Update(UIGoal& _uiGoal)
{
	// �T�g�V�ړ��J�n�ʒu
	if (_uiGoal.GetUIPosY() <= posMax)
	{
		// �w�i�̃X�N���[���Ɠ��������ňړ�
		velocity = VGet(veloX, -SCROLL_SPEED * 2, -EXPANSION_SPEED);
	}
	// �T�g�V�̃|�W�V�����ɑ��x�ǉ�
	pos = VAdd(pos, velocity);
}

/// <summary>
/// �`��
/// </summary>
void Satoshi::Draw()
{
	// �T�g�V�̕`��
	DrawBillboard3D(pos, centerX, centerY, size, angle, satoshiImg, true);
}
