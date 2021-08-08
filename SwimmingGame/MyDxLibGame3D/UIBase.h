#ifndef _UIBASE_H_
#define _UIBASE_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/
#include <DxLib.h>

/// <summary>
/// UIベースのクラス
/// </summary>
class UIBase
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	UIBase(int _chara);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~UIBase();

	virtual void Update();    //更新関数
	virtual void Draw();    //描画関数

private:
};

#endif //_UIBASE_H_