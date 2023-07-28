#pragma once
#include "AbstractScene.h"
#include"common.h"
#include"Player.h"
#include"Enemy.h"
#include"Bubble.h"


class GameMainScene : public AbstractScene
{
private:
	Player player;
	Enemy** enemy;
	Bubble** bubble;

	int Level;	//ステージ数
	int Score;	//スコア

	int Ground[11];	//足場

	//さかな関連のステータス
	bool Turn;		//魚の向き
	bool Encount;	//魚が出現中ならtrue
	int FishTime;	//魚が出現する時間

public:
	GameMainScene();
	//デストラクト
	virtual ~GameMainScene()
	{
		delete enemy;//newを作ったらdeleteを作る
		delete bubble;//newを作ったらdeleteを作る
	};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;		//通常の描画

	//魚が現れる
	void Fish();
};