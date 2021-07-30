#include "Title.h"

// コンストラクタ
Title::Title()
	:Count(0)
	,ColorAlpha(5)
{
	// ３Ｄモデルの読み込み
	Model = MV1LoadModel("data/model/player/pika/pikapika.pmx");
	BallModel = MV1LoadModel("data/model/ball/monsterBall.pmx");
	BackGround = MV1LoadModel("data/model/BackGround/sougen.pmx");
	TitleText = MV1LoadModel("data/model/BackGround/Title.pmx");
	LoadDivGraph("data/Asset/Start.png", 2, 2, 1, 100, 30, KeyText1, TRUE);
	LoadDivGraph("data/Asset/End.png", 2, 2, 1, 100, 30, KeyText2, TRUE);
	PointGraph = LoadGraph("data/Asset/mejirushi.png");

	// モデルの位置設定
	MV1SetPosition(Model, VGet(0, -1.0, -6));
	MV1SetPosition(BallModel, VGet(-2.5, 3, -4));
	MV1SetPosition(TitleText, VGet(18, 35, -44));
	MV1SetPosition(BackGround, VGet(0, 10, -45));
	// 背景の大きさ変更
	MV1SetScale(BackGround, VGet(5.0f, 5.0f, 5.0f));
	// モデルを回転(ピカチュウが背中を向けているので前に変更)
	MV1SetRotationXYZ(Model, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(BallModel, VGet(5.6, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(TitleText, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
	MV1SetRotationXYZ(BackGround, VGet(0, 180.0f * DX_PI_F / 180.0f, 0));
}

// デストラクタ
Title::~Title()
{
	MV1DeleteModel(Model);
	MV1DeleteModel(BallModel);
	MV1DeleteModel(BackGround);
	MV1DeleteModel(TitleText);
	DeleteGraph(PointGraph);
	DeleteGraph(*KeyText1);
	DeleteGraph(*KeyText2);
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// 描画
void Title::Draw(SceneBase& scene)
{
	MV1DrawModel(BackGround);
	MV1DrawModel(TitleText);
	MV1DrawModel(Model);
	MV1DrawModel(BallModel);
	// 描画ブレンドモードをノーブレンドにする
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

	// 描画ブレンドモードにする(文字を点滅させる)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Count);
	SetFontSize(36);
	DrawString(200, 444, "Push The Enter", GetColor(0, 0, 0));
}

// 更新
void Title::Update()
{
	// モデルのサイズを変える
	MV1SetScale(Model, VGet(Size, Size, Size));
	// ボールを回転させる
	MV1SetRotationXYZ(BallModel, VGet(0, Move, -0.5));

	Move += 0.05f;
	Size += SizePoint;

	// モデルのサイズを拡大、縮小させる
	if (Size > 1.02)
	{
		SizePoint *= -1;
	}
	else if (Size < 1.0)
	{
		SizePoint *= -1;
	}

	// 描画ブレンドモードを濃さを変える
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