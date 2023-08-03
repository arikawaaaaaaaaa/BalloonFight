#pragma once
#include"DxLib.h"
#include"common.h"

class Thunder
{
	float X, Y;	//雷弾の座標
	float SpdX, SpdY;	//弾の各軸におけるスピード

	//弾サイズの半分
	float Width = 18 / 2;
	float Height = 16 / 2;

	int Anim = 0;	//アニメーション管理

	//画像変数
	int Img[3];

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//マップデータ

public:

	Thunder(float X, float Y, float SpdX, float SpdY);
	void Update();
	void Draw() const;

	//座標取得
	float GetX() { return X; }
	float GetY() { return Y; }

	//マップデータセット
	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);
};

