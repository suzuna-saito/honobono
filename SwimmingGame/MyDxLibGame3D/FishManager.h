#ifndef _FISH_MANAGER_H_
#define _FISH_MANAGER_H_

#include"DxLib.h"

//定数
const int FISH_NUM = 11;    // 魚の数

/// <summary>
/// 魚のベース/処理クラスの前方宣言
/// </summary>
class FishBase;

/// <summary>
/// 魚たちのまとめクラス
/// </summary>
class FishManager final
{
public:
	FishManager();					//コンストラクタ
	~FishManager();					//デストラクタ

	void CreatFish();				//魚たちの生成
	void DestroyFish();				//魚たちの削除

	void Updata();					//更新関数

	void Draw();					//描画関数

private:
	FishBase* mFish[FISH_NUM];		//魚たちの配列

	int mSourceModelHandle;			//魚たちのモデルハンドル変数

	const VECTOR BEFORE_DIVING_POS[FISH_NUM];	//それぞれの魚たちの座標
	const VECTOR BEFORE_DIVING_ROTATE[FISH_NUM];//それぞれの魚たちの向き
	const VECTOR SET_DANCING_POS[FISH_NUM];		//それぞれの魚たちのアーティスティックスイミング開始時の座標

	//---------------デバック用変数-------------
	const int DEBUG_SPHERE_COLOR[FISH_NUM];		//それぞれの魚たちのDrawSphere3Dデバック用の色
};


#endif // !_FISH_MANAGER_H_
