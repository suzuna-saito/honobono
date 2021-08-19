#ifndef _UIGOAL_H_
#define _UIGOAL_H_
/*
* ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
*/

#include "UIBase.h"

/// <summary>
/// �S�[����������UI�N���X
/// </summary>
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

    //void GetDy(Player& _player, Satoshi& _satoshi);

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
    bool GetGoalFlag() { return mGoalImg; }

    /// <summary>
    /// UI�v���C���[�̍��WY���擾
    /// </summary>
    /// <returns> �v���C���[�̍��W��n�� </returns>
    float GetUIPosY() { return mUIPosY; }

private:
    int mGoalImg;            // �S�[���摜
    int mPlayerImg;          // �v���C���[�摜
    int mBaseImg;            // �x�[�X�摜
    float mPosY1;            //�v�Z�pY���W1
    float mPosY2;            //�v�Z�pY���W2
    float mMainPosY;         //�Q�[���̋���
    float mUIPosY;           //UI�̋���
    float mDy;               //�����̔䗦
    bool mGoalFlag;          //�S�[������

};

#endif //_UIGOAL_H_