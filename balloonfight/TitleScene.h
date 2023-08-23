#pragma once
#include"AbstractScene.h"
#include"PadInput.h"

class Title : public AbstractScene {
private:
	//���C���V�[���Ɉ����p���n�C�X�R�A
	int Hiscore;

	//�^�C�g���摜
	int TitleImg;
	int Icon[4];

	//�A�j���[�V�����Ǘ��p
	int Anim = 0;

public:
	Title(int Hiscore);

	~Title() {};

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
};