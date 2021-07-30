#include "Satoshi.h"
#include "BackGround.h"
#include"DxLib.h"
#include"SceneBase.h"
#include "UIGoal.h"

// �R���X�g���N�^
Satoshi::Satoshi()
	:satoshiGraphHandle(-1)
	, angle(0.0f)
	, centerX(0.5f), centerY(0.5f)
{
	if (satoshiGraphHandle == -1)
	{
		satoshiGraphHandle = LoadGraph("data/Asset/SatoshiDot.png");
	}

	pos = VGet(-10, 0, 810);  // ����340,0,500
	PosY = 1800.0f; // Y���W�擾
	size = 300;    // ����300
	hitRadius = 0;

	// �w�i�̃X�N���[���Ɠ��������ňړ�
	velocity = VGet(0.0f, 0.0f, 0.0f);
}

// �f�X�g���N�^
Satoshi::~Satoshi()
{
}

// �X�V
void Satoshi::Update(SceneBase& scene, UIGoal& uiGoal)
{
	// �T�g�V�ړ��J�n�ʒu
	if (uiGoal.GetUIPosY() <= 140)
	{
		// �w�i�̃X�N���[���Ɠ��������ňړ�
		velocity = VGet(0.0f, -SCROLL_SPEED * 2, -EXPANSION_SPEED);
	}

	pos = VAdd(pos, velocity);
}

void Satoshi::Draw()
{
	DrawBillboard3D(pos, centerX, centerY, size, angle, satoshiGraphHandle, true);
}
