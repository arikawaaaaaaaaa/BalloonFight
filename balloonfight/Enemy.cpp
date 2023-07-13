#include "Enemy.h"
#include"DxLib.h"
#include"PadInput.h"
#include"common.h"
#include <math.h>

Enemy::Enemy(float X, float Y) {
	this->X = X;
	this->Y = Y;

	LeftX = X - Width;
	RightX = X + Width;

	Speed = 0;
	fall = 1;

	JumpCount = 0;

	LoadDivGraph("images/player.png", 30, 8, 4, 64, 64, Image);
}

void Enemy::Update(float Px, float Py) {

	int BlockSize = BLOCK_SIZE;

	//�㉺�ړ�-----------------------------------------------------------
	float JumpPow = -0.1;	//�W�����v��
	float FallMax = -JumpPow * 21;		//�����̍ő呬�x

	if (!JumpCount && Py < Y)
	{
		JumpCount = 12;
		Anim = 0;
		//if (Ground)fall = JumpPow * 12;
		AirMove = 12;
	}

	if (JumpCount)
	{
		fall += JumpPow;
		if (fall < JumpPow * 25) fall = JumpPow * 25;
	}
	else
	{
		fall += 0.1;
		Anim++;
		if (FallMax < fall)fall = FallMax;
	}
	Y += fall;

	if (--JumpCount < 0)JumpCount = 0;

	bool WallHit = false;
	//�V��ŃW�����v���j�܂��
	while (MapData[(int)(Y - Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
		MapData[(int)(Y - Height) / BlockSize][(int)X / BlockSize] > 0 ||
		MapData[(int)(Y - Height) / BlockSize][(int)RightX / BlockSize] > 0 ||
		Y - Height <= 0)
	{
		Y += 0.1;
		WallHit = true;
	}

	if (WallHit)
	{
		fall *= -1;
	}

	Ground = false;

	//���ŗ������j�܂��
	while (MapData[(int)(Y + Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
		MapData[(int)(Y + Height) / BlockSize][(int)X / BlockSize] > 0 ||
		MapData[(int)(Y + Height) / BlockSize][(int)RightX / BlockSize] > 0 ||
		SCREEN_HEIGHT + BLOCK_SIZE * 2 <= Y + Height + 1)
	{
		Y -= 0.1;
		if (fall > 0.f)
		{
			fall = 0;
		}
	}

	//���E�ړ�-------------------------------------------
	float MaxSpeed = 2;

	if (Ground || AirMove)
	{
		//�E�Ɉړ�
		if (Px >= X) {
			if (Speed < 0 && Ground)Speed += 0.2;
			Turn = true;
			Speed += 0.2;
			Anim++;
			if (MaxSpeed < Speed)Speed = MaxSpeed;
		}
		//���Ɉړ�
		else if (Px <= X) {
			if (0 < Speed && Ground)Speed -= 0.2;
			Turn = false;
			Speed -= 0.2;
			Anim++;
			if (Speed < -MaxSpeed)Speed = -MaxSpeed;
		}
		else if (Ground)
		{
			if (0 < Speed)
			{
				Speed -= 0.2;
				if (Speed < 0)Speed = 0;
			}
			else if (Speed < 0)
			{
				Speed += 0.2;
				if (0 < Speed)Speed = 0;
			}
			Anim = 0;
		}
	}

	if (--AirMove < 0)AirMove = 0;

	//�G�L�������ړ�
	X += Speed;
	FixX();

	WallHit = false;
	//�ǂňړ����~�߂�
	bool Wall = false;
	for (float i = 0; i < Height && !Wall; i++)
	{
		if (MapData[(int)(Y + i) / BlockSize][(int)RightX / BlockSize] > 0) Wall = true;
		if (MapData[(int)(Y - i) / BlockSize][(int)RightX / BlockSize] > 0) Wall = true;
	}
	while (Wall)
	{
		X--;
		FixX();
		WallHit = true;

		Wall = false;
		for (float i = 0; i < Height && !Wall; i++)
		{
			if (MapData[(int)(Y + i) / BlockSize][(int)RightX / BlockSize] > 0) Wall = true;
			if (MapData[(int)(Y - i) / BlockSize][(int)RightX / BlockSize] > 0) Wall = true;
		}
	}

	Wall = false;
	for (float i = 0; i < Height && !Wall; i++)
	{
		if (MapData[(int)(Y + i) / BlockSize][(int)LeftX / BlockSize] > 0) Wall = true;
		if (MapData[(int)(Y - i) / BlockSize][(int)LeftX / BlockSize] > 0) Wall = true;
	}
	while (Wall)
	{
		X++;
		FixX();
		WallHit = true;

		Wall = false;
		for (float i = 0; i < Height && !Wall; i++)
		{
			if (MapData[(int)(Y + i) / BlockSize][(int)LeftX / BlockSize] > 0) Wall = true;
			if (MapData[(int)(Y - i) / BlockSize][(int)LeftX / BlockSize] > 0) Wall = true;
		}
	}

	if (WallHit)Speed *= -0.9;

	GameTime++;
}

void Enemy::FixX()
{
	//��ʒ[�ɓ��B����Ɣ��΂̉�ʒ[�Ɉړ�����
	if (X <= 0)X = GAME_WIDTH - 1;		//��ʍ��[��
	else if (GAME_WIDTH <= X)X = 0 + 1;	//��ʉE�[��

	//�v���C���[�E�[�̍��W���X�V
	LeftX = X - Width;
	if (LeftX <= 0)LeftX = GAME_WIDTH + LeftX;

	//�v���C���[���[�̍��W���X�V
	RightX = X + Width;
	if (GAME_WIDTH <= RightX)RightX = RightX - GAME_WIDTH;
}

void Enemy::Reset()
{
	X = BLOCK_SIZE * 5 + Width;
	Y = BLOCK_SIZE * 20;

	LeftX = X - Width;
	RightX = X + Width;

	Speed = 0;
	fall = 1;

	JumpCount = 0;
}


void Enemy::Draw() const {
	//DrawBox(SIDE_MARGIN + X - Width, Y - Height, SIDE_MARGIN + X + Width, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width - GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width - GAME_WIDTH, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width + GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width + GAME_WIDTH, Y + Height, 0xff0000, true);

	//�v���C���[�`��
	int Move = 0;

	//�󒆈ړ�
	if (!Ground)
	{
		Move = abs(-2 + (JumpCount / 3 % 4));
		if (JumpCount == 0)Move += Anim / 25 % 3;

		//�Q�[����ʕ��̊Ԋu��������3�̕`�悷��
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[16 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[16 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[16 + Move], true, Turn);
	}
	//�ҋ@
	else if (Speed == 0)
	{
		Move = GameTime / 25 % 3;
		//�Q�[����ʕ��̊Ԋu��������3�̕`�悷��
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[Move], true, Turn);

	}
	//�n�ʂ𑖂�
	else if (Ground)
	{
		Move = Anim / 5 % 3;
		if ((PadX > -0.3 && 0.3 > PadX) ||
			(Speed < 0 && PadX >= 0.3) ||
			(0 < Speed && -0.3 >= PadX)) {
			//�Q�[����ʕ��̊Ԋu��������3�̕`�悷��
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[11], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[11], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[11], true, Turn);
		}
		else
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
		}
	}

	//DrawCircle(LeftX + SIDE_MARGIN, Y, 2, 0x00ff00, true);
	//DrawCircle(RightX + SIDE_MARGIN, Y, 2, 0x00ff00, true);
}

//�}�b�v�f�[�^
void Enemy::SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]) {

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			this->MapData[i][j] = MapData[i][j];
		}
	}
}