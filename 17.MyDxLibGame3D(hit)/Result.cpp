#include "Result.h"

/// <summary>
/// コンストラクタ
/// </summary>
Result::Result()
	: i(0)
	, mAlpha(0)
	, mTextAlpha(0)
	, mCount(6)
	, mTextCount(1)
	, mRotatePoint{ 0.0050f,0.0050f }
	, mEndFlag(false)
	, mFishPos{ VGet(-40.0f, -15.0f, 50.0f), VGet(40.0f, -15.0f, 50.0f) }
	, mTextPos{VGet(-10.5f,10.0f,40.0f)
	          ,VGet(-1.250f,-1.0f,10.0f),VGet(-1.0f,-2.0f,10.0f) }
	, mCursorPos(VGet(-0.05f, -0.15f, 2.0f))
	, mBackPosX(0)
	, mBackPosY(0)
	, mFishRotate{ VGet(0.0f,-2.50f,0.0f),VGet(0.0f,-0.50f,0.0f) }
	, mFishSize{ VGet(1.50f,1.50f,1.50f), VGet(1.50f,1.50f,1.50f) }
	, mTextSize{ VGet(10.0f,10.0f,1.0f)
	            ,VGet(1.0f,1.0f,1.0f), VGet(1.0f,1.0f,1.0f) }
	, POINT_X(0.5f)
	, POINT_Y(0.5f)
	, SIZE(1.0f)
	, ANGLE(0.0f)
	, FISH_NUM(2)
	, TEXT_NUM(3)
	, BACK_EXTEND_X(2000)
	, BACK_EXTEND_Y(1000)
	, CURSOR_SIZE(1.0f)
	, CURSOR_ANGLE(0.0f)
	, TITLE(1)
	, EXIT(2)
	, mCursorPoint(0)
	, ALPHA_MAX_POINT(255)
	, ALPHA_MIN_POINT(0)
	, FONT_SIZE(60)
	, MAX_SIZE(VGet(1.60f,1.60f,1.60f))
	, MIN_SIZE(VGet(1.40f,1.40f,1.40f))
{
	// モデルをロード
	mFishModel = MV1LoadModel("data/model/ResultAsset/Fish.mqo");
	mTextModel[0] = MV1LoadModel("data/model/ResultAsset/ResultText.mqo");
	mTextModel[1] = MV1LoadModel("data/model/TextAsset/Title.mqo");
	mTextModel[2] = MV1LoadModel("data/model/TextAsset/Exit.mqo");

	// 画像をロード
	mTexture = LoadGraph("data/model/ResultAsset/texture/watergarasu.jpg");
	mCursor = LoadGraph("data/model/TextAsset/Cursor.png");
	mBackGroundGraph = LoadGraph("data/model/ResultAsset/Result.png", false);

	// テクスチャ貼り付け
	MV1SetTextureGraphHandle(mTextModel[0], 0, mTexture, true);
}

/// <summary>
/// デストラクタ
/// </summary>
Result::~Result()
{
	// データを消去
	MV1DeleteModel(mFishModel);
	MV1DeleteModel(*mTextModel);
	DeleteGraph(mCursor);
	DeleteGraph(mBackGroundGraph);
	DeleteGraph(mTexture);
}

/// <summary>
/// リザルトシーン
/// </summary>
void Result::ResultScene()
{
	// カメラクラスを宣言
	Camera* camera = new Camera();
	// 原点にカメラをセット
	camera->SetOriginCameraUpdate();
	// リザルトシーンループ
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		FishMove();

		Draw();
		Update();

		camera->CameraSet();

		ScreenFlip();

		// タイトルへ
		if (mCursorPoint == TITLE && CheckHitKey(KEY_INPUT_RETURN))
		{
			mEndFlag = false;
			break;
		}
		// ゲーム終了
		else if (mCursorPoint == EXIT && CheckHitKey(KEY_INPUT_RETURN))
		{
			mEndFlag = true;
			break;
		}
	}
	delete(camera);
}

/// <summary>
/// 更新
/// </summary>
void Result::Update()
{
	// カーソル移動
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mCursorPos.y = -0.15f;
		mCursorPoint = TITLE;
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

/// <summary>
/// 描画
/// </summary>
void Result::Draw()
{
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

	// アルファで表示する画像を描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlpha);
	DrawBillboard3D(mCursorPos, POINT_X, POINT_Y,
		CURSOR_SIZE, CURSOR_ANGLE, mCursor, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mAlpha);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mTextAlpha);
	SetFontSize(FONT_SIZE);
	DrawString(750, 750, "Push The Enter", GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mTextAlpha);
}

/// <summary>
/// 魚の挙動
/// </summary>
void Result::FishMove()
{
	for (i = 0; i < FISH_NUM; i++)
	{
		if (mFishSize[i].x > MAX_SIZE.x)
		{
			mRotatePoint[i] *= -1.0f;
		}
		if (mFishSize[i].x < MIN_SIZE.x)
		{
			mRotatePoint[i] *= -1.0f;
		}

		mFishSize[i].x += mRotatePoint[i];
	}
}
