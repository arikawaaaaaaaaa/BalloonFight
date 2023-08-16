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

		//画面端に到達すると反対の画面端に移動する
		if (X <= 0)X = GAME_WIDTH - 1;		//画面左端時
		else if (GAME_WIDTH <= X)X = 0 + 1;	//画面右端時

		//右端の座標を更新
		LeftX = X - Width;
		if (LeftX <= 0)LeftX = GAME_WIDTH + LeftX;

		//左端の座標を更新
		RightX = X + Width;
		if (GAME_WIDTH <= RightX)RightX = RightX - GAME_WIDTH;

		//上に移動する
		Y -= 0.5;
	}
	else 
	{
		BurstTime++;
	}

	//アニメーション進行
	Anim++;

}

void Bubble::Draw() const {
	//DrawBox(SIDE_MARGIN + X - Width, Y - Height, SIDE_MARGIN + X + Width, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width - GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width - GAME_WIDTH, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width + GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width + GAME_WIDTH, Y + Height, 0xff0000, true);

	//泡描画
	int Move = 0;

	//空中移動
	Move = Anim / 20 % 3;

	if (!Hit)
	{
		//ゲーム画面分の間隔をあけて3体描画する
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

//プレイヤーに触れる(X座標、Y座標、幅、高さ)
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

//スコアを加算する
int Bubble::AddScore()
{
	//加算するスコアを代入
	int Score = this->Score;

	//敵のスコアをリセットする
	this->Score = 0;

	//初めのスコアを返す
	return Score;
}