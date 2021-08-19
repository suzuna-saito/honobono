#pragma once
#include "DxLib.h"

/// <summary>
/// FishBaseクラス
/// </summary>
class FishBase
{
protected:

	int mModelHandle;                   // 魚Mob画像変数 
	int mModelFishTexture;             // 魚Mobテクスチャ

	VECTOR mPos;             // 魚の座標

	VECTOR mVelocity;     //移動速度

	VECTOR mRotate;    // Mobのモデルが向いている角度

	VECTOR mSetDancePos;    //シンクロ時最も多いポジション

	bool mInPoolFlag;    //プールに入っているかどうかのフラグ

public:
	// コンストラクタ
	FishBase(int _sourceModelHandle, int _sourceModelTexture);
	// デストラクタ
	virtual ~FishBase();

	// 更新関数
	virtual void Updata(FishBase* _mobFish);

	// シンクロで最も多い位置の設定
	void SetDancePos(VECTOR _setDancePos);

	// 描画関数
	virtual void Draw();

	//モデルハンドルの取得
	int GetModelHandle() { return mModelHandle; }

	//ポジションのsetter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

	//向きのsetter/getter
	void SetRotate(const VECTOR _setRotate) { mRotate = _setRotate; }
};