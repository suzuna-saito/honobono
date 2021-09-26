#include "NPCManager.h"
#include"NPCBase.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

/// <summary>
/// コンストラクタ
/// </summary>
NPCManager::NPCManager()
	:mModelSourceHandle(-1)
	,mPos(VGet(0.0f,0.0f,0.0f))
	,mVelocity(VGet(0.0f,0.0f,0.0f))
{
	//モデルの初期化
	for (int i = 0; i < NPC_NUM; i++)
	{
		mNPC[i] = NULL;
	}
}

/// <summary>
/// デストラクタ
/// </summary>
NPCManager::~NPCManager()
{
}

/// <summary>
/// NPCの生成
/// </summary>
void NPCManager::CreatNPC()
{
	//モデルのロード
	mModelSourceHandle = MV1LoadModel("data/model/fish/Mobfish.mqo");

	for (int i = 0; i < NPC_NUM; i++)
	{
		//NPCのベースの生成
		mNPC[i] = new NPCBase(mModelSourceHandle);

		//NPCの位置の初期化
	}
}


void NPCManager::DestroyNPC()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		delete(mNPC[i]);
		mNPC[i] = NULL;
	}
	MV1DeleteModel(mModelSourceHandle);
}

//更新関数
void NPCManager::Update()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		if (mNPC[i] != NULL)
		{
			mNPC[i]->Update();
		}
	}
}


//描画関数
void NPCManager::Draw()
{
	for (int i = 0; i < NPC_NUM; i++)
	{
		if (mNPC[i] != NULL)
		{
			mNPC[i]->Draw();
		}
	}
}