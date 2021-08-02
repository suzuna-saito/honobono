#pragma once
#include "DxLib.h"

class Camera;
class UIGoal;
class Player;
class Title;
class Fade;

/// <summary>
/// シーン遷移の基本クラス
/// </summary>
class SceneBase
{
protected:
	int mIsScene;          // 現在のシーン
	int mReturn;            // タイトルへが選択された
	int mEnd;               // ゲーム終了が選択された
	int mStart;             // ゲームスタートが選択された
	int mPointPosition;     // カーソル位置
	float mMove;            // キャラの動き
	float mSize;            // キャラの大きさ
	float mSizePoint;       // 大きさを変える値
	bool mFadeFlag;         // フェードしているか
	const int mUp;
	const int mDown;

public:
	// コンストラクタ
	SceneBase();

	// デストラクタ
	virtual ~SceneBase();

	// シーンの種類
	enum Scene
	{
		// タイトル
		title,
		// ゲームプレイ
		play,
		// ゲームクリア
		gameClear,
		// ゲームオーバー
		gameOver,
		// ゲーム終了
		gameEnd
	};

	// シーンを変える
	void ChangeScene(UIGoal& _uiGoal, Player& _player);

	// 現在のシーンを返す
	int GetScene() { return mIsScene; }

	// _isScene 現在のシーン
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// カーソル位置更新
    void PointUpdate();

	// 値を渡す
	int GetStartPoint() { return mStart; }
	int GetEndPoint() { return mEnd; }
	int GetReturnPoint() { return mReturn; }
	int GetPointPosition() { return mPointPosition; }

	bool GetChangeFlag() { return mChangeFlag; }
	void SetChangeFlag(bool _change) { mChangeFlag = _change; }

	bool GetShutDownFlag() { return mShutDownFlag; }

private:

	bool mChangeFlag;

	bool mShutDownFlag;


};
