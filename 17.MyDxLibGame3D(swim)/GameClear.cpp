#include "GameClear.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

//追加する濃さの定数
const int ALPHA_VELOCITY = 5;

// コンストラクタ
GameClear::GameClear()
	:Count(0)
	, ColorAlpha(ALPHA_VELOCITY)
{
}

// デストラクタ
GameClear::~GameClear()
{
}

// 描画関数
void GameClear::Draw(SceneBase& scene)
{
}

// 更新関数
void GameClear::Update()
{
}