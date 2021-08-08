#ifndef _SOUND_H_
#define _SOUND_H_
#include <DxLib.h>
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/

/// <summary>
/// 音源関係クラス
/// </summary>
class Sound
{
public:
	// コンストラクタ
	Sound();
	// デストラクタ
	~Sound();
	// 音楽を再生
	void PlayBGM(int _scene);
	// 効果音を再生
	void PlaySE(bool _movecheck, bool _hitCheck, bool _goalCheck);
	// 音楽を止める
	void StopMusic(int _scene);

private:
	// タイトルBGM
	int mTitleBGM;
	// ゲームBGM
	int mGameBGM;
	// クリアBGM
	int mClearBGM;
	// ゲームオーバーBGM
	int mOverBGM;
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