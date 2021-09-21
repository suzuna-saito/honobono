#include "Title.h"
#include "Tutorial.h"
#include "Camera.h"
#include "Sound.h"
#include "Input.h"

/// <summary>
/// コンストラクタ
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
	, mIconPosY(980)
	, mTeamNamePosX(1280)
	, mTeamNamePosY(960)
{
	SetScene(title);
	// モデルをロード
	mFishModel = MV1LoadModel("data/model/TitleAsset/Fish.mqo");
	mTextModel[0] = MV1LoadModel("data/model/TitleAsset/TitleText.mqo");
	mTextModel[1] = MV1LoadModel("data/model/TextAsset/GameStart.mqo");
	mTextModel[2] = MV1LoadModel("data/model/TextAsset/Exit.mqo");

	// 画像をロード
	mCursor = LoadGraph("data/model/TextAsset/Cursor.png");
	mTextTexture = LoadGraph("data/model/TitleAsset/texture/watergarasu.jpg");
	mBackGroundGraph = LoadGraph("data/model/TitleAsset/Title.png");
	mRubiGraph = LoadGraph("data/model/TitleAsset/titleRubi.png");
	mIconGraph = LoadGraph("data/model/TitleAsset/Icon1.png");
	mTeamNameGraph = LoadGraph("data/model/TitleAsset/team.png");

	// テクスチャ貼り付け
	MV1SetTextureGraphHandle(mTextModel[0], 0, mTextTexture, true);

	// サウンドのロード
	mTitleBGM = new Sound("data/newSound/bgm/title.mp3");
	mTitleSE = new Sound("data/newSound/se/startSE.mp3");
	mCancelSE = new Sound("data/newSound/se/cancelSE.mp3");

	// BGMの再生
	mTitleBGM->PlayBGM();
}

/// <summary>
/// デストラクタ
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


// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Title::Update()
{
	UpdateKey();
	// シーン遷移条件
	if (mCursorPoint == GAME_START && Key[KEY_INPUT_SPACE] == 1)
	{
		// タイトルの効果音
		mTitleSE->PlaySE();
		// タイトルのBGMを止める
		mTitleBGM->StopMusic();
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Tutorial();

	}
	else if (mCursorPoint == EXIT && Key[KEY_INPUT_SPACE] == 1)
	{
		// ゲーム終了を選択したときになる効果音
		mCancelSE->PlaySE();
		SetScene(gameEnd);
	}
	
	CursorUpdate();
	FishMove();

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// カーソルの更新処理
void Title::CursorUpdate()
{
	// カーソル移動
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

	// 画像の透明度を変更
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

// 描画
void Title::Draw()
{
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	// 背景描画
	DrawExtendGraph(mBackPosX, mBackPosY,
		BACK_EXTEND_X, BACK_EXTEND_Y, mBackGroundGraph, true);
	
	// 魚を描画
	for (i = 0; i < FISH_NUM; i++)
	{
		MV1SetPosition(mFishModel, mFishPos[i]);
		MV1SetScale(mFishModel, mFishSize[i]);
		MV1SetRotationXYZ(mFishModel, mFishRotate[i]);
		MV1DrawModel(mFishModel);
	}

	// テキストを描画
	for (i = 0; i < TEXT_NUM; i++)
	{
		MV1SetPosition(mTextModel[i], mTextPos[i]);
		MV1SetScale(mTextModel[i], mTextSize[i]);
		MV1DrawModel(mTextModel[i]);
	}

	// ルビを描画
	DrawExtendGraph(mRubiPosX, mRubiPosY,1500,550,mRubiGraph,TRUE);
	// アイコンを描画
	DrawGraph(mIconPosX, mIconPosY, mIconGraph, TRUE);
	// チーム名描画
	DrawGraph(mTeamNamePosX, mTeamNamePosY, mTeamNameGraph, TRUE);

	// アルファで表示する画像を描画
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
/// 魚の挙動
/// </summary>
void Title::FishMove()
{
	// 魚のジャンプ処理
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

			// 角度を変える
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

	// ジャンプ量をランダムにセットする
	mKeepPower = (float)(GetRand(2) + 6);
}