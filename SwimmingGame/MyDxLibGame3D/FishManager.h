#ifndef _FISH_MANAGER_H_
#define _FISH_MANAGER_H_

#include"DxLib.h"

//�萔
const int FISH_MOB_NUM = 11;    // ���̐�

/// <summary>
/// Mob�̋���
/// </summary>
class FishBase;

class FishManager final
{
public:
	FishManager();
	~FishManager();

	void CreatMobFish();
	void DestroyMobFish();

	void Updata();

	void Draw();

private:
	FishBase* mMobFish[FISH_MOB_NUM];    //mob�̋��̔z��

	int mModelSourceHandle;    //mob�̋������̃��f���n���h��
	int mModelSourceTexture;
};

#endif // !_FISH_MANAGER_H_
