#pragma once
#include"DxLib.h"
#include"common.h"

class Cloud
{
private:

	float X, Y;	//雷雲の座標

	bool Active = false;	//雷発射の予告を行うならtrue
	int Angle = 0;			//雷を放つ方向(0:右上 1:左上 2:右下 3:左下)
	bool Shot = false;		//雷が発射できる状態ならtrue

	int Anim = 0;	//アニメーション管理

	//画像変数
	int CloudImg[3];
	int ThunderImg[6];

public:

	Cloud(float X, float Y);
	void Update();
	void Draw() const;

	//座標取得
	float GetX() { return X; }
	float GetY() { return Y; }

	//雷発射予告を始める
	void Fire() 
	{ 
		//弾の発射予告を行う
		Active = true;
		//弾の発射角を決める
		Angle = GetRand(3);
	}

	//弾を発射する
	bool Spawn() 
	{
		if (Shot) {
			Shot = false;
			return true;
		}
		return false;
	}
	//角度取得
	int GetAngle() { return Angle; }
};

