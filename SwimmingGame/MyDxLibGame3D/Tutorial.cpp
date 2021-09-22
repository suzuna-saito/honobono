#include "Tutorial.h"
#include "Play.h"
#include "Camera.h"
#include "Sound.h"
#include "Time.h"
#include "Input.h"

/// <summary>
/// コンストラクタ
/// </summary>
Tutorial::Tutorial()
	: mStartTextAlpha(0)
	, mStartTextCount(6)
	, ALPHA_MAX_POINT(255)
	, ALPHA_MIN_POINT(0)
	, mBackPosX(0)
	, mBackPosY(0)
	, BACK_EXTEND_X(700)
	, BACK_EXTEND_Y(600)
	, mTutorialkPosX(80)
	, mTutorialPosY(130)
	, TUTORIAL_EXTEND_X(570)
	, TUTORIAL_EXTEND_Y(400)
	, mTime(1000)
	, mTimeMax(1000)
	, mGageX1(50)
	, mGageX2(600)
	, mGageY1(100)
	, mGageY2(130)
	, mStartTextPosX(15)
	, mStartTextPosY(25)
	, mSkipTextPosX(100)
	, mSkipTextPosY(150)
	, mSkipDrawTime(950)
	, mSkipDrawFlag(false)
	, mSkipFlag(false)
{
	// シーン変更
	SetScene(tutorial);

	camera = new Camera();

	// テキスト画像のロード
	mStartText = LoadGraph("data/model/TutorialAsset/startText.png");
	mSkipText = LoadGraph("data/model/TutorialAsset/skipText.png");

	// 画像のロード
	mBackGroundGraph = LoadGraph("data/model/TutorialAsset/tutorialBack.png");
	mTutorialGraph = LoadGraph("data/model/TutorialAsset/tutorial.png");

	// サウンドのロード
	mTutorialBGM = new Sound("data/newSound/bgm/tutorial.mp3");
	mTutorialSE = new Sound("data/newSound/se/tutorialSE.mp3");

	// ゲージの色の設定
	mWhite = GetColor(255, 255, 255);

	// BGMの再生
	mTutorialBGM->PlayBGM();

}

/// <summary>
/// デストラクタ
/// </summary>
Tutorial::~Tutorial()
{
	// 画像の削除
	DeleteGraph(mTutorialGraph);
	DeleteGraph(mBackGroundGraph);
	DeleteGraph(mStartText);
	DeleteGraph(mSkipText);
	// サウンドデータの削除
	mTutorialBGM->StopMusic();
	delete mTutorialBGM;
	delete mTutorialSE;
}


/// <summary>
/// 更新
/// </summary>
SceneBase* Tutorial::Update()
{
	// 時間を減らす
	mTime--;
	UpdateKey();
	// シーン遷移の条件
	if (mSkipFlag || mTime < 0)
	{
		// チュートリアルのBGMを止める
		mTutorialBGM->StopMusic();
		// 効果音を再生
		mTutorialSE->PlaySE();
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new Play();
	}

	TextUpdate();

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

void Tutorial::TextUpdate()
{
	// スキップする
	if (mTime < mSkipDrawTime)
	{
		mSkipDrawFlag = true;

		// スキップの文字が描画されているときにスペースが押されたら
		if (Key[KEY_INPUT_SPACE] == 1)
		{
			mSkipFlag = true;  // シーン遷移フラグをtrueにする
		}
	}

	// 画像の透明度を変更
	if (mStartTextAlpha > ALPHA_MAX_POINT)
	{
		mStartTextCount *= -1;
	}
	else if (mStartTextAlpha < ALPHA_MIN_POINT)
	{
		mStartTextCount *= -1;
	}

	mStartTextAlpha += mStartTextCount;
}

	

/// <summary>
/// 描画
/// </summary>
void Tutorial::Draw()
{
	// 背景描画
	DrawGraph(mBackPosX, mBackPosY, mBackGroundGraph, TRUE);
	// チュートリアル画像の描画
	//DrawExtendGraph(mTutorialkPosX, mTutorialPosY,
		//TUTORIAL_EXTEND_X, TUTORIAL_EXTEND_Y, mTutorialGraph, TRUE);

	// テキスト描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mStartTextAlpha);
	DrawGraph(mSkipTextPosX, mStartTextPosY, mStartText, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, mStartTextAlpha);


	if (mSkipDrawFlag)
	{
		// スキップテキストの描画
		DrawGraph(mSkipTextPosX, mSkipTextPosY, mSkipText, TRUE);

	}

	//枠を描画
	DrawBox(mGageX1, mGageY1, mGageX1 + mGageX2, mGageY2, mWhite, FALSE);
	//時間ゲージを描画
	DrawBox(mGageX1, mGageY1, mGageX1 + mGageX2 * mTime / mTimeMax, mGageY2, mWhite, TRUE);

}