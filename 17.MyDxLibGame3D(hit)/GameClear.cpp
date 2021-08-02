#include "GameClear.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameClear::GameClear()
	: mCount(0)
	, mColorAlpha(5)
	, mFontSize(36)
{
	// モデルをクリア用に変更
	mModel = MV1LoadModel("data/model/player/pika/pikaHandUP.pmx");
	// 文字画像の読み込み
	mClearText = MV1LoadModel("data/model/BackGround/Clear.pmx");
	mBackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	LoadDivGraph("data/Asset/Return.png", 2, 2, 1, 100, 30, mKeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, mKeyText2, TRUE);
	mPointGraph = LoadGraph("data/Asset/mejirushi.png");
	// モデルの位置設定
	MV1SetPosition(mModel, VGet(0, -1.0, -6));
	MV1SetPosition(mClearText, VGet(0, 40, -40));
	MV1SetPosition(mBackGround, VGet(0, 10, -45));
	// 背景の大きさ設定
	MV1SetScale(mBackGround, VGet(5.0f, 5.0f, 5.0f));
	// モデルを回転(ピカチュウが背中を向けているので前に変更)
	MV1SetRotationXYZ(mModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mClearText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(mBackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	// モデルのシェイプ画像設定(ピカチュウの表情変更)
	MV1SetShapeRate(mModel, 3, 1);
}

/// <summary>
/// デストラクタ
/// </summary>
GameClear::~GameClear()
{
	MV1DeleteModel(mModel);
	MV1DeleteModel(mBackGround);
	MV1DeleteModel(mClearText);
	DeleteGraph(*mKeyText1);
	DeleteGraph(*mKeyText2);
	DeleteGraph(mPointGraph);
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/// <summary>
/// 描画
/// </summary>
/// <param name="_scene">SceneBaseクラスのポインタ</param>
void GameClear::Draw(SceneBase& _scene)
{
	MV1DrawModel(mBackGround);
	MV1DrawModel(mClearText);
	MV1DrawModel(mModel);
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(540, 350, mKeyText1[_scene.GetReturnPoint()], TRUE);
	DrawGraph(540, 400, mKeyText2[_scene.GetEndPoint()], TRUE);
	if (_scene.GetPointPosition() == 1)
	{
		DrawGraph(500, 350, mPointGraph, TRUE);
	}
	else if (_scene.GetPointPosition() == 2)
	{
		DrawGraph(500, 400, mPointGraph, TRUE);
	}
	// 描画ブレンドモードにする(文字を点滅させる)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mCount);
	SetFontSize(mFontSize);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}

/// <summary>
/// 更新
/// </summary>
void GameClear::Update()
{
	// モデルのサイズを変える
	MV1SetScale(mModel, VGet(mSize, mSize, mSize));
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
}