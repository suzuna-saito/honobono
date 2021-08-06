#ifndef _UIGOAL_H_
#define _UIGOAL_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

#include "UIBase.h"

/// <summary>
/// ゴールした時のUIクラス
/// </summary>
class UIGoal : UIBase
{
public:
    UIGoal();               // コンストラクタ
    ~UIGoal();              // デストラクタ

    // 距離の比率を出す
    void GetDy(Player& _player, Satoshi& _satoshi);
    void Update();      	// 更新
    void Draw();	        // 描画

    // その時のそれぞれの値を返す
    bool GetGoalFlag() { return mGoalFlag; }
    float GetUIPosY() { return mUIPosY; }

private:
    int mGoalImg;            // ゴール画像
    int mPlayerImg;          // プレイヤー画像
    int mBaseImg;            // ベース画像
    float mPosY1;            //計算用Y座標1
    float mPosY2;            //計算用Y座標2
    float mMainPosY;         //ゲームの距離
    float mUIPosY;           //UIの距離
    float mDy;               //距離の比率
    bool mGoalFlag;          //ゴール判定

};

#endif //_UIGOAL_H_