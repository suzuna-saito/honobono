//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
// インクルード
#include "DxLib.h"
#include "Common.h"
#include "SceneManager.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	//画面モードのセット
	SetGraphMode( SCREEN_W, SCREEN_H, 32);
	ChangeWindowMode(TRUE);

	// シーン管理するクラスを生成
	SceneManager* sceneManager = new SceneManager();

	// ゲームの更新を行うか確認するのためフラグ
	bool isRun = true;

	// 更新を行うかのフラグがtrueでエスケープキーが押されるか、ウインドウが閉じられるまでループ
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE) && isRun)
	{
		// 画面を初期化する
		ClearDrawScreen();

		// シーン管理更新
		isRun = sceneManager->UpdateScene();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	// シーンの管理クラス削除
	delete sceneManager;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}