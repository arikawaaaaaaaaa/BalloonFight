﻿#include "Enemy.h"
#include"DxLib.h"
#include"PadInput.h"
#include"Sound.h"
#include"common.h"
#include <math.h>

Enemy::Enemy(float X, float Y, int Level) {

	this->Level = Level;
	this->X = X;
	this->Y = Y;

	LeftX = X - Width;
	RightX = X + Width;

	Speed = 0;
	fall = 1;

	JumpCount = 0;
	Takeoff = 300;

	for (int i = 0; i < 2; i++)
	{
		drawscore[i].X = 0;
		drawscore[i].Y = 0;
		drawscore[i].Time = 0;
		drawscore[i].Imagenum = 0;
	}

	LoadDivGraph("images/EnemyA.png", 18, 6, 3, 64, 64, ImageA);
	LoadDivGraph("images/EnemyB.png", 18, 6, 3, 64, 64, ImageB);
	LoadDivGraph("images/EnemyC.png", 18, 6, 3, 64, 64, ImageC);
	LoadDivGraph("images/ScoreNum.png", 5, 5, 1, 32, 32, ScoreImg);
}

void Enemy::Update(float Px, float Py) {

	int BlockSize = BLOCK_SIZE;

	if (Condition == 1)
	{
		//上下移動-----------------------------------------------------------
		float JumpPow = -0.02 - (Level * 0.005);	//ジャンプ力
		float FallMax = 0.5 + (Level * 0.05);		//落下の最大速度

		if (!Flying && Py < Y)
		{
			Flying = true;
		}
		else if (Flying && 100 < Py - Y && JumpCount == 0)
		{
			Flying = false;
		}

		if (!JumpCount && Flying)
		{
			JumpCount = 60;
			Anim = 0;
			//if (Ground)fall = JumpPow * 12;
		}

		if (JumpCount)
		{
			fall += JumpPow;
			Anim++;
			if (fall < -FallMax) fall = -FallMax;
		}
		else
		{
			fall += -JumpPow;
			if (FallMax * 1.5 < fall)fall = FallMax * 1.5;
		}
		Y += fall;

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
			fall *= -2;
		}

		//床で落下が阻まれる
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
			JumpCount = 90 + GetRand(120);
			SlideTime = JumpCount;
			Flying = true;
		}

		//左右移動-------------------------------------------
		float MaxSpeed = 1 + (Level * 0.5);

		//プレイヤーの真下にいるか調べる
		bool under = false;
		if (fabs(Px - X) < 30 && Y - Py < 100 && 0 < Y - Py)under = true;

		//移動する方向と時間を決める

		if (Flying)
		{
			if (SlideTime == 0)SlideTime = GetRand(30) + 60;
			if (Px >= X)
			{
				//プレイヤーの真下にいなければ右に加速 そうでなければ左に加速
				if (!under)
				{
					MovePower = 0.05;
					Turn = true;
				}
				else
				{
					MovePower = -0.05;
					Turn = false;
				}
			}
			else if (Px <= X) {
				Turn = false;

				//プレイヤーの真下にいなければ左に加速 そうでなければ右に加速
				if (!under)
				{
					MovePower = -0.05;
					Turn = false;
				}
				else
				{
					MovePower = 0.05;
					Turn = true;
				}
			}
		}

		if (SlideTime)
		{
			Speed += MovePower;

			Anim++;
			if (MaxSpeed < Speed)Speed = MaxSpeed;
			if (Speed < -MaxSpeed)Speed = -MaxSpeed;
		}

		if (--JumpCount < 0)JumpCount = 0;

		if (--SlideTime < 0)
		{
			MovePower = 0;
			SlideTime = 0;
		}

		//敵キャラ横移動
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
	//飛び上がる準備をする
	else if (Condition == 0)
	{
		int Dex = Level * 60;
		if (GameTime < 500)Dex = 0;

		if (480 - Dex < ++Takeoff)
		{
			JumpCount = 90 + GetRand(60);
			SlideTime = JumpCount;
			Flying = true;
			Condition = 1;

			if (500 <= GameTime && Level < 2) Level++;
		}

		Y += 5;

		//床で落下が阻まれる
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
			JumpCount = 60;
			SlideTime = 120;
		}
	}
	//パラシュートで落下する
	else if (Condition == 2)
	{
		Takeoff++;

		float MaxSpeed = 2;

		if (24 < Takeoff)
		{
			Speed += 0.03 * Paraangle;

			if (Speed < -MaxSpeed)
			{
				Speed = -MaxSpeed;
				Paraangle *= -1;
			}

			if (MaxSpeed < Speed)
			{
				Speed = MaxSpeed;
				Paraangle *= -1;
			}

			X += Speed;
			FixX();

			bool WallHit = false;
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

			if (WallHit) 
			{
				Speed *= -1;
				Paraangle *= -1;
			}

			Y += 0.5;

			while (MapData[(int)(Y + Height) / BlockSize][(int)LeftX / BlockSize] > 0 ||
				MapData[(int)(Y + Height) / BlockSize][(int)X / BlockSize] > 0 ||
				MapData[(int)(Y + Height) / BlockSize][(int)RightX / BlockSize] > 0 ||
				SCREEN_HEIGHT + BLOCK_SIZE * 2 <= Y + Height + 1)
			{
				Y--;
				Condition = 0;
				Takeoff = 0;
			}
		}
	}
	//倒される
	else if (Condition == 3) 
	{
		float FallMax = 4;		//落下の最大速度

		fall += 0.1;
		if (FallMax < fall)fall = FallMax;

		Y += fall;
	}
	//魚に食べられる
	else if (Condition == 4) 
	{
		Y = SCREEN_HEIGHT + 1;
	}

	//獲得スコア表示の更新
	for (int i = 0; i < 2; i++)
	{
		if (0 < drawscore[i].Time)
		{
			drawscore[i].Time--;
		}
	}
	GameTime++;
}

void Enemy::FixX()
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

	//獲得スコア表示
	for (int i = 0; i < 2; i++)
	{
		if (0 < drawscore[i].Time)
		{
			DrawRotaGraph(SIDE_MARGIN + drawscore[i].X, drawscore[i].Y - 32, 1, 0, ScoreImg[drawscore[i].Imagenum], true);
		}
	}

	//敵描画
	int Move = 0;

	//描画に使う画像
	int Image[18];

	//Levelに合わせた画像をimageに入れる
	if (Level == 0) memcpy(Image, ImageA, sizeof(ImageA));
	else if (Level == 1) memcpy(Image, ImageB, sizeof(ImageB));
	else if (Level == 2) memcpy(Image, ImageC, sizeof(ImageC));

	//空中移動
	if (Condition == 1)
	{
		Move = abs(-2 + (JumpCount / 3 % 4));
		if (JumpCount == 0)Move += Anim / 25 % 3;

		//ゲーム画面分の間隔をあけて3体描画する
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[8 + Move], true, Turn);
	}
	//待機
	else if (Condition == 0)
	{
		Move = GameTime / 12 % 2;

		int Dex = Level * 60;
		if (GameTime < 500)Dex = 0;

		//ゲーム画面分の間隔をあけて3体描画する
		if (Takeoff <= 300 - Dex)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[0], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[0], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[0], true, Turn);
		}
		else if (Takeoff <= 360 - Dex)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[0 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[0 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[0 + Move], true, Turn);
		}
		else if (Takeoff <= 360 + (12 * 3) - Dex)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[2 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[2 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[2 + Move], true, Turn);
		}
		else if (Takeoff <= 360 + (12 * 5) - Dex)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[4 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[4 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[4 + Move], true, Turn);
		}
		else if (Takeoff <= 480 - Dex)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[6 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[6 + Move], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[6 + Move], true, Turn);
		}

	}
	//パラシュート
	else if (Condition == 2) 
	{
		//ゲーム画面分の間隔をあけて3体描画する
		if (Takeoff < 6)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[13], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[13], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[13], true, Turn);
		}
		else if (Takeoff < 12)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[15], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[15], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[15], true, Turn);
		}
		else if (Takeoff < 18)
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[16], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[16], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[16], true, Turn);
		}
		else
		{
			DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[17], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[17], true, Turn);
			DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[17], true, Turn);
		}
	}
	//倒された
	else if (Condition == 3)
	{
		Move = GameTime / 3 % 2;
		//ゲーム画面分の間隔をあけて3体描画する
		DrawRotaGraph2(SIDE_MARGIN + X, Y, 32, 64 - Height, 1, 0, Image[13 + Move] , true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X - GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[13 + Move], true, Turn);
		DrawRotaGraph2(SIDE_MARGIN + X + GAME_WIDTH, Y, 32, 64 - Height, 1, 0, Image[13 + Move], true, Turn);
	}

	//DrawCircle(SIDE_MARGIN + X, Y - Height, 2, 0x00ff00, true);
}

//マップデータ
void Enemy::SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]) {

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			this->MapData[i][j] = MapData[i][j];
		}
	}
}

//プレイヤーに触れる(X座標、Y座標、幅、高さ)
void Enemy::HitPlayer(float Px, float Py, float Pw, float Ph)
{
	if (fabs(Px - X) < Width * 2 && fabs(Py - Y) < Height * 2 && Condition != 3)
	{
		//プレイヤーに風船・パラシュートを割られる
		if (fabs((Py + Ph) - (Y - Height)) < Height)
		{
			//風船を割られてパラシュート状態になる
			if (Condition == 1)
			{
				//速度、落下速度をリセット
				Speed = 0;
				fall = 0;

				//状態を変化させる
				Takeoff = 0;
				Condition = 2;

				//スコアを加算する
				if (Level == 0)Score = 500;
				else if (Level == 1)Score = 750;
				else if (Level == 2)Score = 1000;
				
				
				//スコア表示をセットする
				for (int i = 0; i < 2; i++)
				{
					if (drawscore[i].Time <= 0) 
					{
						drawscore[i].X = X;
						drawscore[i].Y = Y;
						drawscore[i].Imagenum = Level * 1;
						drawscore[i].Time = 90;
						break;
					}
				}

				if (Px < X)Paraangle = -1;
				else	   Paraangle = 1;

				Sound::PlayCrack();
				return;
			}
			//パラシュートを壊されて撃破される
			else if (Condition == 2 && 24 < Takeoff)
			{
				//速度、落下速度をリセット
				Speed = 0;
				fall = -3;

				//状態を変化させる
				Takeoff = 0;
				Condition = 3;

				//スコアを加算する
				if (Level == 0)Score = 1000;
				else if (Level == 1)Score = 1500;
				else if (Level == 2)Score = 2000;

				//スコア表示をセットする
				for (int i = 0; i < 2; i++)
				{
					if (drawscore[i].Time <= 0)
					{
						drawscore[i].X = X;
						drawscore[i].Y = Y;
						drawscore[i].Imagenum = 2 + (Level * 1);
						drawscore[i].Time = 90;
						break;
					}
				}

				Sound::StopAll();
				Sound::PlayDefeat();
				return;
			}
		}
		//地面で触れられて撃破される
		else if (Condition == 0)
		{
			//速度、落下速度をリセット
			Speed = 0;
			fall = -3;

			//状態を変化させる
			Takeoff = 0;
			Condition = 3;

			//スコアを加算する
			if (Level == 0)Score = 750;
			else if (Level == 1)Score = 1000;
			else if (Level == 2)Score = 1500;

			//スコア表示をセットする
			for (int i = 0; i < 2; i++)
			{
				if (drawscore[i].Time <= 0)
				{
					drawscore[i].X = X;
					drawscore[i].Y = Y;
					drawscore[i].Imagenum = 1 + (Level * 1);
					drawscore[i].Time = 90;
					break;
				}
			}

			Sound::StopAll();
			Sound::PlayDefeat();

			return;
		}

		//プレイヤーに触れて跳ね返る

		enum Angle
		{
			UP,
			DOWN,
			RIGHT,
			LEFT
		};
		Angle angle;	//どの方向から触れたか記録する変数

		//敵とプレイヤーの対応する辺同士の距離を調べる
		float Up = fabs((Py - Ph) - (Y + Height));		//プレイヤー上辺と敵下辺の差
		float Down = fabs((Y - Height) - (Py + Ph));	//敵上辺とプレイヤー下辺の差
		float Right = fabs((X - Width) - (Px + Pw));	//敵左辺とプレイヤー右辺の差
		float Left = fabs((Px - Pw) - (X + Width));		//プレイヤー左辺と敵右辺の差

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

//スコアを加算する
int Enemy::AddScore() 
{
	//加算するスコアを代入
	int Score = this->Score;

	//敵のスコアをリセットする
	this->Score = 0;

	//初めのスコアを返す
	return Score;
}

//敵同士で触れる(X座標、Y座標、幅、高さ)
void Enemy::HitEnemy(float Ex, float Ey, float Ew, float Eh)
{
	if (fabs(Ex - X) < Width * 2 && fabs(Ey - Y) < Height * 2 && Condition != 3)
	{
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