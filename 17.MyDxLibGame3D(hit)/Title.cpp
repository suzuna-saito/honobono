#include "Title.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Title::Title()
	:mCount(0)
	,mColorAlpha(5)
	,mFontSize(36)
{
	// �R�c���f���̓ǂݍ���
	mModel = MV1LoadModel("data/model/player/pika/pikapika.pmx");
	mBallModel = MV1LoadModel("data/model/ball/monsterBall.pmx");
	mBackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	mTitleText = MV1LoadModel("data/model/BackGround/Title.pmx");
	LoadDivGraph("data/Asset/Start.png", 2, 2, 1, 100, 30, mKeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, mKeyText2, TRUE);
	mPointGraph = LoadGraph("data/Asset/mejirushi.png");

	// ���f���̈ʒu�ݒ�
	MV1SetPosition(mModel, VGet(0, -1.0, -6));
	MV1SetPosition(mBallModel, VGet(-2.5, 3, -4));
	MV1SetPosition(mTitleText, VGet(18, 35, -44));
	MV1SetPosition(mBackGround, VGet(0, 10, -45));
	// �w�i�̑傫���ύX
	MV1SetScale(mBackGround, VGet(5.0f, 5.0f, 5.0f));
	// ���f������](�s�J�`���E���w���������Ă���̂őO�ɕύX)
	MV1SetRotationXYZ(mModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBallModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mTitleText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Title::~Title()
{
	MV1DeleteModel(mModel);
	MV1DeleteModel(mBallModel);
	MV1DeleteModel(mBackGround);
	MV1DeleteModel(mTitleText);
	DeleteGraph(mPointGraph);
	DeleteGraph(*mKeyText1);
	DeleteGraph(*mKeyText2);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/// <summary>
/// �`��
/// </summary>
/// <param name="scene">SceneBase�N���X�̃|�C���^</param>
void Title::Draw(SceneBase& _scene)
{
	MV1DrawModel(mBackGround);
	MV1DrawModel(mTitleText);
	MV1DrawModel(mModel);
	MV1DrawModel(mBallModel);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(540, 350, mKeyText1[_scene.GetStartPoint()], TRUE);
	DrawGraph(540, 400, mKeyText2[_scene.GetEndPoint()], TRUE);
	if (_scene.GetPointPosition() == 1)
	{
		DrawGraph(500, 350, mPointGraph, TRUE);
	}
	else if (_scene.GetPointPosition() == 2)
	{
		DrawGraph(500, 400, mPointGraph, TRUE);
	}

	// �`��u�����h���[�h�ɂ���(������_�ł�����)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mCount);
	SetFontSize(mFontSize);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}

/// <summary>
/// �X�V
/// </summary>
void Title::Update()
{
	// ���f���̃T�C�Y��ς���
	MV1SetScale(mModel, VGet(mSize, mSize, mSize));
	// �{�[������]������
	MV1SetRotationXYZ(mBallModel, VGet(0, mMove, -0.5));

	mMove += 0.05f;
	mSize += mSizePoint;

	// ���f���̃T�C�Y���g��A�k��������
	if (mSize > 1.02)
	{
		mSizePoint *= -1;
	}
	else if (mSize < 1.0)
	{
		mSizePoint *= -1;
	}

	// �`��u�����h���[�h��Z����ς���
	if (mCount > 255)
	{
		mColorAlpha *= -1;
	}
	else if (mCount < 0)
	{
		mColorAlpha *= -1;
	}

	mCount += mColorAlpha;
}