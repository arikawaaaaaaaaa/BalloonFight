#include "DxLib.h"
#include "common.h"
#include "PadInput.h"
#include "Sound.h"
#include "SceneManager.h"
#include "Fps.h"

#include "TitleScene.h"

#define FLAME 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetMainWindowText("BALLOON FIGHT");  //�^�C�g���ݒ�
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    ChangeWindowMode(TRUE);		//�E�B���h�E���[�h�ŋN��
    SetWindowIconID(01);

    if (DxLib_Init() == -1) return -1;	//DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);  //�`����ʂ𗠂ɂ���

    SetFontSize(20);  //�����T�C�Y��ݒ�

    //��Ŏg����

    SceneManager sceneMng((AbstractScene*)new Title(10000));

    Fps fps;

    Sound::LoadSound();

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();  //��ʂ̏�����

        sceneMng.Draw();

        fps.Update();	//�X�V
        //fps.Draw();		//�`��

        ScreenFlip();  //����ʂ̔|�{��\��ʂɔ��f

        PAD_INPUT::UpdateKey();

        fps.Wait();		//�ҋ@
    }

    DxLib_End();  //DX���C�u�����g�p�̏I������

    return 0;
}