#pragma once
#include <DxLib.h>

class UIBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_object"> �I�u�W�F�N�g </param>
	UIBase(int _object);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~UIBase();

	virtual void Update();
	virtual void Draw();

private:

};