#pragma once
#include "SceneBase.h"
#include "DxLib.h"

/// <summary>
/// タイトルシーンのクラス
/// </summary>
class Title : public SceneBase
{
private:
	int mModel;        // メインモデル
	int mBallModel;    // サブモデル(飾り)
	int mBackGround;   // 3D背景
	int mTitleText;    // タイトルテキスト
	int mKeyText1[2];     // キー指示１
	int mKeyText2[2];     // キー指示２
	int mPointGraph;      // カーソル
	int mCount;           // 濃度カウント
	int mColorAlpha;      // 追加する濃さの値
	const int mFontSize;  // 文字の大きさ

public:
	// コンストラクタ
	Title();
	// デストラクタ
	virtual ~Title();
	// 描画
	void Draw(SceneBase& _scene);
	// 更新
	void Update();
};