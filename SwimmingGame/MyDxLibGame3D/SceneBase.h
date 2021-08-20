#pragma once
#include "DxLib.h"

/// <summary>
/// シーンの基底クラス
/// </summary>
class SceneBase
{
public:
	// コンストラクタ
	SceneBase();

	// デストラクタ
	~SceneBase();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	virtual SceneBase* Update();

	/// <summary>
	/// シーンの描画
	/// </summary>
	virtual void Draw();

	// カーソル位置更新
	void PointUpdate();

	// シーンの種類
	enum Scene
	{
		// タイトル
		title,
		// ゲームプレイ
		play,
		// アーティスティックスイミング時
		DanceGame,
		// ゲームクリア
		gameClear,
		// ゲームオーバー
		gameOver,
		// ゲーム終了
		gameEnd
	};

private:
	bool mShutDownFlag;

protected:
	int mIsScene;          // 現在のシーン

	int mEnd;               // ゲーム終了が選択された
	int mStart;             // ゲームスタートが選択された
	int mPointPosition;     // カーソル位置
	float mMove;            // キャラの動き
	float mSize;            // キャラの大きさ
	float mSizePoint;       // 大きさを変える値
	const int mFontSize;    // 文字の大きさ
	const int mUp;
	const int mDown;

	int mModel;        // メインモデル
	int mBallModel;    // サブモデル(飾り)
	int mBackGround;   // 3D背景
	int mKeyText1[2];     // キー指示１
	int mKeyText2[2];     // キー指示２
	int mPointGraph;      // カーソル
	int mCount;           // 濃度カウント
	int mColorAlpha;      // 追加する濃さの値
	int mReturn;            // タイトルへが選択された
//	bool mFadeFlag;         // フェードしているか


public: // ゲッター、セッター

	/// <summary>
	/// シーンを取得
	/// </summary>
	/// <returns>現在のシーンを返す</returns>
	int GetScene() { return mIsScene; }

	/// <summary>
	/// シーンをセットする
	/// </summary>
	/// <param name="_isScene">現在のシーン</param>
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// 値を渡す
	int GetStartPoint() { return mStart; }
	int GetReturnPoint() { return mReturn; }
	int GetEndPoint() { return mEnd; }
	int GetPointPosition() { return mPointPosition; }
};
