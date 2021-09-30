#pragma once
#include"DxLib.h"
/*
* �t���X�N���[���̎��ƃE�B���h�E�X�N���[���̎���
* �ړ����x�̌����ڂɂ΂��������܂�
* �ݒ�͂����ōs���Ă�������
*/

//�X�N���[���̑傫��
const int  SCREEN_W = 1920;
const int SCREEN_H	= 1080;

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
const float DEBUG_RADIUS = 2.5f;

//�F�̒�`
const int WHITE_COLOR = GetColor(255, 255, 255);
const int YELLOW_COLOR = GetColor(255, 255, 0);
const int LIGHTBLUE_COLOR = GetColor(0, 255, 255);
const int YELLOWGREEN_COLOR = GetColor(0, 255, 0);
const int ORANGE_COULOR = GetColor(255, 102, 0);
const int RED_COLOR = GetColor(255, 0, 0);
const int GREEN_COLOR = GetColor(0, 128, 0);
const int PURPLE_COLOR = GetColor(128, 0, 128);
const int BROWN_COLOR = GetColor(153, 51, 0);
const int BLUE_COLOR = GetColor(0, 0, 255);
const int PINK_COLOR = GetColor(255, 153, 204);
const int BLACK_COLOR = GetColor(0, 0, 0);
const int DARK_SLATE_GRAY = GetColor(47, 79, 79);
//-------------------------------------------------

const float DANCE_VELOCITY = 0.5f;         //�ړ������Ƃ��̈ړ���
const float DANCE_STOP_RANGE = 0.25f;      //�ړ��������̒�~�͈�

const VECTOR ZERO_VECTOR = VGet(0.0f, 0.0f, 0.0f);   //XYZ��0�������Ă���萔

//�f�o�b�N�p�̒萔---------------------------
const float LINE_X = 32.0f; // �v�[���̐��̍��W
const float LINE_Y = 20.0f;
const float LINE_Z = 51.0f;

//�_���X�ŏW�����Ă��特�y�𗬂��܂ł̃t���[���J�E���g
const int WAIT_DANCE_TIME_COUNT = 100;
