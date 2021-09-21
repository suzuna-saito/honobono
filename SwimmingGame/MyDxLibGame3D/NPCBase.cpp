#include "NPCBase.h"
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

//NPCのモデルの拡大表示の大きさ
const float NPC_MODEL_SCALE = 1.0f;

/// <summary>
/// NPCのコンストラクタ
/// </summary>
NPCBase::NPCBase(int _sourceModelHandle)
	:mPos(VGet(0.0f,0.0f,0.0f))
	,mVelocity(VGet(0.0f,0.0f,0.0f))
{
	//モデルハンドルのコピー
	mModelHandle = MV1DuplicateModel(_sourceModelHandle);
	if (mModelHandle < 0)
	{
		//モデルハンドルの読み込みが失敗した場合の表示
		printfDx("データ読み込み失敗. sourceID:%d", _sourceModelHandle);
	}
}

/// <summary>
/// デストラクタ
/// </summary>
NPCBase::~NPCBase()
{
	//モデルの削除
	MV1DeleteModel(mModelHandle);
}


/// <summary>
/// 更新関数
/// </summary>
void NPCBase::Update()
{
	//モデルのset
	MV1SetPosition(mModelHandle, mPos);
}

/// <summary>
/// 描画関数
/// </summary>
void NPCBase::Draw()
{
	//モデルの大きさの変更
	MV1SetScale(mModelHandle, VGet(NPC_MODEL_SCALE, NPC_MODEL_SCALE, NPC_MODEL_SCALE));

	//モデルの表示
	MV1DrawModel(mModelHandle);
}