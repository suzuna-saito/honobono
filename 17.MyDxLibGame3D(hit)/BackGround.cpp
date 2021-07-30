#include "BackGround.h"
/*
なんちゃって背景（雑）
*/

#include "DxLib.h"

/*
コンストラクタ
*/
BackGround::BackGround()
	:size(130)
{
	// 背景座標
	DrawPos = VGet(0, 0, 20);

	// 背景画像読み込み
	bg = LoadGraph("data/Asset/sougen.jpeg");
}


/*
デストラクタ
*/
BackGround::~BackGround()
{
}

/*
描画
*/
void BackGround::Draw()
{
	// 3D空間に画像を描画
	DrawBillboard3D(DrawPos, 0.5, 0.5, size, 0, bg, FALSE);                       // 一枚目の画像

	DrawBillboard3D(VAdd(DrawPos,VGet(0,40,50)), 0.5, 0.5, size+10, 0, bg, FALSE);// 二枚目の画像
}

/*
スクロール
*/
void BackGround::Scroll()
{
	DrawPos.y -= SCROLL_SPEED;
	DrawPos.z -= EXPANSION_SPEED;

	// 一定数進んだら元の座標に戻してあげる(ループ)
	if (DrawPos.y <= -30)
	{
		DrawPos.y = 0;
		DrawPos.z = 20;
	}
}
