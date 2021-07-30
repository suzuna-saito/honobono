#include "Title.h"

// �R���X�g���N�^
Title::Title()
	:Count(0)
	,ColorAlpha(5)
{
	// �R�c���f���̓ǂݍ���
	Model = MV1LoadModel("data/model/player/pika/pikapika.pmx");
	BallModel = MV1LoadModel("data/model/ball/monsterBall.pmx");
	BackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	TitleText = MV1LoadModel("data/model/BackGround/Title.pmx");
	LoadDivGraph("data/Asset/Start.png", 2, 2, 1, 100, 30, KeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, KeyText2, TRUE);
	PointGraph = LoadGraph("data/Asset/mejirushi.png");

	// ���f���̈ʒu�ݒ�
	MV1SetPosition(Model, VGet(0, -1.0, -6));
	MV1SetPosition(BallModel, VGet(-2.5, 3, -4));
	MV1SetPosition(TitleText, VGet(18, 35, -44));
	MV1SetPosition(BackGround, VGet(0, 10, -45));
	// �w�i�̑傫���ύX
	MV1SetScale(BackGround, VGet(5.0f, 5.0f, 5.0f));
	// ���f������](�s�J�`���E���w���������Ă���̂őO�ɕύX)
	MV1SetRotationXYZ(Model, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(BallModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(TitleText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(BackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
}

// �f�X�g���N�^
Title::~Title()
{
	MV1DeleteModel(Model);
	MV1DeleteModel(BallModel);
	MV1DeleteModel(BackGround);
	MV1DeleteModel(TitleText);
	DeleteGraph(PointGraph);
	DeleteGraph(*KeyText1);
	DeleteGraph(*KeyText2);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �`��
void Title::Draw(SceneBase& scene)
{
	MV1DrawModel(BackGround);
	MV1DrawModel(TitleText);
	MV1DrawModel(Model);
	MV1DrawModel(BallModel);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(540, 350, KeyText1[scene.GetStartPoint()], TRUE);
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
void Title::Update()
{
	// ���f���̃T�C�Y��ς���
	MV1SetScale(Model, VGet(Size, Size, Size));
	// �{�[������]������
	MV1SetRotationXYZ(BallModel, VGet(0, Move, -0.5));

	Move += 0.05f;
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