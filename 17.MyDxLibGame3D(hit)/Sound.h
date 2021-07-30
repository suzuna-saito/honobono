#pragma once
#include <DxLib.h>

// シーン別BGM切り替えに使用
class SceneBase;
// プレイヤーの動き確認に使用
class Hitchecker;
class Player;

class Sound
{
public:
	// コンストラクタ
	Sound();
	// デストラクタ
	~Sound();
	// 音楽を再生
	void PlayBGM(SceneBase& _scene);
	// 効果音を再生
	void PlaySE(bool _movecheck, bool _hitCheck, bool _goalCheck);
	// 音楽を止める
	void StopMusic(SceneBase& _scene);

private:
	// タイトルBGM
	int titleBGM;
	// ゲームBGM
	int gameBGM;
	// クリアBGM
	int clearBGM;
	// ゲームオーバーBGM
	int overBGM;
	// タイトルからゲーム画面移動するときの効果音
	int titleSound;
	// 自機が左右に移動したときの効果音
	int moveSound;
	// 自機が敵機にぶつかったときの効果音
	int damageSound;
	// ゴールした時の効果音
	int goalSound;
	// ゲームクリア時の効果音
	int clearSound;
	// ゲームオーバー時の効果音
	int overSound;
	// 一回きりの音
	bool SoundFlag;
};