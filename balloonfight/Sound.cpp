#include "Sound.h"

int Sound::Start;
int Sound::EnemyJump;
int Sound::Crack;
int Sound::Parachute;
int Sound::Defeat;
int Sound::PlayerJump;
int Sound::PlayerWalk;
int Sound::Fall;
int Sound::Restart;
int Sound::Bubble;
int Sound::Splash;
int Sound::Eatable;
int Sound::Clear;
int Sound::GameOver;

void Sound::LoadSound() 
{
	Start = LoadSoundMem("sounds/SE_Start.wav");
	EnemyJump = LoadSoundMem("sounds/SE_EnemyMove.wav");
	Crack = LoadSoundMem("sounds/SE_crack.wav");
	Parachute = LoadSoundMem("sounds/SE_parachute.wav");
	Defeat = LoadSoundMem("sounds/SE_Defeat.wav");
	PlayerJump = LoadSoundMem("sounds/SE_PlayerJump.wav");
	PlayerWalk = LoadSoundMem("sounds/SE_PlayerWalk.wav");
	Fall = LoadSoundMem("sounds/SE_Falling.wav");
	Bubble = LoadSoundMem("sounds/SE_Bubble.wav");
	Splash = LoadSoundMem("sounds/SE_Splash.wav");
	Eatable = LoadSoundMem("sounds/SE_Eatable.wav");
	Clear = LoadSoundMem("sounds/SE_StageClear.wav");
	GameOver = LoadSoundMem("sounds/SE_GameOver.wav");
	Restart = LoadSoundMem("sounds/SE_Restart.wav");
}