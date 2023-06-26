#include "PadInput.h"
#include<math.h>

char PAD_INPUT::NowKey[BUTTONS];
char PAD_INPUT::OldKey[BUTTONS];
XINPUT_STATE PAD_INPUT::Input;
Stick PAD_INPUT::Rstick;
Stick PAD_INPUT::Lstick;


float PAD_INPUT::LstickRad()
{
    float L_X = Input.ThumbLX / MAXL_X;
    float L_Y = Input.ThumbLY / MAXL_Y;

    if (L_X == 0 && L_Y == 0)
    {
        return 0;
    }
    return (float)atan2(L_Y, L_X);
}

float PAD_INPUT::LstickTilt()
{
    float L_X = Input.ThumbLX / MAXL_X;
    float L_Y = Input.ThumbLY / MAXL_Y;

    L_X *= L_X;
    L_Y *= L_Y;

    if (L_X == 0 && L_Y == 0)
    {
        return 0;
    }
    return (float)sqrt(L_Y + L_X);
}