#include "SceneBase.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneBase::SceneBase()
	: mEndFlag(false)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneBase::~SceneBase()
{
}

/// <summary>
/// �Q�[��
/// main��SceneBase��Game�֐����ĂԂƃQ�[�����N������
/// main�ŕK�v�ȃw�b�_�[��SceneBase��Common����while������܂���
/// main�����Ȃ�Z�k���܂���
/// </summary>
void SceneBase::Game()
{
	Title* title = new Title();
	Play* play = new Play();
	Result* result = new Result();

	while (!ProcessMessage() && !mEndFlag)
	{
		if (!mEndFlag)
		{
			title->TitleScene();
			mEndFlag = title->GetEndFlag();
		}

		if (!mEndFlag)
		{
			play->PlayScene();
			mEndFlag = play->GetEndFlag();
		}

		/*if (!mEndFlag)
		{
			result->ResultScene();
			mEndFlag = result->GetEndFlag();
		}*/
	}

	delete(title);
	delete(play);
	delete(result);
}
