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
const VECTOR FISH_SIZE = (VGet(0.2f, 0.2f, 0.2f));

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