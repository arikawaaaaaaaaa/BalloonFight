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
	int Condition = 0;	//現在の状態(0:地面 1:通常飛行 2:パラシュート)
	int Takeoff = 0;	//風船を膨らませて飛び上がるまでの時間

	bool Flying = false;	//飛行するか？
	int SlideTime = 0;		//横移動する時間
	float MovePower = 0;	//キャラ移動の加速度

	float PadX;	//横方向入力値

	int Image[18];	//画像
	int Anim = 0;	//アニメーション管理

	int GameTime = 0;	//経過時間

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//マップデータ

public:

	Enemy(float X, float Y);
	void Update(float Px, float Py);
	void Draw() const;

	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void FixX();	//画面端のワープと左右端の座標の更新

	//座標取得
	float GetX() { return X; }
	float GetY() { return Y; }

	//高さ、幅の取得
	float GetWidth() { return Width; }
	float GetHeight() { return Height; }

	void HitPlayer(float Px, float Py, float Pw, float Ph);	//プレイヤーに触れる(X座標、Y座標、幅、高さ)

	void Reset();	//位置リセット
};



