#pragma once
#include"DxLib.h"
/*
* フルスクリーンの時とウィンドウスクリーンの時で
* 移動速度の見た目にばらつきがあります
* 設定はここで行ってください
*/

//ミリセカンド
const float M_S = 1000.0f;

//スクリーンの大きさ
const int  SCREEN_W = 1920;
const int SCREEN_H	= 900;

//ボールのY軸移動スピード
const float BALL_Y_SPEED = -0.05f;
const float  BALL_Z_SPEED = -0.3f;

//ボールのZ軸移動スピード(早いほう)
const int BALL_Z_SPEED_FIRST = 2;

//ボールのZ軸移動スピード(遅いほう)
const int  BALL_Z_SPEED_SLOW = 1;

//ボールのモデルの大きさ
const float  MODEL_SCALE = 10.0f;

//ボールの出現範囲の左端と右端の値(変更ok)
const int  LEFT_EDGE = -25;
const int  RIGHT_EDGE = 100;

//ボールの出現範囲の上端と下端の値(変更ok)
const int  TOP_EDGE = 1000;
const int  LOWER_EDGE = 250;

//ボールの回転数の値
const float BALL_ROTATION_X = 0.05f;

//ボールの当たり判定の半径
const float BALL_COLLISION = 5.0f;

//ボールの出現する範囲の広さ
const int  BALL_APPEARANCE_AREA_W = 4;
const int  BALL_APPEARANCE_AREA_H = 136;

//ボールの数
const int  BALL_NUM = 50;

//サトシのX軸ポジション
const int  SATOSHI_POS_X = -10;

//サトシのZ軸ポジション
const int  SATOSHI_POS_Z = 3750;

//サトシの大きさ
const int SATOSHI_SIZE = 150;

//サトシのZ軸スピード
const float  SATOSHI_Z_SPEED = -2.75f;

//ラジアン
const double PI = 3.1415926535897932384626433832795;

struct Color
{
	int r;
	int g;
	int b;
};

//RGBを使った白色の定義
const Color WHITE = { 255,255,255 };
//RGBを使った黒色の定義
const Color BLACK = { 0,0,0 };