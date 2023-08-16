#pragma once
#include"DxLib.h"
#include"common.h"

class Enemy
{
private:

	float X, Y;	//敵座標
	float LeftX, RightX;	//敵の左右端座標

	//敵サイズの半分
	float Width = 30 / 2;
	float Height = 45 / 2;

	float Speed;	//移動速度
	bool Turn = true;		//左右反転
	int AirMove;	//空中での左右移動受付
	float fall;		//落下速度

	int JumpCount;	//ジャンプ入力間隔
	int Condition = 0;	//現在の状態(0:地面 1:通常飛行 2:パラシュート 3:撃破 4:魚に食べられた)
	int Takeoff = 0;	//風船を膨らませて飛び上がるまでの時間
	int Paraangle = 0;	//パラシュートのX軸移動方向

	bool Flying = false;	//飛行するか？
	int SlideTime = 0;		//横移動する時間
	float MovePower = 0;	//キャラ移動の加速度

	float PadX;	//横方向入力値

	int Image[18];	//画像
	int Anim = 0;	//アニメーション管理

	int GameTime = 0;	//経過時間

	int Score = 0;	//獲得スコア

	bool Bubble = false;	//海に沈んで泡を出したならtrueになる

	DrawScore drawscore[2];	//獲得スコア表示
	int ScoreImg[5];

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//マップデータ

public:

	Enemy(float X, float Y);
	void Update(float Px, float Py);
	void Draw() const;

	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void FixX();	//画面端のワープと左右端の座標の更新

	//座標取得
	float GetX() const { return X; }
	float GetY() const { return Y; }

	//高さ、幅の取得
	float GetWidth() const { return Width; }
	float GetHeight() const { return Height; }

	bool GetJump() const { return Flying; }

	//敵状態の取得
	int GetCondition() const { return Condition; }

	//スコア加算
	int AddScore();

	//泡を出したかどうかを返す
	bool SpawnBubble() const { return Bubble; }
	
	//泡を出した時の処理
	void TrueBubble() { Bubble = true; }

	//スコア描画状況を返す
	bool DrawingScore()const
	{
		if (drawscore[0].Time <= 0 && drawscore[1].Time <= 0) return true;
		else return false;
	}

	//魚に食べられた
	void Eaten() { Condition = 4; }

	void HitPlayer(float Px, float Py, float Pw, float Ph);	//プレイヤーに触れる(X座標、Y座標、幅、高さ)
	void HitEnemy(float Ex, float Ey, float Ew, float Eh);	//敵同士で触れる(X座標、Y座標、幅、高さ)

	void Reset();	//位置リセット
};



