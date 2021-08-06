#include "GameOver.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

//追加する濃さの定数
const int ALPHA_VELOCITY = 5;

// コンストラクタ
GameOver::GameOver()
	:Count(0)
	, ColorAlpha(ALPHA_VELOCITY)
{
}

// デストラクタ
GameOver::~GameOver()
{
}

// 描画
void GameOver::Draw(SceneBase& scene)
{
}

// 更新
void GameOver::Update()
{
}