#pragma once
#include"DxLib.h"
#include"common.h"

class Enemy
{
private:

	float X, Y;	//プレイヤー座標
	float LeftX, RightX;	//プレイヤーの左右端座標

	//プレイヤーサイズ
	float Width = 30 / 2;
	float Height = 45 / 2;

	float Speed;	//移動速度
	bool Turn = true;		//左右反転
	int AirMove;	//空中での左右移動受付
	float fall;		//落下速度

	int JumpCount;	//ジャンプ入力間隔
	bool Ground = true;	//地面にいるか？

	bool Flying = false;	//飛行するか？

	float PadX;	//横方向入力値

	int Image[30];	//画像
	int Anim = 0;	//アニメーション管理

	int GameTime = 0;	//経過時間

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//マップデータ

public:

	Enemy(float X, float Y);
	void Update(float Px, float Py);
	void Draw() const;

	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void FixX();	//画面端のワープと左右端の座標の更新

	void Reset();	//位置リセット
};



