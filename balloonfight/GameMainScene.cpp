#include"DxLib.h"
#include"TitleScene.h"
#include"Sound.h"
#include"GameMainScene.h"
#include"AbstractScene.h"

#include<math.h>
#include<stdlib.h>

//#define DEBUG

int Stage[5][MAP_HEIGHT][MAP_WIDTH] =
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
		{0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	//STAGE 2
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,3,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	//STAGE 3
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	//STAGE 4
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	//STAGE 5
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	}
};

GameMainScene::GameMainScene(int Hiscore)
{
	Level = 0;
	Phase = 1;
	Score = 0;
	this->Hiscore = Hiscore;
	player.SetMapData(Stage[Level]);

	Stock = 2;

	enemy = new Enemy * [ENEMY_MAX];
	bubble = new Bubble * [ENEMY_MAX];
	cloud = new Cloud * [2];
	thunder = new Thunder * [2];

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i] = nullptr;
		bubble[i] = nullptr;

		Splash[i].Active = false;
		Splash[i].Time = 0;
		Splash[i].X = 0;

		drawscore[i].X = 0;
		drawscore[i].Y = 0;
		drawscore[i].Time = 0;
		drawscore[i].Imagenum = 0;
	}

	for (int i = 0; i < 2; i++)
	{
		cloud[i] = nullptr;
		thunder[i] = nullptr;
	}

	enemy[0] = new Enemy(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2);
	enemy[0]->SetMapData(Stage[Level]);

	enemy[1] = new Enemy(SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2);
	enemy[1]->SetMapData(Stage[Level]);

	enemy[2] = new Enemy(SCREEN_WIDTH / 2 + 90, SCREEN_HEIGHT / 2);
	enemy[2]->SetMapData(Stage[Level]);

	cloud[0] = new Cloud(SCREEN_WIDTH / 2 + 40, 120);

	//画像読み込み-----------------------------------------

	//数字
	LoadDivGraph("images/fmc_num.png", 10, 10, 1, 19, 19, Num);

	//アイコン類
	Icon[0] = LoadGraph("images/Score.png");
	Icon[1] = LoadGraph("images/Hiscore.png");
	Icon[2] = LoadGraph("images/Phase.png");
	Icon[3] = LoadGraph("images/Stock.png");
	Icon[4] = LoadGraph("images/Gameover.png");

	//地面
	Ground[0] = LoadGraph("images/GroundA.png");
	Ground[1] = LoadGraph("images/GroundB.png");

	//足場・ステージ１
	Ground[2] = LoadGraph("images/Lv1_foot.png");

	//足場・ステージ２
	Ground[3] = LoadGraph("images/Lv2_foot.png");

	//足場・ステージ３
	Ground[4] = LoadGraph("images/Lv3_footA.png");
	Ground[5] = LoadGraph("images/Lv3_footB.png");
	Ground[6] = LoadGraph("images/Lv3_footC.png");

	//足場・ステージ４
	Ground[7] = LoadGraph("images/Lv4_foot.png");

	//足場・ステージ５
	Ground[8] = LoadGraph("images/Lv5_footA.png");
	Ground[9] = LoadGraph("images/Lv5_footB.png");

	//海
	Ground[10] = LoadGraph("images/Sea.png");

	//魚
	LoadDivGraph("images/Fish.png", 10, 5, 2, 64, 64, FishImg);

	//水しぶき
	LoadDivGraph("images/Splash.png", 4, 4, 1, 64, 32, SplashImg);

	//獲得スコア表示
	LoadDivGraph("images/ScoreNum.png", 5, 5, 1, 32, 32, ScoreImg);

	//----------------------------------------------------------

	Sound::PlayStart();
}

AbstractScene* GameMainScene::Update()
{

	if (!Gameover && !StageClear)
	{
		//プレーヤーが海に沈んでいないか判定
		if (player.GetY() < SCREEN_HEIGHT)
		{
			//プレイヤー更新
			player.Update();
		}
		//プレイヤーが海に沈んでいる場合
		else
		{
			if (Sound::CheckFall())
			{
				Sound::PlaySplash();
				Sound::StopFall();
			}
			//プレイヤーの状態をミスにする
			if (player.GetCondition() != 3)
			{
				if (player.GetCondition() != 2)
				{
					Sound::PlaySplash();
				}
				player.Miss();
			}
			//ミス後の待機時間をカウントする
			if (120 < ++Miss)
			{
				//待機時間が終了した時に行う処理
				Miss = 0;
				//残機が残っている場合、残機を1減らしてプレイヤーの状態をリセットする。
				if (0 <= --Stock)
				{
					if(!Sound::CheckStart())Sound::PlayRestart();
					player.Reset();
				}
				//残機が残っていない場合、ゲームオーバーに移行する。
				else
				{
					Gameover++;
					Sound::StopAll();
					Sound::PlayGameOver();
					return this;
				}
			}
		}

		//敵更新
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (enemy[i] != nullptr)
			{
				//敵情報の更新
				enemy[i]->Update(player.GetX(), player.GetY());

				//敵とプレイヤーの当たり
				if (enemy[i]->GetCondition() != 0 && enemy[i]->GetCondition() != 3 && player.GetCondition() < 2)
				{
					player.HitEnemy(enemy[i]->GetX(), enemy[i]->GetY(), enemy[i]->GetWidth(), enemy[i]->GetHeight(), enemy[i]->GetCondition());
				}
				if (player.GetCondition() < 2)
				{
					enemy[i]->HitPlayer(player.GetX(), player.GetY(), player.GetWidth(), player.GetHeight());
				}

				//敵同士の当たり
				for (int j = 0; j < ENEMY_MAX; j++)
				{
					if (enemy[j] != nullptr && i != j)
					{
						enemy[i]->HitEnemy(enemy[j]->GetX(), enemy[j]->GetY(), enemy[j]->GetWidth(), enemy[j]->GetHeight());
					}
				}

				//スコアを加算する
				Score += enemy[i]->AddScore();

				//海に落ちたらその敵が消えて泡を出す
				if (SCREEN_HEIGHT < enemy[i]->GetY())
				{
					//水しぶきを上げる
					if (!enemy[i]->SpawnBubble() && enemy[i]->GetCondition() != 4)
					{
						Sound::PlaySplash();
						Splash[i].Active = true;
						Splash[i].Time = 20;
						Splash[i].X = enemy[i]->GetX();
					}
					//泡を出す
					if (!enemy[i]->SpawnBubble())
					{
						bubble[i] = new Bubble(enemy[i]->GetX(), SCREEN_HEIGHT);
						enemy[i]->TrueBubble();
					}
					if (!enemy[i]->DrawingScore())enemy[i] = nullptr;
				}
			}
		}

		//敵関連のサウンド管理

		bool stopJump = true;
		bool stopPara = true;
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (enemy[i] != nullptr)
			{
				//パラシュート効果音を鳴らす
				if (enemy[i]->GetCondition() == 2)
				{
					stopPara = false;
					if (!Sound::CheckParachute() && !Sound::CheckDefeat() && !Sound::CheckStart() && !Sound::CheckEatable())
					{
						Sound::PlayParachute();
						break;
					}
				}
				//ジャンプ効果音を鳴らす
				else
				{
					if (enemy[i]->GetJump())
					{
						stopJump = false;
						if (enemy[i]->GetCondition() == 1 && !Sound::CheckAll())
						{
							Sound::PlayEnemyJump();
							break;
						}
					}
				}
			}
		}
		if (stopJump || Sound::CheckParachute())
		{
			Sound::StopEnemyJump();
		}
		if (stopPara)
		{
			Sound::StopParachute();
		}

		//泡更新
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (bubble[i] != nullptr)
			{
				//敵情報の更新
				bubble[i]->Update(player.GetX(), player.GetY());

				bubble[i]->HitPlayer(player.GetX(), player.GetY(), player.GetWidth(), player.GetHeight());

				//スコアを加算する
				Score += bubble[i]->AddScore();

				if (bubble[i]->Burst())
				{
					drawscore[i].X = player.GetX();
					drawscore[i].Y = player.GetY();
					drawscore[i].Time = 90;
					drawscore[i].Imagenum = 0;

					bubble[i] = nullptr;
				}
			}
		}

		//水しぶき更新
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (Splash[i].Active)
			{
				if (--Splash[i].Time <= 0)
				{
					Splash[i].Active = false;
					Splash[i].X = 0;
					Splash[i].Time = 0;
				}
			}
		}

		//雲更新
		for (int i = 0; i < 2; i++)
		{
			if (cloud[i] != nullptr)
			{
				cloud[i]->Update();

				//雷弾を発射する
				if (cloud[i]->Spawn())
				{
					for (int j = 0; j < 2; j++)
					{
						if (thunder[j] == nullptr)
						{
							float fixX = 35;
							float fixY = 80;
							//雲のAngle(発射角)によって発射する位置と速度を決める
							switch (cloud[i]->GetAngle())
							{
							case 0:
								thunder[j] = new Thunder(cloud[i]->GetX() - fixX, cloud[i]->GetY() - fixY, -1, -2);
								thunder[j]->SetMapData(Stage[Level]);
								break;

							case 1:
								thunder[j] = new Thunder(cloud[i]->GetX() + fixX, cloud[i]->GetY() - fixY, 1, -2);
								thunder[j]->SetMapData(Stage[Level]);
								break;

							case 2:
								thunder[j] = new Thunder(cloud[i]->GetX() - fixX, cloud[i]->GetY() + fixY, -1, 2);
								thunder[j]->SetMapData(Stage[Level]);
								break;

							case 3:
								thunder[j] = new Thunder(cloud[i]->GetX() + fixX, cloud[i]->GetY() + fixY, 1, 2);
								thunder[j]->SetMapData(Stage[Level]);
								break;

							}
							break;
						}
					}
				}
			}
		}

		//雲が雷発射の予告をする
		if (1800 < Time && Time % 600 == 0 && (thunder[0] == nullptr || thunder[1] == nullptr))
		{
			if (GetRand(99) < 49 && cloud[1] != nullptr)
			{
				cloud[1]->Fire();
			}
			else if (cloud[0] != nullptr)
			{
				cloud[0]->Fire();
			}
		}

		//雷弾更新
		for (int i = 0; i < 2; i++)
		{
			if (thunder[i] != nullptr)
			{
				thunder[i]->Update();

				//プレイヤー間との距離をとる
				float DisX = fabs(thunder[i]->GetX() - player.GetX());
				float DisY = fabs(thunder[i]->GetY() - player.GetY());

				//プレイヤーに触れた際にtrueになり、雷弾をnullptrにする
				bool Death = false;

				if (DisX < 12 && DisY < 20)
				{
					player.Shock();
					Death = true;
				}
				if (SCREEN_HEIGHT < thunder[i]->GetY() || Death)
				{
					thunder[i] = nullptr;
				}
			}
		}

#ifdef DEBUG


		if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
		{
			if (++Level > 4)Level = 0;
			player.SetMapData(Stage[Level]);
			player.Reset();

			SetStage();
		}

#endif // DEBUG

		//魚更新
		Fish();

		//ハイスコア更新
		if (Hiscore < Score)Hiscore = Score;

		//ステージクリア確認
		bool Clear = true;	//ステージクリア判定の結果
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (enemy[i] != nullptr) 
			{
				//生存している敵がいるなら結果をfalseにしてループを抜ける
				if (enemy[i]->GetCondition() <= 2) 
				{
					Clear = false;
					break;
				}
			}
		}

		//判定結果がtrue(生存している敵がいない)ならステージクリア演出を開始する
		if (Clear)StageClear++;

		//獲得スコア表示の更新
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (0 < drawscore[i].Time)
			{
				drawscore[i].Time--;
			}
		}

		Time++;
	}
	else if (0 < Gameover)
	{
		if (500 < ++Gameover) 
		{
			return new Title(Hiscore);
		}
	}
	else if (0 < StageClear) 
	{
		if (StageClear < 30 && !Sound::CheckClear())
		{
			Sound::StopAll();
			Sound::PlayClear();
		}
		//ステージクリア時の処理
		if (150 < ++StageClear) 
		{
			//次に使うステージを切り替える
			if (++Level > 4)Level = 0;

			//プレイヤー情報のリセット
			player.SetMapData(Stage[Level]);
			player.Reset();

			//次のステージをセットする
			SetStage();

			//ゲーム経過時間をリセット
			StageClear = 0;
			Time = 0;

			//突破ステージ数をカウント
			Phase++;
		}
	}

	return this;
}

void GameMainScene::Fish()
{

	bool Approach = false;	//プレイヤーか敵が海面に接近しているならtrueになる

	//魚が出現していない場合
	if (!Encount) 
	{
		//プレイヤーが海面に近づいているか判定
		if (SCREEN_HEIGHT - BLOCK_SIZE * 5 < player.GetY() && player.GetCondition() < 2)
		{
			Approach = true;
			//魚が現れる座標をセット
			FishX = player.GetX();

			//ターゲットを設定
			Target = ENEMY_MAX;
		}

		//敵が海面に近づいているか判定
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (enemy[i] != nullptr && !(SCREEN_HEIGHT < enemy[i]->GetY()))
			{
				if (SCREEN_HEIGHT - BLOCK_SIZE * 5 < enemy[i]->GetY())
				{
					Approach = true;
					//魚が現れる座標をセット
					FishX = enemy[i]->GetX();

					//ターゲットを設定
					Target = i;
					break;
				}
			}
		}

		//海面に誰かが接近しているならカウントを進める
		if (Approach)
		{
			FishTime++;

			//誰かが接近して3秒経過すると2秒ごとに魚が出現する判定
			if (180 < FishTime && FishTime % 120 == 0)
			{
				//確率で魚が出現してカウントをリセット
				int Check = GetRand(99);
				if (Check < 99)
				{
					Encount = true;
					Attack = true;
					FishTime = 0;
				}
			}
		}
	}
	//魚が出現している場合
	else 
	{
		//カウントを進める
		if (Attack || FishEat)FishTime++;
		else FishTime--;

		//ターゲットが海面に近いか判定
		//ターゲットがプレイヤー
		if (Target == ENEMY_MAX)
		{
			//プレイヤーが海面に近づいているか判定
			if (SCREEN_HEIGHT - BLOCK_SIZE * 5 < player.GetY() && player.GetCondition() < 2)
			{
				Approach = true;
				//魚の現れる座標をセット
				FishX = player.GetX();
			}
			else 
			{
				Attack = false;
			}
		}
		//ターゲットが敵
		else if (0 <= Target && Target < ENEMY_MAX)
		{
			if (enemy[Target] != nullptr && !(SCREEN_HEIGHT < enemy[Target]->GetY()))
			{
				//該当の敵が海面に近づいているか判定
				if (SCREEN_HEIGHT - BLOCK_SIZE * 5 < enemy[Target]->GetY())
				{
					Approach = true;
					//魚の現れる座標をセット
					FishX = enemy[Target]->GetX();
				}
			}
			else
			{
				Attack = false;
			}
		}

		//魚がキャラを食べる判定
		if (FishTime == 30 && Attack) 
		{
			if (Target == ENEMY_MAX)
			{
				//プレイヤーが海面に近づいているか判定
				if (Approach)
				{
					player.Eaten();
					if (!Sound::CheckEatable())
					{
						Sound::StopAll();
						Sound::PlayEatable();
					}
					FishEat = 1;
				}
			}
			else if (0 <= Target && Target < ENEMY_MAX) 
			{
				if (enemy[Target] != nullptr)
				{
					if (Approach)
					{
						enemy[Target]->Eaten();
						if (!Sound::CheckEatable())
						{
							Sound::StopAll();
							Sound::PlayEatable();
						}
						FishEat = 2;
					}
				}
			}
		}
		
		//カウントが一定以上になったら出現(Encount)をfalseにする
		if (60 < FishTime || FishTime < 0)
		{
			FishTime = 0;
			FishEat = 0;
			Encount = false;
			Attack = false;
		}
	}
}

void GameMainScene::SetStage() 
{
	//敵を一旦全リセット
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i] = nullptr;
		bubble[i] = nullptr;

		Splash[i].Active = false;
		Splash[i].Time = 0;
		Splash[i].X = 0;

		drawscore[i].X = 0;
		drawscore[i].Y = 0;
		drawscore[i].Time = 0;
		drawscore[i].Imagenum = 0;
	}

	//雲を一旦全リセット
	for (int i = 0; i < 2; i++)
	{
		cloud[i] = nullptr;
		thunder[i] = nullptr;
	}

	//魚ステータスをリセット
	Encount = false;
	Attack = false;
	FishTime = 0;
	FishX = 0;
	Target = 0;
	FishEat = 0;

	//次のステージに応じて敵と雲を配置する
	switch (Level)
	{
	case 0:
		enemy[0] = new Enemy(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2);
		enemy[0]->SetMapData(Stage[Level]);

		enemy[1] = new Enemy(SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2);
		enemy[1]->SetMapData(Stage[Level]);

		enemy[2] = new Enemy(SCREEN_WIDTH / 2 + 90, SCREEN_HEIGHT / 2);
		enemy[2]->SetMapData(Stage[Level]);

		cloud[0] = new Cloud(SCREEN_WIDTH / 2 + 40, 120);

		break;

	case 1:
		enemy[0] = new Enemy(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2);
		enemy[0]->SetMapData(Stage[Level]);

		enemy[1] = new Enemy(SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2);
		enemy[1]->SetMapData(Stage[Level]);

		enemy[2] = new Enemy(SCREEN_WIDTH / 2 + 90, SCREEN_HEIGHT / 2);
		enemy[2]->SetMapData(Stage[Level]);

		enemy[3] = new Enemy(150, 110);
		enemy[3]->SetMapData(Stage[Level]);

		enemy[4] = new Enemy(490, 90);
		enemy[4]->SetMapData(Stage[Level]);

		cloud[0] = new Cloud(110, 230);
		cloud[1] = new Cloud(490, 190);
		break;

	case 2:
		enemy[0] = new Enemy(210, 73);
		enemy[0]->SetMapData(Stage[Level]);

		enemy[1] = new Enemy(505, 73);
		enemy[1]->SetMapData(Stage[Level]);

		enemy[2] = new Enemy(334, 130);
		enemy[2]->SetMapData(Stage[Level]);

		enemy[3] = new Enemy(180, 225);
		enemy[3]->SetMapData(Stage[Level]);

		enemy[4] = new Enemy(305, 320);
		enemy[4]->SetMapData(Stage[Level]);

		cloud[0] = new Cloud(110, 150);
		cloud[1] = new Cloud(460, 270);
		break;

	case 3:
		enemy[0] = new Enemy(330, 130);
		enemy[0]->SetMapData(Stage[Level]);

		enemy[1] = new Enemy(140, 205);
		enemy[1]->SetMapData(Stage[Level]);

		enemy[2] = new Enemy(465, 225);
		enemy[2]->SetMapData(Stage[Level]);

		enemy[3] = new Enemy(260, 244);
		enemy[3]->SetMapData(Stage[Level]);

		enemy[4] = new Enemy(370, 320);
		enemy[4]->SetMapData(Stage[Level]);

		cloud[0] = new Cloud(190, 100);
		cloud[1] = new Cloud(510, 150);
		break;

	case 4:
		enemy[0] = new Enemy(222, 54);
		enemy[0]->SetMapData(Stage[Level]);

		enemy[1] = new Enemy(483, 111);
		enemy[1]->SetMapData(Stage[Level]);

		enemy[2] = new Enemy(241, 130);
		enemy[2]->SetMapData(Stage[Level]);

		enemy[3] = new Enemy(104, 168);
		enemy[3]->SetMapData(Stage[Level]);

		enemy[4] = new Enemy(218, 301);
		enemy[4]->SetMapData(Stage[Level]);

		enemy[5] = new Enemy(387, 301);
		enemy[5]->SetMapData(Stage[Level]);

		cloud[0] = new Cloud(110, 110);
		cloud[1] = new Cloud(380, 130);
		break;

	default:
		break;
	}

	//Sound::PlayStart();
}

void GameMainScene::Draw() const
{
#ifdef DEBUG
	DrawFormatString(100, 50, 0xffffff, "STAGE %d", Level + 1);
	DrawFormatString(300, 50, 0xffffff, "FISH %d", FishTime);
	DrawFormatString(100, 100, 0xffffff, "PRESS START");
#endif // DEBUG

	//for (int i = 0; i <= MAP_WIDTH; i++)
	//{
	//	DrawLine(SIDE_MARGIN + BLOCK_SIZE * i, 0, SIDE_MARGIN + BLOCK_SIZE * i, SCREEN_HEIGHT, 0xffffff);
	//}

	//for (int i = 0; i <= MAP_HEIGHT; i++)
	//{
	//	DrawLine(0, BLOCK_SIZE * i, SCREEN_WIDTH, BLOCK_SIZE * i, 0xffffff);
	//}

	//ステージクリア後暗転
	if (140 < StageClear)return;

	//UI表示-------------------------------------------

	//プレイヤースコア
	DrawGraph(BLOCK_SIZE * 3, BLOCK_SIZE * 1, Icon[0], true);

	DrawGraph(BLOCK_SIZE * 4, BLOCK_SIZE * 1, Num[Score / 100000 % 10], true);
	DrawGraph(BLOCK_SIZE * 5, BLOCK_SIZE * 1, Num[Score / 10000 % 10], true);
	DrawGraph(BLOCK_SIZE * 6, BLOCK_SIZE * 1, Num[Score / 1000 % 10], true);
	DrawGraph(BLOCK_SIZE * 7, BLOCK_SIZE * 1, Num[Score / 100 % 10], true);
	DrawGraph(BLOCK_SIZE * 8, BLOCK_SIZE * 1, Num[Score / 10 % 10], true);
	DrawGraph(BLOCK_SIZE * 9, BLOCK_SIZE * 1, Num[Score % 10], true);

	//ハイスコア
	DrawGraph(BLOCK_SIZE * 12, BLOCK_SIZE * 1, Icon[1], true);

	DrawGraph(BLOCK_SIZE * 14, BLOCK_SIZE * 1, Num[Hiscore / 100000 % 10], true);
	DrawGraph(BLOCK_SIZE * 15, BLOCK_SIZE * 1, Num[Hiscore / 10000 % 10], true);
	DrawGraph(BLOCK_SIZE * 16, BLOCK_SIZE * 1, Num[Hiscore / 1000 % 10], true);
	DrawGraph(BLOCK_SIZE * 17, BLOCK_SIZE * 1, Num[Hiscore / 100 % 10], true);
	DrawGraph(BLOCK_SIZE * 18, BLOCK_SIZE * 1, Num[Hiscore / 10 % 10], true);
	DrawGraph(BLOCK_SIZE * 19, BLOCK_SIZE * 1, Num[Hiscore % 10], true);

	//残機数
	for (int i = 0; i < Stock; i++)
	{
		DrawGraph(BLOCK_SIZE * (8 - i), BLOCK_SIZE * 2, Icon[3], true);
	}
	
	//現在フェーズ数
	if (Time < 240 && Time % 60 < 30) 
	{
		DrawGraph(BLOCK_SIZE * 12, BLOCK_SIZE * 2, Icon[2], true);

		DrawGraph(BLOCK_SIZE * 18, BLOCK_SIZE * 2, Num[Phase / 10 % 10], true);
		DrawGraph(BLOCK_SIZE * 19, BLOCK_SIZE * 2, Num[Phase % 10], true);
	}

	//獲得スコア表示
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (0 < drawscore[i].Time)
		{
			DrawRotaGraph(SIDE_MARGIN + drawscore[i].X, drawscore[i].Y - 32, 1, 0, ScoreImg[drawscore[i].Imagenum], true);
		}
	}

	//-------------------------------------------------

	//足場・ステージ１
	if (Level == 0) 
	{
		for (int i = 0; i < MAP_HEIGHT - 6; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (Stage[Level][i][j] == 2)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[2], true);
				}
			}
		}
	}
	//足場・ステージ２
	if (Level == 1)
	{
		for (int i = 0; i < MAP_HEIGHT - 6; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (Stage[Level][i][j] == 2)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[2], true);
				}
				else if (Stage[Level][i][j] == 3)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[3], true);
				}
			}
		}
	}
	//足場・ステージ３
	if (Level == 2)
	{
		for (int i = 0; i < MAP_HEIGHT - 6; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (Stage[Level][i][j] == 2)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[4], true);
				}
				else if (Stage[Level][i][j] == 3)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[5], true);
				}
				else if (Stage[Level][i][j] == 4)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[6], true);
				}
			}
		}
	}
	//足場・ステージ４
	if (Level == 3)
	{
		for (int i = 0; i < MAP_HEIGHT - 6; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (Stage[Level][i][j] == 2)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[7], true);
				}
			}
		}
	}
	//足場・ステージ５
	if (Level == 4)
	{
		for (int i = 0; i < MAP_HEIGHT - 6; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (Stage[Level][i][j] == 2)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[7], true);
				}
				else if (Stage[Level][i][j] == 3)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[8], true);
				}
				else if (Stage[Level][i][j] == 4)
				{
					DrawGraph(SIDE_MARGIN + BLOCK_SIZE * j, BLOCK_SIZE * i, Ground[9], true);
				}
			}
		}
	}

	//地面を描画
	if (Level + 1 <= 3) DrawGraph(SIDE_MARGIN, SCREEN_HEIGHT - 80, Ground[0], true);
	else				DrawGraph(SIDE_MARGIN, SCREEN_HEIGHT - 80, Ground[1], true);

	//雲更新
	for (int i = 0; i < 2; i++)
	{
		if (cloud[i] != nullptr)
		{
			cloud[i]->Draw();
		}
	}

	//プレイヤー更新
	player.Draw();

	//敵更新
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}

		if (bubble[i] != nullptr)
		{
			bubble[i]->Draw();
		}
	}

	//魚
	if (Encount) 
	{
		if (FishTime < 30)
		{
			int FishY = (BLOCK_SIZE * 2.3) / 30 * FishTime;
			if (FishTime < 15)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[0], true);
			else if (FishTime < 25)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[1], true);
			else if (FishTime < 30)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[2], true);
		}
		else if (FishTime < 60)
		{
			int FishY = (BLOCK_SIZE * 2.3) - (BLOCK_SIZE * 1.1) / 30 * (FishTime - 30);
			if (FishTime < 40)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[5 + FishEat], true);
			else if (FishTime < 47)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[3], true);
			else if (FishTime < 54)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[4], true);
			else if (FishTime < 60)DrawRotaGraph2(SIDE_MARGIN + FishX, SCREEN_HEIGHT - FishY, 32, 64, 1, 0, FishImg[5], true);
		}
	}

	//弾更新
	for (int i = 0; i < 2; i++)
	{
		if (thunder[i] != nullptr)
		{
			thunder[i]->Draw();
		}
	}


	//海
	DrawGraph(SIDE_MARGIN, SCREEN_HEIGHT - 80, Ground[10], true);

	//水しぶき
	//プレイヤーの水しぶき
	int Flame = 5;
	if (0 < Miss && Miss < Flame * 4 && player.GetCondition() != 3)
	{
		int step = Miss / Flame % 4;
		DrawRotaGraph(SIDE_MARGIN + player.GetX(), SCREEN_HEIGHT - BLOCK_SIZE * 3.5, 1, 0, SplashImg[0 + step], true);
	}
	//敵の水しぶき
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Splash[i].Active)
		{
			int step = (Flame * 4 - Splash[i].Time) / Flame % 4;
			DrawRotaGraph(SIDE_MARGIN + Splash[i].X, SCREEN_HEIGHT - BLOCK_SIZE * 3.5, 1, 0, SplashImg[0 + step], true);
		}
	}

	//ゲームオーバー表示
	if (Gameover)
	{
		DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, 0, Icon[4], true);
	}

	//画面端の空間
	DrawBox(0, 0, SIDE_MARGIN, SCREEN_HEIGHT, 0x000000, true);
	DrawBox(SCREEN_WIDTH - SIDE_MARGIN, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x000000, true);
}