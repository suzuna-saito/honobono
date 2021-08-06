#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "SceneBase.h"

/// <summary>
/// ゲームオーバー時のクラス
/// シーケンスベースを元にして作成
/// </summary>
class GameOver : public SceneBase
{
private:
	int Model;         // モデル
	int BallModel;     // サブモデル
	int OverText;      // ゲームオーバーテキスト
	int BackGround;    // 3D背景
	int KeyText1[2];   // キー指示１
	int KeyText2[2];   // キー指示２
	int PointGraph;    // カーソル
	int Count;	       // 濃度カウント
	int ColorAlpha;    // 追加する濃さの値

public:
	// コンストラクタ
	GameOver();
	// デストラクタ
	~GameOver();
	// 描画
	void Draw(SceneBase& scene);
	// 更新
	void Update();
};

#endif //_GAMEOVER_H_