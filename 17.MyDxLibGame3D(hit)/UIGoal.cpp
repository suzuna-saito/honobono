#include "UIGoal.h"
#include "UIBase.h"
#include "Player.h"
#include "Satoshi.h"

/// <summary>
/// �R���X�g���N�^ 
/// </summary>
UIGoal::UIGoal()
	:UIBase(goalImg)
	, goalX(560)
	, goalY(90)
	, baseX(550)
	, baseY(50)
	, playerX(560)
	, playerY(340)
	, PosY1(0.0f)
	, PosY2(0.0f)
	, distanceRatio(0.0f)
	, MainPosY(0.0f)
	, GoalFlag(FALSE)
	, playerMaxY(120)
	, ratio(0.255f)
{
	// �摜�ǂݍ���
	goalImg = LoadGraph("data/Asset/satoshi.png");
	baseImg = LoadGraph("data/Asset/base.png");
	playerImg = LoadGraph("data/Asset/pikachu.png");
}

/// <summary>
/// �f�X�g���N�^ 
/// </summary>
UIGoal::~UIGoal()
{
	// �摜������
	DeleteGraph(goalImg);
	DeleteGraph(baseImg);
	DeleteGraph(playerImg);
}

/// <summary>
/// �����̔䗦���o�� 
/// </summary>
/// <param name="player"> �v���C���[�̍��W�擾�̂��ߎg�p </param>
/// <param name="satoshi"> �T�g�V�̍��W�擾�̂��ߎg�p </param>
void UIGoal::GetDy(Player& player, Satoshi& satoshi)
{
	// Satoshi��PosY��GetPosY�֐��̒ǉ�
	PosY1 = satoshi.GetPosY();
	// Player��PosY��GetPosY�֐��̒ǉ�
	PosY2 = player.GetPosY();

	// �Q�[�����̋��� = �T�g�VZ���W(PosY1) - �s�J�`���E��Y���W(PosY2)
	MainPosY = PosY1 - PosY2;
	// �����̔䗦
	distanceRatio = (playerY - goalY) / MainPosY;	
	// �Q�[���̂ق��̈ʒu�\�����ς���Ă���̂ŁA���x����
	distanceRatio *= ratio;
}

/// <summary>
/// �X�V
/// </summary>
void UIGoal::Update()
{
	// UI�̈ʒu���狗���̔䗦������
	playerY -= distanceRatio;

	// UI�̋����ŃS�[���v�Z
	// SceneBase�̂ق��ŃN���A��ʂɑJ��
	if (playerY <= playerMaxY)
	{
		// �S�[���t���O���u�^�v�ɂ���
		GoalFlag = TRUE;
	}
}

/// <summary>
/// �`��
/// </summary>
void UIGoal::Draw()
{
	DrawGraph(baseX, baseY, baseImg, FALSE);
	DrawGraph(goalX, goalY, goalImg, TRUE);
	DrawGraph(playerX, playerY, playerImg, TRUE);

}