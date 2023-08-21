#pragma once
#include "DxLib.h"

class Sound
{
public:
    static int Start;   //スタート時ジングル

    static int EnemyJump;   //敵ジャンプ時SE
    static int Crack;       //風船破裂SE
    static int Parachute;       //パラシュートジングル
    static int Defeat;          //敵撃破SE

    static int PlayerJump;      //プレイヤー飛行SE
    static int PlayerWalk;      //プレイヤー歩行SE
    static int Fall;            //プレイヤー落下SE
    static int Restart;         //プレイヤー復活ジングル

    static int Bubble;      //泡破裂SE
    static int Splash;      //水しぶきSE

    static int Eatable;     //魚出現SE

    static int Clear;       //ステージクリアジングル
    static int GameOver;       //ゲームオーバージングル

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

    //風船破裂SE
    static void PlayDefeat() { PlaySoundMem(Defeat, DX_PLAYTYPE_BACK); }  //再生
    static void StopDefeat() { StopSoundMem(Defeat); }                    //停止
    static bool CheckDefeat() { return CheckSoundMem(Defeat); }           //再生チェック

    //プレイヤー飛行SE
    static void PlayPlayerJump() { PlaySoundMem(PlayerJump, DX_PLAYTYPE_BACK); }  //再生
    static void StopPlayerJump() { StopSoundMem(PlayerJump); }                    //停止
    static bool CheckPlayerJump() { return CheckSoundMem(PlayerJump); }           //再生チェック

    //プレイヤー歩行SE
    static void PlayPlayerWalk() { PlaySoundMem(PlayerWalk, DX_PLAYTYPE_BACK); }  //再生
    static void StopPlayerWalk() { StopSoundMem(PlayerWalk); }                    //停止
    static bool CheckPlayerWalk() { return CheckSoundMem(PlayerWalk); }           //再生チェック

    //プレイヤー落下SE
    static void PlayFall() { PlaySoundMem(Fall, DX_PLAYTYPE_BACK); }  //再生
    static void StopFall() { StopSoundMem(Fall); }                    //停止
    static bool CheckFall() { return CheckSoundMem(Fall); }           //再生チェック

    //プレイヤー復活ジングル
    static void PlayRestart() { PlaySoundMem(Restart, DX_PLAYTYPE_BACK); }  //再生
    static void StopRestart() { StopSoundMem(Restart); }                    //停止
    static bool CheckRestart() { return CheckSoundMem(Restart); }           //再生チェック

    //泡破裂SE
    static void PlayBubble() { PlaySoundMem(Bubble, DX_PLAYTYPE_BACK); }  //再生
    static void StopBubble() { StopSoundMem(Bubble); }                    //停止
    static bool CheckBubble() { return CheckSoundMem(Bubble); }           //再生チェック

    //水しぶきSE
    static void PlaySplash() { PlaySoundMem(Splash, DX_PLAYTYPE_BACK); }  //再生
    static void StopSplash() { StopSoundMem(Splash); }                    //停止
    static bool CheckSplash() { return CheckSoundMem(Splash); }           //再生チェック

    //魚出現SE
    static void PlayEatable() { PlaySoundMem(Eatable, DX_PLAYTYPE_BACK); }  //再生
    static void StopEatable() { StopSoundMem(Eatable); }                    //停止
    static bool CheckEatable() { return CheckSoundMem(Eatable); }           //再生チェック

    //ステージクリアジングル
    static void PlayClear() { PlaySoundMem(Clear, DX_PLAYTYPE_BACK); }  //再生
    static void StopClear() { StopSoundMem(Clear); }                    //停止
    static bool CheckClear() { return CheckSoundMem(Clear); }           //再生チェック

    //ゲームオーバージングル
    static void PlayGameOver() { PlaySoundMem(GameOver, DX_PLAYTYPE_BACK); }  //再生
    static void StopGameOver() { StopSoundMem(GameOver); }                    //停止
    static bool CheckGameOver() { return CheckSoundMem(GameOver); }           //再生チェック

    //全サウンド停止
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

    //サウンド再生中チェック
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

