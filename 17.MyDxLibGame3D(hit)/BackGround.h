#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "DxLib.h"

// 背景スクロールスピード(y軸)
#define SCROLL_SPEED 0.25
// 背景拡大スピード(z軸)
#define EXPANSION_SPEED 0.3f

/// <summary>
/// ゲーム内背景のクラス
/// </summary>
class BackGround
{
public:
	/// <summary>
	/// コンストラクタ 
	/// </summary>
	BackGround();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~BackGround();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// スクロール
	/// </summary>
	void Scroll();

private:
	// 描画座標
	VECTOR DrawPos;
	// 1枚目の座標X
	float x1;
	// 1枚目の座標Y
	float y1;
	// 1枚目の座標Z
	float z1;
	// 2枚目の座標X
	float x2;
	// 2枚目の座標Y
	float y2;
	// 2枚目の座標Z
	float z2;
	// 画像の中心座標X
	float cx;
	// 画像の中心座標Y
	float cy;
	// 画像のサイズ
	float size;
	// 2枚目の画像のサイズ
	float size2;
	// アングル
	float angle;
	// 背景のハンドル
	int bg;
	// スクロールのMAXの値
	int scrMax;
	// スクロールの座標の初期化
	float scrInitY;
	// スクロールの座標Zの初期化
	float scrInitZ;
};

#endif // _BACKGROUND_H_