#pragma once

//�X�N���[���T�C�Y(�c�E��)
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

//�Q�[����ʂ̃T�C�Y
#define GAME_WIDTH 608

#define SCREEN_COLOR_BIT_16 16

//�}�b�v�u���b�N��(�c�E��)
#define MAP_HEIGHT 27 //25?
#define MAP_WIDTH 32

//UI�g�̃T�C�Y
#define UI_SIZE 100

//���E�̗]��
#define SIDE_MARGIN (SCREEN_WIDTH - GAME_WIDTH) / 2

//�u���b�N1�̃T�C�Y(�����`)
#define BLOCK_SIZE GAME_WIDTH / MAP_WIDTH

//�G�̍ő吔
#define ENEMY_MAX 6

//�X�R�A�\��
struct DrawScore
{
	int X;
	int Y;
	int Imagenum;
	int Time;
};