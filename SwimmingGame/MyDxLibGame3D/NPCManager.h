#ifndef _NPCMANAGER_H_
#define _NPCMANAGER_H_

#include<DxLib.h>

//NPCの数
const int NPC_NUM = 8;

/// <summary>
/// クラスの定義
/// </summary>
class NPCBase;

/// <summary>
/// 全体的なNPCを総括するクラス
/// </summary>
class NPCManager final
{
public:
	NPCManager();    //コンストラクタ
	~NPCManager();    //デストラクタ

	void CreatNPC();    //NPCの生成

	void DestroyNPC();    //NPCの削除

	void Update();     //更新関数

	void Draw();    //描画関数


private:
	NPCBase* mNPC[NPC_NUM];    //NPC一人(一匹)の生成
	int mModelSourceHandle;    //NPCのモデルハンドル
	VECTOR mPos;    //NPCの位置
	VECTOR mVelocity;    //NPCの移動速度

};

#endif // !_NPCMANAGER_H_
