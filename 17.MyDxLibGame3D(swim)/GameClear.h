#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "SceneBase.h"

/// <summary>
/// ゲームクリア時のクラス
/// シーケンスベースを元にして作成
/// </summary>
class GameClear : public SceneBase
{
private:
	int Model;        // メインモデル
	int ClearText;    // サブモデル(飾り)
	int BackGround;   // 3D背景
	int KeyText1[2];// キー指示１
	int KeyText2[2];// キー指示２
	int PointGraph;// カーソル
	int Count;	   // 濃度カウント
	int ColorAlpha;// 追加する濃さの値

public:
	// コンストラクタ
	GameClear();
	// デストラクタ
	~GameClear();
	// 描画関数
	void Draw(SceneBase& scene);
	// 更新関数
	void Update();
};

#endif //_GAMECLEAR_H_