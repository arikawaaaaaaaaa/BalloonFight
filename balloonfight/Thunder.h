#pragma once
#include"DxLib.h"
#include"common.h"

class Thunder
{
	float X, Y;	//���e�̍��W
	float SpdX, SpdY;	//�e�̊e���ɂ�����X�s�[�h

	//�e�T�C�Y�̔���
	float Width = 18 / 2;
	float Height = 16 / 2;

	int Anim = 0;	//�A�j���[�V�����Ǘ�

	//�摜�ϐ�
	int Img[3];

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//�}�b�v�f�[�^

public:

	Thunder(float X, float Y, float SpdX, float SpdY);
	void Update();
	void Draw() const;

	//���W�擾
	float GetX() { return X; }
	float GetY() { return Y; }

	//�}�b�v�f�[�^�Z�b�g
	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);
};

