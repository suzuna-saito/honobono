#ifndef _SATOSHI_H_
#define _SATOSHI_H_

#include"DxLib.h"

class SceneBase;
class UIGoal;

class Satoshi
{
public:
	// コンストラクタ
	Satoshi();
	// デストラクタ
	~Satoshi();
	
	// 更新
	void Update(SceneBase& scene, UIGoal& uiGoal);
	void Draw();

	float GetPosY() { return PosY; }

private:
	VECTOR pos;             // 描画座標
	VECTOR velocity;        // 移動速度ベクトル
	int satoshiGraphHandle; // 画像ハンドル
	float size;               // 画像サイズ
	float angle;            // 画像の回転角度
	float centerX, centerY; // 描画する画像の中心座標
	float hitRadius;
	float PosY;             // Y座標
};

#endif // !_SATOSHI_H_

