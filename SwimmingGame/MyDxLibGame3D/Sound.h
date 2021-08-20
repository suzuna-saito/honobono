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
	Sound(SceneBase& _scene);
	// デストラクタ
	~Sound();

	/// <summary>
	/// シーンごとで音楽を再生する
	/// </summary>
/// < param name = "_scene"> シーン取得 </param>
	void PlayBGM(SceneBase& _scene);

	/// <summary>
	/// 効果音を再生する
	/// </summary>
	/// < param name = "_scene"> シーン取得 </param>
	void PlaySE(SceneBase& _scene);



	/// <summary>
	/// 再生している音楽を止める
	/// </summary>
	/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
	void StopMusic(SceneBase& _scene);

private:

	// タイトルBGM
	int mTitleBGM;
	// ゲームBGM_1
	int mGameBGM1;
	// ゲームBGM_2
	int mGameBGM2;
	// ゲームBGM_3
	int mGameBGM3;
	// リザルトBGM
	int mResultBGM;

	// タイトルからゲーム画面移動するときの効果音
	int mTitleSound;
	// パーフェクト時の効果音
	int mPerfectSound;
	// グッド時の効果音
	int mGoodSound;
	// バッド時の効果音
	int mBadSound;
	// 飛び込んで水の入った時の音
	int mWaterInSound;
	// シンクロでちゃぷちゃぷする音
	int mWaterOutSound;
	// リザルトでなる効果音
	int mResultSound;

	// 一回きりの音
	bool mOnceSoundFlag;

	// リズムボタン
	Timing* timing;
	
};

#endif //_SOUND_H_