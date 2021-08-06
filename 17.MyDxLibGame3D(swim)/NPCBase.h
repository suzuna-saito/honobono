#ifndef _NPCBASE_H_
#define _NPCBASE_H_

#include<DxLib.h>

/// <summary>
/// NPCの一人分のクラス
/// 名前の変更や追加・削除は行っても大丈夫です
/// </summary>
class NPCBase
{
public:
	NPCBase();	//コンストラクタ

	~NPCBase();	//デストラクタ

	virtual void Update();   //更新関数

	virtual void Draw();    //描画関数

	// NPCのモデルハンドルのgetter
	const int GetModelHandle() const { return mModelHandle; }

	//NPCのポジションのsetter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

protected:
	int mModelHandle;    //モデルハンドル変数
	VECTOR mPos;    //ポジション
	VECTOR mVelocity;    //移動速度

private:
};


#endif // !_NPCBASE_H_
