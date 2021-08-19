#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

// 前方宣言
class SceneBase;

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
	/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
	/// <return> 読み込んでいる音楽を再生 </return> 
	void PlayBGM(SceneBase& _scene);

	/// <summary>
	/// 効果音を再生する
	/// </summary>
	/// < param name = "_moveCheck"> プレイヤーが動いていることを確認 </param>
	/// < param name = "_hitCheck">  プレイヤーがボールにぶつかったことを確認 </param>
	/// < param name = "_movecheck"> プレイヤーがゴールしたことを確認 </param>
	void PlaySE(bool _movecheck, bool _hitCheck, bool _goalCheck);

	/// <summary>
	/// 再生している音楽を止める
	/// </summary>
	/// < param name = "_scene"> シーンベースからシーンを拝借 </param>
	void StopMusic(SceneBase& _scene);

private:
	// タイトルBGM
	int mTitleBGM;
	// ゲームBGM
	int mGameBGM;
	// クリアBGM
	int mClearBGM;
	// ゲームオーバーBGM
	int mOverBGM;
	// アーティスティックスイミングに使用するBGM
	int mDanceBGM;
	// アーティスティックスイミングに使用するBGMショート.ver
	int mDanceShortBGM;
	// タイトルからゲーム画面移動するときの効果音
	int mTitleSound;
	// 自機が左右に移動したときの効果音
	int mMoveSound;
	// 自機が敵機にぶつかったときの効果音
	int mDamageSound;
	// ゴールした時の効果音
	int mGoalSound;
	// ゲームクリア時の効果音
	int mClearSound;
	// ゲームオーバー時の効果音
	int mOverSound;
	// 一回きりの音
	bool mOnceSoundFlag;
};

#endif //_SOUND_H_