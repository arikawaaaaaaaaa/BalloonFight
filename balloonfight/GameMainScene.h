#pragma once
#include "AbstractScene.h"
#include"common.h"
#include"Player.h"
#include"Enemy.h"
#include"Bubble.h"
#include"Cloud.h"
#include"Thunder.h"

//敵の水しぶきのデータ
struct Death
{
	bool Active;
	int X;
	int Time;
};

class GameMainScene : public AbstractScene
{
private:
	Player player;
	Enemy** enemy;
	Bubble** bubble;
	Cloud** cloud;
	Thunder** thunder;

	int Level;	//ステージ数
	int Phase;	//突破ステージ数
	int Score;	//スコア
	int Hiscore;//ハイスコア

	int Stock;	//プレイヤーのライフ
	int StageClear = 0;	//ステージクリア演出の管理
	int Gameover = 0;	//ゲームオーバー演出の管理

	DrawScore drawscore[ENEMY_MAX];	//獲得スコア表示

	int Miss = 0;	//プレイヤーがミスしてから復活するまでの時間
	Death Splash[ENEMY_MAX];	//敵の水しぶきを管理する

	int Time;	//ゲーム経過時間

	//画像関連
	int Ground[11];	//足場
	int Num[10];	//数字
	int Icon[5];	//アイコン類
	int SplashImg[4];	//水しぶき
	int ScoreImg[5];	//獲得スコア表示

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
	GameMainScene(int Hiscore);
	//デストラクト
	virtual ~GameMainScene()
	{
		delete enemy;
		delete bubble;
		delete cloud;
	};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;		//通常の描画

	//魚が現れる
	void Fish();

	//ステージ配置
	void SetStage();
};