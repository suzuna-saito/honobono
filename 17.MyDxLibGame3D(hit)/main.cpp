//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
// インクルード
#include "DxLib.h"
#include "SceneBase.h"
#include "Title.h"
#include "Play.h"
#include "GameOver.h"
#include "GameClear.h"
#include "Camera.h"
#include "Sound.h"
#include "Common.h"

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

	// シーンの生成
	SceneBase* nowScene = new Title();

	// サウンドの生成
	Sound* sound = new Sound();

	// 音楽を再生
	sound->PlayBGM(*nowScene);

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		// シーンの更新処理
		// 現在と次のシーンを比較するためのSceneBaseクラスポインタ
		// Updateの戻り値で次のシーンのポインタが返ってくる
		SceneBase* tmpScene = nowScene->Update();

		// 現在のシーンであるnowSceneと次のシーンであるtmpSceneを比較
		// シーンが変わっていたら
		if (tmpScene != nowScene)
		{
			// 音楽を止める
			sound->StopMusic(*tmpScene);

			// 現在のシーンを解放
			delete nowScene;
			// nowSceneに現在のシーン（tmpScene）を代入
			nowScene = tmpScene;

			// 音楽を再生
			sound->PlayBGM(*nowScene);
		}
		if (nowScene->GetScene() == nowScene->gameEnd)
		{
			break;
		}
		// 画面を初期化する
		ClearDrawScreen();

		// 現在のシーンを描画
		nowScene->Draw();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	// シーンの削除
	delete nowScene;

	// 音楽の削除
	delete sound;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}