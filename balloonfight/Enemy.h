#pragma once
#include"DxLib.h"
#include"common.h"

class Enemy
{
private:

	float X, Y;	//�v���C���[���W
	float LeftX, RightX;	//�v���C���[�̍��E�[���W

	//�v���C���[�T�C�Y
	float Width = 30 / 2;
	float Height = 45 / 2;

	float Speed;	//�ړ����x
	bool Turn = true;		//���E���]
	int AirMove;	//�󒆂ł̍��E�ړ���t
	float fall;		//�������x

	int JumpCount;	//�W�����v���͊Ԋu
	bool Ground = true;	//�n�ʂɂ��邩�H

	bool Flying = false;	//��s���邩�H

	float PadX;	//���������͒l

	int Image[30];	//�摜
	int Anim = 0;	//�A�j���[�V�����Ǘ�

	int GameTime = 0;	//�o�ߎ���

	int MapData[MAP_HEIGHT][MAP_WIDTH];	//�}�b�v�f�[�^

public:

	Enemy(float X, float Y);
	void Update(float Px, float Py);
	void Draw() const;

	void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);

	void FixX();	//��ʒ[�̃��[�v�ƍ��E�[�̍��W�̍X�V

	void Reset();	//�ʒu���Z�b�g
};



