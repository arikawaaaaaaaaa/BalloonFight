#include "Thunder.h"
#include"DxLib.h"
#include"common.h"

Thunder::Thunder(float X, float Y, float SpdX, float SpdY) {
	this->X = X;
	this->Y = Y;

	this->SpdX = SpdX;
	this->SpdY = SpdY;

	LoadDivGraph("images/Bullet.png", 3, 3, 1, 32, 32, Img);
}

void Thunder::Update() {

	X += SpdX;
	bool WallHit = false;
	int BlockSize = BLOCK_SIZE;

	//壁で移動を止める
	bool Wall = false;
	for (float i = 0; i < Height && !Wall; i++)
	{
		if (MapData[(int)(Y + i) / BlockSize][(int)(X + Width) / BlockSize] > 0) Wall = true;
		if (MapData[(int)(Y - i) / BlockSize][(int)(X + Width) / BlockSize] > 0) Wall = true;
	}
	while (Wall)
	{
		X--;
		WallHit = true;

		Wall = false;
		for (float i = 0; i < Height && !Wall; i++)
		{
			if (MapData[(int)(Y + i) / BlockSize][(int)(X + Width) / BlockSize] > 0) Wall = true;
			if (MapData[(int)(Y - i) / BlockSize][(int)(X + Width) / BlockSize] > 0) Wall = true;
		}
	}

	Wall = false;
	for (float i = 0; i < Height && !Wall; i++)
	{
		if (MapData[(int)(Y + i) / BlockSize][(int)(X - Width) / BlockSize] > 0) Wall = true;
		if (MapData[(int)(Y - i) / BlockSize][(int)(X - Width) / BlockSize] > 0) Wall = true;
	}
	while (Wall)
	{
		X++;
		WallHit = true;

		Wall = false;
		for (float i = 0; i < Height && !Wall; i++)
		{
			if (MapData[(int)(Y + i) / BlockSize][(int)(X - Width) / BlockSize] > 0) Wall = true;
			if (MapData[(int)(Y - i) / BlockSize][(int)(X - Width) / BlockSize] > 0) Wall = true;
		}
	}

	if (WallHit || X < 0 || GAME_WIDTH < X)SpdX *= -1;

	Y += SpdY;
	WallHit = false;
	//天井でジャンプが阻まれる
	while (MapData[(int)(Y - Height) / BlockSize][(int)(X - Width) / BlockSize] > 0 ||
		MapData[(int)(Y - Height) / BlockSize][(int)X / BlockSize] > 0 ||
		MapData[(int)(Y - Height) / BlockSize][(int)(X + Width) / BlockSize] > 0 ||
		Y - Height <= 0)
	{
		Y += 0.1;
		WallHit = true;
	}

	//床で落下が阻まれる
	while (MapData[(int)(Y + Height) / BlockSize][(int)(X - Width) / BlockSize] > 0 ||
		MapData[(int)(Y + Height) / BlockSize][(int)X / BlockSize] > 0 ||
		MapData[(int)(Y + Height) / BlockSize][(int)(X + Width) / BlockSize] > 0 ||
		SCREEN_HEIGHT + BLOCK_SIZE * 2 <= Y + Height + 1)
	{
		Y -= 0.1;
		WallHit = true;
	}

	if (WallHit || Y < 0)
	{
		SpdY *= -1;
	}

	Anim++;
}

void Thunder::Draw() const {

	//描画
	int Move = Anim / 3 % 3;

	DrawRotaGraph(SIDE_MARGIN + X, Y, 1, 0, Img[Move], true);
}

//マップデータ
void Thunder::SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]) {

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			this->MapData[i][j] = MapData[i][j];
		}
	}
}