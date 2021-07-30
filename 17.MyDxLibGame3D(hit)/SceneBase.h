#pragma once
#include "DxLib.h"

class Camera;
class UIGoal;
class Player;
class Title;
class Fade;

class SceneBase
{
protected:
	int mIsScene;          // 現在のシーン
	int Return;            // タイトルへが選択された
	int End;               // ゲーム終了が選択された
	int Start;             // ゲームスタートが選択された
	int PointPosition;     // カーソル位置
	float Move;            // キャラの動き
	float Size;            // キャラの大きさ
	float SizePoint;       // 大きさを変える値
	bool FadeFlag;

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
	void ChangeScene(UIGoal& uiGoal, Player& player);

	// 現在のシーンを返す
	int GetScene() { return mIsScene; }

	// _isScene 現在のシーン
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// カーソル位置更新
    void PointUpdate();

	// 値を渡す
	int GetStartPoint() { return Start; }
	int GetEndPoint() { return End; }
	int GetReturnPoint() { return Return; }
	int GetPointPosition() { return PointPosition; }

	bool GetChangeFlag() { return mChangeFlag; }
	void SetChangeFlag(bool _change) { mChangeFlag = _change; }

	bool GetShutDownFlag() { return mShutDownFlag; }

private:

	bool mChangeFlag;

	bool mShutDownFlag;


};
