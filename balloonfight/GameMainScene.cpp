﻿#include"DxLib.h"
#include"TitleScene.h"
#include"GameMainScene.h"
#include"AbstractScene.h"

#include<math.h>
#include<stdlib.h>

#define DEBUG

int Stage[1][MAP_HEIGHT][MAP_WIDTH] =
{
	//STAGE 1
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	}
};

GameMainScene::GameMainScene()
{
	player.SetMapData(Stage[0]);
}

AbstractScene* GameMainScene::Update() 
{
	player.Update();

	return this;
}

void GameMainScene::Draw() const
{
	DrawString(100, 100, "MAIN", 0xffffff);
	//for (int i = 0; i <= MAP_WIDTH; i++)
	//{
	//	DrawLine(SIDE_MARGIN + BLOCK_SIZE * i, 0, SIDE_MARGIN + BLOCK_SIZE * i, SCREEN_HEIGHT, 0xffffff);
	//}

	//for (int i = 0; i <= MAP_HEIGHT; i++)
	//{
	//	DrawLine(0, BLOCK_SIZE * i, SCREEN_WIDTH, BLOCK_SIZE * i, 0xffffff);
	//}

	DrawBox(SIDE_MARGIN, BLOCK_SIZE * 27, SCREEN_WIDTH - SIDE_MARGIN, SCREEN_HEIGHT, 0x00a6ff, true);

	//DrawBox(SIDE_MARGIN, BLOCK_SIZE * 27, SIDE_MARGIN + BLOCK_SIZE * 8, BLOCK_SIZE * 28, 0x88001b, true);
	//DrawBox(SCREEN_WIDTH - SIDE_MARGIN - BLOCK_SIZE * 8, BLOCK_SIZE * 27, SCREEN_WIDTH - SIDE_MARGIN, BLOCK_SIZE * 28, 0x88001b, true);

	//DrawBox(SIDE_MARGIN, BLOCK_SIZE * 26, SIDE_MARGIN + BLOCK_SIZE * 8, BLOCK_SIZE * 27, 0x0ed145, true);
	//DrawBox(SCREEN_WIDTH - SIDE_MARGIN - BLOCK_SIZE * 8, BLOCK_SIZE * 26, SCREEN_WIDTH - SIDE_MARGIN, BLOCK_SIZE * 27, 0x0ed145, true);

	//DrawBox(SIDE_MARGIN + BLOCK_SIZE * 9, BLOCK_SIZE * 18, SIDE_MARGIN + BLOCK_SIZE * 23, BLOCK_SIZE * 19, 0x0ed145, true);

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (Stage[0][i][j] == 1)
			{
				DrawBox(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, SIDE_MARGIN + BLOCK_SIZE * (j + 1), BLOCK_SIZE * (i + 1), 0x0ed145, true);
			}
			else if (Stage[0][i][j] == 2)
			{
				DrawBox(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, SIDE_MARGIN + BLOCK_SIZE * (j + 1), BLOCK_SIZE * (i + 1), 0x88001b, true);
			}
		}
	}

	player.Draw();

	DrawBox(0, 0, SIDE_MARGIN, SCREEN_HEIGHT, 0x000000, true);
	DrawBox(SCREEN_WIDTH - SIDE_MARGIN, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x000000, true);
}