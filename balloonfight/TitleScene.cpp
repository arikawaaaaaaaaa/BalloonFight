#include"TitleScene.h"
#include"GameMainScene.h"

Title::Title(int Hiscore) {
	this->Hiscore = Hiscore;
}

AbstractScene* Title::Update() {
	
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) 
	{
		return new GameMainScene(Hiscore);
	}

	return this;
}

void Title::Draw() const{
	DrawString(100, 100, "TITLE", 0xffffff);
	DrawString(100, 130, "PRESS B", 0xffffff);
}