#include "Title.h"
#include "Play.h"

/// <summary>
/// コンストラクタ
/// </summary>
Title::Title()
{
	SetScene(title);

	// ３Ｄモデルの読み込み
	mModel = MV1LoadModel("data/model/player/pika/pikapika.pmx");
	mBallModel = MV1LoadModel("data/model/ball/monsterBall.pmx");
	mBackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	mTitleText = MV1LoadModel("data/model/BackGround/Title.pmx");
	LoadDivGraph("data/Asset/Start.png", 2, 2, 1, 100, 30, mKeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, mKeyText2, TRUE);
	
	// モデルの位置設定
	MV1SetPosition(mModel, VGet(0, -1.0, -6));
	MV1SetPosition(mBallModel, VGet(-2.5, 3, -4));
	MV1SetPosition(mTitleText, VGet(18, 35, -44));
	MV1SetPosition(mBackGround, VGet(0, 10, -45));
	// 背景の大きさ変更
	MV1SetScale(mBackGround, VGet(5.0f, 5.0f, 5.0f));
	// モデルを回転(ピカチュウが背中を向けているので前に変更)
	MV1SetRotationXYZ(mModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBallModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mTitleText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
}

/// <summary>
/// デストラクタ
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
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}


// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Title::Update()
{
	// シーン遷移条件
	if (GetPointPosition() == mUp && CheckHitKey(KEY_INPUT_RETURN))
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Play();
	}
	else if (GetPointPosition() == mDown && CheckHitKey(KEY_INPUT_RETURN))
	{
		SetScene(gameEnd);
	}
	// カーソル位置更新
	PointUpdate();

	// モデルのサイズを変える
	MV1SetScale(mModel, VGet(mSize, mSize, mSize));
	// ボールを回転させる
	MV1SetRotationXYZ(mBallModel, VGet(0, mMove, -0.5));

	mMove += 0.05f;
	mSize += mSizePoint;

	// モデルのサイズを拡大、縮小させる
	if (mSize > 1.02)
	{
		mSizePoint *= -1;
	}
	else if (mSize < 1.0)
	{
		mSizePoint *= -1;
	}

	// 描画ブレンドモードを濃さを変える
	if (mCount > 255)
	{
		mColorAlpha *= -1;
	}
	else if (mCount < 0)
	{
		mColorAlpha *= -1;
	}

	mCount += mColorAlpha;

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Title::Draw()
{
	MV1DrawModel(mBackGround);
	MV1DrawModel(mTitleText);
	MV1DrawModel(mModel);
	MV1DrawModel(mBallModel);
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(540, 350, mKeyText1[GetStartPoint()], TRUE);
	DrawGraph(540, 400, mKeyText2[GetEndPoint()], TRUE);
	if (GetPointPosition() == 1)
	{
		DrawGraph(500, 350, mPointGraph, TRUE);
	}
	else if (GetPointPosition() == 2)
	{
		DrawGraph(500, 400, mPointGraph, TRUE);
	}

	// 描画ブレンドモードにする(文字を点滅させる)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mCount);
	SetFontSize(mFontSize);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}