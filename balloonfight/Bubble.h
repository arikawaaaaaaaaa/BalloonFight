#pragma once
#include"DxLib.h"
#include"common.h"

class Bubble
{
private:

	float X, Y;	//�A�̍��W
	float LeftX, RightX;	//�A�̍��E�[���W

	//�A�T�C�Y�̔���
	float Width = 34 / 2;
	float Height = 34 / 2;

	float Speed;	//�ړ����x
	float MaxSpeed;	//�ō����x
	int Angle;		//�ړ�����

	int Image[4];	//�摜
	int Anim = 0;	//�A�j���[�V�����Ǘ�

	int GameTime = 0;	//�o�ߎ���

	bool Hit = false;	//�v���C���[�ɐG�ꂽ�Ȃ�true
	int BurstTime = 0;	//�A�������Ă��������܂ł̎���

	int Score = 0;	//�l���X�R�A

public:

	Bubble(float X, float Y);
	void Update(float Px, float Py);
	void Draw() const;

	//���W�擾
	float GetX() { return X; }
	float GetY() { return Y; }

	//�����A���̎擾
	float GetWidth() { return Width; }
	float GetHeight() { return Height; }

	//�A�������ď�����
	bool Burst();

	//�X�R�A���Z
	int AddScore();

	//�v���C���[�Ƃ̓�����
	void HitPlayer(float Px, float Py, float Pw, float Ph);	//�v���C���[�ɐG���(X���W�AY���W�A���A����)
};



