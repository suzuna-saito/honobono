#include "BackGround.h"
/*
�Ȃ񂿂���Ĕw�i�i�G�j
*/

#include "DxLib.h"

/*
�R���X�g���N�^
*/
BackGround::BackGround()
	:size(130)
{
	// �w�i���W
	DrawPos = VGet(0, 0, 20);

	// �w�i�摜�ǂݍ���
	bg = LoadGraph("data/Asset/sougen.jpeg");
}


/*
�f�X�g���N�^
*/
BackGround::~BackGround()
{
}

/*
�`��
*/
void BackGround::Draw()
{
	// 3D��Ԃɉ摜��`��
	DrawBillboard3D(DrawPos, 0.5, 0.5, size, 0, bg, FALSE);                       // �ꖇ�ڂ̉摜

	DrawBillboard3D(VAdd(DrawPos,VGet(0,40,50)), 0.5, 0.5, size+10, 0, bg, FALSE);// �񖇖ڂ̉摜
}

/*
�X�N���[��
*/
void BackGround::Scroll()
{
	DrawPos.y -= SCROLL_SPEED;
	DrawPos.z -= EXPANSION_SPEED;

	// ��萔�i�񂾂猳�̍��W�ɖ߂��Ă�����(���[�v)
	if (DrawPos.y <= -30)
	{
		DrawPos.y = 0;
		DrawPos.z = 20;
	}
}
