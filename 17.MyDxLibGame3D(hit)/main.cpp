//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "ObstructManager.h"
#include "HitChecker.h"
#include "BackGround.h"
#include "Satoshi.h"
#include "SceneBase.h"
#include "Title.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Fade.h"
#include "UIBase.h"
#include "UIGoal.h"
#include "UIFireworks.h"
#include "Common.h"
#include "Sound.h"
#include "Timing.h"

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

	// 画面モードのセット
	SetGraphMode( SCREEN_W, SCREEN_H, 32);
	//ChangeWindowMode(TRUE);

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// カメラを生成.
		Camera* camera = new Camera();
		// 背景を生成.
		BackGround* backGround = new BackGround();
		// プレイヤーを生成.
		Player* player = new Player();
		// UI（ゴール）の生成
		UIGoal* uiGoal = new UIGoal();
		// UI(花火)の生成
		UIFireworks* uiFire = new UIFireworks();
		// シーンの生成
		SceneBase* sceneBase = new SceneBase();
		// サウンドの生成
		Sound* sound = new Sound();
		// フェードの生成
		Fade* fade = new Fade();
		// タイミングゲージの生成
		Timing* timing = new Timing();

		// フェードインちゅうかどうか
		bool fadeFlag = false;

		// タイトル
		// 音楽を再生
		sound->PlayBGM(*sceneBase);
		// タイトルを生成
		Title* Tit = new Title();
		while (sceneBase->GetScene() == sceneBase->title)
		{
			if (!sceneBase->GetChangeFlag())
			{
				// シーンを遷移する
				sceneBase->ChangeScene(*uiGoal, *player);

			}

			// 背景用カメラ位置を設定
			camera->SceneUpdate();
			// カーソル位置更新
			sceneBase->PointUpdate();
			// タイトル更新
			Tit->Update();

			// 画面を初期化する
			ClearDrawScreen();
			// タイトルを描画
			Tit->Draw(*sceneBase);

			// シーンを遷移する
			if (sceneBase->GetChangeFlag())
			{
				if (!fade->GetEndFlag())
				{
					fadeFlag = true;

					if (sceneBase->GetShutDownFlag())
					{
						// フェードアウトの更新
						fade->Update(fadeFlag, BLACK);
					}
					else
					{
						// フェードアウトの更新
						fade->Update(fadeFlag, WHITE);
					}
				}

				// フェードインが終わったらシーンを遷移する
				if (fade->GetEndFlag())
				{
					fadeFlag = false;
					fade->Init();
					if (sceneBase->GetShutDownFlag())
					{
						sceneBase->SetScene(SceneBase::Scene::gameEnd);
					}
					else
					{
						sceneBase->SetScene(SceneBase::Scene::play);
					}

					sceneBase->SetChangeFlag(false);
					sceneBase->ChangeScene(*uiGoal, *player);
				}
			}

			// 裏画面の内容を表画面に反映させる
			ScreenFlip();
		}
		// 音楽を止める
		sound->StopMusic(*sceneBase);
		// タイトルの消去
		delete(Tit);

		// サトシを生成
		Satoshi* satoshi = new Satoshi();
		// 障害物を生成.
		ObstructManager* obstructManager = new ObstructManager();
		obstructManager->CreateObstructs();
		// 当たり判定を生成
		HitChecker* hit = new HitChecker();
		// 距離の比率を作成
		uiGoal->GetDy(*player, *satoshi);
		//ゲーム
		// ゲーム用カメラ位置を設定
		camera->PlayerUpdate();
		// 音楽を再生
		sound->PlayBGM(*sceneBase);

		bool firstPlay = false;
		bool fadeInit = false;

		while (sceneBase->GetScene() == sceneBase->play)
		{
			if (!firstPlay)
			{
				// 画面を初期化する
				ClearDrawScreen();

				// 背景
				backGround->Draw();
				if (!fadeFlag)
				{
					// サトシの描画
					satoshi->Draw();
					// 障害物描画.
					obstructManager->Draw();
					// プレイヤー描画.
					player->Draw();

					
				}
				// 当たり判定UIの描画
				hit->Draw(*player);
				// UI(ゴール)の描画
				uiGoal->Draw();
				// タイミングゲージの描画
				timing->Draw();


				fadeFlag = true;

				// フェードアウトの更新
				fade->Update(!fadeFlag, WHITE);
				// 裏画面の内容を表画面に反映させる
				ScreenFlip();

				// フェードインが終わったらシーンを遷移する
				if (fade->GetEndFlag())
				{
					fadeFlag = false;
					firstPlay = true;
				}
			}
			else
			{
				if (!fadeInit)
				{
					fade->Init();
					fadeInit = true;

				}

				if (!uiGoal->GetGoalFlag() && !fadeFlag)
				{
					// 効果音再生
					sound->PlaySE(player->GetMoveFlag(), hit->GetisHit(), uiGoal->GetGoalFlag());
					// 背景
					backGround->Scroll();
					// プレイヤー制御.
					player->Update();
					// サトシの制御
					satoshi->Update(*sceneBase, *uiGoal);
					// 障害物制御.
					obstructManager->Update(*player, *uiGoal);
					// 残りゴール距離の更新
					uiGoal->Update();
					// タイミングゲージの更新
					timing->Update();

					// ヒットのチェック.
					hit->Check(*player, *obstructManager);
				}
				// 画面を初期化する
				ClearDrawScreen();

				// 背景
				backGround->Draw();
				if (!fadeFlag)
				{
					// サトシの描画
					satoshi->Draw();
					// 障害物描画.
					obstructManager->Draw();
					// プレイヤー描画.
					player->Draw();
				}
				// 当たり判定UIの描画
				hit->Draw(*player);
				// UI(ゴール)の描画
				uiGoal->Draw();
				// タイミングゲージの描画
				timing->Draw();


				// 花火の処理
				if (uiGoal->GetGoalFlag())
				{
					uiFire->Update();
					// UI(花火)の描画
					uiFire->Draw();

					// 花火の描画が終わったらフェードインの画面に移る
					if (uiFire->GetclearCount() >= uiFire->time)
					{
						fadeFlag = true;

						if (!fade->GetEndFlag())
						{
							fadeFlag = true;

							// フェードアウトの更新
							fade->Update(fadeFlag, WHITE);
						}

						// フェードインが終わったらシーンを遷移する
						if (fade->GetEndFlag())
						{
							fadeFlag = false;
							fade->Init();
							sceneBase->SetScene(SceneBase::Scene::gameClear);

							sceneBase->SetChangeFlag(false);
						}
					}

				}


				// Hpが0だったらシーンを遷移する
				if (player->GetHp() == 0)
				{
					fadeFlag = true;

					if (!fade->GetEndFlag())
					{
						fadeFlag = true;

						// フェードアウトの更新
						fade->Update(fadeFlag, BLACK);
					}

					// フェードインが終わったらシーンを遷移する
					if (fade->GetEndFlag())
					{
						fadeFlag = false;
						fade->Init();
						sceneBase->SetScene(SceneBase::Scene::gameOver);

						sceneBase->SetChangeFlag(false);
					}

				}
			}
			// 裏画面の内容を表画面に反映させる
			ScreenFlip();
		}
		// 音楽を止める
		sound->StopMusic(*sceneBase);

		// ゲームクリア
		GameClear* gameclear = new GameClear();
		// 音楽を再生
		sound->PlayBGM(*sceneBase);

		bool firstGameClear = false;
		bool fadeInitGameClear = false;
		while (sceneBase->GetScene() == sceneBase->gameClear)
		{
			if (!firstGameClear)
			{
				// 画面を初期化する
				ClearDrawScreen();
				fadeFlag = true;

				// クリア画面更新
				gameclear->Update();
				// 背景用カメラ位置を設定
				camera->SceneUpdate();
				// クリア画面を描画
				gameclear->Draw(*sceneBase);
				// フェードアウトの更新
				fade->Update(!fadeFlag, BLACK);
				// 裏画面の内容を表画面に反映させる
				ScreenFlip();

				// フェードインが終わったらシーンを遷移する
				if (fade->GetEndFlag())
				{
					fadeFlag = false;
					firstGameClear = true;
				}
			}
			else
			{
				if (!fadeInitGameClear)
				{
					fade->Init();
					fadeInitGameClear = true;

				}

				// シーンを遷移する
				sceneBase->ChangeScene(*uiGoal, *player);

				// カーソル位置更新
				sceneBase->PointUpdate();
				// クリア画面更新
				gameclear->Update();

				// 画面を初期化する
				ClearDrawScreen();

				// クリア画面を描画
				gameclear->Draw(*sceneBase);

				// シーンを遷移する
				if (sceneBase->GetChangeFlag())
				{
					if (!fade->GetEndFlag())
					{
						fadeFlag = true;

						if (sceneBase->GetShutDownFlag())
						{
							// フェードアウトの更新
							fade->Update(fadeFlag, BLACK);
						}
						else
						{
							// フェードアウトの更新
							fade->Update(fadeFlag, WHITE);
						}
						
					}

					// フェードインが終わったらシーンを遷移する
					if (fade->GetEndFlag())
					{
						fadeFlag = false;
						fade->Init();
						if (sceneBase->GetShutDownFlag())
						{
							sceneBase->SetScene(SceneBase::Scene::gameEnd);
						}
						else
						{
							sceneBase->SetScene(SceneBase::Scene::title);
						}
						sceneBase->SetChangeFlag(false);
						sceneBase->ChangeScene(*uiGoal, *player);
					}
				}

				// 裏画面の内容を表画面に反映させる
				ScreenFlip();
			}
		}
		// クリアの消去
		delete(gameclear);
		// 音楽を止める
		sound->StopMusic(*sceneBase);

		bool firstGameOver = false;
		bool fadeInitGameOver = false;
		// ゲームオーバー
		GameOver* gameover = new GameOver();
		sound->PlayBGM(*sceneBase);
		while (sceneBase->GetScene() == sceneBase->gameOver)
		{
			
			if (!firstGameOver)
			{
				// 画面を初期化する
				ClearDrawScreen();

				fadeFlag = true;

				// 背景用カメラ位置を設定
				camera->SceneUpdate();
				// オーバー画面を描画
				gameover->Draw(*sceneBase);
				// フェードアウトの更新
				fade->Update(!fadeFlag, WHITE);

				// 裏画面の内容を表画面に反映させる
				ScreenFlip();

				// フェードインが終わったらシーンを遷移する
				if (fade->GetEndFlag())
				{
					fadeFlag = false;
					firstGameOver = true;
				}
			}
			else
			{
				if (!fadeInitGameOver)
				{
					fade->Init();
					fadeInitGameOver = true;

				}

				// シーンを遷移する
				sceneBase->ChangeScene(*uiGoal, *player);

				// カーソル位置更新
				sceneBase->PointUpdate();
				// オーバー画面更新
				gameover->Update();
				// 画面を初期化する
				ClearDrawScreen();

				// オーバー画面を描画
				gameover->Draw(*sceneBase);

				// シーンを遷移する
				if (sceneBase->GetChangeFlag())
				{
					if (!fade->GetEndFlag())
					{
						fadeFlag = true;

						if (sceneBase->GetShutDownFlag())
						{
							// フェードアウトの更新
							fade->Update(fadeFlag, BLACK);
						}
						else
						{
							// フェードアウトの更新
							fade->Update(fadeFlag, WHITE);
						}
					}

					// フェードインが終わったらシーンを遷移する
					if (fade->GetEndFlag())
					{
						fadeFlag = false;
						fade->Init();
					
						if (sceneBase->GetShutDownFlag())
						{
							sceneBase->SetScene(SceneBase::Scene::gameEnd);
						}
						else
						{
							sceneBase->SetScene(SceneBase::Scene::title);
						}
						sceneBase->SetChangeFlag(false);
						sceneBase->ChangeScene(*uiGoal, *player);
					}
				}

				// 裏画面の内容を表画面に反映させる
				ScreenFlip();
				
			}
		}
		// 音楽を止める
		sound->StopMusic(*sceneBase);
		// オーバー画面の消去
		delete(gameover);
		// ゲーム終了処理
		if (sceneBase->GetScene() == sceneBase->gameEnd)
		{
			break;
		}
		// サウンドの消去
		delete(sound);
		// 背景の削除
		delete(backGround);
		// シーンの削除
		delete(sceneBase);
		delete(fade);
		// 当たり判定の削除
		delete(hit);
		// UIの削除
		delete(uiGoal);
		delete(uiFire);
		// プレイヤーを削除.
		delete(player);
		// サトシの削除
		delete(satoshi);
		// カメラを削除.
		delete(camera);
		// 障害物を削除.
		obstructManager->DestroyObstructs();
		delete(obstructManager);
	}

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}