#pragma once
#include"AbstractScene.h"
#include"PadInput.h"

class Title : public AbstractScene {
private:
	//���C���V�[���Ɉ����p���n�C�X�R�A
	int Hiscore;

public:
	Title(int Hiscore);

	~Title() {};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
};