#ifndef _TITLE_H_
#define _TITLE_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include "SceneBase.h"

/// <summary>
/// タイトルシーンクラス
/// シーケンスベースを元にして作成
/// </summary>
class Title : public SceneBase
{
private:
	int Model;        // メインモデル
	int BallModel;    // サブモデル(飾り)
	int BackGround;   // 3D背景
	int TitleText;    // タイトルテキスト
	int KeyText1[2];     // キー指示１
	int KeyText2[2];     // キー指示２
	int PointGraph;      // カーソル
	int Count;           // 濃度カウント
	int ColorAlpha;      // 追加する濃さの値

public:
	// コンストラクタ
	Title();
	// デストラクタ
	virtual ~Title();
	// 描画
	void Draw(SceneBase& scene);
	// 更新
	void Update();
};

#endif //_TITLE_H_