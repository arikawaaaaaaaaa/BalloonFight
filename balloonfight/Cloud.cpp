#include "Cloud.h"
#include"DxLib.h"
#include"common.h"

Cloud::Cloud(float X, float Y) {
	this->X = X;
	this->Y = Y;

	LoadDivGraph("images/Cloud.png", 3, 3, 1, 128, 64, CloudImg);
	LoadDivGraph("images/Thunder.png", 6, 6, 1, 64, 64, ThunderImg);
}

void Cloud::Update() {

	if (Active)
	{
		//アニメーション進行
		if (90 < ++Anim)
		{
			Active = false;
			Shot = true;
			Anim = 0;
		}
	}
}

void Cloud::Draw() const {

	//描画
	int Move = 0;

	//発射予告時
	if (Active)
	{
		if (Anim < 60) 
		{
			//雲が点滅するアニメーション
			Move = Anim / 4 % 2;
			DrawRotaGraph(SIDE_MARGIN + X, Y, 1, 0, CloudImg[1 + Move], true);
		}
		else
		{
			//雷が雲から伸びるアニメーション
			Move = (Anim / 4 % 2) + ((Anim - 60) / 10) * 2;

			int fixX = 30;
			int fixY = 17;
			DrawRotaGraph(SIDE_MARGIN + X, Y, 1, 0, CloudImg[0], true);
			//発射角によって雷の位置と向きを変える
			     if (Angle == 0)DrawRotaGraph2(SIDE_MARGIN + X - fixX, Y - fixY, 32, 0, 1, 3.14, ThunderImg[Move], true, true);
			else if (Angle == 1)DrawRotaGraph2(SIDE_MARGIN + X + fixX, Y - fixY, 32, 0, 1, 3.14, ThunderImg[Move], true);
			else if (Angle == 2)DrawRotaGraph2(SIDE_MARGIN + X - fixX, Y + fixY, 32, 0, 1, 0, ThunderImg[Move], true);
			else if (Angle == 3)DrawRotaGraph2(SIDE_MARGIN + X + fixX, Y + fixY, 32, 0, 1, 0, ThunderImg[Move], true, true);
		}
	}
	//何もしない時
	else
	{
		DrawRotaGraph(SIDE_MARGIN + X, Y, 1, 0, CloudImg[0], true);
	}
}