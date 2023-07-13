#pragma once
#include "AbstractScene.h"
#include"common.h"
#include"Player.h"
#include"Enemy.h"


class GameMainScene : public AbstractScene
{
private:
	Player player;
	Enemy** enemy;

	int Level;	//ステージ数

	int Ground[10];	//足場

public:
	GameMainScene();
	//デストラクト
	virtual ~GameMainScene()
	{
		//delete player;//newを作ったらdeleteを作る
	};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;		//通常の描画
};