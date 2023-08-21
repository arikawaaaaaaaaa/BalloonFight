#pragma once
#include "DxLib.h"

class Sound
{
public:
    static int Start;   //�X�^�[�g���W���O��

    static int EnemyJump;   //�G�W�����v��SE
    static int Crack;       //���D�j��SE
    static int Parachute;       //�p���V���[�g�W���O��
    static int Defeat;          //�G���jSE

    static int PlayerJump;      //�v���C���[��sSE
    static int PlayerWalk;      //�v���C���[���sSE
    static int Fall;            //�v���C���[����SE
    static int Restart;         //�v���C���[�����W���O��

    static int Bubble;      //�A�j��SE
    static int Splash;      //�����Ԃ�SE

    static int Eatable;     //���o��SE

    static int Clear;       //�X�e�[�W�N���A�W���O��
    static int GameOver;       //�Q�[���I�[�o�[�W���O��

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

    //���D�j��SE
    static void PlayDefeat() { PlaySoundMem(Defeat, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopDefeat() { StopSoundMem(Defeat); }                    //��~
    static bool CheckDefeat() { return CheckSoundMem(Defeat); }           //�Đ��`�F�b�N

    //�v���C���[��sSE
    static void PlayPlayerJump() { PlaySoundMem(PlayerJump, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopPlayerJump() { StopSoundMem(PlayerJump); }                    //��~
    static bool CheckPlayerJump() { return CheckSoundMem(PlayerJump); }           //�Đ��`�F�b�N

    //�v���C���[���sSE
    static void PlayPlayerWalk() { PlaySoundMem(PlayerWalk, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopPlayerWalk() { StopSoundMem(PlayerWalk); }                    //��~
    static bool CheckPlayerWalk() { return CheckSoundMem(PlayerWalk); }           //�Đ��`�F�b�N

    //�v���C���[����SE
    static void PlayFall() { PlaySoundMem(Fall, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopFall() { StopSoundMem(Fall); }                    //��~
    static bool CheckFall() { return CheckSoundMem(Fall); }           //�Đ��`�F�b�N

    //�v���C���[�����W���O��
    static void PlayRestart() { PlaySoundMem(Restart, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopRestart() { StopSoundMem(Restart); }                    //��~
    static bool CheckRestart() { return CheckSoundMem(Restart); }           //�Đ��`�F�b�N

    //�A�j��SE
    static void PlayBubble() { PlaySoundMem(Bubble, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopBubble() { StopSoundMem(Bubble); }                    //��~
    static bool CheckBubble() { return CheckSoundMem(Bubble); }           //�Đ��`�F�b�N

    //�����Ԃ�SE
    static void PlaySplash() { PlaySoundMem(Splash, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopSplash() { StopSoundMem(Splash); }                    //��~
    static bool CheckSplash() { return CheckSoundMem(Splash); }           //�Đ��`�F�b�N

    //���o��SE
    static void PlayEatable() { PlaySoundMem(Eatable, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopEatable() { StopSoundMem(Eatable); }                    //��~
    static bool CheckEatable() { return CheckSoundMem(Eatable); }           //�Đ��`�F�b�N

    //�X�e�[�W�N���A�W���O��
    static void PlayClear() { PlaySoundMem(Clear, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopClear() { StopSoundMem(Clear); }                    //��~
    static bool CheckClear() { return CheckSoundMem(Clear); }           //�Đ��`�F�b�N

    //�Q�[���I�[�o�[�W���O��
    static void PlayGameOver() { PlaySoundMem(GameOver, DX_PLAYTYPE_BACK); }  //�Đ�
    static void StopGameOver() { StopSoundMem(GameOver); }                    //��~
    static bool CheckGameOver() { return CheckSoundMem(GameOver); }           //�Đ��`�F�b�N

    //�S�T�E���h��~
    static void StopAll() 
    {
        StopSoundMem(Start);
        StopSoundMem(EnemyJump);
        StopSoundMem(Crack);
        StopSoundMem(Parachute);
        StopSoundMem(Defeat);
        StopSoundMem(PlayerJump);
        StopSoundMem(PlayerWalk);
        StopSoundMem(Fall);
        StopSoundMem(Bubble);
    }

    //�T�E���h�Đ����`�F�b�N
    static bool CheckAll()
    {
        if (CheckStart())return true;
        if (CheckEnemyJump())return true;
        if (CheckCrack())return true;
        if (CheckParachute())return true;
        if (CheckDefeat())return true;
        if (CheckBubble())return true;
        if (CheckEatable())return true;
        if (CheckFall())return true;

        return false;
    }

};

