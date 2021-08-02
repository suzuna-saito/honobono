#pragma once
#include "DxLib.h"
#include "SceneBase.h"

/// <summary>
/// ゲームオーバーシーンのクラス
/// </summary>
class GameOver : public SceneBase
{
private:
	int mModel;               // モデル
	int mBallModel;           // サブモデル
	int mOverText;            // ゲームオーバーテキスト
	int mBackGround;          // 3D背景
	int mKeyText1[2];         // キー指示１
	int mKeyText2[2];         // キー指示２
	int mPointGraph;          // カーソル
	int mCount;	              // 濃度カウント
	int mColorAlpha;          // 追加する濃さの値
	const int mFontSize;      // 文字の大きさ

public:
	// コンストラクタ
	GameOver();
	// デストラクタ
	~GameOver();
	// 描画
	void Draw(SceneBase& _scene);
	// 更新
	void Update();
};