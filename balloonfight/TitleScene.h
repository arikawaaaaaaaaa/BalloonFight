#pragma once
#include"AbstractScene.h"
#include"PadInput.h"

class Title : public AbstractScene {
private:

public:
	Title();

	~Title() {};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
};