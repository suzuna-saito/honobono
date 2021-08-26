#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

// 前方宣言
class SceneBase;
class Timing;

/// <summary>
/// 音源関係クラス
/// </summary>
class Sound
{
public:
	// コンストラクタ
	Sound(const char* _filePath);
	// デストラクタ
	~Sound();

	/// <summary>
	/// シーンごとで音楽を再生する
	/// </summary>
/// < param name = "_scene"> シーン取得 </param>
	void PlayBGM();

	/// <summary>
	/// 効果音を再生する
	/// </summary>
	/// < param name = "_scene"> シーン取得 </param>
	void PlaySE();



	/// <summary>
	/// 再生している音楽を止める
	/// </summary>
	/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
	void StopMusic();

private:

	// サウンドを格納するハンドル
	int mSoundHandle;
	// 一回きりの音
	bool mOnceSoundFlag;

};

#endif //_SOUND_H_