#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "DxLib.h"

/// <summary>
/// 背景クラス
/// </summary>
class BackGround
{
public:
	// コンストラクタ
	BackGround();

	// デストラクタ
	~BackGround();

	// 更新関数
	/*
	* 動く(スクロールをする等)のであればここで
	*/
	void Update();

	// 描画
	void Draw();


private:
	VECTOR mDrawPos;   // 描画座標
	float mSize;         // サイズ
	int mBackGroundImage;    // 背景のハンドル
};

#endif // _BACKGROUND_H_