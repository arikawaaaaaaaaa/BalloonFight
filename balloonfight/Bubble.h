#pragma once
#include"DxLib.h"
#include"common.h"

class Bubble
{
private:

	float X, Y;	//泡の座標
	float LeftX, RightX;	//泡の左右端座標

	//泡サイズの半分
	float Width = 34 / 2;
	float Height = 34 / 2;

	float Speed;	//移動速度
	float MaxSpeed;	//最高速度
	int Angle;		//移動方向

	int Image[4];	//画像
	int Anim = 0;	//アニメーション管理

	int GameTime = 0;	//経過時間

	bool Hit = false;	//プレイヤーに触れたならtrue
	int BurstTime = 0;	//泡が割られてから消えるまでの時間

	int Score = 0;	//獲得スコア

public:

	Bubble(float X, float Y);
	void Update(float Px, float Py);
	void Draw() const;

	//座標取得
	float GetX() { return X; }
	float GetY() { return Y; }

	//高さ、幅の取得
	float GetWidth() { return Width; }
	float GetHeight() { return Height; }

	//泡が割られて消える
	bool Burst();

	//スコア加算
	int AddScore();

	//プレイヤーとの当たり
	void HitPlayer(float Px, float Py, float Pw, float Ph);	//プレイヤーに触れる(X座標、Y座標、幅、高さ)
};



