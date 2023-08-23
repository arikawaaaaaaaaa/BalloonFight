#pragma once
#include"AbstractScene.h"
#include"PadInput.h"

class Title : public AbstractScene {
private:
	//メインシーンに引き継ぐハイスコア
	int Hiscore;

	//タイトル画像
	int TitleImg;
	int Icon[4];

	//アニメーション管理用
	int Anim = 0;

public:
	Title(int Hiscore);

	~Title() {};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
};