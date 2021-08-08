#include "GameOver.h"
#include "Title.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameOver::GameOver()
{
	SetScene(gameOver);

	// モデルをクリア用に変更
	mModel = MV1LoadModel("data/model/player/pika/pikaSad.pmx");
	mBallModel = MV1LoadModel("data/model/ball/monsterBall.pmx");
	// 文字画像の読み込み
	mOverText = MV1LoadModel("data/model/BackGround/Over.pmx");
	mBackGround = MV1LoadModel("data/model/BackGround/unnamed.pmx");
	LoadDivGraph("data/Asset/Return.png", 2, 2, 1, 100, 30, mKeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, mKeyText2, TRUE);
	
	// モデルの位置設定
	MV1SetPosition(mModel, VGet(-1.5, 0, -6));
	MV1SetPosition(mBallModel, VGet(1, 0, -5));
	MV1SetPosition(mOverText, VGet(0, 40, -40));
	MV1SetPosition(mBackGround, VGet(0, 10, -45));
	// 背景の大きさ設定
	MV1SetScale(mBackGround, VGet(5.0f, 5.0f, 5.0f));
	// モデルを回転(ピカチュウが背中を向けているので前に変更)
	MV1SetRotationXYZ(mModel, VGet(5.6, 200.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBallModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mOverText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	// モデルのシェイプ画像設定(ピカチュウの表情変更)
	MV1SetShapeRate(mModel, 24, 1);
}

/// <summary>
/// デストラクタ
/// </summary>
GameOver::~GameOver()
{
	MV1DeleteModel(mModel);
	MV1DeleteModel(mBallModel);
	MV1DeleteModel(mBackGround);
	MV1DeleteModel(mOverText);
	DeleteGraph(*mKeyText1);
	DeleteGraph(*mKeyText2);
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* GameOver::Update()
{
	// シーン遷移条件
	if (GetPointPosition() == mUp && CheckHitKey(KEY_INPUT_RETURN))
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Title();
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

	mMove += 0.10f;
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

/// <summary>
/// 描画
/// </summary>
/// <param name="scene">SceneBaseクラスのポインタ</param>
void GameOver::Draw()
{
	MV1DrawModel(mBackGround);
	MV1DrawModel(mOverText);
	MV1DrawModel(mModel);
	MV1DrawModel(mBallModel);
	// 描画ブレンドモードをノーブレンドにする
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
	// 描画ブレンドモードにする(文字を点滅させる)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mCount);
	SetFontSize(mFontSize);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}

