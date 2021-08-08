#include "NPCManager.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

//コンストラクタ
NPCManager::NPCManager()
	:mModelSourceHandle(-1)
	,mPos(VGet(0.0f,0.0f,0.0f))
	,mVelocity(VGet(0.0f,0.0f,0.0f))
{
}

//デストラクタ
NPCManager::~NPCManager()
{
}

//更新関数
void NPCManager::Update()
{
}


//描画関数
void NPCManager::Draw()
{

}