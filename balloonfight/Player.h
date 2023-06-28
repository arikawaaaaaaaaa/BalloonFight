#pragma once
#include"DxLib.h"
#include"common.h"

class Player
{
private:

	float X, Y;	//プレイヤー座標
	float LeftX, RightX;	//プレイヤーの左右端座標

	//プレイヤーサイズ
	float Width = BLOCK_SIZE / 2;
	float Height = BLOCK_SIZE / 2;

	float Speed;	//移動速度
	int AirMove;	//空中での左右移動受付
	float fall;		//落下速度

	int JumpCount;	//ジャンプ入力間隔
	bool Ground = true;	//地面にいるか？

	float PadX;	//横方向入力値

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//マップデータ

public:

	void InitPad();
	Player();
	void Update();
	void Draw() const;

	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void FixX();	//画面端のワープと左右端の座標の更新
};

