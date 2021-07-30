#pragma once
#include "UIBase.h"

class Player;
class Satoshi;

class UIGoal : UIBase
{
public:
    UIGoal();               // �R���X�g���N�^
    ~UIGoal();              // �f�X�g���N�^

    // �����̔䗦���o��
    void GetDy(Player& player, Satoshi& satoshi);
    void Update();      	// �X�V
    void Draw();	        // �`��

    // �S�[�������n��
    bool GetGoalFlag() { return GoalFlag; }

    float GetUIPosY() { return UIPosY; }

private:
    int goalImg;            // �S�[���摜
    int playerImg;          // �v���C���[�摜
    int baseImg;            // �x�[�X�摜
    float PosY1;            //�v�Z�pY���W1
    float PosY2;            //�v�Z�pY���W2
    float MainPosY;         //�Q�[���̋���
    float UIPosY;           //UI�̋���
    float Dy;               //�����̔䗦
    bool GoalFlag;          //�S�[������

};