#pragma once
#include "DxLib.h"

class Sound
{
public:
    static int Start;   //スタート時ジングル
    static int EnemyJump;   //敵ジャンプ時SE
    static int Crack;       //風船破裂SE
    static int Parachute;       //パラシュートジングル

private:
    //コンストラクタ
    Sound() = default;

public:

    static void LoadSound();

    //スタート時ジングル
    static void PlayStart() { PlaySoundMem(Start, DX_PLAYTYPE_BACK); }  //再生
    static void StopStart() { StopSoundMem(Start); }                    //停止
    static bool CheckStart() { return CheckSoundMem(Start); }           //再生チェック

    //敵ジャンプ時SE
    static void PlayEnemyJump() { PlaySoundMem(EnemyJump, DX_PLAYTYPE_BACK); }  //再生
    static void StopEnemyJump() { StopSoundMem(EnemyJump); }                    //停止
    static bool CheckEnemyJump() { return CheckSoundMem(EnemyJump); }           //再生チェック

    //風船破裂SE
    static void PlayCrack() { PlaySoundMem(Crack, DX_PLAYTYPE_BACK); }  //再生
    static void StopCrack() { StopSoundMem(Crack); }                    //停止
    static bool CheckCrack() { return CheckSoundMem(Crack); }           //再生チェック

    //パラシュートジングル
    static void PlayParachute() { PlaySoundMem(Parachute, DX_PLAYTYPE_BACK); }  //再生
    static void StopParachute() { StopSoundMem(Parachute); }                    //停止
    static bool CheckParachute() { return CheckSoundMem(Parachute); }           //再生チェック

    //全サウンド停止
    static void StopAll() 
    {
        StopSoundMem(Start);
        StopSoundMem(EnemyJump);
        StopSoundMem(Crack);
        StopSoundMem(Parachute);
    }

};

