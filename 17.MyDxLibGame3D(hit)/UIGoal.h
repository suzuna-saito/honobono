#pragma once
#include "UIBase.h"

class Player;
class Satoshi;

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
    void GetDy(Player& _player, Satoshi& _satoshi);
  
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
    bool GetGoalFlag() { return GoalFlag; }
    
    /// <summary>
    /// UIプレイヤーの座標Yを取得
    /// </summary>
    /// <returns> プレイヤーの座標を渡す </returns>
    float GetUIPosY() { return playerY; }

private:
    // ゴール画像
    int goalImg;
    // プレイヤー画像
    int playerImg;
    // ベース画像
    int baseImg;
    // ゴール画像の座標X
    int goalX;
    // ゴール画像の座標Y
    int goalY;
    //プレイヤーの座標Y
    int playerX;
    //プレイヤーの座標Y
    float playerY;
    // ベース画像の座標X
    int baseX;
    // ベース画像の座標Y
    int baseY;


    //計算用Y座標1
    float PosY1;
    //計算用Y座標2
    float PosY2;
    //ゲームの距離
    float MainPosY;
    // UIプレイヤーが移動できる最大値
    int playerMaxY;
    
    //距離の比率
    float distanceRatio;
    //比率の値
    float ratio;
    //ゴール判定
    bool GoalFlag;

};