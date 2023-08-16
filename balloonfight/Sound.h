#pragma once
#include "DxLib.h"

class Sound
{
public:
    static int Start;   //�X�^�[�g���W���O��
    static int EnemyJump;   //�G�W�����v��SE
    static int Crack;       //���D�j��SE
    static int Parachute;       //�p���V���[�g�W���O��

private:
    //�R���X�g���N�^
    Sound() = default;

public:

    static void LoadSound();

    //�X�^�[�g���W���O��
    static void PlayStart() { PlaySoundMem(Start, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopStart() { StopSoundMem(Start); }                    //��~
    static bool CheckStart() { return CheckSoundMem(Start); }           //�Đ��`�F�b�N

    //�G�W�����v��SE
    static void PlayEnemyJump() { PlaySoundMem(EnemyJump, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopEnemyJump() { StopSoundMem(EnemyJump); }                    //��~
    static bool CheckEnemyJump() { return CheckSoundMem(EnemyJump); }           //�Đ��`�F�b�N

    //���D�j��SE
    static void PlayCrack() { PlaySoundMem(Crack, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopCrack() { StopSoundMem(Crack); }                    //��~
    static bool CheckCrack() { return CheckSoundMem(Crack); }           //�Đ��`�F�b�N

    //�p���V���[�g�W���O��
    static void PlayParachute() { PlaySoundMem(Parachute, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopParachute() { StopSoundMem(Parachute); }                    //��~
    static bool CheckParachute() { return CheckSoundMem(Parachute); }           //�Đ��`�F�b�N

    //�S�T�E���h��~
    static void StopAll() 
    {
        StopSoundMem(Start);
        StopSoundMem(EnemyJump);
        StopSoundMem(Crack);
        StopSoundMem(Parachute);
    }

};

