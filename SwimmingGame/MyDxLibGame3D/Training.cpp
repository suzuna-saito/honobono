#include "Training.h"
#include "Pool.h"
#include "Camera.h"
#include "Play.h"
#include "BackGround.h"
#include "Time.h"
#include "Timing.h"
#include "Sound.h"
#include "Common.h"
#include "Fish.h"
#include "Input.h"

// コンストラクタ
Training::Training()
	: mPlayBGM1(nullptr)
	, mModelHandle(-1)
	, mPos(VGet(0.0f, 5.5f, 0.0f))
	, mRot(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f))
	, mDance(VGet(0.0f, 0.0f, 0.0))
{
	SetScene(training);

	// プール生成
	pool = new Pool();

	mModelHandle = MV1LoadModel("data/model/fish/player02.mv1");
	// 魚生成
	fish = new Fish(mModelHandle, mPos, mRot, mDance);

	// リズムボタンUI生成
	timing = new Timing();


	time = new Time();

	// 背景の生成
	backGround = new BackGround();

	camera = new Camera();

	camera->TrainingCameraUpdate();
	camera->CameraSet();

	mPlayBGM1 = new Sound("data/newSound/bgm/kari.mp3");

	mPlayBGM1->PlayBackBGM();
}

// デストラクタ
Training::~Training()
{
	// 魚削除
	delete fish;
	// プール削除
	delete pool;
	// リズムボタンUI削除
	delete timing;
	delete time;
	// 背景の削除
	delete(backGround);
	mPlayBGM1->StopMusic();


	delete mPlayBGM1;

}

// 更新処理
/// <return>シーンのポインタ</return>
SceneBase* Training::Update()
{
	UpdateKey();

	if (Key[KEY_INPUT_SPACE] == 1)
	{
		mPlayBGM1->StopMusic();

		return new Play();
	}

	time->Update();

	// リズムボタンUI更新
 	timing->Update(1);

	fish->Updata(timing->GetJudg(), time->GetDeltaTime(), false, GetScene());

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

// 描画
void Training::Draw()
{
	// 背景の生成
	backGround->Draw();
	// 魚描画
	fish->Draw(0);
	// プール描画
	pool->Draw();
	// リズムボタンUI描画
	timing->Draw();
}

