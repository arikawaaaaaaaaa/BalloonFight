#pragma once
#include"AbstractScene.h"
#include"PadInput.h"

class Title : public AbstractScene {
private:
	//メインシーンに引き継ぐハイスコア
	int Hiscore;

public:
	Title(int Hiscore);

	~Title() {};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
};