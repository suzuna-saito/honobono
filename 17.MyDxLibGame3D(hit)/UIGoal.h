#pragma once
#include "UIBase.h"

class Player;
class Satoshi;

class UIGoal : UIBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    UIGoal();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~UIGoal();

    /// <summary>
    /// �����̔䗦���o��
    /// </summary>
    /// <param name="_player"> �v���C���[�̍��W�擾�̂��ߎg�p </param>
    /// <param name="satoshi">      �T�g�V�̍��W�擾�̂��ߎg�p </param>
    void GetDy(Player& _player, Satoshi& _satoshi);
  
    /// <summary>
    /// �X�V
    /// </summary>
    void Update();
  
    /// <summary>
    /// �`��
    /// </summary>
    void Draw();

    /// <summary>
    /// �S�[���������m�F����
    /// </summary>
    /// <returns> �S�[�������Ԃ� </returns>
    bool GetGoalFlag() { return GoalFlag; }
    
    /// <summary>
    /// UI�v���C���[�̍��WY���擾
    /// </summary>
    /// <returns> �v���C���[�̍��W��n�� </returns>
    float GetUIPosY() { return playerY; }

private:
    // �S�[���摜
    int goalImg;
    // �v���C���[�摜
    int playerImg;
    // �x�[�X�摜
    int baseImg;
    // �S�[���摜�̍��WX
    int goalX;
    // �S�[���摜�̍��WY
    int goalY;
    //�v���C���[�̍��WY
    int playerX;
    //�v���C���[�̍��WY
    float playerY;
    // �x�[�X�摜�̍��WX
    int baseX;
    // �x�[�X�摜�̍��WY
    int baseY;


    //�v�Z�pY���W1
    float PosY1;
    //�v�Z�pY���W2
    float PosY2;
    //�Q�[���̋���
    float MainPosY;
    // UI�v���C���[���ړ��ł���ő�l
    int playerMaxY;
    
    //�����̔䗦
    float distanceRatio;
    //�䗦�̒l
    float ratio;
    //�S�[������
    bool GoalFlag;

};