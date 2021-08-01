#include "BackGround.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
BackGround::BackGround()
	: cx(0.5f)
	, cy(0.5f)
	, angle(0.0f)
	, x1(0.0f)
	, y1(0.0f)
	, z1(20.0f)
	, size(130.0f)
	, x2(0.0f)
	, y2(40.0f)
	, z2(50.0f)
	, size2(140.0f)
	, scrMax(-30)
	, scrInitY(0)
	, scrInitZ(20)
{
	// �w�i���W
	DrawPos = VGet(x1, y1, z1);

	// �w�i�摜�ǂݍ���
	bg = LoadGraph("data/Asset/sougen.jpeg");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BackGround::~BackGround()
{
	DeleteGraph(bg);
}

/// <summary>
/// �`��
/// </summary>
void BackGround::Draw()
{
	// 3D��Ԃɉ摜��`��
	DrawBillboard3D(DrawPos, cx, cy, size, angle, bg, FALSE);                       // �ꖇ�ڂ̉摜

	DrawBillboard3D(VAdd(DrawPos,VGet(x2,y2,z2)), cx, cy, size2, angle, bg, FALSE);// �񖇖ڂ̉摜
}

/// <summary>
/// �X�N���[��
/// </summary>
void BackGround::Scroll()
{
	// �X�N���[���X�s�[�h����
	DrawPos.y -= SCROLL_SPEED;
	// �w�i�g��X�s�[�h����
	DrawPos.z -= EXPANSION_SPEED;

	// ��萔�i�񂾂猳�̍��W�ɖ߂�(���[�v)
	if (DrawPos.y <= scrMax)
	{
		// Y���W�����̍��W�ɖ߂�
		DrawPos.y = scrInitY;
		// Z���W�����̍��W�ɖ߂�
		DrawPos.z = scrInitZ;
	}
}
