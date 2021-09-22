//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
// インクルード
#include "DxLib.h"
#include "Common.h"
#include "SceneManager.h"
#include "EffekseerForDXLib.h"

void InitializeEffekseer();

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
	SetGraphMode(SCREEN_W, SCREEN_H, 16);
	//SetGraphMode(640, 480, 16);
	/*SetGraphMode( SCREEN_W, SCREEN_H, 32);*/
	//ChangeWindowMode(TRUE);

	InitializeEffekseer();

	// シーン管理するクラスを生成
	SceneManager* sceneManager = new SceneManager();

	// ゲームの更新を行うか確認するのためフラグ
	bool isRun = true;

	// 更新を行うかのフラグがtrueでエスケープキーが押されるか、ウインドウが閉じられるまでループ
	while (!CheckHitKey(KEY_INPUT_ESCAPE) && isRun)
	{
		// 画面を初期化する
		ClearDrawScreen();

		Effekseer_Sync3DSetting();

		// シーン管理更新
		isRun = sceneManager->UpdateScene();

		UpdateEffekseer3D();

		DrawEffekseer3D();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		ProcessMessage();
	}

	// シーンの管理クラス削除
	delete sceneManager;

	// Effekseerの終了
	Effkseer_End();

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}

/// <summary>
/// Effekseerの初期化
/// </summary>
void InitializeEffekseer()
{
	// DXライブラリとEffekseerの初期化処理
	if (Effekseer_Init(8000) == -1)
	{
		printf("Effekseer初期化に失敗！\n");			                              // エラーが起きたら直ちに終了
	}

	//---------------------------------------------------+
	// Effekseer関連の初期化
	//---------------------------------------------------+
	SetUseDirect3DVersion(DX_DIRECT3D_11);                    // DirectX11を使用
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	SetUseZBuffer3D(TRUE);                                    // ZBufferを使用
	SetWriteZBuffer3D(TRUE);                                  // ZBufferへの書き込みを許可
}