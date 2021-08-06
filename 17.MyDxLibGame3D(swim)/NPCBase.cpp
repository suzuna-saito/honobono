#include "NPCBase.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

/// <summary>
/// NPCのコンストラクタ
/// </summary>
NPCBase::NPCBase()
	:mModelHandle(-1)
	,mPos(VGet(0.0f,0.0f,0.0f))
	,mVelocity(VGet(0.0f,0.0f,0.0f))
{

}

/// <summary>
/// デストラクタ
/// </summary>
NPCBase::~NPCBase()
{

}

/// <summary>
/// 更新関数
/// </summary>
void NPCBase::Update()
{

}

/// <summary>
/// 描画関数
/// </summary>
void NPCBase::Draw()
{

}