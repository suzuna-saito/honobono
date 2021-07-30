#pragma once
#include "UIBase.h"

class Player;
class Satoshi;

class UIGoal : UIBase
{
public:
    UIGoal();               // RXgN^
    ~UIGoal();              // fXgN^

    // £Ìä¦ðo·
    void GetDy(Player& player, Satoshi& satoshi);
    void Update();      	// XV
    void Draw();	        // `æ

    // S[»èðn·
    bool GetGoalFlag() { return GoalFlag; }

    float GetUIPosY() { return UIPosY; }

private:
    int goalImg;            // S[æ
    int playerImg;          // vC[æ
    int baseImg;            // x[Xæ
    float PosY1;            //vZpYÀW1
    float PosY2;            //vZpYÀW2
    float MainPosY;         //Q[Ì£
    float UIPosY;           //UIÌ£
    float Dy;               //£Ìä¦
    bool GoalFlag;          //S[»è

};