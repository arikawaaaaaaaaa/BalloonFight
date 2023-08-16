#include "Player.h"
#include"DxLib.h"
#include"PadInput.h"
#include"Sound.h"
#include"common.h"
#include <math.h>

Player::Player() {
	X = BLOCK_SIZE * 5 + Width;
	Y = BLOCK_SIZE * 20;

	LeftX = X - Width;
	RightX = X + Width;

	Speed = 0;
	fall = 1;

	JumpCount = 0;

	LoadDivGraph("images/player.png", 30, 8, 4, 64, 64, Image);
}

void Player::Update() {

	InitPad();
	int BlockSize = BLOCK_SIZE;

	//通常の状態
	if (Condition == 0 || Condition == 1)
	{
		//上下移動-----------------------------------------------------------
		float JumpPow = -0.1;	//ジャンプ力
		float FallMax = -JumpPow * 21;		//落下の最大速度

		if (!JumpCount && (PAD_INPUT::OnButton(XINPUT_BUTTON_B) || PAD_INPUT::OnPressed(XINPUT_BUTTON_A)))
		{
			JumpCount = 12;
			Anim = 0;
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
			Anim++;
			if (FallMax < fall)fall = FallMax;
		}
		Y += fall;

		if (--JumpCount < 0)JumpCount = 0;

		bool WallHit = false;
		//天井でジャンプが阻まれる
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

		Condition = 1;

		//床で落下が阻まれる
		while (MapData[(int)(Y + Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
			MapData[(int)(Y + Height) / BlockSize][(int)X / BlockSize] > 0 ||
			MapData[(int)(Y + Height) / BlockSize][(int)RightX / BlockSize] > 0 ||
			SCREEN_HEIGHT + BLOCK_SIZE * 2 <= Y + Height + 1)
		{
			Y -= 0.1;
			Condition = 0;
			if (fall > 0.f)
			{
				fall = 0;
			}
		}

		//左右移動-------------------------------------------
		float MaxSpeed = 2.3;

		if (Condition == 0 || AirMove)
		{
			if (PadX >= 0.3) {
				if (Speed < 0 && Condition == 0)Speed += 0.2;
				Turn = true;
				Speed += 0.2;
				Anim++;
				if (MaxSpeed < Speed)Speed = MaxSpeed;
			}
			else if (PadX <= -0.3) {
				if (0 < Speed && Condition == 0)Speed -= 0.2;
				Turn = false;
				Speed -= 0.2;
				Anim++;
				if (Speed < -MaxSpeed)Speed = -MaxSpeed;
			}
			else if (Condition == 0)
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

		if (--AirMove < 0 || (PadX < 0.3 && PadX > -0.3))AirMove = 0;

		//プレイヤー横移動
		X += Speed;
		FixX();

		WallHit = false;
		//壁で移動を止める
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
	}
	//ミス
	else if (Condition == 2)
	{
		float FallMax = 4;		//落下の最大速度

		fall += 0.1;
		if (FallMax < fall)fall = FallMax;

		Y += fall;
	}
	//魚に食べられた
	else if (Condition == 3)
	{
		Y = SCREEN_HEIGHT + 1;
	}
	//雷に当たった
	else if (Condition == 4)
	{
		if (60 < ++Anim)Condition = 2;
		fall = -3;
	}

	GameTime++;
	if (--Vincible < 0)Vincible = 0;
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

void Player::Reset()
{
	X = BLOCK_SIZE * 5 + Width;
	Y = 377;

	LeftX = X - Width;
	RightX = X + Width;

	Turn = true;

	Speed = 0;
	fall = 1; 
	
	if (Condition == 2 || Condition == 3)
	{
		Balloon = 2;
	}
	Condition = 0;
	Anim = 0;

	JumpCount = 0;
}


void Player::Draw() const {
	//DrawBox(SIDE_MARGIN + X - Width, Y - Height, SIDE_MARGIN + X + Width, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width - GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width - GAME_WIDTH, Y + Height, 0xff0000, true);
	//DrawBox(SIDE_MARGIN + X - Width + GAME_WIDTH, Y - Height, SIDE_MARGIN + X + Width + GAME_WIDTH, Y + Height, 0xff0000, true);

	//プレイヤー描画
	int Move = 0;

	//空中移動
	if (Condition == 1)
	{
		Move = abs(-2 + (JumpCount / 3 % 4));
		if (JumpCount == 0)Move += Anim / 25 % 3;

		//風船が割られているときのイラスト変化
		if (Balloon == 1)
		{
			Move += 8;
		}

		//ゲーム画面分の間隔をあけて3体描画する
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[16 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[16 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[16 + Move], true, Turn);
	}
	//待機
	else if (Condition < 2 && Speed == 0)
	{
		Move = GameTime / 25 % 3;

		//風船が割られているときのイラスト変化
		if (Balloon == 1)
		{
			Move += 4;
		}

		//ゲーム画面分の間隔をあけて3体描画する
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[Move], true, Turn);

	}
	//地面を走る
	else if (Condition == 0)
	{
		Move = Anim / 5 % 3;

		//風船が割られているときのイラスト変化
		if (Balloon == 1)
		{
			Move += 4;
		}

		if ((PadX > -0.3 && 0.3 > PadX) ||
			(Speed < 0 && PadX >= 0.3) ||
			(0 < Speed && -0.3 >= PadX)) {
			//ゲーム画面分の間隔をあけて3体描画する
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[15], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[15], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[15], true, Turn);
		}
		else
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
		}
	}
	//ミス
	else if (Condition == 2)
	{
		Move = abs(-2 + (GameTime / 3 % 4));
		//ゲーム画面分の間隔をあけて3体描画する
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[21 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[21 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[21 + Move], true, Turn);
	}
	//雷に当たった
	else if (Condition == 4)
	{
		Move = (Anim / 3 % 2) * 8;
		//ゲーム画面分の間隔をあけて3体描画する
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[21 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[21 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[21 + Move], true, Turn);
	}

	//DrawCircle(LeftX + SIDE_MARGIN, Y, 2, 0x00ff00, true);
	//DrawCircle(RightX + SIDE_MARGIN, Y, 2, 0x00ff00, true);
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

//敵に触れる(X座標、Y座標、幅、高さ)
void Player::HitEnemy(float Ex, float Ey, float Ew, float Eh, int con)
{
	if (fabs(Ex - X) < Width * 2 && fabs(Ey - Y) < Height * 2 && Condition != 2)
	{
		DrawFormatString(500, 100, 0xffffff, "HIT");
		//敵に風船を割られる
		if (fabs((Ey + Eh) - (Y - Height)) < Height && con < 2)
		{
			//風船の数が2個の場合、風船を一個減らす
			if (Balloon == 2 && !Vincible)
			{
				Vincible = 12;
				Balloon = 1;

				Sound::PlayCrack();

				return;
			}
			//風船の数が1個の場合、ミスの状態にする
			else if (Balloon == 1 && !Vincible)
			{
				Balloon = 0;
				Speed = 0;
				fall = -3;
				Condition = 2;

				Sound::PlayCrack();

				return;
			}
		}

		//敵に触れて跳ね返る
		enum Angle
		{
			UP,
			DOWN,
			RIGHT,
			LEFT
		};
		Angle angle;	//どの方向から触れたか記録する変数

		//敵とプレイヤーの対応する辺同士の距離を調べる
		float Up = fabs((Ey - Eh) - (Y + Height));		//敵上辺とプレイヤー下辺の差
		float Down = fabs((Y - Height) - (Ey + Eh));	//プレイヤー上辺と敵下辺の差
		float Right = fabs((X - Width) - (Ex + Ew));	//プレイヤー左辺と敵右辺の差
		float Left = fabs((Ex - Ew) - (X + Width));		//敵左辺とプレイヤー右辺の差

		//4つの変数のうち、最も値の小さいものを触れた方向とする
		if (Up < Down)
		{
			if (Up < Right)
			{
				if (Up < Left)  angle = UP;
				else			angle = LEFT;
			}
			else
			{
				if (Right < Left)  angle = RIGHT;
				else			   angle = LEFT;
			}
		}
		else
		{
			if (Down < Right)
			{
				if (Down < Left)  angle = DOWN;
				else			angle = LEFT;
			}
			else
			{
				if (Right < Left)  angle = RIGHT;
				else			   angle = LEFT;
			}
		}

		switch (angle)
		{
		case UP:
			if (0 < fall)fall *= -1;
			break;

		case DOWN:
			if (fall < 0)fall *= -1;
			break;

		case RIGHT:
			if (Speed < 0)Speed *= -1;
			break;

		case LEFT:
			if (0 < Speed)Speed *= -1;
			break;

		default:
			break;
		}

	}
}