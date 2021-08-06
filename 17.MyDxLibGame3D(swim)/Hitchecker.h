#ifndef _HITCHECKER_H_
#define _HITCHECKER_H_
/*
* 名前の変更や追加・削除は行っても大丈夫です
*/


/// <summary>
/// 当たり判定クラス
/// </summary>
class HitChecker
{
public:

	// コンストラクタ
	HitChecker();
	// デストラクタ
	~HitChecker();

	// エフェクト等を描画
	void Draw();

	// 当たり判定
	void Check();

	/// <summary>
	/// 当たっているかの判定を返す
	/// </summary>
	/// <returns>当たっているかそうではないかの判定(bool型)</returns>
	bool GetisHit() { return mIsHitFlag; }


protected:

	int mDamageImg;         // ダメージエフェクト
	int mHP;                // 体力
	bool mIsHitFlag;            // 当たり判定
};

#endif // _HITCHECKER_