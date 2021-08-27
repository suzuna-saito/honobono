#pragma once
#include"DxLib.h"
/*
* �t���X�N���[���̎��ƃE�B���h�E�X�N���[���̎���
* �ړ����x�̌����ڂɂ΂��������܂�
* �ݒ�͂����ōs���Ă�������
*/

//�X�N���[���̑傫��
const int  SCREEN_W = 1920;
const int SCREEN_H	= 900;

//���W�A��
const double PI = 3.1415926535897932384626433832795;

// ���̃T�C�Y�ύX�l
const VECTOR FISH_SIZE = (VGet(0.0025f, 0.0025f, 0.0025f));

struct Color
{
	int r;
	int g;
	int b;
};

//RGB���g�������F�̒�`
const Color WHITE = { 255,255,255 };
//RGB���g�������F�̒�`
const Color BLACK = { 0,0,0 };

//---------------------DrawSphere3D�g�p�̂��߂̒�`---------------------------
//�`�攼�a
const float debugRad = 2.5f;

//�F�̒�`
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
