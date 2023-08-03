#pragma once
#include"DxLib.h"
#include"common.h"

class Cloud
{
private:

	float X, Y;	//���_�̍��W

	bool Active = false;	//�����˂̗\�����s���Ȃ�true
	int Angle = 0;			//���������(0:�E�� 1:���� 2:�E�� 3:����)
	bool Shot = false;		//�������˂ł����ԂȂ�true

	int Anim = 0;	//�A�j���[�V�����Ǘ�

	//�摜�ϐ�
	int CloudImg[3];
	int ThunderImg[6];

public:

	Cloud(float X, float Y);
	void Update();
	void Draw() const;

	//���W�擾
	float GetX() { return X; }
	float GetY() { return Y; }

	//�����˗\�����n�߂�
	void Fire() 
	{ 
		//�e�̔��˗\�����s��
		Active = true;
		//�e�̔��ˊp�����߂�
		Angle = GetRand(3);
	}

	//�e�𔭎˂���
	bool Spawn() 
	{
		if (Shot) {
			Shot = false;
			return true;
		}
		return false;
	}
	//�p�x�擾
	int GetAngle() { return Angle; }
};

