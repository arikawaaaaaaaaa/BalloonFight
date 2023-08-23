#include"TitleScene.h"
#include"GameMainScene.h"
#include <math.h>

Title::Title(int Hiscore) {
	this->Hiscore = Hiscore;

	TitleImg = LoadGraph("images/title.png");
	LoadDivGraph("images/TitleIcon.png", 4, 4, 1, 32, 64, Icon);
}

AbstractScene* Title::Update() {
	
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START)) 
	{
		return new GameMainScene(Hiscore);
	}

	Anim++;
	return this;
}

void Title::Draw() const{
	DrawGraph(0, 0, TitleImg, true);

	int step = abs(-3 + (Anim / 15 % 6));
	DrawRotaGraph(125, SCREEN_HEIGHT / 2 + 70, 1, 0, Icon[step], true);
}