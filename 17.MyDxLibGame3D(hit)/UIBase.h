#pragma once
#include <DxLib.h>

class UIBase
{
public:
	UIBase(int _chara);				// �R���X�^���X
	~UIBase();				// �f�X�g���N�^

	virtual void Update();
	virtual void Draw();

private:

};