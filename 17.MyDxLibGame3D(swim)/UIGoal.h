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
    UIGoal();               // �R���X�g���N�^
    ~UIGoal();              // �f�X�g���N�^

    // �����̔䗦���o��
    void GetDy(Player& _player, Satoshi& _satoshi);
    void Update();      	// �X�V
    void Draw();	        // �`��

    // ���̎��̂��ꂼ��̒l��Ԃ�
    bool GetGoalFlag() { return mGoalFlag; }
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