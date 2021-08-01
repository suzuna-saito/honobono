#include <DxLib.h>
#include "UIBase.h"

// Xの座標
const int POS_X = 150;
// Yの座標
const int POS_Y = 100;		

// 描画ポジションを少しずらすための値
const int ADD_POS = 150;

// 一つ目と二つ目の花火の拡大値X
const int EXPANSION_X = 230;
// 一つ目と二つ目の花火の拡大値Y
const int EXPANSION_Y = 250;
// 三つ目の花火の拡大値
const int EXPANSION3 = 400;	
// 花火を出すタイミング(最大)
const int TIME = 240;		

/// <summary>
/// ゴール直後に出す花火の演出のクラス
/// </summary>
class UIFireworks
{
public:
	// コンストラクタ
	UIFireworks();
	// デストラクタ
	~UIFireworks();

	// 更新
	void Update();
	// 描画
	void Draw();

	/// <summary>
	/// ゴール直後に花火を時間差で描画する
	/// </summary>
	/// <returns> 花火を時間差で出すためのカウンター </returns>
	int GetclearCount() { return clearCount; }
	// 花火を出すタイミング(最大)
	const int time;

private:
	// 花火の画像読み込み
	int fireworksImg;
	// 花火の画像読み込み2
	int fireworksImg2;
	// 花火の画像読み込み3
	int fireworksImg3;

	// 1つ目の花火の描画フラグ
	bool mDrawFlag;
	// 2つ目の花火の描画フラグ
	bool mDrawFlag2;
	// 3つ目の花火の描画フラグ
	bool mDrawFlag3;

	// 描画させるポジションX
	const int mDrawPosX;
	// 描画させるポジションY
	const int mDrawPosY;

	// クリアしてたった時間
	int clearCount;				
};