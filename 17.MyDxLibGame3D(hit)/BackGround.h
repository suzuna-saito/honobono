#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "DxLib.h"

#define SCROLL_SPEED 0.25     // 背景スクロールスピード(y軸)
#define EXPANSION_SPEED 0.3f  // 背景拡大スピード(z軸)

class BackGround
{
public:
	// コンストラクタ
	BackGround();

	// デストラクタ
	~BackGround();

	// 描画
	void Draw();

	// スクロール
	void Scroll();

private:
	VECTOR DrawPos;   // 描画座標
	float size;         // サイズ
	int bg;           // 背景のハンドル
};

#endif // _BACKGROUND_H_