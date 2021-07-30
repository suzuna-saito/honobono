#include "GameClear.h"

// �R���X�g���N�^
GameClear::GameClear()
	:Count(0)
	, ColorAlpha(5)
{
	// ���f�����N���A�p�ɕύX
	Model = MV1LoadModel("data/model/player/pika/pikaHandUP.pmx");
	// �����摜�̓ǂݍ���
	ClearText = MV1LoadModel("data/model/BackGround/Clear.pmx");
	BackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	LoadDivGraph("data/Asset/Return.png", 2, 2, 1, 100, 30, KeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, KeyText2, TRUE);
	PointGraph = LoadGraph("data/Asset/mejirushi.png");
	// ���f���̈ʒu�ݒ�
	MV1SetPosition(Model, VGet(0, -1.0, -6));
	MV1SetPosition(ClearText, VGet(0, 40, -40));
	MV1SetPosition(BackGround, VGet(0, 10, -45));
	// �w�i�̑傫���ݒ�
	MV1SetScale(BackGround, VGet(5.0f, 5.0f, 5.0f));
	// ���f������](�s�J�`���E���w���������Ă���̂őO�ɕύX)
	MV1SetRotationXYZ(Model, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(ClearText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(BackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	// ���f���̃V�F�C�v�摜�ݒ�(�s�J�`���E�̕\��ύX)
	MV1SetShapeRate(Model, 3, 1);
}

// �f�X�g���N�^
GameClear::~GameClear()
{
	MV1DeleteModel(Model);
	MV1DeleteModel(BackGround);
	MV1DeleteModel(ClearText);
	DeleteGraph(*KeyText1);
	DeleteGraph(*KeyText2);
	DeleteGraph(PointGraph);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �`��
void GameClear::Draw(SceneBase& scene)
{
	MV1DrawModel(BackGround);
	MV1DrawModel(ClearText);
	MV1DrawModel(Model);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(540, 350, KeyText1[scene.GetReturnPoint()], TRUE);
	DrawGraph(540, 400, KeyText2[scene.GetEndPoint()], TRUE);
	if (scene.GetPointPosition() == 1)
	{
		DrawGraph(500, 350, PointGraph, TRUE);
	}
	else if (scene.GetPointPosition() == 2)
	{
		DrawGraph(500, 400, PointGraph, TRUE);
	}
	// �`��u�����h���[�h�ɂ���(������_�ł�����)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Count);
	SetFontSize(36);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}

// �X�V
void GameClear::Update()
{
	// ���f���̃T�C�Y��ς���
	MV1SetScale(Model, VGet(Size, Size, Size));
	Size += SizePoint;
	// ���f���̃T�C�Y���g��A�k��������
	if (Size > 1.02)
	{
		SizePoint *= -1;
	}
	else if (Size < 1.0)
	{
		SizePoint *= -1;
	}

	// �`��u�����h���[�h��Z����ς���
	if (Count > 255)
	{
		ColorAlpha *= -1;
	}
	else if (Count < 0)
	{
		ColorAlpha *= -1;
	}

	Count += ColorAlpha;
}