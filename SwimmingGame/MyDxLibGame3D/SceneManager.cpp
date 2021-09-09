// インクルード
#include "SceneManager.h"
#include "Title.h"
#include "Camera.h"
#include "Common.h"
#include "Fade.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager()
    // カメラ生成
	: camera(new Camera())
	// 現在のシーンの生成
	, nowScene(new Title())
	// 次のシーンに現在のシーンを保存
	, nextScene(nowScene)
	// 現在のシーンを一時保存
	, saveNextScene(nowScene)
	// フェードインアウト生成
	, fade(new Fade())
	// フェードインアウトの状態をフェードインアウトしていない状態に変更
	, fadeState(FadeState::NonFadeInOut)
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager()
{
	// カメラ削除
	delete camera;
    // シーン削除
	delete nowScene;

	// フェードインアウト削除
	delete fade;
}

/// <summary>
/// シーン管理の更新
/// </summary>
bool SceneManager::UpdateScene()
{
	// シーンの更新処理
    // 現在と次のシーンを比較するためのSceneBaseクラスポインタ
	// Updateの戻り値で次のシーンのポインタが返ってくる
	nextScene = nowScene->Update();

	// フェードの状態をみて、フェードインアウトを行う
	switch (fadeState)
	{
	// フェードインしている時
	case FadeState::FadeIn:

		// フェードイン時の更新
		UpdateFadeInCase();

		break;
	// フェードアウトしている時
	case FadeState::FadeOut:

		// フェードアウト時の更新
		UpdateFadeOutCase();

		break;
    // フェードインアウトしていない時
	case FadeState::NonFadeInOut:

		// フェードインアウトしていない時の更新
		UpdateNonFadeInOutCase();

		break;
	}

	// ゲーム終了状態になったら更新を止める
	if (nowScene->GetScene() == nowScene->gameEnd)
	{
		return false;
	}

	return true;
}

/// <summary>
/// フェードイン時の更新
/// </summary>
void SceneManager::UpdateFadeInCase()
{
	// 一時保存したシーンを描画
	saveNextScene->Draw();

	// フェードイン描画
	// フェードインが終わったらフェードインアウトしていない状態に切り替える
	if (fade->Draw(false, WHITE))
	{
		fadeState = FadeState::NonFadeInOut;
	}
}

/// <summary>
/// フェードアウト時の更新
/// </summary>
void SceneManager::UpdateFadeOutCase()
{
	// 現在のシーンを描画
	nowScene->Draw();

	// フェードアウト描画
	// フェードアウトが終わったらフェードインの状態に切り替える
	if (fade->Draw(true, WHITE))
	{
		fadeState = FadeState::FadeIn;
	}
}

/// <summary>
/// フェードインアウトしていない時の更新
/// </summary>
void SceneManager::UpdateNonFadeInOutCase()
{
	// 現在のシーンを描画
	nowScene->Draw();

    // シーンが変わっていたら次のシーンを一時保存して、カメラのアングル、フェードインアウトの状態を切り替える
	if (nextScene != nowScene)
	{
		// 次のシーンを一時保存
		saveNextScene = nextScene;
		// フェードインの状態に切り替える
		fadeState = FadeState::FadeIn;
	}

	// フェードインアウトが終わったら、音楽、シーンを切り替えて、フェードインアウト初期化
	if (saveNextScene != nowScene)
	{
		// 音楽を止める
		//sound->StopMusic(*saveNextScene);

		// 現在のシーンを解放
		delete nowScene;
		// 現在のシーンに一時保存したシーンを保存
		nowScene = saveNextScene;

		// フェードインアウト初期化
		fade->Init();
	}
}
