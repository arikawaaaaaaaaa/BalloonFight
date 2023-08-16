#include "Bubble.h"
#include"DxLib.h"
#include"common.h"
#include <math.h>

Bubble::Bubble(float X, float Y) {
	this->X = X;
	this->Y = Y;

	LeftX = X - Width;
	RightX = X + Width;

	MaxSpeed = 1.f + (0.1f * GetRand(9));
	Speed = 0;
	Angle = 1;

	LoadDivGraph("images/Bubble.png", 4, 4, 1, 64, 64, Image);
}

void Bubble::Update(float Px, float Py) {

	if (!Hit)
	{
		Speed += 0.03 * Angle;

		if (Speed < -MaxSpeed)
		{
			Speed = -MaxSpeed;
			Angle *= -1;
		}

		if (MaxSpeed < Speed)
		{
			Speed = MaxSpeed;
			Angle *= -1;
		}

		X += Speed;

		//��ʒ[�ɓ��B����Ɣ��΂̉�ʒ[�Ɉړ�����
		if (X <= 0)X = GAME_WIDTH - 1;		//��ʍ��[��
		else if (GAME_WIDTH <= X)X = 0 + 1;	//��ʉE�[��

		//�E�[�̍��W���X�V
		LeftX = X - Width;
		if (LeftX <= 0)LeftX = GAME_WIDTH + LeftX;

		//���[�̍��W���X�V
		RightX = X + Width;
		if (GAME_WIDTH <= RightX)RightX = RightX - GAME_WIDTH;

		//��Ɉړ�����
		Y -= 0.5;
	}
	else 
	{
		BurstTime++;
	}

	//�A�j���[�V�����i�s
	Anim++;

}

void Bubble::Draw() const {
	//DrawBox(SIDE_MARGIN + X - Width, Y - Height, SIDE_MARGIN + X + Width, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width - GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width - GAME_WIDTH, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width + GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width + GAME_WIDTH, Y + Height, 0xff0000, true);

	//�A�`��
	int Move = 0;

	//�󒆈ړ�
	Move = Anim / 20 % 3;

	if (!Hit)
	{
		//�Q�[����ʕ��̊Ԋu��������3�̕`�悷��
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[Move], true, true);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[Move], true, true);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[Move], true, true);
	}
	else 
	{
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[3], true, true);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[3], true, true);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[3], true, true);
	}
	//DrawCircle(SIDE_MARGIN + X, Y - Height, 2, 0x00ff00, true);
}

bool Bubble::Burst() 
{
	if (10 < BurstTime || Y < -32)return true;
	else return false;
}

//�v���C���[�ɐG���(X���W�AY���W�A���A����)
void Bubble::HitPlayer(float Px, float Py, float Pw, float Ph)
{
	if (fabs(Px - X) < Width * 2 && fabs(Py - Y) < Height * 2)
	{
		if (!Hit)
		{
			Score = 500;
		}
		Hit = true;
	}
}

//�X�R�A�����Z����
int Bubble::AddScore()
{
	//���Z����X�R�A����
	int Score = this->Score;

	//�G�̃X�R�A�����Z�b�g����
	this->Score = 0;

	//���߂̃X�R�A��Ԃ�
	return Score;
}