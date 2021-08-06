#include "Title.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

//追加する濃さの定数
const int ALPHA_VELOCITY = 5;

// コンストラクタ
Title::Title()
	:Count(0)
	,ColorAlpha(ALPHA_VELOCITY)
{
}

// デストラクタ
Title::~Title()
{
}

// 描画
void Title::Draw(SceneBase& scene)
{
}

// 更新
void Title::Update()
{
}