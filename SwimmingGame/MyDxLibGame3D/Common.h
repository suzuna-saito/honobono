#pragma once
#include"DxLib.h"
/*
* フルスクリーンの時とウィンドウスクリーンの時で
* 移動速度の見た目にばらつきがあります
* 設定はここで行ってください
*/

//スクリーンの大きさ
const int  SCREEN_W = 1920;
const int SCREEN_H	= 1080;

//ラジアン
const double PI = 3.1415926535897932384626433832795;

// 魚のサイズ変更値
const VECTOR FISH_SIZE = (VGet(0.0025f, 0.0025f, 0.0025f));

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

//---------------------DrawSphere3D使用のための定義---------------------------
//描画半径
const float DEBUG_RADIUS = 2.5f;

//色の定義
const int whiteColor = GetColor(255, 255, 255);
const int yellowColor = GetColor(255, 255, 0);
const int lightBlueColor = GetColor(0, 255, 255);
const int yellowGreenColor = GetColor(0, 255, 0);
const int orangeColor = GetColor(255, 102, 0);
const int redColor = GetColor(255, 0, 0);
const int greenColor = GetColor(0, 128, 0);
const int purpleColor = GetColor(128, 0, 128);
const int brownColor = GetColor(153, 51, 0);
const int blueColor = GetColor(0, 0, 255);
const int pinkColor = GetColor(255, 153, 204);
//-------------------------------------------------

const float DANCE_VELOCITY = 0.5f;         //移動したときの移動量
const float DANCE_STOP_RANGE = 0.25f;      //移動した時の停止範囲

const VECTOR ZERO_VECTOR = VGet(0.0f, 0.0f, 0.0f);   //XYZに0が入っている定数

//デバック用の定数---------------------------
const float LINE_X = 32.0f; // プールの線の座標
const float LINE_Y = 20.0f;
const float LINE_Z = 51.0f;

//ダンスで集合してから音楽を流すまでのフレームカウント
const int WAIT_DANCE_TIME_COUNT = 100;
