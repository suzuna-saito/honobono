#include "Play.h"

/// <summary>
/// コンストラクタ
/// </summary>
Play::Play()
	: mEndFlag(false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
Play::~Play()
{
}

/// <summary>
/// プレイシーン
/// </summary>
void Play::PlayScene()
{
	// カメラを生成.
	Camera* camera = new Camera();
	// 時間を生成
	Time* time = new Time();
	// 背景を生成
	BackGround* background = new BackGround();
	// フィールドを生成
	Pool* pool = new Pool();
	// プレイヤーを生成
	Fish* fish = new Fish();

	// プレイシーンループ
	while (!ProcessMessage())
	{
		ClearDrawScreen();

		time->Update();

		camera->DivingCameraUpdate(*time);
		camera->CameraSet();

		background->Draw();
		pool->Draw();
		fish->Draw();

		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			mEndFlag = true;
			break;
		}
	}

	// カメラを削除.
	delete(camera);
	// 時間を削除.
	delete(time);
	// 背景を削除
	delete(background);
	// フィールドを削除.
	delete(pool);
	// プレイヤーを削除.
	delete(fish);
}
