#include "Player.h"
#include"DxLib.h"
#include"PadInput.h"
#include"common.h"
#include <math.h>

Player::Player() {
	X = BLOCK_SIZE * 5 + Width;
	Y = BLOCK_SIZE * 25 + Height - 2;

	LeftX = X - Width;
	RightX = X + Width;

	Speed = 0;
	fall = 1;

	JumpCount = 0;
}

void Player::Update() {

	InitPad();
	int BlockSize = BLOCK_SIZE;

	float MaxSpeed = 2.5;

	if (Ground || AirMove)
	{
		if (PadX >= 0.3) {
			if (Speed < 0 && Ground)Speed += 0.6;
			Speed += 0.2;
			if (MaxSpeed < Speed)Speed = MaxSpeed;
		}
		else if (PadX <= -0.3) {
			if (0 < Speed && Ground)Speed -= 0.6;
			Speed -= 0.2;
			if (Speed < -MaxSpeed)Speed = -MaxSpeed;
		}
		else if (Ground)
		{
			if (0 < Speed)
			{
				Speed -= 0.4;
				if (Speed < 0)Speed = 0;
			}
			else if (Speed < 0)
			{
				Speed += 0.4;
				if (0 < Speed)Speed = 0;
			}
		}
	}

	if (--AirMove < 0 || (PadX < 0.3 && PadX > -0.3))AirMove = 0;

	//プレイヤー横移動
	X += Speed;
	FixX();

	bool WallHit = false;
	//壁で移動を止める
	while (MapData[(int)(Y - Height) / BlockSize][(int)RightX / BlockSize] > 0 ||
		   MapData[(int)(Y + Height) / BlockSize][(int)RightX / BlockSize] > 0)
	{
		X--;
		FixX();
		WallHit = true;
	}
	while (MapData[(int)(Y - Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
		   MapData[(int)(Y + Height) / BlockSize][(int)LeftX / BlockSize] > 0)
	{
		X++;
		FixX();
		WallHit = true;
	}

	if (WallHit)Speed *= -1;

	float JumpPow = -0.1;	//ジャンプ力
	float FallMax = -JumpPow * 21;		//落下の最大速度

	if (!JumpCount && (PAD_INPUT::OnButton(XINPUT_BUTTON_B) || PAD_INPUT::OnPressed(XINPUT_BUTTON_A)))
	{
		JumpCount = 12;
		//if (Ground)fall = JumpPow * 12;
		if (PadX >= 0.3 || PadX <= -0.3)AirMove = 12;
	}

	if (JumpCount) 
	{
		fall += JumpPow;
		if (fall < JumpPow * 25) fall = JumpPow * 25;
	}
	else 
	{
		fall += 0.1;
		if (FallMax < fall)fall = FallMax;
	}
	Y += fall;

	if (--JumpCount < 0)JumpCount = 0;

	WallHit = false;
	//天井でジャンプが阻まれる
	while (MapData[(int)(Y - Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
		   MapData[(int)(Y - Height) / BlockSize][(int)RightX / BlockSize] > 0 ||
		   Y - Height <= 0)
	{
		Y+=0.1;
		WallHit = true;
	}

	if (WallHit)
	{
		fall *= -1;
	}

	Ground = false;

	//床で落下が阻まれる
	while (MapData[(int)(Y + Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
		   MapData[(int)(Y + Height) / BlockSize][(int)RightX / BlockSize] > 0)
	{
		Y-=0.1;
		Ground = true;
		if (fall > 0.f)
		{
			fall = 0;
		}
	}

}

void Player::FixX() 
{
	//画面端に到達すると反対の画面端に移動する
	if (X <= 0)X = GAME_WIDTH - 1;		//画面左端時
	else if (GAME_WIDTH <= X)X = 0 + 1;	//画面右端時

	//プレイヤー右端の座標を更新
	LeftX = X - Width;
	if (LeftX <= 0)LeftX = GAME_WIDTH + LeftX;

	//プレイヤー左端の座標を更新
	RightX = X + Width;
	if (GAME_WIDTH <= RightX)RightX = RightX - GAME_WIDTH;
}

void Player::Draw() const {
	DrawBox(SIDE_MARGIN + X - Width, Y - Height, SIDE_MARGIN + X + Width, Y + Height, 0xff0000, true);
	DrawBox(SIDE_MARGIN + X - Width - GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width - GAME_WIDTH, Y + Height, 0xff0000, true);
	DrawBox(SIDE_MARGIN + X - Width + GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width + GAME_WIDTH, Y + Height, 0xff0000, true);

	DrawCircle(LeftX + SIDE_MARGIN, Y, 2, 0x00ff00, true);
	DrawCircle(RightX + SIDE_MARGIN, Y, 2, 0x00ff00, true);
}

void Player::InitPad() {

	//スティック
	PadX = PAD_INPUT::TipLeftLStick(STICKL_X);
}

//マップデータ
void Player::SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]) {

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			this->MapData[i][j] = MapData[i][j];
		}
	}
}