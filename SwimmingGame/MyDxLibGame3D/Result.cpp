#include "Result.h"
#include "Title.h"
#include "Camera.h"
#include "Sound.h"
#include "Score.h"
#include  "Input.h"
#include "Effect.h"


// 定数
const float ENLARGED = 0.02f;


/// <summary>
/// コンストラクタ
/// </summary>
Result::Result(int* _Score)
	: i(0)
	, mAlpha(0)
	, mTextAlpha(0)
	, mCount(6)
	, mTextCount(1)
	, mRotatePoint{ 0.0050f,0.0050f }
	, mEndFlag(false)
	, mFishPos{ VGet(-40.0f, -15.0f, 50.0f), VGet(40.0f, -15.0f, 50.0f) }
	, mTextPos{ VGet(-10.5f,10.0f,40.0f)
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
	, BACK_EXTEND_Y(1100)
	, CURSOR_SIZE(1.0f)
	, CURSOR_ANGLE(0.0f)
	, TITLE(1)
	, EXIT(2)
	, mCursorPoint(1)
	, ALPHA_MAX_POINT(255)
	, ALPHA_MIN_POINT(0)
	, FONT_SIZE(60)
	, MAX_SIZE(VGet(1.60f, 1.60f, 1.60f))
	, MIN_SIZE(VGet(1.40f, 1.40f, 1.40f))
	, mResultBGM(nullptr)
	, mResultSE(nullptr)
	, mRestartSE(nullptr)
	, mCancelSE(nullptr)
	, SCORE_FONT_SIZE(40)
	, mScorePosX(170)
	, mScorePosY(180)
	, DIGIT_NUM(5)
	, NUM_POS(330)
	, NUM_SPACE(30)
	, mColor(GetColor(0, 0, 0))
	, mRunkPos(VGet(7,5,15))
	, mRunkScale(VGet(0,0,0))
	, mRunkAngle(VGet(0,0.1,0))
	, GOLD_SCORE(2000)
	, SILVER_SCORE(1000)
	, BRONZE_SCORE(500)
	, RUNK_NUM(3)
	, mNowMedal(bronze)
	, mRunkEnlarged(VGet(ENLARGED, ENLARGED, ENLARGED))
	, mEndEffect(false)
{
	// シーン変更
	SetScene(gameClear);

	// モデルをロード
	mFishModel = MV1LoadModel("data/model/ResultAsset/Fish.mqo");
	mTextModel[0] = MV1LoadModel("data/model/ResultAsset/ResultText.mqo");
	mTextModel[1] = MV1LoadModel("data/model/TextAsset/Title.mqo");
	mTextModel[2] = MV1LoadModel("data/model/TextAsset/Exit.mqo");
	mRunkModel[0] = MV1LoadModel("data/model/Medal/Gold02.mv1");
	mRunkModel[1] = MV1LoadModel("data/model/Medal/Silver02.mv1");
	mRunkModel[2] = MV1LoadModel("data/model/Medal/Bronze02.mv1");

	// 画像をロード
	mTexture = LoadGraph("data/model/ResultAsset/texture/watergarasu.jpg");
	mCursor = LoadGraph("data/model/TextAsset/Cursor.png");
	mBackGroundGraph = LoadGraph("data/model/ResultAsset/Result.png");
	mRunkTexture[0] = LoadGraph("data/model/Medal/texture/Gold.png");
	mRunkTexture[1] = LoadGraph("data/model/Medal/texture/Silver.png");
	mRunkTexture[2] = LoadGraph("data/model/Medal/texture/Bronze.png");

	// テクスチャ貼り付け
	MV1SetTextureGraphHandle(mTextModel[0], 0, mTexture, true);

	camera = new Camera();

	// サウンドのロード
	mResultBGM = new Sound("data/newSound/bgm/result.mp3");
	mResultSE = new Sound("data/newSound/se/resultSE.mp3");
	mRestartSE = new Sound("data/newSound/se/restartSE.mp3");
	mCancelSE = new Sound("data/newSound/se/cancelSE.mp3");

	// スコアをもらう＆描画用スコア計算
	mRunkScore = *_Score;
	// スコアにプレイ時のスコアを渡す
	SceneBase::mScore->SetResultScore(_Score);

	// 位置、大きさ、角度、テクスチャをセット
	for (i = 0; i < RUNK_NUM; i++)
	{
		MV1SetPosition(mRunkModel[i], mRunkPos);
		MV1SetScale(mRunkModel[i], mRunkScale);
		MV1SetRotationXYZ(mRunkModel[i], mRunkAngle);
		MV1SetTextureGraphHandle(mRunkModel[i], 0, mRunkTexture[i], true);
	}

	// エフェクト生成(ファイルを渡す)
	mMedalEffect = new Effect("data/Effect/medalEffect.efk");
}

/// <summary>
/// デストラクタ
/// </summary>
Result::~Result()
{
	// データを消去
	MV1DeleteModel(mFishModel);
	MV1DeleteModel(*mTextModel);
	MV1DeleteModel(*mRunkModel);
	DeleteGraph(mCursor);
	DeleteGraph(mBackGroundGraph);
	DeleteGraph(mTexture);
	DeleteGraph(*mRunkTexture);
	delete mResultBGM;
	delete mResultSE;
	delete mCancelSE;

	delete mMedalEffect;
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Result::Update()
{
	// リザルト時のBGM
	mResultBGM->PlayBGM();
	
	UpdateKey();
	// シーン遷移条件
	if (mCursorPoint == TITLE && Key[KEY_INPUT_SPACE] == 1)
	{
		// リスタートを選んだ時の効果音
		mRestartSE->PlaySE();
		// BGMをとめる
		mResultBGM->StopMusic();
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Title();
	}
	else if (mCursorPoint == EXIT && Key[KEY_INPUT_SPACE] == 1)
	{
		// ゲーム終了を選んだ時の効果音
		mCancelSE->PlaySE();
		// ゲームを終了させる
		SetScene(gameEnd);
	}

	CursorUpdate();
	FishMove();

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// カーソルの更新処理
void Result::CursorUpdate()
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

// 描画
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
	DrawString(750, 750, "Push The SPACE", GetColor(0, 0, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mTextAlpha);

	// スコアを描画
	SceneBase::mScore->Draw(GetScene());
	// ランク決定
	Runk();
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

/// <summary>
/// ランクを決定＆メダルの描画
/// </summary>
void Result::Runk()
{
	// ランクごとのモデルを描画
	if (mRunkScore > BRONZE_SCORE && mRunkScore < SILVER_SCORE || mRunkScore == 0)
	{
		MV1DrawModel(mRunkModel[2]);
	}
	else if (mRunkScore > SILVER_SCORE && mRunkScore < GOLD_SCORE)
	{
		MV1DrawModel(mRunkModel[1]);
		mNowMedal = silver;
	}
	else if (mRunkScore > GOLD_SCORE)
	{
		MV1DrawModel(mRunkModel[0]);
		mNowMedal = gold;
	}

	// エフェクト
	if (mMedalEffect->GetNowPlaying3D() != 0 && !mEndEffect)
	{
		mMedalEffect->PlayScaleEffect(mRunkPos, VGet(0.5f, 0.5f, 0.5f));
	}
	else
	{
		mEndEffect = true;
	}

	// 描画するメダルのサイズを大きくしていく
	if (mRunkScale.x < 1.5f)
	{
		switch (mNowMedal)
		{
		case gold:
			MV1SetScale(mRunkModel[0], mRunkScale);
			break;
		case silver:
			MV1SetScale(mRunkModel[1], mRunkScale);
			break;
		case bronze:
			MV1SetScale(mRunkModel[2], mRunkScale);
			break;
		default:
			break;
		}
		mRunkScale = VAdd(mRunkScale, mRunkEnlarged);
	}
}
