#pragma once
#include "SceneBase.h"
#include "DxLib.h"

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
	// 描画
	void Draw(SceneBase& scene);
	// 更新
	void Update();
};