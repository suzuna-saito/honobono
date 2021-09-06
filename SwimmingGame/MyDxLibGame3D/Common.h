#pragma once
#include"DxLib.h"
/*
* �t���X�N���[���̎��ƃE�B���h�E�X�N���[���̎���
* �ړ����x�̌����ڂɂ΂��������܂�
* �ݒ�͂����ōs���Ă�������
*/

//�~���Z�J���h
const float M_S = 1000.0f;

//�X�N���[���̑傫��
const int  SCREEN_W = 1920;
const int SCREEN_H	= 900;

//�{�[����Y���ړ��X�s�[�h
const float BALL_Y_SPEED = -0.05f;
const float  BALL_Z_SPEED = -0.3f;

//�{�[����Z���ړ��X�s�[�h(�����ق�)
const int BALL_Z_SPEED_FIRST = 2;

//�{�[����Z���ړ��X�s�[�h(�x���ق�)
const int  BALL_Z_SPEED_SLOW = 1;

//�{�[���̃��f���̑傫��
const float  MODEL_SCALE = 10.0f;

//�{�[���̏o���͈͂̍��[�ƉE�[�̒l(�ύXok)
const int  LEFT_EDGE = -25;
const int  RIGHT_EDGE = 100;

//�{�[���̏o���͈͂̏�[�Ɖ��[�̒l(�ύXok)
const int  TOP_EDGE = 1000;
const int  LOWER_EDGE = 250;

//�{�[���̉�]���̒l
const float BALL_ROTATION_X = 0.05f;

//�{�[���̓����蔻��̔��a
const float BALL_COLLISION = 5.0f;

//�{�[���̏o������͈͂̍L��
const int  BALL_APPEARANCE_AREA_W = 4;
const int  BALL_APPEARANCE_AREA_H = 136;

//�{�[���̐�
const int  BALL_NUM = 50;

//�T�g�V��X���|�W�V����
const int  SATOSHI_POS_X = -10;

//�T�g�V��Z���|�W�V����
const int  SATOSHI_POS_Z = 3750;

//�T�g�V�̑傫��
const int SATOSHI_SIZE = 150;

//�T�g�V��Z���X�s�[�h
const float  SATOSHI_Z_SPEED = -2.75f;

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
