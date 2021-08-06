#ifndef _SCENEBASE_H_
#define _SCENEBASE_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "DxLib.h"

/// <summary>
/// シーケンスベースクラス
/// </summary>
class SceneBase
{
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
	void ChangeScene();

	// 現在のシーンを返す
	int GetScene() { return mIsScene; }

	// _isScene 現在のシーン
	void SetScene(int _isScene) { mIsScene = _isScene; }

	// カーソル位置更新
    void PointUpdate();

	// その時のそれぞれの変数の値を返す
	int GetStartPoint() { return mStart; }
	int GetEndPoint() { return mEnd; }
	int GetReturnPoint() { return mReturn; }
	int GetPointPosition() { return mPointPosition; }

	//mChangeFlagのsetter/getter
	bool GetChangeFlag() { return mChangeFlag; }
	void SetChangeFlag(bool _change) { mChangeFlag = _change; }

	bool GetShutDownFlag() { return mShutDownFlag; }

protected:
	int mIsScene;          // 現在のシーン
	int mReturn;            // タイトルへが選択された
	int mEnd;               // ゲーム終了が選択された
	int mStart;             // ゲームスタートが選択された
	int mPointPosition;     // カーソル位置
	float mMove;            // キャラの動き
	float mSize;            // キャラの大きさ
	float mSizePoint;       // 大きさを変える値

	bool mFadeFlag;

private:

	bool mChangeFlag;
	bool mShutDownFlag;
};

#endif //_SCENEBASE_H_