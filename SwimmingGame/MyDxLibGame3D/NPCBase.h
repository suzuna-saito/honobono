#ifndef _NPCBASE_H_
#define _NPCBASE_H_

#include<DxLib.h>

/// <summary>
/// NPC�̈�l���̃N���X
/// ���O�̕ύX��ǉ��E�폜�͍s���Ă����v�ł�
/// </summary>
class NPCBase
{
public:
	NPCBase(int _sourceModelHandle);	//�R���X�g���N�^

	~NPCBase();	//�f�X�g���N�^

	virtual void Update();   //�X�V�֐�

	virtual void Draw();    //�`��֐�

	// NPC�̃��f���n���h����getter
	const int GetModelHandle() const { return mModelHandle; }

	//NPC�̃|�W�V������setter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

protected:
	int mModelHandle;    //���f���n���h���ϐ�
	VECTOR mPos;    //�|�W�V����
	VECTOR mVelocity;    //�ړ����x

private:
};


#endif // !_NPCBASE_H_
