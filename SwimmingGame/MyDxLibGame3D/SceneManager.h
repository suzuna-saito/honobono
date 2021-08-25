#pragma once

// 前方宣言
class Camera;
class SceneBase;
class Fade;

/// <summary>
/// フェードインフェードアウトの状態
/// </summary>
enum class FadeState : int
{
	Empty,
	FadeIn,
	FadeOut,
	NonFadeInOut,
};

/// <summary>
/// シーンを管理
/// </summary>
class SceneManager
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SceneManager();

	/// <summary>
    /// シーン管理の更新
    /// </summary>
	bool UpdateScene();

	/// <summary>
	/// フェードイン時の更新
	/// </summary>
	void UpdateFadeInCase();
	
	/// <summary>
	/// フェードアウト時の更新
	/// </summary>
	void UpdateFadeOutCase();

	/// <summary>
	/// フェードインアウトしていない時の更新
	/// </summary>
	void UpdateNonFadeInOutCase();

private:
	// カメラ
	Camera* camera = nullptr;
	// 現在のシーン
	SceneBase* nowScene = nullptr;
	// 次のシーン
	SceneBase* nextScene = nullptr;
	// 次のシーンをフェードインアウト処理のために一時保存するためのポインタ
	SceneBase* saveNextScene = nullptr;
	// フェードインアウト
	Fade* fade = nullptr;
	// フェードインアウトの状態
	FadeState fadeState = FadeState::Empty;
};