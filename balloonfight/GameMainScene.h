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

	int Miss = 0;	//プレイヤーがミスしてから復活するまでの時間

	int Ground[11];	//足場

	//さかな関連のステータス
	bool Turn = false;		//魚の向き
	bool Encount = false;	//魚が出現中ならtrue
	bool Attack = false;	//魚がターゲットを捕捉しているならtrue
	int FishTime = 0;	//魚が出現する時間
	float FishX = 0;	//魚が現れる座標
	int Target = 0;		//魚が狙っているキャラ(0~ENEMY_MAX-1:敵 ENEMY_MAX:プレイヤー)
	int FishEat = 0;	//魚が食べたキャラの種類(1:プレイヤー 2:敵)

	int FishImg[10];	//画像

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