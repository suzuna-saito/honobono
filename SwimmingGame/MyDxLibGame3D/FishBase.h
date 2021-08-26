#ifndef _FISHBASE_H_
#define _FISHBASE_H_

//前方宣言
#include "DxLib.h"

/// <summary>
/// FishBaseクラス
/// </summary>
class FishBase
{
public:
	FishBase(int _sourceModelHandle);	// コンストラクタ

	virtual ~FishBase();										// デストラクタ

	virtual void Updata() = 0;									// 更新関数(純粋仮想関数)

	virtual void Draw(int _debugColor);							// 描画関数

	/*----それぞれのsetter / getter*/

	int GetModelHandle() { return mModelHandle; }				//モデルハンドルの取得

	//ポジションのsetter/getter
	void SetPos(const VECTOR _setPos) { mPos = _setPos; }
	const VECTOR& GetPos() const { return mPos; }

	//向きのsetter/getter
	void SetRotate(const VECTOR _setRotate) { mRotate = _setRotate; }
	const VECTOR& GetRotate()const { return mRotate; }

	//アーティスティックスイミング開始時の座標のgetter
	const VECTOR& GetDancePos()const { return mSetDancePos; }

protected:

	int		mModelHandle;		// モデルハンドル変数 
	int		mModelFishTexture;	// モデルテクスチャ変数

	VECTOR	mPos;				// 座標

	VECTOR	mVelocity;			// 移動速度

	VECTOR	mRotate;			// モデルが向いている角度

	VECTOR	mSetDancePos;		//シンクロ時最も多いポジション
};


#endif // !_FISHBASE_H_