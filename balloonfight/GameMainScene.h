#pragma once
#include "AbstractScene.h"
#include"common.h"
#include"Player.h"


class GameMainScene : public AbstractScene
{
private:
	Player player;

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