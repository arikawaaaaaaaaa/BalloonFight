#include"DxLib.h"
#include"TitleScene.h"
#include"GameMainScene.h"
#include"AbstractScene.h"

#include<math.h>
#include<stdlib.h>


#define DEBUG

GameMainScene::GameMainScene()
{
}

AbstractScene* GameMainScene::Update() 
{

	return this;
}

void GameMainScene::Draw() const
{
	DrawString(100, 100, "MAIN", 0xffffff);
}