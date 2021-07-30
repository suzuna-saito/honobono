#pragma once
#include "UIBase.h"

class Player;
class Satoshi;

class UIGoal : UIBase
{
public:
    UIGoal();               // コンストラクタ
    ~UIGoal();              // デストラクタ

    // 距離の比率を出す
    void GetDy(Player& player, Satoshi& satoshi);
    void Update();      	// 更新
    void Draw();	        // 描画

    // ゴール判定を渡す
    bool GetGoalFlag() { return GoalFlag; }

    float GetUIPosY() { return UIPosY; }

private:
    int goalImg;            // ゴール画像
    int playerImg;          // プレイヤー画像
    int baseImg;            // ベース画像
    float PosY1;            //計算用Y座標1
    float PosY2;            //計算用Y座標2
    float MainPosY;         //ゲームの距離
    float UIPosY;           //UIの距離
    float Dy;               //距離の比率
    bool GoalFlag;          //ゴール判定

};