/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "UIGoal.h"

// コンストラクタ
UIGoal::UIGoal()
	:UIBase(mGoalImg)
{
}

// デストラクタ
UIGoal::~UIGoal()
{

}

//// 距離の比率を出す
///*
//* 必要そうなので丸々残しておきます
//*/
//void UIGoal::GetDy(Player& _player, Satoshi& _satoshi)
//{
//	// この流れでUIとGAMEの距離の比率が出ます
//	// 一応どこでも呼び出せるようにするため関数を作りました
//	// PlayerにPosYとGetPosY関数の追加
//	// SatoshiにPosYとGetPosY関数の追加
//	// mainのほうのSceneBase生成の後に呼び出しています
//
//	PosY1 = satoshi.GetPosY();
//	PosY2 = player.GetPosY();
//
//	MainPosY = PosY1 - PosY2;
//	Dy = (UIPosY - 90) / MainPosY;
//
//	// 画像がサトシが2D、ピカチュウが3Dでの表示
//	// ゲームのほうの位置表示が変わっているので、下記の計算で速度調整をかけてます
//	// 距離が変わったら変えてください
//	Dy *= 0.255f;
//
//	// サトシはZ座標で計算を行っています(距離差を出すため元の500で計算してます)
//	// 	 ゲームの距離 = サトシZ座標(PosY1) - ピカチュウのY座標(PosY2)
//	//   距離の比率 = UIのピカチュウのY - UIのサトシのY / ゲームの距離
//	// 上下移動は考えていない計算です
//	// 時間がないので、ここまでですみません
//}

// 更新内容
void UIGoal::Update()
{
}

// 描画内容
void UIGoal::Draw()
{
}