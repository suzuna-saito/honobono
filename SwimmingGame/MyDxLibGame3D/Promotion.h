#pragma once
#include "DxLib.h"

class Promotion
{
public:

	// コンストラクタ
	Promotion();
	// デストラクタ
	~Promotion();

	/// <summary>
	/// 広告の描画
	/// </summary>
	void Draw();


	/// <summary>
	/// 広告のセット
	/// </summary>
	void SetPromo();

private:
	// 広告を表示させるポジション
	const VECTOR mPromoDrawPos[16];
	// 広告の土台を表示させるポジション１
	const VECTOR mBaseDrawPos1[2];
	// 広告の土台を表示させるポジション２
	const VECTOR mBaseDrawPos2[2];
	// サイズのセット
	const VECTOR mSetSize;

	//  テクスチャ
	// ベース
	int mBase;
	// シンプルな広告
	int mSimple;
	// ファルソックの広告
	int mFalsoc;
	// 学校の広告
	int mSchool;
	// ほのぼのの広告
	int mHonobono;
	// コーラの広告
	int mKora;
	// 日本の広告
	int mJapan;
	// やまこの広告
	int mYamako;


	// 広告の土台
	int mPromo[16];
	// 広告のベース１
	int mPromoBase1[2];
	// 広告のベース２
	int mPromoBase2[2];
};

