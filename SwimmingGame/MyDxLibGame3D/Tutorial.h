#pragma once
#include "SceneBase.h"

class Tutorial : public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Tutorial();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Tutorial();

	/// <summary>
	/// チュートリアルシーンの更新
	/// </summary>
	SceneBase* Update()override;

	/// <summary>
	/// テキストの更新
	/// </summary>
	void TextUpdate();


	/// <summary>
	/// チュートリアルシーンの描画
	/// </summary>
	void Draw()override;

private:
	//  背景
	// 背景画像
	int mBackGroundGraph; 
	// 背景座標X
	int mBackPosX;
	// 背景座標Y
	int mBackPosY;
	// 背景の拡大X
	const int BACK_EXTEND_X;
	// 背景の拡大Y
	const int BACK_EXTEND_Y;

	//  チュートリアル
	// チュートリアル画像
	int mTutorialGraph;
	// チュートリアル座標X
	int mTutorialkPosX;
	// チュートリアル座標Y
	int mTutorialPosY;
	// チュートリアルの拡大X
	const int TUTORIAL_EXTEND_X;
	// チュートリアルの拡大Y
	const int TUTORIAL_EXTEND_Y;


	//  テキスト
	// スタートテキスト
	int mStartText;
	// スタートテキストの座標X
	int mStartTextPosX;
	// スタートテキストの座標Y
	int mStartTextPosY;
	// スタートテキストアルファ値
	int mStartTextAlpha;
	// スタートテキストアルファ値カウント
	int mStartTextCount;
	// アルファ値の最大値
	const int ALPHA_MAX_POINT;
	// アルファ値の最小値
	const int ALPHA_MIN_POINT;
	// スキップテキスト
	int mSkipText;
	// スキップテキストの座標X
	int mSkipTextPosX;
	// スキップテキストの座標X
	int mSkipTextPosY;
	// スキップテキストが描画されるフラグ
	bool mSkipDrawFlag;

	// スキップするかどうか true:シーン遷移 false:遷移しない
	bool mSkipFlag;


	//  時間ゲージ
	// ゲージを表示する時間
	int mTime;
	// ゲージを表示する時間の最大値
	int mTimeMax;
	// スキップテキストを描画する時間
	int mSkipDrawTime;
	// ゲージの色
	int mWhite;
	// ゲージの座標X1
	int mGageX1;
	// ゲージの座標Y
	int mGageY1;
	// ゲージの座標X2
	int mGageX2;
	// ゲージの座標Y2
	int mGageY2;



	//  サウンド
	// チュートリアルのBGM
	class Sound* mTutorialBGM;
	// チュートリアルの効果音
	class Sound* mTutorialSE;

	class Camera* camera;

	class Time* time;


};

