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

    /// <summary>
    /// コンストラクタ
    /// </summary>
    UIGoal();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~UIGoal();

    /// <summary>
    /// 距離の比率を出す
    /// </summary>
    /// <param name="_player"> プレイヤーの座標取得のため使用 </param>
    /// <param name="satoshi">      サトシの座標取得のため使用 </param>

    //void GetDy(Player& _player, Satoshi& _satoshi);

    /// <summary>
    /// 更新
    /// </summary>
    void Update();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw();

    /// <summary>
    /// ゴールしたか確認する
    /// </summary>
    /// <returns> ゴール判定を返す </returns>
    bool GetGoalFlag() { return mGoalImg; }

    /// <summary>
    /// UIプレイヤーの座標Yを取得
    /// </summary>
    /// <returns> プレイヤーの座標を渡す </returns>
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