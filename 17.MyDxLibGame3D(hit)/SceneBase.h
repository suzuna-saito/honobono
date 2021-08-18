#pragma once
#include "Title.h"
#include "Play.h"
#include "Result.h"

// それぞれのシーンクラスを宣言
class Title;
class Play;
class Result;

/// <summary>
/// SceneBaseクラス
/// </summary>
class SceneBase : public Title, public Play, public Result
{
private:
	bool mEndFlag;               // ゲーム終了フラグ

public:
	// コンストラクタ
	SceneBase();
	// デストラクタ
	~SceneBase();

	// ゲーム
	void Game();
};

