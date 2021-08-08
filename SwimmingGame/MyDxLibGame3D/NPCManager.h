#ifndef _NPCMANAGER_H_
#define _NPCMANAGER_H_

#include<DxLib.h>

//NPC�̐�
const int NPC_NUM = 4;

/// <summary>
/// �N���X�̒�`
/// </summary>
class NPCBase;

/// <summary>
/// �S�̓I��NPC�𑍊�����N���X
/// </summary>
class NPCManager final
{
public:
	NPCManager();    //�R���X�g���N�^
	~NPCManager();    //�f�X�g���N�^

	void Update();     //�X�V�֐�

	void Draw();    //�`��֐�


private:
	NPCBase* mNPC[NPC_NUM];    //NPC��l(��C)�̐���
	int mModelSourceHandle;    //NPC�̃��f���n���h��
	VECTOR mPos;    //NPC�̈ʒu
	VECTOR mVelocity;    //NPC�̈ړ����x

};

#endif // !_NPCMANAGER_H_
