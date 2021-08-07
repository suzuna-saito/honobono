#include <DxLib.h>

class SceneBase;    // シーン別BGM切り替えに使用
class Hitchecker;   // プレイヤーの動き確認に使用
class Player;       // プレイヤーの動き確認に使用

/// <summary>
/// ゲーム内音楽のクラス
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
	// 音楽を再生するかを管理するフラグ
	bool SoundFlag;
};