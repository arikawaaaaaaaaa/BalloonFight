#pragma once
#include"DxLib.h"
#include"common.h"

class Player
{
private:

	float X, Y;	//プレイヤー座標
	float LeftX, RightX;	//プレイヤーの左右端座標

	//プレイヤーサイズの半分
	float Width = 30 / 2;
	float Height = 45 / 2;

	float Speed;	//移動速度
	bool Turn = true;		//左右反転
	int AirMove;	//空中での左右移動受付
	float fall;		//落下速度

	int JumpCount;	//ジャンプ入力間隔
	int Condition = 0;	//現在の状態(0:地面 1:通常飛行 2:ミス 3:魚に食べられた 4:雷が当たった)
	int Balloon = 2;	//風船の数
	int Vincible = 0;	//被ダメージ後の無敵時間


	float PadX;	//横方向入力値

	int Image[30];	//画像
	int Anim = 0;	//アニメーション管理

	int GameTime = 0;	//経過時間

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//マップデータ

public:

	void InitPad();
	Player();
	void Update();
	void Draw() const;

	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void FixX();	//画面端のワープと左右端の座標の更新

	void Reset();	//位置リセット

	//座標取得
	float GetX() { return X; }
	float GetY() { return Y; }

	//高さ、幅の取得
	float GetWidth() { return Width; }
	float GetHeight() { return Height; }

	//状態の取得
	int GetCondition() { return Condition; }

	//ミスした
	void Miss() { Condition = 2; }

	//魚に食べられた
	void Eaten() { Condition = 3; }

	//雷に当たった
	void Shock() { 
		Condition = 4;
		Anim = 0;
	}

	void HitEnemy(float Ex, float Ey, float Ew, float Eh);	//敵に触れる(X座標、Y座標、幅、高さ)
};