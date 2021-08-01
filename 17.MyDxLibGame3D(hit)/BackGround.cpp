#include "BackGround.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
BackGround::BackGround()
	: cx(0.5f)
	, cy(0.5f)
	, angle(0.0f)
	, x1(0.0f)
	, y1(0.0f)
	, z1(20.0f)
	, size(130.0f)
	, x2(0.0f)
	, y2(40.0f)
	, z2(50.0f)
	, size2(140.0f)
	, scrMax(-30)
	, scrInitY(0)
	, scrInitZ(20)
{
	// 背景座標
	DrawPos = VGet(x1, y1, z1);

	// 背景画像読み込み
	bg = LoadGraph("data/Asset/sougen.jpeg");
}

/// <summary>
/// デストラクタ
/// </summary>
BackGround::~BackGround()
{
	DeleteGraph(bg);
}

/// <summary>
/// 描画
/// </summary>
void BackGround::Draw()
{
	// 3D空間に画像を描画
	DrawBillboard3D(DrawPos, cx, cy, size, angle, bg, FALSE);                       // 一枚目の画像

	DrawBillboard3D(VAdd(DrawPos,VGet(x2,y2,z2)), cx, cy, size2, angle, bg, FALSE);// 二枚目の画像
}

/// <summary>
/// スクロール
/// </summary>
void BackGround::Scroll()
{
	// スクロールスピードを代入
	DrawPos.y -= SCROLL_SPEED;
	// 背景拡大スピードを代入
	DrawPos.z -= EXPANSION_SPEED;

	// 一定数進んだら元の座標に戻す(ループ)
	if (DrawPos.y <= scrMax)
	{
		// Y座標を元の座標に戻す
		DrawPos.y = scrInitY;
		// Z座標を元の座標に戻す
		DrawPos.z = scrInitZ;
	}
}
