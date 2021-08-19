#ifndef _FISH_MANAGER_H_
#define _FISH_MANAGER_H_

#include"DxLib.h"

//定数
const int FISH_MOB_NUM = 11;    // 魚の数

/// <summary>
/// Mobの魚の
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
	FishBase* mMobFish[FISH_MOB_NUM];    //mobの魚の配列

	int mModelSourceHandle;    //mobの魚たちのモデルハンドル
	int mModelSourceTexture;
};

#endif // !_FISH_MANAGER_H_
