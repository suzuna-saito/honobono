#ifndef _SATOSHI_H_
#define _SATOSHI_H_

#include"DxLib.h"
#include "UIBase.h"

class SceneBase;
class UIGoal;

/// <summary>
/// ゴール地点にサトシを描画するクラス
/// </summary>
class Satoshi : UIBase
{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Satoshi();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Satoshi();
	
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="scene"> ゲームシーンに入ってから描画するため </param>
    /// <param name="uiGoal"> プレイヤーとの距離を測るため </param>
	void Update(UIGoal& _uiGoal);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// サトシの座標Yを取得 
	/// </summary>
	/// <returns>サトシの座標を返す</returns>
	float GetPosY() { return posY; }

private:
	// 描画座標
	VECTOR pos;
	// 移動速度ベクトル
	VECTOR velocity;
	// 座標X
	float x;
	// 座標Y
	float y;
	// 座標Z
	float z;        
	// 移動するときの座標X
	float veloX;            
	// 移動するときの座標Y
	float veloY;
	// 移動するときの座標Z
	float veloZ;
	// 画像ハンドル
	int satoshiImg;
	// 画像サイズ
	float size;
	// 画像の回転角度
	float angle; 
	// 画像の中心座標X
	float centerX;
	// 画像の中心座標Y
	float centerY;
	//float hitRadius;
	// Y座標
	float posY;
	// Y座標のMax値
	float posMax;

};

#endif // !_SATOSHI_H_

