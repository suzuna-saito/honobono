#pragma once
#include"DxLib.h"
/*
* �t���X�N���[���̎��ƃE�B���h�E�X�N���[���̎���
* �ړ����x�̌����ڂɂ΂��������܂�
* �ݒ�͂����ōs���Ă�������
*/

//�~���Z�J���h
#define M_S			1000.0f

//�X�N���[���̑傫��
#define SCREEN_W	640
#define SCREEN_H	480

//�{�[����Y���ړ��X�s�[�h
#define BALL_Y_SPEED		-0.05f
#define BALL_Z_SPEED         -0.3f

//�{�[����Z���ړ��X�s�[�h(�����ق�)
#define BALL_Z_SPEED_FIRST		2

//�{�[����Z���ړ��X�s�[�h(�x���ق�)
#define BALL_Z_SPEED_SLOW		1

//�{�[���̃��f���̑傫��
#define MODEL_SCALE		10.0f

//�{�[���̏o���͈͂̍��[�ƉE�[�̒l(�ύXok)
#define LEFT_EDGE	-25
#define RIGHT_EDGE	100

//�{�[���̏o���͈͂̏�[�Ɖ��[�̒l(�ύXok)
#define TOP_EDGE		1000
#define LOWER_EDGE		250

//�{�[���̉�]���̒l
#define BALL_ROTATION_X		0.05f

//�{�[���̓����蔻��̔��a
#define BALL_COLLISION		5.0f

//�{�[���̏o������͈͂̍L��
#define BALL_APPEARANCE_AREA_W		4
#define BALL_APPEARANCE_AREA_H		136

//�{�[���̐�
#define BALL_NUM			50

//�T�g�V��X���|�W�V����
#define SATOSHI_POS_X		-10

//�T�g�V��Z���|�W�V����
#define SATOSHI_POS_Z		3750

//�T�g�V�̑傫��
#define SATOSHI_SIZE		150

//�T�g�V��Z���X�s�[�h
#define SATOSHI_Z_SPEED		-2.75f

//���W�A��
#define PI	3.1415926535897932384626433832795

struct Color
{
	int r;
	int g;
	int b;
};

const Color WHITE = { 255,255,255 };
const Color BLACK = { 0,0,0 };