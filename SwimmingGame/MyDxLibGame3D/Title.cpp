#include "Title.h"
#include "Tutorial.h"
#include "Camera.h"
#include "Sound.h"
#include "Input.h"
#include "Play.h"
#include "Training.h"



const float RAIT = 0.57;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Title::Title()
	: i(0)
	, mAlpha(0)
	, mTextAlpha(0)
	, mCount(6)
	, mTextCount(1)
	, mEndFlag(false)
	, mFishPos{ VGet(-50.0f, -200.0f, 80.0f), VGet(50.0f, -200.0f, 80.0f) }
	, mTextPos{ VGet(-30.0f, 10.0f, 40.0f), VGet(-2.5f,-1.0f,10.0f)
			  ,VGet(-1.0f,-2.0f,10.0f) }
	, mCursorPos(VGet(-0.05f, -0.15f, 2.0f))
	, mBackPosX(0)
	, mBackPosY(0)
	, mFishRotate{ VGet(10.0f,0.0f,-1.5f),VGet(-0.5f,0.0f,-1.5f) }
	, mFishSize{ VGet(1.5f,1.5f,0.5f), VGet(1.5f,1.5f,0.5f) }
	, mTextSize{ VGet(10.0f,10.0f,1.0f), VGet(1.0f,1.0f,1.0f), VGet(1.0f,1.0f,1.0f) }
	, POINT_X(0.5f)
	, POINT_Y(0.5f)
	, SIZE(1.0f)
	, ANGLE(0.0f)
	, FISH_NUM(2)
	, TEXT_NUM(3)
	, BACK_EXTEND_X(2000)
	, BACK_EXTEND_Y(1100)
	, CURSOR_SIZE(1.0f)
	, CURSOR_ANGLE(0.0f)
	, GAME_START(1)
	, EXIT(2)
	, mCursorPoint(1)
	, ALPHA_MAX_POINT(255)
	, ALPHA_MIN_POINT(0)
	, FONT_SIZE(60)
	, mJympPower{ 7.0f , 7.0f }
	, mGravity(0.1f)
	, mJympFlag{ false,false }
	, mKeepPower(7.0f)
	, mTitleBGM(nullptr)
	, mTitleSE(nullptr)
	, mCancelSE(nullptr)
	, mRubiPosX(380)
	, mRubiPosY(160)
	, mIconPosX(1180)
	, mIconPosY(920)
	, mTeamNamePosX(1280)
	, mTeamNamePosY(920)
{
	SetScene(title);

	ChangeLightTypeDir(VGet(RAIT, RAIT, RAIT));
	SetLightDifColor(GetColorF(1.0f, 1.0f, 1.0f, 0));
	SetLightSpcColor(GetColorF(0.33f, 0.33f, 0.33f, 0));
	SetLightAmbColor(GetColorF(0.57f, 0.57f, 0.57f, 0));

	// ���f�������[�h
	mFishModel = MV1LoadModel("data/model/TitleAsset/Fish.mqo");
	mTextModel[0] = MV1LoadModel("data/model/TitleAsset/TitleText.mqo");
	mTextModel[1] = MV1LoadModel("data/model/TextAsset/GameStart.mqo");
	mTextModel[2] = MV1LoadModel("data/model/TextAsset/Exit.mqo");

	// �摜�����[�h
	mCursor = LoadGraph("data/model/TextAsset/Cursor.png");
	mTextTexture = LoadGraph("data/model/TitleAsset/texture/watergarasu.jpg");
	mBackGroundGraph = LoadGraph("data/model/TitleAsset/Title.png");
	mRubiGraph = LoadGraph("data/model/TitleAsset/titleRubi.png");
	mIconGraph = LoadGraph("data/model/TitleAsset/Icon1.png");
	mTeamNameGraph = LoadGraph("data/model/TitleAsset/team.png");

	// �e�N�X�`���\��t��
	MV1SetTextureGraphHandle(mTextModel[0], 0, mTextTexture, true);

	// �T�E���h�̃��[�h
	mTitleBGM = new Sound("data/newSound/bgm/title.mp3");
	mTitleSE = new Sound("data/newSound/se/startSE.mp3");
	mCancelSE = new Sound("data/newSound/se/cancelSE.mp3");

	// BGM�̍Đ�
	mTitleBGM->PlayBGM();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Title::~Title()
{
	DeleteGraph(mTextTexture);
	MV1DeleteModel(mFishModel);
	MV1DeleteModel(*mTextModel);
	DeleteGraph(mCursor);
	DeleteGraph(mBackGroundGraph);
	DeleteGraph(mRubiGraph);
	DeleteGraph(mIconGraph);
	delete mTitleBGM;
	delete mTitleSE;
	delete mCancelSE;
}


// �X�V����
/// <return>�V�[���̃|�C���^</return>
SceneBase* Title::Update()
{
	UpdateKey();
	// �V�[���J�ڏ���
	if (mCursorPoint == GAME_START && Key[KEY_INPUT_SPACE] == 1)
	{
		// �^�C�g���̌��ʉ�
		mTitleSE->PlaySE();
		// �^�C�g����BGM���~�߂�
		mTitleBGM->StopMusic();
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		//return new Tutorial();
		//return new Play();
		return new Training();

	}
	else if (mCursorPoint == EXIT && Key[KEY_INPUT_SPACE] == 1)
	{
		// �Q�[���I����I�������Ƃ��ɂȂ���ʉ�
		mCancelSE->PlaySE();
		SetScene(gameEnd);
	}
	
	CursorUpdate();
	FishMove();

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

// �J�[�\���̍X�V����
void Title::CursorUpdate()
{
	// �J�[�\���ړ�
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mCursorPos.y = -0.15f;
		mCursorPoint = GAME_START;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mCursorPos.y = -0.35f;
		mCursorPoint = EXIT;
	}

	// �摜�̓����x��ύX
	if (mAlpha > ALPHA_MAX_POINT)
	{
		mCount *= -1;
	}
	else if (mAlpha < ALPHA_MIN_POINT)
	{
		mCount *= -1;
	}
	if (mTextAlpha > ALPHA_MAX_POINT)
	{
		mTextCount *= -1;
	}
	else if (mTextAlpha < ALPHA_MIN_POINT)
	{
		mTextCount *= -1;
	}

	mAlpha += mCount;
	mTextAlpha += mTextCount;
}

// �`��
void Title::Draw()
{
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	// �w�i�`��
	DrawExtendGraph(mBackPosX, mBackPosY,
		BACK_EXTEND_X, BACK_EXTEND_Y, mBackGroundGraph, true);
	
	// ����`��
	for (i = 0; i < FISH_NUM; i++)
	{
		MV1SetPosition(mFishModel, mFishPos[i]);
		MV1SetScale(mFishModel, mFishSize[i]);
		MV1SetRotationXYZ(mFishModel, mFishRotate[i]);
		MV1DrawModel(mFishModel);
	}

	// �e�L�X�g��`��
	for (i = 0; i < TEXT_NUM; i++)
	{
		MV1SetPosition(mTextModel[i], mTextPos[i]);
		MV1SetScale(mTextModel[i], mTextSize[i]);
		MV1DrawModel(mTextModel[i]);
	}

	// ���r��`��
	DrawExtendGraph(mRubiPosX, mRubiPosY,1500,550,mRubiGraph,TRUE);
	// �A�C�R����`��
	DrawGraph(mIconPosX, mIconPosY, mIconGraph, TRUE);
	// �`�[�����`��
	DrawGraph(mTeamNamePosX, mTeamNamePosY, mTeamNameGraph, TRUE);

	// �A���t�@�ŕ\������摜��`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlpha);
	DrawBillboard3D(mCursorPos, POINT_X, POINT_Y,
		CURSOR_SIZE, CURSOR_ANGLE, mCursor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mAlpha);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mTextAlpha);
	SetFontSize(FONT_SIZE);
	DrawString(750, 750, "Push The SPACE", GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mTextAlpha);
}

/// <summary>
/// ���̋���
/// </summary>
void Title::FishMove()
{
	// ���̃W�����v����
	for (i = 0; i < FISH_NUM; i++)
	{
		if (!mJympFlag[i])
		{
			mJympFlag[i] = true;
		}
		if (mJympFlag[i])
		{
			mFishPos[i].y += mJympPower[i];
			mJympPower[i] -= mGravity;

			// �p�x��ς���
			if (i == 0 && mFishRotate[i].z < -0.5f)
			{
				mFishRotate[i].z += 0.01f;
			}
			if (i == 1 && mFishRotate[i].z > -2.5f)
			{
				mFishRotate[i].z -= 0.01f;
			}
		}

		if (mFishPos[i].y < -200.0f)
		{
			mJympPower[i] = mKeepPower;
			mFishRotate[i].z = -1.5f;
			mJympFlag[i] = false;
		}
	}

	// �W�����v�ʂ������_���ɃZ�b�g����
	mKeepPower = (float)(GetRand(2) + 6);
}