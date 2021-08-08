#include "GameClear.h"
#include "Title.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameClear::GameClear()
{
	SetScene(gameClear);

	// ���f�����N���A�p�ɕύX
	mModel = MV1LoadModel("data/model/player/pika/pikaHandUP.pmx");
	// �����摜�̓ǂݍ���
	mClearText = MV1LoadModel("data/model/BackGround/Clear.pmx");
	mBackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	LoadDivGraph("data/Asset/Return.png", 2, 2, 1, 100, 30, mKeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, mKeyText2, TRUE);
	mPointGraph = LoadGraph("data/Asset/mejirushi.png");
	// ���f���̈ʒu�ݒ�
	MV1SetPosition(mModel, VGet(0, -1.0, -6));
	MV1SetPosition(mClearText, VGet(0, 40, -40));
	MV1SetPosition(mBackGround, VGet(0, 10, -45));
	// �w�i�̑傫���ݒ�
	MV1SetScale(mBackGround, VGet(5.0f, 5.0f, 5.0f));
	// ���f������](�s�J�`���E���w���������Ă���̂őO�ɕύX)
	MV1SetRotationXYZ(mModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mClearText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	// ���f���̃V�F�C�v�摜�ݒ�(�s�J�`���E�̕\��ύX)
	MV1SetShapeRate(mModel, 3, 1);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameClear::~GameClear()
{
	MV1DeleteModel(mModel);
	MV1DeleteModel(mBackGround);
	MV1DeleteModel(mClearText);
	DeleteGraph(*mKeyText1);
	DeleteGraph(*mKeyText2);
	DeleteGraph(mPointGraph);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* GameClear::Update()
{
	// �V�[���J�ڏ���
	if (GetPointPosition() == mUp && CheckHitKey(KEY_INPUT_RETURN))
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new Title();
	}
	else if (GetPointPosition() == mDown && CheckHitKey(KEY_INPUT_RETURN))
	{
		SetScene(gameEnd);
	}

	// �J�[�\���ʒu�X�V
	PointUpdate();

	// ���f���̃T�C�Y��ς���
	MV1SetScale(mModel, VGet(mSize, mSize, mSize));
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

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �`��
void GameClear::Draw()
{
	MV1DrawModel(mBackGround);
	MV1DrawModel(mClearText);
	MV1DrawModel(mModel);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(540, 350, mKeyText1[GetReturnPoint()], TRUE);
	DrawGraph(540, 400, mKeyText2[GetEndPoint()], TRUE);
	if (GetPointPosition() == 1)
	{
		DrawGraph(500, 350, mPointGraph, TRUE);
	}
	else if (GetPointPosition() == 2)
	{
		DrawGraph(500, 400, mPointGraph, TRUE);
	}
	// �`��u�����h���[�h�ɂ���(������_�ł�����)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mCount);
	SetFontSize(mFontSize);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}