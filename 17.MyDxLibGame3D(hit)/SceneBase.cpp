#include "SceneBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneBase::SceneBase()
	: mEndFlag(false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneBase::~SceneBase()
{
}

/// <summary>
/// ゲーム
/// mainでSceneBaseのGame関数を呼ぶとゲームが起動する
/// mainで必要なヘッダーはSceneBaseとCommonだけwhileもいりません
/// mainをかなり短縮しました
/// </summary>
void SceneBase::Game()
{
	Title* title = new Title();
	Play* play = new Play();
	Result* result = new Result();

	while (!ProcessMessage() && !mEndFlag)
	{
		if (!mEndFlag)
		{
			title->TitleScene();
			mEndFlag = title->GetEndFlag();
		}

		if (!mEndFlag)
		{
			play->PlayScene();
			mEndFlag = play->GetEndFlag();
		}

		/*if (!mEndFlag)
		{
			result->ResultScene();
			mEndFlag = result->GetEndFlag();
		}*/
	}

	delete(title);
	delete(play);
	delete(result);
}
