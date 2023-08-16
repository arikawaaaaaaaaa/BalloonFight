#include "DxLib.h"
#include "common.h"
#include "PadInput.h"
#include "Sound.h"
#include "SceneManager.h"
#include "Fps.h"

#include "TitleScene.h"

#define FLAME 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetMainWindowText("BALLOON FIGHT");  //タイトル設定
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    ChangeWindowMode(TRUE);		//ウィンドウモードで起動
    SetWindowIconID(01);

    if (DxLib_Init() == -1) return -1;	//DXライブラリの初期化処理

    SetDrawScreen(DX_SCREEN_BACK);  //描画先画面を裏にする

    SetFontSize(20);  //文字サイズを設定

    //後で使うよ

    SceneManager sceneMng((AbstractScene*)new Title(10000));

    Fps fps;

    Sound::LoadSound();

    //ゲームループ
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();  //画面の初期化

        sceneMng.Draw();

        fps.Update();	//更新
        //fps.Draw();		//描画

        ScreenFlip();  //裏画面の培養を表画面に反映

        PAD_INPUT::UpdateKey();

        fps.Wait();		//待機
    }

    DxLib_End();  //DXライブラリ使用の終了処理

    return 0;
}