#pragma once
#include <DxLib.h>

class UIBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_object"> オブジェクト </param>
	UIBase(int _object);
	/// <summary>
	/// デストラクタ
	/// </summary>
	~UIBase();

	virtual void Update();
	virtual void Draw();

private:

};