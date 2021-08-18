#pragma once
#include "DxLib.h"
#include "Camera.h"

/// <summary>
/// リザルトクラス
/// </summary>
class Result
{
private:
	int i;
	int mAlpha;                           // カーソルアルファ値
	int mTextAlpha;                       // テキストアルファ値
	int mCount;                           // カーソルアルファ値カウント
	int mTextCount;                       // テキストアルファ値
	int mCursorPoint;                     // カーソル位置
	float mRotatePoint[2];                // 回転値
	bool mEndFlag;                        // 終了フラグ

	int mBackGroundGraph;                 // 背景画像
	int mFishModel;                       // 魚モデル
	int mTextModel[3];                    // テキストモデル
	int mTexture;                         // テクスチャ
	int mCursor;                          // カーソル画像

	VECTOR mFishPos[2];                   // 魚の位置
	VECTOR mTextPos[3];                   // テキストの位置

	int mBackPosX;                        // 背景座標X
	int mBackPosY;                        // 背景座標Y

	VECTOR mFishRotate[2];                // 魚の回転角度

	VECTOR mFishSize[2];                  // 魚のサイズ
	VECTOR mTextSize[3];                  // テキストのサイズ
	VECTOR mCursorPos;                    // カーソル位置

	const float POINT_X, POINT_Y;         // 3D画像の中心
	const float SIZE;                     // 3D画像のサイズ
	const float ANGLE;                    // 3D画像の角度

	const int FISH_NUM;                   // 魚の数
	const int TEXT_NUM;                   // テキストの数
	const int BACK_EXTEND_X;              // 背景の拡大X
	const int BACK_EXTEND_Y;              // 背景の拡大Y
	const float CURSOR_SIZE;              // カーソルサイズ
	const float CURSOR_ANGLE;             // カーソル角度

	const int TITLE;                      // タイトル
	const int EXIT;                       // 終了
	const int ALPHA_MAX_POINT;            // アルファ値の最大値
	const int ALPHA_MIN_POINT;            // アルファ値の最小値
	const int FONT_SIZE;                  // 文字のサイズ

	const VECTOR MAX_SIZE;                // 魚の拡大縮小最大値
	const VECTOR MIN_SIZE;                // 魚の拡大縮小最小値
public:
	// コンストラクタ
	Result();
	// デストラクタ
	virtual ~Result();

	// リザルトシーン
	void ResultScene();
	// 更新
	void Update();
	// 描画
	void Draw();

	// 魚の挙動
	void FishMove();
	// 値を渡す
	bool GetEndFlag() { return mEndFlag; }
};

