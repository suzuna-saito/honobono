#pragma once
#include <DxLib.h>

class UIBase
{
public:
	UIBase(int _chara);				// コンスタンス
	~UIBase();				// デストラクタ

	virtual void Update();
	virtual void Draw();

private:

};